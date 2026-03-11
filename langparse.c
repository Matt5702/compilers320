/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
#define YYBISON 30704

/* Bison version string.  */
#define YYBISON_VERSION "3.7.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "lang.y"

//**************************************
// lang.y
//
// Parser definition file. bison uses this file to generate the parser.
//
// Author: Phil Howard 
//

#include <iostream>
#include "lex.h"
#include "astnodes.h"
#include "cSymbolTable.h"
#include "cBaseTypeNode.h"


#line 88 "langparse.c"

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

#include "langparse.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_TYPE_ID = 4,                    /* TYPE_ID  */
  YYSYMBOL_CHAR_VAL = 5,                   /* CHAR_VAL  */
  YYSYMBOL_INT_VAL = 6,                    /* INT_VAL  */
  YYSYMBOL_FLOAT_VAL = 7,                  /* FLOAT_VAL  */
  YYSYMBOL_LE = 8,                         /* LE  */
  YYSYMBOL_GE = 9,                         /* GE  */
  YYSYMBOL_AND = 10,                       /* AND  */
  YYSYMBOL_OR = 11,                        /* OR  */
  YYSYMBOL_EQUALS = 12,                    /* EQUALS  */
  YYSYMBOL_NOT_EQUALS = 13,                /* NOT_EQUALS  */
  YYSYMBOL_STRING_LIT = 14,                /* STRING_LIT  */
  YYSYMBOL_PROGRAM = 15,                   /* PROGRAM  */
  YYSYMBOL_PRINT = 16,                     /* PRINT  */
  YYSYMBOL_PRINTS = 17,                    /* PRINTS  */
  YYSYMBOL_WHILE = 18,                     /* WHILE  */
  YYSYMBOL_IF = 19,                        /* IF  */
  YYSYMBOL_ELSE = 20,                      /* ELSE  */
  YYSYMBOL_ENDIF = 21,                     /* ENDIF  */
  YYSYMBOL_STRUCT = 22,                    /* STRUCT  */
  YYSYMBOL_ARRAY = 23,                     /* ARRAY  */
  YYSYMBOL_RETURN = 24,                    /* RETURN  */
  YYSYMBOL_JUNK_TOKEN = 25,                /* JUNK_TOKEN  */
  YYSYMBOL_26_ = 26,                       /* '{'  */
  YYSYMBOL_27_ = 27,                       /* '}'  */
  YYSYMBOL_28_ = 28,                       /* ';'  */
  YYSYMBOL_29_ = 29,                       /* '['  */
  YYSYMBOL_30_ = 30,                       /* ']'  */
  YYSYMBOL_31_ = 31,                       /* '('  */
  YYSYMBOL_32_ = 32,                       /* ')'  */
  YYSYMBOL_33_ = 33,                       /* ','  */
  YYSYMBOL_34_ = 34,                       /* '='  */
  YYSYMBOL_35_ = 35,                       /* '.'  */
  YYSYMBOL_36_ = 36,                       /* '>'  */
  YYSYMBOL_37_ = 37,                       /* '<'  */
  YYSYMBOL_38_ = 38,                       /* '+'  */
  YYSYMBOL_39_ = 39,                       /* '-'  */
  YYSYMBOL_40_ = 40,                       /* '*'  */
  YYSYMBOL_41_ = 41,                       /* '/'  */
  YYSYMBOL_42_ = 42,                       /* '%'  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_program = 44,                   /* program  */
  YYSYMBOL_block = 45,                     /* block  */
  YYSYMBOL_func_body = 46,                 /* func_body  */
  YYSYMBOL_open = 47,                      /* open  */
  YYSYMBOL_close = 48,                     /* close  */
  YYSYMBOL_decls = 49,                     /* decls  */
  YYSYMBOL_decl = 50,                      /* decl  */
  YYSYMBOL_51_1 = 51,                      /* $@1  */
  YYSYMBOL_52_2 = 52,                      /* $@2  */
  YYSYMBOL_var_decl = 53,                  /* var_decl  */
  YYSYMBOL_54_3 = 54,                      /* $@3  */
  YYSYMBOL_struct_decl = 55,               /* struct_decl  */
  YYSYMBOL_56_4 = 56,                      /* $@4  */
  YYSYMBOL_array_decl = 57,                /* array_decl  */
  YYSYMBOL_58_5 = 58,                      /* $@5  */
  YYSYMBOL_decl_after_id = 59,             /* decl_after_id  */
  YYSYMBOL_60_6 = 60,                      /* $@6  */
  YYSYMBOL_61_7 = 61,                      /* $@7  */
  YYSYMBOL_62_8 = 62,                      /* $@8  */
  YYSYMBOL_63_9 = 63,                      /* $@9  */
  YYSYMBOL_func_tail = 64,                 /* func_tail  */
  YYSYMBOL_paramsspec = 65,                /* paramsspec  */
  YYSYMBOL_paramspec = 66,                 /* paramspec  */
  YYSYMBOL_stmts = 67,                     /* stmts  */
  YYSYMBOL_stmt = 68,                      /* stmt  */
  YYSYMBOL_func_call = 69,                 /* func_call  */
  YYSYMBOL_varref = 70,                    /* varref  */
  YYSYMBOL_varpart = 71,                   /* varpart  */
  YYSYMBOL_lval = 72,                      /* lval  */
  YYSYMBOL_params = 73,                    /* params  */
  YYSYMBOL_param = 74,                     /* param  */
  YYSYMBOL_expr = 75,                      /* expr  */
  YYSYMBOL_andexpr = 76,                   /* andexpr  */
  YYSYMBOL_eqexpr = 77,                    /* eqexpr  */
  YYSYMBOL_relexpr = 78,                   /* relexpr  */
  YYSYMBOL_addit = 79,                     /* addit  */
  YYSYMBOL_term = 80,                      /* term  */
  YYSYMBOL_fact = 81                       /* fact  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 41 "lang.y"

    int yyerror(const char *msg);

    cAstNode *yyast_root;
    static cSymbol *g_declType = nullptr;
    static cSymbol *g_declName = nullptr;
    static cFuncDeclNode *g_funcDecl = nullptr;
    static bool g_semanticErrorHappened = false;
    
    // Error checking macros
    #define CHECK_ERROR() { if (g_semanticErrorHappened) \
        { g_semanticErrorHappened = false; } }
    #define PROP_ERROR() { if (g_semanticErrorHappened) \
        { g_semanticErrorHappened = false; YYERROR; } }

#line 219 "langparse.c"


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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   204

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  162

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   280


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
       2,     2,     2,     2,     2,     2,     2,    42,     2,     2,
      31,    32,    40,    38,    33,    39,    35,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    28,
      37,    34,    36,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    29,     2,    30,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    26,     2,    27,     2,     2,     2,     2,
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
      25
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   111,   111,   119,   127,   129,   132,   135,   138,   141,
     143,   145,   145,   145,   147,   149,   151,   154,   154,   161,
     161,   168,   168,   176,   182,   183,   182,   189,   190,   189,
     197,   199,   207,   209,   212,   215,   217,   220,   222,   224,
     226,   228,   230,   232,   234,   236,   238,   241,   243,   246,
     248,   250,   253,   256,   259,   261,   264,   267,   269,   272,
     274,   277,   279,   281,   284,   286,   288,   290,   292,   295,
     297,   299,   302,   304,   306,   308,   311,   313,   315,   317,
     319,   321,   323
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
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "TYPE_ID", "CHAR_VAL", "INT_VAL", "FLOAT_VAL", "LE", "GE", "AND", "OR",
  "EQUALS", "NOT_EQUALS", "STRING_LIT", "PROGRAM", "PRINT", "PRINTS",
  "WHILE", "IF", "ELSE", "ENDIF", "STRUCT", "ARRAY", "RETURN",
  "JUNK_TOKEN", "'{'", "'}'", "';'", "'['", "']'", "'('", "')'", "','",
  "'='", "'.'", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", "'%'", "$accept",
  "program", "block", "func_body", "open", "close", "decls", "decl", "$@1",
  "$@2", "var_decl", "$@3", "struct_decl", "$@4", "array_decl", "$@5",
  "decl_after_id", "$@6", "$@7", "$@8", "$@9", "func_tail", "paramsspec",
  "paramspec", "stmts", "stmt", "func_call", "varref", "varpart", "lval",
  "params", "param", "expr", "andexpr", "eqexpr", "relexpr", "addit",
  "term", "fact", YY_NULLPTR
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
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   123,   125,    59,    91,
      93,    40,    41,    44,    61,    46,    62,    60,    43,    45,
      42,    47,    37
};
#endif

#define YYPACT_NINF (-36)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-47)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -7,   -16,   -36,    27,   -36,   142,   -36,   -36,    54,    18,
     -36,    60,    62,    73,    81,   -16,   111,    38,   -36,   142,
     -36,    93,    95,    70,   -36,    96,   -18,   -36,    92,    39,
      33,   124,    38,   115,    38,    38,    25,   102,   -36,   -36,
     -36,    38,    38,   -36,   -18,    56,   122,     2,    26,   -15,
      34,   -36,   -36,    70,   -36,   -36,   106,   -36,   -36,   -36,
     -36,    38,   133,    38,   -36,    66,   -36,   126,   -36,    10,
     107,    14,    21,   110,    91,   134,    47,   -36,    38,   -36,
      38,    38,    38,    38,    38,    38,    38,    38,    38,    38,
      38,    38,   -36,   -36,    40,   -36,   -36,    57,   -36,    38,
     -19,   113,   119,   178,   178,   -36,   -36,   118,   -36,   122,
       2,    26,    26,   -15,   -15,   -15,   -15,    34,    34,   -36,
     -36,   -36,   -36,   -36,   -36,   -36,   117,   -36,   -36,   -36,
     -36,   154,   147,   -36,   148,   121,   178,   128,   -36,   159,
     -36,   -36,    77,   -36,   -36,   166,   -36,   -36,   160,   -36,
     148,    52,   149,   -36,    52,   -36,   -36,   -36,   -36,   -36,
     -36,   -36
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     7,     0,     3,     0,     2,     1,     0,    52,
      11,     0,     0,     0,     0,     0,     0,     0,    44,     0,
      10,     0,     0,     0,    36,     0,    53,    51,     0,    16,
       0,     0,     0,     0,     0,     0,     0,     0,    79,    78,
      80,     0,     0,    82,    81,     0,    58,    60,    63,    68,
      71,    75,     9,     0,    15,    14,     0,     8,     5,    35,
      43,     0,     0,     0,    48,     0,    55,    56,    12,     0,
       0,     0,     0,     0,     0,     0,     0,    77,     0,    45,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     4,    46,     0,    52,    49,     0,    47,     0,
       0,     0,     0,     0,     0,    16,    19,     0,    76,    57,
      59,    61,    62,    67,    66,    64,    65,    69,    70,    72,
      73,    74,    50,    42,    54,    23,    24,    13,    40,    41,
      39,     0,     0,    21,     0,     0,     0,     0,    20,     0,
      17,    34,     0,    33,    28,     0,    37,    22,     0,    25,
       0,     0,     0,    18,     0,    32,    30,     6,    31,    29,
      38,    26
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -36,   -36,     0,   -36,   161,     7,   150,   -13,   -36,   -36,
     -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,
     -36,    37,   -36,    43,   -14,   -20,    -3,    -1,   127,   -36,
     -36,    89,    -4,   120,   123,    35,    22,    32,   -35
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,    18,   158,     5,    58,    19,    20,    31,   100,
     141,   148,    21,   132,    22,   139,   127,   134,   154,   135,
     151,   159,   142,   143,    23,    24,    43,    44,    27,    28,
      65,    66,    67,    46,    47,    48,    49,    50,    51
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       4,     6,    25,    59,    26,    53,    52,    77,     1,   125,
       2,    61,   126,    45,    81,    82,    25,    62,    26,     2,
      25,    78,    26,    87,    88,    78,    73,     7,    69,    10,
      71,    72,    78,    59,    83,    84,     9,    76,    38,    39,
      40,     9,   101,    38,    39,    40,   103,    15,    16,    30,
      25,    78,    26,   104,   119,   120,   121,    94,    78,    97,
      92,    52,    85,    86,    41,    64,   -46,    78,    78,    41,
     122,    56,    42,     9,    89,    90,    91,    42,     2,   108,
     156,   106,    29,   130,    79,   123,    11,    12,    13,    14,
     131,    32,    73,    33,    17,    10,     2,    57,    98,    99,
      25,    25,    26,    26,    34,   113,   114,   115,   116,   149,
     150,    59,    35,    15,    16,    37,   111,   112,    57,   117,
     118,    54,   145,    55,    60,    59,    63,    68,    25,    70,
      26,    75,    80,    25,    93,    26,    95,    78,   105,   102,
     107,   128,    25,     8,    26,     9,    10,   129,   133,   -27,
     138,   157,   140,   144,   157,    56,   146,     9,    11,    12,
      13,    14,   147,   153,    15,    16,    17,    56,     2,     9,
      11,    12,    13,    14,   136,   137,    36,   160,    17,    56,
       2,     9,    11,    12,    13,    14,    74,   152,   124,    96,
      17,   161,     2,   155,    11,    12,    13,    14,   109,     0,
       0,     0,    17,   110,     2
};

static const yytype_int16 yycheck[] =
{
       0,     1,     5,    23,     5,    19,    19,    42,    15,    28,
      26,    29,    31,    17,    12,    13,    19,    35,    19,    26,
      23,    11,    23,    38,    39,    11,     1,     0,    32,     4,
      34,    35,    11,    53,     8,     9,     3,    41,     5,     6,
       7,     3,    32,     5,     6,     7,    32,    22,    23,    31,
      53,    11,    53,    32,    89,    90,    91,    61,    11,    63,
      53,    74,    36,    37,    31,    32,    27,    11,    11,    31,
      30,     1,    39,     3,    40,    41,    42,    39,    26,    32,
      28,    74,    28,   103,    28,    28,    16,    17,    18,    19,
     104,    31,     1,    31,    24,     4,    26,    27,    32,    33,
     103,   104,   103,   104,    31,    83,    84,    85,    86,    32,
      33,   131,    31,    22,    23,     4,    81,    82,    27,    87,
      88,    28,   136,    28,    28,   145,    34,     3,   131,    14,
     131,    29,    10,   136,    28,   136,     3,    11,    28,    32,
       6,    28,   145,     1,   145,     3,     4,    28,    30,    32,
       3,   151,     4,    32,   154,     1,    28,     3,    16,    17,
      18,    19,     3,     3,    22,    23,    24,     1,    26,     3,
      16,    17,    18,    19,    20,    21,    15,    28,    24,     1,
      26,     3,    16,    17,    18,    19,    36,    21,    99,    62,
      24,   154,    26,   150,    16,    17,    18,    19,    78,    -1,
      -1,    -1,    24,    80,    26
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    15,    26,    44,    45,    47,    45,     0,     1,     3,
       4,    16,    17,    18,    19,    22,    23,    24,    45,    49,
      50,    55,    57,    67,    68,    69,    70,    71,    72,    28,
      31,    51,    31,    31,    31,    31,    47,     4,     5,     6,
       7,    31,    39,    69,    70,    75,    76,    77,    78,    79,
      80,    81,    50,    67,    28,    28,     1,    27,    48,    68,
      28,    29,    35,    34,    32,    73,    74,    75,     3,    75,
      14,    75,    75,     1,    49,    29,    75,    81,    11,    28,
      10,    12,    13,     8,     9,    36,    37,    38,    39,    40,
      41,    42,    48,    28,    75,     3,    71,    75,    32,    33,
      52,    32,    32,    32,    32,    28,    48,     6,    32,    76,
      77,    78,    78,    79,    79,    79,    79,    80,    80,    81,
      81,    81,    30,    28,    74,    28,    31,    59,    28,    28,
      68,    67,    56,    30,    60,    62,    20,    21,     3,    58,
       4,    53,    65,    66,    32,    67,    28,     3,    54,    32,
      33,    63,    21,     3,    61,    66,    28,    45,    46,    64,
      28,    64
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    44,    45,    45,    46,    47,    48,    49,
      49,    51,    52,    50,    50,    50,    50,    54,    53,    56,
      55,    58,    57,    59,    60,    61,    59,    62,    63,    59,
      64,    64,    65,    65,    66,    67,    67,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    69,    69,    70,
      70,    70,    71,    72,    73,    73,    74,    75,    75,    76,
      76,    77,    77,    77,    78,    78,    78,    78,    78,    79,
      79,    79,    80,    80,    80,    80,    81,    81,    81,    81,
      81,    81,    81
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     4,     3,     1,     1,     1,     2,
       1,     0,     0,     5,     2,     2,     2,     0,     3,     0,
       6,     0,     7,     1,     0,     0,     6,     0,     0,     5,
       1,     1,     3,     1,     1,     2,     1,     7,     9,     5,
       5,     5,     4,     2,     1,     3,     2,     4,     3,     3,
       4,     1,     1,     1,     3,     1,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     1,     3,     2,     1,     1,
       1,     1,     1
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

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YY_LOCATION_PRINT
#  if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#   define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

#  else
#   define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#  endif
# endif /* !defined YY_LOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yyerror_range[1] = yylloc;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: PROGRAM block  */
#line 112 "lang.y"
                                { (yyval.program_node) = new cProgramNode((yyvsp[0].block_node));
                                  yyast_root = (yyval.program_node);
                                  if (yynerrs == 0) 
                                      YYACCEPT;
                                  else
                                      YYABORT;
                                }
