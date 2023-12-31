#include "ast2llvm.h"
#include "TeaplAst.h"
#include "llvm_ir.h"
#include "temp.h"
#include <list>
#include <string>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;
using namespace LLVMIR;

static unordered_map<string, FuncType> funcReturnMap;
static unordered_map<string, StructInfo> structInfoMap;
static unordered_map<string, Name_name *> globalVarMap;
static unordered_map<string, Temp_temp *> localVarMap;
static list<L_stm *> emit_irs;

LLVMIR::L_prog *ast2llvm(aA_program p) {
  auto defs = ast2llvmProg_first(p);
  auto funcs = ast2llvmProg_second(p);
  vector<L_func *> funcs_block;

  // Modify the loop to use a reference to avoid unnecessary copies
  for (auto &f : funcs) {
    funcs_block.push_back(ast2llvmFuncBlock(f));
  }

  // Introduce a separate loop for moving Alloca instructions
  for (auto &f : funcs_block) {
    ast2llvm_moveAlloca(f);
  }

  return new L_prog(defs, funcs_block);
}


int ast2llvmRightVal_first(aA_rightVal r) {
  if (r == nullptr) {
    return 0;
  }
  switch (r->kind) {
    case A_arithExprValKind: {
      return ast2llvmArithExpr_first(r->u.arithExpr);
      break;
    }
    case A_boolExprValKind: {
      return ast2llvmBoolExpr_first(r->u.boolExpr);
      break;
    }
    default:
      break;
  }
  return 0;
}

int ast2llvmBoolExpr_first(aA_boolExpr b) {
  switch (b->kind) {
    case A_boolBiOpExprKind: {
      return ast2llvmBoolBiOpExpr_first(b->u.boolBiOpExpr);
      break;
    }
    case A_boolUnitKind: {
      return ast2llvmBoolUnit_first(b->u.boolUnit);
      break;
    }
    default:
      break;
  }
  return 0;
}

int ast2llvmBoolBiOpExpr_first(aA_boolBiOpExpr b) {
  int l = ast2llvmBoolExpr_first(b->left);
  int r = ast2llvmBoolExpr_first(b->right);
  if (b->op == A_and) {
    return l && r;
  } else {
    return l || r;
  }
}

int ast2llvmBoolUOpExpr_first(aA_boolUOpExpr b) {
  if (b->op == A_not) {
    return !ast2llvmBoolUnit_first(b->cond);
  }
  return 0;
}

int ast2llvmBoolUnit_first(aA_boolUnit b) {
  switch (b->kind) {
    case A_comOpExprKind: {
      return ast2llvmComOpExpr_first(b->u.comExpr);
      break;
    }
    case A_boolExprKind: {
      return ast2llvmBoolExpr_first(b->u.boolExpr);
      break;
    }
    case A_boolUOpExprKind: {
      return ast2llvmBoolUOpExpr_first(b->u.boolUOpExpr);
      break;
    }
    default:
      break;
  }
  return 0;
}

int ast2llvmComOpExpr_first(aA_comExpr c) {
  auto l = ast2llvmExprUnit_first(c->left);
  auto r = ast2llvmExprUnit_first(c->right);
  switch (c->op) {
    case A_lt: {
      return l < r;
      break;
    }
    case A_le: {
      return l <= r;
      break;
    }
    case A_gt: {
      return l > r;
      break;
    }
    case A_ge: {
      return l >= r;
      break;
    }
    case A_eq: {
      return l == r;
      break;
    }
    case A_ne: {
      return l != r;
      break;
    }
    default:
      break;
  }
  return 0;
}

int ast2llvmArithBiOpExpr_first(aA_arithBiOpExpr a) {
  auto l = ast2llvmArithExpr_first(a->left);
  auto r = ast2llvmArithExpr_first(a->right);
  switch (a->op) {
    case A_add: {
      return l + r;
      break;
    }
    case A_sub: {
      return l - r;
      break;
    }
    case A_mul: {
      return l * r;
      break;
    }
    case A_div: {
      return l / r;
      break;
    }
    default:
      break;
  }
  return 0;
}

int ast2llvmArithUExpr_first(aA_arithUExpr a) {
  if (a->op == A_neg) {
    return -ast2llvmExprUnit_first(a->expr);
  }
  return 0;
}

int ast2llvmArithExpr_first(aA_arithExpr a) {
  switch (a->kind) {
    case A_arithBiOpExprKind: {
      return ast2llvmArithBiOpExpr_first(a->u.arithBiOpExpr);
      break;
    }
    case A_exprUnitKind: {
      return ast2llvmExprUnit_first(a->u.exprUnit);
      break;
    }
    default:
      assert(0);
      break;
  }
  return 0;
}

int ast2llvmExprUnit_first(aA_exprUnit e) {
  if (e->kind == A_numExprKind) {
    return e->u.num;
  } else if (e->kind == A_arithExprKind) {
    return ast2llvmArithExpr_first(e->u.arithExpr);
  } else if (e->kind == A_arithUExprKind) {
    return ast2llvmArithUExpr_first(e->u.arithUExpr);
  } else {
    assert(0);
  }
  return 0;
}

