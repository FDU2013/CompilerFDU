/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
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


#line 86 "y.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "y.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ADD = 3,                        /* ADD  */
  YYSYMBOL_SUB = 4,                        /* SUB  */
  YYSYMBOL_MUL = 5,                        /* MUL  */
  YYSYMBOL_DIV = 6,                        /* DIV  */
  YYSYMBOL_SEMICOLON = 7,                  /* SEMICOLON  */
  YYSYMBOL_LEFT_PARENT = 8,                /* LEFT_PARENT  */
  YYSYMBOL_RIGHT_PARENT = 9,               /* RIGHT_PARENT  */
  YYSYMBOL_LEFT_SQUARE_BRACKET = 10,       /* LEFT_SQUARE_BRACKET  */
  YYSYMBOL_RIGHT_SQUARE_BRACKET = 11,      /* RIGHT_SQUARE_BRACKET  */
  YYSYMBOL_LEFT_BRACE = 12,                /* LEFT_BRACE  */
  YYSYMBOL_RIGHT_BRACE = 13,               /* RIGHT_BRACE  */
  YYSYMBOL_GREATER = 14,                   /* GREATER  */
  YYSYMBOL_NOT_LESS_THEN = 15,             /* NOT_LESS_THEN  */
  YYSYMBOL_LESS = 16,                      /* LESS  */
  YYSYMBOL_NOT_GREATER_THEN = 17,          /* NOT_GREATER_THEN  */
  YYSYMBOL_EQUAL = 18,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 19,                 /* NOT_EQUAL  */
  YYSYMBOL_ASSIGN = 20,                    /* ASSIGN  */
  YYSYMBOL_COMMA = 21,                     /* COMMA  */
  YYSYMBOL_COLON = 22,                     /* COLON  */
  YYSYMBOL_LET = 23,                       /* LET  */
  YYSYMBOL_POINT = 24,                     /* POINT  */
  YYSYMBOL_RETURN = 25,                    /* RETURN  */
  YYSYMBOL_AND = 26,                       /* AND  */
  YYSYMBOL_OR = 27,                        /* OR  */
  YYSYMBOL_NOT = 28,                       /* NOT  */
  YYSYMBOL_FN = 29,                        /* FN  */
  YYSYMBOL_IF = 30,                        /* IF  */
  YYSYMBOL_ELSE = 31,                      /* ELSE  */
  YYSYMBOL_WHILE = 32,                     /* WHILE  */
  YYSYMBOL_BREAK = 33,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 34,                  /* CONTINUE  */
  YYSYMBOL_RIGHT_ARROW = 35,               /* RIGHT_ARROW  */
  YYSYMBOL_INT = 36,                       /* INT  */
  YYSYMBOL_STRUCT = 37,                    /* STRUCT  */
  YYSYMBOL_Id = 38,                        /* Id  */
  YYSYMBOL_Num = 39,                       /* Num  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_Type = 41,                      /* Type  */
  YYSYMBOL_VarDecl = 42,                   /* VarDecl  */
  YYSYMBOL_VarDef = 43,                    /* VarDef  */
  YYSYMBOL_RightVal = 44,                  /* RightVal  */
  YYSYMBOL_ArithExpr = 45,                 /* ArithExpr  */
  YYSYMBOL_BoolExpr = 46,                  /* BoolExpr  */
  YYSYMBOL_ArithBiOpExpr = 47,             /* ArithBiOpExpr  */
  YYSYMBOL_ArithUExpr = 48,                /* ArithUExpr  */
  YYSYMBOL_ExprUnit = 49,                  /* ExprUnit  */
  YYSYMBOL_FnCall = 50,                    /* FnCall  */
  YYSYMBOL_IndexExpr = 51,                 /* IndexExpr  */
  YYSYMBOL_ArrayExpr = 52,                 /* ArrayExpr  */
  YYSYMBOL_MemberExpr = 53,                /* MemberExpr  */
  YYSYMBOL_BoolUnit = 54,                  /* BoolUnit  */
  YYSYMBOL_BoolBiOpExpr = 55,              /* BoolBiOpExpr  */
  YYSYMBOL_BoolUOpExpr = 56,               /* BoolUOpExpr  */
  YYSYMBOL_ComExpr = 57,                   /* ComExpr  */
  YYSYMBOL_LeftVal = 58,                   /* LeftVal  */
  YYSYMBOL_AssignStmt = 59,                /* AssignStmt  */
  YYSYMBOL_RightValList = 60,              /* RightValList  */
  YYSYMBOL_VarDefScalar = 61,              /* VarDefScalar  */
  YYSYMBOL_VarDefArray = 62,               /* VarDefArray  */
  YYSYMBOL_VarDeclScalar = 63,             /* VarDeclScalar  */
  YYSYMBOL_VarDeclArray = 64,              /* VarDeclArray  */
  YYSYMBOL_VarDeclStmt = 65,               /* VarDeclStmt  */
  YYSYMBOL_VarDeclList = 66,               /* VarDeclList  */
  YYSYMBOL_StructDef = 67,                 /* StructDef  */
  YYSYMBOL_ParamDecl = 68,                 /* ParamDecl  */
  YYSYMBOL_FnDecl = 69,                    /* FnDecl  */
  YYSYMBOL_FnDef = 70,                     /* FnDef  */
  YYSYMBOL_CodeBlockStmt = 71,             /* CodeBlockStmt  */
  YYSYMBOL_IfStmt = 72,                    /* IfStmt  */
  YYSYMBOL_WhileStmt = 73,                 /* WhileStmt  */
  YYSYMBOL_FnDeclStmt = 74,                /* FnDeclStmt  */
  YYSYMBOL_CallStmt = 75,                  /* CallStmt  */
  YYSYMBOL_ReturnStmt = 76,                /* ReturnStmt  */
  YYSYMBOL_ProgramElement = 77,            /* ProgramElement  */
  YYSYMBOL_CodeBlockStmtList = 78,         /* CodeBlockStmtList  */
  YYSYMBOL_ProgramElementList = 79,        /* ProgramElementList  */
  YYSYMBOL_Program = 80                    /* Program  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  25
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   189

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  173

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   158,   158,   162,   170,   174,   183,   187,   195,   199,
     207,   211,   219,   223,   230,   234,   238,   242,   249,   262,
     266,   270,   274,   278,   282,   286,   293,   301,   305,   312,
     319,   329,   333,   337,   344,   348,   355,   362,   366,   370,
     374,   378,   382,   391,   395,   399,   407,   414,   418,   422,
     429,   436,   443,   450,   460,   464,   472,   476,   480,   488,
     495,   503,   507,   514,   529,   533,   537,   541,   545,   549,
     553,   557,   561,   568,   572,   580,   587,   594,   601,   604,
     617,   621,   625,   629,   633,   642,   646,   653,   657,   664
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ADD", "SUB", "MUL",
  "DIV", "SEMICOLON", "LEFT_PARENT", "RIGHT_PARENT", "LEFT_SQUARE_BRACKET",
  "RIGHT_SQUARE_BRACKET", "LEFT_BRACE", "RIGHT_BRACE", "GREATER",
  "NOT_LESS_THEN", "LESS", "NOT_GREATER_THEN", "EQUAL", "NOT_EQUAL",
  "ASSIGN", "COMMA", "COLON", "LET", "POINT", "RETURN", "AND", "OR", "NOT",
  "FN", "IF", "ELSE", "WHILE", "BREAK", "CONTINUE", "RIGHT_ARROW", "INT",
  "STRUCT", "Id", "Num", "$accept", "Type", "VarDecl", "VarDef",
  "RightVal", "ArithExpr", "BoolExpr", "ArithBiOpExpr", "ArithUExpr",
  "ExprUnit", "FnCall", "IndexExpr", "ArrayExpr", "MemberExpr", "BoolUnit",
  "BoolBiOpExpr", "BoolUOpExpr", "ComExpr", "LeftVal", "AssignStmt",
  "RightValList", "VarDefScalar", "VarDefArray", "VarDeclScalar",
  "VarDeclArray", "VarDeclStmt", "VarDeclList", "StructDef", "ParamDecl",
  "FnDecl", "FnDef", "CodeBlockStmt", "IfStmt", "WhileStmt", "FnDeclStmt",
  "CallStmt", "ReturnStmt", "ProgramElement", "CodeBlockStmtList",
  "ProgramElementList", "Program", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-92)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-46)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      77,   -92,    -2,     0,    28,   -92,   -92,     4,   -92,   -92,
      77,   -92,    14,     7,    35,    87,   -92,   -92,   -92,   -92,
      90,   108,   -92,    63,   -92,   -92,    83,   -26,   -92,   -92,
     110,   110,   -92,    11,   142,   144,   147,   148,   149,   151,
     -92,   -92,    99,   -92,   -92,    63,   -92,   -92,   -92,   -92,
     143,   150,   -92,   -92,   139,    36,   141,   -92,   154,   152,
      29,   -92,    17,    17,    33,   -92,   153,   138,    65,   -92,
     -92,   113,   -92,    -1,    10,   -92,   -92,   -92,   -92,   100,
      17,    17,   -92,   -92,    17,   -92,    24,    17,   126,   -92,
     -92,   145,    17,   127,   -26,   110,   133,   -92,    29,   -92,
     112,    76,   113,   -92,   -92,    29,    29,    29,    29,    17,
      17,    29,    29,    29,    29,    29,    29,    78,    81,   155,
     160,   -92,   -92,   159,   164,   -92,   -26,   -92,   161,   -92,
     -92,   -26,   -92,   -92,   -92,   140,   140,   -92,   -92,    65,
      65,   -92,   -92,   -92,   -92,   -92,   -92,   162,   163,    17,
     -92,   -92,   -92,   157,   156,   -92,    63,    63,   -92,   167,
     -26,   168,   169,    17,   -92,   158,   -92,   170,   172,   -92,
      63,   173,   -92
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      88,    84,     0,     0,     0,    80,    81,     0,    83,    82,
      88,    89,     0,     0,     0,     0,     6,     7,     4,     5,
       0,     0,    76,     0,    87,     1,     0,     0,    54,    55,
      58,    58,    72,     0,     0,     0,     0,     0,    43,     0,
      44,    45,     0,    65,    64,    86,    67,    68,    66,    69,
       0,     0,     2,     3,    52,     0,    57,    60,     0,     0,
       0,    79,     0,     0,    20,    19,     0,     8,     9,    10,
      25,    11,    22,    23,    24,    13,    12,    33,    31,     0,
       0,     0,    71,    70,    49,    77,     0,     0,     0,    85,
      63,     0,     0,     0,     0,    58,    61,    59,     0,    18,
       0,     0,     0,    36,    78,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
       0,    28,    27,     0,     0,    30,     0,    50,     0,    52,
      56,     0,    11,    21,    32,    14,    15,    16,    17,    35,
      34,    37,    40,    39,    38,    42,    41,     0,     0,    49,
      26,    29,    46,    53,     0,    62,     0,     0,    47,     0,
       0,     0,     0,    49,    53,    73,    75,     0,     0,    51,
       0,     0,    74
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -92,   -91,   171,   -92,   -28,   -54,   -49,   -92,   -92,   -33,
     -23,   -92,   -21,   -19,   117,   -92,   -92,   -92,   -17,   -92,
     -38,   -92,   -92,   -92,   -92,    89,   -24,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -44,   175,
     -92
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    54,    56,    15,   119,    67,    68,    69,    70,    71,
      72,   123,    73,    74,    75,    76,    77,    78,    79,    43,
     120,    16,    17,    18,    19,    44,    57,     6,    58,     7,
       8,    45,    46,    47,     9,    48,    49,    10,    50,    11,
      12
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,    89,    40,   129,    41,    66,    42,    59,   100,   -44,
      52,    22,    53,   101,    25,    60,    23,    26,    61,    62,
     -45,    60,    39,   -44,    40,    62,    41,    99,    42,    27,
     102,   117,   118,    60,   -45,   153,    13,    98,    20,    63,
     155,    84,    28,   -43,   100,    63,    93,   102,   102,    64,
      65,   135,   136,   137,   138,    64,    65,   -43,    94,   124,
     139,   140,   121,   122,   127,   132,    21,    64,    65,   164,
      32,   130,   132,   132,   132,   132,   102,   102,   141,   142,
     143,   144,   145,   146,     1,   134,     2,   147,    33,     5,
     148,   109,   110,    34,    29,    35,    36,    37,    30,     5,
       2,    38,   109,   110,   109,   110,     3,   109,   110,    86,
      86,   158,   161,   162,     4,   105,   106,   107,   108,    87,
      31,   133,    51,    88,    88,   167,   171,   111,   112,   113,
     114,   115,   116,    39,    39,    40,    40,    41,    41,    42,
      42,   105,   106,   107,   108,   107,   108,    39,    55,    40,
      80,    41,    81,    42,    82,    83,    90,    84,    85,    92,
     104,    91,    95,    96,   125,    97,   128,   126,   131,   150,
     151,   152,   154,    14,   156,   157,   149,   159,   160,   163,
     103,   165,   166,   169,   170,    24,   172,     0,     0,   168
};

static const yytype_int16 yycheck[] =
{
      23,    45,    23,    94,    23,    33,    23,    31,    62,    10,
      36,     7,    38,    62,     0,     4,    12,    10,     7,     8,
      10,     4,    45,    24,    45,     8,    45,    60,    45,    22,
      63,    80,    81,     4,    24,   126,    38,     8,    38,    28,
     131,     8,     7,    10,    98,    28,    10,    80,    81,    38,
      39,   105,   106,   107,   108,    38,    39,    24,    22,    87,
     109,   110,    38,    39,    92,    98,    38,    38,    39,   160,
       7,    95,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,     7,     9,    23,     9,    25,     0,
       9,    26,    27,    30,     7,    32,    33,    34,     8,    10,
      23,    38,    26,    27,    26,    27,    29,    26,    27,    10,
      10,   149,   156,   157,    37,     3,     4,     5,     6,    20,
      12,     9,    39,    24,    24,   163,   170,    14,    15,    16,
      17,    18,    19,   156,   157,   156,   157,   156,   157,   156,
     157,     3,     4,     5,     6,     5,     6,   170,    38,   170,
       8,   170,     8,   170,     7,     7,    13,     8,     7,    20,
       7,    11,    21,     9,    38,    13,    39,    22,    35,     9,
      11,     7,    11,     2,    12,    12,    21,    20,    22,    12,
      63,    13,    13,    13,    12,    10,    13,    -1,    -1,    31
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,    23,    29,    37,    65,    67,    69,    70,    74,
      77,    79,    80,    38,    42,    43,    61,    62,    63,    64,
      38,    38,     7,    12,    79,     0,    10,    22,     7,     7,
       8,    12,     7,    25,    30,    32,    33,    34,    38,    50,
      52,    53,    58,    59,    65,    71,    72,    73,    75,    76,
      78,    39,    36,    38,    41,    38,    42,    66,    68,    66,
       4,     7,     8,    28,    38,    39,    44,    45,    46,    47,
      48,    49,    50,    52,    53,    54,    55,    56,    57,    58,
       8,     8,     7,     7,     8,     7,    10,    20,    24,    78,
      13,    11,    20,    10,    22,    21,     9,    13,     8,    49,
      45,    46,    49,    54,     7,     3,     4,     5,     6,    26,
      27,    14,    15,    16,    17,    18,    19,    46,    46,    44,
      60,    38,    39,    51,    44,    38,    22,    44,    39,    41,
      66,    35,    49,     9,     9,    45,    45,    45,    45,    46,
      46,    49,    49,    49,    49,    49,    49,     9,     9,    21,
       9,    11,     7,    41,    11,    41,    12,    12,    60,    20,
      22,    78,    78,    12,    41,    13,    13,    60,    31,    13,
      12,    78,    13
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    41,    42,    42,    43,    43,    44,    44,
      45,    45,    46,    46,    47,    47,    47,    47,    48,    49,
      49,    49,    49,    49,    49,    49,    50,    51,    51,    52,
      53,    54,    54,    54,    55,    55,    56,    57,    57,    57,
      57,    57,    57,    58,    58,    58,    59,    60,    60,    60,
      61,    62,    63,    64,    65,    65,    66,    66,    66,    67,
      68,    69,    69,    70,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    72,    72,    73,    74,    75,    76,    76,
      77,    77,    77,    77,    77,    78,    78,    79,    79,    80
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     2,     1,
       1,     3,     1,     1,     1,     1,     4,     1,     1,     4,
       3,     1,     3,     1,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     1,     1,     1,     4,     3,     1,     0,
       5,    10,     3,     6,     3,     3,     3,     1,     0,     5,
       1,     5,     7,     4,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     7,    11,     7,     2,     2,     3,     2,
       1,     1,     1,     1,     1,     2,     1,     2,     0,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Type: INT  */
