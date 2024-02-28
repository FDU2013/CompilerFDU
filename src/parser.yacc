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
  A_pos pos;
  A_type type;
  A_varDecl varDecl;
  A_varDef varDef;
  A_rightVal rightVal;
  A_arithExpr arithExpr;
  A_boolExpr boolExpr;
  A_arithBiOpExpr arithBiOpExpr;
  A_arithUExpr arithUExpr;
  A_exprUnit exprUnit;
  A_fnCall fnCall;
  A_indexExpr indexExpr;
  A_arrayExpr arrayExpr;
  A_memberExpr memberExpr;
  A_boolUnit boolUnit;
  A_boolBiOpExpr boolBiOpExpr;
  A_boolUOpExpr boolUOpExpr;
  A_comExpr comExpr;
  A_leftVal leftVal;
  A_assignStmt assignStmt;
  A_rightValList rightValList;
  A_varDefScalar varDefScalar;
  A_varDefArray varDefArray;
  A_varDeclScalar varDeclScalar;
  A_varDeclArray varDeclArray;
  A_varDeclStmt varDeclStmt;
  A_varDeclList varDeclList;
  A_structDef structDef;
  A_paramDecl paramDecl;
  A_fnDecl fnDecl;
  A_fnDef fnDef;
  A_codeBlockStmt codeBlockStmt;
  A_ifStmt ifStmt;
  A_whileStmt whileStmt;
  A_fnDeclStmt fnDeclStmt;
  A_callStmt callStmt;
  A_returnStmt returnStmt;
  A_programElement programElement;
  A_codeBlockStmtList codeBlockStmtList;
  A_programElementList programElementList;
  A_program program;
  A_tokenId tokenId;
  A_tokenNum tokenNum;
}

%token <pos> ADD
%token <pos> SUB
%token <pos> MUL
%token <pos> DIV
%token <pos> SEMICOLON // ;
%token <pos> COMMA // ,
%token <pos> STRUCT
%token <pos> IF
%token <pos> ELSE
%token <pos> LET
%token <pos> EQUAL // ==
%token <pos> NOT_EQUAL // !=
%token <pos> ASSIGN // =
%token <pos> LEFT_PARENT // (
%token <pos> RIGHT_PARENT // )
%token <pos> LEFT_SQUARE_BRACKET // [
%token <pos> RIGHT_SQUARE_BRACKET // ]
%token <pos> LEFT_BRACE // {
%token <pos> RIGHT_BRACE // }
%token <pos> POINT // .
%token <pos> COLON // :
%token <pos> INT 
%token <pos> AND // &&
%token <pos> OR // ||
%token <pos> NOT // !
%token <pos> GREATER // >
%token <pos> NO_LESS_THAN // >=
%token <pos> LESS // <
%token <pos> NO_GREATER_THAN // <=
%token <pos> FN // fn
%token <pos> RIGHT_ARROW // ->
%token <pos> WHILE // while
%token <pos> RETURN // ret
%token <pos> BREAK // break
%token <pos> CONTINUE // continue
%token <tokenId> Id
%token <tokenNum> Num

