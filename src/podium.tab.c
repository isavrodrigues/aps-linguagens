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
#line 1 "podium.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "podium_ast.h"
#include "podium_llvm.h"

extern int yylex();
extern int yylineno;
extern char* yytext;
void yyerror(const char* s);

Environment* env;

// LLVM global 
extern LLVMContext* llvm_ctx;

#line 89 "podium.tab.c"

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

#include "podium.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_GREENLIGHT = 3,                 /* GREENLIGHT  */
  YYSYMBOL_CHEQUEREDFLAG = 4,              /* CHEQUEREDFLAG  */
  YYSYMBOL_DRIVER = 5,                     /* DRIVER  */
  YYSYMBOL_TEAM = 6,                       /* TEAM  */
  YYSYMBOL_TYPE_INT = 7,                   /* TYPE_INT  */
  YYSYMBOL_TYPE_BOOL = 8,                  /* TYPE_BOOL  */
  YYSYMBOL_TYPE_LAPTIME = 9,               /* TYPE_LAPTIME  */
  YYSYMBOL_IFPIT = 10,                     /* IFPIT  */
  YYSYMBOL_ELSEPIT = 11,                   /* ELSEPIT  */
  YYSYMBOL_FORLAP = 12,                    /* FORLAP  */
  YYSYMBOL_WHILESC = 13,                   /* WHILESC  */
  YYSYMBOL_PITSTOP = 14,                   /* PITSTOP  */
  YYSYMBOL_PUSHLAP = 15,                   /* PUSHLAP  */
  YYSYMBOL_RADIO = 16,                     /* RADIO  */
  YYSYMBOL_MIN = 17,                       /* MIN  */
  YYSYMBOL_MAX = 18,                       /* MAX  */
  YYSYMBOL_ADDPOINT = 19,                  /* ADDPOINT  */
  YYSYMBOL_EQ = 20,                        /* EQ  */
  YYSYMBOL_NE = 21,                        /* NE  */
  YYSYMBOL_LE = 22,                        /* LE  */
  YYSYMBOL_GE = 23,                        /* GE  */
  YYSYMBOL_AND = 24,                       /* AND  */
  YYSYMBOL_OR = 25,                        /* OR  */
  YYSYMBOL_DOTDOT = 26,                    /* DOTDOT  */
  YYSYMBOL_COLON = 27,                     /* COLON  */
  YYSYMBOL_TRUE = 28,                      /* TRUE  */
  YYSYMBOL_FALSE = 29,                     /* FALSE  */
  YYSYMBOL_IDENTIFIER = 30,                /* IDENTIFIER  */
  YYSYMBOL_STRING = 31,                    /* STRING  */
  YYSYMBOL_NUMBER = 32,                    /* NUMBER  */
  YYSYMBOL_33_ = 33,                       /* '<'  */
  YYSYMBOL_34_ = 34,                       /* '>'  */
  YYSYMBOL_35_ = 35,                       /* '+'  */
  YYSYMBOL_36_ = 36,                       /* '-'  */
  YYSYMBOL_37_ = 37,                       /* '*'  */
  YYSYMBOL_38_ = 38,                       /* '/'  */
  YYSYMBOL_UMINUS = 39,                    /* UMINUS  */
  YYSYMBOL_40_ = 40,                       /* '!'  */
  YYSYMBOL_41_ = 41,                       /* ';'  */
  YYSYMBOL_42_ = 42,                       /* '['  */
  YYSYMBOL_43_ = 43,                       /* ','  */
  YYSYMBOL_44_ = 44,                       /* ']'  */
  YYSYMBOL_45_ = 45,                       /* '='  */
  YYSYMBOL_46_ = 46,                       /* '('  */
  YYSYMBOL_47_ = 47,                       /* ')'  */
  YYSYMBOL_48_ = 48,                       /* '{'  */
  YYSYMBOL_49_ = 49,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 50,                  /* $accept  */
  YYSYMBOL_program = 51,                   /* program  */
  YYSYMBOL_52_1 = 52,                      /* $@1  */
  YYSYMBOL_statement_list = 53,            /* statement_list  */
  YYSYMBOL_statement = 54,                 /* statement  */
  YYSYMBOL_declaration = 55,               /* declaration  */
  YYSYMBOL_driver_decl = 56,               /* driver_decl  */
  YYSYMBOL_team_decl = 57,                 /* team_decl  */
  YYSYMBOL_var_decl = 58,                  /* var_decl  */
  YYSYMBOL_type = 59,                      /* type  */
  YYSYMBOL_assignment = 60,                /* assignment  */
  YYSYMBOL_expression = 61,                /* expression  */
  YYSYMBOL_term = 62,                      /* term  */
  YYSYMBOL_factor = 63,                    /* factor  */
  YYSYMBOL_conditional = 64,               /* conditional  */
  YYSYMBOL_block = 65,                     /* block  */
  YYSYMBOL_66_2 = 66,                      /* $@2  */
  YYSYMBOL_loop = 67,                      /* loop  */
  YYSYMBOL_68_3 = 68,                      /* $@3  */
  YYSYMBOL_command = 69                    /* command  */
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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   322

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  56
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  130

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   288


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
       2,     2,     2,    40,     2,     2,     2,     2,     2,     2,
      46,    47,    37,    35,    43,    36,     2,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    41,
      33,    45,    34,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    44,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,    49,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    39
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    55,    55,    54,    83,    84,    88,    89,    90,    91,
      92,    96,    97,    98,   102,   109,   116,   126,   152,   153,
     154,   158,   170,   174,   178,   182,   186,   190,   194,   198,
     202,   206,   210,   217,   221,   225,   232,   236,   240,   244,
     248,   256,   260,   264,   268,   279,   291,   295,   303,   302,
     314,   313,   335,   342,   346,   350,   359
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
  "\"end of file\"", "error", "\"invalid token\"", "GREENLIGHT",
  "CHEQUEREDFLAG", "DRIVER", "TEAM", "TYPE_INT", "TYPE_BOOL",
  "TYPE_LAPTIME", "IFPIT", "ELSEPIT", "FORLAP", "WHILESC", "PITSTOP",
  "PUSHLAP", "RADIO", "MIN", "MAX", "ADDPOINT", "EQ", "NE", "LE", "GE",
  "AND", "OR", "DOTDOT", "COLON", "TRUE", "FALSE", "IDENTIFIER", "STRING",
  "NUMBER", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "UMINUS", "'!'",
  "';'", "'['", "','", "']'", "'='", "'('", "')'", "'{'", "'}'", "$accept",
  "program", "$@1", "statement_list", "statement", "declaration",
  "driver_decl", "team_decl", "var_decl", "type", "assignment",
  "expression", "term", "factor", "conditional", "block", "$@2", "loop",
  "$@3", "command", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-84)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      17,   -84,     3,   -84,   -84,   212,   -84,    -5,    -4,   -19,
     -18,   -15,   -14,   -12,   -11,   -10,   -16,   -84,   -84,   -84,
     -84,    -2,   -84,   -84,   -84,    -1,     4,     2,    33,    33,
      33,     1,     5,    33,    16,    15,    33,   -84,   -84,   -84,
      23,     8,    10,   -84,   -84,   -84,   -84,   -84,    33,    33,
      33,    66,   -20,   -84,   269,    72,   -84,   -84,   100,    14,
     -84,   -84,   -84,    21,   247,    24,    33,    33,   -84,   -84,
     106,    33,    33,    33,    33,    33,    33,    33,    33,    33,
      33,    12,    33,    33,    33,    12,   -84,    33,    33,   -84,
      38,   213,   230,   -84,   -20,   -20,   -20,   -20,   -20,   -20,
     -20,   -20,   -20,   -20,   -84,    36,   -84,   -84,   134,   -84,
     140,   276,    26,    33,    33,   -84,    12,   -84,   -84,    30,
     168,   174,     0,   -84,    12,   -84,   -84,   -84,   -84,   -84
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     2,     0,     4,     1,     0,     3,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     5,     6,    11,
      12,     0,     7,     8,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    13,    10,    14,
       0,     0,     0,    37,    38,    40,    39,    36,     0,     0,
       0,     0,    22,    33,     0,     0,    53,    54,     0,     0,
      18,    19,    20,    16,     0,     0,     0,     0,    44,    45,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    55,     0,     0,    21,
       0,     0,     0,    41,    25,    26,    29,    30,    31,    32,
      27,    28,    23,    24,    48,    46,    34,    35,     0,    52,
       0,    17,     0,     0,     0,     4,     0,    50,    56,     0,
       0,     0,     0,    47,     0,    15,    42,    43,    49,    51
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -84,   -84,   -84,   -43,   -84,   -84,   -84,   -84,   -84,   -84,
     -84,   -29,   242,   -40,   -84,   -83,   -84,   -84,   -84,   -84
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     5,    17,    18,    19,    20,    21,    63,
      22,    51,    52,    53,    23,   105,   115,    24,   124,    25
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      54,    55,   109,     4,    58,     7,     8,    64,    68,    69,
       9,    35,    10,    11,    12,    13,    14,    82,    83,    15,
       1,    70,    60,    61,    62,    26,    27,    28,    29,    36,
      16,    30,    31,   123,    32,    33,    34,    91,    92,    37,
      38,   129,   106,   107,    40,    39,    59,   116,    56,   128,
      41,    42,    57,    65,    66,   108,    67,    87,   110,   111,
     104,    43,    44,    45,    46,    47,    88,    90,   112,    48,
     119,   125,   122,    49,     0,     0,     0,     0,     0,    50,
       0,     0,     0,     0,   120,   121,    71,    72,    73,    74,
      75,    76,    71,    72,    73,    74,    75,    76,     0,    77,
      78,    79,    80,     0,     0,    77,    78,    79,    80,     0,
       0,     0,     0,    81,     0,     0,     0,     0,     0,    85,
      71,    72,    73,    74,    75,    76,    71,    72,    73,    74,
      75,    76,     0,    77,    78,    79,    80,     0,     0,    77,
      78,    79,    80,     0,     0,     0,     0,    86,     0,     0,
       0,     0,     0,    93,    71,    72,    73,    74,    75,    76,
      71,    72,    73,    74,    75,    76,     0,    77,    78,    79,
      80,     0,     0,    77,    78,    79,    80,     0,     0,     0,
       0,   117,     0,     0,     0,     0,     0,   118,    71,    72,
      73,    74,    75,    76,    71,    72,    73,    74,    75,    76,
       0,    77,    78,    79,    80,     0,     0,    77,    78,    79,
      80,     0,     0,     0,     0,   126,     6,     7,     8,     0,
       0,   127,     9,     0,    10,    11,    12,    13,    14,     0,
       0,    15,     0,    71,    72,    73,    74,    75,    76,     0,
       0,     0,    16,     0,     0,     0,    77,    78,    79,    80,
      71,    72,    73,    74,    75,    76,   113,     0,     0,     0,
       0,     0,     0,    77,    78,    79,    80,    71,    72,    73,
      74,    75,    76,   114,     0,     0,     0,     0,     0,     0,
      77,    78,    79,    80,     0,     0,     0,     0,    89,    71,
      72,    73,    74,    75,    76,    84,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,     0,     0,     0,    77,
      78,    79,    80,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103
};

