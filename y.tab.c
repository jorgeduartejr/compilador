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
		n += "\t" + tabelaSimbolos[i].tipoVariavel + "\t" + tabelaSimbolos[i].nomeTemp + ";\n";
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

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TK_NUM = 258,                  /* TK_NUM  */
    TK_REAL = 259,                 /* TK_REAL  */
    TK_BOOL = 260,                 /* TK_BOOL  */
    TK_CHAR = 261,                 /* TK_CHAR  */
    TK_OP_REL = 262,               /* TK_OP_REL  */
    TK_STRING = 263,               /* TK_STRING  */
    _STRING = 264,                 /* _STRING  */
    TK_MAIN = 265,                 /* TK_MAIN  */
    TK_ID = 266,                   /* TK_ID  */
    TK_TIPO_INT = 267,             /* TK_TIPO_INT  */
    TK_TIPO_FLOAT = 268,           /* TK_TIPO_FLOAT  */
    TK_TIPO_CHAR = 269,            /* TK_TIPO_CHAR  */
    TK_TIPO_BOOL = 270,            /* TK_TIPO_BOOL  */
    TK_CAST_INT = 271,             /* TK_CAST_INT  */
    TK_CAST_FLOAT = 272,           /* TK_CAST_FLOAT  */
    TK_TIPO_STRING = 273,          /* TK_TIPO_STRING  */
    TK_FIM = 274,                  /* TK_FIM  */
    TK_ERROR = 275,                /* TK_ERROR  */
    TK_IG = 276,                   /* TK_IG  */
    TK_DIF = 277,                  /* TK_DIF  */
    TK_MAIG = 278,                 /* TK_MAIG  */
    TK_MEIG = 279,                 /* TK_MEIG  */
    TK_MAIOR = 280,                /* TK_MAIOR  */
    TK_MENOR = 281,                /* TK_MENOR  */
    TK_AND = 282,                  /* TK_AND  */
    TK_OR = 283,                   /* TK_OR  */
    TK_NOT = 284,                  /* TK_NOT  */
    TK_MAIS_MAIS = 285,            /* TK_MAIS_MAIS  */
    TK_MENOS_MENOS = 286,          /* TK_MENOS_MENOS  */
    TK_IF = 287,                   /* TK_IF  */
    TK_ELSE_IF = 288,              /* TK_ELSE_IF  */
    TK_ELSE = 289,                 /* TK_ELSE  */
    TK_WHILE = 290,                /* TK_WHILE  */
    TK_DO = 291,                   /* TK_DO  */
    TK_FOR = 292,                  /* TK_FOR  */
    TK_SWITCH = 293,               /* TK_SWITCH  */
    TK_CASE = 294,                 /* TK_CASE  */
    TK_BREAK = 295,                /* TK_BREAK  */
    TK_DEFAULT = 296,              /* TK_DEFAULT  */
    TK_CONTINUE = 297,             /* TK_CONTINUE  */
    TK_RETURN = 298                /* TK_RETURN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
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
#define TK_IG 276
#define TK_DIF 277
#define TK_MAIG 278
#define TK_MEIG 279
#define TK_MAIOR 280
#define TK_MENOR 281
#define TK_AND 282
#define TK_OR 283
#define TK_NOT 284
#define TK_MAIS_MAIS 285
#define TK_MENOS_MENOS 286
#define TK_IF 287
#define TK_ELSE_IF 288
#define TK_ELSE 289
#define TK_WHILE 290
#define TK_DO 291
#define TK_FOR 292
#define TK_SWITCH 293
#define TK_CASE 294
#define TK_BREAK 295
#define TK_DEFAULT 296
#define TK_CONTINUE 297
#define TK_RETURN 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TK_NUM = 3,                     /* TK_NUM  */
  YYSYMBOL_TK_REAL = 4,                    /* TK_REAL  */
  YYSYMBOL_TK_BOOL = 5,                    /* TK_BOOL  */
  YYSYMBOL_TK_CHAR = 6,                    /* TK_CHAR  */
  YYSYMBOL_TK_OP_REL = 7,                  /* TK_OP_REL  */
  YYSYMBOL_TK_STRING = 8,                  /* TK_STRING  */
  YYSYMBOL__STRING = 9,                    /* _STRING  */
  YYSYMBOL_TK_MAIN = 10,                   /* TK_MAIN  */
  YYSYMBOL_TK_ID = 11,                     /* TK_ID  */
  YYSYMBOL_TK_TIPO_INT = 12,               /* TK_TIPO_INT  */
  YYSYMBOL_TK_TIPO_FLOAT = 13,             /* TK_TIPO_FLOAT  */
  YYSYMBOL_TK_TIPO_CHAR = 14,              /* TK_TIPO_CHAR  */
  YYSYMBOL_TK_TIPO_BOOL = 15,              /* TK_TIPO_BOOL  */
  YYSYMBOL_TK_CAST_INT = 16,               /* TK_CAST_INT  */
  YYSYMBOL_TK_CAST_FLOAT = 17,             /* TK_CAST_FLOAT  */
  YYSYMBOL_TK_TIPO_STRING = 18,            /* TK_TIPO_STRING  */
  YYSYMBOL_TK_FIM = 19,                    /* TK_FIM  */
  YYSYMBOL_TK_ERROR = 20,                  /* TK_ERROR  */
  YYSYMBOL_TK_IG = 21,                     /* TK_IG  */
  YYSYMBOL_TK_DIF = 22,                    /* TK_DIF  */
  YYSYMBOL_TK_MAIG = 23,                   /* TK_MAIG  */
  YYSYMBOL_TK_MEIG = 24,                   /* TK_MEIG  */
  YYSYMBOL_TK_MAIOR = 25,                  /* TK_MAIOR  */
  YYSYMBOL_TK_MENOR = 26,                  /* TK_MENOR  */
  YYSYMBOL_TK_AND = 27,                    /* TK_AND  */
  YYSYMBOL_TK_OR = 28,                     /* TK_OR  */
  YYSYMBOL_TK_NOT = 29,                    /* TK_NOT  */
  YYSYMBOL_TK_MAIS_MAIS = 30,              /* TK_MAIS_MAIS  */
  YYSYMBOL_TK_MENOS_MENOS = 31,            /* TK_MENOS_MENOS  */
  YYSYMBOL_TK_IF = 32,                     /* TK_IF  */
  YYSYMBOL_TK_ELSE_IF = 33,                /* TK_ELSE_IF  */
  YYSYMBOL_TK_ELSE = 34,                   /* TK_ELSE  */
  YYSYMBOL_TK_WHILE = 35,                  /* TK_WHILE  */
  YYSYMBOL_TK_DO = 36,                     /* TK_DO  */
  YYSYMBOL_TK_FOR = 37,                    /* TK_FOR  */
  YYSYMBOL_TK_SWITCH = 38,                 /* TK_SWITCH  */
  YYSYMBOL_TK_CASE = 39,                   /* TK_CASE  */
  YYSYMBOL_TK_BREAK = 40,                  /* TK_BREAK  */
  YYSYMBOL_TK_DEFAULT = 41,                /* TK_DEFAULT  */
  YYSYMBOL_TK_CONTINUE = 42,               /* TK_CONTINUE  */
  YYSYMBOL_TK_RETURN = 43,                 /* TK_RETURN  */
  YYSYMBOL_44_ = 44,                       /* '+'  */
  YYSYMBOL_45_ = 45,                       /* '-'  */
  YYSYMBOL_46_ = 46,                       /* '*'  */
  YYSYMBOL_47_ = 47,                       /* '('  */
  YYSYMBOL_48_ = 48,                       /* ')'  */
  YYSYMBOL_49_ = 49,                       /* '{'  */
  YYSYMBOL_50_ = 50,                       /* '}'  */
  YYSYMBOL_51_ = 51,                       /* ';'  */
  YYSYMBOL_52_ = 52,                       /* '='  */
  YYSYMBOL_53_ = 53,                       /* '/'  */
  YYSYMBOL_YYACCEPT = 54,                  /* $accept  */
  YYSYMBOL_S = 55,                         /* S  */
  YYSYMBOL_BLOCO = 56,                     /* BLOCO  */
  YYSYMBOL_INICIO = 57,                    /* INICIO  */
  YYSYMBOL_FIM = 58,                       /* FIM  */
  YYSYMBOL_COMANDOS = 59,                  /* COMANDOS  */
  YYSYMBOL_CONDICAO = 60,                  /* CONDICAO  */
  YYSYMBOL_LOOP = 61,                      /* LOOP  */
  YYSYMBOL_BREAK1 = 62,                    /* BREAK1  */
  YYSYMBOL_COMANDO = 63,                   /* COMANDO  */
  YYSYMBOL_E = 64                          /* E  */
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
#define YYLAST   542

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  53
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  147

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


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
      47,    48,    46,    44,     2,    45,     2,    53,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    51,
       2,    52,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,     2,    50,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    79,    79,    87,    98,   106,   112,   117,   121,   130,
     139,   145,   161,   176,   188,   194,   199,   213,   214,   215,
     216,   220,   241,   262,   284,   306,   328,   351,   372,   393,
     414,   441,   445,   450,   480,   510,   540,   570,   600,   631,
     672,   713,   755,   796,   837,   878,   884,   897,   909,   920,
     931,   967,   975,   990
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
  "\"end of file\"", "error", "\"invalid token\"", "TK_NUM", "TK_REAL",
  "TK_BOOL", "TK_CHAR", "TK_OP_REL", "TK_STRING", "_STRING", "TK_MAIN",
  "TK_ID", "TK_TIPO_INT", "TK_TIPO_FLOAT", "TK_TIPO_CHAR", "TK_TIPO_BOOL",
  "TK_CAST_INT", "TK_CAST_FLOAT", "TK_TIPO_STRING", "TK_FIM", "TK_ERROR",
  "TK_IG", "TK_DIF", "TK_MAIG", "TK_MEIG", "TK_MAIOR", "TK_MENOR",
  "TK_AND", "TK_OR", "TK_NOT", "TK_MAIS_MAIS", "TK_MENOS_MENOS", "TK_IF",
  "TK_ELSE_IF", "TK_ELSE", "TK_WHILE", "TK_DO", "TK_FOR", "TK_SWITCH",
  "TK_CASE", "TK_BREAK", "TK_DEFAULT", "TK_CONTINUE", "TK_RETURN", "'+'",
  "'-'", "'*'", "'('", "')'", "'{'", "'}'", "';'", "'='", "'/'", "$accept",
  "S", "BLOCO", "INICIO", "FIM", "COMANDOS", "CONDICAO", "LOOP", "BREAK1",
  "COMANDO", "E", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

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
      -8,     3,    15,   -28,  -117,   -24,   -16,  -117,  -117,   108,
    -117,  -117,  -117,    -3,    41,    45,    47,    49,    58,    58,
      52,    58,    17,    18,    20,    19,    23,    58,  -117,  -117,
      37,  -117,   108,   137,    58,   -40,   -34,   -31,   -29,   445,
     445,    -9,   445,    58,    58,    58,  -117,    58,   148,    22,
     -16,  -117,    58,    58,    58,    58,    58,    58,    58,    58,
    -117,  -117,    58,    58,    58,  -117,    58,   445,  -117,    58,
    -117,    58,  -117,    58,  -117,    58,  -117,    58,   181,   192,
     225,   108,   236,  -117,  -117,  -117,   445,   445,   445,   445,
     445,   445,   445,   445,   456,   456,   489,   445,   269,   280,
     313,   324,   357,   -16,   -16,    24,   -32,    58,  -117,  -117,
    -117,  -117,  -117,  -117,  -117,  -117,    26,    27,  -117,   368,
     108,   108,   108,    29,    58,   -32,   -32,   -32,    46,   401,
    -117,  -117,  -117,    33,    34,    32,    58,  -117,  -117,   412,
     108,    35,   -32,  -117,  -117,    38,  -117
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     4,     2,     7,
      51,    52,    32,    53,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    20,     5,
      18,    19,     7,     0,     0,     0,     0,     0,     0,    48,
      49,     0,    45,     0,     0,     0,     4,     0,     0,     0,
       0,     6,     0,     0,     0,     0,     0,     0,     0,     0,
      46,    47,     0,     0,     0,    17,     0,    50,    21,     0,
      27,     0,    28,     0,    22,     0,    29,     0,     0,     0,
       0,     7,     0,    31,     3,    10,    37,    38,    41,    42,
      39,    40,    43,    44,    33,    34,    35,    36,     0,     0,
       0,     0,     0,     0,     0,     0,    16,     0,    24,    26,
      25,    23,    30,     8,     9,     4,     0,     0,     5,     0,
       7,     7,     7,     0,     0,    16,    16,    16,     0,     0,
       5,    14,    15,     0,     0,     0,     0,     4,    11,     0,
       7,     0,    16,    13,     5,     0,    12
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -117,  -117,     0,   -39,  -116,   -27,  -117,  -117,   -95,  -117,
     -18
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    28,     9,    49,    29,    30,    31,   118,    32,
      33
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      39,    40,   123,    42,     1,    51,     8,    81,   116,    48,
     117,    68,    69,     3,   135,     4,    67,    70,    71,     5,
      72,    73,    74,    75,     6,    78,    79,    80,   145,    82,
     130,   131,   132,     7,    86,    87,    88,    89,    90,    91,
      92,    93,    76,    77,    94,    95,    96,   144,    97,    34,
      85,    98,    35,    99,   106,   100,    36,   101,    37,   102,
      38,    10,    11,    41,    43,    44,    12,    45,    46,    13,
      47,    50,    84,   115,    18,    19,   120,   121,   122,   128,
     136,   133,   138,   137,     0,     0,   143,    21,   146,   119,
       0,     0,     0,   125,   126,   127,     0,     0,   140,     0,
       0,     0,     0,   113,   114,    27,   129,     0,     0,     0,
       0,    10,    11,   142,     0,     0,    12,     0,   139,    13,
      14,    15,    16,    17,    18,    19,    20,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    21,     0,     0,
      22,    23,     0,    24,    25,    26,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,     0,     7,    52,    53,
      54,    55,    56,    57,    58,    59,     0,    60,    61,    52,
      53,    54,    55,    56,    57,    58,    59,     0,    60,    61,
       0,    62,    63,    64,     0,     0,     0,     0,    65,     0,
      66,     0,    62,    63,    64,     0,    83,     0,     0,     0,
       0,    66,    52,    53,    54,    55,    56,    57,    58,    59,
       0,    60,    61,    52,    53,    54,    55,    56,    57,    58,
      59,     0,    60,    61,     0,    62,    63,    64,     0,   103,
       0,     0,     0,     0,    66,     0,    62,    63,    64,     0,
     104,     0,     0,     0,     0,    66,    52,    53,    54,    55,
      56,    57,    58,    59,     0,    60,    61,    52,    53,    54,
      55,    56,    57,    58,    59,     0,    60,    61,     0,    62,
      63,    64,     0,   105,     0,     0,     0,     0,    66,     0,
      62,    63,    64,     0,     0,     0,     0,   107,     0,    66,
      52,    53,    54,    55,    56,    57,    58,    59,     0,    60,
      61,    52,    53,    54,    55,    56,    57,    58,    59,     0,
      60,    61,     0,    62,    63,    64,     0,     0,     0,     0,
     108,     0,    66,     0,    62,    63,    64,     0,     0,     0,
       0,   109,     0,    66,    52,    53,    54,    55,    56,    57,
      58,    59,     0,    60,    61,    52,    53,    54,    55,    56,
      57,    58,    59,     0,    60,    61,     0,    62,    63,    64,
       0,     0,     0,     0,   110,     0,    66,     0,    62,    63,
      64,     0,     0,     0,     0,   111,     0,    66,    52,    53,
      54,    55,    56,    57,    58,    59,     0,    60,    61,    52,
      53,    54,    55,    56,    57,    58,    59,     0,    60,    61,
       0,    62,    63,    64,     0,     0,     0,     0,   112,     0,
      66,     0,    62,    63,    64,     0,     0,     0,     0,   124,
       0,    66,    52,    53,    54,    55,    56,    57,    58,    59,
       0,    60,    61,    52,    53,    54,    55,    56,    57,    58,
      59,     0,    60,    61,     0,    62,    63,    64,     0,   134,
       0,     0,     0,     0,    66,     0,    62,    63,    64,     0,
     141,     0,     0,     0,     0,    66,    52,    53,    54,    55,
      56,    57,    58,    59,     0,    60,    61,    52,    53,    54,
      55,    56,    57,    58,    59,     0,    60,    61,     0,    62,
      63,    64,     0,     0,     0,     0,     0,     0,    66,     0,
       0,     0,    64,     0,     0,     0,     0,     0,     0,    66,
      52,    53,    54,    55,    56,    57,    58,    59,     0,    60,
      61,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    66
};

