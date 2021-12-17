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

#ifndef YY_YY_CALC_TAB_H_INCLUDED
# define YY_YY_CALC_TAB_H_INCLUDED
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
    NUMERO = 258,
    IDENTIFICADOR = 259,
    TIPO_ENTERO = 260,
    SIN_TIPO = 261,
    RETORNO = 262,
    MIENTRAS = 263,
    SI = 264,
    SINO = 265,
    MAIN = 266,
    OP_COMP_DIFERENTE = 267,
    OP_COMP_IGUAL = 268,
    OP_COMP_MENOR = 269,
    OP_COMP_MAYOR = 270,
    OP_COMP_MENOR_IGUAL = 271,
    OP_COMP_MAYOR_IGUAL = 272,
    OP_SUMA = 273,
    OP_RESTA = 274,
    OP_MUL = 275,
    OP_DIV = 276,
    ASIGNAR = 277,
    COMA = 278,
    PUNTO_COMA = 279,
    PAR_INICIO = 280,
    PAR_FINAL = 281,
    CORCH_INICIO = 282,
    CORCH_FINAL = 283,
    LLAVES_INICIO = 284,
    LLAVES_FINAL = 285,
    ERROR = 286
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 11 "calc.y"

  int		int_val;
  string*	op_val;

#line 94 "calc.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CALC_TAB_H_INCLUDED  */
