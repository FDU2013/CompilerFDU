#include "TypeCheck.h"

#include <iostream>
#include <memory>
#include <string>

#include "TeaplAst.h"
#include "TeaplaAst.h"

using std::cout;
using std::endl;

// maps to store the type information. Feel free to design new data
// structures if you need.
// typeMap g_token2Type;  // global token ids to type
// typeMap l_token2Type;  // local token ids to type

// typeMap funcparam_token2Type;  // func params token ids to type

// paramMemberMap func2Param;
// paramMemberMap struct2Members;

varMap g_token2Var;
varMap l_token2Var;

structMap token2Struct;

funcMap token2Func;

static auto boolup = std::make_unique<aA_type_>();
static auto intup = std::make_unique<aA_type_>();

static aA_type Bool_aAType = []() {
  aA_type boolType = boolup.get();
  boolType->type = A_dataType::A_structTypeKind;
  boolType->u.structType = new string("bool");
  return boolType;
}();

static aA_type Int_aAType = []() {
  aA_type intType = intup.get();
  intType->type = A_dataType::A_nativeTypeKind;
  intType->u.nativeType = A_nativeType::A_intTypeKind;
  return intType;
}();

static aA_type BoolTypeTmp(A_pos pos) {
  aA_type type = new aA_type_;
  type->pos = pos;
  type->type = A_dataType::A_structTypeKind;
  type->u.structType = new string("bool");
  return type;
}

static aA_type IntTypeTmp(A_pos pos) {
  aA_type type = new aA_type_;
  type->pos = pos;
  type->type = A_dataType::A_nativeTypeKind;
  type->u.nativeType = A_nativeType::A_intTypeKind;
  return type;
}

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

  for (auto ele : p->programElements) {
    if (ele->kind == A_programFnDeclStmtKind) {
      // cout << "func decl" << endl;
      check_FnDeclStmt(out, ele->u.fnDeclStmt);
    }
    if (ele->kind == A_programFnDefKind) {
      // cout << "func def" << endl;
      check_FnPreDef(out, ele->u.fnDef);
    }
  }

  for (auto ele : p->programElements) {
    if (ele->kind == A_programFnDefKind) {
      // cout << "check func def" << endl;
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
  string name = *sd->id;
  auto it = token2Struct.find(name);
  if (it != token2Struct.end()) {
    error_print(out, sd->pos, string("struct \"") + name + "\"  has defined.");
  } else {
    my_Struct myStruct = std::make_shared<StructProxy>(out, sd);
    token2Struct.emplace(name, myStruct);
  }

  // if (struct2Members.find(*(sd->id)) != struct2Members.end()) {
  //   error_print(out, sd->pos, " struct redefine: " + *sd->id);
  //   return;
  // }
  // vector<aA_varDecl>* paramMap = new vector<aA_varDecl>(sd->varDecls);
  // struct2Members.emplace(*(sd->id), paramMap);
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
    if (it->second->isDefined()) {
      error_print(out, fd->pos,
                  string("function has defined on line: ") +
                      std::to_string(it->second->getDefPos()->line));
      return;
    }
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
    func->CheckDefine(out, fd);
  } else {
    error_print(out, fd->pos, "Function not exists.");
  }
}

void check_CodeblockStmt(std::ostream* out, aA_codeBlockStmt cs, my_Func func) {
  if (!cs) return;
  switch (cs->kind) {
    case A_codeBlockStmtType::A_varDeclStmtKind:
      check_LocalVarDecl(out, cs->u.varDeclStmt);
      break;
    case A_codeBlockStmtType::A_assignStmtKind:
      check_AssignStmt(out, cs->u.assignStmt);
      break;
    case A_codeBlockStmtType::A_ifStmtKind:
      check_IfStmt(out, cs->u.ifStmt, func);
      break;
    case A_codeBlockStmtType::A_whileStmtKind:
      check_WhileStmt(out, cs->u.whileStmt, func);
      break;
    case A_codeBlockStmtType::A_callStmtKind:
      check_CallStmt(out, cs->u.callStmt);
      break;
    case A_codeBlockStmtType::A_returnStmtKind:
      check_ReturnStmt(out, cs->u.returnStmt, func->getRetType());
      break;
    default:
      break;
  }
  return;
}

void check_AssignStmt(std::ostream* out, aA_assignStmt as) {
  if (!as) return;
  // string name;

  aA_type leftType, rightType;
  // bool same = true;
  switch (as->leftVal->kind) {
    case A_leftValType::A_varValKind: {
      /* write your code here */
      check_scalarExists(out, as->leftVal->pos, *as->leftVal->u.id);
      leftType = get_varType(*as->leftVal->u.id);
    } break;
    case A_leftValType::A_arrValKind: {
      /* write your code here */
      leftType = check_ArrayExpr(out, as->leftVal->u.arrExpr);
    } break;
    case A_leftValType::A_memberValKind: {
      /* write your code here */
      leftType = check_MemberExpr(out, as->leftVal->u.memberExpr);
    } break;
  }
  rightType = get_RightValType(out, as->rightVal);
  check_Convert(out, as->rightVal->pos, leftType, rightType);
  return;
}

aA_type check_ArrayExpr(std::ostream* out, aA_arrayExpr ae) {
  if (!ae) return nullptr;
  /*
      Example:
          a[1] = 0;
      Hint:
          check the validity of the array index
  */
  string name = *ae->arr;
  auto arrayVar = check_arrayExists(out, ae->pos, name);
  auto array = static_cast<ArrayDeclProxy*>(arrayVar.get());
  if (ae->idx->kind == A_indexExprKind::A_idIndexKind) {
    check_scalarExists(out, ae->idx->pos, *ae->idx->u.id);
  } else {
    int size = array->getSize();
    if (size <= ae->idx->u.num)
      error_print(out, ae->idx->pos,
                  string("Array index: ") + std::to_string(ae->idx->u.num) +
                      string(" is out of range. "));
  }
  return array->getType();
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
  string name = *me->structId;
  A_pos pos = me->pos;
  check_scalarExists(out, pos, name);
  auto type = get_varType(name);
  if (type->type == A_dataType::A_nativeTypeKind) {
    error_print(out, pos, name + string(" is not a struct."));
    return nullptr;
  }
  auto it = token2Struct.find(*type->u.structType);
  if (it == token2Struct.end()) {
    error_print(out, pos,
                *type->u.structType + string(" have not been defined."));
    return nullptr;
  }
  return it->second->CheckMember(out, pos, *me->memberId);
}

// 检查if语句
void check_IfStmt(std::ostream* out, aA_ifStmt is, my_Func func) {
  if (!is) return;
  check_BoolExpr(out, is->boolExpr);
  // 对每个if语句进行判断
  for (aA_codeBlockStmt s : is->ifStmts) {
    check_CodeblockStmt(out, s, func);
  }
  // 于局部变量的注册取消掉
  for (aA_codeBlockStmt s : is->ifStmts) {
    if (s->kind == A_codeBlockStmtType::A_varDeclStmtKind) {
      erase_localVar(s);
    }
  }
  for (aA_codeBlockStmt s : is->elseStmts) {
    check_CodeblockStmt(out, s, func);
  }
  for (aA_codeBlockStmt s : is->elseStmts) {
    erase_localVar(s);
  }
  return;
}

void erase_localVar(aA_codeBlockStmt cb) {
  if (cb->kind == A_codeBlockStmtType::A_varDeclStmtKind) {
    switch (cb->kind) {
      case A_varDeclStmtKind:
        erase_localVar(cb->u.varDeclStmt);
        break;
      default:
        break;
    }
  }
}

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
      return get_varType(*eu->u.id);
    } break;
    case A_exprUnitType::A_numExprKind: {
      /* write your code here */
      return IntTypeTmp(eu->pos);
    } break;
    case A_exprUnitType::A_fnCallKind: {
      /* write your code here */
      return check_FuncCall(out, eu->u.callExpr);
    } break;
    case A_exprUnitType::A_arrayExprKind: {
      /* write your code here */
      return check_ArrayExpr(out, eu->u.arrayExpr);
    } break;
    case A_exprUnitType::A_memberExprKind: {
      /* write your code here */
      return check_MemberExpr(out, eu->u.memberExpr);
    } break;
    case A_exprUnitType::A_arithExprKind: {
      /* write your code here */
      return check_ArithExpr(out, eu->u.arithExpr);
    } break;
    case A_exprUnitType::A_arithUExprKind: {
      /* write your code here */
      return check_ArithUExpr(out, eu->u.arithUExpr);
    } break;
  }
  return ret;
}

