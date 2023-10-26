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
%token <pos> ADD //加法
%token <pos> SUB //减法
%token <pos> MUL //乘法
%token <pos> DIV //除法
%token <pos> SEMICOLON // 分号
%token <pos> LEFT_PARENT //左小括号
%token <pos> RIGHT_PARENT //右小括号
%token <pos> LEFT_SQUARE_BRACKET //左中括号
%token <pos> RIGHT_SQUARE_BRACKET //右中括号
%token <pos> LEFT_BRACE //左大括号
%token <pos> RIGHT_BRACE //右大括号
%token <pos> GREATER //大于
%token <pos> NOT_LESS_THEN //大于等于
%token <pos> LESS //小于
%token <pos> NOT_GREATER_THEN //小于等于
%token <pos> EQUAL //等于
%token <pos> NOT_EQUAL //不等于
%token <pos> ASSIGN // 赋值
%token <pos> COMMA //逗号
%token <pos> COLON //冒号
%token <pos> LET //let
%token <pos> POINT //点，比如用在struct上
%token <pos> RET //ret
%token <pos> AND //与
%token <pos> OR //或
%token <pos> NOT //非
%token <pos> FN //fn
%token <pos> IF //if
%token <pos> ELSE //else
%token <pos> WHILE //while
%token <pos> BREAK //break
%token <pos> CONTINUE //continue
%token <pos> RIGHT_ARROW //->
%token <pos> INT //int
%token <pos> STRUCT //struct
%token <tokenId> Id 
%token <tokenNum> Num


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
//A_type A_NativeType(A_pos pos, A_nativeType ntype);
//A_type A_StructType(A_pos pos, char* stype);
Type:
INT{
  $$ = A_NativeType($1,A_intTypeKind);
}
|
Id{
  $$ = A_StructType($1->pos,$1->id);
}

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
  $$ = A_BoolBiOp_Expr($1->pos,$1);
}
|
BoolUnit{
  $$ = A_BoolExpr($1->pos,$1);
};

//8
//A_arithBiOpExpr A_ArithBiOpExpr(A_pos pos, A_arithBiOp op, A_arithExpr left, A_arithExpr right);
ArithBiOpExpr:
ArithExpr ADD ArithExpr{
  $$ = A_ArithBiOpExpr($1->pos,A_add,$1,$3);
}
|
ArithExpr SUB ArithExpr{
  $$ = A_ArithBiOpExpr($1->pos,A_sub,$1,$3);
}
|
ArithExpr MUL ArithExpr{
  $$ = A_ArithBiOpExpr($1->pos,A_mul,$1,$3);
}
|
ArithExpr DIV ArithExpr{
  $$ = A_ArithBiOpExpr($1->pos,A_div,$1,$3);
};

//9
//A_arithUExpr A_ArithUExpr(A_pos pos, A_arithUOp op, A_exprUnit expr);
ArithUExpr:
SUB ExprUnit{
  $$ = A_ArithUExpr($1,A_neg,$2);
};

//10
//A_exprUnit A_NumExprUnit(A_pos pos, int num);
//A_exprUnit A_IdExprUnit(A_pos pos, char* id);
//A_exprUnit A_ArithExprUnit(A_pos pos, A_arithExpr arithExpr);
//A_exprUnit A_CallExprUnit(A_pos pos, A_fnCall callExpr);
//A_exprUnit A_ArrayExprUnit(A_pos pos, A_arrayExpr arrayExpr);
//A_exprUnit A_MemberExprUnit(A_pos pos, A_memberExpr memberExpr);
//A_exprUnit A_ArithUExprUnit(A_pos pos, A_arithUExpr arithUExpr);
ExprUnit:
Num{
  $$ = A_NumExprUnit($1->pos,$1->num);
}
|
Id{
  $$ = A_IdExprUnit($1->pos,$1->id);
}
|
LEFT_PARENT ArithExpr RIGHT_PARENT { 
  $$ = A_ArithExprUnit($1,$2); //括号是Apos类型
}
|
FnCall{
  $$ = A_CallExprUnit($1->pos,$1);
}
|
ArrayExpr{
  $$ = A_ArrayExprUnit($1->pos,$1);
}
|
MemberExpr{
  $$ = A_MemberExprUnit($1->pos,$1);
}
|
ArithUExpr{
  $$ = A_ArithUExprUnit($1->pos,$1);
};

