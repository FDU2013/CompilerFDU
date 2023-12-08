#include "ssa.h"

#include <cassert>
#include <iostream>
#include <list>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "bg_llvm.h"
#include "graph.hpp"
#include "liveness.h"
#include "printLLVM.h"

using namespace std;
using namespace LLVMIR;
using namespace GRAPH;
struct imm_Dominator {
  LLVMIR::L_block* pred;
  unordered_set<LLVMIR::L_block*> succs;
};

unordered_map<L_block*, unordered_set<L_block*>> dominators;
unordered_map<L_block*, imm_Dominator> tree_dominators;
unordered_map<L_block*, unordered_set<L_block*>> DF_array;
unordered_map<L_block*, Node<LLVMIR::L_block*>*> revers_graph;
unordered_set<L_block*> node_deprecated;
unordered_map<Temp_temp*, unordered_set<Node<LLVMIR::L_block*>*>> defsite;
unordered_map<L_block*, unordered_set<Temp_temp*>> place_phi_set;
unordered_map<Temp_temp*, AS_operand*> temp2ASoper;

static void init_table() {
  dominators.clear();
  tree_dominators.clear();
  DF_array.clear();
  node_deprecated.clear();
  revers_graph.clear();
  temp2ASoper.clear();
  defsite.clear();
  place_phi_set.clear();
}

LLVMIR::L_prog* SSA(LLVMIR::L_prog* prog, FILE* liveness_file, FILE* domi_file,
                    FILE* domiTree_file, FILE* domiFron_file) {
  for (auto& fun : prog->funcs) {
    init_table();
    combine_addr(fun);

    mem2reg(fun);

    auto RA_bg = Create_bg(fun->blocks);
    comput_reverse_graph(RA_bg);

    SingleSourceGraph(RA_bg.mynodes[0], RA_bg, fun, node_deprecated);

    Liveness(RA_bg.mynodes[0], RA_bg, fun->args);

    Dominators(RA_bg);

    tree_Dominators(RA_bg);

    computeDF(RA_bg, RA_bg.mynodes[0]);

    Place_phi_fu(RA_bg, fun);

    Rename(RA_bg);
    combine_addr(fun);
  }
  return prog;
}

static bool is_mem_variable(L_stm* stm) {
  return stm->type == L_StmKind::T_ALLOCA &&
         stm->u.ALLOCA->dst->kind == OperandKind::TEMP &&
         stm->u.ALLOCA->dst->u.TEMP->type == TempType::INT_PTR &&
         stm->u.ALLOCA->dst->u.TEMP->len == 0;
}

void combine_addr(LLVMIR::L_func* fun) {
  unordered_map<Temp_temp*, unordered_set<AS_operand**>> temp_set;
  unordered_map<Name_name*, unordered_set<AS_operand**>> name_set;
  for (auto& block : fun->blocks) {
    for (auto& stm : block->instrs) {
      auto AS_operand_list = get_all_AS_operand(stm);
      for (auto AS_op : AS_operand_list) {
        if ((*AS_op)->kind == OperandKind::TEMP) {
          temp_set[(*AS_op)->u.TEMP].insert(AS_op);
        } else if ((*AS_op)->kind == OperandKind::NAME) {
          name_set[(*AS_op)->u.NAME].insert(AS_op);
        }
      }
    }
  }
  for (auto temp : temp_set) {
    AS_operand* fi_AS_op = **temp.second.begin();
    for (auto AS_op : temp.second) {
      *AS_op = fi_AS_op;
    }
    temp2ASoper.emplace(temp.first, fi_AS_op);
  }
  for (auto name : name_set) {
    AS_operand* fi_AS_op = **name.second.begin();
    for (auto AS_op : name.second) {
      *AS_op = fi_AS_op;
    }
  }
}

static AS_operand* check_exist_mem_variable(LLVMIR::L_func* fun) {
  for (auto block : fun->blocks) {
    for (auto s : block->instrs) {
      if (is_mem_variable(s)) return s->u.ALLOCA->dst;
    }
  }
  return nullptr;
}

