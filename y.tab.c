/* A Bison parser, made by GNU Bison 3.5.1.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "sintatica.y"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <set>

#define YYSTYPE atributos

using namespace std;

struct atributos
{
	string label;
	string traducao;
	string tipo;
};
typedef struct{
	string nomeVariavel;
	string tipoVariavel;
	string nomeTemp;
	string size = "";
	stack<int> scope;
} TIPO_SIMBOLO;

int var_temp_qnt;
vector<TIPO_SIMBOLO> tabelaSimbolos;
int flag;
int marcador;
static int cont = 0;
stack<int> escopototal;
int yylex(void);
void yyerror(string);
string gentempcode();
void addtabSimbolos(string ntemp, string tipo)
{
	TIPO_SIMBOLO novovar;
	novovar.nomeVariavel = "";
	novovar.tipoVariavel = tipo;
	novovar.nomeTemp = ntemp;
	novovar.scope = escopototal;
	tabelaSimbolos.push_back(novovar);
}
//void execute_casting(string label)
string printtabelaSimbolos()
{
	string n = "";
	for(int i = 0; i < tabelaSimbolos.size(); i++)
	{
		n += "\t" + tabelaSimbolos[i].tipoVariavel + "\t" + tabelaSimbolos[i].nomeTemp  + tabelaSimbolos[i].size + ";\n";
	}
	return n;
}
/*void printpilhasdeSimbolos()
{
	//string n = "";
	for(int i = 0; i < tabelaSimbolos.size(); i++)
	{
		cout << "\t" << tabelaSimbolos[i].scope.top()<< " " <<tabelaSimbolos[i].nomeTemp<<endl;
	}
	//return n;
}*/

#line 135 "y.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TK_NUM = 258,
    TK_REAL = 259,
    TK_BOOL = 260,
    TK_CHAR = 261,
    TK_OP_REL = 262,
    TK_STRING = 263,
    _STRING = 264,
    TK_MAIN = 265,
    TK_ID = 266,
    TK_TIPO_INT = 267,
    TK_TIPO_FLOAT = 268,
    TK_TIPO_CHAR = 269,
    TK_TIPO_BOOL = 270,
    TK_CAST_INT = 271,
    TK_CAST_FLOAT = 272,
    TK_TIPO_STRING = 273,
    TK_FIM = 274,
    TK_ERROR = 275,
    TK_PRINT = 276,
    TK_SCAN = 277,
    TK_IG = 278,
    TK_DIF = 279,
    TK_MAIG = 280,
    TK_MEIG = 281,
    TK_MAIOR = 282,
    TK_MENOR = 283,
    TK_AND = 284,
    TK_OR = 285,
    TK_NOT = 286,
    TK_MAIS_MAIS = 287,
    TK_MENOS_MENOS = 288,
    TK_IF = 289,
    TK_ELSE_IF = 290,
    TK_ELSE = 291,
    TK_WHILE = 292,
    TK_DO = 293,
    TK_FOR = 294,
    TK_SWITCH = 295,
    TK_CASE = 296,
    TK_BREAK = 297,
    TK_DEFAULT = 298,
    TK_CONTINUE = 299,
    TK_RETURN = 300
  };
#endif
/* Tokens.  */
#define TK_NUM 258
#define TK_REAL 259
#define TK_BOOL 260
#define TK_CHAR 261
#define TK_OP_REL 262
#define TK_STRING 263
#define _STRING 264
#define TK_MAIN 265
#define TK_ID 266
#define TK_TIPO_INT 267
#define TK_TIPO_FLOAT 268
#define TK_TIPO_CHAR 269
#define TK_TIPO_BOOL 270
#define TK_CAST_INT 271
#define TK_CAST_FLOAT 272
#define TK_TIPO_STRING 273
#define TK_FIM 274
#define TK_ERROR 275
#define TK_PRINT 276
#define TK_SCAN 277
#define TK_IG 278
#define TK_DIF 279
#define TK_MAIG 280
#define TK_MEIG 281
#define TK_MAIOR 282
#define TK_MENOR 283
#define TK_AND 284
#define TK_OR 285
#define TK_NOT 286
#define TK_MAIS_MAIS 287
#define TK_MENOS_MENOS 288
#define TK_IF 289
#define TK_ELSE_IF 290
#define TK_ELSE 291
#define TK_WHILE 292
#define TK_DO 293
#define TK_FOR 294
#define TK_SWITCH 295
#define TK_CASE 296
#define TK_BREAK 297
#define TK_DEFAULT 298
#define TK_CONTINUE 299
#define TK_RETURN 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYLAST   559

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  54
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  151

#define YYUNDEFTOK  2
#define YYMAXUTOK   300


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      49,    50,    48,    46,     2,    47,     2,    55,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    53,
       2,    54,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,    52,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    80,    80,    88,    99,   107,   113,   118,   122,   131,
     140,   146,   162,   177,   189,   195,   200,   214,   215,   216,
     217,   221,   242,   263,   285,   307,   329,   352,   373,   394,
     415,   443,   447,   453,   475,   516,   546,   576,   606,   636,
     667,   708,   749,   791,   832,   873,   914,   920,   933,   945,
     956,   967,  1003,  1011,  1026
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_NUM", "TK_REAL", "TK_BOOL",
  "TK_CHAR", "TK_OP_REL", "TK_STRING", "_STRING", "TK_MAIN", "TK_ID",
  "TK_TIPO_INT", "TK_TIPO_FLOAT", "TK_TIPO_CHAR", "TK_TIPO_BOOL",
  "TK_CAST_INT", "TK_CAST_FLOAT", "TK_TIPO_STRING", "TK_FIM", "TK_ERROR",
  "TK_PRINT", "TK_SCAN", "TK_IG", "TK_DIF", "TK_MAIG", "TK_MEIG",
  "TK_MAIOR", "TK_MENOR", "TK_AND", "TK_OR", "TK_NOT", "TK_MAIS_MAIS",
  "TK_MENOS_MENOS", "TK_IF", "TK_ELSE_IF", "TK_ELSE", "TK_WHILE", "TK_DO",
  "TK_FOR", "TK_SWITCH", "TK_CASE", "TK_BREAK", "TK_DEFAULT",
  "TK_CONTINUE", "TK_RETURN", "'+'", "'-'", "'*'", "'('", "')'", "'{'",
  "'}'", "';'", "'='", "'/'", "$accept", "S", "BLOCO", "INICIO", "FIM",
  "COMANDOS", "CONDICAO", "LOOP", "BREAK1", "COMANDO", "E", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,    43,    45,    42,    40,
      41,   123,   125,    59,    61,    47
};
# endif