#line 158 "parser.yacc"
   {
  (yyval.type) = A_NativeType((yyvsp[0].pos),A_intTypeKind);
}
#line 1277 "y.tab.cpp"
    break;

  case 3: /* Type: Id  */
#line 162 "parser.yacc"
  {
  (yyval.type) = A_StructType((yyvsp[0].tokenId)->pos,(yyvsp[0].tokenId)->id);
}
#line 1285 "y.tab.cpp"
    break;

  case 4: /* VarDecl: VarDeclScalar  */
#line 170 "parser.yacc"
             {
  (yyval.varDecl) = A_VarDecl_Scalar((yyvsp[0].varDeclScalar)->pos,(yyvsp[0].varDeclScalar));
}
#line 1293 "y.tab.cpp"
    break;

  case 5: /* VarDecl: VarDeclArray  */
#line 174 "parser.yacc"
            {
  (yyval.varDecl) = A_VarDecl_Array((yyvsp[0].varDeclArray)->pos,(yyvsp[0].varDeclArray));
}
#line 1301 "y.tab.cpp"
    break;

  case 6: /* VarDef: VarDefScalar  */
#line 183 "parser.yacc"
            {
  (yyval.varDef) = A_VarDef_Scalar((yyvsp[0].varDefScalar)->pos,(yyvsp[0].varDefScalar));
}
#line 1309 "y.tab.cpp"
    break;

  case 7: /* VarDef: VarDefArray  */
