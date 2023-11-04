#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <time.h>
#include "TeaplAst.h"
#include "TeaplaAst.h"
#include <unordered_map>


// you can use this type to store the type a token.
typedef std::unordered_map<string, aA_type> typeMap; 

// you can use this map to store the members of a struct or params of a function.
typedef std::unordered_map<string, vector<aA_varDecl>*> paramMemberMap;

void check_Prog(std::ostream* out, aA_program p);
void check_VarDecl(std::ostream* out, aA_varDeclStmt vd);
void check_StructDef(std::ostream* out, aA_structDef sd);
void check_FnDecl(std::ostream* out, aA_fnDecl fd);
void check_FnDeclStmt(std::ostream* out, aA_fnDeclStmt fd);
void check_FnDef(std::ostream* out, aA_fnDef fd);
void check_CodeblockStmt(std::ostream* out, aA_codeBlockStmt cs);
void check_AssignStmt(std::ostream* out, aA_assignStmt as);
void check_ArrayExpr(std::ostream* out, aA_arrayExpr ae);
aA_type check_MemberExpr(std::ostream* out, aA_memberExpr me);
void check_IfStmt(std::ostream* out, aA_ifStmt is);
void check_BoolExpr(std::ostream* out, aA_boolExpr be);
void check_BoolUnit(std::ostream* out, aA_boolUnit bu);
aA_type check_ExprUnit(std::ostream* out, aA_exprUnit eu);
void check_FuncCall(std::ostream* out, aA_fnCall fc);
void check_WhileStmt(std::ostream* out, aA_whileStmt ws);
void check_CallStmt(std::ostream* out, aA_callStmt cs);
void check_ReturnStmt(std::ostream* out, aA_returnStmt rs);

//对于局部变量的取消注册
void cancelStmtRegis(std::ostream* out,aA_varDeclStmt vd);