static inline void replace_operand_in_one_operand(
    unordered_map<AS_operand*, AS_operand*>& replace_set, AS_operand** opr) {
  if (replace_set.count(*opr) > 0) *opr = replace_set[*opr];
}

static void replace_operand_in_one_stmt(
    unordered_map<AS_operand*, AS_operand*>& replace_set, L_stm* stm) {
  switch (stm->type) {
    case L_StmKind::T_BINOP: {
      replace_operand_in_one_operand(replace_set, &(stm->u.BINOP->left));
      replace_operand_in_one_operand(replace_set, &(stm->u.BINOP->right));
      replace_operand_in_one_operand(replace_set, &(stm->u.BINOP->dst));
    } break;
    case L_StmKind::T_LOAD: {
    } break;
    case L_StmKind::T_STORE: {
      replace_operand_in_one_operand(replace_set, &(stm->u.STORE->src));
    } break;
    case L_StmKind::T_LABEL: {
    } break;
    case L_StmKind::T_JUMP: {
    } break;
    case L_StmKind::T_CMP: {
      replace_operand_in_one_operand(replace_set, &(stm->u.CMP->left));
      replace_operand_in_one_operand(replace_set, &(stm->u.CMP->right));
      replace_operand_in_one_operand(replace_set, &(stm->u.CMP->dst));
    } break;
    case L_StmKind::T_CJUMP: {
      replace_operand_in_one_operand(replace_set, &(stm->u.CJUMP->dst));
    } break;
    case L_StmKind::T_MOVE: {
      replace_operand_in_one_operand(replace_set, &(stm->u.MOVE->src));
      replace_operand_in_one_operand(replace_set, &(stm->u.MOVE->dst));
    } break;
    case L_StmKind::T_CALL: {
      for (auto& arg : stm->u.CALL->args) {
        replace_operand_in_one_operand(replace_set, &(arg));
      }
    } break;
    case L_StmKind::T_VOID_CALL: {
      for (auto& arg : stm->u.VOID_CALL->args) {
        replace_operand_in_one_operand(replace_set, &(arg));
      }
    } break;
    case L_StmKind::T_RETURN: {
      if (stm->u.RET->ret != nullptr)
        replace_operand_in_one_operand(replace_set, &(stm->u.RET->ret));
    } break;
    case L_StmKind::T_ALLOCA: {
    } break;
    case L_StmKind::T_GEP: {
      replace_operand_in_one_operand(replace_set, &(stm->u.GEP->index));
    } break;
    default: {
      printf("%d\n", (int)stm->type);
      assert(0);
    }
  }
}

static void replace_use_in_one_stmt(
    unordered_map<AS_operand*, AS_operand*>& replace_set, L_stm* stm) {
  switch (stm->type) {
    case L_StmKind::T_BINOP: {
      replace_operand_in_one_operand(replace_set, &(stm->u.BINOP->left));
      replace_operand_in_one_operand(replace_set, &(stm->u.BINOP->right));
    } break;
    case L_StmKind::T_LOAD: {
    } break;
    case L_StmKind::T_STORE: {
      replace_operand_in_one_operand(replace_set, &(stm->u.STORE->src));
    } break;
    case L_StmKind::T_LABEL: {
    } break;
    case L_StmKind::T_JUMP: {
    } break;
    case L_StmKind::T_CMP: {
      replace_operand_in_one_operand(replace_set, &(stm->u.CMP->left));
      replace_operand_in_one_operand(replace_set, &(stm->u.CMP->right));
    } break;
    case L_StmKind::T_CJUMP: {
      replace_operand_in_one_operand(replace_set, &(stm->u.CJUMP->dst));
    } break;
    case L_StmKind::T_MOVE: {
      replace_operand_in_one_operand(replace_set, &(stm->u.MOVE->src));
    } break;
    case L_StmKind::T_CALL: {
      for (auto& arg : stm->u.CALL->args) {
        replace_operand_in_one_operand(replace_set, &(arg));
      }
    } break;
    case L_StmKind::T_VOID_CALL: {
      for (auto& arg : stm->u.VOID_CALL->args) {
        replace_operand_in_one_operand(replace_set, &(arg));
      }
    } break;
    case L_StmKind::T_RETURN: {
      if (stm->u.RET->ret != nullptr)
        replace_operand_in_one_operand(replace_set, &(stm->u.RET->ret));
    } break;
    case L_StmKind::T_ALLOCA: {
    } break;
    case L_StmKind::T_GEP: {
      replace_operand_in_one_operand(replace_set, &(stm->u.GEP->index));
    } break;
    case L_StmKind::T_PHI: {
      for (auto& phi : stm->u.PHI->phis) {
        replace_operand_in_one_operand(replace_set, &(phi.first));
      }

    } break;
    default: {
      printf("%d\n", (int)stm->type);
      assert(0);
    }
  }
}