#line 187 "parser.yacc"
           {
  (yyval.varDef) = A_VarDef_Array((yyvsp[0].varDefArray)->pos,(yyvsp[0].varDefArray));
}
#line 1317 "y.tab.cpp"
    break;

  case 8: /* RightVal: ArithExpr  */
#line 195 "parser.yacc"
         {
  (yyval.rightVal) = A_ArithExprRVal((yyvsp[0].arithExpr)->pos,(yyvsp[0].arithExpr));
}
#line 1325 "y.tab.cpp"
    break;

  case 9: /* RightVal: BoolExpr  */
#line 199 "parser.yacc"
        {
  (yyval.rightVal) = A_BoolExprRVal((yyvsp[0].boolExpr)->pos,(yyvsp[0].boolExpr));
}
#line 1333 "y.tab.cpp"
    break;

  case 10: /* ArithExpr: ArithBiOpExpr  */
#line 207 "parser.yacc"
             {
  (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[0].arithBiOpExpr)->pos,(yyvsp[0].arithBiOpExpr));
}
#line 1341 "y.tab.cpp"
    break;

  case 11: /* ArithExpr: ExprUnit  */
#line 211 "parser.yacc"
        {
  (yyval.arithExpr) = A_ExprUnit((yyvsp[0].exprUnit)->pos,(yyvsp[0].exprUnit));
}
#line 1349 "y.tab.cpp"
    break;

  case 12: /* BoolExpr: BoolBiOpExpr  */