#line 1394 "langparse.c"
    break;

  case 3: /* program: block  */
#line 120 "lang.y"
                                { (yyval.program_node) = new cProgramNode((yyvsp[0].block_node));
                                  yyast_root = (yyval.program_node);
                                  if (yynerrs == 0)
                                      YYACCEPT;
                                  else
                                      YYABORT;
                                }
#line 1406 "langparse.c"
    break;

  case 4: /* block: open decls stmts close  */
#line 128 "lang.y"
                                { (yyval.block_node) = new cBlockNode((yyvsp[-2].decls_node), (yyvsp[-1].stmts_node)); }
#line 1412 "langparse.c"
    break;

  case 5: /* block: open stmts close  */
#line 130 "lang.y"
                                { (yyval.block_node) = new cBlockNode(nullptr, (yyvsp[-1].stmts_node)); }
#line 1418 "langparse.c"
    break;

  case 6: /* func_body: block  */
#line 133 "lang.y"
                                { (yyval.block_node) = (yyvsp[0].block_node); }
#line 1424 "langparse.c"
    break;

  case 7: /* open: '{'  */
#line 136 "lang.y"
                                { g_symbolTable.IncreaseScope(); }
#line 1430 "langparse.c"
    break;

  case 8: /* close: '}'  */
#line 139 "lang.y"
                                { g_symbolTable.DecreaseScope(); }