//11
//A_fnCall A_FnCall(A_pos pos, char* fn, A_rightValList vals);
FnCall:
Id LEFT_PARENT RightValList RIGHT_PARENT{
  $$ = A_FnCall($1->pos,$1->id,$3);
};

//12
//A_indexExpr A_NumIndexExpr(A_pos pos, int num);
//A_indexExpr A_IdIndexExpr(A_pos pos, char* id);
IndexExpr:
Num{
  $$ = A_NumIndexExpr($1->pos,$1->num);
}
|
Id{
  $$ = A_IdIndexExpr($1->pos,$1->id);
};

//13 数组
//A_arrayExpr A_ArrayExpr(A_pos pos, char* arr, A_indexExpr idx);
ArrayExpr:
Id LEFT_SQUARE_BRACKET IndexExpr RIGHT_SQUARE_BRACKET{
  $$ = A_ArrayExpr($1->pos,$1->id,$3);
};

//14 member是？
//A_memberExpr A_MemberExpr(A_pos pos, char* structId, char* memberId);
MemberExpr:
Id POINT Id{
  $$ = A_MemberExpr($1->pos,$1->id,$3->id);
};


//15
//A_boolUnit A_ComExprUnit(A_pos pos, A_comExpr comExpr);
//A_boolUnit A_BoolExprUnit(A_pos pos, A_boolExpr boolExpr);
//A_boolUnit A_BoolUOpExprUnit(A_pos pos, A_boolUOpExpr boolUOpExpr);
BoolUnit:
ComExpr{
  $$ = A_ComExprUnit($1->pos,$1);
}
|
LEFT_PARENT BoolExpr RIGHT_PARENT{
  $$ = A_BoolExprUnit($1,$2);
}
|
BoolUOpExpr{
  $$ = A_BoolUOpExprUnit($1->pos,$1);
};

//16
//A_boolBiOpExpr A_BoolBiOpExpr(A_pos pos, A_boolBiOp op, A_boolExpr left, A_boolUnit right);
BoolBiOpExpr:
BoolExpr OR BoolUnit{
  $$ = A_BoolBiOpExpr($1->pos,A_or,$1,$3);
}
|
BoolExpr AND BoolUnit{
  $$ = A_BoolBiOpExpr($1->pos,A_and,$1,$3);
};

//17
//A_boolUOpExpr A_BoolUOpExpr(A_pos pos, A_boolUOp op, A_boolUnit cond);
BoolUOpExpr:
NOT BoolUnit{
  $$ = A_BoolUOpExpr($1,A_not,$2);
};

//18 比较 分为 大于，大于等于，小于，小于等于，等于，不等于
//A_comExpr A_ComExpr(A_pos pos, A_comOp op, A_exprUnit left, A_exprUnit right);
ComExpr:
ExprUnit GREATER ExprUnit{
  $$ = A_ComExpr($1->pos,A_gt,$1,$3);
}
|
ExprUnit NOT_GREATER_THEN ExprUnit{
  $$ = A_ComExpr($1->pos,A_le,$1,$3);
}
|
ExprUnit LESS ExprUnit{
  $$ = A_ComExpr($1->pos,A_lt,$1,$3);
}
|
ExprUnit NOT_LESS_THEN ExprUnit{
  $$ = A_ComExpr($1->pos,A_ge,$1,$3);
}
|
ExprUnit NOT_EQUAL ExprUnit{
  $$ = A_ComExpr($1->pos,A_ne,$1,$3);
}
|
ExprUnit EQUAL ExprUnit{
  $$ = A_ComExpr($1->pos,A_eq,$1,$3);
};

//19
//A_leftVal A_IdExprLVal(A_pos pos, char* id);
//A_leftVal A_ArrExprLVal(A_pos pos, A_arrayExpr arrExpr);
//A_leftVal A_MemberExprLVal(A_pos pos, A_memberExpr memberExpr);
LeftVal:
Id{
  $$ = A_IdExprLVal($1->pos,$1->id);
}
|
ArrayExpr{
  $$ = A_ArrExprLVal($1->pos,$1);
}
|
MemberExpr{
  $$ = A_MemberExprLVal($1->pos,$1);
};


//20 赋值
//A_assignStmt A_AssignStmt(A_pos pos, A_leftVal leftVal, A_rightVal rightVal);
AssignStmt:
LeftVal ASSIGN RightVal SEMICOLON{
 $$ = A_AssignStmt($1->pos,$1,$3);
};

