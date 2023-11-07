#include "TypeCheck.h"

#include <string>

#include "TeaplAst.h"
#include "TeaplaAst.h"
#include "TypeCheckClass.h"

// maps to store the type information. Feel free to design new data structures
// if you need.
typeMap g_token2Type;  // global token ids to type
typeMap l_token2Type;  // local token ids to type

typeMap funcparam_token2Type;  // func params token ids to type

paramMemberMap func2Param;
paramMemberMap struct2Members;

// 函数map
funcSet funcDefs;
funcSet funcDelcs;

// 位置map
posMap func2Pos;
posMap g_token2Pos;
posMap l_token2Pos;

arraySizeMap g_token2Size;
arraySizeMap l_token2Size;

// private util functions. You can use these functions to help you debug.
void error_print(std::ostream* out, A_pos p, string info) {
  *out << "Typecheck error in line " << p->line << ", col " << p->col << ": "
       << info << std::endl;
  exit(0);
}

void print_token_map(typeMap* map) {
  for (auto it = map->begin(); it != map->end(); it++) {
    std::cout << it->first << " : ";
    switch (it->second->type) {
      case A_dataType::A_nativeTypeKind:
        switch (it->second->u.nativeType) {
          case A_nativeType::A_intTypeKind:
            std::cout << "int";
            break;
          default:
            break;
        }
        break;
      case A_dataType::A_structTypeKind:
        std::cout << *(it->second->u.structType);
        break;
      default:
        break;
    }
    std::cout << std::endl;
  }
}

// public functions
// This is the entrace of this file.
void check_Prog(std::ostream* out, aA_program p) {
  // p is the root of AST tree.

  // 1.注册结构体 和 全局变量，有顺序要求
  for (auto ele : p->programElements) {
    /*
        Write your code here.

        Hint:
        1. Design the order of checking the program elements to meet the
       requirements that funtion declaration and global variable declaration can
       be used anywhere in the program.

        2. Many types of statements indeed collapse to some same units, so a
       good abstract design will help you reduce the amount of your code.
    */
    if (ele->kind == A_programStructDefKind)
      check_StructDef(out, ele->u.structDef);
    if (ele->kind == A_programVarDeclStmtKind) {
      check_GlobalVarDecl(out, ele->u.varDeclStmt);
    }
  }
  // 2.把函数注册进全局表，检查函数声明和定义的顺序，但不检查函数体内部
  for (auto ele : p->programElements) {
    if (ele->kind == A_programFnDeclStmtKind) {
      check_FnDeclStmt(out, ele->u.fnDeclStmt);
    }
    if (ele->kind == A_programFnDefKind) {
      check_FnPreDef(out, ele->u.fnDef);
    }
  }

  for (auto ele : p->programElements) {
    if (ele->kind == A_programFnDefKind) {
      check_FnDef(out, ele->u.fnDef);
    }
  }

  (*out) << "Typecheck passed!" << std::endl;
  return;
}

void check_GlobalVarDecl(std::ostream* out, aA_varDeclStmt vd) {
  // TODO：不允许调用函数对全局变量进行初始化
  if (!vd) return;
  auto decl = VarDeclCheckProxyFactory::CreateVarDeclProxy(out, vd);
  decl->CheckStmt();
  g_token2Var.emplace(decl->getName(), decl);
}

void check_LocalVarDecl(std::ostream* out, aA_varDeclStmt vd,
                        bool isParam = false) {
  // TODO：不允许调用函数对全局变量进行初始化
  if (!vd) return;
  auto decl =
      VarDeclCheckProxyFactory::CreateVarDeclProxy(out, vd, false, isParam);
  decl->CheckStmt();
  l_token2Var.emplace(decl->getName(), decl);
}

void check_VarDecl(std::ostream* out, aA_varDeclStmt vd) {
  // variable declaration statement
  if (!vd) return;
  string name;
  if (vd->kind == A_varDeclStmtType::A_varDeclKind) {
    // if declaration only
    // Example:
    //   let a:int;
    //   let a[5]:int;

    /* write your code here*/
  } else if (vd->kind == A_varDeclStmtType::A_varDefKind) {
    // if both declaration and initialization
    // Example:
    //   let a:int = 5;

    /* write your code here */
  }
  return;
}