#line 1436 "langparse.c"
    break;

  case 9: /* decls: decls decl  */
#line 142 "lang.y"
                                { (yyvsp[-1].decls_node)->Insert((yyvsp[0].decl_node)); (yyval.decls_node) = (yyvsp[-1].decls_node); }
#line 1442 "langparse.c"
    break;

  case 10: /* decls: decl  */
#line 144 "lang.y"
                                { (yyval.decls_node) = new cDeclsNode((yyvsp[0].decl_node)); }
#line 1448 "langparse.c"
    break;

  case 11: /* $@1: %empty  */
#line 145 "lang.y"
                    { g_insert = 1; }
#line 1454 "langparse.c"
    break;

  case 12: /* $@2: %empty  */
#line 145 "lang.y"
                                                 { g_insert = 0; g_declType = (yyvsp[-2].symbol); g_declName = (yyvsp[0].symbol); }
#line 1460 "langparse.c"
    break;

  case 13: /* decl: TYPE_ID $@1 IDENTIFIER $@2 decl_after_id  */
#line 146 "lang.y"
                { (yyval.decl_node) = (yyvsp[0].decl_node); }
#line 1466 "langparse.c"
    break;

  case 14: /* decl: array_decl ';'  */
#line 148 "lang.y"
                                { (yyval.decl_node) = (yyvsp[-1].decl_node); }