static void replace_def_in_one_stmt(
    unordered_map<AS_operand*, AS_operand*>& replace_set, L_stm* stm) {
  switch (stm->type) {
    case L_StmKind::T_BINOP: {
      replace_operand_in_one_operand(replace_set, &(stm->u.BINOP->dst));
    } break;
    case L_StmKind::T_LOAD: {
      replace_operand_in_one_operand(replace_set, &(stm->u.LOAD->dst));
    } break;
    case L_StmKind::T_STORE: {
    } break;
    case L_StmKind::T_LABEL: {
    } break;
    case L_StmKind::T_JUMP: {
    } break;
    case L_StmKind::T_CMP: {
      replace_operand_in_one_operand(replace_set, &(stm->u.CMP->dst));
    } break;
    case L_StmKind::T_CJUMP: {
    } break;
    case L_StmKind::T_MOVE: {
      replace_operand_in_one_operand(replace_set, &(stm->u.MOVE->dst));
    } break;
    case L_StmKind::T_CALL: {
      replace_operand_in_one_operand(replace_set, &(stm->u.CALL->res));
    } break;
    case L_StmKind::T_VOID_CALL: {
    } break;
    case L_StmKind::T_RETURN: {
    } break;
    case L_StmKind::T_ALLOCA: {
    } break;
    case L_StmKind::T_GEP: {
    } break;
    case L_StmKind::T_PHI: {
      replace_operand_in_one_operand(replace_set, &(stm->u.PHI->dst));

    } break;
    default: {
      printf("%d\n", (int)stm->type);
      assert(0);
    }
  }
}

void mem2reg(LLVMIR::L_func* fun) {
  AS_operand* update_reg = nullptr;
  while ((update_reg = check_exist_mem_variable(fun)) != nullptr) {
    assert(update_reg->kind == OperandKind::TEMP);
    update_reg->u.TEMP->type = TempType::INT_TEMP;
    for (auto block : fun->blocks) {
      unordered_map<AS_operand*, AS_operand*> replace_set;
      for (auto it = block->instrs.begin(); it != block->instrs.end();) {
        auto s = *it;
        replace_operand_in_one_stmt(replace_set, s);
        if (s->type == L_StmKind::T_ALLOCA && s->u.ALLOCA->dst == update_reg) {
          s->type = L_StmKind::T_MOVE;
          delete s->u.ALLOCA;
          s->u.MOVE = new L_move(AS_Operand_Const(0), update_reg);
        } else if (s->type == L_StmKind::T_STORE &&
                   s->u.STORE->ptr == update_reg) {
          s->type = L_StmKind::T_MOVE;
          auto src = s->u.STORE->src;
          delete s->u.STORE;
          s->u.MOVE = new L_move(src, update_reg);
        } else if (s->type == L_StmKind::T_LOAD &&
                   s->u.LOAD->ptr == update_reg) {
          auto dst = s->u.LOAD->dst;
          delete s->u.LOAD;
          it = block->instrs.erase(it);
          replace_set.emplace(dst, update_reg);
          continue;
        }
        it++;
      }
    }
  }
}