std::vector<LLVMIR::L_def *> ast2llvmProg_first(aA_program p) {
  vector<L_def *> defs;
  defs.push_back(
      L_Funcdecl("getch", vector<TempDef>(), FuncType(ReturnType::INT_TYPE)));
  defs.push_back(
      L_Funcdecl("getint", vector<TempDef>(), FuncType(ReturnType::INT_TYPE)));
  defs.push_back(L_Funcdecl("putch",
                            vector<TempDef>{TempDef(TempType::INT_TEMP)},
                            FuncType(ReturnType::VOID_TYPE)));
  defs.push_back(L_Funcdecl("putint",
                            vector<TempDef>{TempDef(TempType::INT_TEMP)},
                            FuncType(ReturnType::VOID_TYPE)));
  defs.push_back(L_Funcdecl("putarray",
                            vector<TempDef>{TempDef(TempType::INT_TEMP),
                                            TempDef(TempType::INT_PTR, -1)},
                            FuncType(ReturnType::VOID_TYPE)));
  defs.push_back(L_Funcdecl("_sysy_starttime",
                            vector<TempDef>{TempDef(TempType::INT_TEMP)},
                            FuncType(ReturnType::VOID_TYPE)));
  defs.push_back(L_Funcdecl("_sysy_stoptime",
                            vector<TempDef>{TempDef(TempType::INT_TEMP)},
                            FuncType(ReturnType::VOID_TYPE)));
  for (const auto &v : p->programElements) {
    switch (v->kind) {
      case A_programNullStmtKind: {
        break;
      }
      case A_programVarDeclStmtKind: {
        if (v->u.varDeclStmt->kind == A_varDeclKind) {
          if (v->u.varDeclStmt->u.varDecl->kind == A_varDeclScalarKind) {
            if (v->u.varDeclStmt->u.varDecl->u.declScalar->type->type ==
                A_structTypeKind) {
              globalVarMap.emplace(
                  *v->u.varDeclStmt->u.varDecl->u.declScalar->id,
                  Name_newname_struct(
                      Temp_newlabel_named(
                          *v->u.varDeclStmt->u.varDecl->u.declScalar->id),
                      *v->u.varDeclStmt->u.varDecl->u.declScalar->type->u
                           .structType));
              TempDef def(TempType::STRUCT_TEMP, 0,
                          *v->u.varDeclStmt->u.varDecl->u.declScalar->type->u
                               .structType);
              defs.push_back(
                  L_Globaldef(*v->u.varDeclStmt->u.varDecl->u.declScalar->id,
                              def, vector<int>()));
            } else {
              globalVarMap.emplace(
                  *v->u.varDeclStmt->u.varDecl->u.declScalar->id,
                  Name_newname_int(Temp_newlabel_named(
                      *v->u.varDeclStmt->u.varDecl->u.declScalar->id)));
              TempDef def(TempType::INT_TEMP, 0);
              defs.push_back(
                  L_Globaldef(*v->u.varDeclStmt->u.varDecl->u.declScalar->id,
                              def, vector<int>()));
            }
          } else if (v->u.varDeclStmt->u.varDecl->kind == A_varDeclArrayKind) {
            if (v->u.varDeclStmt->u.varDecl->u.declArray->type->type ==
                A_structTypeKind) {
              globalVarMap.emplace(
                  *v->u.varDeclStmt->u.varDecl->u.declArray->id,
                  Name_newname_struct_ptr(
                      Temp_newlabel_named(
                          *v->u.varDeclStmt->u.varDecl->u.declArray->id),
                      v->u.varDeclStmt->u.varDecl->u.declArray->len,
                      *v->u.varDeclStmt->u.varDecl->u.declArray->type->u
                           .structType));
              TempDef def(TempType::STRUCT_PTR,
                          v->u.varDeclStmt->u.varDecl->u.declArray->len,
                          *v->u.varDeclStmt->u.varDecl->u.declArray->type->u
                               .structType);
              defs.push_back(
                  L_Globaldef(*v->u.varDeclStmt->u.varDecl->u.declArray->id,
                              def, vector<int>()));
            } else {
              globalVarMap.emplace(
                  *v->u.varDeclStmt->u.varDecl->u.declArray->id,
                  Name_newname_int_ptr(
                      Temp_newlabel_named(
                          *v->u.varDeclStmt->u.varDecl->u.declArray->id),
                      v->u.varDeclStmt->u.varDecl->u.declArray->len));
              TempDef def(TempType::INT_PTR,
                          v->u.varDeclStmt->u.varDecl->u.declArray->len);
              defs.push_back(
                  L_Globaldef(*v->u.varDeclStmt->u.varDecl->u.declArray->id,
                              def, vector<int>()));
            }
          } else {
            assert(0);
          }
        } else if (v->u.varDeclStmt->kind == A_varDefKind) {
          if (v->u.varDeclStmt->u.varDef->kind == A_varDefScalarKind) {
            if (v->u.varDeclStmt->u.varDef->u.defScalar->type->type ==
                A_structTypeKind) {
              globalVarMap.emplace(
                  *v->u.varDeclStmt->u.varDef->u.defScalar->id,
                  Name_newname_struct(
                      Temp_newlabel_named(
                          *v->u.varDeclStmt->u.varDef->u.defScalar->id),
                      *v->u.varDeclStmt->u.varDef->u.defScalar->type->u
                           .structType));
              TempDef def(
                  TempType::STRUCT_TEMP, 0,
                  *v->u.varDeclStmt->u.varDef->u.defScalar->type->u.structType);
              defs.push_back(
                  L_Globaldef(*v->u.varDeclStmt->u.varDef->u.defScalar->id, def,
                              vector<int>()));
            } else {
              globalVarMap.emplace(
                  *v->u.varDeclStmt->u.varDef->u.defScalar->id,
                  Name_newname_int(Temp_newlabel_named(
                      *v->u.varDeclStmt->u.varDef->u.defScalar->id)));
              TempDef def(TempType::INT_TEMP, 0);
              vector<int> init;
              init.push_back(ast2llvmRightVal_first(
                  v->u.varDeclStmt->u.varDef->u.defScalar->val));
              defs.push_back(L_Globaldef(
                  *v->u.varDeclStmt->u.varDef->u.defScalar->id, def, init));
            }
          } else if (v->u.varDeclStmt->u.varDef->kind == A_varDefArrayKind) {
            if (v->u.varDeclStmt->u.varDef->u.defArray->type->type ==
                A_structTypeKind) {
              globalVarMap.emplace(
                  *v->u.varDeclStmt->u.varDef->u.defArray->id,
                  Name_newname_struct_ptr(
                      Temp_newlabel_named(
                          *v->u.varDeclStmt->u.varDef->u.defArray->id),
                      v->u.varDeclStmt->u.varDef->u.defArray->len,
                      *v->u.varDeclStmt->u.varDef->u.defArray->type->u
                           .structType));
              TempDef def(
                  TempType::STRUCT_PTR,
                  v->u.varDeclStmt->u.varDef->u.defArray->len,
                  *v->u.varDeclStmt->u.varDef->u.defArray->type->u.structType);
              defs.push_back(
                  L_Globaldef(*v->u.varDeclStmt->u.varDef->u.defArray->id, def,
                              vector<int>()));
            } else {
              globalVarMap.emplace(
                  *v->u.varDeclStmt->u.varDef->u.defArray->id,
                  Name_newname_int_ptr(
                      Temp_newlabel_named(
                          *v->u.varDeclStmt->u.varDef->u.defArray->id),
                      v->u.varDeclStmt->u.varDef->u.defArray->len));
              TempDef def(TempType::INT_PTR,
                          v->u.varDeclStmt->u.varDef->u.defArray->len);
              vector<int> init;
              for (auto &el : v->u.varDeclStmt->u.varDef->u.defArray->vals) {
                init.push_back(ast2llvmRightVal_first(el));
              }
              defs.push_back(L_Globaldef(
                  *v->u.varDeclStmt->u.varDef->u.defArray->id, def, init));
            }
          } else {
            assert(0);
          }
        } else {
          assert(0);
        }
        break;
      }
      case A_programStructDefKind: {
        StructInfo si;
        int off = 0;
        vector<TempDef> members;
        for (const auto &decl : v->u.structDef->varDecls) {
          if (decl->kind == A_varDeclScalarKind) {
            if (decl->u.declScalar->type->type == A_structTypeKind) {
              TempDef def(TempType::STRUCT_TEMP, 0,
                          *decl->u.declScalar->type->u.structType);
              MemberInfo info(off++, def);
              si.memberinfos.emplace(*decl->u.declScalar->id, info);
              members.push_back(def);
            } else {
              TempDef def(TempType::INT_TEMP, 0);
              MemberInfo info(off++, def);
              si.memberinfos.emplace(*decl->u.declScalar->id, info);
              members.push_back(def);
            }
          } else if (decl->kind == A_varDeclArrayKind) {
            if (decl->u.declArray->type->type == A_structTypeKind) {
              TempDef def(TempType::STRUCT_PTR, decl->u.declArray->len,
                          *decl->u.declArray->type->u.structType);
              MemberInfo info(off++, def);
              si.memberinfos.emplace(*decl->u.declArray->id, info);
              members.push_back(def);
            } else {
              TempDef def(TempType::INT_PTR, decl->u.declArray->len);
              MemberInfo info(off++, def);
              si.memberinfos.emplace(*decl->u.declArray->id, info);
              members.push_back(def);
            }
          } else {
            assert(0);
          }
        }
        structInfoMap.emplace(*v->u.structDef->id, std::move(si));
        defs.push_back(L_Structdef(*v->u.structDef->id, members));
        break;
      }
      case A_programFnDeclStmtKind: {
        FuncType type;
        if (v->u.fnDeclStmt->fnDecl->type == nullptr) {
          type.type = ReturnType::VOID_TYPE;
        }
        if (v->u.fnDeclStmt->fnDecl->type->type == A_nativeTypeKind) {
          type.type = ReturnType::INT_TYPE;
        } else if (v->u.fnDeclStmt->fnDecl->type->type == A_structTypeKind) {
          type.type = ReturnType::STRUCT_TYPE;
          type.structname = *v->u.fnDeclStmt->fnDecl->type->u.structType;
        } else {
          assert(0);
        }
        if (funcReturnMap.find(*v->u.fnDeclStmt->fnDecl->id) ==
            funcReturnMap.end())
          funcReturnMap.emplace(*v->u.fnDeclStmt->fnDecl->id, std::move(type));
        vector<TempDef> args;
        for (const auto &decl : v->u.fnDeclStmt->fnDecl->paramDecl->varDecls) {
          if (decl->kind == A_varDeclScalarKind) {
            if (decl->u.declScalar->type->type == A_structTypeKind) {
              TempDef def(TempType::STRUCT_PTR, 0,
                          *decl->u.declScalar->type->u.structType);
              args.push_back(def);
            } else {
              TempDef def(TempType::INT_TEMP, 0);
              args.push_back(def);
            }
          } else if (decl->kind == A_varDeclArrayKind) {
            if (decl->u.declArray->type->type == A_structTypeKind) {
              TempDef def(TempType::STRUCT_PTR, -1,
                          *decl->u.declArray->type->u.structType);
              args.push_back(def);
            } else {
              TempDef def(TempType::INT_PTR, -1);
              args.push_back(def);
            }
          } else {
            assert(0);
          }
        }
        defs.push_back(L_Funcdecl(*v->u.fnDeclStmt->fnDecl->id, args, type));
        break;
      }
      case A_programFnDefKind: {
        if (funcReturnMap.find(*v->u.fnDef->fnDecl->id) ==
            funcReturnMap.end()) {
          FuncType type;
          if (v->u.fnDef->fnDecl->type == nullptr) {
            type.type = ReturnType::VOID_TYPE;
          } else if (v->u.fnDef->fnDecl->type->type == A_nativeTypeKind) {
            type.type = ReturnType::INT_TYPE;
          } else if (v->u.fnDef->fnDecl->type->type == A_structTypeKind) {
            type.type = ReturnType::STRUCT_TYPE;
            type.structname = *v->u.fnDef->fnDecl->type->u.structType;
          } else {
            assert(0);
          }
          funcReturnMap.emplace(*v->u.fnDef->fnDecl->id, std::move(type));
        }
        break;
      }
      default:
        assert(0);
        break;
    }
  }
  return defs;
}