#line 1472 "langparse.c"
    break;

  case 15: /* decl: struct_decl ';'  */
#line 150 "lang.y"
                                { (yyval.decl_node) = (yyvsp[-1].decl_node); }
#line 1478 "langparse.c"
    break;

  case 16: /* decl: error ';'  */
#line 152 "lang.y"
                                { (yyval.decl_node) = nullptr; }
#line 1484 "langparse.c"
    break;

  case 17: /* $@3: %empty  */
#line 154 "lang.y"
                    { g_insert = 1; }
#line 1490 "langparse.c"
    break;

  case 18: /* var_decl: TYPE_ID $@3 IDENTIFIER  */
#line 155 "lang.y"
                                    {
                                        g_insert = 0;
                                        cVarDeclNode *varDecl = new cVarDeclNode((yyvsp[-2].symbol), (yyvsp[0].symbol));
                                        (yyvsp[0].symbol)->SetDecl(varDecl);
                                        (yyval.decl_node) = varDecl;
                                    }
#line 1501 "langparse.c"
    break;

  case 19: /* $@4: %empty  */
#line 161 "lang.y"
                                      { g_insert = 1; }
#line 1507 "langparse.c"
    break;

  case 20: /* struct_decl: STRUCT open decls close $@4 IDENTIFIER  */