static const yytype_int16 yycheck[] =
{
      18,    19,   118,    21,    12,    32,     6,    46,    40,    27,
      42,    51,    52,    10,   130,     0,    34,    51,    52,    47,
      51,    52,    51,    52,    48,    43,    44,    45,   144,    47,
     125,   126,   127,    49,    52,    53,    54,    55,    56,    57,
      58,    59,    51,    52,    62,    63,    64,   142,    66,    52,
      50,    69,    11,    71,    81,    73,    11,    75,    11,    77,
      11,     3,     4,    11,    47,    47,     8,    47,    49,    11,
      47,    34,    50,    49,    16,    17,   115,    51,    51,    50,
      47,    35,    50,    49,    -1,    -1,    51,    29,    50,   107,
      -1,    -1,    -1,   120,   121,   122,    -1,    -1,   137,    -1,
      -1,    -1,    -1,   103,   104,    47,   124,    -1,    -1,    -1,
      -1,     3,     4,   140,    -1,    -1,     8,    -1,   136,    11,
      12,    13,    14,    15,    16,    17,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      32,    33,    -1,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    49,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,    31,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    30,    31,
      -1,    44,    45,    46,    -1,    -1,    -1,    -1,    51,    -1,
      53,    -1,    44,    45,    46,    -1,    48,    -1,    -1,    -1,
      -1,    53,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,    30,    31,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    30,    31,    -1,    44,    45,    46,    -1,    48,
      -1,    -1,    -1,    -1,    53,    -1,    44,    45,    46,    -1,
      48,    -1,    -1,    -1,    -1,    53,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    30,    31,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    30,    31,    -1,    44,
      45,    46,    -1,    48,    -1,    -1,    -1,    -1,    53,    -1,
      44,    45,    46,    -1,    -1,    -1,    -1,    51,    -1,    53,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    30,
      31,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      30,    31,    -1,    44,    45,    46,    -1,    -1,    -1,    -1,
      51,    -1,    53,    -1,    44,    45,    46,    -1,    -1,    -1,
      -1,    51,    -1,    53,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    31,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    30,    31,    -1,    44,    45,    46,
      -1,    -1,    -1,    -1,    51,    -1,    53,    -1,    44,    45,
      46,    -1,    -1,    -1,    -1,    51,    -1,    53,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,    31,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    30,    31,
      -1,    44,    45,    46,    -1,    -1,    -1,    -1,    51,    -1,
      53,    -1,    44,    45,    46,    -1,    -1,    -1,    -1,    51,
      -1,    53,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,    30,    31,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    30,    31,    -1,    44,    45,    46,    -1,    48,
      -1,    -1,    -1,    -1,    53,    -1,    44,    45,    46,    -1,
      48,    -1,    -1,    -1,    -1,    53,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    30,    31,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    30,    31,    -1,    44,
      45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    12,    55,    10,     0,    47,    48,    49,    56,    57,
       3,     4,     8,    11,    12,    13,    14,    15,    16,    17,
      18,    29,    32,    33,    35,    36,    37,    47,    56,    59,
      60,    61,    63,    64,    52,    11,    11,    11,    11,    64,
      64,    11,    64,    47,    47,    47,    49,    47,    64,    58,
      34,    59,    21,    22,    23,    24,    25,    26,    27,    28,
      30,    31,    44,    45,    46,    51,    53,    64,    51,    52,
      51,    52,    51,    52,    51,    52,    51,    52,    64,    64,
      64,    57,    64,    48,    50,    56,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    48,    48,    48,    59,    51,    51,    51,
      51,    51,    51,    56,    56,    49,    40,    42,    62,    64,
      57,    51,    51,    58,    51,    59,    59,    59,    50,    64,
      62,    62,    62,    35,    48,    58,    47,    49,    50,    64,
      57,    48,    59,    51,    62,    58,    50
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    56,    57,    58,    59,    59,    60,    60,
      60,    61,    61,    61,    62,    62,    62,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     5,     0,     0,     2,     0,     5,     5,
       3,    10,    14,    12,     4,     4,     0,     2,     1,     1,
       1,     3,     3,     5,     5,     5,     5,     3,     3,     3,
       5,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     2,
       3,     1,     1,     1
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
  case 2: /* S: TK_TIPO_INT TK_MAIN '(' ')' BLOCO  */
#line 80 "sintatica.y"
                        {
				
				cout << "/*Compilador XGH*/\n" << "#include <iostream>\n#include<string.h>\n#include<math.h>\n#include<stdio.h>\nint main(void)\n{\n" << printtabelaSimbolos() << yyvsp[0].traducao  << "\treturn 0;\n}" << endl; 
				//printpilhasdeSimbolos();
			}
#line 1482 "y.tab.c"
    break;

  case 3: /* BLOCO: '{' INICIO COMANDOS FIM '}'  */
#line 88 "sintatica.y"
                        {
				//escopototal.push(flag);
				//flag++;
				yyval.traducao = yyvsp[-2].traducao;
				//escopototal.pop();

			}
#line 1494 "y.tab.c"
    break;

  case 4: /* INICIO: %empty  */
#line 98 "sintatica.y"
            {
	            flag++; 
				escopototal.push(flag);
				yyval.traducao = "";
			}
#line 1504 "y.tab.c"
    break;

  case 5: /* FIM: %empty  */
#line 106 "sintatica.y"
            {
				escopototal.pop();
				yyval.traducao = "";
			}
#line 1513 "y.tab.c"
    break;

  case 6: /* COMANDOS: COMANDO COMANDOS  */
#line 113 "sintatica.y"
                        {
				yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
			}
#line 1521 "y.tab.c"
    break;

  case 7: /* COMANDOS: %empty  */
#line 117 "sintatica.y"
                        {
				yyval.traducao = "";
			}
#line 1529 "y.tab.c"
    break;

  case 8: /* CONDICAO: TK_IF '(' E ')' BLOCO  */
#line 122 "sintatica.y"
                        {
				cont ++;
                yyval.label = gentempcode();
                addtabSimbolos(yyval.label,"int");
                yyval.traducao =yyvsp[-2].traducao + "\t" + yyval.label + " != " + yyvsp[-2].label + ";\n"; 
                yyval.traducao+="\tif(" + yyval.label + ") goto fim_if_Label" + to_string(cont) + ";\n" 
				+ yyvsp[0].traducao + "\tfim_if_Label"+ to_string(cont) + ":\n\n";
			}
#line 1542 "y.tab.c"
    break;

  case 9: /* CONDICAO: TK_ELSE_IF '(' E ')' BLOCO  */
#line 131 "sintatica.y"
            {	
				cont ++;
                yyval.label = gentempcode();
                addtabSimbolos(yyval.label,"int");
                yyval.traducao = yyvsp[-2].traducao + "\t" + yyval.label + " != " + yyvsp[-2].label + ";\n"; 
                yyval.traducao+="\tif("+ yyval.label + ") goto fim_else_if_Label" + to_string(cont) + ";\n" 
				+ yyvsp[0].traducao + "\tfim_else_if_Label" + to_string(cont) + ":\n\n";
            }
#line 1555 "y.tab.c"
    break;

  case 10: /* CONDICAO: CONDICAO TK_ELSE BLOCO  */
#line 140 "sintatica.y"
            {
                yyval.traducao= yyvsp[-2].traducao + "\tif(!" + yyvsp[-2].label + ") goto fim_else_Label" + to_string(cont) 
				+ ";\n" + yyvsp[0].traducao + "\tfim_else_Label" + to_string(cont) + ";\n\n";
            }
#line 1564 "y.tab.c"
    break;

  case 11: /* LOOP: TK_WHILE '(' E ')' '{' INICIO COMANDOS BREAK1 FIM '}'  */
#line 146 "sintatica.y"
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
#line 1584 "y.tab.c"
    break;

  case 12: /* LOOP: TK_FOR '(' E ';' E ';' E ')' '{' INICIO COMANDOS BREAK1 FIM '}'  */
#line 162 "sintatica.y"
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
#line 1603 "y.tab.c"
    break;

  case 13: /* LOOP: TK_DO '{' INICIO COMANDOS BREAK1 FIM '}' TK_WHILE '(' E ')' ';'  */
#line 177 "sintatica.y"
            {
                yyval.label = gentempcode();
                string tempVar = gentempcode();
                addtabSimbolos(yyval.label,"int");

                yyval.traducao ="inicio_do_while"+ to_string(cont) +":\n"+ yyvsp[-8].traducao + yyvsp[-7].traducao; 
                yyval.traducao+=yyvsp[-2].traducao + "\tif(" + yyvsp[-2].label + ") goto inicio_do_while"+ to_string(cont) + "\n";
            }
#line 1616 "y.tab.c"
    break;

  case 14: /* BREAK1: TK_BREAK ';' COMANDOS BREAK1  */
#line 189 "sintatica.y"
            {
                
                yyval.traducao = "\tgoto fim_Label" + to_string(cont) + ";\n" + yyvsp[-1].traducao + yyvsp[0].traducao;
            }
#line 1625 "y.tab.c"
    break;

  case 15: /* BREAK1: TK_CONTINUE ';' COMANDOS BREAK1  */
#line 195 "sintatica.y"
            {
                yyval.traducao = "\tgoto fim_Label" + to_string(cont) + ";\n" + yyvsp[-1].traducao + yyvsp[0].traducao;
            }
#line 1633 "y.tab.c"
    break;

  case 16: /* BREAK1: %empty  */
#line 199 "sintatica.y"
            {
                cont ++;
                yyval.traducao = "";
            }
#line 1642 "y.tab.c"
    break;

  case 20: /* COMANDO: BLOCO  */
#line 217 "sintatica.y"
                        {
				yyval = yyvsp[0];
			}
#line 1650 "y.tab.c"
    break;

  case 21: /* COMANDO: TK_TIPO_INT TK_ID ';'  */
#line 221 "sintatica.y"
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
#line 1675 "y.tab.c"
    break;

  case 22: /* COMANDO: TK_TIPO_BOOL TK_ID ';'  */
#line 242 "sintatica.y"
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
#line 1700 "y.tab.c"
    break;

  case 23: /* COMANDO: TK_TIPO_BOOL TK_ID '=' E ';'  */
#line 262 "sintatica.y"
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
#line 1726 "y.tab.c"
    break;

  case 24: /* COMANDO: TK_TIPO_INT TK_ID '=' E ';'  */
#line 285 "sintatica.y"
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
#line 1752 "y.tab.c"
    break;

  case 25: /* COMANDO: TK_TIPO_CHAR TK_ID '=' E ';'  */
#line 307 "sintatica.y"
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
#line 1778 "y.tab.c"
    break;

  case 26: /* COMANDO: TK_TIPO_FLOAT TK_ID '=' E ';'  */
#line 329 "sintatica.y"
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
#line 1805 "y.tab.c"
    break;

  case 27: /* COMANDO: TK_TIPO_FLOAT TK_ID ';'  */
#line 352 "sintatica.y"
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
#line 1830 "y.tab.c"
    break;

  case 28: /* COMANDO: TK_TIPO_CHAR TK_ID ';'  */
#line 373 "sintatica.y"
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
#line 1855 "y.tab.c"
    break;

  case 29: /* COMANDO: TK_TIPO_STRING TK_ID ';'  */
#line 394 "sintatica.y"
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
#line 1880 "y.tab.c"
    break;

  case 30: /* COMANDO: TK_TIPO_STRING TK_ID '=' E ';'  */
#line 415 "sintatica.y"
                        {
				std::string str (yyvsp[-1].label);
				string a = '['+ std::to_string(str.length()-1)+']';
				TIPO_SIMBOLO valor;
				//string a = '['+ $3.label +']';
				valor.nomeVariavel = yyvsp[0].label;
				valor.tipoVariavel = "char" + a;
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
#line 1909 "y.tab.c"
    break;

  case 31: /* E: '(' E ')'  */
#line 442 "sintatica.y"
            {
			    yyval = yyvsp[-1];
			}
#line 1917 "y.tab.c"
    break;

  case 32: /* E: TK_STRING  */
#line 446 "sintatica.y"
                        {
				yyvsp[0].tipo = "string";
				yyval = yyvsp[0];
			}
#line 1926 "y.tab.c"
    break;

  case 33: /* E: E '+' E  */
#line 451 "sintatica.y"
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
				}
			}