//21 函数传参用到的list
//A_rightValList A_RightValList(A_rightVal head, A_rightValList tail);
RightValList:
RightVal COMMA RightValList{
  $$ = A_RightValList($1,$3);
}
|
RightVal{
  $$ = A_RightValList($1,NULL);
}
|
{
  $$ = NULL;
};

//22 定义 var:int = 1
//A_varDefScalar A_VarDefScalar(A_pos pos, char* id, A_type type, A_rightVal val);
VarDefScalar:
Id COLON Type ASSIGN RightVal{
  $$ = A_VarDefScalar($1->pos,$1->id,$3,$5);
};

//23 带数组的 比如a[1]:int = {1}
//A_varDefArray A_VarDefArray(A_pos pos, char* id, int len, A_type type, A_rightValList vals);
VarDefArray:
Id LEFT_SQUARE_BRACKET Num RIGHT_SQUARE_BRACKET COLON Type ASSIGN LEFT_BRACE RightValList RIGHT_BRACE{
  $$ = A_VarDefArray($1->pos,$1->id,$3->num,$6,$9);
};

//24 a:int
//A_varDeclScalar A_VarDeclScalar(A_pos pos, char* id, A_type type);
VarDeclScalar:
Id COLON Type{
  $$ = A_VarDeclScalar($1->pos,$1->id,$3);
};

//25 a[1]:int
//A_varDeclArray A_VarDeclArray(A_pos pos, char* id, int len, A_type type);
VarDeclArray:
Id LEFT_SQUARE_BRACKET Num RIGHT_SQUARE_BRACKET COLON Type{
  $$ = A_VarDeclArray($1->pos,$1->id,$3->num,$6);
}

//26
//A_varDeclStmt A_VarDeclStmt(A_pos pos, A_varDecl varDecl);
//A_varDeclStmt A_VarDefStmt(A_pos pos, A_varDef varDef);
//let a/a[1]:int
//let a:int = 6
VarDeclStmt:
LET VarDecl SEMICOLON{
  $$ = A_VarDeclStmt($1,$2);
}
|
LET VarDef SEMICOLON{
  $$ = A_VarDefStmt($1,$2);
};

//27
//A_varDeclList A_VarDeclList(A_varDecl head, A_varDeclList tail);
//a:int,b:int
VarDeclList:
VarDecl COMMA VarDeclList{
  $$ = A_VarDeclList($1,$3);
}
|
VarDecl{
  $$ = A_VarDeclList($1,NULL);
}
|
{
  $$ = NULL;
};


//28
//A_structDef A_StructDef(A_pos pos, char* id, A_varDeclList varDecls);
StructDef:
STRUCT Id LEFT_BRACE VarDeclList RIGHT_BRACE{
  $$ = A_StructDef($1,$2->id,$4);
};

//29
//A_paramDecl A_ParamDecl(A_varDeclList varDecls)
ParamDecl:
VarDeclList{
  $$ = A_ParamDecl($1);
};

//30
//A_fnDecl A_FnDecl(A_pos pos, char* id, A_paramDecl paramDecl, A_type type);
//声明函数 fn f(a:int)->int
FnDecl:
FN Id LEFT_PARENT ParamDecl RIGHT_PARENT{
  $$ = A_FnDecl($1,$2->id,$4,NULL);
}
|
FN Id LEFT_PARENT ParamDecl RIGHT_PARENT RIGHT_ARROW Type{
  $$ = A_FnDecl($1,$2->id,$4,$7);
};

//31
//A_fnDef A_FnDef(A_pos pos, A_fnDecl fnDecl, A_codeBlockStmtList stmts);
FnDef:
FnDecl LEFT_BRACE CodeBlockStmtList RIGHT_BRACE{
  $$ = A_FnDef($1->pos,$1,$3);
};