#line 219 "parser.yacc"
            {
  (yyval.boolExpr) = A_BoolBiOp_Expr((yyvsp[0].boolBiOpExpr)->pos,(yyvsp[0].boolBiOpExpr));
}
#line 1357 "y.tab.cpp"
    break;

  case 13: /* BoolExpr: BoolUnit  */
#line 223 "parser.yacc"
        {
  (yyval.boolExpr) = A_BoolExpr((yyvsp[0].boolUnit)->pos,(yyvsp[0].boolUnit));
}
#line 1365 "y.tab.cpp"
    break;

  case 14: /* ArithBiOpExpr: ArithExpr ADD ArithExpr  */
#line 230 "parser.yacc"
                       {
  (yyval.arithBiOpExpr) = A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos,A_add,(yyvsp[-2].arithExpr),(yyvsp[0].arithExpr));
}
#line 1373 "y.tab.cpp"
    break;

  case 15: /* ArithBiOpExpr: ArithExpr SUB ArithExpr  */
#line 234 "parser.yacc"
                       {
  (yyval.arithBiOpExpr) = A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos,A_sub,(yyvsp[-2].arithExpr),(yyvsp[0].arithExpr));
}
#line 1381 "y.tab.cpp"
    break;

  case 16: /* ArithBiOpExpr: ArithExpr MUL ArithExpr  */
#line 238 "parser.yacc"
                       {
  (yyval.arithBiOpExpr) = A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos,A_mul,(yyvsp[-2].arithExpr),(yyvsp[0].arithExpr));
}
#line 1389 "y.tab.cpp"
    break;

  case 17: /* ArithBiOpExpr: ArithExpr DIV ArithExpr  */
#line 242 "parser.yacc"
                       {
  (yyval.arithBiOpExpr) = A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos,A_div,(yyvsp[-2].arithExpr),(yyvsp[0].arithExpr));
}
#line 1397 "y.tab.cpp"
    break;

  case 18: /* ArithUExpr: SUB ExprUnit  */
#line 249 "parser.yacc"
            {
  (yyval.arithUExpr) = A_ArithUExpr((yyvsp[-1].pos),A_neg,(yyvsp[0].exprUnit));
}
#line 1405 "y.tab.cpp"
    break;

  case 19: /* ExprUnit: Num  */
#line 262 "parser.yacc"
   {
  (yyval.exprUnit) = A_NumExprUnit((yyvsp[0].tokenNum)->pos,(yyvsp[0].tokenNum)->num);
}
#line 1413 "y.tab.cpp"
    break;

  case 20: /* ExprUnit: Id  */
#line 266 "parser.yacc"
  {
  (yyval.exprUnit) = A_IdExprUnit((yyvsp[0].tokenId)->pos,(yyvsp[0].tokenId)->id);
}
#line 1421 "y.tab.cpp"
    break;

  case 21: /* ExprUnit: LEFT_PARENT ArithExpr RIGHT_PARENT  */