std::vector<Func_local *> ast2llvmProg_second(aA_program p) {
  vector<Func_local *> funcs;
  for (const auto &v : p->programElements) {
    if (v->kind != A_programFnDefKind) continue;
    funcs.push_back(ast2llvmFunc(v->u.fnDef));
  }
  return funcs;
}

Func_local *ast2llvmFunc(aA_fnDef f) {
  localVarMap.clear();
  string name = *f->fnDecl->id;
  FuncType type;
  if (f->fnDecl->type == nullptr) {
    type.type = ReturnType::VOID_TYPE;
  } else if (f->fnDecl->type->type == A_nativeTypeKind) {
    type.type = ReturnType::INT_TYPE;
  } else if (f->fnDecl->type->type == A_structTypeKind) {
    assert(0);
    type.type = ReturnType::STRUCT_TYPE;
    type.structname = *f->fnDecl->type->u.structType;
  } else {
    assert(0);
  }
  emit_irs.clear();
  emit_irs.emplace_back(L_Label(Temp_newlabel()));
  vector<Temp_temp *> args;
  for (const auto &decl : f->fnDecl->paramDecl->varDecls) {
    if (decl->kind == A_varDeclScalarKind) {
      if (decl->u.declScalar->type->type == A_structTypeKind) {
        auto def =
            Temp_newtemp_struct_ptr(0, *decl->u.declScalar->type->u.structType);
        def->varname = *decl->u.declScalar->id;
        args.push_back(def);
        localVarMap.emplace(def->varname, def);
      } else {
        auto def = Temp_newtemp_int();
        def->varname = *decl->u.declScalar->id;
        args.push_back(def);
        auto replace_ptr = Temp_newtemp_int_ptr(0);
        emit_irs.emplace_back(L_Alloca(AS_Operand_Temp(replace_ptr)));
        emit_irs.emplace_back(
            L_Store(AS_Operand_Temp(def), AS_Operand_Temp(replace_ptr)));
        localVarMap.emplace(def->varname, replace_ptr);
      }
    } else if (decl->kind == A_varDeclArrayKind) {
      if (decl->u.declArray->type->type == A_structTypeKind) {
        auto def =
            Temp_newtemp_struct_ptr(-1, *decl->u.declArray->type->u.structType);
        def->varname = *decl->u.declArray->id;
        args.push_back(def);
        localVarMap.emplace(def->varname, def);
      } else {
        auto def = Temp_newtemp_int_ptr(-1);
        def->varname = *decl->u.declArray->id;
        args.push_back(def);
        localVarMap.emplace(def->varname, def);
      }
    } else {
      assert(0);
    }
  }

  for (auto stmt : f->stmts) {
    ast2llvmBlock(stmt);
  }
  if(emit_irs.back()->type != L_StmKind::T_RETURN){
    if(type.type == ReturnType::VOID_TYPE){
      emit_irs.emplace_back(L_Ret(nullptr));
    }else{
      emit_irs.emplace_back(L_Ret(AS_Operand_Const(0)));
    }
  }
  list<L_stm *> ir = emit_irs;
  emit_irs.clear();
  return new Func_local(name, type, args, ir);
} 


