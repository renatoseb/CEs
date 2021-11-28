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

#ifndef YY_YY_CALC_TAB_H_INCLUDED
# define YY_YY_CALC_TAB_H_INCLUDED
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
    OP_COMP_IGUAL = 258,           /* OP_COMP_IGUAL  */
    OP_COMP_DESIGUAL = 259,        /* OP_COMP_DESIGUAL  */
    OP_COMP_MENOR = 260,           /* OP_COMP_MENOR  */
    OP_COMP_MAYOR = 261,           /* OP_COMP_MAYOR  */
    OP_COMP_MENOR_IGUAL = 262,     /* OP_COMP_MENOR_IGUAL  */
    OP_COMP_MAYOR_IGUAL = 263,     /* OP_COMP_MAYOR_IGUAL  */
    ASIGNAR = 264,                 /* ASIGNAR  */
    COMA = 265,                    /* COMA  */
    OP_SUMA = 266,                 /* OP_SUMA  */
    OP_RESTA = 267,                /* OP_RESTA  */
    OP_MUL = 268,                  /* OP_MUL  */
    OP_DIV = 269,                  /* OP_DIV  */
    NUMERO = 270,                  /* NUMERO  */
    PAR_INICIO = 271,              /* PAR_INICIO  */
    PAR_FINAL = 272,               /* PAR_FINAL  */
    CORCH_INICIO = 273,            /* CORCH_INICIO  */
    CORCH_FINAL = 274,             /* CORCH_FINAL  */
    LLAVES_INICIO = 275,           /* LLAVES_INICIO  */
    LLAVES_FINAL = 276,            /* LLAVES_FINAL  */
    TIPO_ENTERO = 277,             /* TIPO_ENTERO  */
    SIN_TIPO = 278,                /* SIN_TIPO  */
    SI = 279,                      /* SI  */
    SINO = 280,                    /* SINO  */
    RETORNO = 281,                 /* RETORNO  */
    MIENTRAS = 282,                /* MIENTRAS  */
    MAIN = 283,                    /* MAIN  */
    IDENTIFICADOR = 284,           /* IDENTIFICADOR  */
    PUNTO_COMA = 285               /* PUNTO_COMA  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 33 "calc.y"

  int		int_val;
  string string_val;
  string*	op_val;

#line 100 "calc.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_CALC_TAB_H_INCLUDED  */