#line 270 "parser.yacc"
                                   { 
  (yyval.exprUnit) = A_ArithExprUnit((yyvsp[-2].pos),(yyvsp[-1].arithExpr)); //括号是Apos类型
}
#line 1429 "y.tab.cpp"
    break;

  case 22: /* ExprUnit: FnCall  */
#line 274 "parser.yacc"
      {
  (yyval.exprUnit) = A_CallExprUnit((yyvsp[0].fnCall)->pos,(yyvsp[0].fnCall));
}
#line 1437 "y.tab.cpp"
    break;

  case 23: /* ExprUnit: ArrayExpr  */
#line 278 "parser.yacc"
         {
  (yyval.exprUnit) = A_ArrayExprUnit((yyvsp[0].arrayExpr)->pos,(yyvsp[0].arrayExpr));
}
#line 1445 "y.tab.cpp"
    break;

  case 24: /* ExprUnit: MemberExpr  */
#line 282 "parser.yacc"
          {
  (yyval.exprUnit) = A_MemberExprUnit((yyvsp[0].memberExpr)->pos,(yyvsp[0].memberExpr));
}
#line 1453 "y.tab.cpp"
    break;

  case 25: /* ExprUnit: ArithUExpr  */
#line 286 "parser.yacc"
          {
  (yyval.exprUnit) = A_ArithUExprUnit((yyvsp[0].arithUExpr)->pos,(yyvsp[0].arithUExpr));
}
#line 1461 "y.tab.cpp"
    break;

  case 26: /* FnCall: Id LEFT_PARENT RightValList RIGHT_PARENT  */
#line 293 "parser.yacc"
                                        {
  (yyval.fnCall) = A_FnCall((yyvsp[-3].tokenId)->pos,(yyvsp[-3].tokenId)->id,(yyvsp[-1].rightValList));
}
#line 1469 "y.tab.cpp"
    break;

  case 27: /* IndexExpr: Num  */
#line 301 "parser.yacc"
   {
  (yyval.indexExpr) = A_NumIndexExpr((yyvsp[0].tokenNum)->pos,(yyvsp[0].tokenNum)->num);
}
#line 1477 "y.tab.cpp"
    break;

  case 28: /* IndexExpr: Id  */
#line 305 "parser.yacc"
  {
  (yyval.indexExpr) = A_IdIndexExpr((yyvsp[0].tokenId)->pos,(yyvsp[0].tokenId)->id);
}
#line 1485 "y.tab.cpp"
    break;

  case 29: /* ArrayExpr: LeftVal LEFT_SQUARE_BRACKET IndexExpr RIGHT_SQUARE_BRACKET  */
#line 312 "parser.yacc"
                                                          {
  (yyval.arrayExpr) = A_ArrayExpr((yyvsp[-3].leftVal)->pos,(yyvsp[-3].leftVal),(yyvsp[-1].indexExpr));
}
#line 1493 "y.tab.cpp"
    break;

  case 30: /* MemberExpr: LeftVal POINT Id  */
#line 319 "parser.yacc"
                {
  (yyval.memberExpr) = A_MemberExpr((yyvsp[-2].leftVal)->pos,(yyvsp[-2].leftVal),(yyvsp[0].tokenId)->id);
}
#line 1501 "y.tab.cpp"
    break;

  case 31: /* BoolUnit: ComExpr  */
#line 329 "parser.yacc"
       {
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[0].comExpr)->pos,(yyvsp[0].comExpr));
}
#line 1509 "y.tab.cpp"
    break;

  case 32: /* BoolUnit: LEFT_PARENT BoolExpr RIGHT_PARENT  */
#line 333 "parser.yacc"
                                 {
  (yyval.boolUnit) = A_BoolExprUnit((yyvsp[-2].pos),(yyvsp[-1].boolExpr));
}
#line 1517 "y.tab.cpp"
    break;

  case 33: /* BoolUnit: BoolUOpExpr  */
#line 337 "parser.yacc"
           {
  (yyval.boolUnit) = A_BoolUOpExprUnit((yyvsp[0].boolUOpExpr)->pos,(yyvsp[0].boolUOpExpr));
}
#line 1525 "y.tab.cpp"
    break;

  case 34: /* BoolBiOpExpr: BoolExpr OR BoolExpr  */
#line 344 "parser.yacc"
                    {
  (yyval.boolBiOpExpr) = A_BoolBiOpExpr((yyvsp[-2].boolExpr)->pos,A_or,(yyvsp[-2].boolExpr),(yyvsp[0].boolExpr));
}
#line 1533 "y.tab.cpp"
    break;

  case 35: /* BoolBiOpExpr: BoolExpr AND BoolExpr  */
#line 348 "parser.yacc"
                     {
  (yyval.boolBiOpExpr) = A_BoolBiOpExpr((yyvsp[-2].boolExpr)->pos,A_and,(yyvsp[-2].boolExpr),(yyvsp[0].boolExpr));
}
#line 1541 "y.tab.cpp"
    break;

  case 36: /* BoolUOpExpr: NOT BoolUnit  */
#line 355 "parser.yacc"
            {
  (yyval.boolUOpExpr) = A_BoolUOpExpr((yyvsp[-1].pos),A_not,(yyvsp[0].boolUnit));
}
#line 1549 "y.tab.cpp"
    break;

  case 37: /* ComExpr: ExprUnit GREATER ExprUnit  */
#line 362 "parser.yacc"
                         {
  (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos,A_gt,(yyvsp[-2].exprUnit),(yyvsp[0].exprUnit));
}
#line 1557 "y.tab.cpp"
    break;

  case 38: /* ComExpr: ExprUnit NOT_GREATER_THEN ExprUnit  */
