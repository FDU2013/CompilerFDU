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

%token <pos> ADD
%token <pos> SUB
%token <pos> MUL
%token <pos> DIV
%token <pos> SEMICOLON // ;

%type <program> Program
%type <arithExpr> ArithExpr
%type <programElementList> ProgramElementList
%type <programElement> ProgramElement
%type <exprUnit> ExprUnit
%type <structDef> StructDef
%type <varDeclStmt> VarDeclStmt
%type <fnDeclStmt> FnDeclStmt
%type <fnDef> FnDef

%start Program

%%                   /* beginning of rules section */

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