aA_type check_ArithExpr(std::ostream* out, aA_arithExpr ae) {
  if (ae->kind == A_arithExprType::A_exprUnitKind) {
    return check_ExprUnit(out, ae->u.exprUnit);
  }
  if (ae->kind == A_arithExprType::A_arithBiOpExprKind) {
    return check_ArithBiOpExpr(out, ae->u.arithBiOpExpr);
  }
  cout << "null in check_ArithExpr" << endl;
  return nullptr;
}

aA_type check_ArithUExpr(std::ostream* out, aA_arithUExpr aue) {
  aA_type ret = check_ExprUnit(out, aue->expr);
  if (!Equal(ret, Int_aAType)) {
    error_print(out, aue->pos,
                string("Type ") + get_TypeName(ret) +
                    string(" doesn's support operator: '-'."));
  }
  return ret;
}

aA_type check_ArithBiOpExpr(std::ostream* out, aA_arithBiOpExpr aboe) {
  aA_type left_type = check_ArithExpr(out, aboe->left);
  if (!Equal(left_type, Int_aAType)) {
    error_print(out, aboe->pos,
                string("Type ") + get_TypeName(left_type) +
                    string(" doesn's support operators: '+-*/'."));
  }
  aA_type right_type = check_ArithExpr(out, aboe->right);
  if (!Equal(right_type, Int_aAType)) {
    error_print(out, aboe->pos,
                string("Type ") + get_TypeName(right_type) +
                    string(" doesn's support operator: '-'."));
  }
  return left_type;
}

aA_type check_FuncCall(std::ostream* out, aA_fnCall fc) {
  if (!fc) return nullptr;
  // Example:
  //      foo(1, 2);

  /* write your code here */
  auto it = token2Func.find(*fc->fn);
  if (it == token2Func.end() || !it->second->isDefined()) {
    error_print(
        out, fc->pos,
        string("Function \"") + *(fc->fn) + string("\" is not defined"));
    return nullptr;
  }
  it->second->CheckCall(out, fc);
  return it->second->getRetType();
}

void check_WhileStmt(std::ostream* out, aA_whileStmt ws, my_Func func) {
  if (!ws) return;
  check_BoolExpr(out, ws->boolExpr);
  for (aA_codeBlockStmt s : ws->whileStmts) {
    check_CodeblockStmt(out, s, func);
  }
  for (auto s : ws->whileStmts) {
    if (s->kind == A_codeBlockStmtType::A_varDeclStmtKind) {
      erase_localVar(s);
    }
  }
  return;
}

void check_CallStmt(std::ostream* out, aA_callStmt cs) {
  if (!cs) return;
  check_FuncCall(out, cs->fnCall);
  return;
}

void check_ReturnStmt(std::ostream* out, aA_returnStmt rs, aA_type expected) {
  if (!rs) return;

  aA_type retType = get_RightValType(out, rs->retVal);
  if (!Equal(retType, expected)) {
    error_print(out, retType->pos,
                string("Your return type: ") + get_TypeName(retType) +
                    string(" not match function return type: ") +
                    get_TypeName(expected) + string(" ."));
  }
  return;
}

void check_g_varName(std::ostream* out, A_pos pos, string name) {
  if (token2Struct.find(name) != token2Struct.end()) {
    error_print(out, pos, name + string(" has been a struct's name."));
  }
  if (token2Func.find(name) != token2Func.end()) {
    error_print(out, pos,
                string("function: ") + name + string(" have existed."));
  }
  if (g_token2Var.find(name) != g_token2Var.end()) {
    error_print(out, pos,
                string("global var: ") + name + string(" have existed."));
  }
}

void check_l_varName(std::ostream* out, A_pos pos, string name) {
  check_g_varName(out, pos, name);
  if (l_token2Var.find(name) != l_token2Var.end()) {
    error_print(out, pos,
                string("local var: ") + (name) + string(" have existed."));
  }
}

aA_type get_RightValType(std::ostream* out, aA_rightVal rl) {
  if (rl->kind == A_rightValType::A_arithExprValKind) {
    return check_ArithExpr(out, rl->u.arithExpr);
  }
  if (rl->kind == A_rightValType::A_boolExprValKind) {
    return Bool_aAType;
  }
  cout << "null in get_RightValType" << endl;
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
                string("cannot convert ") + get_TypeName(right) +
                    string(" to ") + get_TypeName(left) + string(" ."));
  }
}