#define YYPACT_NINF (-117)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -10,    -2,    12,   -31,  -117,   -34,   -28,  -117,  -117,   112,
    -117,  -117,  -117,   -22,     9,    13,    38,    41,    59,    59,
      45,   -23,    59,    17,    22,    23,     7,    24,    59,  -117,
    -117,    42,  -117,   112,   141,    59,   -32,   -19,    -9,    11,
     460,   460,    15,    59,   460,    59,    59,    59,  -117,    59,
     152,     8,   -28,  -117,    59,    59,    59,    59,    59,    59,
      59,    59,  -117,  -117,    59,    59,    59,  -117,    59,   460,
    -117,    59,  -117,    59,  -117,    59,  -117,    59,  -117,    59,
     185,   196,   229,   240,   112,   273,  -117,  -117,  -117,   460,
     460,   460,   460,   460,   460,   460,   460,   493,   493,   504,
     460,   284,   317,   328,   361,   372,  -117,   -28,   -28,    28,
     -33,    59,  -117,  -117,  -117,  -117,  -117,  -117,  -117,  -117,
      21,    29,  -117,   405,   112,   112,   112,    31,    59,   -33,
     -33,   -33,    44,   416,  -117,  -117,  -117,    35,    34,    36,
      59,  -117,  -117,   449,   112,    33,   -33,  -117,  -117,    37,
    -117
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     4,     2,     7,
      52,    53,    32,    54,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    20,
       5,    18,    19,     7,     0,     0,     0,     0,     0,     0,
      49,    50,     0,     0,    46,     0,     0,     0,     4,     0,
       0,     0,     0,     6,     0,     0,     0,     0,     0,     0,
       0,     0,    47,    48,     0,     0,     0,    17,     0,    51,
      21,     0,    27,     0,    28,     0,    22,     0,    29,     0,
       0,     0,     0,     0,     7,     0,    31,     3,    10,    38,
      39,    42,    43,    40,    41,    44,    45,    34,    35,    36,
      37,     0,     0,     0,     0,     0,    33,     0,     0,     0,
      16,     0,    24,    26,    25,    23,    30,     8,     9,     4,
       0,     0,     5,     0,     7,     7,     7,     0,     0,    16,
      16,    16,     0,     0,     5,    14,    15,     0,     0,     0,
       0,     4,    11,     0,     7,     0,    16,    13,     5,     0,
      12
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -117,  -117,    -1,   -42,  -115,   -30,  -117,  -117,  -116,  -117,
     -18
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    29,     9,    51,    30,    31,    32,   122,    33,
      34
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      40,    41,     1,    53,    44,     8,    84,   127,     3,   120,
      50,   121,     4,   134,   135,   136,     6,    69,     5,   139,
      36,    70,    71,     7,    37,    80,    43,    81,    82,    83,
     148,    85,    35,   149,    72,    73,    89,    90,    91,    92,
      93,    94,    95,    96,    74,    75,    97,    98,    99,    38,
     100,    88,    39,   101,   110,   102,    42,   103,    48,   104,
      87,   105,    10,    11,    76,    77,    45,    12,    78,    79,
      13,    46,    47,    49,   125,    18,    19,   124,    52,   119,
      21,   137,   126,   132,   140,   141,   147,     0,   142,   150,
      22,     0,     0,   123,   129,   130,   131,     0,     0,   144,
       0,     0,     0,     0,     0,     0,   117,   118,    28,     0,
     133,     0,     0,     0,   146,    10,    11,     0,     0,     0,
      12,     0,   143,    13,    14,    15,    16,    17,    18,    19,
      20,     0,     0,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,     0,     0,    23,    24,     0,    25,
      26,    27,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    28,     0,     7,    54,    55,    56,    57,    58,    59,
      60,    61,     0,    62,    63,    54,    55,    56,    57,    58,
      59,    60,    61,     0,    62,    63,     0,    64,    65,    66,
       0,     0,     0,     0,    67,     0,    68,     0,    64,    65,
      66,     0,    86,     0,     0,     0,     0,    68,    54,    55,
      56,    57,    58,    59,    60,    61,     0,    62,    63,    54,
      55,    56,    57,    58,    59,    60,    61,     0,    62,    63,
       0,    64,    65,    66,     0,   106,     0,     0,     0,     0,
      68,     0,    64,    65,    66,     0,   107,     0,     0,     0,
       0,    68,    54,    55,    56,    57,    58,    59,    60,    61,
       0,    62,    63,    54,    55,    56,    57,    58,    59,    60,
      61,     0,    62,    63,     0,    64,    65,    66,     0,   108,
       0,     0,     0,     0,    68,     0,    64,    65,    66,     0,
     109,     0,     0,     0,     0,    68,    54,    55,    56,    57,
      58,    59,    60,    61,     0,    62,    63,    54,    55,    56,
      57,    58,    59,    60,    61,     0,    62,    63,     0,    64,
      65,    66,     0,     0,     0,     0,   111,     0,    68,     0,
      64,    65,    66,     0,     0,     0,     0,   112,     0,    68,
      54,    55,    56,    57,    58,    59,    60,    61,     0,    62,
      63,    54,    55,    56,    57,    58,    59,    60,    61,     0,
      62,    63,     0,    64,    65,    66,     0,     0,     0,     0,
     113,     0,    68,     0,    64,    65,    66,     0,     0,     0,
       0,   114,     0,    68,    54,    55,    56,    57,    58,    59,
      60,    61,     0,    62,    63,    54,    55,    56,    57,    58,
      59,    60,    61,     0,    62,    63,     0,    64,    65,    66,
       0,     0,     0,     0,   115,     0,    68,     0,    64,    65,
      66,     0,     0,     0,     0,   116,     0,    68,    54,    55,
      56,    57,    58,    59,    60,    61,     0,    62,    63,    54,
      55,    56,    57,    58,    59,    60,    61,     0,    62,    63,
       0,    64,    65,    66,     0,     0,     0,     0,   128,     0,
      68,     0,    64,    65,    66,     0,   138,     0,     0,     0,
       0,    68,    54,    55,    56,    57,    58,    59,    60,    61,
       0,    62,    63,    54,    55,    56,    57,    58,    59,    60,
      61,     0,    62,    63,     0,    64,    65,    66,     0,   145,
       0,     0,     0,     0,    68,     0,    64,    65,    66,     0,
       0,     0,     0,     0,     0,    68,    54,    55,    56,    57,
      58,    59,    60,    61,     0,    62,    63,    54,    55,    56,
      57,    58,    59,    60,    61,     0,    62,    63,     0,     0,
       0,    66,     0,     0,     0,     0,     0,     0,    68,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    68
};