//32
//A_codeBlockStmt A_BlockNullStmt(A_pos pos);
//A_codeBlockStmt A_BlockVarDeclStmt(A_pos pos, A_varDeclStmt varDeclStmt);
//A_codeBlockStmt A_BlockAssignStmt(A_pos pos, A_assignStmt assignStmt);
//A_codeBlockStmt A_BlockCallStmt(A_pos pos, A_callStmt callStmt);
//A_codeBlockStmt A_BlockIfStmt(A_pos pos, A_ifStmt ifStmt);
//A_codeBlockStmt A_BlockWhileStmt(A_pos pos, A_whileStmt whileStmt);
//A_codeBlockStmt A_BlockReturnStmt(A_pos pos, A_returnStmt returnStmt);
//A_codeBlockStmt A_BlockContinueStmt(A_pos pos);
//A_codeBlockStmt A_BlockBreakStmt(A_pos pos);
CodeBlockStmt:
VarDeclStmt{
  $$ = A_BlockVarDeclStmt($1->pos,$1);
}
|
AssignStmt{
  $$ = A_BlockAssignStmt($1->pos,$1);
}
|
CallStmt{
  $$ = A_BlockCallStmt($1->pos,$1);
}
|
IfStmt{
  $$ = A_BlockIfStmt($1->pos,$1);
}
|
WhileStmt{
  $$ = A_BlockWhileStmt($1->pos,$1);
}
|
ReturnStmt{
  $$ = A_BlockReturnStmt($1->pos,$1);
}
|
CONTINUE SEMICOLON{
  $$ = A_BlockContinueStmt($1);
}
|
BREAK SEMICOLON{
  $$ = A_BlockBreakStmt($1);
}
|
SEMICOLON{
  $$ = A_BlockNullStmt($1);
};

//33
//A_ifStmt A_IfStmt(A_pos pos, A_boolExpr boolExpr, A_codeBlockStmtList ifStmts, A_codeBlockStmtList elseStmts);
IfStmt:
IF LEFT_PARENT BoolExpr RIGHT_PARENT LEFT_BRACE CodeBlockStmtList RIGHT_BRACE{
  $$ = A_IfStmt($1,$3,$6,NULL);
}
|
IF LEFT_PARENT BoolExpr RIGHT_PARENT LEFT_BRACE CodeBlockStmtList RIGHT_BRACE ELSE LEFT_BRACE CodeBlockStmtList RIGHT_BRACE{
  $$ = A_IfStmt($1,$3,$6,$10);
};


//34
//A_whileStmt A_WhileStmt(A_pos pos, A_boolExpr boolExpr, A_codeBlockStmtList whileStmts);
WhileStmt:
WHILE LEFT_PARENT BoolExpr RIGHT_PARENT LEFT_BRACE CodeBlockStmtList RIGHT_BRACE{
  $$ = A_WhileStmt($1,$3,$6);
};

//35
//A_fnDeclStmt A_FnDeclStmt(A_pos pos, A_fnDecl fnDecl);
FnDeclStmt:
FnDecl SEMICOLON{
  $$ = A_FnDeclStmt($1->pos,$1);
};

//36
//A_callStmt A_CallStmt(A_pos pos, A_fnCall fnCall);
CallStmt:
FnCall SEMICOLON{
  $$ = A_CallStmt($1->pos,$1);
};

//37
//A_returnStmt A_ReturnStmt(A_pos pos, A_rightVal retVal);
ReturnStmt:
RET RightVal SEMICOLON{
  $$ = A_ReturnStmt($1,$2);
};

//38
//A_programElement A_ProgramNullStmt(A_pos pos);
//A_programElement A_ProgramVarDeclStmt(A_pos pos, A_varDeclStmt varDeclStmt);
//A_programElement A_ProgramStructDef(A_pos pos, A_structDef structDef);
//A_programElement A_ProgramFnDeclStmt(A_pos pos, A_fnDeclStmt fnDecl);
//A_programElement A_ProgramFnDef(A_pos pos, A_fnDef fnDef);
ProgramElement:
VarDeclStmt
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

//39
//A_codeBlockStmtList A_CodeBlockStmtList(A_codeBlockStmt head, A_codeBlockStmtList tail);
CodeBlockStmtList:
CodeBlockStmt CodeBlockStmtList{
  $$ = A_CodeBlockStmtList($1,$2);
}
|
CodeBlockStmt{
  $$ = A_CodeBlockStmtList($1,NULL);
}

//40
//A_programElementList A_ProgramElementList(A_programElement head, A_programElementList tail);
ProgramElementList:
ProgramElement ProgramElementList{
  $$ = A_ProgramElementList($1,$2);
}
|
{
  $$ = NULL;
};

//41
//A_program A_Program(A_programElementList programElements);
Program: 
ProgramElementList 
{  
  root = A_Program($1);
  $$ = A_Program($1);
};


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