%type <program> Program /* NO1 */
%type <programElementList> ProgramElementList /* NO2 */
%type <programElement> ProgramElement /* NO3 */
%type <structDef> StructDef /* NO4 */
%type <fnDef> FnDef /* NO5 */
%type <fnDeclStmt> FnDeclStmt /* NO6 */
%type <varDeclStmt> VarDeclStmt /* NO7 */
%type <varDeclList> VarDeclList /* NO8 */
%type <arithExpr> ArithExpr /* NO9 */
%type <exprUnit> ExprUnit /* NO10 */
%type <type> Type /* NO11 */
%type <leftVal> LeftVal /* NO12 */
%type <rightVal> RightVal /* NO13 */
%type <comExpr> ComExpr /* NO14 */
%type <boolUOpExpr> BoolUOpExpr /* NO15 */
%type <boolBiOpExpr> BoolBiOpExpr /* NO16 */
%type <boolUnit> BoolUnit /* NO17 */
%type <memberExpr> MemberExpr /* NO18 */
%type <arrayExpr> ArrayExpr /* NO19 */
%type <indexExpr> IndexExpr /* NO20 */
%type <fnCall> FnCall /* NO21 */
%type <arithUExpr> ArithUExpr /* NO22 */
%type <arithBiOpExpr> ArithBiOpExpr /* NO23 */
%type <boolExpr> BoolExpr /* NO24 */
%type <assignStmt> AssignStmt /* NO25 */
%type <rightValList> RightValList /* NO26 */
%type <varDefScalar> VarDefScalar /* NO27 */
%type <varDefArray> VarDefArray /* NO28 */
%type <varDeclScalar> VarDeclScalar /* NO29 */
%type <varDeclArray> VarDeclArray /* NO30 */
%type <varDecl> VarDecl /* NO31 */
%type <varDef> VarDef /* NO32 */
%type <paramDecl> ParamDecl /* NO33 */
%type <fnDecl> FnDecl /* NO34 */
%type <codeBlockStmt> CodeBlockStmt /*  NO35 */
%type <ifStmt> IfStmt /* NO36 */
%type <whileStmt> WhileStmt /* NO37 */
%type <callStmt> CallStmt /* NO38 */
%type <codeBlockStmtList> CodeBlockStmtList /* NO39 */
%type <returnStmt> ReturnStmt /* NO40 */

%left ADD SUB
%left MUL DIV
%left OR
%left AND


%start Program

%%                   /* beginning of rules section */
/* NO1 finish*/
Program: ProgramElementList 
{  
  root = A_Program($1);
  $$ = A_Program($1);
}
;

/* NO2 finish */
ProgramElementList: ProgramElement ProgramElementList
{
  $$ = A_ProgramElementList($1, $2);
}
|
{
  $$ = NULL;
}
;

/* NO3 finish */
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


/* NO4  finish
struct node{
  a:int
}
*/
StructDef: STRUCT Id LEFT_BRACE VarDeclList RIGHT_BRACE
{
    $$ = A_StructDef($1, $2->id, $4);
}
;

/* NO5 finish*/
FnDef: FnDecl LEFT_BRACE CodeBlockStmtList RIGHT_BRACE
{
    $$ = A_FnDef($1->pos, $1, $3);
}
;
/* NO6 finish 带分号的完整声明*/
FnDeclStmt: FnDecl SEMICOLON
{
    $$ = A_FnDeclStmt($1->pos, $1);
}
;
/* NO7 
let a:int;
let a:int=6;
let a[10]:int;
finish
*/
VarDeclStmt: LET VarDecl SEMICOLON
{
    $$ = A_VarDeclStmt($1, $2);
}
| LET VarDef SEMICOLON
{
    $$ = A_VarDefStmt($1, $2);
}
;
/* NO8
function括号里面的参数,或者结构体定义的body
a:int,b:int
 */
VarDeclList: VarDecl COMMA VarDeclList
{
    $$ = A_VarDeclList($1, $3);
}
| VarDecl
{
    $$ = A_VarDeclList($1, NULL);
}
|
{
    $$ = NULL;
}
;

/* NO9 finish*/
ArithExpr: ArithBiOpExpr
{
    $$ = A_ArithBiOp_Expr($1->pos, $1);
}
| ExprUnit
{
  $$ = A_ExprUnit($1->pos, $1);
}
;

/* NO10 
finish
10,a,a.xx,f(1,2,a),a[6],
运算单元，其实叫ArithExprUnit或许更好？
*/
ExprUnit: Num
{
    $$ = A_NumExprUnit($1->pos, $1->num);
}
| Id
{
    $$ = A_IdExprUnit($1->pos, $1->id);
}
| LEFT_PARENT ArithExpr RIGHT_PARENT
{
    $$ = A_ArithExprUnit($1, $2);
}
| FnCall
{
    $$ = A_CallExprUnit($1->pos, $1);
}
| ArrayExpr
{
    $$ = A_ArrayExprUnit($1->pos, $1);
}
| MemberExpr
{
    $$ = A_MemberExprUnit($1->pos, $1);
}
| ArithUExpr
{
    $$ = A_ArithUExprUnit($1->pos, $1);
}
;

