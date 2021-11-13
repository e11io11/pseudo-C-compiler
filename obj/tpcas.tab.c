/* A Bison parser, made by GNU Bison 3.7.5.  */

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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/tpcas.y"

#include "../src/tree.h"
#include <stdio.h>
#include <getopt.h>
int yylex();
int yyerror(char* msg);
extern int lineno;
int treeFlag;

#line 81 "obj/tpcas.tab.c"

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


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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
    DIVSTAR = 258,                 /* DIVSTAR  */
    IDENT = 259,                   /* IDENT  */
    TYPE = 260,                    /* TYPE  */
    VOID = 261,                    /* VOID  */
    WHILE = 262,                   /* WHILE  */
    IF = 263,                      /* IF  */
    RETURN = 264,                  /* RETURN  */
    ELSE = 265,                    /* ELSE  */
    OR = 266,                      /* OR  */
    AND = 267,                     /* AND  */
    EQ = 268,                      /* EQ  */
    ORDER = 269,                   /* ORDER  */
    ADDSUB = 270,                  /* ADDSUB  */
    NUM = 271,                     /* NUM  */
    CHARACTER = 272                /* CHARACTER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 12 "src/tpcas.y"

    Node* node;

#line 149 "obj/tpcas.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);


/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_DIVSTAR = 3,                    /* DIVSTAR  */
  YYSYMBOL_IDENT = 4,                      /* IDENT  */
  YYSYMBOL_TYPE = 5,                       /* TYPE  */
  YYSYMBOL_VOID = 6,                       /* VOID  */
  YYSYMBOL_WHILE = 7,                      /* WHILE  */
  YYSYMBOL_IF = 8,                         /* IF  */
  YYSYMBOL_RETURN = 9,                     /* RETURN  */
  YYSYMBOL_ELSE = 10,                      /* ELSE  */
  YYSYMBOL_OR = 11,                        /* OR  */
  YYSYMBOL_AND = 12,                       /* AND  */
  YYSYMBOL_EQ = 13,                        /* EQ  */
  YYSYMBOL_ORDER = 14,                     /* ORDER  */
  YYSYMBOL_ADDSUB = 15,                    /* ADDSUB  */
  YYSYMBOL_NUM = 16,                       /* NUM  */
  YYSYMBOL_CHARACTER = 17,                 /* CHARACTER  */
  YYSYMBOL_18_ = 18,                       /* ';'  */
  YYSYMBOL_19_ = 19,                       /* ','  */
  YYSYMBOL_20_ = 20,                       /* '('  */
  YYSYMBOL_21_ = 21,                       /* ')'  */
  YYSYMBOL_22_ = 22,                       /* '{'  */
  YYSYMBOL_23_ = 23,                       /* '}'  */
  YYSYMBOL_24_ = 24,                       /* '='  */
  YYSYMBOL_25_ = 25,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 26,                  /* $accept  */
  YYSYMBOL_Prog = 27,                      /* Prog  */
  YYSYMBOL_DeclVars = 28,                  /* DeclVars  */
  YYSYMBOL_Declarateurs = 29,              /* Declarateurs  */
  YYSYMBOL_DeclFoncts = 30,                /* DeclFoncts  */
  YYSYMBOL_DeclFonct = 31,                 /* DeclFonct  */
  YYSYMBOL_EnTeteFonct = 32,               /* EnTeteFonct  */
  YYSYMBOL_Parametres = 33,                /* Parametres  */
  YYSYMBOL_ListTypVar = 34,                /* ListTypVar  */
  YYSYMBOL_Corps = 35,                     /* Corps  */
  YYSYMBOL_SuiteInstr = 36,                /* SuiteInstr  */
  YYSYMBOL_Instr = 37,                     /* Instr  */
  YYSYMBOL_Exp = 38,                       /* Exp  */
  YYSYMBOL_TB = 39,                        /* TB  */
  YYSYMBOL_FB = 40,                        /* FB  */
  YYSYMBOL_M = 41,                         /* M  */
  YYSYMBOL_E = 42,                         /* E  */
  YYSYMBOL_T = 43,                         /* T  */
  YYSYMBOL_F = 44,                         /* F  */
  YYSYMBOL_LValue = 45,                    /* LValue  */
  YYSYMBOL_Arguments = 46,                 /* Arguments  */
  YYSYMBOL_ListExp = 47                    /* ListExp  */
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
typedef yytype_int8 yy_state_t;

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

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   112

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  26
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  51
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  104

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   272


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
       2,     2,     2,    25,     2,     2,     2,     2,     2,     2,
      20,    21,     2,     2,    19,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    18,
       2,    24,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    22,     2,    23,     2,     2,     2,     2,
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
      15,    16,    17
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int8 yyrline[] =
{
       0,    23,    23,    26,    27,    30,    31,    34,    35,    38,
      41,    42,    45,    46,    49,    50,    52,    55,    56,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    69,    70,
      72,    73,    75,    76,    78,    79,    81,    82,    84,    85,
      87,    88,    89,    90,    91,    92,    93,    96,    99,   100,
     103,   104
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
  "\"end of file\"", "error", "\"invalid token\"", "DIVSTAR", "IDENT",
  "TYPE", "VOID", "WHILE", "IF", "RETURN", "ELSE", "OR", "AND", "EQ",
  "ORDER", "ADDSUB", "NUM", "CHARACTER", "';'", "','", "'('", "')'", "'{'",
  "'}'", "'='", "'!'", "$accept", "Prog", "DeclVars", "Declarateurs",
  "DeclFoncts", "DeclFonct", "EnTeteFonct", "Parametres", "ListTypVar",
  "Corps", "SuiteInstr", "Instr", "Exp", "TB", "FB", "M", "E", "T", "F",
  "LValue", "Arguments", "ListExp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,    59,    44,
      40,    41,   123,   125,    61,    33
};
#endif