static const yytype_int16 yycheck[] =
{
      18,    19,    12,    33,    22,     6,    48,   122,    10,    42,
      28,    44,     0,   129,   130,   131,    50,    35,    49,   134,
      11,    53,    54,    51,    11,    43,    49,    45,    46,    47,
     146,    49,    54,   148,    53,    54,    54,    55,    56,    57,
      58,    59,    60,    61,    53,    54,    64,    65,    66,    11,
      68,    52,    11,    71,    84,    73,    11,    75,    51,    77,
      52,    79,     3,     4,    53,    54,    49,     8,    53,    54,
      11,    49,    49,    49,    53,    16,    17,   119,    36,    51,
      21,    37,    53,    52,    49,    51,    53,    -1,    52,    52,
      31,    -1,    -1,   111,   124,   125,   126,    -1,    -1,   141,
      -1,    -1,    -1,    -1,    -1,    -1,   107,   108,    49,    -1,
     128,    -1,    -1,    -1,   144,     3,     4,    -1,    -1,    -1,
       8,    -1,   140,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,    -1,    37,
      38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    -1,    51,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    32,    33,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    32,    33,    -1,    46,    47,    48,
      -1,    -1,    -1,    -1,    53,    -1,    55,    -1,    46,    47,
      48,    -1,    50,    -1,    -1,    -1,    -1,    55,    23,    24,
      25,    26,    27,    28,    29,    30,    -1,    32,    33,    23,
      24,    25,    26,    27,    28,    29,    30,    -1,    32,    33,
      -1,    46,    47,    48,    -1,    50,    -1,    -1,    -1,    -1,
      55,    -1,    46,    47,    48,    -1,    50,    -1,    -1,    -1,
      -1,    55,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    32,    33,    23,    24,    25,    26,    27,    28,    29,
      30,    -1,    32,    33,    -1,    46,    47,    48,    -1,    50,
      -1,    -1,    -1,    -1,    55,    -1,    46,    47,    48,    -1,
      50,    -1,    -1,    -1,    -1,    55,    23,    24,    25,    26,
      27,    28,    29,    30,    -1,    32,    33,    23,    24,    25,
      26,    27,    28,    29,    30,    -1,    32,    33,    -1,    46,
      47,    48,    -1,    -1,    -1,    -1,    53,    -1,    55,    -1,
      46,    47,    48,    -1,    -1,    -1,    -1,    53,    -1,    55,
      23,    24,    25,    26,    27,    28,    29,    30,    -1,    32,
      33,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      32,    33,    -1,    46,    47,    48,    -1,    -1,    -1,    -1,
      53,    -1,    55,    -1,    46,    47,    48,    -1,    -1,    -1,
      -1,    53,    -1,    55,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    32,    33,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    32,    33,    -1,    46,    47,    48,
      -1,    -1,    -1,    -1,    53,    -1,    55,    -1,    46,    47,
      48,    -1,    -1,    -1,    -1,    53,    -1,    55,    23,    24,
      25,    26,    27,    28,    29,    30,    -1,    32,    33,    23,
      24,    25,    26,    27,    28,    29,    30,    -1,    32,    33,
      -1,    46,    47,    48,    -1,    -1,    -1,    -1,    53,    -1,
      55,    -1,    46,    47,    48,    -1,    50,    -1,    -1,    -1,
      -1,    55,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    32,    33,    23,    24,    25,    26,    27,    28,    29,
      30,    -1,    32,    33,    -1,    46,    47,    48,    -1,    50,
      -1,    -1,    -1,    -1,    55,    -1,    46,    47,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    23,    24,    25,    26,
      27,    28,    29,    30,    -1,    32,    33,    23,    24,    25,
      26,    27,    28,    29,    30,    -1,    32,    33,    -1,    -1,
      -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    12,    57,    10,     0,    49,    50,    51,    58,    59,
       3,     4,     8,    11,    12,    13,    14,    15,    16,    17,
      18,    21,    31,    34,    35,    37,    38,    39,    49,    58,
      61,    62,    63,    65,    66,    54,    11,    11,    11,    11,
      66,    66,    11,    49,    66,    49,    49,    49,    51,    49,
      66,    60,    36,    61,    23,    24,    25,    26,    27,    28,
      29,    30,    32,    33,    46,    47,    48,    53,    55,    66,
      53,    54,    53,    54,    53,    54,    53,    54,    53,    54,
      66,    66,    66,    66,    59,    66,    50,    52,    58,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    50,    50,    50,    50,
      61,    53,    53,    53,    53,    53,    53,    58,    58,    51,
      42,    44,    64,    66,    59,    53,    53,    60,    53,    61,
      61,    61,    52,    66,    64,    64,    64,    37,    50,    60,
      49,    51,    52,    66,    59,    50,    61,    53,    64,    60,
      52
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    56,    57,    58,    59,    60,    61,    61,    62,    62,
      62,    63,    63,    63,    64,    64,    64,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     5,     0,     0,     2,     0,     5,     5,
       3,    10,    14,    12,     4,     4,     0,     2,     1,     1,
       1,     3,     3,     5,     5,     5,     5,     3,     3,     3,
       5,     3,     1,     4,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     2,
       2,     3,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
  case 2:
#line 81 "sintatica.y"
                        {
				
				cout << "/*Compilador InsaneLabz XGH*/\n" << "#include <iostream>\n#include<string.h>\n#include<math.h>\n#include<stdio.h>\nint main(void)\n{\n" << printtabelaSimbolos() << yyvsp[0].traducao  << "\treturn 0;\n}" << endl; 
				//printpilhasdeSimbolos();
			}
#line 1629 "y.tab.c"
    break;

  case 3:
#line 89 "sintatica.y"
                        {
				//escopototal.push(flag);
				//flag++;
				yyval.traducao = yyvsp[-2].traducao;
				//escopototal.pop();

			}
#line 1641 "y.tab.c"
    break;

  case 4:
#line 99 "sintatica.y"
            {
	            flag++; 
				escopototal.push(flag);
				yyval.traducao = "";
			}
#line 1651 "y.tab.c"
    break;

  case 5:
#line 107 "sintatica.y"
            {
				escopototal.pop();
				yyval.traducao = "";
			}
#line 1660 "y.tab.c"
    break;

  case 6:
#line 114 "sintatica.y"
                        {
				yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
			}
#line 1668 "y.tab.c"
    break;

  case 7:
#line 118 "sintatica.y"
                        {
				yyval.traducao = "";
			}
#line 1676 "y.tab.c"
    break;

  case 8:
#line 123 "sintatica.y"
                        {
				cont ++;
                yyval.label = gentempcode();
                addtabSimbolos(yyval.label,"int");
                yyval.traducao =yyvsp[-2].traducao + "\t" + yyval.label + " != " + yyvsp[-2].label + ";\n"; 
                yyval.traducao+="\tif(" + yyval.label + ") goto fim_if_Label" + to_string(cont) + ";\n" 
				+ yyvsp[0].traducao + "\tfim_if_Label"+ to_string(cont) + ":\n\n";
			}
#line 1689 "y.tab.c"
    break;

  case 9:
#line 132 "sintatica.y"
            {	
				cont ++;
                yyval.label = gentempcode();
                addtabSimbolos(yyval.label,"int");
                yyval.traducao = yyvsp[-2].traducao + "\t" + yyval.label + " != " + yyvsp[-2].label + ";\n"; 
                yyval.traducao+="\tif("+ yyval.label + ") goto fim_else_if_Label" + to_string(cont) + ";\n" 
				+ yyvsp[0].traducao + "\tfim_else_if_Label" + to_string(cont) + ":\n\n";
            }
#line 1702 "y.tab.c"
    break;

  case 10:
#line 141 "sintatica.y"
            {
                yyval.traducao= yyvsp[-2].traducao + "\tif(!" + yyvsp[-2].label + ") goto fim_else_Label" + to_string(cont) 
				+ ";\n" + yyvsp[0].traducao + "\tfim_else_Label" + to_string(cont) + ";\n\n";
            }
#line 1711 "y.tab.c"
    break;

  case 11:
#line 147 "sintatica.y"
            {
                yyval.label = gentempcode();
                string tempVar = gentempcode();
                addtabSimbolos(yyval.label,"int");

                //Adicionando na tabela de simbolos a temporária que verifica se while é verdadeiro.
                TIPO_SIMBOLO temp;
                temp.nomeVariavel = tempVar;
                temp.tipoVariavel = "int";
                temp.scope = escopototal;
                tabelaSimbolos.push_back(temp); 

                yyval.traducao ="inicio_while"+ to_string(cont) +":\n"+ yyvsp[-7].traducao + "\t" + yyval.label + " = " + yyvsp[-7].label + ";\n\t" + tempVar + " = !" + yyval.label + ";\n"; 
                yyval.traducao+="\tif(" + tempVar + ") goto fim_Label"+ to_string(cont)  +";\n" + yyvsp[-3].traducao + yyvsp[-2].traducao + "\tgoto inicio_while"+ to_string(cont) +";\n" +"fim_Label" + to_string(cont) + ":\n";
            }
#line 1731 "y.tab.c"
    break;

  case 12:
#line 163 "sintatica.y"
            {
                yyval.label = gentempcode();
                string tempVar = gentempcode();
                addtabSimbolos(yyval.label,"int");
                yyval.traducao ="inicio_for"+ to_string(cont) +":\n"+ yyvsp[-11].traducao + yyvsp[-9].traducao + "\t" + yyval.label + " = " + yyvsp[-9].label + ";\n\t" + tempVar + " = !" + yyval.label + ";\n"; 
                yyval.traducao+="\tif(" + tempVar + ") goto fim_Label"+ to_string(cont) +";\n" + yyvsp[-3].traducao + yyvsp[-2].traducao + yyvsp[-7].traducao +"\tgoto inicio_for"+ to_string(cont) +";\n" +"fim_Label" + to_string(cont) + ":\n\n";

                //Adicionando na tabela de simbolos a temporária que verifica se while é verdadeiro.
                TIPO_SIMBOLO temp;
                temp.nomeVariavel = tempVar;
                temp.tipoVariavel = "int";
                temp.scope = escopototal;
                tabelaSimbolos.push_back(temp);
            }
#line 1750 "y.tab.c"
    break;

  case 13:
#line 178 "sintatica.y"
            {
                yyval.label = gentempcode();
                string tempVar = gentempcode();
                addtabSimbolos(yyval.label,"int");

                yyval.traducao ="inicio_do_while"+ to_string(cont) +":\n"+ yyvsp[-8].traducao + yyvsp[-7].traducao; 
                yyval.traducao+=yyvsp[-2].traducao + "\tif(" + yyvsp[-2].label + ") goto inicio_do_while"+ to_string(cont) + "\n";
            }
#line 1763 "y.tab.c"
    break;

  case 14:
#line 190 "sintatica.y"
            {
                
                yyval.traducao = "\tgoto fim_Label" + to_string(cont) + ";\n" + yyvsp[-1].traducao + yyvsp[0].traducao;
            }
#line 1772 "y.tab.c"
    break;

  case 15:
#line 196 "sintatica.y"
            {
                yyval.traducao = "\tgoto fim_Label" + to_string(cont) + ";\n" + yyvsp[-1].traducao + yyvsp[0].traducao;
            }
#line 1780 "y.tab.c"
    break;

  case 16:
#line 200 "sintatica.y"
            {
                cont ++;
                yyval.traducao = "";
            }
#line 1789 "y.tab.c"
    break;

  case 20:
#line 218 "sintatica.y"
                        {
				yyval = yyvsp[0];
			}
#line 1797 "y.tab.c"
    break;

  case 21:
#line 222 "sintatica.y"
                        {
				TIPO_SIMBOLO valor;
				valor.nomeVariavel = yyvsp[-1].label;
				valor.tipoVariavel = "int";
				valor.nomeTemp = gentempcode(); valor.scope = escopototal;
				for(int i = 0; i < tabelaSimbolos.size(); i++)
				{
					if(tabelaSimbolos[i].nomeVariavel == valor.nomeVariavel)
					{
					    if(tabelaSimbolos[i].scope.top() == escopototal.top())
					    {
						    yyerror("Variavel ja declarada");
					    }
					}
				}
				tabelaSimbolos.push_back(valor);

				yyval.traducao = "";
				yyval.label = "";
			}
#line 1822 "y.tab.c"
    break;

  case 22:
#line 243 "sintatica.y"
                        {
				TIPO_SIMBOLO valor;
				valor.nomeVariavel = yyvsp[-1].label;
				valor.tipoVariavel = "int";
				valor.nomeTemp = gentempcode(); valor.scope = escopototal;
				for(int i = 0; i < tabelaSimbolos.size(); i++)
				{
					if(tabelaSimbolos[i].nomeVariavel == valor.nomeVariavel)
					{
					    if(tabelaSimbolos[i].scope.top() == escopototal.top())
					    {
						    yyerror("Variavel ja declarada");
					    }
					}
				}
				tabelaSimbolos.push_back(valor);
                
				yyval.traducao = "";
				yyval.label = "";
			}
#line 1847 "y.tab.c"
    break;

  case 23:
#line 263 "sintatica.y"
                                                      {
				TIPO_SIMBOLO valor;
				valor.nomeVariavel = yyvsp[-3].label;
				valor.tipoVariavel = "int";
				valor.nomeTemp = gentempcode(); valor.scope = escopototal;
				for(int i = 0; i < tabelaSimbolos.size(); i++)
				{
					if(tabelaSimbolos[i].nomeVariavel == valor.nomeVariavel)
					{
					    if(tabelaSimbolos[i].scope.top() == escopototal.top())
					    {
						    yyerror("Variavel ja declarada");
					    }
					}
				}
				tabelaSimbolos.push_back(valor);
                yyvsp[-3].label = valor.nomeTemp;
				yyvsp[-3].tipo = valor.tipoVariavel;
				yyval.traducao = yyvsp[-1].traducao + "\t" + yyvsp[-3].label + " = " + yyvsp[-1].label + ";\n";
				yyval.label = "";
			}
#line 1873 "y.tab.c"
    break;

  case 24:
#line 286 "sintatica.y"
                        {
				TIPO_SIMBOLO valor;
				valor.nomeVariavel = yyvsp[-3].label;
				valor.tipoVariavel = "int";
				valor.nomeTemp = gentempcode(); valor.scope = escopototal;
				for(int i = 0; i < tabelaSimbolos.size(); i++)
				{
					if(tabelaSimbolos[i].nomeVariavel == valor.nomeVariavel)
					{
					    if(tabelaSimbolos[i].scope.top() == escopototal.top())
					    {
						    yyerror("Variavel ja declarada");
					    }
					}
				}
				tabelaSimbolos.push_back(valor);
                yyvsp[-3].label = valor.nomeTemp;
				yyvsp[-3].tipo = valor.tipoVariavel;
				yyval.traducao = yyvsp[-1].traducao + "\t" + yyvsp[-3].label + " = " + yyvsp[-1].label + ";\n";
				yyval.label = "";
			}
#line 1899 "y.tab.c"
    break;

  case 25:
#line 308 "sintatica.y"
                        {
				TIPO_SIMBOLO valor;
				valor.nomeVariavel = yyvsp[-3].label;
				valor.tipoVariavel = "char";
				valor.nomeTemp = gentempcode(); valor.scope = escopototal;
				for(int i = 0; i < tabelaSimbolos.size(); i++)
				{
					if(tabelaSimbolos[i].nomeVariavel == valor.nomeVariavel)
					{
					    if(tabelaSimbolos[i].scope.top() == escopototal.top())
					    {
						    yyerror("Variavel ja declarada");
					    }
					}
				}
				tabelaSimbolos.push_back(valor);
                yyvsp[-3].label = valor.nomeTemp;
				yyvsp[-3].tipo = valor.tipoVariavel;
				yyval.traducao = yyvsp[-1].traducao + "\t" + yyvsp[-3].label + " = " + yyvsp[-1].label + ";\n";
				yyval.label = "";
			}
#line 1925 "y.tab.c"
    break;

  case 26:
#line 330 "sintatica.y"
                        {
				TIPO_SIMBOLO valor;
				valor.nomeVariavel = yyvsp[-3].label;
				valor.tipoVariavel = "float";
				valor.nomeTemp = gentempcode(); valor.scope = escopototal;
				for(int i = 0; i < tabelaSimbolos.size(); i++)
				{
					if(tabelaSimbolos[i].nomeVariavel == valor.nomeVariavel)
					{
					    if(tabelaSimbolos[i].scope.top() == escopototal.top())
					    {
						    yyerror("Variavel ja declarada");
					    }
					}
				}
				tabelaSimbolos.push_back(valor);

                yyvsp[-3].label = valor.nomeTemp;
				yyvsp[-3].tipo = valor.tipoVariavel;
				yyval.traducao = yyvsp[-1].traducao + "\t" + yyvsp[-3].label + " = " + yyvsp[-1].label + ";\n";
				yyval.label = "";
			}
#line 1952 "y.tab.c"
    break;

  case 27:
#line 353 "sintatica.y"
                        {
				TIPO_SIMBOLO valor;
				valor.nomeVariavel = yyvsp[-1].label;
				valor.tipoVariavel = "float";
				valor.nomeTemp = gentempcode(); valor.scope = escopototal;
				for(int i = 0; i < tabelaSimbolos.size(); i++)
				{
					if(tabelaSimbolos[i].nomeVariavel == valor.nomeVariavel)
					{
					    if(tabelaSimbolos[i].scope.top() == escopototal.top())
					    {
						    yyerror("Variavel ja declarada");
					    }
					}
				}
				tabelaSimbolos.push_back(valor);
                
				yyval.traducao = "";
				yyval.label = "";
			}
#line 1977 "y.tab.c"
    break;

  case 28:
#line 374 "sintatica.y"
                        {
				TIPO_SIMBOLO valor;
				valor.nomeVariavel = yyvsp[-1].label;
				valor.tipoVariavel = "char";
				valor.nomeTemp = gentempcode(); valor.scope = escopototal;
				for(int i = 0; i < tabelaSimbolos.size(); i++)
				{
					if(tabelaSimbolos[i].nomeVariavel == valor.nomeVariavel)
					{
					    if(tabelaSimbolos[i].scope.top() == escopototal.top())
					    {
						    yyerror("Variavel ja declarada");
					    }
					}
				}
				tabelaSimbolos.push_back(valor);

				yyval.traducao = "";
				yyval.label = "";
			}
#line 2002 "y.tab.c"
    break;

  case 29:
#line 395 "sintatica.y"
                        {
				TIPO_SIMBOLO valor;
				valor.nomeVariavel = yyvsp[-1].label;
				valor.tipoVariavel =  "char*";
				valor.nomeTemp = gentempcode()  ; valor.scope = escopototal;
				for(int i = 0; i < tabelaSimbolos.size(); i++)
				{
					if(tabelaSimbolos[i].nomeVariavel == valor.nomeVariavel)
					{
					    if(tabelaSimbolos[i].scope.top() == escopototal.top())
					    {
						    yyerror("Variavel ja declarada");
					    }
					}
				}
				tabelaSimbolos.push_back(valor);

				yyval.traducao = "";
				yyval.label = "";
			}
#line 2027 "y.tab.c"
    break;

  case 30:
#line 416 "sintatica.y"
                        {
				std::string str (yyvsp[-1].label);
				string a = '['+ std::to_string(str.length()-1)+']';
				TIPO_SIMBOLO valor;
				//string a = '['+ $3.label +']';
				valor.nomeVariavel = yyvsp[-3].label;
				valor.tipoVariavel = "char";
				valor.size = a;
				valor.nomeTemp = gentempcode(); valor.scope = escopototal;
				for(int i = 0; i < tabelaSimbolos.size(); i++)
				{
					if(tabelaSimbolos[i].nomeVariavel == valor.nomeVariavel)
					{
					    if(tabelaSimbolos[i].scope.top() == escopototal.top())
					    {
						    yyerror("Variavel ja declarada");
					    }
					}
				}
				tabelaSimbolos.push_back(valor);
                yyvsp[-3].label = valor.nomeTemp;
				yyvsp[-3].tipo = valor.tipoVariavel;
				yyval.traducao = yyvsp[-1].traducao + "\t" + "strcpy" + '(' + yyvsp[-3].label + " , " + yyvsp[-1].label + ')'  + ";\n";
				yyval.label = "";
			}
#line 2057 "y.tab.c"
    break;

  case 31:
#line 444 "sintatica.y"
            {
			    yyval = yyvsp[-1];
			}
#line 2065 "y.tab.c"
    break;

  case 32:
#line 448 "sintatica.y"
                        {
				yyval.label = yyvsp[0].label;
				yyvsp[0].tipo = "string";
				yyval = yyvsp[0];
			}
#line 2075 "y.tab.c"
    break;

  case 33:
#line 454 "sintatica.y"
                        {
				if(yyvsp[-1].tipo == "string")
				{
                    yyval.traducao = yyvsp[-1].traducao + "\t" + "print"+ "f("+  yyvsp[-1].label + ")"+ ";\n";
				}
				else
				{
				    switch(yyvsp[-1].tipo[0])
					{
						case 'i':
						yyval.traducao = yyvsp[-1].traducao + "\t" + "print"+ "f("+ '%' + "d,"+ yyvsp[-1].label + ')'+ ";\n";
						break;
						case 'c':
						yyval.traducao = yyvsp[-1].traducao +"\t" + "print"+ "f("+ '%' + "c,"+ yyvsp[-1].label + ')'+ ";\n";
						break;
						case 'f':
						yyval.traducao = yyvsp[-1].traducao +"\t" + "print"+ "f("+ '%' + "f,"+ yyvsp[-1].label + ')'+ ";\n";
						break;
					}
				}
			}
#line 2101 "y.tab.c"
    break;

  case 34:
#line 476 "sintatica.y"
                        {
				if(yyvsp[-2].tipo == "char" || yyvsp[-2].tipo == "char*")
				{
					std::string str (yyvsp[-2].label);
					std::string str2 (yyvsp[0].label);
				    string a = "char";
					string temp = gentempcode();
					yyval.label = temp + '['+ std::to_string((str.length() + str2.length())*100)+']';
				    addtabSimbolos( yyval.label, a);
                    yyval.traducao = yyvsp[0].traducao + "\t"+ temp + '=' + "strcat" + '(' + yyvsp[-2].label + " , " + yyvsp[0].label + ')'  + ";\n";
				}
				else{
				if(yyvsp[-2].tipo != yyvsp[0].tipo) //default = tipo float mas talvez precise mudar
				{
					if(yyvsp[-2].tipo == "int" && yyvsp[0].tipo == "float") 
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						yyval.label = gentempcode();
				        addtabSimbolos( yyval.label, "float");
				        yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + castvar + " = " + "(float)" + yyvsp[-2].label + ";\n" + "\t" + yyval.label +
					    " = " + castvar + " + " + yyvsp[0].label + ";\n";
					}
					else if(yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int")
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						yyval.label = gentempcode();
				        addtabSimbolos( yyval.label, "float");
				        yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + castvar + " = " + "(float)" + yyvsp[0].label + ";\n" + "\t" + yyval.label +
					    " = " + yyvsp[-2].label + " + " + castvar + ";\n";
					}
				}
				else{
				yyval.label = gentempcode();
				addtabSimbolos( yyval.label, yyvsp[-2].tipo);
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label +
					" = " + yyvsp[-2].label + " + " + yyvsp[0].label + ";\n";
				}}
			}
#line 2146 "y.tab.c"
    break;

  case 35:
#line 517 "sintatica.y"
                        {
				if(yyvsp[-2].tipo != yyvsp[0].tipo) //default = tipo float mas talvez precise mudar
				{
					if(yyvsp[-2].tipo == "int" && yyvsp[0].tipo == "float") 
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						yyval.label = gentempcode();
				        addtabSimbolos( yyval.label, "float");
				        yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + castvar + " = " + "(float)" + yyvsp[-2].label + ";\n" + "\t" + yyval.label +
					    " = " + castvar + " - " + yyvsp[0].label + ";\n";
					}
					else if(yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int")
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						yyval.label = gentempcode();
				        addtabSimbolos( yyval.label, "float");
				        yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + castvar + " = " + "(float)" + yyvsp[0].label + ";\n" + "\t" + yyval.label +
					    " = " + yyvsp[-2].label + " - " + castvar + ";\n";
					}
				}
				else{
				yyval.label = gentempcode();
				addtabSimbolos(yyval.label, yyvsp[-2].tipo);
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label +
					" = " + yyvsp[-2].label + " - " + yyvsp[0].label + ";\n";
				}
			}
#line 2180 "y.tab.c"
    break;

  case 36:
#line 547 "sintatica.y"
                        {
				if(yyvsp[-2].tipo != yyvsp[0].tipo) //default = tipo float mas talvez precise mudar
				{
					if(yyvsp[-2].tipo == "int" && yyvsp[0].tipo == "float") 
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						yyval.label = gentempcode();
				        addtabSimbolos( yyval.label, "float");
				        yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + castvar + " = " + "(float)" + yyvsp[-2].label + ";\n" + "\t" + yyval.label +
					    " = " + castvar + " * " + yyvsp[0].label + ";\n";
					}
					else if(yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int")
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						yyval.label = gentempcode();
				        addtabSimbolos( yyval.label, "float");
				        yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + castvar + " = " + "(float)" + yyvsp[0].label + ";\n" + "\t" + yyval.label +
					    " = " + yyvsp[-2].label + " * " + castvar + ";\n";
					}
				}
				else{
				yyval.label = gentempcode();
				addtabSimbolos(yyval.label, yyvsp[-2].tipo);
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label +
					" = " + yyvsp[-2].label + " * " + yyvsp[0].label + ";\n";
				}
			}
#line 2214 "y.tab.c"
    break;

  case 37:
#line 577 "sintatica.y"
                        {
				if(yyvsp[-2].tipo != yyvsp[0].tipo) //default = tipo float mas talvez precise mudar
				{
					if(yyvsp[-2].tipo == "int" && yyvsp[0].tipo == "float") 
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						yyval.label = gentempcode();
				        addtabSimbolos( yyval.label, "float");
				        yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + castvar + " = " + "(float)" + yyvsp[-2].label + ";\n" + "\t" + yyval.label +
					    " = " + castvar + " / " + yyvsp[0].label + ";\n";
					}
					else if(yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int")
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						yyval.label = gentempcode();
				        addtabSimbolos( yyval.label, "float");
				        yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + castvar + " = " + "(float)" + yyvsp[0].label + ";\n" + "\t" + yyval.label +
					    " = " + yyvsp[-2].label + " / " + castvar + ";\n";
					}
				}
				else{
				yyval.label = gentempcode();
				addtabSimbolos(yyval.label, yyvsp[-2].tipo);
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao  + "\t" + yyval.label +
					" = " + yyvsp[-2].label + " / " + yyvsp[0].label + ";\n";
				}
			}
#line 2248 "y.tab.c"
    break;

  case 38:
#line 607 "sintatica.y"
                        {	
				// if ($1.tipo != "bool"){
                //     yyerror("ERRO! Operação inválida");
                // }
                // if ($3.tipo != "bool"){
                //     yyerror("ERRO! Operação inválida");
                // }
				// if($1.tipo != $3.tipo) 
				{
					if(yyvsp[-2].tipo == "int" && yyvsp[0].tipo == "float")  // mudar para a variavel final ser bool ao inves do tipo convertido
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						yyval.label = gentempcode();
				        addtabSimbolos( yyval.label, "float");
				        yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + castvar + " = " + "(float)" + yyvsp[-2].label + ";\n" + "\t" + yyval.label +
					    " = " + castvar + " == " + yyvsp[0].label + ";\n";
					}
					else if(yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int")
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						yyval.label = gentempcode();
				        addtabSimbolos( yyval.label, "float");
				        yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + castvar + " = " + "(float)" + yyvsp[-2].label + ";\n" + "\t" + yyval.label +
					    " = " + castvar + " == " + yyvsp[0].label + ";\n";
					}
				} 
			}
#line 2282 "y.tab.c"
    break;

  case 39:
#line 637 "sintatica.y"
                        {
				if (yyvsp[-2].tipo != "bool"){
                    yyerror("ERRO! Operação inválida");
                }
                if (yyvsp[0].tipo != "bool"){
                    yyerror("ERRO! Operação inválida");
                }
				if(yyvsp[-2].tipo != yyvsp[0].tipo) 
				{
					if(yyvsp[-2].tipo == "int" && yyvsp[0].tipo == "float")  // mudar para a variavel final ser bool ao inves do tipo convertido
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						yyval.label = gentempcode();
				        addtabSimbolos( yyval.label, "float");
				        yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + castvar + " = " + "(float)" + yyvsp[-2].label + ";\n" + "\t" + yyval.label +
					    " = " + castvar + " != " + yyvsp[0].label + ";\n";
					}
					else if(yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int")
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						yyval.label = gentempcode();
				        addtabSimbolos( yyval.label, "float");
				        yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + castvar + " = " + "(float)" + yyvsp[-2].label + ";\n" + "\t" + yyval.label +
					    " = " + castvar + " != " + yyvsp[0].label + ";\n";
					}
				} 
				
			}
#line 2317 "y.tab.c"
    break;

  case 40:
#line 668 "sintatica.y"
                        {
				// if ($1.tipo != "bool"){
                //     yyerror("ERRO! Operação inválida");
                // }
                // if ($3.tipo != "bool"){
                //     yyerror("ERRO! Operação inválida");
                // }
				if(yyvsp[-2].tipo != yyvsp[0].tipo) 
				{
					if(yyvsp[-2].tipo == "int" && yyvsp[0].tipo == "float")  // mudar para a variavel final ser bool ao inves do tipo convertido
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						yyval.label = gentempcode();
				        addtabSimbolos( yyval.label, "float");
				        yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + castvar + " = " + "(float)" + yyvsp[-2].label + ";\n" + "\t" + yyval.label +
					    " = " + castvar + " > " + yyvsp[0].label + ";\n";
					}
					else if(yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int")
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						yyval.label = gentempcode();
				        addtabSimbolos( yyval.label, "float");
				        yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + castvar + " = " + "(float)" + yyvsp[-2].label + ";\n" + "\t" + yyval.label +
					    " = " + castvar + " > " + yyvsp[0].label + ";\n";
					} 
				} else {
						yyval.label = gentempcode();
						yyval.tipo = yyvsp[-2].tipo;
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + // a = $1, b = $3, c = $$ 
						" = " + yyvsp[-2].label + " > " + yyvsp[0].label + ";\n";  // caracter = " < "
						// Atualizar tipo da temporária com base nos tipos dos operandos
						TIPO_SIMBOLO temp;
						temp.nomeVariavel = yyval.label;
						temp.scope = escopototal;
						temp.tipoVariavel = yyval.tipo;
						tabelaSimbolos.push_back(temp);
					}
			}
#line 2362 "y.tab.c"
    break;

  case 41:
#line 709 "sintatica.y"
                        {
				// if ($1.tipo != "bool"){
                //     yyerror("ERRO! Operação inválida");
                // }
                // if ($3.tipo != "bool"){
                //     yyerror("ERRO! Operação inválida");
                // }
				if(yyvsp[-2].tipo != yyvsp[0].tipo) 
				{
					if(yyvsp[-2].tipo == "int" && yyvsp[0].tipo == "float")  // mudar para a variavel final ser bool ao inves do tipo convertido
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						yyval.label = gentempcode();
				        addtabSimbolos( yyval.label, "float");
				        yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + castvar + " = " + "(float)" + yyvsp[-2].label + ";\n" + "\t" + yyval.label +
					    " = " + castvar + " < " + yyvsp[0].label + ";\n";
					}
					else if(yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int")
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						yyval.label = gentempcode();
				        addtabSimbolos( yyval.label, "float");
				        yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + castvar + " = " + "(float)" + yyvsp[-2].label + ";\n" + "\t" + yyval.label +
					    " = " + castvar + " < " + yyvsp[0].label + ";\n";
					}
				} else {
					yyval.label = gentempcode();
					yyval.tipo = yyvsp[-2].tipo;
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + // a = $1, b = $3, c = $$ 
						" = " + yyvsp[-2].label + " < " + yyvsp[0].label + ";\n";  // caracter = " < "
					// Atualizar tipo da temporária com base nos tipos dos operandos
					TIPO_SIMBOLO temp;
					temp.nomeVariavel = yyval.label;
					temp.scope = escopototal;
					temp.tipoVariavel = yyval.tipo;
					tabelaSimbolos.push_back(temp);
				}
			}
#line 2407 "y.tab.c"
    break;

  case 42:
#line 750 "sintatica.y"
                        {	
				// if ($1.tipo != "bool"){
                //     yyerror("ERRO! Operação inválida");
                // }
                // if ($3.tipo != "bool"){
                //     yyerror("ERRO! Operação inválida");
                // }
				if(yyvsp[-2].tipo != yyvsp[0].tipo) {
					if(yyvsp[-2].tipo == "int" && yyvsp[0].tipo == "float")  // mudar para a variavel final ser bool ao inves do tipo convertido
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						yyval.label = gentempcode();
				        addtabSimbolos( yyval.label, "float");
				        yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + castvar + " = " + "(float)" + yyvsp[-2].label + ";\n" + "\t" + yyval.label +
					    " = " + castvar + " >= " + yyvsp[0].label + ";\n";
					}
					else if(yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int")
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						yyval.label = gentempcode();
				        addtabSimbolos( yyval.label, "float");
				        yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + castvar + " = " + "(float)" + yyvsp[-2].label + ";\n" + "\t" + yyval.label +
					    " = " + castvar + " >= " + yyvsp[0].label + ";\n";
					}
				} 
				else {
					yyval.label = gentempcode();
					yyval.tipo = yyvsp[-2].tipo;
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + // a = $1, b = $3, c = $$ 
						" = " + yyvsp[-2].label + " >= " + yyvsp[0].label + ";\n";  // caracter = " < "
					// Atualizar tipo da temporária com base nos tipos dos operandos
					TIPO_SIMBOLO temp;
					temp.nomeVariavel = yyval.label;
					temp.scope = escopototal;
					temp.tipoVariavel = yyval.tipo;
					tabelaSimbolos.push_back(temp);
				}
			}
#line 2452 "y.tab.c"
    break;

  case 43:
#line 792 "sintatica.y"
                        {
				// if ($1.tipo != "bool"){
                //     yyerror("ERRO! Operação inválida");
                // }
                // if ($3.tipo != "bool"){
                //     yyerror("ERRO! Operação inválida");
                // }
				if(yyvsp[-2].tipo != yyvsp[0].tipo) 
				{
					if(yyvsp[-2].tipo == "int" && yyvsp[0].tipo == "float")  // mudar para a variavel final ser bool ao inves do tipo convertido
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						yyval.label = gentempcode();
				        addtabSimbolos( yyval.label, "float");
				        yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + castvar + " = " + "(float)" + yyvsp[-2].label + ";\n" + "\t" + yyval.label +
					    " = " + castvar + " <= " + yyvsp[0].label + ";\n";
					}
					else if(yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int")
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						yyval.label = gentempcode();
				        addtabSimbolos( yyval.label, "float");
				        yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + castvar + " = " + "(float)" + yyvsp[-2].label + ";\n" + "\t" + yyval.label +
					    " = " + castvar + " <= " + yyvsp[0].label + ";\n";
					}
				} else {
					yyval.label = gentempcode();
					yyval.tipo = yyvsp[-2].tipo;
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + // a = $1, b = $3, c = $$ 
						" = " + yyvsp[-2].label + " <= " + yyvsp[0].label + ";\n";  // caracter = " < "
					// Atualizar tipo da temporária com base nos tipos dos operandos
					TIPO_SIMBOLO temp;
					temp.nomeVariavel = yyval.label;
					temp.scope = escopototal;
					temp.tipoVariavel = yyval.tipo;
					tabelaSimbolos.push_back(temp);
				}
			}
#line 2497 "y.tab.c"
    break;

  case 44:
#line 833 "sintatica.y"
                        {	
				if (yyvsp[-2].tipo != "bool"){
                    yyerror("ERRO! Operação inválida");
                }
                if (yyvsp[0].tipo != "bool"){
                    yyerror("ERRO! Operação inválida");
                }
				if(yyvsp[-2].tipo != yyvsp[0].tipo) 
				{
					if(yyvsp[-2].tipo == "int" && yyvsp[0].tipo == "float")  // mudar para a variavel final ser bool ao inves do tipo convertido
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						yyval.label = gentempcode();
				        addtabSimbolos( yyval.label, "float");
				        yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + castvar + " = " + "(float)" + yyvsp[-2].label + ";\n" + "\t" + yyval.label +
					    " = " + castvar + " && " + yyvsp[0].label + ";\n";
					}
					else if(yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int")
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						yyval.label = gentempcode();
				        addtabSimbolos( yyval.label, "float");
				        yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + castvar + " = " + "(float)" + yyvsp[-2].label + ";\n" + "\t" + yyval.label +
					    " = " + castvar + " && " + yyvsp[0].label + ";\n";
					}
				} else {
					yyval.label = gentempcode();
					yyval.tipo = yyvsp[-2].tipo;
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + // a = $1, b = $3, c = $$ 
						" = " + yyvsp[-2].label + " && " + yyvsp[0].label + ";\n";  // caracter = " < "
					// Atualizar tipo da temporária com base nos tipos dos operandos
					TIPO_SIMBOLO temp;
					temp.nomeVariavel = yyval.label;
					temp.scope = escopototal;
					temp.tipoVariavel = yyval.tipo;
					tabelaSimbolos.push_back(temp);
				}
			}
#line 2542 "y.tab.c"
    break;

  case 45:
#line 874 "sintatica.y"
                        {	
				if (yyvsp[-2].tipo != "bool"){
                    yyerror("ERRO! Operação inválida");
                }
                if (yyvsp[0].tipo != "bool"){
                    yyerror("ERRO! Operação inválida");
                }
				if(yyvsp[-2].tipo != yyvsp[0].tipo) 
				{
					if(yyvsp[-2].tipo == "int" && yyvsp[0].tipo == "float")  // mudar para a variavel final ser bool ao inves do tipo convertido
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						yyval.label = gentempcode();
				        addtabSimbolos( yyval.label, "float");
				        yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + castvar + " = " + "(float)" + yyvsp[-2].label + ";\n" + "\t" + yyval.label +
					    " = " + castvar + " || " + yyvsp[0].label + ";\n";
					}
					else if(yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int")
					{
						string castvar = gentempcode();
				        addtabSimbolos( castvar, "float");
						yyval.label = gentempcode();
				        addtabSimbolos( yyval.label, "float");
				        yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + castvar + " = " + "(float)" + yyvsp[-2].label + ";\n" + "\t" + yyval.label +
					    " = " + castvar + " || " + yyvsp[0].label + ";\n";
					}
				} else {
					yyval.label = gentempcode();
					yyval.tipo = yyvsp[-2].tipo;
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + // a = $1, b = $3, c = $$ 
						" = " + yyvsp[-2].label + " || " + yyvsp[0].label + ";\n";  // caracter = " < "
					// Atualizar tipo da temporária com base nos tipos dos operandos
					TIPO_SIMBOLO temp;
					temp.nomeVariavel = yyval.label;
					temp.scope = escopototal;
					temp.tipoVariavel = yyval.tipo;
					tabelaSimbolos.push_back(temp);
				}
			}
#line 2587 "y.tab.c"
    break;

  case 46:
#line 915 "sintatica.y"
                        {	
				yyval.label = gentempcode();
				yyval.traducao = yyvsp[0].traducao + "\t" + yyval.label +
				" = ! " + yyvsp[0].label + ";\n"; 
			}
#line 2597 "y.tab.c"
    break;

  case 47:
#line 921 "sintatica.y"
                        {
				yyval.label = gentempcode();
				yyval.tipo = "int";
				if(yyvsp[-1].tipo != "int")
				{
					yyerror("Operacao invalida: incrementar variavel nao inteira");
				} else {
					addtabSimbolos(yyval.label, yyval.tipo);
				}
				yyval.traducao = yyvsp[-1].traducao + "\t" + yyval.label + " = " + yyvsp[-1].label + " + 1;\n";

			}
#line 2614 "y.tab.c"
    break;

  case 48:
#line 934 "sintatica.y"
                        {
				yyval.label = gentempcode();
				yyval.tipo = "int";
				if(yyvsp[-1].tipo != "int")
				{
					yyerror("Operacao invalida: decrementar variavel nao inteira");
				} else {
					addtabSimbolos(yyval.label, yyval.tipo);
				}
				yyval.traducao = yyvsp[-1].traducao + "\t" + yyval.label + " = " + yyvsp[-1].label + " - 1;\n";
			}
#line 2630 "y.tab.c"
    break;

  case 49:
#line 946 "sintatica.y"
                        {
				if(yyvsp[0].tipo == "float")
				{
					yyvsp[0].label = "(int)" + yyvsp[0].label;
					yyvsp[0].tipo = "int";
				}
				yyval.label = gentempcode();
				yyval.tipo = "int";
				yyval.traducao = yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
			}
#line 2645 "y.tab.c"
    break;

  case 50:
#line 957 "sintatica.y"
                        {
				if(yyvsp[0].tipo == "int")
				{
					yyvsp[0].label = "(float)" + yyvsp[0].label;
					yyvsp[0].tipo = "float";
				}
				yyval.label = gentempcode();
				yyval.tipo = "float";
				yyval.traducao = yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
			}
#line 2660 "y.tab.c"
    break;

  case 51:
#line 968 "sintatica.y"
                        {
				bool encontrei = false;
				TIPO_SIMBOLO variavel;
				stack<int> ordem = escopototal;
                set<int> referencias;
                //int bob;
                bool fin;
                while(!ordem.empty()){
                    //bob = ordem.pop();
                    referencias.insert(ordem.top());
                    ordem.pop();
                }
                for(int i = 0; i < tabelaSimbolos.size(); i++){
                    fin = referencias.find(tabelaSimbolos[i].scope.top()) != referencias.end();
                    if(tabelaSimbolos[i].nomeVariavel == yyvsp[-2].label  && tabelaSimbolos[i].scope.size() <= escopototal.size() && fin == true){
                        variavel = tabelaSimbolos[i];
                        encontrei = true;
                    }
                }
				if(!encontrei){
					yyerror("Variavel nao declarada");
				}
				if(yyvsp[0].tipo == "string")
				{
					yyvsp[-2].label = variavel.nomeTemp;
					std::string criativo (yyvsp[0].label);
					string tamanho = std::to_string(criativo.length()-1); 
                    yyval.traducao = "\t" + yyvsp[-2].label + '=' + "malloc" + '(' + tamanho + '*' + "sizeof(char*)" + ')' + ";\n" + yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + "strcpy(" + yyvsp[-2].label + " , " + yyvsp[0].label + ')' + ";\n";
				}
				else
				{
				    yyvsp[-2].label = variavel.nomeTemp;
				    yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" +  yyvsp[-2].label + " = " + yyvsp[0].label + ";\n";
				}
			}
#line 2700 "y.tab.c"
    break;

  case 52:
#line 1004 "sintatica.y"
                        {	

				yyval.tipo = "int";
				yyval.label = gentempcode();
				addtabSimbolos(yyval.label, yyval.tipo);
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
			}
#line 2712 "y.tab.c"
    break;

  case 53:
#line 1012 "sintatica.y"
                        {
				yyval.tipo = "float";
				yyval.label = gentempcode();
				addtabSimbolos(yyval.label, yyval.tipo);
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
			}
#line 2723 "y.tab.c"
    break;

  case 54:
#line 1027 "sintatica.y"
                        {
				if (yyvsp[0].label == "true" || yyvsp[0].label == "false"){
					yyval.tipo = "bool"; 
					yyval.label = gentempcode();
					addtabSimbolos(yyval.label, yyval.tipo);
					yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
				} 
				else {
					bool encontrei = false;
				TIPO_SIMBOLO variavel;
				stack<int> ordem = escopototal;
                set<int> referencias;
                //int bob;
                bool fin;
                while(!ordem.empty()){
                    //bob = ordem.pop();
                    referencias.insert(ordem.top());
                    ordem.pop();
                }
                for(int i = 0; i < tabelaSimbolos.size(); i++){
                    fin = referencias.find(tabelaSimbolos[i].scope.top()) != referencias.end();
                    if(tabelaSimbolos[i].nomeVariavel == yyvsp[0].label  && tabelaSimbolos[i].scope.size() <= escopototal.size() && fin == true){
                        variavel = tabelaSimbolos[i];
                        encontrei = true;
                    }
                }
				if(!encontrei){
					if(yyvsp[0].label == "true" || yyvsp[0].label == "false"){
						yyval.tipo = "bool";
					} else {
						yyerror("Variavel nao declarada");
					}
				}
                yyvsp[0].label = variavel.nomeTemp;
				yyval.tipo = variavel.tipoVariavel;
				yyval.label = gentempcode();
				addtabSimbolos(yyval.label, yyval.tipo);
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
				}
			}
#line 2768 "y.tab.c"
    break;


#line 2772 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
  return yyresult;
}
#line 1069 "sintatica.y"


#include "lex.yy.c"

int yyparse();

string gentempcode(){
	var_temp_qnt++;
	return "t" + std::to_string(var_temp_qnt);
}

int main( int argc, char* argv[] )
{
    flag = 0;
	var_temp_qnt = 0;
    escopototal.push(flag);
	yyparse();
    //cout << printtabelaSimbolos();
	return 0;
}

void yyerror( string MSG )
{
	cout << MSG << endl;
	exit (0);
}				
