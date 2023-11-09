/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ADD = 258,
     SUB = 259,
     MUL = 260,
     DIV = 261,
     SEMICOLON = 262,
     LEFT_PARENT = 263,
     RIGHT_PARENT = 264,
     LEFT_SQUARE_BRACKET = 265,
     RIGHT_SQUARE_BRACKET = 266,
     LEFT_BRACE = 267,
     RIGHT_BRACE = 268,
     GREATER = 269,
     NOT_LESS_THEN = 270,
     LESS = 271,
     NOT_GREATER_THEN = 272,
     EQUAL = 273,
     NOT_EQUAL = 274,
     ASSIGN = 275,
     COMMA = 276,
     COLON = 277,
     LET = 278,
     POINT = 279,
     RET = 280,
     AND = 281,
     OR = 282,
     NOT = 283,
     FN = 284,
     IF = 285,
     ELSE = 286,
     WHILE = 287,
     BREAK = 288,
     CONTINUE = 289,
     RIGHT_ARROW = 290,
     INT = 291,
     STRUCT = 292,
     Id = 293,
     Num = 294
   };
#endif
/* Tokens.  */
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
#define RET 280
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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 19 "parser.yacc"
{
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
/* Line 1529 of yacc.c.  */
#line 173 "y.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