#line 162 "lang.y"
                                { 
                                    g_insert = 0;
                                    cStructDeclNode *structNode = new cStructDeclNode((yyvsp[-3].decls_node), (yyvsp[0].symbol));
                                    (yyvsp[0].symbol)->SetDecl(structNode);
                                    (yyval.decl_node) = structNode;
                                }
#line 1518 "langparse.c"
    break;

  case 21: /* $@5: %empty  */
#line 168 "lang.y"
                                            { g_insert = 1; }
#line 1524 "langparse.c"
    break;

  case 22: /* array_decl: ARRAY TYPE_ID '[' INT_VAL ']' $@5 IDENTIFIER  */
#line 169 "lang.y"
                                { 
                                    g_insert = 0;
                                    cArrayDeclNode *arrayNode = new cArrayDeclNode((yyvsp[-5].symbol), (yyvsp[0].symbol), (yyvsp[-3].int_val));
                                    (yyvsp[0].symbol)->SetDecl(arrayNode);
                                    (yyval.decl_node) = arrayNode;
                                }
#line 1535 "langparse.c"
    break;

  case 23: /* decl_after_id: ';'  */
#line 177 "lang.y"
                                                                {
                                                                    cVarDeclNode *varDecl = new cVarDeclNode(g_declType, g_declName);
                                                                    g_declName->SetDecl(varDecl);
                                                                    (yyval.decl_node) = varDecl;
                                                                }