AS_operand *ast2llvmArithBiOpExpr(aA_arithBiOpExpr a) {
  auto left = ast2llvmArithExpr(a->left);
  auto right = ast2llvmArithExpr(a->right);
  auto dst = AS_Operand_Temp(Temp_newtemp_int());
  switch (a->op) {
    case A_arithBiOp::A_add:
      emit_irs.emplace_back(L_Binop(L_binopKind::T_plus, left, right, dst));
      break;
    case A_arithBiOp::A_div:
      emit_irs.emplace_back(L_Binop(L_binopKind::T_div, left, right, dst));
      break;
    case A_arithBiOp::A_mul:
      emit_irs.emplace_back(L_Binop(L_binopKind::T_mul, left, right, dst));
      break;
    case A_arithBiOp::A_sub:
      emit_irs.emplace_back(L_Binop(L_binopKind::T_minus, left, right, dst));
      break;

    default:
      assert(0);
      break;
  }
  return dst;
}

AS_operand *ast2llvmArithUExpr(aA_arithUExpr a) {
  AS_operand *left = AS_Operand_Const(0);
  AS_operand *right = ast2llvmExprUnit(a->expr);
  AS_operand *dst = AS_Operand_Temp(Temp_newtemp_int());
  emit_irs.emplace_back(L_Binop(L_binopKind::T_minus, left, right, dst));
  return dst;
}

AS_operand *ast2llvmArithExpr(aA_arithExpr a) {
  if (a->kind == A_arithExprType::A_arithBiOpExprKind) {
    return ast2llvmArithBiOpExpr(a->u.arithBiOpExpr);
  } else if (a->kind == A_arithExprType::A_exprUnitKind) {
    return ast2llvmExprUnit(a->u.exprUnit);
  } else
    assert(0);
  return nullptr;
}