bool calcu_Dominators(GRAPH::Node<LLVMIR::L_block*>* r,
                      GRAPH::Graph<LLVMIR::L_block*>& bg) {
  static const int calcu_Dominators_magic = 103;
  r->color = calcu_Dominators_magic;
  bool ret = false;
  auto block = r->info;

  if (r->preds.size() > 0) {
    for (auto it = dominators[block].begin(); it != dominators[block].end();) {
      auto r_dom = *it;

      if (r_dom == block) {
        it++;
        continue;
      }
      bool in_all_pre = true;
      for (auto pre_count : r->preds) {
        auto pre_node = bg.mynodes[pre_count];

        if (node_deprecated.count(pre_node->info) > 0) continue;

        if (dominators[pre_node->info].count(r_dom) == 0) {
          in_all_pre = false;
          break;
        }
      }
      if (!in_all_pre) {
        it = dominators[block].erase(it);
        ret = true;

      } else {
        it++;
      }
    }
  }

  for (auto succ_count : r->succs) {
    auto succ_node = bg.mynodes[succ_count];
    if (succ_node->color != calcu_Dominators_magic) {
      ret = ret | calcu_Dominators(succ_node, bg);
    }
  }

  return ret;
}

void init_Dominators(GRAPH::Node<LLVMIR::L_block*>* r,
                     GRAPH::Graph<LLVMIR::L_block*>& bg,
                     unordered_set<L_block*>& init_set) {
  static const int init_Dominators_maigc = 104;
  r->color = init_Dominators_maigc;
  dominators[r->info] = init_set;
  for (auto succ_count : r->succs) {
    auto succ_node = bg.mynodes[succ_count];
    if (succ_node->color != init_Dominators_maigc) {
      init_Dominators(succ_node, bg, init_set);
    }
  }
}

void Dominators(GRAPH::Graph<LLVMIR::L_block*>& bg) {
  unordered_set<L_block*> init_set = unordered_set<L_block*>();

  for (int i = 0; i < bg.nodecount; i++) {
    if (node_deprecated.count(bg.mynodes[i]->info) == 0)
      init_set.insert(bg.mynodes[i]->info);
  }
  init_Dominators(bg.mynodes[0], bg, init_set);
  auto root_block = bg.mynodes[0]->info;
  dominators[root_block].clear();
  dominators[root_block].insert(root_block);

  bool changed = true;
  int gi = 0;
  while (changed) {
    gi++;

    clearGraphColor(bg);
    changed = calcu_Dominators(bg.mynodes[0], bg);
  }
}

void printf_domi(FILE* out) {
  fprintf(out, "Dominator:\n");
  for (auto x : dominators) {
    fprintf(out, "%s :\n", x.first->label->name.c_str());
    for (auto t : x.second) {
      fprintf(out, "%s ", t->label->name.c_str());
    }
    fprintf(out, "\n\n");
  }
}

void printf_D_tree(FILE* out) {
  fprintf(out, "dominator tree:\n");
  for (auto x : tree_dominators) {
    fprintf(out, "%s :\n", x.first->label->name.c_str());
    for (auto t : x.second.succs) {
      fprintf(out, "%s ", t->label->name.c_str());
    }
    fprintf(out, "\n\n");
  }
}
void printf_DF(FILE* out) {
  fprintf(out, "DF:\n");
  for (auto x : DF_array) {
    fprintf(out, "%s :\n", x.first->label->name.c_str());
    for (auto t : x.second) {
      fprintf(out, "%s ", t->label->name.c_str());
    }
    fprintf(out, "\n\n");
  }
}