/* NO11 finish 下次考虑包装一下NativeType和StructType
*/
Type: INT
{
    $$ = A_NativeType($1, A_intTypeKind);
}
| Id
{
    $$ = A_StructType($1->pos, $1->id);
}
;


/* NO12 finish*/
LeftVal: Id
{
    $$ = A_IdExprLVal($1->pos, $1->id);
}
| ArrayExpr
{
    $$ = A_ArrExprLVal($1->pos, $1);
}
| MemberExpr
{
    $$ = A_MemberExprLVal($1->pos, $1);
}
;

/* NO13 finish
*/
RightVal: ArithExpr
{
    $$ = A_ArithExprRVal($1->pos, $1);
}
| BoolExpr
{
    $$ = A_BoolExprRVal($1->pos, $1);
}
;

/* NO14 
比较式  (1+1) >= (2+2)注意左右必须是unit，式子的话得加上括号
finish
*/
ComExpr: ExprUnit GREATER ExprUnit
{
    $$ = A_ComExpr($1->pos, A_gt, $1, $3);
}
| ExprUnit NO_GREATER_THAN ExprUnit
{
    $$ = A_ComExpr($1->pos, A_le, $1, $3);
}
| ExprUnit LESS ExprUnit
{
    $$ = A_ComExpr($1->pos, A_lt, $1, $3);
}
| ExprUnit NO_LESS_THAN ExprUnit
{
    $$ = A_ComExpr($1->pos, A_ge, $1, $3);
}
| ExprUnit NOT_EQUAL ExprUnit
{
    $$ = A_ComExpr($1->pos, A_ne, $1, $3);
}
| ExprUnit EQUAL ExprUnit
{
    $$ = A_ComExpr($1->pos, A_eq, $1, $3);
}
;

/* NO15 finish*/
BoolUOpExpr: NOT BoolUnit
{
    $$ = A_BoolUOpExpr($1, A_not, $2);
}
;

/* NO16 
a<0 and a>10 || a==111
注意运算符优先级，not > and >or
所以应该先按照or展开，再按照and展开
*/
BoolBiOpExpr: BoolExpr OR BoolExpr
{
    $$ = A_BoolBiOpExpr($1->pos, A_or, $1, $3);
}
| BoolExpr AND BoolExpr
{
    $$ = A_BoolBiOpExpr($1->pos, A_and, $1, $3);
}
;

/* NO17 
BoolUnit是指最外层没有and和or的布尔表达式
*/
BoolUnit: ComExpr
{
    $$ = A_ComExprUnit($1->pos, $1);
}
| LEFT_PARENT BoolExpr RIGHT_PARENT
{
    $$ = A_BoolExprUnit($1, $2);
}
| BoolUOpExpr
{
    $$ = A_BoolUOpExprUnit($1->pos, $1);
}
;

/* NO18 */
MemberExpr: LeftVal POINT Id
{
    $$ = A_MemberExpr($1->pos, $1, $3->id);
}
;
/* NO19
a[10]
*/
ArrayExpr: LeftVal LEFT_SQUARE_BRACKET IndexExpr RIGHT_SQUARE_BRACKET
{
    $$ = A_ArrayExpr($1->pos, $1, $3);
}
;
/* NO20 */
IndexExpr: Num
{
    $$ = A_NumIndexExpr($1->pos, $1->num);
}
| Id
{
    $$ = A_IdIndexExpr($1->pos, $1->id);
}
;