static const yytype_int8 yycheck[] =
{
      29,    30,    85,     0,    33,     5,     6,    36,    48,    49,
      10,    27,    12,    13,    14,    15,    16,    37,    38,    19,
       3,    50,     7,     8,     9,    30,    30,    46,    46,    45,
      30,    46,    46,   116,    46,    46,    46,    66,    67,    41,
      41,   124,    82,    83,    42,    41,    30,    11,    47,    49,
      17,    18,    47,    30,    46,    84,    46,    43,    87,    88,
      48,    28,    29,    30,    31,    32,    45,    43,    30,    36,
      44,    41,   115,    40,    -1,    -1,    -1,    -1,    -1,    46,
      -1,    -1,    -1,    -1,   113,   114,    20,    21,    22,    23,
      24,    25,    20,    21,    22,    23,    24,    25,    -1,    33,
      34,    35,    36,    -1,    -1,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    47,
      20,    21,    22,    23,    24,    25,    20,    21,    22,    23,
      24,    25,    -1,    33,    34,    35,    36,    -1,    -1,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      -1,    -1,    -1,    47,    20,    21,    22,    23,    24,    25,
      20,    21,    22,    23,    24,    25,    -1,    33,    34,    35,
      36,    -1,    -1,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    -1,    -1,    -1,    47,    20,    21,
      22,    23,    24,    25,    20,    21,    22,    23,    24,    25,
      -1,    33,    34,    35,    36,    -1,    -1,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    47,     4,     5,     6,    -1,
      -1,    47,    10,    -1,    12,    13,    14,    15,    16,    -1,
      -1,    19,    -1,    20,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    33,    34,    35,    36,
      20,    21,    22,    23,    24,    25,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    35,    36,    20,    21,    22,
      23,    24,    25,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    41,    20,
      21,    22,    23,    24,    25,    26,    20,    21,    22,    23,
      24,    25,    33,    34,    35,    36,    -1,    -1,    -1,    33,
      34,    35,    36,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    51,    52,     0,    53,     4,     5,     6,    10,
      12,    13,    14,    15,    16,    19,    30,    54,    55,    56,
      57,    58,    60,    64,    67,    69,    30,    30,    46,    46,
      46,    46,    46,    46,    46,    27,    45,    41,    41,    41,
      42,    17,    18,    28,    29,    30,    31,    32,    36,    40,
      46,    61,    62,    63,    61,    61,    47,    47,    61,    30,
       7,     8,     9,    59,    61,    30,    46,    46,    63,    63,
      61,    20,    21,    22,    23,    24,    25,    33,    34,    35,
      36,    47,    37,    38,    26,    47,    47,    43,    45,    41,
      43,    61,    61,    47,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    48,    65,    63,    63,    61,    65,
      61,    61,    30,    43,    43,    66,    11,    47,    47,    44,
      61,    61,    53,    65,    68,    41,    47,    47,    49,    65
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    52,    51,    53,    53,    54,    54,    54,    54,
      54,    55,    55,    55,    56,    57,    58,    58,    59,    59,
      59,    60,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    62,    62,    62,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    64,    64,    66,    65,
      68,    67,    67,    69,    69,    69,    69
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     4,     0,     2,     1,     1,     1,     1,
       2,     1,     1,     2,     3,     8,     3,     5,     1,     1,
       1,     4,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     1,     1,     1,     1,
       1,     3,     6,     6,     2,     2,     5,     7,     0,     4,
       0,     8,     5,     3,     3,     4,     6
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
  case 2: /* $@1: %empty  */
#line 55 "podium.y"
    { 
        env = init_environment(); 
        printf("=== Início da Execução ===\n");
    }
#line 1263 "podium.tab.c"
    break;

  case 3: /* program: GREENLIGHT $@1 statement_list CHEQUEREDFLAG  */
#line 60 "podium.y"
    {
        printf("\n=== Fim da Execução ===\n");
        printf("\n--- Resultados ---\n");
        printf("Pilotos registrados: %d\n", env->driver_count);
        for (int i = 0; i < env->driver_count; i++) {
            printf("  %s: %d pontos\n", env->drivers[i].name, env->drivers[i].points);
        }
        
        printf("\nEquipes registradas: %d\n", env->team_count);
        for (int i = 0; i < env->team_count; i++) {
            int team_points = env->drivers[env->teams[i].driver1_idx].points + 
                             env->drivers[env->teams[i].driver2_idx].points;
            printf("  %s: %d pontos (%s: %d, %s: %d)\n", 
                   env->teams[i].name, 
                   team_points,
                   env->drivers[env->teams[i].driver1_idx].name,
                   env->drivers[env->teams[i].driver1_idx].points,
                   env->drivers[env->teams[i].driver2_idx].name,
                   env->drivers[env->teams[i].driver2_idx].points);
        }
    }
#line 1289 "podium.tab.c"
    break;

  case 14: /* driver_decl: DRIVER IDENTIFIER ';'  */
#line 103 "podium.y"
    {
        register_driver(env, (yyvsp[-1].str_val));
    }
#line 1297 "podium.tab.c"
    break;

  case 15: /* team_decl: TEAM IDENTIFIER '[' IDENTIFIER ',' IDENTIFIER ']' ';'  */
#line 110 "podium.y"
    {
        register_team(env, (yyvsp[-6].str_val), (yyvsp[-4].str_val), (yyvsp[-2].str_val));
    }
#line 1305 "podium.tab.c"
    break;

  case 16: /* var_decl: IDENTIFIER COLON type  */
#line 117 "podium.y"
    {
        if (strcmp((yyvsp[0].str_val), "int") == 0) {
            define_variable(env, (yyvsp[-2].str_val), create_int_value(0));
        } else if (strcmp((yyvsp[0].str_val), "bool") == 0) {
            define_variable(env, (yyvsp[-2].str_val), create_bool_value(0));
        } else if (strcmp((yyvsp[0].str_val), "lapTime") == 0) {
            define_variable(env, (yyvsp[-2].str_val), create_laptime_value(0));
        }
    }
#line 1319 "podium.tab.c"
    break;

  case 17: /* var_decl: IDENTIFIER COLON type '=' expression  */
#line 127 "podium.y"
    {
        // Para lapTime, fazer conversão automática de int
        if (strcmp((yyvsp[-2].str_val), "int") == 0 && (yyvsp[0].value).type != VAL_INT) {
            printf("Erro: Tipo incompatível na inicialização da variável '%s'\n", (yyvsp[-4].str_val));
            exit(1);
        } else if (strcmp((yyvsp[-2].str_val), "bool") == 0 && (yyvsp[0].value).type != VAL_BOOL) {
            printf("Erro: Tipo incompatível na inicialização da variável '%s'\n", (yyvsp[-4].str_val));
            exit(1);
        } else if (strcmp((yyvsp[-2].str_val), "lapTime") == 0) {
            if ((yyvsp[0].value).type == VAL_INT) {
                // Converter int para lapTime
                define_variable(env, (yyvsp[-4].str_val), create_laptime_value((yyvsp[0].value).as.int_val));
            } else if ((yyvsp[0].value).type == VAL_LAPTIME) {
                define_variable(env, (yyvsp[-4].str_val), (yyvsp[0].value));
            } else {
                printf("Erro: Tipo incompatível na inicialização da variável '%s'\n", (yyvsp[-4].str_val));
                exit(1);
            }
        } else {
            define_variable(env, (yyvsp[-4].str_val), (yyvsp[0].value));
        }
    }
#line 1346 "podium.tab.c"
    break;

  case 18: /* type: TYPE_INT  */
#line 152 "podium.y"
              { (yyval.str_val) = "int"; }
#line 1352 "podium.tab.c"
    break;

  case 19: /* type: TYPE_BOOL  */
#line 153 "podium.y"
                  { (yyval.str_val) = "bool"; }
#line 1358 "podium.tab.c"
    break;

  case 20: /* type: TYPE_LAPTIME  */
#line 154 "podium.y"
                      { (yyval.str_val) = "lapTime"; }
#line 1364 "podium.tab.c"
    break;

  case 21: /* assignment: IDENTIFIER '=' expression ';'  */
#line 159 "podium.y"
    {
        if (!variable_exists(env, (yyvsp[-3].str_val))) {
            printf("Erro: Variável '%s' não definida\n", (yyvsp[-3].str_val));
            exit(1);
        }
        
        set_variable(env, (yyvsp[-3].str_val), (yyvsp[-1].value));
    }
#line 1377 "podium.tab.c"
    break;

  case 22: /* expression: term  */
#line 171 "podium.y"
    {
        (yyval.value) = (yyvsp[0].value);
    }
#line 1385 "podium.tab.c"
    break;

  case 23: /* expression: expression '+' term  */
#line 175 "podium.y"
    {
        (yyval.value) = value_add((yyvsp[-2].value), (yyvsp[0].value));
    }
#line 1393 "podium.tab.c"
    break;

  case 24: /* expression: expression '-' term  */
#line 179 "podium.y"
    {
        (yyval.value) = value_sub((yyvsp[-2].value), (yyvsp[0].value));
    }
#line 1401 "podium.tab.c"
    break;

  case 25: /* expression: expression EQ term  */
#line 183 "podium.y"
    {
        (yyval.value) = value_eq((yyvsp[-2].value), (yyvsp[0].value));
    }
#line 1409 "podium.tab.c"
    break;

  case 26: /* expression: expression NE term  */
#line 187 "podium.y"
    {
        (yyval.value) = value_ne((yyvsp[-2].value), (yyvsp[0].value));
    }
#line 1417 "podium.tab.c"
    break;

  case 27: /* expression: expression '<' term  */
#line 191 "podium.y"
    {
        (yyval.value) = value_lt((yyvsp[-2].value), (yyvsp[0].value));
    }
#line 1425 "podium.tab.c"
    break;

  case 28: /* expression: expression '>' term  */
#line 195 "podium.y"
    {
        (yyval.value) = value_gt((yyvsp[-2].value), (yyvsp[0].value));
    }
#line 1433 "podium.tab.c"
    break;

  case 29: /* expression: expression LE term  */
#line 199 "podium.y"
    {
        (yyval.value) = value_le((yyvsp[-2].value), (yyvsp[0].value));
    }
#line 1441 "podium.tab.c"
    break;

  case 30: /* expression: expression GE term  */
#line 203 "podium.y"
    {
        (yyval.value) = value_ge((yyvsp[-2].value), (yyvsp[0].value));
    }
#line 1449 "podium.tab.c"
    break;

  case 31: /* expression: expression AND term  */
#line 207 "podium.y"
    {
        (yyval.value) = value_and((yyvsp[-2].value), (yyvsp[0].value));
    }
#line 1457 "podium.tab.c"
    break;

  case 32: /* expression: expression OR term  */
#line 211 "podium.y"
    {
        (yyval.value) = value_or((yyvsp[-2].value), (yyvsp[0].value));
    }
#line 1465 "podium.tab.c"
    break;

  case 33: /* term: factor  */
#line 218 "podium.y"
    {
        (yyval.value) = (yyvsp[0].value);
    }
#line 1473 "podium.tab.c"
    break;

  case 34: /* term: term '*' factor  */
#line 222 "podium.y"
    {
        (yyval.value) = value_mul((yyvsp[-2].value), (yyvsp[0].value));
    }
#line 1481 "podium.tab.c"
    break;

  case 35: /* term: term '/' factor  */
#line 226 "podium.y"
    {
        (yyval.value) = value_div((yyvsp[-2].value), (yyvsp[0].value));
    }
#line 1489 "podium.tab.c"
    break;

  case 36: /* factor: NUMBER  */
#line 233 "podium.y"
    {
        (yyval.value) = create_int_value((yyvsp[0].int_val));
    }
#line 1497 "podium.tab.c"
    break;

  case 37: /* factor: TRUE  */
#line 237 "podium.y"
    {
        (yyval.value) = create_bool_value(1);
    }
#line 1505 "podium.tab.c"
    break;

  case 38: /* factor: FALSE  */
#line 241 "podium.y"
    {
        (yyval.value) = create_bool_value(0);
    }
#line 1513 "podium.tab.c"
    break;

  case 39: /* factor: STRING  */
#line 245 "podium.y"
    {
        (yyval.value) = create_string_value((yyvsp[0].str_val));
    }
#line 1521 "podium.tab.c"
    break;

  case 40: /* factor: IDENTIFIER  */
#line 249 "podium.y"
    {
        if (!variable_exists(env, (yyvsp[0].str_val))) {
            printf("Erro: Variável '%s' não definida\n", (yyvsp[0].str_val));
            exit(1);
        }
        (yyval.value) = get_variable(env, (yyvsp[0].str_val));
    }
#line 1533 "podium.tab.c"
    break;

  case 41: /* factor: '(' expression ')'  */
#line 257 "podium.y"
    {
        (yyval.value) = (yyvsp[-1].value);
    }
#line 1541 "podium.tab.c"
    break;

  case 42: /* factor: MIN '(' expression ',' expression ')'  */
#line 261 "podium.y"
    {
        (yyval.value) = value_min((yyvsp[-3].value), (yyvsp[-1].value));
    }
#line 1549 "podium.tab.c"
    break;

  case 43: /* factor: MAX '(' expression ',' expression ')'  */
#line 265 "podium.y"
    {
        (yyval.value) = value_max((yyvsp[-3].value), (yyvsp[-1].value));
    }
#line 1557 "podium.tab.c"
    break;

  case 44: /* factor: '-' factor  */
#line 269 "podium.y"
    {
        if ((yyvsp[0].value).type == VAL_INT) {
            (yyval.value) = create_int_value(-(yyvsp[0].value).as.int_val);
        } else if ((yyvsp[0].value).type == VAL_LAPTIME) {
            (yyval.value) = create_laptime_value(-(yyvsp[0].value).as.laptime_val);
        } else {
            printf("Erro: Operador '-' unário não pode ser aplicado a este tipo\n");
            exit(1);
        }
    }
#line 1572 "podium.tab.c"
    break;

  case 45: /* factor: '!' factor  */
#line 280 "podium.y"
    {
        if ((yyvsp[0].value).type == VAL_BOOL) {
            (yyval.value) = create_bool_value(!(yyvsp[0].value).as.bool_val);
        } else {
            printf("Erro: Operador '!' requer operando booleano\n");
            exit(1);
        }
    }
#line 1585 "podium.tab.c"
    break;

  case 46: /* conditional: IFPIT '(' expression ')' block  */
#line 292 "podium.y"
    {
        
    }
#line 1593 "podium.tab.c"
    break;

  case 47: /* conditional: IFPIT '(' expression ')' block ELSEPIT block  */
#line 296 "podium.y"
    {
        
    }
#line 1601 "podium.tab.c"
    break;

  case 48: /* $@2: %empty  */
#line 303 "podium.y"
    {
        
    }
#line 1609 "podium.tab.c"
    break;

  case 49: /* block: '{' $@2 statement_list '}'  */
#line 307 "podium.y"
    {
        
    }
#line 1617 "podium.tab.c"
    break;

  case 50: /* $@3: %empty  */
#line 314 "podium.y"
    {
        if ((yyvsp[-3].value).type != VAL_INT || (yyvsp[-1].value).type != VAL_INT) {
            printf("Erro: Limites do loop 'forLap' devem ser inteiros\n");
            exit(1);
        }
        
        // Salvar valores do loop para uso posterior
        int start = (yyvsp[-3].value).as.int_val;
        int end = (yyvsp[-1].value).as.int_val;
        
        for (int i = start; i <= end; i++) {
            printf("--- Volta %d ---\n", i);
            
            // Definir variável de índice
            define_variable(env, "current_lap", create_int_value(i));
        }
    }
#line 1639 "podium.tab.c"
    break;

  case 51: /* loop: FORLAP '(' expression DOTDOT expression ')' $@3 block  */
#line 332 "podium.y"
    {
        
    }
#line 1647 "podium.tab.c"
    break;

  case 52: /* loop: WHILESC '(' expression ')' block  */
#line 336 "podium.y"
    {
        
    }
#line 1655 "podium.tab.c"
    break;

  case 53: /* command: PITSTOP '(' ')'  */
#line 343 "podium.y"
    {
        pit_stop(env);
    }
#line 1663 "podium.tab.c"
    break;

  case 54: /* command: PUSHLAP '(' ')'  */
#line 347 "podium.y"
    {
        push_lap(env);
    }
#line 1671 "podium.tab.c"
    break;

  case 55: /* command: RADIO '(' expression ')'  */
#line 351 "podium.y"
    {
        if ((yyvsp[-1].value).type == VAL_STRING) {
            radio_message((yyvsp[-1].value).as.str_val);
        } else {
            printf("Erro: Argumento para radio deve ser uma string\n");
            exit(1);
        }
    }
#line 1684 "podium.tab.c"
    break;

  case 56: /* command: ADDPOINT '(' IDENTIFIER ',' expression ')'  */
#line 360 "podium.y"
    {
        if ((yyvsp[-1].value).type != VAL_INT) {
            printf("Erro: Pontos devem ser do tipo int\n");
            exit(1);
        }
        
        add_points(env, (yyvsp[-3].str_val), (yyvsp[-1].value).as.int_val);
    }
#line 1697 "podium.tab.c"
    break;


#line 1701 "podium.tab.c"

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

#line 370 "podium.y"


void yyerror(const char* s) {
    fprintf(stderr, "Erro sintático na linha %d: %s próximo a '%s'\n", yylineno, s, yytext);
}