AS_operand *ast2llvmExprUnit(aA_exprUnit e) {
  if (e->kind == A_exprUnitType::A_arithExprKind) {
    return ast2llvmArithExpr(e->u.arithExpr);
  } else if (e->kind == A_exprUnitType::A_arithUExprKind) {
    return ast2llvmArithUExpr(e->u.arithUExpr);
  } else if (e->kind == A_exprUnitType::A_arrayExprKind) {
    auto temp_ptr = ast2llvmArrayExpr(e->u.arrayExpr);
    auto temp_val = AS_Operand_Temp(Temp_newtemp_int());
    emit_irs.emplace_back(L_Load(temp_val, temp_ptr));
    return temp_val;
  } else if (e->kind == A_exprUnitType::A_fnCallKind) {
    vector<AS_operand *> args;
    for (auto val : e->u.callExpr->vals) {
      args.push_back(ast2llvmRightVal(val));
    }
    auto dst = AS_Operand_Temp(Temp_newtemp_int());
    emit_irs.push_back(L_Call(*e->u.callExpr->fn, dst, args));
    return dst;
  } else if (e->kind == A_exprUnitType::A_idExprKind) {
    auto temp_ptr = ast2llvmIdExpr(*e->u.id);

    if (temp_ptr->kind == OperandKind::TEMP &&
        temp_ptr->u.TEMP->type == TempType::INT_TEMP) {
      assert(0);
      return temp_ptr;
    } else if (temp_ptr->kind == OperandKind::TEMP &&
               temp_ptr->u.TEMP->type == TempType::INT_PTR &&
               temp_ptr->u.TEMP->len == 0) {
      auto val_dst_operand = AS_Operand_Temp(Temp_newtemp_int());
      emit_irs.emplace_back(L_Load(val_dst_operand, temp_ptr));
      return val_dst_operand;
    } else if (temp_ptr->kind == OperandKind::NAME &&
               temp_ptr->u.NAME->type == TempType::INT_TEMP) {
      // 全局变量int
      auto val_dst_operand = AS_Operand_Temp(Temp_newtemp_int());
      emit_irs.emplace_back(L_Load(val_dst_operand, temp_ptr));
      return val_dst_operand;
    } else if (temp_ptr->kind == OperandKind::ICONST) {
      return temp_ptr;
    } else {

      return temp_ptr;
    }
  } else if (e->kind == A_exprUnitType::A_memberExprKind) {
    auto ptr = ast2llvmMemberExpr(e->u.memberExpr);
    auto val = AS_Operand_Temp(Temp_newtemp_int());
    emit_irs.emplace_back(L_Load(val, ptr));
    return val;
  } else if (e->kind == A_exprUnitType::A_numExprKind) {
    return AS_Operand_Const(e->u.num);
  } else
    assert(0);
  assert(0);
  return nullptr;
}

AS_operand *ast2llvmIdExpr(string id) {
  if (localVarMap.count(id) > 0) {
    auto temp = localVarMap[id];
    return AS_Operand_Temp(temp);
  } else if (globalVarMap.count(id) > 0) {
    auto name = globalVarMap[id];
    return AS_Operand_Name(name);
  } else
    assert(0);
}

Temp_temp *ast2llvmLoadGlobalVar(Name_name *name) {
  if (name->type == TempType::INT_TEMP) {
    return Temp_newtemp_int();
  } else {
    assert(0);
    return nullptr;
  }
}

Temp_temp *ast2llvmLoadLocalVar(Temp_temp *temp) {
  if (temp->type == TempType::INT_TEMP) {
    return Temp_newtemp_int();
  } else {
    assert(0);
    return nullptr;
  }
}

LLVMIR::L_func *ast2llvmFuncBlock(Func_local *f) {
  for (auto it = f->irs.begin(); it != f->irs.end(); ++it) {
    auto it_next = std::next(it, 1);
    if ((*it)->type == L_StmKind::T_RETURN && it_next != f->irs.end() && (*it_next)->type != L_StmKind::T_LABEL) {
      ++it;
      auto label_stm = L_Label(Temp_newlabel());
      it = f->irs.insert(it, label_stm);
    }
  }

  list<L_block *> blocks;
  assert(f->irs.front()->type == L_StmKind::T_LABEL);
  list<L_stm *> instrs;
  for (auto ir : f->irs) {
    if (ir->type == L_StmKind::T_LABEL && !instrs.empty()) {
      blocks.emplace_back(L_Block(instrs));
      instrs.clear();
    }
    instrs.emplace_back(ir);
  }

  if (!instrs.empty()) {
    blocks.emplace_back(L_Block(instrs));
    instrs.clear();
  }

  return new L_func(f->name, f->ret, f->args, blocks);
}


void ast2llvm_moveAlloca(LLVMIR::L_func *f) {
  auto block_first = f->blocks.front();
  
  for (auto block : f->blocks) {
    if (block == f->blocks.front()) continue;

    // Use iterators to traverse the source list
    for (auto it = block->instrs.begin(); it != block->instrs.end();) {
      if ((*it)->type == L_StmKind::T_ALLOCA) {
        // Move elements that meet the condition from the source list to the target list
        auto insertPos = std::next(block_first->instrs.begin(), 1);
        block_first->instrs.insert(insertPos, *it);
        it = block->instrs.erase(it);  // Delete the current element and get the next element's iterator
      } else {
        ++it;  // Move to the next element
      }
    }
  }
}