void DFS_tree_Dominators(GRAPH::Node<LLVMIR::L_block*>* r,
                         GRAPH::Graph<LLVMIR::L_block*>& bg) {
  static const int DFS_tree_Dominators_magic = 110;
  r->color = DFS_tree_Dominators_magic;
  if (r->mykey == 0) {
    tree_dominators[r->info].pred = nullptr;
  } else {
    L_block* imm_dom_father = nullptr;
    for (auto dom_block : dominators[r->info]) {
      if (dom_block == r->info) continue;

      bool is_father = true;
      /*
      (1)idom(n)和n不是同一个结点
      (2) idom(n)是n的必经结点
      (3) idom(n)不是 n的其他必经结点的必经结点。
      */
      for (auto other_dom_block : dominators[r->info]) {
        if (other_dom_block == r->info || other_dom_block == dom_block)
          continue;
        if (dominators[other_dom_block].count(dom_block) > 0) is_father = false;
      }
      if (is_father) {
        imm_dom_father = dom_block;
        tree_dominators[r->info].pred = dom_block;
        tree_dominators[dom_block].succs.insert(r->info);
        break;
      }
    }
    assert(imm_dom_father);
  }

  for (auto succ_count : r->succs) {
    auto succ_node = bg.mynodes[succ_count];
    if (succ_node->color != DFS_tree_Dominators_magic) {
      DFS_tree_Dominators(succ_node, bg);
    }
  }
}

void tree_Dominators(GRAPH::Graph<LLVMIR::L_block*>& bg) {
  DFS_tree_Dominators(bg.mynodes[0], bg);
}

void computeDF(GRAPH::Graph<LLVMIR::L_block*>& bg,
               GRAPH::Node<LLVMIR::L_block*>* r) {
  unordered_set<L_block*> S = unordered_set<L_block*>();

  for (auto succ_count : r->succs) {
    auto succ_node = bg.mynodes[succ_count];
    if (tree_dominators[succ_node->info].pred != r->info) {
      S.insert(succ_node->info);
    }
  }

  for (auto succ_in_dom_tree : tree_dominators[r->info].succs) {
    computeDF(bg, revers_graph[succ_in_dom_tree]);
    for (auto w : DF_array[succ_in_dom_tree]) {
      if (r->info == w || dominators[w].count(r->info) == 0) {
        S.insert(w);
      }
    }
  }
  DF_array[r->info] = S;
}

void Place_phi_fu(GRAPH::Graph<LLVMIR::L_block*>& bg, L_func* fun) {
  for (int i = 0; i < bg.nodecount; i++) {
    auto node = bg.mynodes[i];

    if (node_deprecated.count(node->info) > 0) continue;
    for (auto def_temp : FG_def(node)) {
      defsite[def_temp].insert(node);
    }
  }
  for (auto temp_set_pair : defsite) {
    auto a = temp_set_pair.first;
    auto a_operand = temp2ASoper[a];
    auto W = temp_set_pair.second;
    while (!W.empty()) {
      auto it = W.begin();
      auto n = *it;
      for (auto Y : DF_array[n->info]) {
        auto Y_node = revers_graph[Y];
        if (place_phi_set[Y].count(a) == 0 && FG_In(Y_node).count(a) > 0) {
          auto insert_phi_place = Y->instrs.begin();
          insert_phi_place++;
          auto phis = vector<std::pair<AS_operand*, Temp_label*>>();
          for (auto Y_pre_count : Y_node->preds) {
            auto Y_pre_node = bg.mynodes[Y_pre_count];
            if (node_deprecated.count(Y_pre_node->info) > 0) continue;
            phis.emplace_back(a_operand, Y_pre_node->info->label);
          }
          auto phi_stm = L_Phi(a_operand, phis);
          Y->instrs.insert(insert_phi_place, phi_stm);

          place_phi_set[Y].insert(a);
          if (FG_def(Y_node).count(a) == 0) {
            W.insert(Y_node);
          }
        }
      }

      W.erase(it);
    }
  }
}

static list<AS_operand**> get_def_int_operand(LLVMIR::L_stm* stm) {
  list<AS_operand**> ret1 = get_def_operand(stm), ret2;
  for (auto AS_op : ret1) {
    if ((**AS_op).u.TEMP->type == TempType::INT_TEMP) {
      ret2.push_back(AS_op);
    }
  }
  return ret2;
}

