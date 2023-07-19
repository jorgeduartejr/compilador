/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
    TK_IG = 276,
    TK_DIF = 277,
    TK_MAIG = 278,
    TK_MEIG = 279,
    TK_MAIOR = 280,
    TK_MENOR = 281,
    TK_AND = 282,
    TK_OR = 283,
    TK_NOT = 284,
    TK_MAIS_MAIS = 285,
    TK_MENOS_MENOS = 286,
    TK_IF = 287,
    TK_ELSE_IF = 288,
    TK_ELSE = 289,
    TK_WHILE = 290,
    TK_DO = 291,
    TK_FOR = 292,
    TK_SWITCH = 293,
    TK_CASE = 294,
    TK_BREAK = 295,
    TK_DEFAULT = 296,
    TK_CONTINUE = 297,
    TK_RETURN = 298
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