#line 1960 "y.tab.c"
    break;

  case 34: /* E: E '-' E  */
#line 481 "sintatica.y"
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
#line 1994 "y.tab.c"
    break;

  case 35: /* E: E '*' E  */
#line 511 "sintatica.y"
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
#line 2028 "y.tab.c"
    break;

  case 36: /* E: E '/' E  */
#line 541 "sintatica.y"
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
#line 2062 "y.tab.c"
    break;

  case 37: /* E: E TK_IG E  */
#line 571 "sintatica.y"
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
#line 2096 "y.tab.c"
    break;

  case 38: /* E: E TK_DIF E  */
#line 601 "sintatica.y"
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
#line 2131 "y.tab.c"
    break;

  case 39: /* E: E TK_MAIOR E  */
#line 632 "sintatica.y"
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
#line 2176 "y.tab.c"
    break;

  case 40: /* E: E TK_MENOR E  */
#line 673 "sintatica.y"
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
#line 2221 "y.tab.c"
    break;

  case 41: /* E: E TK_MAIG E  */
#line 714 "sintatica.y"
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
#line 2266 "y.tab.c"
    break;

  case 42: /* E: E TK_MEIG E  */
#line 756 "sintatica.y"
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
#line 2311 "y.tab.c"
    break;

  case 43: /* E: E TK_AND E  */