#line 366 "parser.yacc"
                                  {
  (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos,A_le,(yyvsp[-2].exprUnit),(yyvsp[0].exprUnit));
}
#line 1565 "y.tab.cpp"
    break;

  case 39: /* ComExpr: ExprUnit LESS ExprUnit  */
#line 370 "parser.yacc"
                      {
  (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos,A_lt,(yyvsp[-2].exprUnit),(yyvsp[0].exprUnit));
}
#line 1573 "y.tab.cpp"
    break;

  case 40: /* ComExpr: ExprUnit NOT_LESS_THEN ExprUnit  */
#line 374 "parser.yacc"
                               {
  (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos,A_ge,(yyvsp[-2].exprUnit),(yyvsp[0].exprUnit));
}
#line 1581 "y.tab.cpp"
    break;

  case 41: /* ComExpr: ExprUnit NOT_EQUAL ExprUnit  */
#line 378 "parser.yacc"
                           {
  (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos,A_ne,(yyvsp[-2].exprUnit),(yyvsp[0].exprUnit));
}
#line 1589 "y.tab.cpp"
    break;

  case 42: /* ComExpr: ExprUnit EQUAL ExprUnit  */
#line 382 "parser.yacc"
                       {
  (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos,A_eq,(yyvsp[-2].exprUnit),(yyvsp[0].exprUnit));
}
#line 1597 "y.tab.cpp"
    break;

  case 43: /* LeftVal: Id  */
#line 391 "parser.yacc"
  {
  (yyval.leftVal) = A_IdExprLVal((yyvsp[0].tokenId)->pos,(yyvsp[0].tokenId)->id);
}
#line 1605 "y.tab.cpp"
    break;

  case 44: /* LeftVal: ArrayExpr  */
#line 395 "parser.yacc"
         {
  (yyval.leftVal) = A_ArrExprLVal((yyvsp[0].arrayExpr)->pos,(yyvsp[0].arrayExpr));
}
#line 1613 "y.tab.cpp"
    break;

  case 45: /* LeftVal: MemberExpr  */
#line 399 "parser.yacc"
          {
  (yyval.leftVal) = A_MemberExprLVal((yyvsp[0].memberExpr)->pos,(yyvsp[0].memberExpr));
}
#line 1621 "y.tab.cpp"
    break;

  case 46: /* AssignStmt: LeftVal ASSIGN RightVal SEMICOLON  */
#line 407 "parser.yacc"
                                 {
 (yyval.assignStmt) = A_AssignStmt((yyvsp[-3].leftVal)->pos,(yyvsp[-3].leftVal),(yyvsp[-1].rightVal));
}
#line 1629 "y.tab.cpp"
    break;

  case 47: /* RightValList: RightVal COMMA RightValList  */
#line 414 "parser.yacc"
                           {
  (yyval.rightValList) = A_RightValList((yyvsp[-2].rightVal),(yyvsp[0].rightValList));
}
#line 1637 "y.tab.cpp"
    break;

  case 48: /* RightValList: RightVal  */
#line 418 "parser.yacc"
        {
  (yyval.rightValList) = A_RightValList((yyvsp[0].rightVal),NULL);
}
#line 1645 "y.tab.cpp"
    break;

  case 49: /* RightValList: %empty  */
#line 422 "parser.yacc"
{
  (yyval.rightValList) = NULL;
}
#line 1653 "y.tab.cpp"
    break;

  case 50: /* VarDefScalar: Id COLON Type ASSIGN RightVal  */
#line 429 "parser.yacc"
                             {
  (yyval.varDefScalar) = A_VarDefScalar((yyvsp[-4].tokenId)->pos,(yyvsp[-4].tokenId)->id,(yyvsp[-2].type),(yyvsp[0].rightVal));
}
#line 1661 "y.tab.cpp"
    break;

  case 51: /* VarDefArray: Id LEFT_SQUARE_BRACKET Num RIGHT_SQUARE_BRACKET COLON Type ASSIGN LEFT_BRACE RightValList RIGHT_BRACE  */
#line 436 "parser.yacc"
                                                                                                     {
  (yyval.varDefArray) = A_VarDefArray((yyvsp[-9].tokenId)->pos,(yyvsp[-9].tokenId)->id,(yyvsp[-7].tokenNum)->num,(yyvsp[-4].type),(yyvsp[-1].rightValList));
}
#line 1669 "y.tab.cpp"
    break;

  case 52: /* VarDeclScalar: Id COLON Type  */
#line 443 "parser.yacc"
             {
  (yyval.varDeclScalar) = A_VarDeclScalar((yyvsp[-2].tokenId)->pos,(yyvsp[-2].tokenId)->id,(yyvsp[0].type));
}
#line 1677 "y.tab.cpp"
    break;

  case 53: /* VarDeclArray: Id LEFT_SQUARE_BRACKET Num RIGHT_SQUARE_BRACKET COLON Type  */
#line 450 "parser.yacc"
                                                          {
  (yyval.varDeclArray) = A_VarDeclArray((yyvsp[-5].tokenId)->pos,(yyvsp[-5].tokenId)->id,(yyvsp[-3].tokenNum)->num,(yyvsp[0].type));
}
#line 1685 "y.tab.cpp"
    break;

  case 54: /* VarDeclStmt: LET VarDecl SEMICOLON  */
#line 460 "parser.yacc"
                     {
  (yyval.varDeclStmt) = A_VarDeclStmt((yyvsp[-2].pos),(yyvsp[-1].varDecl));
}
#line 1693 "y.tab.cpp"
    break;

  case 55: /* VarDeclStmt: LET VarDef SEMICOLON  */
