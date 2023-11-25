/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_HPP_INCLUDED
# define YY_YY_Y_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ADD = 258,                     /* ADD  */
    SUB = 259,                     /* SUB  */
    MUL = 260,                     /* MUL  */
    DIV = 261,                     /* DIV  */
    SEMICOLON = 262,               /* SEMICOLON  */
    LEFT_PARENT = 263,             /* LEFT_PARENT  */
    RIGHT_PARENT = 264,            /* RIGHT_PARENT  */
    LEFT_SQUARE_BRACKET = 265,     /* LEFT_SQUARE_BRACKET  */
    RIGHT_SQUARE_BRACKET = 266,    /* RIGHT_SQUARE_BRACKET  */
    LEFT_BRACE = 267,              /* LEFT_BRACE  */
    RIGHT_BRACE = 268,             /* RIGHT_BRACE  */
    GREATER = 269,                 /* GREATER  */
    NOT_LESS_THEN = 270,           /* NOT_LESS_THEN  */
    LESS = 271,                    /* LESS  */
    NOT_GREATER_THEN = 272,        /* NOT_GREATER_THEN  */
    EQUAL = 273,                   /* EQUAL  */
    NOT_EQUAL = 274,               /* NOT_EQUAL  */
    ASSIGN = 275,                  /* ASSIGN  */
    COMMA = 276,                   /* COMMA  */
    COLON = 277,                   /* COLON  */
    LET = 278,                     /* LET  */
    POINT = 279,                   /* POINT  */
    RETURN = 280,                  /* RETURN  */
    AND = 281,                     /* AND  */
    OR = 282,                      /* OR  */
    NOT = 283,                     /* NOT  */
    FN = 284,                      /* FN  */
    IF = 285,                      /* IF  */
    ELSE = 286,                    /* ELSE  */
    WHILE = 287,                   /* WHILE  */
    BREAK = 288,                   /* BREAK  */
    CONTINUE = 289,                /* CONTINUE  */
    RIGHT_ARROW = 290,             /* RIGHT_ARROW  */
    INT = 291,                     /* INT  */
    STRUCT = 292,                  /* STRUCT  */
    Id = 293,                      /* Id  */
    Num = 294                      /* Num  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ADD 258
#define SUB 259
#define MUL 260
#define DIV 261
#define SEMICOLON 262
#define LEFT_PARENT 263
#define RIGHT_PARENT 264
#define LEFT_SQUARE_BRACKET 265
#define RIGHT_SQUARE_BRACKET 266
#define LEFT_BRACE 267
#define RIGHT_BRACE 268
#define GREATER 269
#define NOT_LESS_THEN 270
#define LESS 271
#define NOT_GREATER_THEN 272
#define EQUAL 273
#define NOT_EQUAL 274
#define ASSIGN 275
#define COMMA 276
#define COLON 277
#define LET 278
#define POINT 279
#define RETURN 280
#define AND 281
#define OR 282
#define NOT 283
#define FN 284
#define IF 285
#define ELSE 286
#define WHILE 287
#define BREAK 288
#define CONTINUE 289
#define RIGHT_ARROW 290
#define INT 291
#define STRUCT 292
#define Id 293
#define Num 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "parser.yacc"

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

#line 191 "y.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */
