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

/* "%code top" blocks.  */
#line 2 "src/parser.y"

    #include <iostream>
    #include <assert.h>
    #include "parser.h"
    extern Ast ast;
    int yylex();
    int yyerror( char const * );

#line 77 "src/parser.cpp"




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

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_INTEGER = 4,                    /* INTEGER  */
  YYSYMBOL_IF = 5,                         /* IF  */
  YYSYMBOL_ELSE = 6,                       /* ELSE  */
  YYSYMBOL_WHILE = 7,                      /* WHILE  */
  YYSYMBOL_RETURN = 8,                     /* RETURN  */
  YYSYMBOL_BREAK = 9,                      /* BREAK  */
  YYSYMBOL_CONTINUE = 10,                  /* CONTINUE  */
  YYSYMBOL_INT = 11,                       /* INT  */
  YYSYMBOL_VOID = 12,                      /* VOID  */
  YYSYMBOL_LPAREN = 13,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 14,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 15,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 16,                    /* RBRACE  */
  YYSYMBOL_SEMICOLON = 17,                 /* SEMICOLON  */
  YYSYMBOL_LBRACKET = 18,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 19,                  /* RBRACKET  */
  YYSYMBOL_COMMA = 20,                     /* COMMA  */
  YYSYMBOL_ADD = 21,                       /* ADD  */
  YYSYMBOL_SUB = 22,                       /* SUB  */
  YYSYMBOL_MUL = 23,                       /* MUL  */
  YYSYMBOL_DIV = 24,                       /* DIV  */
  YYSYMBOL_MOD = 25,                       /* MOD  */
  YYSYMBOL_OR = 26,                        /* OR  */
  YYSYMBOL_AND = 27,                       /* AND  */
  YYSYMBOL_LESS = 28,                      /* LESS  */
  YYSYMBOL_LESSEQUAL = 29,                 /* LESSEQUAL  */
  YYSYMBOL_GREATER = 30,                   /* GREATER  */
  YYSYMBOL_GREATEREQUAL = 31,              /* GREATEREQUAL  */
  YYSYMBOL_ASSIGN = 32,                    /* ASSIGN  */
  YYSYMBOL_EQUAL = 33,                     /* EQUAL  */
  YYSYMBOL_NOTEQUAL = 34,                  /* NOTEQUAL  */
  YYSYMBOL_NOT = 35,                       /* NOT  */
  YYSYMBOL_CONST = 36,                     /* CONST  */
  YYSYMBOL_THEN = 37,                      /* THEN  */
  YYSYMBOL_YYACCEPT = 38,                  /* $accept  */
  YYSYMBOL_Program = 39,                   /* Program  */
  YYSYMBOL_Type = 40,                      /* Type  */
  YYSYMBOL_Stmts = 41,                     /* Stmts  */
  YYSYMBOL_Stmt = 42,                      /* Stmt  */
  YYSYMBOL_LVal = 43,                      /* LVal  */
  YYSYMBOL_ExprStmt = 44,                  /* ExprStmt  */
  YYSYMBOL_AssignStmt = 45,                /* AssignStmt  */
  YYSYMBOL_BlockStmt = 46,                 /* BlockStmt  */
  YYSYMBOL_47_1 = 47,                      /* $@1  */
  YYSYMBOL_IfStmt = 48,                    /* IfStmt  */
  YYSYMBOL_WhileStmt = 49,                 /* WhileStmt  */
  YYSYMBOL_BreakStmt = 50,                 /* BreakStmt  */
  YYSYMBOL_ContinueStmt = 51,              /* ContinueStmt  */
  YYSYMBOL_ReturnStmt = 52,                /* ReturnStmt  */
  YYSYMBOL_EmptyStmt = 53,                 /* EmptyStmt  */
  YYSYMBOL_Exp = 54,                       /* Exp  */
  YYSYMBOL_Cond = 55,                      /* Cond  */
  YYSYMBOL_AddExp = 56,                    /* AddExp  */
  YYSYMBOL_MulExp = 57,                    /* MulExp  */
  YYSYMBOL_UnaryExp = 58,                  /* UnaryExp  */
  YYSYMBOL_FuncCallExp = 59,               /* FuncCallExp  */
  YYSYMBOL_FuncCallParams = 60,            /* FuncCallParams  */
  YYSYMBOL_PrimaryExp = 61,                /* PrimaryExp  */
  YYSYMBOL_LOrExp = 62,                    /* LOrExp  */
  YYSYMBOL_LAndExp = 63,                   /* LAndExp  */
  YYSYMBOL_EqExp = 64,                     /* EqExp  */
  YYSYMBOL_RelExp = 65,                    /* RelExp  */
  YYSYMBOL_DeclStmt = 66,                  /* DeclStmt  */
  YYSYMBOL_VarDefs = 67,                   /* VarDefs  */
  YYSYMBOL_ConstDefs = 68,                 /* ConstDefs  */
  YYSYMBOL_VarDef = 69,                    /* VarDef  */
  YYSYMBOL_ConstDef = 70,                  /* ConstDef  */
  YYSYMBOL_FuncDef = 71,                   /* FuncDef  */
  YYSYMBOL_72_2 = 72,                      /* $@2  */
  YYSYMBOL_73_3 = 73,                      /* $@3  */
  YYSYMBOL_MaybeFuncDefParams = 74,        /* MaybeFuncDefParams  */
  YYSYMBOL_FuncDefParams = 75,             /* FuncDefParams  */
  YYSYMBOL_FuncDefParam = 76               /* FuncDefParam  */
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
#define YYFINAL  53
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   156

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  140

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


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
      35,    36,    37
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    61,    61,    68,    71,    79,    80,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,   100,   119,
     125,   132,   130,   145,   148,   153,   158,   163,   169,   174,
     177,   183,   187,   191,   192,   198,   206,   207,   211,   215,
     223,   225,   231,   237,   243,   247,   259,   273,   275,   282,
     285,   288,   295,   296,   303,   304,   311,   312,   316,   323,
     324,   328,   332,   336,   348,   353,   358,   362,   365,   369,
     373,   380,   391,   402,   405,   402,   432,   433,   436,   440,
     444,   451
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
  "\"end of file\"", "error", "\"invalid token\"", "ID", "INTEGER", "IF",
  "ELSE", "WHILE", "RETURN", "BREAK", "CONTINUE", "INT", "VOID", "LPAREN",
  "RPAREN", "LBRACE", "RBRACE", "SEMICOLON", "LBRACKET", "RBRACKET",
  "COMMA", "ADD", "SUB", "MUL", "DIV", "MOD", "OR", "AND", "LESS",
  "LESSEQUAL", "GREATER", "GREATEREQUAL", "ASSIGN", "EQUAL", "NOTEQUAL",
  "NOT", "CONST", "THEN", "$accept", "Program", "Type", "Stmts", "Stmt",
  "LVal", "ExprStmt", "AssignStmt", "BlockStmt", "$@1", "IfStmt",
  "WhileStmt", "BreakStmt", "ContinueStmt", "ReturnStmt", "EmptyStmt",
  "Exp", "Cond", "AddExp", "MulExp", "UnaryExp", "FuncCallExp",
  "FuncCallParams", "PrimaryExp", "LOrExp", "LAndExp", "EqExp", "RelExp",
  "DeclStmt", "VarDefs", "ConstDefs", "VarDef", "ConstDef", "FuncDef",
  "$@2", "$@3", "MaybeFuncDefParams", "FuncDefParams", "FuncDefParam", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-29)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-74)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     101,    -9,   -29,    -7,     4,    80,     5,     9,   -29,   -29,
      80,    22,   -29,    80,    80,    80,    28,    54,    58,   101,
     -29,    25,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,
     -29,    47,    26,    27,   -29,   -29,   -29,   -29,   -29,   121,
      80,    80,   -29,    60,   -29,   -29,    68,   -29,   101,   -29,
     -29,   -29,    82,   -29,   -11,    -2,   -29,   -29,    80,   -29,
      80,    80,    80,    80,    80,   -29,   -29,    -6,    72,    26,
      62,    64,    29,    15,    75,   -29,   -29,    20,    65,    -1,
     -29,    80,    79,   -29,    93,    81,    27,    27,   -29,   -29,
     -29,   -29,    80,   101,    80,    80,    80,    80,    80,    80,
      80,    80,   101,   -29,    80,   -29,    82,   -29,    28,    88,
     -29,   -29,   -29,    94,    64,    29,    15,    15,    26,    26,
      26,    26,   -29,   -29,   -29,   104,   107,   106,   -29,   101,
      95,   -29,    28,   -29,    80,   113,   -29,   -29,   -29,   -29
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    18,    51,     0,     0,     0,     0,     0,     3,     4,
       0,    21,    29,     0,     0,     0,     0,     0,     0,     2,
       5,    50,    17,     7,     8,     9,    10,    11,    12,    13,
      16,     0,    31,    33,    36,    44,    40,    14,    15,     0,
       0,     0,    50,     0,    26,    27,     0,    30,     0,    41,
      42,    43,     0,     1,    70,     0,    67,     6,     0,    19,
       0,     0,     0,     0,     0,    45,    47,     0,     0,    59,
      32,    52,    54,    56,     0,    28,    49,     0,     0,     0,
      69,     0,     0,    64,     0,     0,    34,    35,    37,    38,
      39,    46,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,     0,    65,     0,    71,    77,    70,
      66,    20,    48,    23,    53,    55,    57,    58,    60,    61,
      62,    63,    25,    72,    68,     0,     0,    76,    79,     0,
      80,    74,     0,    24,     0,     0,    78,    81,    21,    75
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -29,   -29,   -13,    83,   -12,     1,   -29,   -29,    -3,   -29,
     -29,   -29,   -29,   -29,   -29,   -29,    -5,    92,   -28,    14,
      -4,   -29,   -29,   -29,   -29,    44,    45,   -17,   -29,   -29,
     -29,    55,    35,   -29,   -29,   -29,   -29,   -29,    12
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    17,    18,    19,    20,    42,    22,    23,    24,    48,
      25,    26,    27,    28,    29,    30,    31,    68,    32,    33,
      34,    35,    67,    36,    70,    71,    72,    73,    37,    55,
      79,    56,    80,    38,    82,   135,   126,   127,   128
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      43,    21,   -73,    52,    39,    46,    40,    57,    91,    49,
      50,    51,    69,    69,    92,    83,   105,    41,    84,   106,
      21,    81,    44,     1,     2,     3,    45,     4,     5,     6,
       7,     8,     9,    10,    66,    11,   103,    12,    47,     8,
       9,    13,    14,    98,    99,   100,   101,    60,    61,    21,
      62,    63,    64,    85,    53,    15,    16,    58,    88,    89,
      90,    54,    96,    97,    59,    57,    69,    69,    69,    69,
     118,   119,   120,   121,    86,    87,   107,    75,    21,   116,
     117,   113,    76,     1,     2,    78,    93,   112,    94,   102,
     122,    95,   108,    10,    21,   125,   109,   104,   111,   123,
     129,    13,    14,    21,     1,     2,     3,   130,     4,     5,
       6,     7,     8,     9,    10,    15,    11,   133,    12,   125,
      81,   131,    13,    14,     1,     2,   132,   134,   138,   137,
      21,    77,   139,    74,    10,    65,    15,    16,   114,   110,
     115,   124,    13,    14,   136,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    15
};

static const yytype_int16 yycheck[] =
{
       5,     0,    13,    16,    13,    10,    13,    19,    14,    13,
      14,    15,    40,    41,    20,    17,    17,    13,    20,    20,
      19,    32,    17,     3,     4,     5,    17,     7,     8,     9,
      10,    11,    12,    13,    39,    15,    16,    17,    16,    11,
      12,    21,    22,    28,    29,    30,    31,    21,    22,    48,
      23,    24,    25,    58,     0,    35,    36,    32,    62,    63,
      64,     3,    33,    34,    17,    77,    94,    95,    96,    97,
      98,    99,   100,   101,    60,    61,    81,    17,    77,    96,
      97,    93,    14,     3,     4,     3,    14,    92,    26,    14,
     102,    27,    13,    13,    93,   108,     3,    32,    17,   104,
       6,    21,    22,   102,     3,     4,     5,     3,     7,     8,
       9,    10,    11,    12,    13,    35,    15,   129,    17,   132,
      32,    14,    21,    22,     3,     4,    20,    32,    15,   134,
     129,    48,   135,    41,    13,    14,    35,    36,    94,    84,
      95,   106,    21,    22,   132,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     7,     8,     9,    10,    11,    12,
      13,    15,    17,    21,    22,    35,    36,    39,    40,    41,
      42,    43,    44,    45,    46,    48,    49,    50,    51,    52,
      53,    54,    56,    57,    58,    59,    61,    66,    71,    13,
      13,    13,    43,    54,    17,    17,    54,    16,    47,    58,
      58,    58,    40,     0,     3,    67,    69,    42,    32,    17,
      21,    22,    23,    24,    25,    14,    54,    60,    55,    56,
      62,    63,    64,    65,    55,    17,    14,    41,     3,    68,
      70,    32,    72,    17,    20,    54,    57,    57,    58,    58,
      58,    14,    20,    14,    26,    27,    33,    34,    28,    29,
      30,    31,    14,    16,    32,    17,    20,    54,    13,     3,
      69,    17,    54,    42,    63,    64,    65,    65,    56,    56,
      56,    56,    42,    54,    70,    40,    74,    75,    76,     6,
       3,    14,    20,    42,    32,    73,    76,    54,    15,    46
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    41,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    42,    43,    44,
      45,    47,    46,    48,    48,    49,    50,    51,    52,    53,
      53,    54,    55,    56,    56,    56,    57,    57,    57,    57,
      58,    58,    58,    58,    58,    59,    59,    60,    60,    61,
      61,    61,    62,    62,    63,    63,    64,    64,    64,    65,
      65,    65,    65,    65,    66,    66,    67,    67,    68,    68,
      69,    69,    70,    72,    73,    71,    74,    74,    75,    75,
      76,    76
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     0,     4,     5,     7,     5,     2,     2,     3,     1,
       2,     1,     1,     1,     3,     3,     1,     3,     3,     3,
       1,     2,     2,     2,     1,     3,     4,     1,     3,     3,
       1,     1,     1,     3,     1,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     3,     4,     3,     1,     3,     1,
       1,     3,     3,     0,     0,     8,     1,     0,     3,     1,
       2,     4
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
  case 2: /* Program: Stmts  */
#line 61 "src/parser.y"
            {
        ast.setRoot((yyvsp[0].stmttype)); // 设置树根
    }
#line 1244 "src/parser.cpp"
    break;

  case 3: /* Type: INT  */
#line 68 "src/parser.y"
          {
        (yyval.type) = TypeSystem::intType;
    }
#line 1252 "src/parser.cpp"
    break;

  case 4: /* Type: VOID  */
#line 71 "src/parser.y"
           {
        (yyval.type) = TypeSystem::voidType;
    }
#line 1260 "src/parser.cpp"
    break;

  case 5: /* Stmts: Stmt  */
#line 79 "src/parser.y"
           {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1266 "src/parser.cpp"
    break;

  case 6: /* Stmts: Stmts Stmt  */
#line 80 "src/parser.y"
                {
        (yyval.stmttype) = new SeqNode((yyvsp[-1].stmttype), (yyvsp[0].stmttype));
        // SeqNode是一个抽象节点，用于构造一个指向多个语句的节点
        // SeqNode继承自StmtNode，构造函数中可以用子类实参来初始化父类形参
    }
#line 1276 "src/parser.cpp"
    break;

  case 7: /* Stmt: AssignStmt  */
#line 87 "src/parser.y"
                 {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1282 "src/parser.cpp"
    break;

  case 8: /* Stmt: BlockStmt  */
#line 88 "src/parser.y"
                {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1288 "src/parser.cpp"
    break;

  case 9: /* Stmt: IfStmt  */
#line 89 "src/parser.y"
             {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1294 "src/parser.cpp"
    break;

  case 10: /* Stmt: WhileStmt  */
#line 90 "src/parser.y"
                {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1300 "src/parser.cpp"
    break;

  case 11: /* Stmt: BreakStmt  */
#line 91 "src/parser.y"
                {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1306 "src/parser.cpp"
    break;

  case 12: /* Stmt: ContinueStmt  */
#line 92 "src/parser.y"
                   {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1312 "src/parser.cpp"
    break;

  case 13: /* Stmt: ReturnStmt  */
#line 93 "src/parser.y"
                 {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1318 "src/parser.cpp"
    break;

  case 14: /* Stmt: DeclStmt  */
#line 94 "src/parser.y"
               {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1324 "src/parser.cpp"
    break;

  case 15: /* Stmt: FuncDef  */
#line 95 "src/parser.y"
              {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1330 "src/parser.cpp"
    break;

  case 16: /* Stmt: EmptyStmt  */
#line 96 "src/parser.y"
                {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1336 "src/parser.cpp"
    break;

  case 17: /* Stmt: ExprStmt  */
#line 97 "src/parser.y"
               {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1342 "src/parser.cpp"
    break;

  case 18: /* LVal: ID  */
#line 100 "src/parser.y"
         {
        SymbolEntry *se;
        // identifiers为一个符号表项的指针，永远指向当前符号表栈的栈顶
        // 从当前作用域的符号表开始，寻找所有符号表中是否有这个标识符，并返回其地址
        se = identifiers->lookup((yyvsp[0].strtype));
        if(se == nullptr)
        {
            // 如果找不到则报错，说明该标识符未声明
            fprintf(stderr, "identifier \"%s\" is undefined\n", (char*)(yyvsp[0].strtype));
            delete [](char*)(yyvsp[0].strtype);
            assert(se != nullptr);
        }
        // new节点，通过构造函数来设置属性
        // 注意：该NT的属性为Id类型的节点，节点中又包含了符号表项指针这一成员
        (yyval.exprtype) = new Id(se);
        delete [](yyvsp[0].strtype);
    }
#line 1364 "src/parser.cpp"
    break;

  case 19: /* ExprStmt: Exp SEMICOLON  */
#line 119 "src/parser.y"
                    {
        (yyval.stmttype) = new ExprStmt((yyvsp[-1].exprtype));
    }
#line 1372 "src/parser.cpp"
    break;

  case 20: /* AssignStmt: LVal ASSIGN Exp SEMICOLON  */
#line 125 "src/parser.y"
                              {
        (yyval.stmttype) = new AssignStmt((yyvsp[-3].exprtype), (yyvsp[-1].exprtype));// 通过新节点的构造函数来构建父子节点关系
    }
#line 1380 "src/parser.cpp"
    break;

  case 21: /* $@1: %empty  */
#line 132 "src/parser.y"
        {identifiers = new SymbolTable(identifiers);}
#line 1386 "src/parser.cpp"
    break;

  case 22: /* BlockStmt: LBRACE $@1 Stmts RBRACE  */
#line 134 "src/parser.y"
        {
            // 遇到}，当前的块语句结束，删除符号表栈中栈顶的符号表
            (yyval.stmttype) = new CompoundStmt((yyvsp[-1].stmttype)); 
            // 类似于pop出栈的过程
            SymbolTable *temp = identifiers;
            identifiers = identifiers->getPrev();
            delete temp;
        }
#line 1399 "src/parser.cpp"
    break;

  case 23: /* IfStmt: IF LPAREN Cond RPAREN Stmt  */
#line 145 "src/parser.y"
                                            {
        (yyval.stmttype) = new IfStmt((yyvsp[-2].exprtype), (yyvsp[0].stmttype));
    }
#line 1407 "src/parser.cpp"
    break;

  case 24: /* IfStmt: IF LPAREN Cond RPAREN Stmt ELSE Stmt  */
#line 148 "src/parser.y"
                                           {
        (yyval.stmttype) = new IfElseStmt((yyvsp[-4].exprtype), (yyvsp[-2].stmttype), (yyvsp[0].stmttype));
    }
#line 1415 "src/parser.cpp"
    break;

  case 25: /* WhileStmt: WHILE LPAREN Cond RPAREN Stmt  */
#line 153 "src/parser.y"
                                    {
        (yyval.stmttype) = new WhileStmt((yyvsp[-2].exprtype), (yyvsp[0].stmttype));
    }
#line 1423 "src/parser.cpp"
    break;

  case 26: /* BreakStmt: BREAK SEMICOLON  */
#line 158 "src/parser.y"
                      {
        (yyval.stmttype) = new BreakStmt();
    }
#line 1431 "src/parser.cpp"
    break;

  case 27: /* ContinueStmt: CONTINUE SEMICOLON  */
#line 163 "src/parser.y"
                         {
        (yyval.stmttype) = new ContinueStmt();
    }
#line 1439 "src/parser.cpp"
    break;

  case 28: /* ReturnStmt: RETURN Exp SEMICOLON  */
#line 169 "src/parser.y"
                        {
        (yyval.stmttype) = new ReturnStmt((yyvsp[-1].exprtype));
    }
#line 1447 "src/parser.cpp"
    break;

  case 29: /* EmptyStmt: SEMICOLON  */
#line 174 "src/parser.y"
                {
        (yyval.stmttype) = new EmptyStmt();
    }
#line 1455 "src/parser.cpp"
    break;

  case 30: /* EmptyStmt: LBRACE RBRACE  */
#line 177 "src/parser.y"
                    {
        (yyval.stmttype)=new EmptyStmt();
    }
#line 1463 "src/parser.cpp"
    break;

  case 31: /* Exp: AddExp  */
#line 183 "src/parser.y"
           {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1469 "src/parser.cpp"
    break;

  case 32: /* Cond: LOrExp  */
#line 187 "src/parser.y"
           {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1475 "src/parser.cpp"
    break;

  case 33: /* AddExp: MulExp  */
#line 191 "src/parser.y"
             {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1481 "src/parser.cpp"
    break;

  case 34: /* AddExp: AddExp ADD MulExp  */
#line 193 "src/parser.y"
    {
        // 中间变量，方便中间代码使用
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::ADD, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1491 "src/parser.cpp"
    break;

  case 35: /* AddExp: AddExp SUB MulExp  */
#line 199 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::SUB, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1500 "src/parser.cpp"
    break;

  case 36: /* MulExp: UnaryExp  */
#line 206 "src/parser.y"
               {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1506 "src/parser.cpp"
    break;

  case 37: /* MulExp: MulExp MUL UnaryExp  */
#line 207 "src/parser.y"
                          {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::MUL, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1515 "src/parser.cpp"
    break;

  case 38: /* MulExp: MulExp DIV UnaryExp  */
#line 211 "src/parser.y"
                          {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::DIV, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1524 "src/parser.cpp"
    break;

  case 39: /* MulExp: MulExp MOD UnaryExp  */
#line 215 "src/parser.y"
                          {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::MOD, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1533 "src/parser.cpp"
    break;

  case 40: /* UnaryExp: PrimaryExp  */
#line 223 "src/parser.y"
               {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1539 "src/parser.cpp"
    break;

  case 41: /* UnaryExp: ADD UnaryExp  */
#line 226 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new UnaryExpr(se, UnaryExpr::ADD, (yyvsp[0].exprtype));
    }
#line 1548 "src/parser.cpp"
    break;

  case 42: /* UnaryExp: SUB UnaryExp  */
#line 232 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new UnaryExpr(se, UnaryExpr::SUB, (yyvsp[0].exprtype));
    }
#line 1557 "src/parser.cpp"
    break;

  case 43: /* UnaryExp: NOT UnaryExp  */
#line 238 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new UnaryExpr(se, UnaryExpr::NOT, (yyvsp[0].exprtype));
    }
#line 1566 "src/parser.cpp"
    break;

  case 44: /* UnaryExp: FuncCallExp  */
#line 243 "src/parser.y"
                {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1572 "src/parser.cpp"
    break;

  case 45: /* FuncCallExp: ID LPAREN RPAREN  */
#line 247 "src/parser.y"
                       {   // 无参函数表达式  eg: f()
        SymbolEntry* se;
        se = identifiers->lookup((yyvsp[-2].strtype));
        //函数调用前必须要有声明/定义
        if(se == nullptr)
        {
            fprintf(stderr, "function \"%s\" is undefined\n", (char*)(yyvsp[-2].strtype));
            delete [](char*)(yyvsp[-2].strtype);
            assert(se != nullptr);
        }
        (yyval.exprtype) = new FuncCallExp(se);
    }
#line 1589 "src/parser.cpp"
    break;

  case 46: /* FuncCallExp: ID LPAREN FuncCallParams RPAREN  */
#line 259 "src/parser.y"
                                      {   // 含参函数表达式
        SymbolEntry* se;    
        se = identifiers->lookup((yyvsp[-3].strtype));
        if(se == nullptr)
        {
            fprintf(stderr, "function \"%s\" is undefined\n", (char*)(yyvsp[-3].strtype));
            delete [](char*)(yyvsp[-3].strtype);
            assert(se != nullptr);
        }
        (yyval.exprtype) = new FuncCallExp(se, (yyvsp[-1].exprtype));
    }
#line 1605 "src/parser.cpp"
    break;

  case 47: /* FuncCallParams: Exp  */
#line 273 "src/parser.y"
          {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1611 "src/parser.cpp"
    break;

  case 48: /* FuncCallParams: FuncCallParams COMMA Exp  */
#line 275 "src/parser.y"
                               {
        (yyval.exprtype) = (yyvsp[-2].exprtype);
        (yyval.exprtype)->setNext((yyvsp[0].exprtype));// 串联上新的节点
    }
#line 1620 "src/parser.cpp"
    break;

  case 49: /* PrimaryExp: LPAREN Exp RPAREN  */
#line 282 "src/parser.y"
                        {
        (yyval.exprtype) = (yyvsp[-1].exprtype);
    }
#line 1628 "src/parser.cpp"
    break;

  case 50: /* PrimaryExp: LVal  */
#line 285 "src/parser.y"
           {
        (yyval.exprtype) = (yyvsp[0].exprtype);
    }
#line 1636 "src/parser.cpp"
    break;

  case 51: /* PrimaryExp: INTEGER  */
#line 288 "src/parser.y"
              {
        SymbolEntry* se = new ConstantSymbolEntry(TypeSystem::intType, (yyvsp[0].itype));
        (yyval.exprtype) = new Constant(se);
    }
#line 1645 "src/parser.cpp"
    break;

  case 52: /* LOrExp: LAndExp  */
#line 295 "src/parser.y"
              {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1651 "src/parser.cpp"
    break;

  case 53: /* LOrExp: LOrExp OR LAndExp  */
#line 296 "src/parser.y"
                        {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::OR, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1660 "src/parser.cpp"
    break;

  case 54: /* LAndExp: EqExp  */
#line 303 "src/parser.y"
            {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1666 "src/parser.cpp"
    break;

  case 55: /* LAndExp: LAndExp AND EqExp  */
#line 304 "src/parser.y"
                        {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::AND, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1675 "src/parser.cpp"
    break;

  case 56: /* EqExp: RelExp  */
#line 311 "src/parser.y"
             {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1681 "src/parser.cpp"
    break;

  case 57: /* EqExp: EqExp EQUAL RelExp  */
#line 312 "src/parser.y"
                         {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::EQUAL, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1690 "src/parser.cpp"
    break;

  case 58: /* EqExp: EqExp NOTEQUAL RelExp  */
#line 316 "src/parser.y"
                            {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::NOTEQUAL, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1699 "src/parser.cpp"
    break;

  case 59: /* RelExp: AddExp  */
#line 323 "src/parser.y"
             {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1705 "src/parser.cpp"
    break;

  case 60: /* RelExp: RelExp LESS AddExp  */
#line 324 "src/parser.y"
                         {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::LESS, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1714 "src/parser.cpp"
    break;

  case 61: /* RelExp: RelExp LESSEQUAL AddExp  */
#line 328 "src/parser.y"
                              {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::LESSEQUAL, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1723 "src/parser.cpp"
    break;

  case 62: /* RelExp: RelExp GREATER AddExp  */
#line 332 "src/parser.y"
                            {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::GREATER, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1732 "src/parser.cpp"
    break;

  case 63: /* RelExp: RelExp GREATEREQUAL AddExp  */
#line 336 "src/parser.y"
                                 {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::GREATEREQUAL, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1741 "src/parser.cpp"
    break;

  case 64: /* DeclStmt: Type VarDefs SEMICOLON  */
#line 348 "src/parser.y"
                           {
        (yyval.stmttype) = (yyvsp[-1].stmttype);
    }
#line 1749 "src/parser.cpp"
    break;

  case 65: /* DeclStmt: CONST Type ConstDefs SEMICOLON  */
#line 353 "src/parser.y"
                                   {
        (yyval.stmttype) = (yyvsp[-1].stmttype);
    }
#line 1757 "src/parser.cpp"
    break;

  case 66: /* VarDefs: VarDefs COMMA VarDef  */
#line 358 "src/parser.y"
                           {
        (yyval.stmttype) = (yyvsp[-2].stmttype);
        (yyvsp[-2].stmttype)->setNext((yyvsp[0].stmttype)); //参数表的参数通过指针串起来
    }
#line 1766 "src/parser.cpp"
    break;

  case 67: /* VarDefs: VarDef  */
#line 362 "src/parser.y"
             {(yyval.stmttype) = (yyvsp[0].stmttype);}
#line 1772 "src/parser.cpp"
    break;

  case 68: /* ConstDefs: ConstDefs COMMA ConstDef  */
#line 365 "src/parser.y"
                               {
        (yyval.stmttype) = (yyvsp[-2].stmttype);
        (yyvsp[-2].stmttype)->setNext((yyvsp[0].stmttype));// 串连上ConstDef节点
    }
#line 1781 "src/parser.cpp"
    break;

  case 69: /* ConstDefs: ConstDef  */
#line 369 "src/parser.y"
               {(yyval.stmttype) = (yyvsp[0].stmttype);}
#line 1787 "src/parser.cpp"
    break;

  case 70: /* VarDef: ID  */
#line 373 "src/parser.y"
         {   
        SymbolEntry* se;
        se = new IdentifierSymbolEntry(TypeSystem::intType, (yyvsp[0].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[0].strtype), se);
        (yyval.stmttype) = new DeclStmt(new Id(se));
        delete [](yyvsp[0].strtype);
    }
#line 1799 "src/parser.cpp"
    break;

  case 71: /* VarDef: ID ASSIGN Exp  */
#line 380 "src/parser.y"
                    {  // eg: int a,b=1+2;
        SymbolEntry* se;
        se = new IdentifierSymbolEntry(TypeSystem::intType, (yyvsp[-2].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[-2].strtype), se);
        (yyval.stmttype) = new DeclStmt(new Id(se), (yyvsp[0].exprtype));
        delete [](yyvsp[-2].strtype);
    }
#line 1811 "src/parser.cpp"
    break;

  case 72: /* ConstDef: ID ASSIGN Exp  */
#line 391 "src/parser.y"
                    {
        SymbolEntry* se;
        se = new IdentifierSymbolEntry(TypeSystem::constIntType, (yyvsp[-2].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[-2].strtype), se);
        (yyval.stmttype) = new DeclStmt(new Id(se), (yyvsp[0].exprtype));
        delete [](yyvsp[-2].strtype);
    }
#line 1823 "src/parser.cpp"
    break;

  case 73: /* $@2: %empty  */
#line 402 "src/parser.y"
            {
        identifiers = new SymbolTable(identifiers);
    }
#line 1831 "src/parser.cpp"
    break;

  case 74: /* $@3: %empty  */
#line 405 "src/parser.y"
                                     { // MaybeFuncDefParams:用于解决函数声明有无形参的问题
        Type* funcType;
        std::vector<Type*> vec;
        DeclStmt* temp = (DeclStmt*)(yyvsp[-1].stmttype);
        // 不断获取参数类型写入vec
        while(temp){
            vec.push_back(temp->getId()->getSymbolEntry()->getType());
            temp = (DeclStmt*)(temp->getNext());// 利用类的多态性，参数链表串接成链，可以直接遍历
        }
        funcType = new FunctionType((yyvsp[-5].type), vec); // 用函数返回值类型和参数列表类型来构造FunctionType节点
        SymbolEntry* se = new IdentifierSymbolEntry(funcType, (yyvsp[-4].strtype), identifiers->getPrev()->getLevel());
        // 将函数名压入函数作用域以外的符号表中，为了后续调用该函数
        identifiers->getPrev()->install((yyvsp[-4].strtype), se);
    }
#line 1850 "src/parser.cpp"
    break;

  case 75: /* FuncDef: Type ID $@2 LPAREN MaybeFuncDefParams RPAREN $@3 BlockStmt  */
#line 419 "src/parser.y"
              {
        SymbolEntry* se;
        se = identifiers->lookup((yyvsp[-6].strtype));
        assert(se != nullptr);
        (yyval.stmttype) = new FunctionDef(se, (yyvsp[0].stmttype), (DeclStmt*)(yyvsp[-3].stmttype));
        SymbolTable* top = identifiers;
        identifiers = identifiers->getPrev();
        delete top;
        delete [](yyvsp[-6].strtype);
    }
#line 1865 "src/parser.cpp"
    break;

  case 76: /* MaybeFuncDefParams: FuncDefParams  */
#line 432 "src/parser.y"
                    {(yyval.stmttype) = (yyvsp[0].stmttype);}
#line 1871 "src/parser.cpp"
    break;

  case 77: /* MaybeFuncDefParams: %empty  */
#line 433 "src/parser.y"
             {(yyval.stmttype) = nullptr;}
#line 1877 "src/parser.cpp"
    break;

  case 78: /* FuncDefParams: FuncDefParams COMMA FuncDefParam  */
#line 436 "src/parser.y"
                                       {
        (yyval.stmttype) = (yyvsp[-2].stmttype);
        (yyval.stmttype)->setNext((yyvsp[0].stmttype));
    }
#line 1886 "src/parser.cpp"
    break;

  case 79: /* FuncDefParams: FuncDefParam  */
#line 440 "src/parser.y"
                   {(yyval.stmttype) = (yyvsp[0].stmttype);}
#line 1892 "src/parser.cpp"
    break;

  case 80: /* FuncDefParam: Type ID  */
#line 444 "src/parser.y"
              {
        SymbolEntry* se;
        se = new IdentifierSymbolEntry((yyvsp[-1].type), (yyvsp[0].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[0].strtype), se);
        (yyval.stmttype) = new DeclStmt(new Id(se));
        delete [](yyvsp[0].strtype);    
    }
#line 1904 "src/parser.cpp"
    break;

  case 81: /* FuncDefParam: Type ID ASSIGN Exp  */
#line 451 "src/parser.y"
                         {
        SymbolEntry *se;
        se = new IdentifierSymbolEntry((yyvsp[-3].type), (yyvsp[-2].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[-2].strtype), se);
        (yyval.stmttype) = new DeclStmt(new Id(se),(yyvsp[0].exprtype));
        delete [](yyvsp[-2].strtype);
    }
#line 1916 "src/parser.cpp"
    break;


#line 1920 "src/parser.cpp"

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

#line 459 "src/parser.y"


int yyerror(char const* message)
{
    std::cerr<<message<<std::endl;
    return -1;
}