#line 1545 "langparse.c"
    break;

  case 24: /* $@6: %empty  */
#line 182 "lang.y"
                        { g_symbolTable.IncreaseScope(); }
#line 1551 "langparse.c"
    break;

  case 25: /* $@7: %empty  */
#line 183 "lang.y"
                                                                {
                                                                    g_funcDecl = new cFuncDeclNode(g_declType, g_declName, (yyvsp[-1].args_node));
                                                                    g_declName->SetDecl(g_funcDecl);
                                                                }
#line 1560 "langparse.c"
    break;

  case 26: /* decl_after_id: '(' $@6 paramsspec ')' $@7 func_tail  */
#line 188 "lang.y"
                                                                { g_symbolTable.DecreaseScope(); (yyval.decl_node) = g_funcDecl; g_funcDecl = nullptr; }
#line 1566 "langparse.c"
    break;

  case 27: /* $@8: %empty  */
#line 189 "lang.y"
                        { g_symbolTable.IncreaseScope(); }
#line 1572 "langparse.c"
    break;

  case 28: /* $@9: %empty  */
#line 190 "lang.y"
                                                                {
                                                                    g_funcDecl = new cFuncDeclNode(g_declType, g_declName, nullptr);
                                                                    g_declName->SetDecl(g_funcDecl);
                                                                }
#line 1581 "langparse.c"
    break;

  case 29: /* decl_after_id: '(' $@8 ')' $@9 func_tail  */
#line 195 "lang.y"
                                                                { g_symbolTable.DecreaseScope(); (yyval.decl_node) = g_funcDecl; g_funcDecl = nullptr; }
#line 1587 "langparse.c"
    break;

  case 30: /* func_tail: ';'  */
#line 198 "lang.y"
                                                                { (yyval.ast_node) = nullptr; }
#line 1593 "langparse.c"
    break;

  case 31: /* func_tail: func_body  */
#line 200 "lang.y"
                                                                { if (g_funcDecl != nullptr)
                                                                  {
                                                                      if ((yyvsp[0].block_node)->GetDecls() != nullptr)
                                                                          g_funcDecl->AppendDecls((yyvsp[0].block_node)->GetDecls());
                                                                      g_funcDecl->AppendStmts((yyvsp[0].block_node)->GetStmts());
                                                                  }
                                                                  (yyval.ast_node) = nullptr; }
#line 1605 "langparse.c"
    break;

  case 32: /* paramsspec: paramsspec ',' paramspec  */
#line 208 "lang.y"
                                { (yyvsp[-2].args_node)->Insert((yyvsp[0].decl_node)); (yyval.args_node) = (yyvsp[-2].args_node); }
#line 1611 "langparse.c"
    break;

  case 33: /* paramsspec: paramspec  */
#line 210 "lang.y"
                                { (yyval.args_node) = new cArgsNode((yyvsp[0].decl_node)); }
#line 1617 "langparse.c"
    break;

  case 34: /* paramspec: var_decl  */
#line 213 "lang.y"
                                    { (yyval.decl_node) = (yyvsp[0].decl_node); }
#line 1623 "langparse.c"
    break;

  case 35: /* stmts: stmts stmt  */
#line 216 "lang.y"
                                { (yyvsp[-1].stmts_node)->Insert((yyvsp[0].stmt_node)); (yyval.stmts_node) = (yyvsp[-1].stmts_node); }
#line 1629 "langparse.c"
    break;

  case 36: /* stmts: stmt  */
#line 218 "lang.y"
                                { (yyval.stmts_node) = new cStmtsNode((yyvsp[0].stmt_node)); }
#line 1635 "langparse.c"
    break;

  case 37: /* stmt: IF '(' expr ')' stmts ENDIF ';'  */
#line 221 "lang.y"
                                { (yyval.stmt_node) = new cIfNode((yyvsp[-4].expr_node), (yyvsp[-2].stmts_node), nullptr); }
#line 1641 "langparse.c"
    break;

  case 38: /* stmt: IF '(' expr ')' stmts ELSE stmts ENDIF ';'  */
#line 223 "lang.y"
                                { (yyval.stmt_node) = new cIfNode((yyvsp[-6].expr_node), (yyvsp[-4].stmts_node), (yyvsp[-2].stmts_node)); }
#line 1647 "langparse.c"
    break;

  case 39: /* stmt: WHILE '(' expr ')' stmt  */
