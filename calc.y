/* Mini Calculator */
/* calc.y */

%{

#include "heading.h"
int yyerror(char *s);
extern "C" int yylex();

%}

%union{
  int		int_val;
  string*	op_val;
}

%start	programa

%type	<int_val>	exp
%type	<int_val>	term
%type	<int_val>	factor

%token OP_COMP
%token ASIGNAR
%token COMA
%token OP_SUMA
%token OP_RESTA
%token OP_MUL
%token OP_DIV
%token	<int_val>	NUMERO
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
%token IDENTIFICADOR

%%
/*

programa → lista_declaracion
lista_declaracion → lista_declaracion declaracion | declaracion

*/

programa: 
      lista_declaracion { cout << "Sintactic Analysis OK \n."; }
;

lista_declaracion:  
      lista_declaracion declaracion { cout << "Derivando a lista_declaracion declaracion \n" ; }
    | declaracion { cout << "Derivando a declaracion \n "; }
    ;

declaracion:
    var_declaracion {}
  | fun_declaracion {}
  ;

var_declaracion:
    TIPO_ENTERO IDENTIFICADOR NUMERO { }
  | TIPO_ENTERO IDENTIFICADOR CORCH_INICIO NUMERO CORCH_FINAL { }
;

tipo:
    TIPO_ENTERO { }
  | SIN_TIPO { }
;

fun_declaracion:
    tipo IDENTIFICADOR PAR_INICIO params PAR_FINAL sent_compuesta {}
;

params:
    lista_params {}
  | SIN_TIPO {}
;

lista_params:
    lista_params COMA param {}
  | param {}
;

param:
    tipo IDENTIFICADOR {}
  | tipo IDENTIFICADOR CORCH_INICIO CORCH_FINAL {}
;

sent_compuesta:
    CORCH_INICIO declaracion_local lista_sentencias CORCH_FINAL {}
;

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
    expresion ; {}
  | ;
;

sentencia_seleccion:
    SI PAR_INICIO expresion PAR_FINAL sentencia {}
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