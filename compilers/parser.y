%{
#include <iostream>
#include <string>
#include <cmath>
#include <FlexLexer.h>
%}

%require "3.5.1"
%language "C++"

%define api.parser.class {Parser}
%define api.namespace {utec::compilers}
%parse-param {FlexScanner* scanner} {int* result}

%code requires
{
    namespace utec::compilers {
        class FlexScanner;
    } // namespace utec::compilers
}

%code
{
    #include "FlexScanner.hpp"
    #define yylex(x) scanner->lex(x)
}


%union{
    std::string* op_val;
    int int_val;
}

%start	programa 

%token <int_val> NUMERO
%nterm <int_val> term factor
%token IDENTIFICADOR TIPO_ENTERO SIN_TIPO RETORNO MIENTRAS SI SINO MAIN
%token OP_COMP_DESIGUAL OP_COMP_IGUAL OP_COMP_MENOR OP_COMP_MAYOR OP_COMP_MENOR_IGUAL OP_COMP_MAYOR_IGUAL OP_SUMA OP_RESTA
%token OP_MUL OP_DIV ASIGNAR COMA PUNTO_COMA PAR_INICIO PAR_FINAL CORCH_INICIO CORCH_FINAL LLAVES_INICIO LLAVES_FINAL ERROR

%left	PLUS REST
%left	MULT


%%
/*
programa → lista_declaracion
lista_declaracion → lista_declaracion declaracion | declaracion
*/

programa:
    lista_declaracion {  *result = 1; }
;

lista_declaracion:
    lista_declaracion declaracion { std::cout << "Derivando a lista_declaracion declaracion \n" ; }
  | declaracion { std::cout << "Derivando a declaracion \n "; }
;

declaracion:
    TIPO_ENTERO IDENTIFICADOR declaracion_fact { std::cout << "fun declaracion1 \n"; }
  | SIN_TIPO IDENTIFICADOR PAR_INICIO params PAR_FINAL sent_compuesta { std::cout << "fun declaracion2 \n"; }
;

declaracion_fact:
    var_declaracion_fact {}
  | PAR_INICIO params PAR_FINAL sent_compuesta { std::cout << "esta corriendo bien" << std::endl; }
;

// var_declaracion:
//    TIPO_ENTERO IDENTIFICADOR var_declaracion_fact {}
//;

var_declaracion_fact:
    PUNTO_COMA {std::cout << "punto y coma" << std::endl;}
  | CORCH_INICIO NUMERO CORCH_FINAL PUNTO_COMA
;

/* tipo:
    TIPO_ENTERO { }
  | SIN_TIPO { }
; */

/* fun_declaracion:
    tipo IDENTIFICADOR PAR_INICIO params PAR_FINAL sent_compuesta { std::cout << "fun declaracion in \n"; }
; */


params:
    lista_params {}
  | { /* sin tipo cambiado por epsilon para representar que una funcion puede no tener parametros*/}
;

lista_params:
    lista_params COMA param {}
  | param {}
;

// TODO: Falta arreglar esta parte, la regla tipo se factorizo para que no hayan ambiguedad
param:
      TIPO_ENTERO IDENTIFICADOR {}
    | SIN_TIPO IDENTIFICADOR {}
    | TIPO_ENTERO IDENTIFICADOR CORCH_INICIO CORCH_FINAL {}
    | SIN_TIPO IDENTIFICADOR CORCH_INICIO CORCH_FINAL {}
;

sent_compuesta:
    LLAVES_INICIO declaracion_local lista_sentencias LLAVES_FINAL {std::cout << "sentencia compuesta" << std::endl;}
;

// TODO: Falta arregalr esta parte, la regla var_declaracion se factorizo para que no haya ambiguedad
declaracion_local:
    declaracion_local TIPO_ENTERO IDENTIFICADOR var_declaracion_fact {std::cout << "declaracion local" << std::endl;}
  |
;

lista_sentencias:
    lista_sentencias sentencia {std::cout << "LISTA SENTENCIAS" << std::endl;}
  |
;

sentencia:
    sentencia_expresion {}
  | sentencia_seleccion {}
  | sentencia_iteracion {}
  | sentencia_retorno {}
;

sentencia_expresion:
    sentencia_expresion_fact PUNTO_COMA {}
;

sentencia_expresion_fact:
    | expresion {}
;

sentencia_seleccion:
    SI PAR_INICIO expresion PAR_FINAL sentencia sentencia_seleccion_fact {}
;

sentencia_seleccion_fact:
    | SINO sentencia {}
;

sentencia_iteracion:
    MIENTRAS PAR_INICIO expresion PAR_FINAL LLAVES_INICIO lista_sentencias LLAVES_FINAL {}
;

sentencia_retorno:
    RETORNO PUNTO_COMA {}
  | RETORNO expresion PUNTO_COMA {std::cout << "RETORNO PUNTO_COMA" << std::endl; }
;

expresion:
    var ASIGNAR expresion {std::cout << "ASIGNAR" << std::endl;}
  | expresion_simple {}
;

var:
    IDENTIFICADOR {}
  | IDENTIFICADOR CORCH_INICIO expresion CORCH_FINAL {}
;

expresion_simple:
    expresion_aditiva relop expresion_aditiva {}
  | expresion_aditiva {}
;

relop:
    OP_COMP_MENOR  {}
  | OP_COMP_MENOR_IGUAL {}
  | OP_COMP_MAYOR  {}
  | OP_COMP_MAYOR_IGUAL {}
  | OP_COMP_IGUAL {}
  | OP_COMP_DESIGUAL {}
;

expresion_aditiva:
    expresion_aditiva addop term {}
  | term {}
;

addop:
    OP_SUMA {}
  | OP_RESTA {}
;

term:
    term mulop factor {}
  | factor {}
;

mulop:
    OP_MUL {}
  | OP_DIV {}
;

factor:
    PAR_INICIO expresion PAR_FINAL {}
  | var {}
  | call {}
  | NUMERO {}
;

call:
    IDENTIFICADOR PAR_INICIO args PAR_FINAL {}
;

args:
    lista_arg {}
  |
;

lista_arg:
    lista_arg COMA expresion {}
  | expresion {}
; 

%%

void utec::compilers::Parser::error(const std::string& msg) {
    std::cerr << msg << " " /*<< yylineno*/ <<'\n';
    //exit(1);
}