/* NO21 
f(1+1,a+2)
*/
FnCall: Id LEFT_PARENT RightValList RIGHT_PARENT
{
    $$ = A_FnCall($1->pos, $1->id, $3);
}
;
/* NO22 

*/
ArithUExpr: SUB ExprUnit
{
    $$ = A_ArithUExpr($1, A_neg, $2);
}
;
/* NO23 */
ArithBiOpExpr:ArithExpr ADD ArithExpr
{
  $$ = A_ArithBiOpExpr($1->pos, A_add, $1, $3);
}
| ArithExpr SUB ArithExpr
{
  $$ = A_ArithBiOpExpr($1->pos, A_sub, $1, $3);
}
| ArithExpr MUL ArithExpr
{
  $$ = A_ArithBiOpExpr($1->pos, A_mul, $1, $3);
}
| ArithExpr DIV ArithExpr
{
  $$ = A_ArithBiOpExpr($1->pos, A_div, $1, $3);
}
;
/* NO24 
a<0 and (a>5)
!a
*/
BoolExpr: BoolBiOpExpr
{
    $$ = A_BoolBiOp_Expr($1->pos, $1);
}
| BoolUnit
{
    $$ = A_BoolExpr($1->pos, $1);
}
;

/* NO25
a = b+2;
a.xx = fun();
 */
AssignStmt: LeftVal ASSIGN RightVal SEMICOLON
{
    $$ = A_AssignStmt($1->pos, $1, $3);
}
;
/* NO26
a,b+2,3*4
 */
RightValList: RightVal COMMA RightValList
{
    $$ = A_RightValList($1, $3);
}
| RightVal
{
    $$ = A_RightValList($1, NULL);
}
|
{
    $$ = NULL;
}
;
/* NO27 
a:int = 6;
*/
VarDefScalar: Id COLON Type ASSIGN RightVal
{
    $$ = A_VarDefScalar($1->pos, $1->id, $3, $5);
}
;
/* NO28 
id[len]:type = {vals} (eg: a[10]:int = {1, 2})
*/
VarDefArray: Id LEFT_SQUARE_BRACKET Num RIGHT_SQUARE_BRACKET COLON Type ASSIGN LEFT_BRACE RightValList RIGHT_BRACE
{
    $$ = A_VarDefArray($1->pos, $1->id, $3->num, $6, $9);
}
;
/* NO29 
id:type (eg: a:int)
*/
VarDeclScalar: Id COLON Type
{
    $$ = A_VarDeclScalar($1->pos, $1->id, $3);
}
;
/* NO30 
a[10]:int
*/
VarDeclArray: Id LEFT_SQUARE_BRACKET Num RIGHT_SQUARE_BRACKET COLON Type
{
    $$ = A_VarDeclArray($1->pos, $1->id, $3->num, $6);
}
/* NO31 
a:int
a[10]:int
*/
VarDecl: VarDeclScalar
{
    $$ = A_VarDecl_Scalar($1->pos, $1);
}
| VarDeclArray
{
    $$ = A_VarDecl_Array($1->pos, $1);
}
;
/* NO32
a:int = 6
a[10]:int = {0}
 */
VarDef: VarDefScalar 
{
    $$ = A_VarDef_Scalar($1->pos, $1);
}
| VarDefArray 
{
    $$ = A_VarDef_Array($1->pos, $1);
}
;

/* NO33 参数声明 
a:int,b:xx
*/
// A_paramDecl A_ParamDecl(A_varDeclList varDecls);
ParamDecl: VarDeclList
{
  $$ = A_ParamDecl($1);
}
;

/* NO34 函数声明 
fn f(a:int,b:int)
fn f(a:int,b:int)->int
*/
// A_fnDecl A_FnDecl(A_pos pos, char* id, A_paramDecl paramDecl, A_type type);
FnDecl: FN Id LEFT_PARENT ParamDecl RIGHT_PARENT
{
  $$ = A_FnDecl($1, $2->id, $4, NULL);
}
| FN Id LEFT_PARENT ParamDecl RIGHT_PARENT RIGHT_ARROW Type
{
  $$ = A_FnDecl($1, $2->id, $4, $7);
}
;