#line 464 "parser.yacc"
                    {
  (yyval.varDeclStmt) = A_VarDefStmt((yyvsp[-2].pos),(yyvsp[-1].varDef));
}
#line 1701 "y.tab.cpp"
    break;

  case 56: /* VarDeclList: VarDecl COMMA VarDeclList  */
#line 472 "parser.yacc"
                         {
  (yyval.varDeclList) = A_VarDeclList((yyvsp[-2].varDecl),(yyvsp[0].varDeclList));
}
#line 1709 "y.tab.cpp"
    break;

  case 57: /* VarDeclList: VarDecl  */
#line 476 "parser.yacc"
       {
  (yyval.varDeclList) = A_VarDeclList((yyvsp[0].varDecl),NULL);
}
#line 1717 "y.tab.cpp"
    break;

  case 58: /* VarDeclList: %empty  */
#line 480 "parser.yacc"
{
  (yyval.varDeclList) = NULL;
}
#line 1725 "y.tab.cpp"
    break;

  case 59: /* StructDef: STRUCT Id LEFT_BRACE VarDeclList RIGHT_BRACE  */
#line 488 "parser.yacc"
                                            {
  (yyval.structDef) = A_StructDef((yyvsp[-4].pos),(yyvsp[-3].tokenId)->id,(yyvsp[-1].varDeclList));
}
#line 1733 "y.tab.cpp"
    break;

  case 60: /* ParamDecl: VarDeclList  */
#line 495 "parser.yacc"
           {
  (yyval.paramDecl) = A_ParamDecl((yyvsp[0].varDeclList));
}
#line 1741 "y.tab.cpp"
    break;

  case 61: /* FnDecl: FN Id LEFT_PARENT ParamDecl RIGHT_PARENT  */
#line 503 "parser.yacc"
                                        {
  (yyval.fnDecl) = A_FnDecl((yyvsp[-4].pos),(yyvsp[-3].tokenId)->id,(yyvsp[-1].paramDecl),NULL);
}
#line 1749 "y.tab.cpp"
    break;

  case 62: /* FnDecl: FN Id LEFT_PARENT ParamDecl RIGHT_PARENT RIGHT_ARROW Type  */
#line 507 "parser.yacc"
                                                         {
  (yyval.fnDecl) = A_FnDecl((yyvsp[-6].pos),(yyvsp[-5].tokenId)->id,(yyvsp[-3].paramDecl),(yyvsp[0].type));
}
#line 1757 "y.tab.cpp"
    break;

  case 63: /* FnDef: FnDecl LEFT_BRACE CodeBlockStmtList RIGHT_BRACE  */
#line 514 "parser.yacc"
                                               {
  (yyval.fnDef) = A_FnDef((yyvsp[-3].fnDecl)->pos,(yyvsp[-3].fnDecl),(yyvsp[-1].codeBlockStmtList));
}
#line 1765 "y.tab.cpp"
    break;

  case 64: /* CodeBlockStmt: VarDeclStmt  */
#line 529 "parser.yacc"
           {
  (yyval.codeBlockStmt) = A_BlockVarDeclStmt((yyvsp[0].varDeclStmt)->pos,(yyvsp[0].varDeclStmt));
}
#line 1773 "y.tab.cpp"
    break;

  case 65: /* CodeBlockStmt: AssignStmt  */
#line 533 "parser.yacc"
          {
  (yyval.codeBlockStmt) = A_BlockAssignStmt((yyvsp[0].assignStmt)->pos,(yyvsp[0].assignStmt));
}
#line 1781 "y.tab.cpp"
    break;

  case 66: /* CodeBlockStmt: CallStmt  */
#line 537 "parser.yacc"
        {
  (yyval.codeBlockStmt) = A_BlockCallStmt((yyvsp[0].callStmt)->pos,(yyvsp[0].callStmt));
}
#line 1789 "y.tab.cpp"
    break;

  case 67: /* CodeBlockStmt: IfStmt  */
#line 541 "parser.yacc"
      {
  (yyval.codeBlockStmt) = A_BlockIfStmt((yyvsp[0].ifStmt)->pos,(yyvsp[0].ifStmt));
}
#line 1797 "y.tab.cpp"
    break;

  case 68: /* CodeBlockStmt: WhileStmt  */
#line 545 "parser.yacc"
         {
  (yyval.codeBlockStmt) = A_BlockWhileStmt((yyvsp[0].whileStmt)->pos,(yyvsp[0].whileStmt));
}
#line 1805 "y.tab.cpp"
    break;

  case 69: /* CodeBlockStmt: ReturnStmt  */
#line 549 "parser.yacc"
          {
  (yyval.codeBlockStmt) = A_BlockReturnStmt((yyvsp[0].returnStmt)->pos,(yyvsp[0].returnStmt));
}
#line 1813 "y.tab.cpp"
    break;

  case 70: /* CodeBlockStmt: CONTINUE SEMICOLON  */
#line 553 "parser.yacc"
                  {
  (yyval.codeBlockStmt) = A_BlockContinueStmt((yyvsp[-1].pos));
}
#line 1821 "y.tab.cpp"
    break;

  case 71: /* CodeBlockStmt: BREAK SEMICOLON  */
#line 557 "parser.yacc"
               {
  (yyval.codeBlockStmt) = A_BlockBreakStmt((yyvsp[-1].pos));
}
#line 1829 "y.tab.cpp"
    break;

  case 72: /* CodeBlockStmt: SEMICOLON  */
#line 561 "parser.yacc"
         {
  (yyval.codeBlockStmt) = A_BlockNullStmt((yyvsp[0].pos));
}
#line 1837 "y.tab.cpp"
    break;

  case 73: /* IfStmt: IF LEFT_PARENT BoolExpr RIGHT_PARENT LEFT_BRACE CodeBlockStmtList RIGHT_BRACE  */