#define YYPACT_NINF (-47)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -47,    11,    27,   -47,    18,    35,    37,   -47,    31,    29,
      41,    36,    67,   -47,   -47,   -47,    57,   -47,    68,    57,
      29,    69,    71,   -47,    55,    58,   -47,    59,    75,    22,
     -47,   -47,    76,   -47,   -47,    63,    64,    65,     3,   -47,
     -47,   -47,   -47,    62,    83,    21,    21,    21,    70,    21,
     -47,   -47,   -47,    21,    21,    -5,    77,    78,    74,    79,
      89,   -47,   -47,    43,    21,   -47,    82,    80,    81,    -9,
      -7,    21,   -47,    -6,   -47,    21,   -47,    21,    21,    21,
      21,    21,   -47,     6,    84,    21,    60,    60,    85,   -47,
      77,    78,    74,    79,    89,   -47,   -47,   -47,    82,   -47,
      86,   -47,    60,   -47
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     1,     0,     0,     2,     8,     0,     6,
       0,     0,     0,     7,     4,     9,     0,     3,     0,     0,
       0,    18,     0,    12,     0,    13,     5,     0,     0,     0,
      15,    10,     0,    11,     6,    47,     0,     0,     0,    27,
      18,    16,    17,     0,     0,    49,     0,     0,    47,     0,
      43,    44,    25,     0,     0,     0,    29,    31,    33,    35,
      37,    39,    45,     0,     0,    14,    51,     0,    48,     0,
       0,    49,    40,     0,    41,     0,    24,     0,     0,     0,
       0,     0,    26,     0,     0,     0,     0,     0,     0,    42,
      28,    30,    32,    34,    36,    38,    19,    23,    50,    22,
      20,    46,     0,    21
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -47,   -47,    90,   -47,   -47,    91,   -47,    88,   -47,   -47,
      72,   -32,   -37,    20,    26,    30,    19,    25,   -46,   -29,
      28,   -47
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,    10,     6,     7,     8,    24,    25,    15,
      29,    42,    66,    56,    57,    58,    59,    60,    61,    62,
      67,    68
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      43,    55,    75,    72,    75,    75,    75,    48,    74,    69,
      70,     3,    86,    76,    87,    89,    73,    75,    49,    50,
      51,    52,     9,    53,    96,    48,    35,    83,    54,    36,
      37,    38,     4,     5,    43,    95,    49,    50,    51,    11,
      39,    53,    12,     5,    40,    41,    54,    35,    98,    16,
      36,    37,    38,    14,    99,   100,    19,    43,    43,    17,
      18,    39,    22,    23,    35,    40,    82,    36,    37,    38,
     103,    20,    26,    43,    28,    30,    31,    32,    39,    34,
      33,    44,    40,    45,    46,    47,    64,    65,    79,    77,
      71,    78,    81,    75,    80,    90,   102,    13,    93,    88,
      85,    84,    97,    91,    21,    94,   101,    27,    92,     0,
       0,     0,    63
};