#line 797 "sintatica.y"
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
#line 2356 "y.tab.c"
    break;

  case 44: /* E: E TK_OR E  */
#line 838 "sintatica.y"
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
#line 2401 "y.tab.c"
    break;

  case 45: /* E: TK_NOT E  */
#line 879 "sintatica.y"
                        {	
				yyval.label = gentempcode();
				yyval.traducao = yyvsp[0].traducao + "\t" + yyval.label +
				" = ! " + yyvsp[0].label + ";\n"; 
			}
#line 2411 "y.tab.c"
    break;

  case 46: /* E: E TK_MAIS_MAIS  */
#line 885 "sintatica.y"
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
#line 2428 "y.tab.c"
    break;

  case 47: /* E: E TK_MENOS_MENOS  */
#line 898 "sintatica.y"
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
#line 2444 "y.tab.c"
    break;

  case 48: /* E: TK_CAST_INT E  */
#line 910 "sintatica.y"
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
#line 2459 "y.tab.c"
    break;

  case 49: /* E: TK_CAST_FLOAT E  */
#line 921 "sintatica.y"
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
#line 2474 "y.tab.c"
    break;

  case 50: /* E: TK_ID '=' E  */
#line 932 "sintatica.y"
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
#line 2514 "y.tab.c"
    break;

  case 51: /* E: TK_NUM  */
#line 968 "sintatica.y"
                        {	

				yyval.tipo = "int";
				yyval.label = gentempcode();
				addtabSimbolos(yyval.label, yyval.tipo);
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
			}
#line 2526 "y.tab.c"
    break;

  case 52: /* E: TK_REAL  */
#line 976 "sintatica.y"
                        {
				yyval.tipo = "float";
				yyval.label = gentempcode();
				addtabSimbolos(yyval.label, yyval.tipo);
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
			}
#line 2537 "y.tab.c"
    break;

  case 53: /* E: TK_ID  */
#line 991 "sintatica.y"
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
#line 2582 "y.tab.c"
    break;


#line 2586 "y.tab.c"

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

#line 1033 "sintatica.y"


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
