#pragma once
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>

#include "TeaplAst.h"
#include "TeaplaAst.h"

// you can use this type to store the type a token.
typedef std::unordered_map<string, aA_type> typeMap;

// you can use this map to store the members of a struct or params of a
// function.
typedef std::unordered_map<string, vector<aA_varDecl>*> paramMemberMap;

typedef std::map<string, A_pos> posMap;

typedef std::map<string, int> arraySizeMap;

typedef std::unordered_set<string> funcSet;

class VarDeclCheckProxy;
class FnProxy;
class StructProxy;
class VarDeclCheckProxyFactory;
// typedef std::shared_ptr<VarDeclCheckProxy> my_Var;

using my_Var = std::shared_ptr<VarDeclCheckProxy>;
using my_Func = std::shared_ptr<FnProxy>;
using my_Struct = std::shared_ptr<StructProxy>;

using my_Scalar = std::shared_ptr<ScalarDeclProxy>;
using my_Array = std::shared_ptr<ArrayDeclProxy>;

using varMap = std::unordered_map<string, my_Var>;
using funcMap = std::unordered_map<string, my_Func>;
using structMap = std::unordered_map<string, my_Struct>;

varMap g_token2Var;
varMap l_token2Var;

structMap token2Struct;

funcMap token2Func;

void check_Prog(std::ostream* out, aA_program p);
void check_VarDecl(std::ostream* out, aA_varDeclStmt vd);
void check_StructDef(std::ostream* out, aA_structDef sd);
void check_FnDecl(std::ostream* out, aA_fnDecl fd);
void check_FnDeclStmt(std::ostream* out, aA_fnDeclStmt fd);
void check_FnDef(std::ostream* out, aA_fnDef fd);
// void check_CodeblockStmt(std::ostream* out, aA_codeBlockStmt cs);
void check_CodeblockStmt(std::ostream* out, aA_codeBlockStmt cs, my_Func func);
void check_AssignStmt(std::ostream* out, aA_assignStmt as);
// void check_ArrayExpr(std::ostream* out, aA_arrayExpr ae);
aA_type check_ArrayExpr(std::ostream* out, aA_arrayExpr ae);
aA_type check_MemberExpr(std::ostream* out, aA_memberExpr me);
void check_IfStmt(std::ostream* out, aA_ifStmt is, my_Func func);
void check_BoolExpr(std::ostream* out, aA_boolExpr be);
void check_BoolUnit(std::ostream* out, aA_boolUnit bu);
aA_type check_ExprUnit(std::ostream* out, aA_exprUnit eu);
aA_type check_FuncCall(std::ostream* out, aA_fnCall fc);
// void check_FuncCall(std::ostream* out, aA_fnCall fc);
void check_WhileStmt(std::ostream* out, aA_whileStmt ws, my_Func func);
void check_CallStmt(std::ostream* out, aA_callStmt cs);

// void check_ReturnStmt(std::ostream* out, aA_returnStmt rs);
void check_ReturnStmt(std::ostream* out, aA_returnStmt rs, aA_type expected);

void check_Convert(std::ostream* out, A_pos pos, aA_type left, aA_type right);
void check_Compare(std::ostream* out, A_pos pos, aA_type left, aA_type right);
void check_scalarExists(std::ostream* out, A_pos pos,
                        string name);  // 对于局部变量的取消注册
void cancelStmtRegis(std::ostream* out, aA_varDeclStmt vd);

void check_g_varName(std::ostream* out, A_pos pos, string name);
void check_l_varName(std::ostream* out, A_pos pos, string name);

bool Equal(aA_type type1, aA_type type2);
aA_type get_RightValType(std::ostream* out, aA_rightVal rl);
string get_TypeName(aA_type type);
aA_type get_arrayType(string name);
aA_type get_scalarType(string name);
void erase_localVar(aA_varDeclStmt vd);

int get_arraySize(string name);
void erase_localVar(aA_codeBlockStmt cb);

class VarDeclCheckProxyFactory {
 public:
  static my_Var CreateVarDeclProxy(std::ostream* out, aA_varDeclStmt vd,
                                   bool isGlobal = true, bool isParam = false);

  /* 变量声明/定义检查分为三步：
   * 1获取基本信息--构造函数
   * 2检查合法性 -- CheckLegality()
   * 3配表 -- ConfigTable()
   */
};
class VarDeclCheckProxy {
 public:
  VarDeclCheckProxy(std::ostream* out, aA_varDeclStmt vd, bool isGlobal,
                    bool isParam);
  void CheckStmt();

  void Unregister();

  string getName();
  aA_type getType();

  virtual bool isScalar();

 protected:
  bool global_;
  bool param_;
  typeMap* token2type_;
  posMap* token2pos_;
  string name_;
  A_pos pos_;
  aA_type type_;
  std::ostream* out_;

  virtual void CheckLegality();
  virtual void ConfigTable();
  virtual void EraseTable();
};

class ScalarDeclProxy : public VarDeclCheckProxy {
 public:
  ScalarDeclProxy(std::ostream* out, aA_varDeclStmt vd, bool isGlobal,
                  bool isParam);
};

class ScalarDefProxy : public ScalarDeclProxy {
 public:
  ScalarDefProxy(std::ostream* out, aA_varDeclStmt vd, bool isGlobal,
                 bool isParam);
  virtual void CheckLegality() override;

 protected:
  aA_rightVal val_;
};

class ArrayDeclProxy : public VarDeclCheckProxy {
 public:
  ArrayDeclProxy(std::ostream* out, aA_varDeclStmt vd, bool isGlobal,
                 bool isParam);
  int getSize();

  virtual bool isScalar() override;

 protected:
  int size_;
  // arraySizeMap* token2Szie_;

  virtual void ConfigTable() override;

  virtual void EraseTable() override;
};

class ArrayDefProxy : public ArrayDeclProxy {
 public:
  ArrayDefProxy(std::ostream* out, aA_varDeclStmt vd, bool isGlobal,
                bool isParam);

  virtual void CheckLegality() override;

 protected:
  vector<aA_rightVal>* vals_;
};

class FnProxy {
 public:
  FnProxy(std::ostream* out, aA_fnDecl fd);

  FnProxy(std::ostream* out, aA_fnDef fd);

  string getName() { return name_; }

  bool isDefined() { return defined_; }

  void CheckDecl(std::ostream* out, aA_fnDecl fd);

  void CheckDefine(std::ostream* out, aA_fnDef fd);

  void CheckCall(std::ostream* out, aA_fnCall fc);

  aA_type getRetType();

 protected:
  bool defined_;
  string name_;
  A_pos defPos_;
  aA_type ret_type_;
  vector<aA_varDecl> params_;

  void Init(aA_fnDecl fd);

  void CheckParams(std::ostream* out, aA_fnDecl fd);
};

class StructProxy {
 public:
  StructProxy(std::ostream* out, aA_structDef sd);

  aA_type CheckMember(std::ostream* out, A_pos pos, string member);

 protected:
  string name_;
  A_pos defPos_;
  vector<aA_varDecl> members_;
};