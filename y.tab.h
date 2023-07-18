/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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
