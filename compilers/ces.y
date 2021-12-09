%{

#include "heading.h"

extern int yylineno;
int yyerror(char *s);
extern "C" int yylex();

class util_token{
  int* valores;
  int tam;
  int declaracion;
  
public:
  util_token(){ }
  util_token(int _declaracion) {
    tam = 1;
    declaracion = declaracion;
    valores = new int[tam];
  }

  util_token(int _tam, int _declaracion) {
    tam = _tam;
    declaracion = _declaracion;
    valores = new int[tam];
  }
};

unordered_map<string*, util_token> tabla_simbolos;

%}

%union{
  int		int_val;
  string*	op_val;
}

%start	programa

%type	<int_val>	term
%type	<int_val>	factor

%token OP_COMP_IGUAL
%token OP_COMP_DESIGUAL
%token OP_COMP_MENOR
%token OP_COMP_MAYOR
%token OP_COMP_MENOR_IGUAL
%token OP_COMP_MAYOR_IGUAL
%token ASIGNAR
%token COMA 
%token OP_SUMA
%token OP_RESTA
%token OP_MUL
%token OP_DIV
%token <int_val>	NUMERO
%token PAR_INICIO
%token PAR_FINAL
%token CORCH_INICIO
%token CORCH_FINAL
%token LLAVES_INICIO
%token LLAVES_FINAL
%token TIPO_ENTERO
%token SIN_TIPO
%token SI
%token SINO
%token RETORNO
%token MIENTRAS
%token MAIN
%token <op_val> IDENTIFICADOR
%token PUNTO_COMA
%token ERROR

%%
/*

programa → lista_declaracion
lista_declaracion → lista_declaracion declaracion | declaracion

*/

programa:
    lista_declaracion {  }
;

lista_declaracion:
    lista_declaracion declaracion { cout << "Derivando a lista_declaracion declaracion \n" ; }
  | declaracion { cout << "Derivando a declaracion \n "; }
;

declaracion:
    TIPO_ENTERO IDENTIFICADOR declaracion_fact { cout << "fun declaracion \n"; }
  | SIN_TIPO IDENTIFICADOR PAR_INICIO params PAR_FINAL sent_compuesta { cout << "fun declaracion \n"; }
;

declaracion_fact:
  var_declaracion_fact
  | PAR_INICIO params PAR_FINAL sent_compuesta
;

// var_declaracion:
//    TIPO_ENTERO IDENTIFICADOR var_declaracion_fact {}
//;

var_declaracion_fact:
    PUNTO_COMA
  | CORCH_INICIO NUMERO CORCH_FINAL PUNTO_COMA
;

/* tipo:
    TIPO_ENTERO { }
  | SIN_TIPO { }
; */

/* fun_declaracion:
    tipo IDENTIFICADOR PAR_INICIO params PAR_FINAL sent_compuesta { cout << "fun declaracion in \n"; }
; */


params:
    lista_params {}
  | SIN_TIPO {}
;

lista_params:
    lista_params COMA param {}
  | param {}
;

// TODO: Falta arreglar esta parte, la regla tipo se factorizo para que no hayan ambiguedad
param:
    tipo IDENTIFICADOR {}
  | tipo IDENTIFICADOR CORCH_INICIO CORCH_FINAL {}
;

sent_compuesta:
    LLAVES_INICIO declaracion_local lista_sentencias LLAVES_FINAL {}
;

// TODO: Falta arregalr esta parte, la regla var_declaracion se factorizo para que no haya ambiguedad
declaracion_local:
    declaracion_local var_declaracion {}
  | 
;

lista_sentencias:
    lista_sentencias sentencia {}
  | 
;

sentencia:
    sentencia_expresion {}
  | sentencia_seleccion {}
  | sentencia_iteracion {}
  | sentencia_retorno {}
;

sentencia_expresion:
    expresion PUNTO_COMA {}
  | PUNTO_COMA
;

sentencia_seleccion:
    SI PAR_INICIO expresion PAR_FINAL sentencia {}
  | SI PAR_INICIO expresion PAR_FINAL sentencia SINO sentencia {}
;

sentencia_iteracion:
    MIENTRAS PAR_INICIO expresion PAR_FINAL LLAVES_INICIO lista_sentencias LLAVES_FINAL {}
;

sentencia_retorno:
    RETORNO PUNTO_COMA {}
  | RETORNO expresion PUNTO_COMA {}
;

expresion:
    var ASIGNAR expresion {}
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

int yyerror(string s)
{
  extern int yylineno;	// defined and maintained in lex.c
  extern char *yytext;	// defined and maintained in lex.c
  
  cerr << "ERROR: " << s << " at symbol \"" << yytext;
  cerr << "\" on line " << yylineno << endl;
  exit(1);
}

int yyerror(char *s)
{
  return yyerror(string(s));
}