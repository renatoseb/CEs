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
#line 4 "calc.y"

#include "heading.h"
#include "table.cpp"
int yyerror(char *s);
extern "C" int yylex();

#line 78 "calc.tab.c"

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

#include "calc.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMERO = 3,                     /* NUMERO  */
  YYSYMBOL_IDENTIFICADOR = 4,              /* IDENTIFICADOR  */
  YYSYMBOL_TIPO_ENTERO = 5,                /* TIPO_ENTERO  */
  YYSYMBOL_SIN_TIPO = 6,                   /* SIN_TIPO  */
  YYSYMBOL_RETORNO = 7,                    /* RETORNO  */
  YYSYMBOL_MIENTRAS = 8,                   /* MIENTRAS  */
  YYSYMBOL_SI = 9,                         /* SI  */
  YYSYMBOL_SINO = 10,                      /* SINO  */
  YYSYMBOL_MAIN = 11,                      /* MAIN  */
  YYSYMBOL_OP_COMP_DIFERENTE = 12,         /* OP_COMP_DIFERENTE  */
  YYSYMBOL_OP_COMP_IGUAL = 13,             /* OP_COMP_IGUAL  */
  YYSYMBOL_OP_COMP_MENOR = 14,             /* OP_COMP_MENOR  */
  YYSYMBOL_OP_COMP_MAYOR = 15,             /* OP_COMP_MAYOR  */
  YYSYMBOL_OP_COMP_MENOR_IGUAL = 16,       /* OP_COMP_MENOR_IGUAL  */
  YYSYMBOL_OP_COMP_MAYOR_IGUAL = 17,       /* OP_COMP_MAYOR_IGUAL  */
  YYSYMBOL_OP_SUMA = 18,                   /* OP_SUMA  */
  YYSYMBOL_OP_RESTA = 19,                  /* OP_RESTA  */
  YYSYMBOL_OP_MUL = 20,                    /* OP_MUL  */
  YYSYMBOL_OP_DIV = 21,                    /* OP_DIV  */
  YYSYMBOL_ASIGNAR = 22,                   /* ASIGNAR  */
  YYSYMBOL_COMA = 23,                      /* COMA  */
  YYSYMBOL_PUNTO_COMA = 24,                /* PUNTO_COMA  */
  YYSYMBOL_PAR_INICIO = 25,                /* PAR_INICIO  */
  YYSYMBOL_PAR_FINAL = 26,                 /* PAR_FINAL  */
  YYSYMBOL_CORCH_INICIO = 27,              /* CORCH_INICIO  */
  YYSYMBOL_CORCH_FINAL = 28,               /* CORCH_FINAL  */
  YYSYMBOL_LLAVES_INICIO = 29,             /* LLAVES_INICIO  */
  YYSYMBOL_LLAVES_FINAL = 30,              /* LLAVES_FINAL  */
  YYSYMBOL_ERROR = 31,                     /* ERROR  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_programa = 33,                  /* programa  */
  YYSYMBOL_lista_declaracion = 34,         /* lista_declaracion  */
  YYSYMBOL_declaracion = 35,               /* declaracion  */
  YYSYMBOL_var_declaracion = 36,           /* var_declaracion  */
  YYSYMBOL_fun_declaracion = 37,           /* fun_declaracion  */
  YYSYMBOL_params = 38,                    /* params  */
  YYSYMBOL_lista_params = 39,              /* lista_params  */
  YYSYMBOL_p = 40,                         /* p  */
  YYSYMBOL_param = 41,                     /* param  */
  YYSYMBOL_sent_compuesta = 42,            /* sent_compuesta  */
  YYSYMBOL_declaracion_local = 43,         /* declaracion_local  */
  YYSYMBOL_lista_sentencias = 44,          /* lista_sentencias  */
  YYSYMBOL_sentencia = 45,                 /* sentencia  */
  YYSYMBOL_sentencia_expresion = 46,       /* sentencia_expresion  */
  YYSYMBOL_sentencia_seleccion = 47,       /* sentencia_seleccion  */
  YYSYMBOL_sentencia_iteracion = 48,       /* sentencia_iteracion  */
  YYSYMBOL_sentencia_retorno = 49,         /* sentencia_retorno  */
  YYSYMBOL_expresion = 50,                 /* expresion  */
  YYSYMBOL_var = 51,                       /* var  */
  YYSYMBOL_expresion_simple = 52,          /* expresion_simple  */
  YYSYMBOL_relop = 53,                     /* relop  */
  YYSYMBOL_expresion_aditiva = 54,         /* expresion_aditiva  */
  YYSYMBOL_term = 55,                      /* term  */
  YYSYMBOL_factor = 56,                    /* factor  */
  YYSYMBOL_call = 57,                      /* call  */
  YYSYMBOL_args = 58,                      /* args  */
  YYSYMBOL_lista_arg = 59                  /* lista_arg  */
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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   142

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  126

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    31,    31,    35,    36,    40,    41,    52,    64,    97,
     103,   109,   115,   124,   131,   134,   139,   145,   152,   156,
     160,   161,   162,   167,   172,   173,   178,   179,   184,   185,
     186,   187,   192,   193,   198,   199,   204,   209,   210,   215,
     219,   224,   225,   230,   231,   236,   237,   238,   239,   240,
     241,   246,   247,   248,   258,   259,   260,   270,   273,   274,
     275,   282,   290,   291,   296,   297
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
  "\"end of file\"", "error", "\"invalid token\"", "NUMERO",
  "IDENTIFICADOR", "TIPO_ENTERO", "SIN_TIPO", "RETORNO", "MIENTRAS", "SI",
  "SINO", "MAIN", "OP_COMP_DIFERENTE", "OP_COMP_IGUAL", "OP_COMP_MENOR",
  "OP_COMP_MAYOR", "OP_COMP_MENOR_IGUAL", "OP_COMP_MAYOR_IGUAL", "OP_SUMA",
  "OP_RESTA", "OP_MUL", "OP_DIV", "ASIGNAR", "COMA", "PUNTO_COMA",
  "PAR_INICIO", "PAR_FINAL", "CORCH_INICIO", "CORCH_FINAL",
  "LLAVES_INICIO", "LLAVES_FINAL", "ERROR", "$accept", "programa",
  "lista_declaracion", "declaracion", "var_declaracion", "fun_declaracion",
  "params", "lista_params", "p", "param", "sent_compuesta",
  "declaracion_local", "lista_sentencias", "sentencia",
  "sentencia_expresion", "sentencia_seleccion", "sentencia_iteracion",
  "sentencia_retorno", "expresion", "var", "expresion_simple", "relop",
  "expresion_aditiva", "term", "factor", "call", "args", "lista_arg", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-58)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      15,    -3,     5,    13,    15,   -58,   -58,   -58,   -10,   -20,
       0,     4,   -58,   -58,   -58,    57,    52,    57,    57,    57,
      28,    83,    69,    75,   -58,   -58,    71,    76,    77,    78,
      79,    80,    81,    84,    85,    81,    81,    81,    86,    87,
     -58,   -58,    83,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
     100,   104,   -58,     3,    29,   -58,    61,    36,    88,    91,
     -58,    -1,   -58,   -58,   -58,   -58,   -58,   -58,    93,    89,
     -58,    55,    26,   -58,   -58,    -1,    -1,   -58,    94,    -1,
      -1,    95,   -58,    -1,   -58,   -58,   -58,   -58,   -58,   -58,
      -1,    -1,    -1,    -1,    -1,   -58,    96,    97,    98,   -58,
      99,   101,   -58,   -58,   -58,    26,    26,    73,   -58,   -58,
     -58,    -1,   -58,    90,   102,   -58,   -58,   -58,    27,    34,
     -58,   113,   103,    41,    82,   -58
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     2,     4,     5,     6,     0,     0,
       0,     0,     1,     3,     7,    15,     0,    15,    15,    15,
       0,    14,     0,    13,    17,    18,     0,     0,     0,     0,
      19,    20,     0,     0,     0,     0,     0,     0,     0,     0,
      25,     9,     0,    16,     8,    11,    10,    12,    21,    22,
      27,     0,    24,     0,     0,    60,    41,     0,     0,     0,
      33,     0,    23,    26,    28,    29,    30,    31,     0,    58,
      40,    44,    53,    56,    59,    63,     0,    37,     0,     0,
       0,     0,    32,     0,    50,    49,    45,    47,    46,    48,
       0,     0,     0,     0,     0,    65,     0,    62,     0,    38,
       0,     0,    57,    39,    58,    51,    52,    43,    54,    55,
      61,     0,    42,     0,     0,    64,    27,    27,     0,     0,
      36,    35,     0,     0,     0,    34
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -58,   -58,   -58,   120,    92,   -58,    63,   -58,   105,   -58,
      48,   -58,   -23,    10,   -58,   -58,   -58,   -58,   -57,   -15,
     -58,   -58,    37,     6,     7,   -58,   -58,   -58
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,     7,    22,    23,    24,    25,
      41,    50,    53,    63,    64,    65,    66,    67,    68,    69,
      70,    92,    71,    72,    73,    74,    96,    97
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      78,     8,    55,    56,    81,    17,    55,    56,     9,    10,
      57,    58,    59,    12,    14,    15,    11,    16,    95,    98,
       1,     2,   100,   101,    61,    18,   103,    60,    61,    19,
      55,    56,    30,    62,    57,    58,    59,    55,    56,    55,
      56,    57,    58,    59,    55,    56,    93,    94,    57,    58,
      59,    60,    61,    14,   115,    26,    16,   120,    60,    61,
      77,    61,    20,    21,   121,    60,    61,    84,    85,    86,
      87,    88,    89,    90,    91,   104,   104,   104,   104,   104,
      27,    28,    29,    45,    46,    47,    75,    31,    76,    20,
      42,    90,    91,   118,   119,    32,   105,   106,    33,    34,
     108,   109,    35,    36,    37,    51,    38,    39,    54,    44,
      40,    83,   125,    79,    48,    49,    80,    82,    99,   116,
     111,   102,   110,   122,    13,   113,   112,   114,     0,   107,
       0,   117,   123,   124,     0,     0,     0,     0,    43,     0,
       0,     0,    52
};

