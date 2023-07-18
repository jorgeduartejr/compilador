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
		n += "\t" + tabelaSimbolos[i].tipoVariavel + "\t" + tabelaSimbolos[i].nomeTemp + "\n";
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
    TK_MAIN = 263,                 /* TK_MAIN  */
    TK_ID = 264,                   /* TK_ID  */
    TK_TIPO_INT = 265,             /* TK_TIPO_INT  */
    TK_TIPO_FLOAT = 266,           /* TK_TIPO_FLOAT  */
    TK_TIPO_CHAR = 267,            /* TK_TIPO_CHAR  */
    TK_TIPO_BOOL = 268,            /* TK_TIPO_BOOL  */
    TK_CAST_INT = 269,             /* TK_CAST_INT  */
    TK_CAST_FLOAT = 270,           /* TK_CAST_FLOAT  */
    TK_FIM = 271,                  /* TK_FIM  */
    TK_ERROR = 272,                /* TK_ERROR  */
    TK_IG = 273,                   /* TK_IG  */
    TK_DIF = 274,                  /* TK_DIF  */
    TK_MAIG = 275,                 /* TK_MAIG  */
    TK_MEIG = 276,                 /* TK_MEIG  */
    TK_MAIOR = 277,                /* TK_MAIOR  */
    TK_MENOR = 278,                /* TK_MENOR  */
    TK_AND = 279,                  /* TK_AND  */
    TK_OR = 280,                   /* TK_OR  */
    TK_NOT = 281,                  /* TK_NOT  */
    TK_MAIS_MAIS = 282,            /* TK_MAIS_MAIS  */
    TK_MENOS_MENOS = 283,          /* TK_MENOS_MENOS  */
    TK_IF = 284,                   /* TK_IF  */
    TK_ELSE_IF = 285,              /* TK_ELSE_IF  */
    TK_ELSE = 286,                 /* TK_ELSE  */
    TK_WHILE = 287,                /* TK_WHILE  */
    TK_DO = 288,                   /* TK_DO  */
    TK_FOR = 289,                  /* TK_FOR  */
    TK_SWITCH = 290,               /* TK_SWITCH  */
    TK_CASE = 291,                 /* TK_CASE  */
    TK_BREAK = 292,                /* TK_BREAK  */
    TK_DEFAULT = 293,              /* TK_DEFAULT  */
    TK_CONTINUE = 294,             /* TK_CONTINUE  */
    TK_RETURN = 295                /* TK_RETURN  */
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
#define TK_MAIN 263
#define TK_ID 264
#define TK_TIPO_INT 265
#define TK_TIPO_FLOAT 266
#define TK_TIPO_CHAR 267
#define TK_TIPO_BOOL 268
#define TK_CAST_INT 269
#define TK_CAST_FLOAT 270
#define TK_FIM 271
#define TK_ERROR 272
#define TK_IG 273
#define TK_DIF 274
#define TK_MAIG 275
#define TK_MEIG 276
#define TK_MAIOR 277
#define TK_MENOR 278
#define TK_AND 279
#define TK_OR 280
#define TK_NOT 281
#define TK_MAIS_MAIS 282
#define TK_MENOS_MENOS 283
#define TK_IF 284
#define TK_ELSE_IF 285
#define TK_ELSE 286
#define TK_WHILE 287
#define TK_DO 288
#define TK_FOR 289
#define TK_SWITCH 290
#define TK_CASE 291
#define TK_BREAK 292
#define TK_DEFAULT 293
#define TK_CONTINUE 294
#define TK_RETURN 295

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
  YYSYMBOL_TK_MAIN = 8,                    /* TK_MAIN  */
  YYSYMBOL_TK_ID = 9,                      /* TK_ID  */
  YYSYMBOL_TK_TIPO_INT = 10,               /* TK_TIPO_INT  */
  YYSYMBOL_TK_TIPO_FLOAT = 11,             /* TK_TIPO_FLOAT  */
  YYSYMBOL_TK_TIPO_CHAR = 12,              /* TK_TIPO_CHAR  */
  YYSYMBOL_TK_TIPO_BOOL = 13,              /* TK_TIPO_BOOL  */
  YYSYMBOL_TK_CAST_INT = 14,               /* TK_CAST_INT  */
  YYSYMBOL_TK_CAST_FLOAT = 15,             /* TK_CAST_FLOAT  */
  YYSYMBOL_TK_FIM = 16,                    /* TK_FIM  */
  YYSYMBOL_TK_ERROR = 17,                  /* TK_ERROR  */
  YYSYMBOL_TK_IG = 18,                     /* TK_IG  */
  YYSYMBOL_TK_DIF = 19,                    /* TK_DIF  */
  YYSYMBOL_TK_MAIG = 20,                   /* TK_MAIG  */
  YYSYMBOL_TK_MEIG = 21,                   /* TK_MEIG  */
  YYSYMBOL_TK_MAIOR = 22,                  /* TK_MAIOR  */
  YYSYMBOL_TK_MENOR = 23,                  /* TK_MENOR  */
  YYSYMBOL_TK_AND = 24,                    /* TK_AND  */
  YYSYMBOL_TK_OR = 25,                     /* TK_OR  */
  YYSYMBOL_TK_NOT = 26,                    /* TK_NOT  */
  YYSYMBOL_TK_MAIS_MAIS = 27,              /* TK_MAIS_MAIS  */
  YYSYMBOL_TK_MENOS_MENOS = 28,            /* TK_MENOS_MENOS  */
  YYSYMBOL_TK_IF = 29,                     /* TK_IF  */
  YYSYMBOL_TK_ELSE_IF = 30,                /* TK_ELSE_IF  */
  YYSYMBOL_TK_ELSE = 31,                   /* TK_ELSE  */
  YYSYMBOL_TK_WHILE = 32,                  /* TK_WHILE  */
  YYSYMBOL_TK_DO = 33,                     /* TK_DO  */
  YYSYMBOL_TK_FOR = 34,                    /* TK_FOR  */
  YYSYMBOL_TK_SWITCH = 35,                 /* TK_SWITCH  */
  YYSYMBOL_TK_CASE = 36,                   /* TK_CASE  */
  YYSYMBOL_TK_BREAK = 37,                  /* TK_BREAK  */
  YYSYMBOL_TK_DEFAULT = 38,                /* TK_DEFAULT  */
  YYSYMBOL_TK_CONTINUE = 39,               /* TK_CONTINUE  */
  YYSYMBOL_TK_RETURN = 40,                 /* TK_RETURN  */
  YYSYMBOL_41_ = 41,                       /* '+'  */
  YYSYMBOL_42_ = 42,                       /* '-'  */
  YYSYMBOL_43_ = 43,                       /* '*'  */
  YYSYMBOL_44_ = 44,                       /* '('  */
  YYSYMBOL_45_ = 45,                       /* ')'  */
  YYSYMBOL_46_ = 46,                       /* '{'  */
  YYSYMBOL_47_ = 47,                       /* '}'  */
  YYSYMBOL_48_ = 48,                       /* ';'  */
  YYSYMBOL_49_ = 49,                       /* '='  */
  YYSYMBOL_50_ = 50,                       /* '/'  */
  YYSYMBOL_YYACCEPT = 51,                  /* $accept  */
  YYSYMBOL_S = 52,                         /* S  */
  YYSYMBOL_BLOCO = 53,                     /* BLOCO  */
  YYSYMBOL_INICIO = 54,                    /* INICIO  */
  YYSYMBOL_FIM = 55,                       /* FIM  */
  YYSYMBOL_COMANDOS = 56,                  /* COMANDOS  */
  YYSYMBOL_CONDICAO = 57,                  /* CONDICAO  */
  YYSYMBOL_COMANDO = 58,                   /* COMANDO  */
  YYSYMBOL_E = 59                          /* E  */
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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   348

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  9
/* YYNRULES -- Number of rules.  */
#define YYNRULES  43
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  95

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


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
      44,    45,    43,    41,     2,    42,     2,    50,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    48,
       2,    49,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,    47,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    79,    79,    87,    98,   106,   112,   117,   121,   130,
     139,   147,   148,   149,   153,   174,   195,   217,   239,   261,
     284,   305,   328,   332,   362,   392,   422,   452,   482,   513,
     544,   574,   604,   634,   664,   694,   700,   713,   725,   736,
     747,   763,   771,   787
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
  "TK_BOOL", "TK_CHAR", "TK_OP_REL", "TK_MAIN", "TK_ID", "TK_TIPO_INT",
  "TK_TIPO_FLOAT", "TK_TIPO_CHAR", "TK_TIPO_BOOL", "TK_CAST_INT",
  "TK_CAST_FLOAT", "TK_FIM", "TK_ERROR", "TK_IG", "TK_DIF", "TK_MAIG",
  "TK_MEIG", "TK_MAIOR", "TK_MENOR", "TK_AND", "TK_OR", "TK_NOT",
  "TK_MAIS_MAIS", "TK_MENOS_MENOS", "TK_IF", "TK_ELSE_IF", "TK_ELSE",
  "TK_WHILE", "TK_DO", "TK_FOR", "TK_SWITCH", "TK_CASE", "TK_BREAK",
  "TK_DEFAULT", "TK_CONTINUE", "TK_RETURN", "'+'", "'-'", "'*'", "'('",
  "')'", "'{'", "'}'", "';'", "'='", "'/'", "$accept", "S", "BLOCO",
  "INICIO", "FIM", "COMANDOS", "CONDICAO", "COMANDO", "E", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-45)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       1,     7,    16,   -27,   -45,   -26,   -28,   -45,   -45,    47,
     -45,   -45,   -25,    13,    14,    26,    30,    60,    60,    60,
     -19,    -3,    60,   -45,   -45,    11,    47,    78,    60,   -44,
     -41,   -39,   -35,   254,   254,   254,    60,    60,    89,    -1,
     -28,   -45,    60,    60,    60,    60,    60,    60,    60,    60,
     -45,   -45,    60,    60,    60,   -45,    60,   254,   -45,    60,
     -45,    60,   -45,    60,   -45,    60,   122,   133,   -45,   -45,
     -45,   254,   254,   254,   254,   254,   254,   254,   254,   265,
     265,   298,   254,   166,   177,   210,   221,   -28,   -28,   -45,
     -45,   -45,   -45,   -45,   -45
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     4,     2,     7,
      41,    42,    43,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,     5,    12,     7,     0,     0,     0,
       0,     0,     0,    38,    39,    35,     0,     0,     0,     0,
       0,     6,     0,     0,     0,     0,     0,     0,     0,     0,
      36,    37,     0,     0,     0,    11,     0,    40,    14,     0,
      20,     0,    21,     0,    15,     0,     0,     0,    22,     3,
      10,    27,    28,    31,    32,    29,    30,    33,    34,    23,
      24,    25,    26,     0,     0,     0,     0,     0,     0,    17,
      19,    18,    16,     8,     9
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -45,   -45,    -6,   -45,   -45,    18,   -45,   -45,   -16
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    23,     9,    39,    24,    25,    26,    27
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
       8,    33,    34,    35,    58,    59,    38,    60,    61,    62,
      63,     1,    57,    64,    65,     3,     4,     5,     7,     6,
      66,    67,    29,    30,    28,    36,    71,    72,    73,    74,
      75,    76,    77,    78,    70,    31,    79,    80,    81,    32,
      82,    37,    40,    83,    41,    84,    69,    85,     0,    86,
      10,    11,     0,     0,     0,     0,    12,    13,    14,    15,
      16,    17,    18,    10,    11,     0,     0,     0,     0,    12,
       0,     0,     0,    19,    17,    18,    20,    21,     0,     0,
       0,    93,    94,     0,     0,     0,    19,     0,     0,     0,
       0,    22,     0,     7,     0,     0,    42,    43,    44,    45,
      46,    47,    48,    49,    22,    50,    51,    42,    43,    44,
      45,    46,    47,    48,    49,     0,    50,    51,     0,    52,
      53,    54,     0,     0,     0,     0,    55,     0,    56,     0,
      52,    53,    54,     0,    68,     0,     0,     0,     0,    56,
      42,    43,    44,    45,    46,    47,    48,    49,     0,    50,
      51,    42,    43,    44,    45,    46,    47,    48,    49,     0,
      50,    51,     0,    52,    53,    54,     0,    87,     0,     0,
       0,     0,    56,     0,    52,    53,    54,     0,    88,     0,
       0,     0,     0,    56,    42,    43,    44,    45,    46,    47,
      48,    49,     0,    50,    51,    42,    43,    44,    45,    46,
      47,    48,    49,     0,    50,    51,     0,    52,    53,    54,
       0,     0,     0,     0,    89,     0,    56,     0,    52,    53,
      54,     0,     0,     0,     0,    90,     0,    56,    42,    43,
      44,    45,    46,    47,    48,    49,     0,    50,    51,    42,
      43,    44,    45,    46,    47,    48,    49,     0,    50,    51,
       0,    52,    53,    54,     0,     0,     0,     0,    91,     0,
      56,     0,    52,    53,    54,     0,     0,     0,     0,    92,
       0,    56,    42,    43,    44,    45,    46,    47,    48,    49,
       0,    50,    51,    42,    43,    44,    45,    46,    47,    48,
      49,     0,    50,    51,     0,    52,    53,    54,     0,     0,
       0,     0,     0,     0,    56,     0,     0,     0,    54,     0,
       0,     0,     0,     0,     0,    56,    42,    43,    44,    45,
      46,    47,    48,    49,     0,    50,    51,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    56
};

