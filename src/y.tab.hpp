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
    COMMA = 263,                   /* COMMA  */
    STRUCT = 264,                  /* STRUCT  */
    IF = 265,                      /* IF  */
    ELSE = 266,                    /* ELSE  */
    LET = 267,                     /* LET  */
    EQUAL = 268,                   /* EQUAL  */
    NOT_EQUAL = 269,               /* NOT_EQUAL  */
    ASSIGN = 270,                  /* ASSIGN  */
    LEFT_PARENT = 271,             /* LEFT_PARENT  */
    RIGHT_PARENT = 272,            /* RIGHT_PARENT  */
    LEFT_SQUARE_BRACKET = 273,     /* LEFT_SQUARE_BRACKET  */
    RIGHT_SQUARE_BRACKET = 274,    /* RIGHT_SQUARE_BRACKET  */
    LEFT_BRACE = 275,              /* LEFT_BRACE  */
    RIGHT_BRACE = 276,             /* RIGHT_BRACE  */
    POINT = 277,                   /* POINT  */
    COLON = 278,                   /* COLON  */
    INT = 279,                     /* INT  */
    AND = 280,                     /* AND  */
    OR = 281,                      /* OR  */
    NOT = 282,                     /* NOT  */
    GREATER = 283,                 /* GREATER  */
    NO_LESS_THAN = 284,            /* NO_LESS_THAN  */
    LESS = 285,                    /* LESS  */
    NO_GREATER_THAN = 286,         /* NO_GREATER_THAN  */
    FN = 287,                      /* FN  */
    RIGHT_ARROW = 288,             /* RIGHT_ARROW  */
    WHILE = 289,                   /* WHILE  */
    RETURN = 290,                  /* RETURN  */
    BREAK = 291,                   /* BREAK  */
    CONTINUE = 292,                /* CONTINUE  */
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
#define COMMA 263
#define STRUCT 264
#define IF 265
#define ELSE 266
#define LET 267
#define EQUAL 268
#define NOT_EQUAL 269
#define ASSIGN 270
#define LEFT_PARENT 271
#define RIGHT_PARENT 272
#define LEFT_SQUARE_BRACKET 273
#define RIGHT_SQUARE_BRACKET 274
#define LEFT_BRACE 275
#define RIGHT_BRACE 276
#define POINT 277
#define COLON 278
#define INT 279
#define AND 280
#define OR 281
#define NOT 282
#define GREATER 283
#define NO_LESS_THAN 284
#define LESS 285
#define NO_GREATER_THAN 286
#define FN 287
#define RIGHT_ARROW 288
#define WHILE 289
#define RETURN 290
#define BREAK 291
#define CONTINUE 292
#define Id 293
#define Num 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "parser.yacc"

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

#line 191 "y.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */
