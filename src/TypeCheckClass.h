#include <string>

#include "TeaplAst.h"
#include "TeaplaAst.h"
#include "TypeCheck.h"

extern typeMap g_token2Type;
extern typeMap l_token2Type;

extern typeMap funcparam_token2Type;

extern paramMemberMap func2Param;
extern paramMemberMap struct2Members;

extern funcSet funcDefs;
extern funcSet funcDelcs;

extern posMap func2Pos;
extern posMap g_token2Pos;
extern posMap l_token2Pos;

extern arraySizeMap g_token2Size;
extern arraySizeMap l_token2Size;

void error_print(std::ostream* out, A_pos p, string info);
void check_g_varName(std::ostream* out, A_pos pos, string name);
void check_l_varName(std::ostream* out, A_pos pos, string name);

bool Equal(aA_type type1, aA_type type2);
aA_type get_RightValType(std::ostream* out, aA_rightVal rl);
string get_TypeName(aA_type type);
void check_Convert(std::ostream* out, A_pos pos, aA_type left, aA_type right);

class VarDeclCheckProxyFactory {
 public:
  static VarDeclCheckProxy CreateVarDeclProxy(std::ostream* out,
                                              aA_varDeclStmt vd,
                                              bool isGlobal = true,
                                              bool isParam = false) {
    if (vd->kind == A_varDeclStmtType::A_varDeclKind) {
      if (vd->u.varDecl->kind == A_varDeclType::A_varDeclScalarKind) {
        return ScalarDeclProxy(out, vd, isGlobal, isParam);
      } else {
        return ArrayDeclProxy(out, vd, isGlobal, isParam);
      }
    } else if (vd->kind == A_varDeclStmtType::A_varDefKind) {
      if (vd->u.varDef->kind == A_varDefType::A_varDefScalarKind) {
        return ScalarDefProxy(out, vd, isGlobal, isParam);
      } else {
        return ArrayDefProxy(out, vd, isGlobal, isParam);
      }
    } else {
      return;
    }
  }
};

/* 变量声明/定义检查分为三步：
 * 1获取基本信息--构造函数
 * 2检查合法性 -- CheckLegality()
 * 3配表 -- ConfigTable()
 */

class VarDeclCheckProxy {
 public:
  VarDeclCheckProxy(std::ostream* out, aA_varDeclStmt vd, bool isGlobal,
                    bool isParam) {
    name_ = *vd->u.varDecl->u.declScalar->id;
    pos_ = vd->u.varDecl->u.declScalar->pos;
    type_ = vd->u.varDecl->u.declScalar->type;
    global_ = isGlobal;
    param_ = isParam;
    out_ = out;
    if (global_) {
      token2type_ = &g_token2Type;
      token2pos_ = &g_token2Pos;
    } else {
      token2type_ = &l_token2Type;
      token2pos_ = &l_token2Pos;
    }
  }
  void CheckStmt() {
    CheckLegality();
    ConfigTable();
  }

 protected:
  bool global_;
  bool param_;
  typeMap* token2type_;
  posMap* token2pos_;
  string name_;
  A_pos pos_;
  aA_type type_;
  std::ostream* out_;

  virtual void CheckLegality() {
    if (global_) {
      check_g_varName(out_, pos_, name_);
    } else if (!param_) {
      check_l_varName(out_, pos_, name_);
    }
  }
  virtual void ConfigTable() {
    token2type_->emplace(name_, type_);
    token2pos_->emplace(name_, pos_);
  }
};

class ScalarDeclProxy : public VarDeclCheckProxy {
 public:
  ScalarDeclProxy(std::ostream* out, aA_varDeclStmt vd, bool isGlobal,
                  bool isParam)
      : VarDeclCheckProxy(out, vd, isGlobal, isParam) {}
};

class ScalarDefProxy : public ScalarDeclProxy {
 public:
  ScalarDefProxy(std::ostream* out, aA_varDeclStmt vd, bool isGlobal,
                 bool isParam)
      : ScalarDeclProxy(out, vd, isGlobal, isParam) {
    val_ = vd->u.varDef->u.defScalar->val;
  }
  void CheckLegality() override {
    VarDeclCheckProxy::CheckLegality();
    aA_type assign_type = get_RightValType(out_, val_);
    check_Convert(out_, pos_, type_, assign_type);
  }

 protected:
  aA_rightVal val_;
};

class ArrayDeclProxy : public VarDeclCheckProxy {
 public:
  ArrayDeclProxy(std::ostream* out, aA_varDeclStmt vd, bool isGlobal,
                 bool isParam)
      : VarDeclCheckProxy(out, vd, isGlobal, isParam) {
    if (global_) {
      token2Szie_ = &g_token2Size;
    } else {
      token2Szie_ = &l_token2Size;
    }
  }

 protected:
  arraySizeMap* token2Szie_;
};

class ArrayDefProxy : public ArrayDeclProxy {
 public:
  ArrayDefProxy(std::ostream* out, aA_varDeclStmt vd, bool isGlobal,
                bool isParam)
      : ArrayDeclProxy(out, vd, isGlobal, isParam) {}
};