static const yytype_int8 yycheck[] =
{
       6,    17,    18,    19,    48,    49,    22,    48,    49,    48,
      49,    10,    28,    48,    49,     8,     0,    44,    46,    45,
      36,    37,     9,     9,    49,    44,    42,    43,    44,    45,
      46,    47,    48,    49,    40,     9,    52,    53,    54,     9,
      56,    44,    31,    59,    26,    61,    47,    63,    -1,    65,
       3,     4,    -1,    -1,    -1,    -1,     9,    10,    11,    12,
      13,    14,    15,     3,     4,    -1,    -1,    -1,    -1,     9,
      -1,    -1,    -1,    26,    14,    15,    29,    30,    -1,    -1,
      -1,    87,    88,    -1,    -1,    -1,    26,    -1,    -1,    -1,
      -1,    44,    -1,    46,    -1,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    44,    27,    28,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    27,    28,    -1,    41,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    -1,
      41,    42,    43,    -1,    45,    -1,    -1,    -1,    -1,    50,
      18,    19,    20,    21,    22,    23,    24,    25,    -1,    27,
      28,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      27,    28,    -1,    41,    42,    43,    -1,    45,    -1,    -1,
      -1,    -1,    50,    -1,    41,    42,    43,    -1,    45,    -1,
      -1,    -1,    -1,    50,    18,    19,    20,    21,    22,    23,
      24,    25,    -1,    27,    28,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    27,    28,    -1,    41,    42,    43,
      -1,    -1,    -1,    -1,    48,    -1,    50,    -1,    41,    42,
      43,    -1,    -1,    -1,    -1,    48,    -1,    50,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    27,    28,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    27,    28,
      -1,    41,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,
      50,    -1,    41,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    27,    28,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,    28,    -1,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    27,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    10,    52,     8,     0,    44,    45,    46,    53,    54,
       3,     4,     9,    10,    11,    12,    13,    14,    15,    26,
      29,    30,    44,    53,    56,    57,    58,    59,    49,     9,
       9,     9,     9,    59,    59,    59,    44,    44,    59,    55,
      31,    56,    18,    19,    20,    21,    22,    23,    24,    25,
      27,    28,    41,    42,    43,    48,    50,    59,    48,    49,
      48,    49,    48,    49,    48,    49,    59,    59,    45,    47,
      53,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    45,    45,    48,
      48,    48,    48,    53,    53
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    53,    54,    55,    56,    56,    57,    57,
      57,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     5,     0,     0,     2,     0,     5,     5,
       3,     2,     1,     1,     3,     3,     5,     5,     5,     5,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
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
				
				cout << "/*Compilador FOCA*/\n" << "#include <iostream>\n#include<string.h>\n#include<math.h>\n#include<stdio.h>\nint main(void)\n{\n" << printtabelaSimbolos() << yyvsp[0].traducao  << "\treturn 0;\n}" << endl; 
				//printpilhasdeSimbolos();
			}