my_Var get_myVar(std::ostream* out, A_pos pos, string name) {
  auto l_it = l_token2Var.find(name);
  auto g_it = g_token2Var.find(name);
  my_Var scalar = nullptr;
  if (l_it != l_token2Var.end()) {
    scalar = l_it->second;
  } else if (g_it != g_token2Var.end()) {
    scalar = g_it->second;
  } else {
    error_print(out, pos, name + string(" is not defined."));
  }
  return scalar;
}

void check_scalarExists(std::ostream* out, A_pos pos, string name) {
  auto scalar = get_myVar(out, pos, name);
  if (scalar != nullptr && !scalar->isScalar()) {
    error_print(out, pos, name + string(" is array."));
  }
}

my_Var check_arrayExists(std::ostream* out, A_pos pos, string name) {
  auto array = get_myVar(out, pos, name);
  if (array != nullptr && array->isScalar()) {
    error_print(out, pos, name + string(" is scalar."));
  }
  return array;
}

void check_Compare(std::ostream* out, A_pos pos, aA_type left, aA_type right) {
  if (left == nullptr || right == nullptr) goto error;
  if (left->type == A_dataType::A_structTypeKind ||
      right->type == A_dataType::A_structTypeKind)
    goto error;
  if (left->u.nativeType != A_nativeType::A_intTypeKind ||
      right->u.nativeType != A_nativeType::A_intTypeKind)
    goto error;

  return;
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

aA_type get_varType(string name) {
  auto l_it = l_token2Var.find(name);
  if (l_it != l_token2Var.end()) {
    return l_it->second->getType();
  }
  auto g_it = g_token2Var.find(name);
  if (g_token2Var.count(name) > 0) {
    return g_it->second->getType();
  }

  cout << "null in get_varType" << endl;
  return nullptr;
}

aA_type get_scalarType(string name) {
  auto l_it = l_token2Var.find(name);
  if (l_it != l_token2Var.end()) {
    return l_it->second->isScalar() ? l_it->second->getType() : nullptr;
  }
  auto g_it = g_token2Var.find(name);
  if (g_token2Var.count(name) > 0) {
    return l_it->second->isScalar() ? g_it->second->getType() : nullptr;
  }

  cout << "null in get_scalarType" << endl;
  return nullptr;
}

aA_type get_arrayType(string name) {
  auto l_it = l_token2Var.find(name);
  if (l_it != l_token2Var.end()) {
    return l_it->second->isScalar() ? nullptr : l_it->second->getType();
  }
  auto g_it = g_token2Var.find(name);
  if (g_token2Var.count(name) > 0) {
    return l_it->second->isScalar() ? nullptr : g_it->second->getType();
  }

  cout << "null in get_arrayType" << endl;
  return nullptr;
}

void erase_localVar(aA_varDeclStmt vd) {
  if (!vd) return;

  string name;
  if (vd->kind == A_varDeclStmtType::A_varDeclKind) {
    if (vd->u.varDecl->kind == A_varDeclType::A_varDeclScalarKind) {
      name = *vd->u.varDecl->u.declScalar->id;
    } else {
      name = *vd->u.varDecl->u.declArray->id;
    }
  } else if (vd->kind == A_varDeclStmtType::A_varDefKind) {
    if (vd->u.varDef->kind == A_varDefType::A_varDefScalarKind) {
      name = *vd->u.varDef->u.defScalar->id;
    } else {
      name = *vd->u.varDef->u.defArray->id;
    }
  }
  l_token2Var.erase(name);
}

int get_arraySize(string name) {
  auto l_it = l_token2Var.find(name);
  if (l_it != l_token2Var.end()) {
    return static_cast<ArrayDeclProxy*>(l_it->second.get())->getSize();
  }
  auto g_it = g_token2Var.find(name);
  if (g_token2Var.count(name) > 0) {
    return static_cast<ArrayDeclProxy*>(l_it->second.get())->getSize();
  }

  return -1;
}

my_Var VarDeclCheckProxyFactory::CreateVarDeclProxy(std::ostream* out,
                                                    aA_varDeclStmt vd,
                                                    bool isGlobal,
                                                    bool isParam) {
  if (vd->kind == A_varDeclStmtType::A_varDeclKind) {
    if (vd->u.varDecl->kind == A_varDeclType::A_varDeclScalarKind) {
      return std::make_shared<ScalarDeclProxy>(out, vd, isGlobal, isParam);
    } else {
      return std::make_shared<ArrayDeclProxy>(out, vd, isGlobal, isParam);
    }
  } else if (vd->kind == A_varDeclStmtType::A_varDefKind) {
    if (vd->u.varDef->kind == A_varDefType::A_varDefScalarKind) {
      return std::make_shared<ScalarDefProxy>(out, vd, isGlobal, isParam);
    } else {
      return std::make_shared<ArrayDefProxy>(out, vd, isGlobal, isParam);
    }
  }
  cout << "null in CreateVarDeclProxy" << endl;
  return nullptr;
}

VarDeclCheckProxy::VarDeclCheckProxy(std::ostream* out, aA_varDeclStmt vd,
                                     bool isGlobal, bool isParam) {
  name_ = *vd->u.varDecl->u.declScalar->id;
  pos_ = vd->u.varDecl->u.declScalar->pos;
  type_ = vd->u.varDecl->u.declScalar->type;
  global_ = isGlobal;
  param_ = isParam;
  out_ = out;
}
void VarDeclCheckProxy::CheckStmt() { CheckLegality(); }

string VarDeclCheckProxy::getName() { return name_; }
aA_type VarDeclCheckProxy::getType() { return type_; }

bool VarDeclCheckProxy::isScalar() { return true; }

void VarDeclCheckProxy::CheckLegality() {
  if (global_) {
    check_g_varName(out_, pos_, name_);
  } else if (!param_) {
    check_l_varName(out_, pos_, name_);
  }
}

ScalarDeclProxy::ScalarDeclProxy(std::ostream* out, aA_varDeclStmt vd,
                                 bool isGlobal, bool isParam)
    : VarDeclCheckProxy(out, vd, isGlobal, isParam) {}

ScalarDefProxy::ScalarDefProxy(std::ostream* out, aA_varDeclStmt vd,
                               bool isGlobal, bool isParam)
    : ScalarDeclProxy(out, vd, isGlobal, isParam) {
  val_ = vd->u.varDef->u.defScalar->val;
}
void ScalarDefProxy::CheckLegality() {
  VarDeclCheckProxy::CheckLegality();
  aA_type assign_type = get_RightValType(out_, val_);
  check_Convert(out_, pos_, type_, assign_type);
}

ArrayDeclProxy::ArrayDeclProxy(std::ostream* out, aA_varDeclStmt vd,
                               bool isGlobal, bool isParam)
    : VarDeclCheckProxy(out, vd, isGlobal, isParam) {
  size_ = vd->u.varDef->u.defArray->len;
}
int ArrayDeclProxy::getSize() { return size_; }

bool ArrayDeclProxy::isScalar() { return false; }

ArrayDefProxy::ArrayDefProxy(std::ostream* out, aA_varDeclStmt vd,
                             bool isGlobal, bool isParam)
    : ArrayDeclProxy(out, vd, isGlobal, isParam) {
  vals_ = &vd->u.varDef->u.defArray->vals;
}

void ArrayDefProxy::CheckLegality() {
  VarDeclCheckProxy::CheckLegality();
  if (vals_->size() != 1 && vals_->size() != size_) {
    error_print(out_, pos_,
                string("The list's lenth should be equal to the array's size"));
  }
  for (auto val : *vals_) {
    aA_type assign_type = get_RightValType(out_, val);
    check_Convert(out_, pos_, type_, assign_type);
  }
}

FnProxy::FnProxy(std::ostream* out, aA_fnDecl fd) {
  defined_ = false;
  check_g_varName(out, fd->pos, *fd->id);
  Init(fd);
}

FnProxy::FnProxy(std::ostream* out, aA_fnDef fd) {
  check_g_varName(out, fd->pos, *fd->fnDecl->id);
  Init(fd->fnDecl);
  defined_ = true;
  defPos_ = fd->pos;
}

string FnProxy::getName() { return name_; }

A_pos FnProxy::getDefPos() { return defPos_; }

bool FnProxy::isDefined() { return defined_; }

void FnProxy::CheckDecl(std::ostream* out, aA_fnDecl fd) {
  CheckParams(out, fd);
  if (!Equal(fd->type, ret_type_)) {
    error_print(out, fd->pos, "return type conflicts.");
  }
}

void FnProxy::CheckDefine(std::ostream* out, aA_fnDef fd) {
  vector<string> params;
  for (aA_varDecl vd : fd->fnDecl->paramDecl->varDecls) {
    aA_varDeclStmt vdStmt = new aA_varDeclStmt_;
    vdStmt->pos = vd->pos;
    vdStmt->kind = A_varDeclStmtType::A_varDeclKind;
    vdStmt->u.varDecl = vd;
    my_Var decl =
        VarDeclCheckProxyFactory::CreateVarDeclProxy(out, vdStmt, false, true);

    decl->CheckStmt();
    params.push_back(decl->getName());
    l_token2Var.emplace(decl->getName(), decl);
  }

  for (auto cs : fd->stmts) {
    check_CodeblockStmt(out, cs, token2Func[name_]);
  }

  for (auto codeBlockStmt : fd->stmts) {
    switch (codeBlockStmt->kind) {
      case A_varDeclStmtKind:
        erase_localVar(codeBlockStmt->u.varDeclStmt);
        break;
      default:
        break;
    }
  }
  for (auto param : params) {
    // l_token2Var[param]->Unregister();
    l_token2Var.erase(param);
  }
}

void FnProxy::CheckCall(std::ostream* out, aA_fnCall fc) {
  if (fc->vals.size() != params_.size()) {
    goto error;
  }
  for (int i = 0; i < fc->vals.size(); i++) {
    aA_rightVal val = fc->vals[i];
    aA_varDecl param = params_[i];
    if (param->kind == A_varDeclType::A_varDeclScalarKind) {
      aA_varDeclScalar scalar = param->u.declScalar;
      if (!Equal(get_RightValType(out, val), scalar->type)) {
        goto error;
      }
    } else if (param->kind == A_varDeclType::A_varDeclArrayKind) {
      if (val->kind == A_rightValType::A_arithExprValKind &&
          val->u.arithExpr->kind == A_arithExprType::A_exprUnitKind &&
          val->u.arithExpr->u.exprUnit->kind == A_exprUnitType::A_idExprKind) {
        string name = *val->u.arithExpr->u.exprUnit->u.id;
        aA_varDeclArray array = param->u.declArray;
        int len = get_arraySize(name);
        if (len != array->len) {
          goto error;
        }
        if (!Equal(get_arrayType(name), array->type)) {
          goto error;
        }
      } else {
        goto error;
      }
    }
  }

  return;
error:
  error_print(out, fc->pos,
              string("The parameters passed in do not match the function \"") +
                  *(fc->fn) + string("\"'s definition ."));
}

aA_type FnProxy::getRetType() { return ret_type_; }

void FnProxy::Init(aA_fnDecl fd) {
  name_ = *(fd->id);
  ret_type_ = fd->type;
  params_ = fd->paramDecl->varDecls;
}

void FnProxy::CheckParams(std::ostream* out, aA_fnDecl fd) {
  auto& target = fd->paramDecl->varDecls;

  if (target.size() != params_.size()) goto error;

  for (int i = 0; i < params_.size(); i++) {
    aA_varDecl a = params_[i];
    aA_varDecl b = target[i];
    if (a->kind == A_varDeclScalarKind && b->kind == A_varDeclScalarKind) {
      if (!Equal(a->u.declScalar->type, b->u.declScalar->type)) {
        goto error;
      }
    } else if (a->kind == A_varDeclArrayKind && b->kind == A_varDeclArrayKind) {
      aA_varDeclArray aArray = a->u.declArray;
      aA_varDeclArray bArray = b->u.declArray;
      if (aArray->len != bArray->len) goto error;
      if (!Equal(aArray->type, bArray->type)) goto error;
    } else {
      goto error;
    }
  }
  return;
error:
  error_print(out, fd->pos, "Function overloading is not currently supported.");
}

StructProxy::StructProxy(std::ostream* out, aA_structDef sd) {
  // if (token2Struct.find(*(sd->id)) != token2Struct.end()) {
  //   error_print(out, sd->pos, " struct redefine: " + *sd->id);
  //   return;
  // }
  members_ = sd->varDecls;
  defPos_ = sd->pos;
  name_ = *sd->id;
}

aA_type StructProxy::CheckMember(std::ostream* out, A_pos pos, string member) {
  for (auto memDecl : members_) {
    if (memDecl->kind == A_varDeclType::A_varDeclScalarKind) {
      if (memDecl->u.declScalar->id->compare(member) == 0)
        return memDecl->u.declScalar->type;
    } else {
      if (memDecl->u.declArray->id->compare(member) == 0)
        return memDecl->u.declScalar->type;
    }
  }
  error_print(out, pos,
              string("' struct '") + name_ +
                  string("' doesn't have member: '") + member + string("'."));
  return nullptr;
}
