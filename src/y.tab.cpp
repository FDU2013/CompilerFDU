/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 1 "parser.yacc"

#include <stdio.h>
#include "TeaplAst.h"

extern A_pos pos;
extern A_program root;

extern int yylex(void);
extern "C"{
extern void yyerror(char *s); 
extern int  yywrap();
}



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

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
/* Line 193 of yacc.c.  */
#line 235 "y.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 248 "y.tab.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  25
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   173

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNRULES -- Number of states.  */
#define YYNSTATES  171

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    31,    35,    39,    43,    46,
      48,    50,    54,    56,    58,    60,    62,    67,    69,    71,
      76,    80,    82,    86,    88,    92,    96,    99,   103,   107,
     111,   115,   119,   123,   125,   127,   129,   134,   138,   140,
     141,   147,   158,   162,   169,   173,   177,   181,   183,   184,
     190,   192,   198,   206,   211,   213,   215,   217,   219,   221,
     223,   226,   229,   231,   239,   251,   259,   262,   265,   269,
     271,   273,   275,   277,   279,   282,   284,   287,   288
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      80,     0,    -1,    36,    -1,    38,    -1,    63,    -1,    64,
      -1,    61,    -1,    62,    -1,    45,    -1,    46,    -1,    47,
      -1,    49,    -1,    55,    -1,    54,    -1,    45,     3,    45,
      -1,    45,     4,    45,    -1,    45,     5,    45,    -1,    45,
       6,    45,    -1,     4,    49,    -1,    39,    -1,    38,    -1,
       8,    45,     9,    -1,    50,    -1,    52,    -1,    53,    -1,
      48,    -1,    38,     8,    60,     9,    -1,    39,    -1,    38,
      -1,    38,    10,    51,    11,    -1,    38,    24,    38,    -1,
      57,    -1,     8,    46,     9,    -1,    56,    -1,    46,    27,
      46,    -1,    46,    26,    46,    -1,    28,    54,    -1,    49,
      14,    49,    -1,    49,    17,    49,    -1,    49,    16,    49,
      -1,    49,    15,    49,    -1,    49,    19,    49,    -1,    49,
      18,    49,    -1,    38,    -1,    52,    -1,    53,    -1,    58,
      20,    44,     7,    -1,    44,    21,    60,    -1,    44,    -1,
      -1,    38,    22,    41,    20,    44,    -1,    38,    10,    39,
      11,    22,    41,    20,    12,    60,    13,    -1,    38,    22,
      41,    -1,    38,    10,    39,    11,    22,    41,    -1,    23,
      42,     7,    -1,    23,    43,     7,    -1,    42,    21,    66,
      -1,    42,    -1,    -1,    37,    38,    12,    66,    13,    -1,
      66,    -1,    29,    38,     8,    68,     9,    -1,    29,    38,
       8,    68,     9,    35,    41,    -1,    69,    12,    78,    13,
      -1,    65,    -1,    59,    -1,    75,    -1,    72,    -1,    73,
      -1,    76,    -1,    34,     7,    -1,    33,     7,    -1,     7,
      -1,    30,     8,    46,     9,    12,    78,    13,    -1,    30,
       8,    46,     9,    12,    78,    13,    31,    12,    78,    13,
      -1,    32,     8,    46,     9,    12,    78,    13,    -1,    69,
       7,    -1,    50,     7,    -1,    25,    44,     7,    -1,    65,
      -1,    67,    -1,    74,    -1,    70,    -1,     7,    -1,    71,
      78,    -1,    71,    -1,    77,    79,    -1,    -1,    79,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   155,   155,   159,   167,   171,   180,   184,   192,   196,
     204,   208,   216,   220,   227,   231,   235,   239,   246,   259,
     263,   267,   271,   275,   279,   283,   290,   298,   302,   309,
     316,   326,   330,   334,   341,   345,   352,   359,   363,   367,
     371,   375,   379,   388,   392,   396,   404,   411,   415,   419,
     426,   433,   440,   447,   457,   461,   469,   473,   477,   485,
     492,   500,   504,   511,   526,   530,   534,   538,   542,   546,
     550,   554,   558,   565,   569,   577,   584,   591,   598,   609,
     613,   617,   621,   625,   634,   638,   645,   649,   656
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ADD", "SUB", "MUL", "DIV", "SEMICOLON",
  "LEFT_PARENT", "RIGHT_PARENT", "LEFT_SQUARE_BRACKET",
  "RIGHT_SQUARE_BRACKET", "LEFT_BRACE", "RIGHT_BRACE", "GREATER",
  "NOT_LESS_THEN", "LESS", "NOT_GREATER_THEN", "EQUAL", "NOT_EQUAL",
  "ASSIGN", "COMMA", "COLON", "LET", "POINT", "RET", "AND", "OR", "NOT",
  "FN", "IF", "ELSE", "WHILE", "BREAK", "CONTINUE", "RIGHT_ARROW", "INT",
  "STRUCT", "Id", "Num", "$accept", "Type", "VarDecl", "VarDef",
  "RightVal", "ArithExpr", "BoolExpr", "ArithBiOpExpr", "ArithUExpr",
  "ExprUnit", "FnCall", "IndexExpr", "ArrayExpr", "MemberExpr", "BoolUnit",
  "BoolBiOpExpr", "BoolUOpExpr", "ComExpr", "LeftVal", "AssignStmt",
  "RightValList", "VarDefScalar", "VarDefArray", "VarDeclScalar",
  "VarDeclArray", "VarDeclStmt", "VarDeclList", "StructDef", "ParamDecl",
  "FnDecl", "FnDef", "CodeBlockStmt", "IfStmt", "WhileStmt", "FnDeclStmt",
  "CallStmt", "ReturnStmt", "ProgramElement", "CodeBlockStmtList",
  "ProgramElementList", "Program", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    41,    42,    42,    43,    43,    44,    44,
      45,    45,    46,    46,    47,    47,    47,    47,    48,    49,
      49,    49,    49,    49,    49,    49,    50,    51,    51,    52,
      53,    54,    54,    54,    55,    55,    56,    57,    57,    57,
      57,    57,    57,    58,    58,    58,    59,    60,    60,    60,
      61,    62,    63,    64,    65,    65,    66,    66,    66,    67,
      68,    69,    69,    70,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    72,    72,    73,    74,    75,    76,    77,
      77,    77,    77,    77,    78,    78,    79,    79,    80
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     2,     1,
       1,     3,     1,     1,     1,     1,     4,     1,     1,     4,
       3,     1,     3,     1,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     1,     1,     1,     4,     3,     1,     0,
       5,    10,     3,     6,     3,     3,     3,     1,     0,     5,
       1,     5,     7,     4,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     7,    11,     7,     2,     2,     3,     1,
       1,     1,     1,     1,     2,     1,     2,     0,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      87,    83,     0,     0,     0,    79,    80,     0,    82,    81,
      87,    88,     0,     0,     0,     0,     6,     7,     4,     5,
       0,     0,    76,     0,    86,     1,     0,     0,    54,    55,
      58,    58,    72,     0,     0,     0,     0,     0,    43,     0,
      44,    45,     0,    65,    64,    85,    67,    68,    66,    69,
       0,     0,     2,     3,    52,     0,    57,    60,     0,     0,
       0,     0,     0,    20,    19,     0,     8,     9,    10,    25,
      11,    22,    23,    24,    13,    12,    33,    31,     0,     0,
      71,    70,    49,     0,     0,    77,     0,    84,    63,     0,
       0,     0,     0,    58,    61,    59,     0,    18,     0,     0,
       0,    36,    78,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,     0,    28,
      27,     0,    30,     0,     0,    50,     0,    52,    56,     0,
      11,    21,    32,    14,    15,    16,    17,    35,    34,    37,
      40,    39,    38,    42,    41,     0,     0,    49,    26,    29,
      46,    53,     0,    62,     0,     0,    47,     0,     0,     0,
       0,    49,    53,    73,    75,     0,     0,    51,     0,     0,
      74
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    54,    56,    15,   117,    66,    67,    68,    69,    70,
      71,   121,    72,    73,    74,    75,    76,    77,    42,    43,
     118,    16,    17,    18,    19,    44,    57,     6,    58,     7,
       8,    45,    46,    47,     9,    48,    49,    10,    50,    11,
      12
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -133
static const yytype_int16 yypact[] =
{
      78,  -133,   -28,   -17,     7,  -133,  -133,     4,  -133,  -133,
      78,  -133,    12,    48,    10,    55,  -133,  -133,  -133,  -133,
      47,    71,  -133,    61,  -133,  -133,    53,    -2,  -133,  -133,
      49,    49,  -133,     5,    90,    92,   101,   105,    17,   106,
    -133,  -133,    94,  -133,  -133,    61,  -133,  -133,  -133,  -133,
     109,   112,  -133,  -133,   110,    80,   108,  -133,   128,   125,
      15,     5,     5,    17,  -133,   132,   122,    62,  -133,  -133,
     102,  -133,  -133,  -133,  -133,  -133,  -133,  -133,     5,     5,
    -133,  -133,     5,    58,   103,  -133,     5,  -133,  -133,   118,
       5,   104,    -2,    49,   107,  -133,    15,  -133,   100,    11,
     102,  -133,  -133,    15,    15,    15,    15,     5,     5,    15,
      15,    15,    15,    15,    15,    30,    39,   123,   137,  -133,
    -133,   139,  -133,   141,    -2,  -133,   140,  -133,  -133,    -2,
    -133,  -133,  -133,   122,   122,   122,   122,    62,    62,  -133,
    -133,  -133,  -133,  -133,  -133,   142,   143,     5,  -133,  -133,
    -133,   133,   130,  -133,    61,    61,  -133,   144,    -2,   145,
     146,     5,  -133,   126,  -133,   147,   149,  -133,    61,   150,
    -133
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -133,   -89,   160,  -133,   -27,   -54,   -47,  -133,  -133,   -32,
     -23,  -133,   -21,   -19,   111,  -133,  -133,  -133,  -133,  -133,
    -132,  -133,  -133,  -133,  -133,     8,   -26,  -133,  -133,  -133,
    -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,   -44,   154,
    -133
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      39,    87,    40,   127,    41,    59,    65,    98,     5,    60,
      13,    22,    25,    61,    99,   156,    23,    28,     5,    60,
     132,    20,    39,    96,    40,    82,    41,    83,    97,   165,
     100,   115,   116,    62,    52,   151,    53,   107,   108,   145,
     153,    84,    98,    63,    64,    21,   100,   100,   146,   133,
     134,   135,   136,    63,    64,    30,   107,   108,    26,   123,
     137,   138,    29,   125,   130,   107,   108,   128,    32,   162,
      27,   130,   130,   130,   130,   100,   100,   139,   140,   141,
     142,   143,   144,    31,     2,     1,    33,    55,   107,   108,
      91,    34,    51,    35,    36,    37,   119,   120,    78,    38,
      79,     2,    92,   103,   104,   105,   106,     3,    80,   131,
     159,   160,    81,    85,    86,     4,   109,   110,   111,   112,
     113,   114,    88,    89,   169,   103,   104,   105,   106,    93,
      90,    39,    39,    40,    40,    41,    41,    94,    95,   102,
     124,   122,   129,   126,   147,    39,   148,    40,   150,    41,
     149,   152,   158,   157,   154,   155,   161,   166,   163,   164,
     167,   168,    14,   170,    24,     0,     0,     0,     0,     0,
       0,     0,     0,   101
};