#line 1410 "y.tab.c"
    break;

  case 3: /* BLOCO: '{' INICIO COMANDOS FIM '}'  */
#line 88 "sintatica.y"
                        {
				//escopototal.push(flag);
				//flag++;
				yyval.traducao = yyvsp[-2].traducao;
				//escopototal.pop();

			}
#line 1422 "y.tab.c"
    break;

  case 4: /* INICIO: %empty  */
#line 98 "sintatica.y"
            {
	            flag++; 
				escopototal.push(flag);
				yyval.traducao = "";
			}
#line 1432 "y.tab.c"
    break;

  case 5: /* FIM: %empty  */
#line 106 "sintatica.y"
            {
				escopototal.pop();
				yyval.traducao = "";
			}
#line 1441 "y.tab.c"
    break;

  case 6: /* COMANDOS: COMANDO COMANDOS  */
#line 113 "sintatica.y"
                        {
				yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
			}
#line 1449 "y.tab.c"
    break;

  case 7: /* COMANDOS: %empty  */
#line 117 "sintatica.y"
                        {
				yyval.traducao = "";
			}
#line 1457 "y.tab.c"
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
#line 1470 "y.tab.c"
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
#line 1483 "y.tab.c"
    break;

  case 10: /* CONDICAO: CONDICAO TK_ELSE BLOCO  */
#line 140 "sintatica.y"
            {
                yyval.traducao= yyvsp[-2].traducao + "\tif(!" + yyvsp[-2].label + ") goto fim_else_Label" + to_string(cont) 
				+ ";\n" + yyvsp[0].traducao + "\tfim_else_Label" + to_string(cont) + ";\n\n";
            }
#line 1492 "y.tab.c"
    break;

  case 13: /* COMANDO: BLOCO  */
#line 150 "sintatica.y"
                        {
				yyval = yyvsp[0];
			}
#line 1500 "y.tab.c"
    break;

  case 14: /* COMANDO: TK_TIPO_INT TK_ID ';'  */
#line 154 "sintatica.y"
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
#line 1525 "y.tab.c"
    break;

  case 15: /* COMANDO: TK_TIPO_BOOL TK_ID ';'  */
#line 175 "sintatica.y"
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
#line 1550 "y.tab.c"
    break;

  case 16: /* COMANDO: TK_TIPO_BOOL TK_ID '=' E ';'  */
#line 195 "sintatica.y"
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
#line 1576 "y.tab.c"
    break;

  case 17: /* COMANDO: TK_TIPO_INT TK_ID '=' E ';'  */
#line 218 "sintatica.y"
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
#line 1602 "y.tab.c"
    break;

  case 18: /* COMANDO: TK_TIPO_CHAR TK_ID '=' E ';'  */