void ast2llvmBlock(aA_codeBlockStmt b, Temp_label *con_label,
                   Temp_label *bre_label) {
  switch (b->kind) {
    case A_codeBlockStmtType::A_nullStmtKind: {
      break;
    }
    case A_codeBlockStmtType::A_varDeclStmtKind: {
      ast2llvmVarDeclStmt(b->u.varDeclStmt);
      break;
    }
    case A_codeBlockStmtType::A_assignStmtKind: {
      ast2llvmAssignStmt(b->u.assignStmt);
      break;
    }
    case A_codeBlockStmtType::A_callStmtKind: {
      ast2llvmCallStmt(b->u.callStmt);
      break;
    }
    case A_codeBlockStmtType::A_ifStmtKind: {
      ast2llvmIfStmt(b->u.ifStmt);
      break;
    }
    case A_codeBlockStmtType::A_whileStmtKind: {
      ast2llvmWhileStmt(b->u.whileStmt);
      break;
    }
    case A_codeBlockStmtType::A_returnStmtKind: {
      ast2llvmReturnStmt(b->u.returnStmt);
      break;
    }
    case A_codeBlockStmtType::A_continueStmtKind: {
      if (con_label == nullptr) assert(0);
      emit_irs.emplace_back(L_Jump(con_label));
      break;
    }
    case A_codeBlockStmtType::A_breakStmtKind: {
      if (bre_label == nullptr) assert(0);
      emit_irs.emplace_back(L_Jump(bre_label));
      break;
    }
    default:
      assert(0);
      break;
  }
}
void ast2llvmVarDeclStmt(aA_varDeclStmt s) {
  if (s->kind == A_varDeclStmtType::A_varDeclKind) {
    Temp_temp *temp;
    if (s->u.varDecl->kind == A_varDeclType::A_varDeclScalarKind) {
      if (s->u.varDecl->u.declScalar->type->type ==
          A_dataType::A_structTypeKind) {
        temp = Temp_newtemp_struct_ptr(
            0, *s->u.varDecl->u.declScalar->type->u.structType);
        temp->varname = *s->u.varDecl->u.declScalar->id;
      } else {
        temp = Temp_newtemp_int_ptr(0);
        temp->varname = *s->u.varDecl->u.declScalar->id;
      }
    } else if (s->u.varDecl->kind == A_varDeclType::A_varDeclArrayKind) {
      if (s->u.varDecl->u.declArray->type->type ==
          A_dataType::A_structTypeKind) {
        temp = Temp_newtemp_struct_ptr(
            s->u.varDecl->u.declArray->len,
            *s->u.varDecl->u.declArray->type->u.structType);
        temp->varname = *s->u.varDecl->u.declArray->id;
      } else {
        temp = Temp_newtemp_int_ptr(s->u.varDecl->u.declArray->len);
        temp->varname = *s->u.varDecl->u.declArray->id;
      }
    } else
      assert(0);

    localVarMap.emplace(temp->varname, temp);
    auto operand = AS_Operand_Temp(temp);
    emit_irs.push_back(L_Alloca(operand));

  } else if (s->kind == A_varDeclStmtType::A_varDefKind) {
    if (s->u.varDef->kind == A_varDefType::A_varDefScalarKind) {
      if (s->u.varDef->u.defScalar->type->type ==
          A_dataType::A_structTypeKind) {
        // 单个结构体的定义
        auto temp = Temp_newtemp_struct_ptr(
            0, *s->u.varDef->u.defScalar->type->u.structType);
        temp->varname = *s->u.varDef->u.defScalar->id;
        localVarMap.emplace(temp->varname, temp);
        auto operand = AS_Operand_Temp(temp);
        emit_irs.push_back(L_Alloca(operand));
      } else {
        auto temp = Temp_newtemp_int_ptr(0);
        temp->varname = *s->u.varDef->u.defScalar->id;
        localVarMap.emplace(temp->varname, temp);
        auto operand = AS_Operand_Temp(temp);
        emit_irs.push_back(L_Alloca(operand));
        auto right_operand = ast2llvmRightVal(s->u.varDef->u.defScalar->val);
        emit_irs.push_back(L_Store(right_operand, operand));
      }
    } else if (s->u.varDef->kind == A_varDefType::A_varDefArrayKind) {
      if (s->u.varDef->u.defArray->type->type == A_dataType::A_structTypeKind) {
        auto temp = Temp_newtemp_struct_ptr(
            0, *s->u.varDef->u.defArray->type->u.structType);
        temp->varname = *s->u.varDef->u.defArray->id;
        localVarMap.emplace(temp->varname, temp);
        auto operand = AS_Operand_Temp(temp);
        emit_irs.push_back(L_Alloca(operand));
      } else {
        auto temp = Temp_newtemp_int_ptr(s->u.varDef->u.defArray->len);
        temp->varname = *s->u.varDef->u.defArray->id;
        localVarMap.emplace(temp->varname, temp);
        auto operand = AS_Operand_Temp(temp);
        emit_irs.push_back(L_Alloca(operand));
      }
    } else
      assert(0);
  } else {
    assert(0);
  }
}