static list<AS_operand**> get_use_int_operand(LLVMIR::L_stm* stm) {
  list<AS_operand**> ret1 = get_use_operand(stm), ret2;
  for (auto AS_op : ret1) {
    if ((**AS_op).u.TEMP->type == TempType::INT_TEMP) {
      ret2.push_back(AS_op);
    }
  }
  return ret2;
}

static void Rename_temp(GRAPH::Graph<LLVMIR::L_block*>& bg,
                        GRAPH::Node<LLVMIR::L_block*>* n,
                        unordered_map<Temp_temp*, stack<Temp_temp*>>& Stack) {
  static const int Rename_temp_magic = 120;
  n->color = 120;
  unordered_map<Temp_temp*, int> stack_push_count;
  for (auto s : n->info->instrs) {
    if (s->type != L_StmKind::T_PHI) {
      auto use_temp_list = get_use_temp(s);
      for (auto use_temp : use_temp_list) {
        if (use_temp->type != TempType::INT_TEMP) continue;
        auto replace_temp = Stack[use_temp].top();
        if (replace_temp != use_temp) {
          auto replace_set = unordered_map<AS_operand*, AS_operand*>();
          replace_set.emplace(temp2ASoper[use_temp], temp2ASoper[replace_temp]);
          replace_use_in_one_stmt(replace_set, s);
        }
      }
    }
    auto def_temp_list = get_def_temp(s);
    for (auto def_temp : def_temp_list) {
      auto new_def_temp_name = Temp_newtemp_int();
      auto new_def_temp_operand = AS_Operand_Temp(new_def_temp_name);
      temp2ASoper[new_def_temp_name] = new_def_temp_operand;
      Stack[def_temp].push(new_def_temp_name);
      stack_push_count[def_temp]++;
      auto replace_set = unordered_map<AS_operand*, AS_operand*>();
      replace_set.emplace(temp2ASoper[def_temp],
                          temp2ASoper[new_def_temp_name]);
      replace_def_in_one_stmt(replace_set, s);
    }
  }

  for (auto succ_count : n->succs) {
    auto Y = bg.mynodes[succ_count];

    int j = 0;
    for (auto succ_pred_count : Y->preds) {
      auto succ_pred_node = bg.mynodes[succ_pred_count];
      if (node_deprecated.count(succ_pred_node->info) > 0) continue;
      if (succ_pred_node == n) {
        break;
      } else {
        j++;
      }
    }
    assert(j < Y->preds.size());
    for (auto s_Y : Y->info->instrs) {
      if (s_Y->type != L_StmKind::T_PHI) continue;
      auto a_temp = s_Y->u.PHI->phis[j].first;
      assert(n->info->label == s_Y->u.PHI->phis[j].second);
      auto replace_temp = Stack[a_temp->u.TEMP].top();
      s_Y->u.PHI->phis[j].first = temp2ASoper[replace_temp];
    }
  }

  for (auto succ_count : n->succs) {
    auto succ_node = bg.mynodes[succ_count];
    if (succ_node->color != Rename_temp_magic) {
      Rename_temp(bg, succ_node, Stack);
    }
  }

  for (auto p : stack_push_count) {
    for (int i = 0; i < p.second; i++) {
      Stack[p.first].pop();
    }
  }
}

void Rename(GRAPH::Graph<LLVMIR::L_block*>& bg) {
  unordered_map<Temp_temp*, stack<Temp_temp*>> Stack =
      unordered_map<Temp_temp*, stack<Temp_temp*>>();
  for (auto temp_pair : temp2ASoper) {
    auto temp = temp_pair.first;
    if (temp->type == TempType::INT_TEMP) Stack[temp].push(temp);
  }
  Rename_temp(bg, bg.mynodes[0], Stack);
}

void comput_reverse_graph(GRAPH::Graph<LLVMIR::L_block*>& bg) {
  for (int i = 0; i < bg.nodecount; i++) {
    auto node = bg.mynodes[i];
    revers_graph[node->info] = node;
  }
}