void check_StructDef(std::ostream* out, aA_structDef sd) {
  if (!sd) return;
  // structure definition
  // Example:
  //      struct A{
  //          a:int;
  //          b:int;
  //      }

  /* write your code here */
  // 目前没有检查结构名不与关键字冲突
  if (struct2Members.find(*(sd->id)) == struct2Members.end()) {
    error_print(out, sd->pos, " struct redefine: " + *sd->id);
    return;
  }
  vector<aA_varDecl>* paramMap = new vector<aA_varDecl>(sd->varDecls);
  struct2Members.emplace(*(sd->id), paramMap);
  return;
}

void check_FnDecl(std::ostream* out, aA_fnDecl fd) {
  // Example:
  //      fn main(a:int, b:int)->int
  if (!fd) return;
  /*
      write your code here
      Hint: you may need to check if the function is already declared
  */
  auto it = token2Func.find(*fd->id);
  if (it != token2Func.end()) {
    my_Func func = it->second;
    func->CheckDecl(out, fd);
  } else {
    my_Func func = std::make_shared<FnProxy>(out, fd);
    token2Func.emplace(func->getName(), func);
  }
}

void check_FnDeclStmt(std::ostream* out, aA_fnDeclStmt fd) {
  // Example:
  //      fn main(a:int, b:int)->int;
  if (!fd) return;
  check_FnDecl(out, fd->fnDecl);
  return;
}

void check_FnPreDef(std::ostream* out, aA_fnDef fd) {
  auto it = token2Func.find(*fd->fnDecl->id);
  if (it != token2Func.end()) {
    error_print(out, fd->pos,
                string("function has defined on position: ") +
                    std::to_string(fd->pos->line));
  }
  if (!it->second->isDefined()) {
    my_Func func = it->second;
    func->CheckDecl(out, fd->fnDecl);
  } else {
    my_Func func = std::make_shared<FnProxy>(out, fd);
    token2Func.emplace(func->getName(), func);
  }
}

void check_FnDef(std::ostream* out, aA_fnDef fd) {
  // Example:
  //      fn main(a:int, b:int)->int{
  //          let c:int;
  //          c = a + b;
  //          return c;
  //      }
  if (!fd) return;
  // check_FnDecl(out, fd->fnDecl);
  // /*
  //     write your code here
  //     Hint: you may pay attention to the function parameters, local variables
  //    and global variables.
  // */

  my_Func func;
  auto it = token2Func.find(*fd->fnDecl->id);
  if (it != token2Func.end()) {
    func = it->second;
    func->Define(out, fd);
  } else {
    error_print(out, fd->pos, "Function not exists.");
  }
}

void check_CodeblockStmt(std::ostream* out, aA_codeBlockStmt cs) {
  if (!cs) return;
  switch (cs->kind) {
    case A_codeBlockStmtType::A_varDeclStmtKind:
      check_VarDecl(out, cs->u.varDeclStmt);
      break;
    case A_codeBlockStmtType::A_assignStmtKind:
      check_AssignStmt(out, cs->u.assignStmt);
      break;
    case A_codeBlockStmtType::A_ifStmtKind:
      check_IfStmt(out, cs->u.ifStmt);
      break;
    case A_codeBlockStmtType::A_whileStmtKind:
      check_WhileStmt(out, cs->u.whileStmt);
      break;
    case A_codeBlockStmtType::A_callStmtKind:
      check_CallStmt(out, cs->u.callStmt);
      break;
    case A_codeBlockStmtType::A_returnStmtKind:
      check_ReturnStmt(out, cs->u.returnStmt);
      break;
    default:
      break;
  }
  return;
}

void check_AssignStmt(std::ostream* out, aA_assignStmt as) {
  if (!as) return;
  string name;
  switch (as->leftVal->kind) {
    case A_leftValType::A_varValKind: {
      /* write your code here */
    } break;
    case A_leftValType::A_arrValKind: {
      /* write your code here */
    } break;
    case A_leftValType::A_memberValKind: {
      /* write your code here */
    } break;
  }
  return;
}

void check_ArrayExpr(std::ostream* out, aA_arrayExpr ae) {
  if (!ae) return;
  /*
      Example:
          a[1] = 0;
      Hint:
          check the validity of the array index
  */
}