#line 225 "lang.y"
                                { (yyval.stmt_node) = new cWhileNode((yyvsp[-2].expr_node), (yyvsp[0].stmt_node)); }
#line 1653 "langparse.c"
    break;

  case 40: /* stmt: PRINT '(' expr ')' ';'  */
#line 227 "lang.y"
                                { (yyval.stmt_node) = new cPrintNode((yyvsp[-2].expr_node)); }
#line 1659 "langparse.c"
    break;

  case 41: /* stmt: PRINTS '(' STRING_LIT ')' ';'  */
#line 229 "lang.y"
                                { (yyval.stmt_node) = new cPrintsNode(*(yyvsp[-2].str_val)); delete (yyvsp[-2].str_val); }
#line 1665 "langparse.c"
    break;

  case 42: /* stmt: lval '=' expr ';'  */
#line 231 "lang.y"
                                { (yyval.stmt_node) = new cAssignNode((yyvsp[-3].varref_node), (yyvsp[-1].expr_node)); }
#line 1671 "langparse.c"
    break;

  case 43: /* stmt: func_call ';'  */
#line 233 "lang.y"
                    { (yyval.stmt_node) = (yyvsp[-1].expr_node); }
#line 1677 "langparse.c"
    break;

  case 44: /* stmt: block  */
#line 235 "lang.y"
                                { (yyval.stmt_node) = (yyvsp[0].block_node); }
#line 1683 "langparse.c"
    break;

  case 45: /* stmt: RETURN expr ';'  */
#line 237 "lang.y"
                                { (yyval.stmt_node) = new cReturnNode((yyvsp[-1].expr_node)); }
#line 1689 "langparse.c"
    break;

  case 46: /* stmt: error ';'  */
#line 239 "lang.y"
                                { (yyval.stmt_node) = nullptr; }
#line 1695 "langparse.c"
    break;

  case 47: /* func_call: IDENTIFIER '(' params ')'  */
#line 242 "lang.y"
                                    { (yyval.expr_node) = new cFuncCallNode((yyvsp[-3].symbol), (yyvsp[-1].params_node)); }
#line 1701 "langparse.c"
    break;

  case 48: /* func_call: IDENTIFIER '(' ')'  */
#line 244 "lang.y"
                            { (yyval.expr_node) = new cFuncCallNode((yyvsp[-2].symbol), nullptr); }
#line 1707 "langparse.c"
    break;

  case 49: /* varref: varref '.' varpart  */
#line 247 "lang.y"
                                { (yyvsp[-2].varref_node)->AddPart((yyvsp[0].symbol)); (yyval.varref_node) = (yyvsp[-2].varref_node); }
#line 1713 "langparse.c"
    break;

  case 50: /* varref: varref '[' expr ']'  */
#line 249 "lang.y"
                                { (yyvsp[-3].varref_node)->AddPart((yyvsp[-1].expr_node)); (yyval.varref_node) = (yyvsp[-3].varref_node); }
#line 1719 "langparse.c"
    break;

  case 51: /* varref: varpart  */
#line 251 "lang.y"
                                { (yyval.varref_node) = new cVarRefNode((yyvsp[0].symbol)); }
#line 1725 "langparse.c"
    break;

  case 52: /* varpart: IDENTIFIER  */
#line 254 "lang.y"
                                { (yyval.symbol) = (yyvsp[0].symbol); }
#line 1731 "langparse.c"
    break;

  case 53: /* lval: varref  */
#line 257 "lang.y"
                                { (yyval.varref_node) = (yyvsp[0].varref_node); }
#line 1737 "langparse.c"
    break;

  case 54: /* params: params ',' param  */
#line 260 "lang.y"
                                { (yyvsp[-2].params_node)->Insert((yyvsp[0].expr_node)); (yyval.params_node) = (yyvsp[-2].params_node); }
#line 1743 "langparse.c"
    break;

  case 55: /* params: param  */
#line 262 "lang.y"
                                { (yyval.params_node) = new cParamsNode((yyvsp[0].expr_node)); }
#line 1749 "langparse.c"
    break;

  case 56: /* param: expr  */
#line 265 "lang.y"
                                { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1755 "langparse.c"
    break;

  case 57: /* expr: expr OR andexpr  */
#line 268 "lang.y"
                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode(OR), (yyvsp[0].expr_node)); }
#line 1761 "langparse.c"
    break;

  case 58: /* expr: andexpr  */
#line 270 "lang.y"
                                { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1767 "langparse.c"
    break;

  case 59: /* andexpr: andexpr AND eqexpr  */
#line 273 "lang.y"
                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode(AND), (yyvsp[0].expr_node)); }