static const yytype_int8 yycheck[] =
{
      29,    38,    11,    49,    11,    11,    11,     4,    54,    46,
      47,     0,    21,    18,    21,    21,    53,    11,    15,    16,
      17,    18,     4,    20,    18,     4,     4,    64,    25,     7,
       8,     9,     5,     6,    63,    81,    15,    16,    17,     4,
      18,    20,     5,     6,    22,    23,    25,     4,    85,    20,
       7,     8,     9,    22,    86,    87,    20,    86,    87,    18,
      19,    18,     5,     6,     4,    22,    23,     7,     8,     9,
     102,     4,     4,   102,     5,     4,    21,    19,    18,     4,
      21,     5,    22,    20,    20,    20,    24,     4,    14,    12,
      20,    13,     3,    11,    15,    75,    10,     6,    79,    71,
      19,    21,    18,    77,    14,    80,    21,    19,    78,    -1,
      -1,    -1,    40
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    27,    28,     0,     5,     6,    30,    31,    32,     4,
      29,     4,     5,    31,    22,    35,    20,    18,    19,    20,
       4,    28,     5,     6,    33,    34,     4,    33,     5,    36,
       4,    21,    19,    21,     4,     4,     7,     8,     9,    18,
      22,    23,    37,    45,     5,    20,    20,    20,     4,    15,
      16,    17,    18,    20,    25,    38,    39,    40,    41,    42,
      43,    44,    45,    36,    24,     4,    38,    46,    47,    38,
      38,    20,    44,    38,    44,    11,    18,    12,    13,    14,
      15,     3,    23,    38,    21,    19,    21,    21,    46,    21,
      39,    40,    41,    42,    43,    44,    18,    18,    38,    37,
      37,    21,    10,    37
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    26,    27,    28,    28,    29,    29,    30,    30,    31,
      32,    32,    33,    33,    34,    34,    35,    36,    36,    37,
      37,    37,    37,    37,    37,    37,    37,    37,    38,    38,
      39,    39,    40,    40,    41,    41,    42,    42,    43,    43,
      44,    44,    44,    44,    44,    44,    44,    45,    46,    46,
      47,    47
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     4,     0,     3,     1,     2,     1,     2,
       5,     5,     1,     1,     4,     2,     4,     2,     0,     4,
       5,     7,     5,     5,     3,     2,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       2,     2,     3,     1,     1,     1,     4,     1,     1,     0,
       3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
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
  case 2: /* Prog: DeclVars DeclFoncts  */
#line 23 "src/tpcas.y"
                                            {(yyval.node) = makeNode(Prog); addChild((yyval.node), (yyvsp[-1].node)); addChild((yyval.node), (yyvsp[0].node)); if (treeFlag) printTree((yyval.node));}
#line 1246 "obj/tpcas.tab.c"
    break;

  case 3: /* DeclVars: DeclVars TYPE Declarateurs ';'  */
#line 26 "src/tpcas.y"
                                            {(yyval.node) = makeNode(type); addSibling((yyval.node), (yyvsp[-3].node)); addChild((yyval.node), (yyvsp[-1].node));}
#line 1252 "obj/tpcas.tab.c"
    break;

  case 4: /* DeclVars: %empty  */
#line 27 "src/tpcas.y"
                                            {(yyval.node) = makeNode(epsilon);}
#line 1258 "obj/tpcas.tab.c"
    break;

  case 5: /* Declarateurs: Declarateurs ',' IDENT  */
#line 30 "src/tpcas.y"
                                            {(yyval.node) = (yyvsp[-2].node); addSibling((yyval.node), makeNode(ident));}
#line 1264 "obj/tpcas.tab.c"
    break;

  case 6: /* Declarateurs: IDENT  */
#line 31 "src/tpcas.y"
                                            {(yyval.node) = makeNode(ident);}
#line 1270 "obj/tpcas.tab.c"
    break;

  case 7: /* DeclFoncts: DeclFoncts DeclFonct  */
#line 34 "src/tpcas.y"
                                            {(yyval.node) = (yyvsp[-1].node); addSibling((yyval.node), (yyvsp[0].node));}
#line 1276 "obj/tpcas.tab.c"
    break;

  case 8: /* DeclFoncts: DeclFonct  */
#line 35 "src/tpcas.y"
                                            {(yyval.node) = (yyvsp[0].node);}
#line 1282 "obj/tpcas.tab.c"
    break;

  case 9: /* DeclFonct: EnTeteFonct Corps  */
#line 38 "src/tpcas.y"
                                            {(yyval.node) = (yyvsp[-1].node); addChild((yyval.node), (yyvsp[0].node));}
#line 1288 "obj/tpcas.tab.c"
    break;

  case 10: /* EnTeteFonct: TYPE IDENT '(' Parametres ')'  */
#line 41 "src/tpcas.y"
                                            {(yyval.node) = makeNode(ident); addChild((yyval.node), makeNode(type)); addChild((yyval.node), (yyvsp[-1].node));}
#line 1294 "obj/tpcas.tab.c"
    break;

  case 11: /* EnTeteFonct: VOID IDENT '(' Parametres ')'  */
#line 42 "src/tpcas.y"
                                            {(yyval.node) = makeNode(ident); addChild((yyval.node), makeNode(void_)); addChild((yyval.node), (yyvsp[-1].node));}
#line 1300 "obj/tpcas.tab.c"
    break;

  case 12: /* Parametres: VOID  */
#line 45 "src/tpcas.y"
                                            {(yyval.node) = makeNode(void_);}
#line 1306 "obj/tpcas.tab.c"
    break;

  case 13: /* Parametres: ListTypVar  */
#line 46 "src/tpcas.y"
                                            {(yyval.node) = (yyvsp[0].node);}
#line 1312 "obj/tpcas.tab.c"
    break;

  case 14: /* ListTypVar: ListTypVar ',' TYPE IDENT  */
#line 49 "src/tpcas.y"
                                            {(yyval.node) = makeNode(type); addSibling((yyval.node), (yyvsp[-3].node)); addChild((yyval.node), makeNode(ident));}
#line 1318 "obj/tpcas.tab.c"
    break;

  case 15: /* ListTypVar: TYPE IDENT  */
#line 50 "src/tpcas.y"
                                            {(yyval.node) = makeNode(type); addChild((yyval.node), makeNode(ident));}
#line 1324 "obj/tpcas.tab.c"
    break;

  case 16: /* Corps: '{' DeclVars SuiteInstr '}'  */
#line 52 "src/tpcas.y"
                                            {(yyval.node) = (yyvsp[-2].node); addSibling((yyval.node), (yyvsp[-1].node));}
#line 1330 "obj/tpcas.tab.c"
    break;

  case 17: /* SuiteInstr: SuiteInstr Instr  */
#line 55 "src/tpcas.y"
                                            {(yyval.node) = (yyvsp[-1].node); addSibling((yyval.node), (yyvsp[0].node));}
#line 1336 "obj/tpcas.tab.c"
    break;

  case 18: /* SuiteInstr: %empty  */
#line 56 "src/tpcas.y"
                                            {(yyval.node) = makeNode(epsilon);}
#line 1342 "obj/tpcas.tab.c"
    break;

  case 19: /* Instr: LValue '=' Exp ';'  */
#line 59 "src/tpcas.y"
                                            {(yyval.node) = (yyvsp[-3].node); addChild((yyval.node), (yyvsp[-1].node));}
#line 1348 "obj/tpcas.tab.c"
    break;

  case 20: /* Instr: IF '(' Exp ')' Instr  */
#line 60 "src/tpcas.y"
                                            {(yyval.node) = makeNode(if_); addChild((yyval.node), (yyvsp[-2].node)); addChild((yyval.node), (yyvsp[0].node));}
#line 1354 "obj/tpcas.tab.c"
    break;

  case 21: /* Instr: IF '(' Exp ')' Instr ELSE Instr  */
#line 61 "src/tpcas.y"
                                            {(yyval.node) = makeNode(if_); addChild((yyval.node), (yyvsp[-4].node)); addChild((yyval.node), (yyvsp[-2].node)); addSibling((yyval.node), makeNode(else_)); addChild(((yyval.node)->nextSibling), (yyvsp[0].node));}
#line 1360 "obj/tpcas.tab.c"
    break;

  case 22: /* Instr: WHILE '(' Exp ')' Instr  */
#line 62 "src/tpcas.y"
                                            {(yyval.node) = makeNode(while_); addChild((yyval.node), (yyvsp[-2].node)); addChild((yyval.node), (yyvsp[0].node));}
#line 1366 "obj/tpcas.tab.c"
    break;

  case 23: /* Instr: IDENT '(' Arguments ')' ';'  */
#line 63 "src/tpcas.y"
                                            {(yyval.node) = makeNode(ident); addChild((yyval.node), (yyvsp[-2].node));}
#line 1372 "obj/tpcas.tab.c"
    break;

  case 24: /* Instr: RETURN Exp ';'  */
#line 64 "src/tpcas.y"
                                            {(yyval.node) = makeNode(return_); addChild((yyval.node), (yyvsp[-1].node));}
#line 1378 "obj/tpcas.tab.c"
    break;

  case 25: /* Instr: RETURN ';'  */
#line 65 "src/tpcas.y"
                                            {(yyval.node) = makeNode(return_);}
#line 1384 "obj/tpcas.tab.c"
    break;

  case 26: /* Instr: '{' SuiteInstr '}'  */
#line 66 "src/tpcas.y"
                                            {(yyval.node) = (yyvsp[-1].node);}
#line 1390 "obj/tpcas.tab.c"
    break;

  case 27: /* Instr: ';'  */
#line 67 "src/tpcas.y"
                                            {(yyval.node) = makeNode(epsilon);}
#line 1396 "obj/tpcas.tab.c"
    break;

  case 28: /* Exp: Exp OR TB  */
#line 69 "src/tpcas.y"
                                            {(yyval.node) = makeNode(or); addChild((yyval.node), (yyvsp[-2].node)); addChild((yyval.node), (yyvsp[0].node));}
#line 1402 "obj/tpcas.tab.c"
    break;

  case 29: /* Exp: TB  */
#line 70 "src/tpcas.y"
                                            {(yyval.node) = (yyvsp[0].node);}
#line 1408 "obj/tpcas.tab.c"
    break;

  case 30: /* TB: TB AND FB  */
#line 72 "src/tpcas.y"
                                            {(yyval.node) = makeNode(and); addChild((yyval.node), (yyvsp[-2].node)); addChild((yyval.node), (yyvsp[0].node));}
#line 1414 "obj/tpcas.tab.c"
    break;

  case 31: /* TB: FB  */
#line 73 "src/tpcas.y"
                                            {(yyval.node) = (yyvsp[0].node);}
#line 1420 "obj/tpcas.tab.c"
    break;

  case 32: /* FB: FB EQ M  */
#line 75 "src/tpcas.y"
                                            {(yyval.node) = makeNode(eq); addChild((yyval.node), (yyvsp[-2].node)); addChild((yyval.node), (yyvsp[0].node));}
#line 1426 "obj/tpcas.tab.c"
    break;

  case 33: /* FB: M  */
#line 76 "src/tpcas.y"
                                            {(yyval.node) = (yyvsp[0].node);}
#line 1432 "obj/tpcas.tab.c"
    break;

  case 34: /* M: M ORDER E  */
#line 78 "src/tpcas.y"
                                            {(yyval.node) = makeNode(order); addChild((yyval.node), (yyvsp[-2].node)); addChild((yyval.node), (yyvsp[0].node));}
#line 1438 "obj/tpcas.tab.c"
    break;

  case 35: /* M: E  */
#line 79 "src/tpcas.y"
                                            {(yyval.node) = (yyvsp[0].node);}
#line 1444 "obj/tpcas.tab.c"
    break;

  case 36: /* E: E ADDSUB T  */
#line 81 "src/tpcas.y"
                                            {(yyval.node) = makeNode(addsub); addChild((yyval.node), (yyvsp[-2].node)); addChild((yyval.node), (yyvsp[0].node));}
#line 1450 "obj/tpcas.tab.c"
    break;

  case 37: /* E: T  */
#line 82 "src/tpcas.y"
                                            {(yyval.node) = (yyvsp[0].node);}
#line 1456 "obj/tpcas.tab.c"
    break;

  case 38: /* T: T DIVSTAR F  */
#line 84 "src/tpcas.y"
                                            {(yyval.node) = makeNode(divstar); addChild((yyval.node), (yyvsp[-2].node)); addChild((yyval.node), (yyvsp[0].node));}
#line 1462 "obj/tpcas.tab.c"
    break;

  case 39: /* T: F  */
#line 85 "src/tpcas.y"
                                            {(yyval.node) = (yyvsp[0].node);}
#line 1468 "obj/tpcas.tab.c"
    break;

  case 40: /* F: ADDSUB F  */
#line 87 "src/tpcas.y"
                                            {(yyval.node) = makeNode(addsub); addChild((yyval.node), (yyvsp[0].node));}
#line 1474 "obj/tpcas.tab.c"
    break;

  case 41: /* F: '!' F  */
#line 88 "src/tpcas.y"
                                            {(yyval.node) = (yyvsp[0].node);}
#line 1480 "obj/tpcas.tab.c"
    break;

  case 42: /* F: '(' Exp ')'  */
#line 89 "src/tpcas.y"
                                            {(yyval.node) = (yyvsp[-1].node);}
#line 1486 "obj/tpcas.tab.c"
    break;

  case 43: /* F: NUM  */
#line 90 "src/tpcas.y"
                                            {(yyval.node) = makeNode(num);}
#line 1492 "obj/tpcas.tab.c"
    break;

  case 44: /* F: CHARACTER  */
#line 91 "src/tpcas.y"
                                            {(yyval.node) = makeNode(character);}
#line 1498 "obj/tpcas.tab.c"
    break;

  case 45: /* F: LValue  */
#line 92 "src/tpcas.y"
                                            {(yyval.node) = (yyvsp[0].node);}
#line 1504 "obj/tpcas.tab.c"
    break;

  case 46: /* F: IDENT '(' Arguments ')'  */
#line 93 "src/tpcas.y"
                                            {(yyval.node) = makeNode(ident); addChild((yyval.node), (yyvsp[-1].node));}
#line 1510 "obj/tpcas.tab.c"
    break;

  case 47: /* LValue: IDENT  */
#line 96 "src/tpcas.y"
                                            {(yyval.node) = makeNode(ident);}
#line 1516 "obj/tpcas.tab.c"
    break;

  case 48: /* Arguments: ListExp  */
#line 99 "src/tpcas.y"
                                            {(yyval.node) = (yyvsp[0].node);}
#line 1522 "obj/tpcas.tab.c"
    break;

  case 49: /* Arguments: %empty  */
#line 100 "src/tpcas.y"
                                            {(yyval.node) = makeNode(epsilon);}
#line 1528 "obj/tpcas.tab.c"
    break;

  case 50: /* ListExp: ListExp ',' Exp  */
#line 103 "src/tpcas.y"
                                            {(yyval.node) = (yyvsp[-2].node); addSibling((yyval.node), (yyvsp[0].node));}
#line 1534 "obj/tpcas.tab.c"
    break;

  case 51: /* ListExp: Exp  */
#line 104 "src/tpcas.y"
                                            {(yyval.node) = (yyvsp[0].node);}
#line 1540 "obj/tpcas.tab.c"
    break;


#line 1544 "obj/tpcas.tab.c"

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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
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

#line 106 "src/tpcas.y"



int main(int argc, char** argv) {
    int c;
    static struct option long_options[] = {
        {"tree", no_argument, 0, 't'},
        {"help", no_argument, 0, 'h'},
        {0,0,0,'?'}
    };
    int option_index = 0;

    while (1) {
        c = getopt_long(argc,argv,"th", long_options, &option_index);
        if (c == -1) {
            break;
        }
        switch (c) {
            case 't':
                treeFlag = 1;
                break;
            case 'h':
                printf("Usage: ./tpcas [options] < [target]\nOptions:\n-h --help Print this message and exit.\n-t --tree Print target's abstract tree\n");
                break;
            case '?':
                return 2;
        }
    }

    return yyparse();
}

int yyerror(char* msg) {
    fprintf(stderr, "Error near line %i.\n", lineno);
    return 0;
}