void ast2llvmAssignStmt(aA_assignStmt s) {
  auto src = ast2llvmRightVal(s->rightVal);
  auto dst = ast2llvmLeftVal(s->leftVal);
  if (dst->kind == OperandKind::TEMP &&
      dst->u.TEMP->type == TempType::INT_TEMP) {
    assert(0);
    emit_irs.emplace_back(L_Move(src, dst));
  } else {
    emit_irs.emplace_back(L_Store(src, dst));
  }
}
void ast2llvmCallStmt(aA_callStmt s) {
  vector<AS_operand *> args;
  for (auto val : s->fnCall->vals) {
    args.push_back(ast2llvmRightVal(val));
  }
  emit_irs.push_back(L_Voidcall(*s->fnCall->fn, args));
}
void ast2llvmIfStmt(aA_ifStmt s, Temp_label *con_label, Temp_label *bre_label) {
  auto true_label = Temp_newlabel();
  Temp_label *false_label = Temp_newlabel();
  auto finish_label = Temp_newlabel();
  ast2llvmBoolExpr(s->boolExpr, true_label, false_label);
  emit_irs.emplace_back(L_Label(true_label));
  for (auto stmt : s->ifStmts) {
    ast2llvmBlock(stmt, con_label, bre_label);
  }
  emit_irs.emplace_back(L_Jump(finish_label));
  emit_irs.emplace_back(L_Label(false_label));
  for (auto stmt : s->elseStmts) ast2llvmBlock(stmt, con_label, bre_label);
  emit_irs.emplace_back(L_Jump(finish_label));

  emit_irs.emplace_back(L_Label(finish_label));
}
void ast2llvmWhileStmt(aA_whileStmt s) {
  auto con_label = Temp_newlabel();
  auto body_label = Temp_newlabel();
  auto bre_label = Temp_newlabel();

  emit_irs.emplace_back(L_Jump(con_label));
  emit_irs.emplace_back(L_Label(con_label));
  ast2llvmBoolExpr(s->boolExpr, body_label, bre_label);

  emit_irs.emplace_back(L_Label(body_label));
  for (auto stmt : s->whileStmts) ast2llvmBlock(stmt, con_label, bre_label);
  emit_irs.emplace_back(L_Jump(con_label));
  // leave
  emit_irs.emplace_back(L_Label(bre_label));
}

void ast2llvmReturnStmt(aA_returnStmt s) {
  if (s->retVal == nullptr)
    emit_irs.emplace_back(L_Ret(nullptr));
  else {
    auto operand = ast2llvmRightVal(s->retVal);
    emit_irs.emplace_back(L_Ret(operand));
  }
}

AS_operand *ast2llvmRightVal(aA_rightVal r) {
  if (r->kind == A_rightValType::A_arithExprValKind) {
    return ast2llvmArithExpr(r->u.arithExpr);
  } else if (r->kind == A_rightValType::A_boolExprValKind) {
    auto true_label = Temp_newlabel();
    auto false_label = Temp_newlabel();
    auto leave_label = Temp_newlabel();
    auto temp_ptr = AS_Operand_Temp(Temp_newtemp_int_ptr(0));
    auto temp_val = AS_Operand_Temp(Temp_newtemp_int());
    emit_irs.emplace_back(L_Alloca(temp_ptr));
    ast2llvmBoolExpr(r->u.boolExpr, true_label, false_label);
  

    emit_irs.emplace_back(L_Label(true_label));
    emit_irs.emplace_back(L_Store(AS_Operand_Const(1), temp_ptr));
    emit_irs.emplace_back(L_Jump(leave_label));

    emit_irs.emplace_back(L_Label(false_label));
    emit_irs.emplace_back(L_Store(AS_Operand_Const(0), temp_ptr));
    emit_irs.emplace_back(L_Jump(leave_label));

    emit_irs.emplace_back(L_Label(leave_label));
    
    emit_irs.emplace_back(L_Load(temp_val, temp_ptr));
    return temp_val;
  } else
    assert(0);
  return nullptr;
}

AS_operand *ast2llvmLeftVal(aA_leftVal l) {
  if (l->kind == A_leftValType::A_arrValKind) {
    return ast2llvmArrayExpr(l->u.arrExpr);
  } else if (l->kind == A_leftValType::A_memberValKind) {
    return ast2llvmMemberExpr(l->u.memberExpr);
  } else if (l->kind == A_leftValType::A_varValKind) {
    string name = *l->u.id;
    return ast2llvmIdExpr(name);
  }
  return nullptr;
}

AS_operand *ast2llvmIndexExpr(aA_indexExpr index) {
  if (index->kind == A_indexExprKind::A_numIndexKind) {
    return AS_Operand_Const(index->u.num);
  } else if (index->kind == A_indexExprKind::A_idIndexKind) {
    auto temp_ptr = ast2llvmIdExpr(*index->u.id);
    auto temp_val = AS_Operand_Temp(Temp_newtemp_int());
    emit_irs.emplace_back(L_Load(temp_val, temp_ptr));
    return temp_val;
  }
  return nullptr;
}

AS_operand *ast2llvmArrayExpr(aA_arrayExpr e) {
  AS_operand *array_operand = ast2llvmLeftVal(e->arr);
  AS_operand *index_operand = ast2llvmIndexExpr(e->idx);
  AS_operand *dst = nullptr;
  if (array_operand->kind == OperandKind::NAME) {
    if (array_operand->u.NAME->type == TempType::INT_PTR) {
      dst = AS_Operand_Temp(Temp_newtemp_int_ptr(0));
    } else if (array_operand->u.NAME->type == TempType::STRUCT_PTR) {
      dst = AS_Operand_Temp(
          Temp_newtemp_struct_ptr(0, array_operand->u.NAME->structname));
    } else if (array_operand->u.NAME->type == TempType::STRUCT_TEMP) {
      assert(0);
    } else {
      assert(0);
    }
  } else if (array_operand->kind == OperandKind::TEMP) {
    if (array_operand->u.TEMP->type == TempType::INT_PTR) {
      dst = AS_Operand_Temp(Temp_newtemp_int_ptr(0));
    } else if (array_operand->u.TEMP->type == TempType::STRUCT_PTR) {
      dst = AS_Operand_Temp(
          Temp_newtemp_struct_ptr(0, array_operand->u.TEMP->structname));
    } else {
      assert(0);
    }
  }
  emit_irs.emplace_back(L_Gep(dst, array_operand, index_operand));

  return dst;
}