static const yytype_int8 yycheck[] =
{
      57,     4,     3,     4,    61,    25,     3,     4,    11,     4,
       7,     8,     9,     0,    24,    25,    11,    27,    75,    76,
       5,     6,    79,    80,    25,    25,    83,    24,    25,    25,
       3,     4,     4,    30,     7,     8,     9,     3,     4,     3,
       4,     7,     8,     9,     3,     4,    20,    21,     7,     8,
       9,    24,    25,    24,   111,     3,    27,    30,    24,    25,
      24,    25,     5,     6,    30,    24,    25,    12,    13,    14,
      15,    16,    17,    18,    19,    90,    91,    92,    93,    94,
      17,    18,    19,    35,    36,    37,    25,     4,    27,     5,
       6,    18,    19,   116,   117,    26,    90,    91,    23,    28,
      93,    94,    26,    26,    26,     5,    27,    27,     4,    24,
      29,    22,    30,    25,    28,    28,    25,    24,    24,    29,
      23,    26,    26,    10,     4,    26,    28,    26,    -1,    92,
      -1,    29,    29,   123,    -1,    -1,    -1,    -1,    33,    -1,
      -1,    -1,    50
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     6,    33,    34,    35,    36,    37,     4,    11,
       4,    11,     0,    35,    24,    25,    27,    25,    25,    25,
       5,     6,    38,    39,    40,    41,     3,    38,    38,    38,
       4,     4,    26,    23,    28,    26,    26,    26,    27,    27,
      29,    42,     6,    40,    24,    42,    42,    42,    28,    28,
      43,     5,    36,    44,     4,     3,     4,     7,     8,     9,
      24,    25,    30,    45,    46,    47,    48,    49,    50,    51,
      52,    54,    55,    56,    57,    25,    27,    24,    50,    25,
      25,    50,    24,    22,    12,    13,    14,    15,    16,    17,
      18,    19,    53,    20,    21,    50,    58,    59,    50,    24,
      50,    50,    26,    50,    51,    55,    55,    54,    56,    56,
      26,    23,    28,    26,    26,    50,    29,    29,    44,    44,
      30,    30,    10,    29,    45,    30
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    36,    36,    37,
      37,    37,    37,    38,    38,    38,    39,    39,    40,    41,
      41,    41,    41,    42,    43,    43,    44,    44,    45,    45,
      45,    45,    46,    46,    47,    47,    48,    49,    49,    50,
      50,    51,    51,    52,    52,    53,    53,    53,    53,    53,
      53,    54,    54,    54,    55,    55,    55,    56,    56,    56,
      56,    57,    58,    58,    59,    59
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     6,     6,
       6,     6,     6,     1,     1,     0,     3,     1,     1,     2,
       2,     4,     4,     4,     2,     0,     2,     0,     1,     1,
       1,     1,     2,     1,    11,     7,     7,     2,     3,     3,
       1,     1,     4,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     1,     3,     3,     1,     3,     1,     1,
       1,     4,     1,     0,     3,     1
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
  case 2: /* programa: lista_declaracion  */
#line 31 "calc.y"
                      { /* std::cout << "lista declaracion" << std::endl; */ }
#line 1210 "calc.tab.c"
    break;

  case 3: /* lista_declaracion: lista_declaracion declaracion  */
#line 35 "calc.y"
                                  { /* std::cout << "Derivando a lista_declaracion declaracion \n"; */ }
#line 1216 "calc.tab.c"
    break;

  case 4: /* lista_declaracion: declaracion  */
#line 36 "calc.y"
                { /* std::cout << "Derivando a declaracion \n "; */ }
#line 1222 "calc.tab.c"
    break;

  case 5: /* declaracion: var_declaracion  */
#line 40 "calc.y"
                    {}
#line 1228 "calc.tab.c"
    break;

  case 6: /* declaracion: fun_declaracion  */
#line 41 "calc.y"
                    {}
#line 1234 "calc.tab.c"
    break;

  case 7: /* var_declaracion: TIPO_ENTERO IDENTIFICADOR PUNTO_COMA  */
#line 52 "calc.y"
                                         {
      // std::cout << "hola" << std::endl;
      if(!anhadir_id_var(string(*(yyvsp[-1].op_val))))
      {
        char* a = "La variable \"";
        char* b = "\" ya ha sido definida";
        char buffer[100];
        strcat(strcpy(buffer, a), string(*(yyvsp[-1].op_val)).c_str());
        strcat(buffer, b);
        yyerror(buffer);
      }
    }
#line 1251 "calc.tab.c"
    break;

  case 8: /* var_declaracion: TIPO_ENTERO IDENTIFICADOR CORCH_INICIO NUMERO CORCH_FINAL PUNTO_COMA  */
#line 64 "calc.y"
                                                                         {
      // std::cout << "hola" << std::endl;
      if(!anhadir_id_arreglo(string(*(yyvsp[-4].op_val)), stoi(string(*(yyvsp[-2].op_val)))))
      {
        char* a = "La variable \"";
        char* b = "\" ya ha sido definida";
        char buffer[100];
        strcat(strcpy(buffer, a), string(*(yyvsp[-4].op_val)).c_str());
        strcat(buffer, b);
        yyerror(buffer);
      }
  }
#line 1268 "calc.tab.c"
    break;

  case 9: /* fun_declaracion: TIPO_ENTERO IDENTIFICADOR PAR_INICIO params PAR_FINAL sent_compuesta  */
#line 97 "calc.y"
                                                                         {
      if(!anhadir_id_function(string(*(yyvsp[-4].op_val)), string(*(yyvsp[-2].op_val)))) {
          yyerror("La funcion ya ha sido declarada");
      }
      //std::cout << "params fun declaracion: " << string(*$4) << std::endl;
    }
#line 1279 "calc.tab.c"
    break;

  case 10: /* fun_declaracion: SIN_TIPO IDENTIFICADOR PAR_INICIO params PAR_FINAL sent_compuesta  */
#line 103 "calc.y"
                                                                      {
      // string s = string(*$2);
      if(!anhadir_id_function(string(*(yyvsp[-4].op_val)), string(*(yyvsp[-2].op_val)))) {
          yyerror("La funcion ya ha sido declarada");
      }
  }
#line 1290 "calc.tab.c"
    break;

  case 11: /* fun_declaracion: TIPO_ENTERO MAIN PAR_INICIO params PAR_FINAL sent_compuesta  */
#line 109 "calc.y"
                                                                {
      string s = "main";
      if(!anhadir_id_function(s, string(*(yyvsp[-2].op_val)))) {
          yyerror("La funcion ya ha sido declarada");
      }
  }
#line 1301 "calc.tab.c"
    break;

  case 12: /* fun_declaracion: SIN_TIPO MAIN PAR_INICIO params PAR_FINAL sent_compuesta  */
#line 115 "calc.y"
                                                             {
      string s = "main";
      if(!anhadir_id_function(s , string(*(yyvsp[-2].op_val)))) {
          yyerror("La funcion ya ha sido declarada");
      }
  }
#line 1312 "calc.tab.c"
    break;

  case 13: /* params: lista_params  */
#line 124 "calc.y"
                 {
      /*
      string *var = new string("params");
      */
      // std::cout << "lista params in params: " << string(*$1) << std::endl;
      (yyval.op_val) = (yyvsp[0].op_val);
    }
#line 1324 "calc.tab.c"
    break;

  case 14: /* params: SIN_TIPO  */
#line 131 "calc.y"
              {
    yyerror("Variable sin tipo declarada");
  }
#line 1332 "calc.tab.c"
    break;

  case 15: /* params: %empty  */
#line 134 "calc.y"
    {
      string s=""; (yyval.op_val) = &s; /* se agrego epsilon para representar que una funcion puede no tener parametros*/
    }
#line 1340 "calc.tab.c"
    break;

  case 16: /* lista_params: lista_params COMA p  */
#line 139 "calc.y"
                                   {
      // std::cout << "lista params 2da: " << string(*$1) << std::endl;
      string t =  string(*(yyvsp[-2].op_val)) + "," + string(*(yyvsp[0].op_val));
      (yyval.op_val) = &t;
    }
#line 1350 "calc.tab.c"
    break;

  case 17: /* lista_params: p  */
#line 145 "calc.y"
      {
      // std::cout << "lista params(regla param) 1ra: " << string(*$1) << std::endl;
      (yyval.op_val) = (yyvsp[0].op_val); 
    }
#line 1359 "calc.tab.c"
    break;

  case 18: /* p: param  */
#line 152 "calc.y"
        {(yyval.op_val) = (yyvsp[0].op_val);}
#line 1365 "calc.tab.c"
    break;

  case 19: /* param: TIPO_ENTERO IDENTIFICADOR  */
#line 156 "calc.y"
                                 {
          // std::cout << "param: " << string(*$2) << std::endl;
          (yyval.op_val) = (yyvsp[0].op_val);
       }
#line 1374 "calc.tab.c"
    break;

  case 20: /* param: SIN_TIPO IDENTIFICADOR  */
#line 160 "calc.y"
                               {  }
#line 1380 "calc.tab.c"
    break;

  case 21: /* param: TIPO_ENTERO IDENTIFICADOR CORCH_INICIO CORCH_FINAL  */
#line 161 "calc.y"
                                                           {  }
#line 1386 "calc.tab.c"
    break;

  case 22: /* param: SIN_TIPO IDENTIFICADOR CORCH_INICIO CORCH_FINAL  */
#line 162 "calc.y"
                                                        {  }
#line 1392 "calc.tab.c"
    break;

  case 23: /* sent_compuesta: LLAVES_INICIO declaracion_local lista_sentencias LLAVES_FINAL  */
#line 167 "calc.y"
                                                                  {std::cout << "sentencia compuesta" << std::endl;}
#line 1398 "calc.tab.c"
    break;

  case 24: /* declaracion_local: declaracion_local var_declaracion  */
#line 172 "calc.y"
                                      {std::cout << "declaracion local" << std::endl;}
#line 1404 "calc.tab.c"
    break;

  case 26: /* lista_sentencias: lista_sentencias sentencia  */
#line 178 "calc.y"
                               {std::cout << "LISTA SENTENCIAS" << std::endl;}
#line 1410 "calc.tab.c"
    break;

  case 28: /* sentencia: sentencia_expresion  */
#line 184 "calc.y"
                        {}
#line 1416 "calc.tab.c"
    break;

  case 29: /* sentencia: sentencia_seleccion  */
#line 185 "calc.y"
                        {}
#line 1422 "calc.tab.c"
    break;

  case 30: /* sentencia: sentencia_iteracion  */
#line 186 "calc.y"
                        {}
#line 1428 "calc.tab.c"
    break;

  case 31: /* sentencia: sentencia_retorno  */
#line 187 "calc.y"
                      {}
#line 1434 "calc.tab.c"
    break;

  case 32: /* sentencia_expresion: expresion PUNTO_COMA  */
#line 192 "calc.y"
                         {}
#line 1440 "calc.tab.c"
    break;

  case 33: /* sentencia_expresion: PUNTO_COMA  */
#line 193 "calc.y"
               {}
#line 1446 "calc.tab.c"
    break;

  case 34: /* sentencia_seleccion: SI PAR_INICIO expresion PAR_FINAL LLAVES_INICIO lista_sentencias LLAVES_FINAL SINO LLAVES_INICIO sentencia LLAVES_FINAL  */
#line 198 "calc.y"
                                                                                                                            {}
#line 1452 "calc.tab.c"
    break;

  case 35: /* sentencia_seleccion: SI PAR_INICIO expresion PAR_FINAL LLAVES_INICIO lista_sentencias LLAVES_FINAL  */
#line 199 "calc.y"
                                                                                  {}
#line 1458 "calc.tab.c"
    break;

  case 36: /* sentencia_iteracion: MIENTRAS PAR_INICIO expresion PAR_FINAL LLAVES_INICIO lista_sentencias LLAVES_FINAL  */
#line 204 "calc.y"
                                                                                        {}
#line 1464 "calc.tab.c"
    break;

  case 37: /* sentencia_retorno: RETORNO PUNTO_COMA  */
#line 209 "calc.y"
                       {}
#line 1470 "calc.tab.c"
    break;

  case 38: /* sentencia_retorno: RETORNO expresion PUNTO_COMA  */
#line 210 "calc.y"
                                 {std::cout << "RETORNO PUNTO_COMA" << std::endl; }
#line 1476 "calc.tab.c"
    break;

  case 39: /* expresion: var ASIGNAR expresion  */
#line 216 "calc.y"
    {
      
    }
#line 1484 "calc.tab.c"
    break;

  case 40: /* expresion: expresion_simple  */
#line 219 "calc.y"
                     {}
#line 1490 "calc.tab.c"
    break;

  case 41: /* var: IDENTIFICADOR  */
#line 224 "calc.y"
                  {}
#line 1496 "calc.tab.c"
    break;

  case 42: /* var: IDENTIFICADOR CORCH_INICIO expresion CORCH_FINAL  */
#line 225 "calc.y"
                                                     {}
#line 1502 "calc.tab.c"
    break;

  case 43: /* expresion_simple: expresion_aditiva relop expresion_aditiva  */
#line 230 "calc.y"
                                              {}
#line 1508 "calc.tab.c"
    break;

  case 44: /* expresion_simple: expresion_aditiva  */
#line 231 "calc.y"
                      {}
#line 1514 "calc.tab.c"
    break;

  case 45: /* relop: OP_COMP_MENOR  */
#line 236 "calc.y"
                   {}
#line 1520 "calc.tab.c"
    break;

  case 46: /* relop: OP_COMP_MENOR_IGUAL  */
#line 237 "calc.y"
                        {}
#line 1526 "calc.tab.c"
    break;

  case 47: /* relop: OP_COMP_MAYOR  */
#line 238 "calc.y"
                   {}
#line 1532 "calc.tab.c"
    break;

  case 48: /* relop: OP_COMP_MAYOR_IGUAL  */
#line 239 "calc.y"
                        {}
#line 1538 "calc.tab.c"
    break;

  case 49: /* relop: OP_COMP_IGUAL  */
#line 240 "calc.y"
                  {}
#line 1544 "calc.tab.c"
    break;

  case 50: /* relop: OP_COMP_DIFERENTE  */
#line 241 "calc.y"
                      {}
#line 1550 "calc.tab.c"
    break;

  case 51: /* expresion_aditiva: expresion_aditiva OP_SUMA term  */
#line 246 "calc.y"
                                   {}
#line 1556 "calc.tab.c"
    break;

  case 52: /* expresion_aditiva: expresion_aditiva OP_RESTA term  */
#line 247 "calc.y"
                                    {}
#line 1562 "calc.tab.c"
    break;

  case 53: /* expresion_aditiva: term  */
#line 248 "calc.y"
         {}
#line 1568 "calc.tab.c"
    break;

  case 54: /* term: term OP_MUL factor  */
#line 258 "calc.y"
                       {}
#line 1574 "calc.tab.c"
    break;

  case 55: /* term: term OP_DIV factor  */
#line 259 "calc.y"
                       {}
#line 1580 "calc.tab.c"
    break;

  case 56: /* term: factor  */
#line 260 "calc.y"
           {}
#line 1586 "calc.tab.c"
    break;

  case 57: /* factor: PAR_INICIO expresion PAR_FINAL  */
#line 270 "calc.y"
                                   {
      
    }
#line 1594 "calc.tab.c"
    break;

  case 58: /* factor: var  */
#line 273 "calc.y"
        {}
#line 1600 "calc.tab.c"
    break;

  case 59: /* factor: call  */
#line 274 "calc.y"
         {}
#line 1606 "calc.tab.c"
    break;

  case 60: /* factor: NUMERO  */
#line 275 "calc.y"
           {
    
    }
#line 1614 "calc.tab.c"
    break;

  case 61: /* call: IDENTIFICADOR PAR_INICIO args PAR_FINAL  */
#line 283 "calc.y"
    {
      
    }
#line 1622 "calc.tab.c"
    break;

  case 62: /* args: lista_arg  */
#line 290 "calc.y"
              {}
#line 1628 "calc.tab.c"
    break;

  case 64: /* lista_arg: lista_arg COMA expresion  */
#line 296 "calc.y"
                             {}
#line 1634 "calc.tab.c"
    break;

  case 65: /* lista_arg: expresion  */
#line 297 "calc.y"
              {}
#line 1640 "calc.tab.c"
    break;


#line 1644 "calc.tab.c"

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

#line 300 "calc.y"


int yyerror(string s)
{
  extern int yylineno;	// defined and maintained in lex.c
  extern char *yytext;	// defined and maintained in lex.c
  
  cerr << "ERROR: " << s;
  cerr << " en la linea " << yylineno << endl;
  exit(1);
}

int yyerror(char *s)
{
  return yyerror(string(s));
}
