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

using my_Scalar = std::shared_ptr<ScalarDeclProxy>;
using my_Array = std::shared_ptr<ArrayDeclProxy>;

using varMap = std::unordered_map<string, my_Var>;
using funcMap = std::unordered_map<string, my_Func>;
using structMap = std::unordered_map<string, my_Struct>;

varMap g_token2Var;
varMap l_token2Var;

structMap token2Struct;

funcMap token2Func;

static void error_print(std::ostream* out, A_pos p, string info) {
  *out << "Typecheck error in line " << p->line << ", col " << p->col << ": "
       << info << std::endl;
  exit(0);
}

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
  aA_type getType() { return type_; }

  virtual bool isScalar() { return true; }

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
  int getSize() { return size_; }

  virtual bool isScalar() override { return false; }

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

  void CheckDefine(std::ostream* out, aA_fnDef fd) {
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

  void CheckCall(std::ostream* out, aA_fnCall fc) {
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
            val->u.arithExpr->u.exprUnit->kind ==
                A_exprUnitType::A_idExprKind) {
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
  error:
    error_print(out, fc->pos,
                string("Function parameter \"") + *(fc->fn) +
                    string("\" does not match."));
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
        if (!Equal(a->u.declScalar->type, b->u.declScalar->type)) {
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
 public:
  StructProxy(std::ostream* out, aA_structDef sd) {
    // if (token2Struct.find(*(sd->id)) != token2Struct.end()) {
    //   error_print(out, sd->pos, " struct redefine: " + *sd->id);
    //   return;
    // }
    members_ = sd->varDecls;
    defPos_ = sd->pos;
    name_ = *sd->id;
  }

  aA_type CheckMember(std::ostream* out, A_pos pos, string member) {
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
                    string("' doesn't have member '") + member + string("'."));
    return nullptr;
  }

 protected:
  string name_;
  A_pos defPos_;
  vector<aA_varDecl> members_;
};