AS_operand *ast2llvmMemberExpr(aA_memberExpr e) {
  AS_operand *struct_operand = ast2llvmLeftVal(e->structId);
  string member_id = *e->memberId;
  string structName;
  // 处理得到structName以及assert判断返回得到的是struct
  if (struct_operand->kind == OperandKind::NAME) {
    structName = struct_operand->u.NAME->structname;
    assert(struct_operand->u.NAME->type == TempType::STRUCT_PTR ||
           struct_operand->u.NAME->type == TempType::STRUCT_TEMP);
  } else if (struct_operand->kind == OperandKind::TEMP) {
    structName = struct_operand->u.TEMP->structname;
    assert(struct_operand->u.TEMP->type == TempType::STRUCT_PTR);
  } else
    assert(0);

  int index = structInfoMap[structName].memberinfos[member_id].offset;
  AS_operand *index_operand = AS_Operand_Const(index);
  AS_operand *dst = searchMemberInStruct(structName, member_id);
  emit_irs.emplace_back(L_Gep(dst, struct_operand, index_operand));
  return dst;
}

AS_operand *searchMemberInStruct(string structName, string member_id) {
  auto def = structInfoMap[structName].memberinfos[member_id].def;
  string child_struct_name = def.structname;
  int len = def.len;
  switch (def.kind) {
    case TempType::INT_TEMP:
      return AS_Operand_Temp(Temp_newtemp_int_ptr(0));
      break;
    case TempType::INT_PTR:
      return AS_Operand_Temp(Temp_newtemp_int_ptr(len));
      break;
    case TempType::STRUCT_TEMP:
      return AS_Operand_Temp(Temp_newtemp_struct_ptr(0, child_struct_name));
      break;
    case TempType::STRUCT_PTR:
      return AS_Operand_Temp(Temp_newtemp_struct_ptr(len, child_struct_name));
      break;

    default:
      assert(0);
      break;
  }
}

void ast2llvmBoolExpr(aA_boolExpr b, Temp_label *true_label,
                      Temp_label *false_label) {
  if (b->kind == A_boolExprType::A_boolBiOpExprKind) {
    ast2llvmBoolBiOpExpr(b->u.boolBiOpExpr, true_label, false_label);
  } else if (b->kind == A_boolExprType::A_boolUnitKind) {
    ast2llvmBoolUnit(b->u.boolUnit, true_label, false_label);
  } else {
    assert(0);
  }
}

void ast2llvmBoolBiOpExpr(aA_boolBiOpExpr b, Temp_label *true_label,
                          Temp_label *false_label) {
  Temp_label *middle_label = Temp_newlabel();

  switch (b->op) {
    case A_boolBiOp::A_and:
      ast2llvmBoolExpr(b->left, middle_label, false_label);
      break;
    case A_boolBiOp::A_or:
      ast2llvmBoolExpr(b->left, true_label, middle_label);
      break;
    default:
      assert(0);
  }

  emit_irs.emplace_back(L_Label(middle_label));
  ast2llvmBoolExpr(b->right, true_label, false_label);
}

void ast2llvmBoolUnit(aA_boolUnit b, Temp_label *true_label,
                      Temp_label *false_label) {
  if (b->kind == A_boolUnitType::A_boolExprKind) {
    ast2llvmBoolExpr(b->u.boolExpr, true_label, false_label);
  } else if (b->kind == A_boolUnitType::A_boolUOpExprKind) {
    ast2llvmBoolUOpExpr(b->u.boolUOpExpr, true_label, false_label);
  } else if (b->kind == A_boolUnitType::A_comOpExprKind) {
    ast2llvmComOpExpr(b->u.comExpr, true_label, false_label);
  } else {
    assert(0);
  }
}

void ast2llvmBoolUOpExpr(aA_boolUOpExpr b, Temp_label *true_label,
                         Temp_label *false_label) {
  if (b->op == A_boolUOp::A_not) {
    ast2llvmBoolUnit(b->cond, false_label, true_label);
  } else {
    assert(0);
  }
}

void ast2llvmComOpExpr(aA_comExpr c, Temp_label *true_label,
                       Temp_label *false_label) {
  auto left = ast2llvmExprUnit(c->left);
  auto right = ast2llvmExprUnit(c->right);
  auto dst = AS_Operand_Temp(Temp_newtemp_int());
  switch (c->op) {
    case A_comOp::A_eq:
      emit_irs.emplace_back(L_Cmp(L_relopKind::T_eq, left, right, dst));
      break;
    case A_comOp::A_ge:
      emit_irs.emplace_back(L_Cmp(L_relopKind::T_ge, left, right, dst));
      break;
    case A_comOp::A_gt:
      emit_irs.emplace_back(L_Cmp(L_relopKind::T_gt, left, right, dst));
      break;
    case A_comOp::A_le:
      emit_irs.emplace_back(L_Cmp(L_relopKind::T_le, left, right, dst));
      break;
    case A_comOp::A_lt:
      emit_irs.emplace_back(L_Cmp(L_relopKind::T_lt, left, right, dst));
      break;
    case A_comOp::A_ne:
      emit_irs.emplace_back(L_Cmp(L_relopKind::T_ne, left, right, dst));
      break;

    default:
      assert(0);
      break;
  }
  emit_irs.emplace_back(L_Cjump(dst, true_label, false_label));
}
