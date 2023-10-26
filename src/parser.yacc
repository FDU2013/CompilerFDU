%{
#include <stdio.h>
#include "TeaplAst.h"

extern A_pos pos;
extern A_program root;

extern int yylex(void);
extern "C"{
extern void yyerror(char *s); 
extern int  yywrap();
}

%}

// TODO:
// your parser

%union {
  A_pos pos;//1
  A_type type;//2
  A_varDecl varDecl;//3
  A_varDef varDef;//4
  A_rightVal rightVal;//5
  A_arithExpr arithExpr;//6
  A_boolExpr boolExpr;//7
  A_arithBiOpExpr arithBiOpExpr;//8
  A_arithUExpr arithUExpr;//9
  A_exprUnit exprUnit;//10
  A_fnCall fnCall;//11
  A_indexExpr indexExpr;//12
  A_arrayExpr arrayExpr;//13
  A_memberExpr memberExpr;//14
  A_boolUnit boolUnit;//15
  A_boolBiOpExpr boolBiOpExpr;//16
  A_boolUOpExpr boolUOpExpr;//17
  A_comExpr comExpr;//18
  A_leftVal leftVal;//19
  A_assignStmt assignStmt;//20
  A_rightValList rightValList;//21
  A_varDefScalar varDefScalar;//22
  A_varDefArray varDefArray;//23
  A_varDeclScalar varDeclScalar;//24
  A_varDeclArray varDeclArray;//25
  A_varDeclStmt varDeclStmt;//26
  A_varDeclList varDeclList;//27
  A_structDef structDef;//28
  A_paramDecl paramDecl;//29
  A_fnDecl fnDecl;//30
  A_fnDef fnDef;//31
  A_codeBlockStmt codeBlockStmt;//32
  A_ifStmt ifStmt;//33
  A_whileStmt whileStmt;//34
  A_fnDeclStmt fnDeclStmt;//35
  A_callStmt callStmt;//36
  A_returnStmt returnStmt;//37
  A_programElement programElement;//38
  A_codeBlockStmtList codeBlockStmtList;//39
  A_programElementList programElementList;//40
  A_program program;//41
  A_tokenId tokenId;//42
  A_tokenNum tokenNum;//43
}
//token是词法，就是一些不可拆分的词语
%token <pos> ADD //+
%token <pos> SUB //-
%token <pos> MUL //*
%token <pos> DIV ///
%token <pos> SEMICOLON // ;


//type是宏观层面可以分解的 比如pos，tokenId，tokenNum不属于这里,所以一共有43-3 = 40个
%type <type> Type //2
%type <varDecl> VarDecl //3
%type <varDef> VarDef //4
%type <rightVal> RightVal //5
%type <arithExpr> ArithExpr //6
%type <boolExpr> BoolExpr //7
%type <arithBiOpExpr> ArithBiOpExpr //8
%type <arithUExpr> ArithUExpr //9
%type <exprUnit> ExprUnit //10
%type <fnCall> FnCall //11
%type <indexExpr> IndexExpr //12
%type <arrayExpr> ArrayExpr //13
%type <memberExpr> MemberExpr //14
%type <boolUnit> BoolUnit //15
%type <boolBiOpExpr> BoolBiOpExpr //16
%type <boolUOpExpr> BoolUOpExpr //17
%type <comExpr> ComExpr //18
%type <leftVal> LeftVal //19
%type <assignStmt> AssignStmt //20
%type <rightValList> RightValList //21
%type <varDefScalar> VarDefScalar //22
%type <varDefArray> VarDefArray //23
%type <varDeclScalar> VarDeclScalar //24
%type <varDeclArray> VarDeclArray //25
%type <varDeclStmt> VarDeclStmt //26
%type <varDeclList> VarDeclList //27
%type <structDef> StructDef //28
%type <paramDecl> ParamDecl //29
%type <fnDecl> FnDecl //30
%type <fnDef> FnDef //31
%type <codeBlockStmt> CodeBlockStmt //32
%type <ifStmt> IfStmt //33
%type <whileStmt> WhileStmt //34
%type <fnDeclStmt> FnDeclStmt //35
%type <callStmt> CallStmt //36
%type <returnStmt> ReturnStmt //37
%type <programElement> ProgramElement //38
%type <codeBlockStmtList> CodeBlockStmtList //39
%type <programElementList> ProgramElementList //40
%type <program> Program //41

%start Program

%%                   /* beginning of rules section */


//2
Type:

//3
//A_varDecl A_VarDecl_Scalar(A_pos pos, A_varDeclScalar declScalar);
//A_varDecl A_VarDecl_Array(A_pos pos, A_varDeclArray declArray);
VarDecl:
VarDeclScalar{
  $$ = A_VarDecl_Scalar($1->pos,$1);
}
|
VarDeclArray{
  $$ = A_VarDecl_Array($1->pos,$1);
};


//4
//A_varDef A_VarDef_Scalar(A_pos pos, A_varDefScalar defScalar);
//A_varDef A_VarDef_Array(A_pos pos, A_varDefArray defArray);
VarDef:
VarDefScalar{
  $$ = A_VarDef_Scalar($1->pos,$1);
}
|
VarDefArray{
  $$ = A_VarDef_Array($1->pos,$1);
};

//5
//A_rightVal A_ArithExprRVal(A_pos pos, A_arithExpr arithExpr);
//A_rightVal A_BoolExprRVal(A_pos pos, A_boolExpr boolExpr);
RightVal:
ArithExpr{
  $$ = A_ArithExprRVal($1->pos,$1);
}
|
BoolExpr{
  $$ = A_BoolExprRVal($1->pos,$1);
};

//6
//A_arithExpr A_ArithBiOp_Expr(A_pos pos, A_arithBiOpExpr arithBiOpExpr);
//A_arithExpr A_ExprUnit(A_pos pos, A_exprUnit exprUnit);
ArithExpr:
ArithBiOpExpr{
  $$ = A_ArithBiOp_Expr($1->pos,$1);
}
|
ExprUnit{
  $$ = A_ExprUnit($1->pos,$1);
};

//7
//A_boolExpr A_BoolBiOp_Expr(A_pos pos, A_boolBiOpExpr boolBiOpExpr);
//A_boolExpr A_BoolExpr(A_pos pos, A_boolUnit boolUnit);
BoolExpr:
BoolBiOpExpr{
  A_BoolBiOp_Expr($1->pos,$1);
}
|
BoolUnit{
  A_BoolExpr($1->pos,$1)
};

//8
//A_arithBiOpExpr A_ArithBiOpExpr(A_pos pos, A_arithBiOp op, A_arithExpr left, A_arithExpr right);
ArithBiOpExpr:
ArithExpr ADD ArithExpr{
  A_ArithBiOpExpr(A_add,$1,$3)
}
|
ArithExpr SUB ArithExpr{
  A_ArithBiOpExpr(A_sbb,$1,$3)
}
|
ArithExpr MUL ArithExpr{
  A_ArithBiOpExpr(A_mul,$1,$3)
}
|
ArithExpr DIV ArithExpr{
  A_ArithBiOpExpr(A_div,$1,$3)
};

//9
//A_arithUExpr A_ArithUExpr(A_pos pos, A_arithUOp op, A_exprUnit expr);
ArithUExpr:
SUB ArithExpr{
  A_ArithUExpr($1,A_neg,$2)
};

//10
ExprUnit

//11
FnCall





















Program: ProgramElementList 
{  
  root = A_Program($1);
  $$ = A_Program($1);
}
;

ProgramElementList: ProgramElement ProgramElementList
{
  $$ = A_ProgramElementList($1, $2);
}
|
{
  $$ = NULL;
}
;

ProgramElement: VarDeclStmt
{
  $$ = A_ProgramVarDeclStmt($1->pos, $1);
}
| StructDef
{
  $$ = A_ProgramStructDef($1->pos, $1);
}
| FnDeclStmt
{
  $$ = A_ProgramFnDeclStmt($1->pos, $1);
}
| FnDef
{
  $$ = A_ProgramFnDef($1->pos, $1);
}
| SEMICOLON
{
  $$ = A_ProgramNullStmt($1);
}
;


ArithExpr: ArithExpr ADD ArithExpr
{
  $$ = A_ArithBiOp_Expr($1->pos, A_ArithBiOpExpr($1->pos, A_add, $1, $3));
}
| ArithExpr SUB ArithExpr
{
  $$ = A_ArithBiOp_Expr($1->pos, A_ArithBiOpExpr($1->pos, A_sub, $1, $3));
}
| ArithExpr MUL ArithExpr
{
  $$ = A_ArithBiOp_Expr($1->pos, A_ArithBiOpExpr($1->pos, A_mul, $1, $3));
}
| ArithExpr DIV ArithExpr
{
  $$ = A_ArithBiOp_Expr($1->pos, A_ArithBiOpExpr($1->pos, A_div, $1, $3));
}
| ExprUnit
{
  $$ = A_ExprUnit($1->pos, $1);
}
;

%%

extern "C"{
void yyerror(char * s)
{
  fprintf(stderr, "%s\n",s);
}
int yywrap()
{
  return(1);
}
}