#line 568 "parser.yacc"
                                                                             {
  (yyval.ifStmt) = A_IfStmt((yyvsp[-6].pos),(yyvsp[-4].boolExpr),(yyvsp[-1].codeBlockStmtList),NULL);
}
#line 1845 "y.tab.cpp"
    break;

  case 74: /* IfStmt: IF LEFT_PARENT BoolExpr RIGHT_PARENT LEFT_BRACE CodeBlockStmtList RIGHT_BRACE ELSE LEFT_BRACE CodeBlockStmtList RIGHT_BRACE  */
#line 572 "parser.yacc"
                                                                                                                           {
  (yyval.ifStmt) = A_IfStmt((yyvsp[-10].pos),(yyvsp[-8].boolExpr),(yyvsp[-5].codeBlockStmtList),(yyvsp[-1].codeBlockStmtList));
}
#line 1853 "y.tab.cpp"
    break;

  case 75: /* WhileStmt: WHILE LEFT_PARENT BoolExpr RIGHT_PARENT LEFT_BRACE CodeBlockStmtList RIGHT_BRACE  */
#line 580 "parser.yacc"
                                                                                {
  (yyval.whileStmt) = A_WhileStmt((yyvsp[-6].pos),(yyvsp[-4].boolExpr),(yyvsp[-1].codeBlockStmtList));
}
#line 1861 "y.tab.cpp"
    break;

  case 76: /* FnDeclStmt: FnDecl SEMICOLON  */
#line 587 "parser.yacc"
                {
  (yyval.fnDeclStmt) = A_FnDeclStmt((yyvsp[-1].fnDecl)->pos,(yyvsp[-1].fnDecl));
}
#line 1869 "y.tab.cpp"
    break;

  case 77: /* CallStmt: FnCall SEMICOLON  */
#line 594 "parser.yacc"
                {
  (yyval.callStmt) = A_CallStmt((yyvsp[-1].fnCall)->pos,(yyvsp[-1].fnCall));
}
#line 1877 "y.tab.cpp"
    break;

  case 78: /* ReturnStmt: RETURN RightVal SEMICOLON  */
#line 601 "parser.yacc"
                         {
  (yyval.returnStmt) = A_ReturnStmt((yyvsp[-2].pos),(yyvsp[-1].rightVal));
}
#line 1885 "y.tab.cpp"
    break;

  case 79: /* ReturnStmt: RETURN SEMICOLON  */
#line 605 "parser.yacc"
{
  (yyval.returnStmt) = A_ReturnStmt((yyvsp[-1].pos), NULL);
}
#line 1893 "y.tab.cpp"
    break;

  case 80: /* ProgramElement: VarDeclStmt  */
#line 618 "parser.yacc"
{
  (yyval.programElement) = A_ProgramVarDeclStmt((yyvsp[0].varDeclStmt)->pos, (yyvsp[0].varDeclStmt));
}
#line 1901 "y.tab.cpp"
    break;

  case 81: /* ProgramElement: StructDef  */
#line 622 "parser.yacc"
{
  (yyval.programElement) = A_ProgramStructDef((yyvsp[0].structDef)->pos, (yyvsp[0].structDef));
}
#line 1909 "y.tab.cpp"
    break;

  case 82: /* ProgramElement: FnDeclStmt  */
#line 626 "parser.yacc"
{
  (yyval.programElement) = A_ProgramFnDeclStmt((yyvsp[0].fnDeclStmt)->pos, (yyvsp[0].fnDeclStmt));
}
#line 1917 "y.tab.cpp"
    break;

  case 83: /* ProgramElement: FnDef  */
#line 630 "parser.yacc"
{
  (yyval.programElement) = A_ProgramFnDef((yyvsp[0].fnDef)->pos, (yyvsp[0].fnDef));
}
#line 1925 "y.tab.cpp"
    break;

  case 84: /* ProgramElement: SEMICOLON  */
#line 634 "parser.yacc"
{
  (yyval.programElement) = A_ProgramNullStmt((yyvsp[0].pos));
}
#line 1933 "y.tab.cpp"
    break;

  case 85: /* CodeBlockStmtList: CodeBlockStmt CodeBlockStmtList  */
#line 642 "parser.yacc"
                               {
  (yyval.codeBlockStmtList) = A_CodeBlockStmtList((yyvsp[-1].codeBlockStmt),(yyvsp[0].codeBlockStmtList));
}
#line 1941 "y.tab.cpp"
    break;

  case 86: /* CodeBlockStmtList: CodeBlockStmt  */
#line 646 "parser.yacc"
             {
  (yyval.codeBlockStmtList) = A_CodeBlockStmtList((yyvsp[0].codeBlockStmt),NULL);
}
#line 1949 "y.tab.cpp"
    break;

  case 87: /* ProgramElementList: ProgramElement ProgramElementList  */
#line 653 "parser.yacc"
                                 {
  (yyval.programElementList) = A_ProgramElementList((yyvsp[-1].programElement),(yyvsp[0].programElementList));
}
#line 1957 "y.tab.cpp"
    break;

  case 88: /* ProgramElementList: %empty  */
#line 657 "parser.yacc"
{
  (yyval.programElementList) = NULL;
}
#line 1965 "y.tab.cpp"
    break;

  case 89: /* Program: ProgramElementList  */
#line 665 "parser.yacc"
{  
  root = A_Program((yyvsp[0].programElementList));
  (yyval.program) = A_Program((yyvsp[0].programElementList));
}
#line 1974 "y.tab.cpp"
    break;


#line 1978 "y.tab.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 671 "parser.yacc"


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