#line 240 "sintatica.y"
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
#line 1628 "y.tab.c"
    break;

  case 19: /* COMANDO: TK_TIPO_FLOAT TK_ID '=' E ';'  */
#line 262 "sintatica.y"
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
#line 1655 "y.tab.c"
    break;

  case 20: /* COMANDO: TK_TIPO_FLOAT TK_ID ';'  */
#line 285 "sintatica.y"
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
#line 1680 "y.tab.c"
    break;

  case 21: /* COMANDO: TK_TIPO_CHAR TK_ID ';'  */
#line 306 "sintatica.y"
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
#line 1705 "y.tab.c"
    break;

  case 22: /* E: '(' E ')'  */
#line 329 "sintatica.y"
            {
			    yyval = yyvsp[-1];
			}
#line 1713 "y.tab.c"
    break;

  case 23: /* E: E '+' E  */
#line 333 "sintatica.y"
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
#line 1747 "y.tab.c"
    break;

  case 24: /* E: E '-' E  */
#line 363 "sintatica.y"
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
#line 1781 "y.tab.c"
    break;

  case 25: /* E: E '*' E  */
#line 393 "sintatica.y"
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
#line 1815 "y.tab.c"
    break;

  case 26: /* E: E '/' E  */
#line 423 "sintatica.y"
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
#line 1849 "y.tab.c"
    break;

  case 27: /* E: E TK_IG E  */
