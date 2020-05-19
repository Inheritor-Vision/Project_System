/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_COMPILATOR_Y_TAB_H_INCLUDED
# define YY_YY_COMPILATOR_Y_TAB_H_INCLUDED
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
    tInt = 258,
    tMain = 259,
    tReturn = 260,
    tPrintf = 261,
    tConst = 262,
    tVoid = 263,
    tAdd = 264,
    tSub = 265,
    tMul = 266,
    tEqu = 267,
    tSC = 268,
    tDiv = 269,
    tOCB = 270,
    tCCB = 271,
    tORB = 272,
    tCRB = 273,
    tComma = 274,
    tCR = 275,
    tVar = 276,
    tValInt = 277,
    tDecVal = 278,
    tExpVal = 279,
    tIf = 280,
    tElse = 281,
    tEquEqu = 282,
    tSupEqu = 283,
    tInfEqu = 284,
    tSup = 285,
    tInf = 286,
    tWhile = 287,
    tEt = 288
  };
#endif
/* Tokens.  */
#define tInt 258
#define tMain 259
#define tReturn 260
#define tPrintf 261
#define tConst 262
#define tVoid 263
#define tAdd 264
#define tSub 265
#define tMul 266
#define tEqu 267
#define tSC 268
#define tDiv 269
#define tOCB 270
#define tCCB 271
#define tORB 272
#define tCRB 273
#define tComma 274
#define tCR 275
#define tVar 276
#define tValInt 277
#define tDecVal 278
#define tExpVal 279
#define tIf 280
#define tElse 281
#define tEquEqu 282
#define tSupEqu 283
#define tInfEqu 284
#define tSup 285
#define tInf 286
#define tWhile 287
#define tEt 288

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 38 "syntaxique_C_Return.y" /* yacc.c:1909  */

    int integerValue;
    char *stringValue;

#line 125 "Compilator.y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_COMPILATOR_Y_TAB_H_INCLUDED  */
