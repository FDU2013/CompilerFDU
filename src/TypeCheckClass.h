#include <memory>
#include <string>

#include "TeaplAst.h"
#include "TeaplaAst.h"
#include "TypeCheck.h"

class VarDeclCheckProxy;
class FnProxy;
class StructProxy;

// typedef std::shared_ptr<VarDeclCheckProxy> my_Var;

using my_Var = std::shared_ptr<VarDeclCheckProxy>;
using my_Func = std::shared_ptr<FnProxy>;
using my_Struct = std::shared_ptr<StructProxy>;

using varMap = std::unordered_map<string, my_Var>;
using funcMap = std::unordered_map<string, my_Func>;
using structMap = std::unordered_map<string, my_Struct>;

varMap g_token2Var;
varMap l_token2Var;

structMap token2Struct;

funcMap token2Func;

void error_print(std::ostream* out, A_pos p, string info);
void check_g_varName(std::ostream* out, A_pos pos, string name);
void check_l_varName(std::ostream* out, A_pos pos, string name);

bool Equal(aA_type type1, aA_type type2);
aA_type get_RightValType(std::ostream* out, aA_rightVal rl);
string get_TypeName(aA_type type);
void check_Convert(std::ostream* out, A_pos pos, aA_type left, aA_type right);

class VarDeclCheckProxyFactory {
 public:
  static std::shared_ptr<VarDeclCheckProxy> CreateVarDeclProxy(
      std::ostream* out, aA_varDeclStmt vd, bool isGlobal = true,
      bool isParam = false) {
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
    return nullptr;
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
    // if (global_) {
    //   token2type_ = &g_token2Type;
    //   token2pos_ = &g_token2Pos;
    // } else {
    //   token2type_ = &l_token2Type;
    //   token2pos_ = &l_token2Pos;
    // }
  }
  void CheckStmt() {
    CheckLegality();
    ConfigTable();
  }

  void Unregister() {
    if (global_) {
      return;
    }
    EraseTable();
  }

  string getName() { return name_; }

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
    // token2type_->emplace(name_, type_);
    // token2pos_->emplace(name_, pos_);
  }
  virtual void EraseTable() {
    // token2type_->erase(name_);
    // token2pos_->erase(name_);
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
  virtual void CheckLegality() override {
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
    // if (global_) {
    //   token2Szie_ = &g_token2Size;
    // } else {
    //   token2Szie_ = &l_token2Size;
    // }
    size_ = vd->u.varDef->u.defArray->len;
  }

 protected:
  int size_;
  // arraySizeMap* token2Szie_;

  virtual void ConfigTable() override {
    VarDeclCheckProxy::ConfigTable();
    // token2Szie_->emplace(name_, size_);
  }

  virtual void EraseTable() override {
    VarDeclCheckProxy::EraseTable();
    // token2Szie_->erase(name_);
  }
};

class ArrayDefProxy : public ArrayDeclProxy {
 public:
  ArrayDefProxy(std::ostream* out, aA_varDeclStmt vd, bool isGlobal,
                bool isParam)
      : ArrayDeclProxy(out, vd, isGlobal, isParam) {
    vals_ = &vd->u.varDef->u.defArray->vals;
  }

  virtual void CheckLegality() override {
    VarDeclCheckProxy::CheckLegality();
    if (vals_->size() != 1 && vals_->size() != size_) {
      error_print(out_, pos_,
                  string("num of list is not match with array's size"));
    }
    for (auto val : *vals_) {
      aA_type assign_type = get_RightValType(out_, val);
      check_Convert(out_, pos_, type_, assign_type);
    }
  }

 protected:
  vector<aA_rightVal>* vals_;
};

class FnProxy {
 public:
  FnProxy(std::ostream* out, aA_fnDecl fd) {
    defined_ = false;
    check_g_varName(out, fd->pos, *fd->id);
    // vector<aA_varDecl>* params =
    //     new vector<aA_varDecl>(fd->paramDecl->varDecls);
    // funcDelcs.emplace(*(fd->id));
    // func2Param.emplace(*(fd->id), params);
    // func2Pos.emplace(*(fd->id), fd->pos);
    // funcparam_token2Type.emplace(*(fd->id), fd->type);
    Init(fd);
  }

  FnProxy(std::ostream* out, aA_fnDef fd) {
    check_g_varName(out, fd->pos, *fd->fnDecl->id);
    Init(fd->fnDecl);
  }

  string getName() { return name_; }

  bool isDefined() { return defined_; }

  void CheckDecl(std::ostream* out, aA_fnDecl fd) {
    check_g_varName(out, fd->pos, *fd->id);
    CheckParams(out, fd);
    if (!Equal(fd->type, ret_type_)) {
      error_print(out, fd->pos, "return type conflicts.");
    }
  }

  void Define(std::ostream* out, aA_fnDef fd) {
    vector<string> params;
    for (aA_varDecl vd : fd->fnDecl->paramDecl->varDecls) {
      aA_varDeclStmt vdStmt = new aA_varDeclStmt_;
      vdStmt->pos = vd->pos;
      vdStmt->kind = A_varDeclStmtType::A_varDeclKind;
      vdStmt->u.varDecl = vd;
      my_Var decl = VarDeclCheckProxyFactory::CreateVarDeclProxy(out, vdStmt,
                                                                 false, true);

      decl->CheckStmt();
      params.push_back(decl->getName());
      l_token2Var.emplace(decl->getName(), decl);
    }

    for (auto cs : fd->stmts) {
      check_CodeblockStmt(out, cs);
    }

    for (auto param : params) {
      l_token2Var[param]->Unregister();
      l_token2Var.erase(param);
    }
  }

 protected:
  bool defined_;
  string name_;
  A_pos defPos_;
  aA_type ret_type_;
  vector<aA_varDecl> params_;

  void Init(aA_fnDecl fd) {
    name_ = *(fd->id);
    ret_type_ = fd->type;
    params_ = fd->paramDecl->varDecls;
  }

  void CheckParams(std::ostream* out, aA_fnDecl fd) {
    auto& target = fd->paramDecl->varDecls;

    if (target.size() != params_.size()) goto error;
    for (int i = 0; i < params_.size(); i++) {
      aA_varDecl a = params_[i];
      aA_varDecl b = target[i];
      if (a->kind == A_varDeclScalarKind && b->kind == A_varDeclScalarKind) {
        aA_varDeclScalar aScalar = a->u.declScalar;
        aA_varDeclScalar bScalar = b->u.declScalar;
        if (!Equal(aScalar->type, bScalar->type)) {
          goto error;
        }
      } else if (a->kind == A_varDeclArrayKind &&
                 b->kind == A_varDeclArrayKind) {
        aA_varDeclArray aArray = a->u.declArray;
        aA_varDeclArray bArray = b->u.declArray;
        if (aArray->len != bArray->len) goto error;
        if (!Equal(aArray->type, bArray->type)) goto error;
      } else {
        goto error;
      }
    }
  error:
    error_print(out, fd->pos,
                "Function overloading is not currently supported.");
  }
};

class StructProxy {
 protected:
  bool defined_;
  string name_;
  A_pos pos_;
  aA_type ret_type_;
  vector<aA_varDecl> params_;
  std::ostream* out_;
};