aA_type check_MemberExpr(std::ostream* out, aA_memberExpr me) {
  // check if the member exists and return the tyep of the member
  // you may need to check if the type of this expression matches with its
  // leftvalue or rightvalue, so return its aA_type would be a good way. Feel
  // free to change the design pattern if you need.
  if (!me) return nullptr;
  /*
      Example:
          a.b
  */
  return nullptr;
}

// 检查if语句
void check_IfStmt(std::ostream* out, aA_ifStmt is) {
  if (!is) return;
  check_BoolExpr(out, is->boolExpr);
  // 对每个if语句进行判断
  for (aA_codeBlockStmt s : is->ifStmts) {
    check_CodeblockStmt(out, s);
  }
  // TODO：对于局部变量的注册取消掉
  // 只有对于变量声明的语句要取消掉
  for (aA_codeBlockStmt s : is->ifStmts) {
    if (s->kind == A_codeBlockStmtType::A_varDeclStmtKind) {
      cancelStmtRegis(out, s->u.varDeclStmt);
    }
  }
  for (aA_codeBlockStmt s : is->elseStmts) {
    check_CodeblockStmt(out, s);
  }
  for (aA_codeBlockStmt s : is->elseStmts) {
    if (s->kind == A_codeBlockStmtType::A_varDeclStmtKind) {
      cancelStmtRegis(out, s->u.varDeclStmt);
    }
  }
  return;
}

void cancelStmtRegis(std::ostream* out, aA_varDeclStmt);

void check_BoolExpr(std::ostream* out, aA_boolExpr be) {
  if (!be) return;
  switch (be->kind) {
    case A_boolExprType::A_boolBiOpExprKind:
      /* write your code here */
      check_BoolExpr(out, be->u.boolBiOpExpr->left);
      check_BoolExpr(out, be->u.boolBiOpExpr->right);
      break;
    case A_boolExprType::A_boolUnitKind:
      check_BoolUnit(out, be->u.boolUnit);
      break;
    default:
      break;
  }
  return;
}

void check_BoolUnit(std::ostream* out, aA_boolUnit bu) {
  if (!bu) return;
  switch (bu->kind) {
    case A_boolUnitType::A_comOpExprKind: {
      /* write your code here */
      check_Compare(out, bu->u.comExpr->pos,
                    check_ExprUnit(out, bu->u.comExpr->left),
                    check_ExprUnit(out, bu->u.comExpr->right));
    } break;
    case A_boolUnitType::A_boolExprKind:
      /* write your code here */
      check_BoolExpr(out, bu->u.boolExpr);
      break;
    case A_boolUnitType::A_boolUOpExprKind:
      /* write your code here */
      check_BoolUnit(out, bu->u.boolUOpExpr->cond);
      break;
    default:
      break;
  }
  return;
}

aA_type check_ExprUnit(std::ostream* out, aA_exprUnit eu) {
  // validate the expression unit and return the aA_type of it
  // you may need to check if the type of this expression matches with its
  // leftvalue or rightvalue, so return its aA_type would be a good way.
  // Feel free to change the design pattern if you need.
  if (!eu) return nullptr;
  aA_type ret;
  switch (eu->kind) {
    case A_exprUnitType::A_idExprKind: {
      /* write your code here */
      check_scalarExists(out, eu->pos, *eu->u.id);

    } break;
    case A_exprUnitType::A_numExprKind: {
      /* write your code here */
    } break;
    case A_exprUnitType::A_fnCallKind: {
      /* write your code here */
    } break;
    case A_exprUnitType::A_arrayExprKind: {
      /* write your code here */
    } break;
    case A_exprUnitType::A_memberExprKind: {
      /* write your code here */
    } break;
    case A_exprUnitType::A_arithExprKind: {
      /* write your code here */
    } break;
    case A_exprUnitType::A_arithUExprKind: {
      /* write your code here */
    } break;
  }
  return ret;
}

void check_FuncCall(std::ostream* out, aA_fnCall fc) {
  if (!fc) return;
  // Example:
  //      foo(1, 2);

  /* write your code here */
  return;
}