#line 1773 "langparse.c"
    break;

  case 60: /* andexpr: eqexpr  */
#line 275 "lang.y"
                { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1779 "langparse.c"
    break;

  case 61: /* eqexpr: eqexpr EQUALS relexpr  */
#line 278 "lang.y"
                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode(EQUALS), (yyvsp[0].expr_node)); }
#line 1785 "langparse.c"
    break;

  case 62: /* eqexpr: eqexpr NOT_EQUALS relexpr  */
#line 280 "lang.y"
                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode(NOT_EQUALS), (yyvsp[0].expr_node)); }
#line 1791 "langparse.c"
    break;

  case 63: /* eqexpr: relexpr  */
#line 282 "lang.y"
                { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1797 "langparse.c"
    break;

  case 64: /* relexpr: relexpr '>' addit  */
#line 285 "lang.y"
                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode('>'), (yyvsp[0].expr_node)); }
#line 1803 "langparse.c"
    break;

  case 65: /* relexpr: relexpr '<' addit  */
#line 287 "lang.y"
                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode('<'), (yyvsp[0].expr_node)); }
#line 1809 "langparse.c"
    break;

  case 66: /* relexpr: relexpr GE addit  */
#line 289 "lang.y"
                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode(GE), (yyvsp[0].expr_node)); }
#line 1815 "langparse.c"
    break;

  case 67: /* relexpr: relexpr LE addit  */
#line 291 "lang.y"
                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode(LE), (yyvsp[0].expr_node)); }
#line 1821 "langparse.c"
    break;

  case 68: /* relexpr: addit  */
#line 293 "lang.y"
                { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1827 "langparse.c"
    break;

  case 69: /* addit: addit '+' term  */
#line 296 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode('+'), (yyvsp[0].expr_node)); }
#line 1833 "langparse.c"
    break;

  case 70: /* addit: addit '-' term  */
#line 298 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode('-'), (yyvsp[0].expr_node)); }
#line 1839 "langparse.c"
    break;

  case 71: /* addit: term  */
#line 300 "lang.y"
                                { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1845 "langparse.c"
    break;

  case 72: /* term: term '*' fact  */
#line 303 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode('*'), (yyvsp[0].expr_node)); }
#line 1851 "langparse.c"
    break;

  case 73: /* term: term '/' fact  */
#line 305 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode('/'), (yyvsp[0].expr_node)); }
#line 1857 "langparse.c"
    break;

  case 74: /* term: term '%' fact  */
#line 307 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode('%'), (yyvsp[0].expr_node)); }
#line 1863 "langparse.c"
    break;

  case 75: /* term: fact  */
#line 309 "lang.y"
                                { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1869 "langparse.c"
    break;

  case 76: /* fact: '(' expr ')'  */
#line 312 "lang.y"
                                { (yyval.expr_node) = (yyvsp[-1].expr_node); }
#line 1875 "langparse.c"
    break;

  case 77: /* fact: '-' fact  */
#line 314 "lang.y"
                { (yyval.expr_node) = new cBinaryExprNode(new cIntExprNode(0), new cOpNode('-'), (yyvsp[0].expr_node)); }
#line 1881 "langparse.c"
    break;

  case 78: /* fact: INT_VAL  */
#line 316 "lang.y"
                                { (yyval.expr_node) = new cIntExprNode((yyvsp[0].int_val)); }
#line 1887 "langparse.c"
    break;

  case 79: /* fact: CHAR_VAL  */
#line 318 "lang.y"
                { (yyval.expr_node) = new cIntExprNode((yyvsp[0].int_val)); }
#line 1893 "langparse.c"
    break;

  case 80: /* fact: FLOAT_VAL  */
#line 320 "lang.y"
                                { (yyval.expr_node) = new cFloatExprNode((yyvsp[0].float_val)); }
#line 1899 "langparse.c"
    break;

  case 81: /* fact: varref  */
#line 322 "lang.y"
                                { (yyval.expr_node) = (yyvsp[0].varref_node); }
#line 1905 "langparse.c"
    break;

  case 82: /* fact: func_call  */
#line 324 "lang.y"
                                { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1911 "langparse.c"
    break;


#line 1915 "langparse.c"

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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 326 "lang.y"


// Function to format error messages
int yyerror(const char *msg)
{
    std::cout << "ERROR: " << msg << " at symbol "
        << yytext << " on line " << yylineno << "\n";

    return 0;
}

// Function that gets called when a semantic error happens
void SemanticParseError(std::string error)
{
    std::cout << "ERROR: " << error << " near line " 
              << yylineno << "\n";
    g_semanticErrorHappened = true;
    yynerrs++;
}