static const yytype_int16 yycheck[] =
{
      23,    45,    23,    92,    23,    31,    33,    61,     0,     4,
      38,     7,     0,     8,    61,   147,    12,     7,    10,     4,
       9,    38,    45,     8,    45,     8,    45,    10,    60,   161,
      62,    78,    79,    28,    36,   124,    38,    26,    27,     9,
     129,    24,    96,    38,    39,    38,    78,    79,     9,   103,
     104,   105,   106,    38,    39,     8,    26,    27,    10,    86,
     107,   108,     7,    90,    96,    26,    27,    93,     7,   158,
      22,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,    12,    23,     7,    25,    38,    26,    27,
      10,    30,    39,    32,    33,    34,    38,    39,     8,    38,
       8,    23,    22,     3,     4,     5,     6,    29,     7,     9,
     154,   155,     7,     7,    20,    37,    14,    15,    16,    17,
      18,    19,    13,    11,   168,     3,     4,     5,     6,    21,
      20,   154,   155,   154,   155,   154,   155,     9,    13,     7,
      22,    38,    35,    39,    21,   168,     9,   168,     7,   168,
      11,    11,    22,    20,    12,    12,    12,    31,    13,    13,
      13,    12,     2,    13,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    62
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    23,    29,    37,    65,    67,    69,    70,    74,
      77,    79,    80,    38,    42,    43,    61,    62,    63,    64,
      38,    38,     7,    12,    79,     0,    10,    22,     7,     7,
       8,    12,     7,    25,    30,    32,    33,    34,    38,    50,
      52,    53,    58,    59,    65,    71,    72,    73,    75,    76,
      78,    39,    36,    38,    41,    38,    42,    66,    68,    66,
       4,     8,    28,    38,    39,    44,    45,    46,    47,    48,
      49,    50,    52,    53,    54,    55,    56,    57,     8,     8,
       7,     7,     8,    10,    24,     7,    20,    78,    13,    11,
      20,    10,    22,    21,     9,    13,     8,    49,    45,    46,
      49,    54,     7,     3,     4,     5,     6,    26,    27,    14,
      15,    16,    17,    18,    19,    46,    46,    44,    60,    38,
      39,    51,    38,    44,    22,    44,    39,    41,    66,    35,
      49,     9,     9,    45,    45,    45,    45,    46,    46,    49,
      49,    49,    49,    49,    49,     9,     9,    21,     9,    11,
       7,    41,    11,    41,    12,    12,    60,    20,    22,    78,
      78,    12,    41,    13,    13,    60,    31,    13,    12,    78,
      13
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 155 "parser.yacc"
    {
  (yyval.type) = A_NativeType((yyvsp[(1) - (1)].pos),A_intTypeKind);
}
    break;

  case 3:
#line 159 "parser.yacc"
    {
  (yyval.type) = A_StructType((yyvsp[(1) - (1)].tokenId)->pos,(yyvsp[(1) - (1)].tokenId)->id);
}
    break;

  case 4:
#line 167 "parser.yacc"
    {
  (yyval.varDecl) = A_VarDecl_Scalar((yyvsp[(1) - (1)].varDeclScalar)->pos,(yyvsp[(1) - (1)].varDeclScalar));
}
    break;

  case 5:
#line 171 "parser.yacc"
    {
  (yyval.varDecl) = A_VarDecl_Array((yyvsp[(1) - (1)].varDeclArray)->pos,(yyvsp[(1) - (1)].varDeclArray));
}
    break;

  case 6:
#line 180 "parser.yacc"
    {
  (yyval.varDef) = A_VarDef_Scalar((yyvsp[(1) - (1)].varDefScalar)->pos,(yyvsp[(1) - (1)].varDefScalar));
}
    break;

  case 7:
#line 184 "parser.yacc"
    {
  (yyval.varDef) = A_VarDef_Array((yyvsp[(1) - (1)].varDefArray)->pos,(yyvsp[(1) - (1)].varDefArray));
}
    break;

  case 8:
#line 192 "parser.yacc"
    {
  (yyval.rightVal) = A_ArithExprRVal((yyvsp[(1) - (1)].arithExpr)->pos,(yyvsp[(1) - (1)].arithExpr));
}
    break;

  case 9:
#line 196 "parser.yacc"
    {
  (yyval.rightVal) = A_BoolExprRVal((yyvsp[(1) - (1)].boolExpr)->pos,(yyvsp[(1) - (1)].boolExpr));
}
    break;

  case 10:
#line 204 "parser.yacc"
    {
  (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[(1) - (1)].arithBiOpExpr)->pos,(yyvsp[(1) - (1)].arithBiOpExpr));
}
    break;

  case 11:
#line 208 "parser.yacc"
    {
  (yyval.arithExpr) = A_ExprUnit((yyvsp[(1) - (1)].exprUnit)->pos,(yyvsp[(1) - (1)].exprUnit));
}
    break;

  case 12:
#line 216 "parser.yacc"
    {
  (yyval.boolExpr) = A_BoolBiOp_Expr((yyvsp[(1) - (1)].boolBiOpExpr)->pos,(yyvsp[(1) - (1)].boolBiOpExpr));
}
    break;

  case 13:
#line 220 "parser.yacc"
    {
  (yyval.boolExpr) = A_BoolExpr((yyvsp[(1) - (1)].boolUnit)->pos,(yyvsp[(1) - (1)].boolUnit));
}
    break;

  case 14:
#line 227 "parser.yacc"
    {
  (yyval.arithBiOpExpr) = A_ArithBiOpExpr((yyvsp[(1) - (3)].arithExpr)->pos,A_add,(yyvsp[(1) - (3)].arithExpr),(yyvsp[(3) - (3)].arithExpr));
}
    break;

  case 15:
#line 231 "parser.yacc"
    {
  (yyval.arithBiOpExpr) = A_ArithBiOpExpr((yyvsp[(1) - (3)].arithExpr)->pos,A_sub,(yyvsp[(1) - (3)].arithExpr),(yyvsp[(3) - (3)].arithExpr));
}
    break;

  case 16:
#line 235 "parser.yacc"
    {
  (yyval.arithBiOpExpr) = A_ArithBiOpExpr((yyvsp[(1) - (3)].arithExpr)->pos,A_mul,(yyvsp[(1) - (3)].arithExpr),(yyvsp[(3) - (3)].arithExpr));
}
    break;

  case 17:
#line 239 "parser.yacc"
    {
  (yyval.arithBiOpExpr) = A_ArithBiOpExpr((yyvsp[(1) - (3)].arithExpr)->pos,A_div,(yyvsp[(1) - (3)].arithExpr),(yyvsp[(3) - (3)].arithExpr));
}
    break;

  case 18:
#line 246 "parser.yacc"
    {
  (yyval.arithUExpr) = A_ArithUExpr((yyvsp[(1) - (2)].pos),A_neg,(yyvsp[(2) - (2)].exprUnit));
}
    break;

  case 19:
#line 259 "parser.yacc"
    {
  (yyval.exprUnit) = A_NumExprUnit((yyvsp[(1) - (1)].tokenNum)->pos,(yyvsp[(1) - (1)].tokenNum)->num);
}
    break;

  case 20:
#line 263 "parser.yacc"
    {
  (yyval.exprUnit) = A_IdExprUnit((yyvsp[(1) - (1)].tokenId)->pos,(yyvsp[(1) - (1)].tokenId)->id);
}
    break;

  case 21:
#line 267 "parser.yacc"
    { 
  (yyval.exprUnit) = A_ArithExprUnit((yyvsp[(1) - (3)].pos),(yyvsp[(2) - (3)].arithExpr)); //括号是Apos类型
}
    break;

  case 22:
#line 271 "parser.yacc"
    {
  (yyval.exprUnit) = A_CallExprUnit((yyvsp[(1) - (1)].fnCall)->pos,(yyvsp[(1) - (1)].fnCall));
}
    break;

  case 23:
#line 275 "parser.yacc"
    {
  (yyval.exprUnit) = A_ArrayExprUnit((yyvsp[(1) - (1)].arrayExpr)->pos,(yyvsp[(1) - (1)].arrayExpr));
}
    break;

  case 24:
#line 279 "parser.yacc"
    {
  (yyval.exprUnit) = A_MemberExprUnit((yyvsp[(1) - (1)].memberExpr)->pos,(yyvsp[(1) - (1)].memberExpr));
}
    break;

  case 25:
#line 283 "parser.yacc"
    {
  (yyval.exprUnit) = A_ArithUExprUnit((yyvsp[(1) - (1)].arithUExpr)->pos,(yyvsp[(1) - (1)].arithUExpr));
}
    break;

  case 26:
#line 290 "parser.yacc"
    {
  (yyval.fnCall) = A_FnCall((yyvsp[(1) - (4)].tokenId)->pos,(yyvsp[(1) - (4)].tokenId)->id,(yyvsp[(3) - (4)].rightValList));
}
    break;

  case 27:
#line 298 "parser.yacc"
    {
  (yyval.indexExpr) = A_NumIndexExpr((yyvsp[(1) - (1)].tokenNum)->pos,(yyvsp[(1) - (1)].tokenNum)->num);
}
    break;

  case 28:
#line 302 "parser.yacc"
    {
  (yyval.indexExpr) = A_IdIndexExpr((yyvsp[(1) - (1)].tokenId)->pos,(yyvsp[(1) - (1)].tokenId)->id);
}
    break;

  case 29:
#line 309 "parser.yacc"
    {
  (yyval.arrayExpr) = A_ArrayExpr((yyvsp[(1) - (4)].tokenId)->pos,(yyvsp[(1) - (4)].tokenId)->id,(yyvsp[(3) - (4)].indexExpr));
}
    break;

  case 30:
#line 316 "parser.yacc"
    {
  (yyval.memberExpr) = A_MemberExpr((yyvsp[(1) - (3)].tokenId)->pos,(yyvsp[(1) - (3)].tokenId)->id,(yyvsp[(3) - (3)].tokenId)->id);
}
    break;

  case 31:
#line 326 "parser.yacc"
    {
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[(1) - (1)].comExpr)->pos,(yyvsp[(1) - (1)].comExpr));
}
    break;

  case 32:
#line 330 "parser.yacc"
    {
  (yyval.boolUnit) = A_BoolExprUnit((yyvsp[(1) - (3)].pos),(yyvsp[(2) - (3)].boolExpr));
}
    break;

  case 33:
#line 334 "parser.yacc"
    {
  (yyval.boolUnit) = A_BoolUOpExprUnit((yyvsp[(1) - (1)].boolUOpExpr)->pos,(yyvsp[(1) - (1)].boolUOpExpr));
}
    break;

  case 34:
#line 341 "parser.yacc"
    {
  (yyval.boolBiOpExpr) = A_BoolBiOpExpr((yyvsp[(1) - (3)].boolExpr)->pos,A_or,(yyvsp[(1) - (3)].boolExpr),(yyvsp[(3) - (3)].boolExpr));
}
    break;

  case 35:
#line 345 "parser.yacc"
    {
  (yyval.boolBiOpExpr) = A_BoolBiOpExpr((yyvsp[(1) - (3)].boolExpr)->pos,A_and,(yyvsp[(1) - (3)].boolExpr),(yyvsp[(3) - (3)].boolExpr));
}
    break;

  case 36:
#line 352 "parser.yacc"
    {
  (yyval.boolUOpExpr) = A_BoolUOpExpr((yyvsp[(1) - (2)].pos),A_not,(yyvsp[(2) - (2)].boolUnit));
}
    break;

  case 37:
#line 359 "parser.yacc"
    {
  (yyval.comExpr) = A_ComExpr((yyvsp[(1) - (3)].exprUnit)->pos,A_gt,(yyvsp[(1) - (3)].exprUnit),(yyvsp[(3) - (3)].exprUnit));
}
    break;

  case 38:
#line 363 "parser.yacc"
    {
  (yyval.comExpr) = A_ComExpr((yyvsp[(1) - (3)].exprUnit)->pos,A_le,(yyvsp[(1) - (3)].exprUnit),(yyvsp[(3) - (3)].exprUnit));
}
    break;

  case 39:
#line 367 "parser.yacc"
    {
  (yyval.comExpr) = A_ComExpr((yyvsp[(1) - (3)].exprUnit)->pos,A_lt,(yyvsp[(1) - (3)].exprUnit),(yyvsp[(3) - (3)].exprUnit));
}
    break;

  case 40:
#line 371 "parser.yacc"
    {
  (yyval.comExpr) = A_ComExpr((yyvsp[(1) - (3)].exprUnit)->pos,A_ge,(yyvsp[(1) - (3)].exprUnit),(yyvsp[(3) - (3)].exprUnit));
}
    break;

  case 41:
#line 375 "parser.yacc"
    {
  (yyval.comExpr) = A_ComExpr((yyvsp[(1) - (3)].exprUnit)->pos,A_ne,(yyvsp[(1) - (3)].exprUnit),(yyvsp[(3) - (3)].exprUnit));
}
    break;

  case 42:
#line 379 "parser.yacc"
    {
  (yyval.comExpr) = A_ComExpr((yyvsp[(1) - (3)].exprUnit)->pos,A_eq,(yyvsp[(1) - (3)].exprUnit),(yyvsp[(3) - (3)].exprUnit));
}
    break;

  case 43:
#line 388 "parser.yacc"
    {
  (yyval.leftVal) = A_IdExprLVal((yyvsp[(1) - (1)].tokenId)->pos,(yyvsp[(1) - (1)].tokenId)->id);
}
    break;

  case 44:
#line 392 "parser.yacc"
    {
  (yyval.leftVal) = A_ArrExprLVal((yyvsp[(1) - (1)].arrayExpr)->pos,(yyvsp[(1) - (1)].arrayExpr));
}
    break;

  case 45:
#line 396 "parser.yacc"
    {
  (yyval.leftVal) = A_MemberExprLVal((yyvsp[(1) - (1)].memberExpr)->pos,(yyvsp[(1) - (1)].memberExpr));
}
    break;

  case 46:
#line 404 "parser.yacc"
    {
 (yyval.assignStmt) = A_AssignStmt((yyvsp[(1) - (4)].leftVal)->pos,(yyvsp[(1) - (4)].leftVal),(yyvsp[(3) - (4)].rightVal));
}
    break;

  case 47:
#line 411 "parser.yacc"
    {
  (yyval.rightValList) = A_RightValList((yyvsp[(1) - (3)].rightVal),(yyvsp[(3) - (3)].rightValList));
}
    break;

  case 48:
#line 415 "parser.yacc"
    {
  (yyval.rightValList) = A_RightValList((yyvsp[(1) - (1)].rightVal),NULL);
}
    break;

  case 49:
#line 419 "parser.yacc"
    {
  (yyval.rightValList) = NULL;
}
    break;

  case 50:
#line 426 "parser.yacc"
    {
  (yyval.varDefScalar) = A_VarDefScalar((yyvsp[(1) - (5)].tokenId)->pos,(yyvsp[(1) - (5)].tokenId)->id,(yyvsp[(3) - (5)].type),(yyvsp[(5) - (5)].rightVal));
}
    break;

  case 51:
#line 433 "parser.yacc"
    {
  (yyval.varDefArray) = A_VarDefArray((yyvsp[(1) - (10)].tokenId)->pos,(yyvsp[(1) - (10)].tokenId)->id,(yyvsp[(3) - (10)].tokenNum)->num,(yyvsp[(6) - (10)].type),(yyvsp[(9) - (10)].rightValList));
}
    break;

  case 52:
#line 440 "parser.yacc"
    {
  (yyval.varDeclScalar) = A_VarDeclScalar((yyvsp[(1) - (3)].tokenId)->pos,(yyvsp[(1) - (3)].tokenId)->id,(yyvsp[(3) - (3)].type));
}
    break;

  case 53:
#line 447 "parser.yacc"
    {
  (yyval.varDeclArray) = A_VarDeclArray((yyvsp[(1) - (6)].tokenId)->pos,(yyvsp[(1) - (6)].tokenId)->id,(yyvsp[(3) - (6)].tokenNum)->num,(yyvsp[(6) - (6)].type));
}
    break;

  case 54:
#line 457 "parser.yacc"
    {
  (yyval.varDeclStmt) = A_VarDeclStmt((yyvsp[(1) - (3)].pos),(yyvsp[(2) - (3)].varDecl));
}
    break;

  case 55:
#line 461 "parser.yacc"
    {
  (yyval.varDeclStmt) = A_VarDefStmt((yyvsp[(1) - (3)].pos),(yyvsp[(2) - (3)].varDef));
}
    break;

  case 56:
#line 469 "parser.yacc"
    {
  (yyval.varDeclList) = A_VarDeclList((yyvsp[(1) - (3)].varDecl),(yyvsp[(3) - (3)].varDeclList));
}
    break;

  case 57:
#line 473 "parser.yacc"
    {
  (yyval.varDeclList) = A_VarDeclList((yyvsp[(1) - (1)].varDecl),NULL);
}
    break;

  case 58:
#line 477 "parser.yacc"
    {
  (yyval.varDeclList) = NULL;
}
    break;

  case 59:
#line 485 "parser.yacc"
    {
  (yyval.structDef) = A_StructDef((yyvsp[(1) - (5)].pos),(yyvsp[(2) - (5)].tokenId)->id,(yyvsp[(4) - (5)].varDeclList));
}
    break;

  case 60:
#line 492 "parser.yacc"
    {
  (yyval.paramDecl) = A_ParamDecl((yyvsp[(1) - (1)].varDeclList));
}
    break;

  case 61:
#line 500 "parser.yacc"
    {
  (yyval.fnDecl) = A_FnDecl((yyvsp[(1) - (5)].pos),(yyvsp[(2) - (5)].tokenId)->id,(yyvsp[(4) - (5)].paramDecl),NULL);
}
    break;

  case 62:
#line 504 "parser.yacc"
    {
  (yyval.fnDecl) = A_FnDecl((yyvsp[(1) - (7)].pos),(yyvsp[(2) - (7)].tokenId)->id,(yyvsp[(4) - (7)].paramDecl),(yyvsp[(7) - (7)].type));
}
    break;

  case 63:
#line 511 "parser.yacc"
    {
  (yyval.fnDef) = A_FnDef((yyvsp[(1) - (4)].fnDecl)->pos,(yyvsp[(1) - (4)].fnDecl),(yyvsp[(3) - (4)].codeBlockStmtList));
}
    break;

  case 64:
#line 526 "parser.yacc"
    {
  (yyval.codeBlockStmt) = A_BlockVarDeclStmt((yyvsp[(1) - (1)].varDeclStmt)->pos,(yyvsp[(1) - (1)].varDeclStmt));
}
    break;

  case 65:
#line 530 "parser.yacc"
    {
  (yyval.codeBlockStmt) = A_BlockAssignStmt((yyvsp[(1) - (1)].assignStmt)->pos,(yyvsp[(1) - (1)].assignStmt));
}
    break;

  case 66:
#line 534 "parser.yacc"
    {
  (yyval.codeBlockStmt) = A_BlockCallStmt((yyvsp[(1) - (1)].callStmt)->pos,(yyvsp[(1) - (1)].callStmt));
}
    break;

  case 67:
#line 538 "parser.yacc"
    {
  (yyval.codeBlockStmt) = A_BlockIfStmt((yyvsp[(1) - (1)].ifStmt)->pos,(yyvsp[(1) - (1)].ifStmt));
}
    break;

  case 68:
#line 542 "parser.yacc"
    {
  (yyval.codeBlockStmt) = A_BlockWhileStmt((yyvsp[(1) - (1)].whileStmt)->pos,(yyvsp[(1) - (1)].whileStmt));
}
    break;

  case 69:
#line 546 "parser.yacc"
    {
  (yyval.codeBlockStmt) = A_BlockReturnStmt((yyvsp[(1) - (1)].returnStmt)->pos,(yyvsp[(1) - (1)].returnStmt));
}
    break;

  case 70:
#line 550 "parser.yacc"
    {
  (yyval.codeBlockStmt) = A_BlockContinueStmt((yyvsp[(1) - (2)].pos));
}
    break;

  case 71:
#line 554 "parser.yacc"
    {
  (yyval.codeBlockStmt) = A_BlockBreakStmt((yyvsp[(1) - (2)].pos));
}
    break;

  case 72:
#line 558 "parser.yacc"
    {
  (yyval.codeBlockStmt) = A_BlockNullStmt((yyvsp[(1) - (1)].pos));
}
    break;

  case 73:
#line 565 "parser.yacc"
    {
  (yyval.ifStmt) = A_IfStmt((yyvsp[(1) - (7)].pos),(yyvsp[(3) - (7)].boolExpr),(yyvsp[(6) - (7)].codeBlockStmtList),NULL);
}
    break;

  case 74:
#line 569 "parser.yacc"
    {
  (yyval.ifStmt) = A_IfStmt((yyvsp[(1) - (11)].pos),(yyvsp[(3) - (11)].boolExpr),(yyvsp[(6) - (11)].codeBlockStmtList),(yyvsp[(10) - (11)].codeBlockStmtList));
}
    break;

  case 75:
#line 577 "parser.yacc"
    {
  (yyval.whileStmt) = A_WhileStmt((yyvsp[(1) - (7)].pos),(yyvsp[(3) - (7)].boolExpr),(yyvsp[(6) - (7)].codeBlockStmtList));
}
    break;

  case 76:
#line 584 "parser.yacc"
    {
  (yyval.fnDeclStmt) = A_FnDeclStmt((yyvsp[(1) - (2)].fnDecl)->pos,(yyvsp[(1) - (2)].fnDecl));
}
    break;

  case 77:
#line 591 "parser.yacc"
    {
  (yyval.callStmt) = A_CallStmt((yyvsp[(1) - (2)].fnCall)->pos,(yyvsp[(1) - (2)].fnCall));
}
    break;

  case 78:
#line 598 "parser.yacc"
    {
  (yyval.returnStmt) = A_ReturnStmt((yyvsp[(1) - (3)].pos),(yyvsp[(2) - (3)].rightVal));
}
    break;

  case 79:
#line 610 "parser.yacc"
    {
  (yyval.programElement) = A_ProgramVarDeclStmt((yyvsp[(1) - (1)].varDeclStmt)->pos, (yyvsp[(1) - (1)].varDeclStmt));
}
    break;

  case 80:
#line 614 "parser.yacc"
    {
  (yyval.programElement) = A_ProgramStructDef((yyvsp[(1) - (1)].structDef)->pos, (yyvsp[(1) - (1)].structDef));
}
    break;

  case 81:
#line 618 "parser.yacc"
    {
  (yyval.programElement) = A_ProgramFnDeclStmt((yyvsp[(1) - (1)].fnDeclStmt)->pos, (yyvsp[(1) - (1)].fnDeclStmt));
}
    break;

  case 82:
#line 622 "parser.yacc"
    {
  (yyval.programElement) = A_ProgramFnDef((yyvsp[(1) - (1)].fnDef)->pos, (yyvsp[(1) - (1)].fnDef));
}
    break;

  case 83:
#line 626 "parser.yacc"
    {
  (yyval.programElement) = A_ProgramNullStmt((yyvsp[(1) - (1)].pos));
}
    break;

  case 84:
#line 634 "parser.yacc"
    {
  (yyval.codeBlockStmtList) = A_CodeBlockStmtList((yyvsp[(1) - (2)].codeBlockStmt),(yyvsp[(2) - (2)].codeBlockStmtList));
}
    break;

  case 85:
#line 638 "parser.yacc"
    {
  (yyval.codeBlockStmtList) = A_CodeBlockStmtList((yyvsp[(1) - (1)].codeBlockStmt),NULL);
}
    break;

  case 86:
#line 645 "parser.yacc"
    {
  (yyval.programElementList) = A_ProgramElementList((yyvsp[(1) - (2)].programElement),(yyvsp[(2) - (2)].programElementList));
}
    break;

  case 87:
#line 649 "parser.yacc"
    {
  (yyval.programElementList) = NULL;
}
    break;

  case 88:
#line 657 "parser.yacc"
    {  
  root = A_Program((yyvsp[(1) - (1)].programElementList));
  (yyval.program) = A_Program((yyvsp[(1) - (1)].programElementList));
}
    break;


/* Line 1267 of yacc.c.  */
#line 2210 "y.tab.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 663 "parser.yacc"


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