#line 453 "sintatica.y"
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
#line 1883 "y.tab.c"
    break;

  case 28: /* E: E TK_DIF E  */
#line 483 "sintatica.y"
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
#line 1918 "y.tab.c"
    break;

  case 29: /* E: E TK_MAIOR E  */
#line 514 "sintatica.y"
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
					
				} 
			}
#line 1953 "y.tab.c"
    break;

  case 30: /* E: E TK_MENOR E  */
#line 545 "sintatica.y"
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
				} 
			}
#line 1987 "y.tab.c"
    break;

  case 31: /* E: E TK_MAIG E  */
#line 575 "sintatica.y"
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
			}
#line 2021 "y.tab.c"
    break;

  case 32: /* E: E TK_MEIG E  */
#line 605 "sintatica.y"
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
				} 
			}
#line 2055 "y.tab.c"
    break;

  case 33: /* E: E TK_AND E  */
#line 635 "sintatica.y"
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
				} 
			}
#line 2089 "y.tab.c"
    break;

  case 34: /* E: E TK_OR E  */
#line 665 "sintatica.y"
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
				} 
			}
#line 2123 "y.tab.c"
    break;

  case 35: /* E: TK_NOT E  */
#line 695 "sintatica.y"
                        {	
				yyval.label = gentempcode();
				yyval.traducao = yyvsp[0].traducao + "\t" + yyval.label +
				" = ! " + yyvsp[0].label + ";\n";
			}
#line 2133 "y.tab.c"
    break;

  case 36: /* E: E TK_MAIS_MAIS  */
#line 701 "sintatica.y"
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
#line 2150 "y.tab.c"
    break;

  case 37: /* E: E TK_MENOS_MENOS  */
#line 714 "sintatica.y"
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
#line 2166 "y.tab.c"
    break;

  case 38: /* E: TK_CAST_INT E  */
#line 726 "sintatica.y"
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
#line 2181 "y.tab.c"
    break;

  case 39: /* E: TK_CAST_FLOAT E  */
#line 737 "sintatica.y"
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
#line 2196 "y.tab.c"
    break;

  case 40: /* E: TK_ID '=' E  */
#line 748 "sintatica.y"
                        {
				bool encontrei = false;
				TIPO_SIMBOLO variavel;
				for(int i = 0; i < tabelaSimbolos.size(); i++){
					if(tabelaSimbolos[i].nomeVariavel == yyvsp[-2].label ){
						variavel = tabelaSimbolos[i];
						encontrei = true;
					}
				}
				if(!encontrei){
					yyerror("Variavel nao declarada");
				}
				yyvsp[-2].label = variavel.nomeTemp;
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" +  yyvsp[-2].label + " = " + yyvsp[0].label + ";\n";
			}
#line 2216 "y.tab.c"
    break;

  case 41: /* E: TK_NUM  */
#line 764 "sintatica.y"
                        {	

				yyval.tipo = "int";
				yyval.label = gentempcode();
				addtabSimbolos(yyval.label, yyval.tipo);
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
			}
#line 2228 "y.tab.c"
    break;

  case 42: /* E: TK_REAL  */
#line 772 "sintatica.y"
                        {
				yyval.tipo = "float";
				yyval.label = gentempcode();
				addtabSimbolos(yyval.label, yyval.tipo);
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
			}
#line 2239 "y.tab.c"
    break;

  case 43: /* E: TK_ID  */
#line 788 "sintatica.y"
                        {
				if (yyvsp[0].label == "true" || yyvsp[0].label == "false"){
					yyval.tipo = "bool"; 
					yyval.label = gentempcode();
					addtabSimbolos(yyval.label, yyval.tipo);
					yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
				} else {
					bool encontrei = false;
				TIPO_SIMBOLO variavel;
				for(int i = tabelaSimbolos.size(); i >= 0; i--){
					if(tabelaSimbolos[i].nomeVariavel == yyvsp[0].label && tabelaSimbolos[i].scope.size() <= escopototal.size() && tabelaSimbolos[i].scope.top()<=escopototal.top()){
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
#line 2273 "y.tab.c"
    break;


#line 2277 "y.tab.c"

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

#line 819 "sintatica.y"


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