/*  NO35 代码块语句 */
/*
A_codeBlockStmt A_BlockNullStmt(A_pos pos);
A_codeBlockStmt A_BlockVarDeclStmt(A_pos pos, A_varDeclStmt varDeclStmt);
A_codeBlockStmt A_BlockAssignStmt(A_pos pos, A_assignStmt assignStmt);
A_codeBlockStmt A_BlockCallStmt(A_pos pos, A_callStmt callStmt);
A_codeBlockStmt A_BlockIfStmt(A_pos pos, A_ifStmt ifStmt);
A_codeBlockStmt A_BlockWhileStmt(A_pos pos, A_whileStmt whileStmt);
A_codeBlockStmt A_BlockReturnStmt(A_pos pos, A_returnStmt returnStmt);
A_codeBlockStmt A_BlockContinueStmt(A_pos pos);
A_codeBlockStmt A_BlockBreakStmt(A_pos pos);
*/
CodeBlockStmt: VarDeclStmt
{
  $$ = A_BlockVarDeclStmt($1->pos, $1);
}
| AssignStmt
{
  $$ = A_BlockAssignStmt($1->pos, $1);
}
| CallStmt
{
  $$ = A_BlockCallStmt($1->pos, $1);
}
| IfStmt
{
  $$ = A_BlockIfStmt($1->pos, $1);
}
| WhileStmt
{
  $$ = A_BlockWhileStmt($1->pos, $1);
}
| ReturnStmt
{
  $$ = A_BlockReturnStmt($1->pos, $1);
}
| CONTINUE SEMICOLON
{
  $$ = A_BlockContinueStmt($1);
}
| BREAK SEMICOLON
{
  $$ = A_BlockBreakStmt($1);
}
| SEMICOLON
{
  $$ = A_BlockNullStmt($1);
}
;


/* NO36 if */
// A_ifStmt A_IfStmt(A_pos pos, A_boolExpr boolExpr, A_codeBlockStmtList ifStmts, A_codeBlockStmtList elseStmts);
IfStmt: IF LEFT_PARENT BoolExpr RIGHT_PARENT LEFT_BRACE CodeBlockStmtList RIGHT_BRACE
{
  $$ = A_IfStmt($1, $3, $6, NULL);
}
| IF LEFT_PARENT BoolExpr RIGHT_PARENT LEFT_BRACE CodeBlockStmtList RIGHT_BRACE ELSE LEFT_BRACE CodeBlockStmtList RIGHT_BRACE
{
  $$ = A_IfStmt($1, $3, $6, $10);
}
;

/* NO37 while */
// A_whileStmt A_WhileStmt(A_pos pos, A_boolExpr boolExpr, A_codeBlockStmtList whileStmts);
WhileStmt: WHILE LEFT_PARENT BoolExpr RIGHT_PARENT LEFT_BRACE CodeBlockStmtList RIGHT_BRACE
{
  $$ = A_WhileStmt($1, $3, $6);
}
;

/* NO38 */
// A_callStmt A_CallStmt(A_pos pos, A_fnCall fnCall);
CallStmt: FnCall SEMICOLON
{
  $$ = A_CallStmt($1->pos, $1);
}
;

/* NO39 */
// A_codeBlockStmtList A_CodeBlockStmtList(A_codeBlockStmt head, A_codeBlockStmtList tail);
CodeBlockStmtList: CodeBlockStmt CodeBlockStmtList
{
  $$ = A_CodeBlockStmtList($1, $2);
}
| CodeBlockStmt
{
  $$ = A_CodeBlockStmtList($1, NULL);
}
;


/* NO40 return */
// A_returnStmt A_ReturnStmt(A_pos pos, A_rightVal retVal);
ReturnStmt: RETURN RightVal SEMICOLON
{
  $$ = A_ReturnStmt($1, $2);
}
| RETURN SEMICOLON
{
  $$ = A_ReturnStmt($1, NULL);
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