void check_WhileStmt(std::ostream* out, aA_whileStmt ws) {
  if (!ws) return;
  check_BoolExpr(out, ws->boolExpr);
  for (aA_codeBlockStmt s : ws->whileStmts) {
    check_CodeblockStmt(out, s);
  }
  return;
}

void check_CallStmt(std::ostream* out, aA_callStmt cs) {
  if (!cs) return;
  check_FuncCall(out, cs->fnCall);
  return;
}

void check_ReturnStmt(std::ostream* out, aA_returnStmt rs) {
  if (!rs) return;
  return;
}

void check_g_varName(std::ostream* out, A_pos pos, string name) {
  if (token2Func.find(name) != token2Func.end()) {
    error_print(out, pos,
                string("function: ") + (name) + string(" have existed."));
  }
  if (g_token2Var.find(name) != g_token2Var.end()) {
    error_print(out, pos,
                string("global var: ") + (name) + string(" have existed."));
  }
}

void check_l_varName(std::ostream* out, A_pos pos, string name) {
  check_g_varName(out, pos, name);
  if (l_token2Var.find(name) != l_token2Var.end()) {
    error_print(out, pos,
                string("local var: ") + (name) + string(" have existed."));
  }
}

void check_fnDecled() {}

void check_fnDefed() {}

aA_type get_RightValType(std::ostream* out, aA_rightVal rl) {
  if (rl->kind == A_rightValType::A_arithExprValKind) {
  }
  if (rl->kind == A_rightValType::A_boolExprValKind) {
  }
  error_print(out, rl->pos, "some thing wrong.");
  return nullptr;
}

bool Equal(aA_type type1, aA_type type2) {
  if (type1 == nullptr && type2 == nullptr) return true;

  if (type1 == nullptr || type2 == nullptr) return false;
  if (type1->type != type2->type) return false;

  if (type1->type == A_nativeTypeKind) {
    if (type1->u.nativeType != type2->u.nativeType) return false;
  }
  if (type1->type == A_structTypeKind) {
    if (type1->u.structType->compare(*(type2->u.structType)) != 0) return false;
  }
  return true;
}

string get_TypeName(aA_type type) {
  if (type == nullptr) return "nullptr";
  switch (type->type) {
    case A_nativeTypeKind: {
      switch (type->u.nativeType) {
        case A_intTypeKind: {
          return "int";
          break;
        }
        default:
          break;
      }
      break;
    }
    case A_structTypeKind: {
      return *type->u.structType;
      break;
    }
    default:
      break;
  }
}

void check_Convert(std::ostream* out, A_pos pos, aA_type left, aA_type right) {
  if (!Equal(left, right)) {
    error_print(out, pos,
                string("cannot convert ") + get_TypeName(left) +
                    string(" to ") + get_TypeName(right) + string(" ."));
  }
}

void check_scalarExists(std::ostream* out, A_pos pos, string name) {
  if (l_token2Type.find(name) == l_token2Type.end() &&
      g_token2Type.find(name) == g_token2Type.end()) {
    error_print(out, pos, name + string(" is not defined."));
  }

  if (l_token2Size.find(name) == l_token2Size.end() ||
      g_token2Size.find(name) == g_token2Size.end()) {
    error_print(out, pos, name + string(" is array."));
  }
}

void check_Compare(std::ostream* out, A_pos pos, aA_type left, aA_type right) {
  if (left == nullptr || right == nullptr) goto error;
  if (left->type == A_dataType::A_structTypeKind ||
      right->type == A_dataType::A_structTypeKind)
    goto error;
  if (left->u.nativeType != A_nativeType::A_intTypeKind ||
      right->u.nativeType != A_nativeType::A_intTypeKind)
    goto error;

error:
  error_print(out, pos,
              get_TypeName(left) + " can't compare to " + get_TypeName(right));
}

bool check_NativeType(aA_type target, A_nativeType type) {
  if (target == nullptr) return false;
  if (target->type == A_dataType::A_structTypeKind) return false;
  return target->u.nativeType == type;
}

bool check_StructType(aA_type target, string type) {
  if (target == nullptr) return false;
  if (target->type == A_dataType::A_nativeTypeKind) return false;
  return target->u.structType->compare(type) == 0;
}