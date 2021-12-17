/* Mini Calculator */
/* calc.y */

%{
#include "heading.h"
#include "table.cpp"
int yyerror(char *s);
extern "C" int yylex();
%}

%union{
  int		int_val;
  string*	op_val;
}

%start	programa

%token <op_val> NUMERO

%token <op_val> IDENTIFICADOR
%token <op_val> TIPO_ENTERO
%token SIN_TIPO RETORNO MIENTRAS SI SINO MAIN
%token OP_COMP_DIFERENTE OP_COMP_IGUAL OP_COMP_MENOR OP_COMP_MAYOR OP_COMP_MENOR_IGUAL OP_COMP_MAYOR_IGUAL OP_SUMA OP_RESTA
%token OP_MUL OP_DIV ASIGNAR COMA PUNTO_COMA PAR_INICIO PAR_FINAL CORCH_INICIO CORCH_FINAL LLAVES_INICIO LLAVES_FINAL ERROR
%type <op_val> expresion var params param lista_params args expresion_simple fun_declaracion var_declaracion p
%type <op_val> expresion_aditiva relop

%%

programa:
    lista_declaracion { /* std::cout << "lista declaracion" << std::endl; */ }
;

lista_declaracion:
    lista_declaracion declaracion { /* std::cout << "Derivando a lista_declaracion declaracion \n"; */ }
  | declaracion { /* std::cout << "Derivando a declaracion \n "; */ }
;

declaracion:
    var_declaracion {}
  | fun_declaracion {}
;

/*
declaracion_fact:
    var_declaracion_fact { $$ = $1; }
  | PAR_INICIO params PAR_FINAL sent_compuesta { $$ = $2; }
;
*/

var_declaracion:
    TIPO_ENTERO IDENTIFICADOR PUNTO_COMA {
      // std::cout << "hola" << std::endl;
      if(!anhadir_id_var(string(*$2)))
      {
        char* a = "La variable \"";
        char* b = "\" ya ha sido definida";
        char buffer[100];
        strcat(strcpy(buffer, a), string(*$2).c_str());
        strcat(buffer, b);
        yyerror(buffer);
      }
    }
  | TIPO_ENTERO IDENTIFICADOR CORCH_INICIO NUMERO CORCH_FINAL PUNTO_COMA {
      // std::cout << "hola" << std::endl;
      if(!anhadir_id_arreglo(string(*$2), stoi(string(*$4))))
      {
        char* a = "La variable \"";
        char* b = "\" ya ha sido definida";
        char buffer[100];
        strcat(strcpy(buffer, a), string(*$2).c_str());
        strcat(buffer, b);
        yyerror(buffer);
      }
  }
;

/*
var_declaracion_fact:
    PUNTO_COMA { 
        string var1 = new string(".");
        $$ = &var1;
      }
  | CORCH_INICIO NUMERO CORCH_FINAL PUNTO_COMA {
      string* t = new string(to_string($2));
      $$ = t;
    }
;
*/

/* tipo:
    TIPO_ENTERO { }
  | SIN_TIPO { }
; */

fun_declaracion:
    TIPO_ENTERO IDENTIFICADOR PAR_INICIO params PAR_FINAL sent_compuesta {
      if(!anhadir_id_function(string(*$2), string(*$4))) {
          yyerror("La funcion ya ha sido declarada");
      }
      //std::cout << "params fun declaracion: " << string(*$4) << std::endl;
    }
  | SIN_TIPO IDENTIFICADOR PAR_INICIO params PAR_FINAL sent_compuesta {
      // string s = string(*$2);
      if(!anhadir_id_function(string(*$2), string(*$4))) {
          yyerror("La funcion ya ha sido declarada");
      }
  }
  | TIPO_ENTERO MAIN PAR_INICIO params PAR_FINAL sent_compuesta {
      string s = "main";
      if(!anhadir_id_function(s, string(*$4))) {
          yyerror("La funcion ya ha sido declarada");
      }
  }
  | SIN_TIPO MAIN PAR_INICIO params PAR_FINAL sent_compuesta {
      string s = "main";
      if(!anhadir_id_function(s , string(*$4))) {
          yyerror("La funcion ya ha sido declarada");
      }
  }
;

params:
    lista_params {
      /*
      string *var = new string("params");
      */
      // std::cout << "lista params in params: " << string(*$1) << std::endl;
      $$ = $1;
    }
  |  SIN_TIPO {
    yyerror("Variable sin tipo declarada");
  }
  | {
      string s=""; $$ = &s; /* se agrego epsilon para representar que una funcion puede no tener parametros*/
    }
;

lista_params: lista_params COMA p  {
      // std::cout << "lista params 2da: " << string(*$1) << std::endl;
      string t =  string(*$1) + "," + string(*$3);
      $$ = &t;
    }
    | 
    p {
      // std::cout << "lista params(regla param) 1ra: " << string(*$1) << std::endl;
      $$ = $1; 
    }
;

p:
  param {$$ = $1;}
;

// TODO: Falta añadir verificacion de parametros
param: TIPO_ENTERO IDENTIFICADOR {
          // std::cout << "param: " << string(*$2) << std::endl;
          $$ = $2;
       }
    |   SIN_TIPO IDENTIFICADOR {  }
    |   TIPO_ENTERO IDENTIFICADOR CORCH_INICIO CORCH_FINAL {  }
    |   SIN_TIPO IDENTIFICADOR CORCH_INICIO CORCH_FINAL {  }  
;

// regla 10
sent_compuesta:
    LLAVES_INICIO declaracion_local lista_sentencias LLAVES_FINAL {std::cout << "sentencia compuesta" << std::endl;}
;

// regla 11
declaracion_local:
    declaracion_local var_declaracion {std::cout << "declaracion local" << std::endl;}
  |
;

// regla 12
lista_sentencias:
    lista_sentencias sentencia {std::cout << "LISTA SENTENCIAS" << std::endl;}
  |
;

// regla 13
sentencia:
    sentencia_expresion {}
  | sentencia_seleccion {}
  | sentencia_iteracion {}
  | sentencia_retorno {}
;

// regla 14
sentencia_expresion:
    expresion PUNTO_COMA {}
  | PUNTO_COMA {}
;

// regla 15
sentencia_seleccion:
    SI PAR_INICIO expresion PAR_FINAL LLAVES_INICIO lista_sentencias LLAVES_FINAL SINO LLAVES_INICIO sentencia LLAVES_FINAL {}
  | SI PAR_INICIO expresion PAR_FINAL LLAVES_INICIO lista_sentencias LLAVES_FINAL {}
;

// regla 16
sentencia_iteracion:
    MIENTRAS PAR_INICIO expresion PAR_FINAL LLAVES_INICIO lista_sentencias LLAVES_FINAL {}
;

// regla 17
sentencia_retorno:
    RETORNO PUNTO_COMA {}
  | RETORNO expresion PUNTO_COMA {std::cout << "RETORNO PUNTO_COMA" << std::endl; }
;

// regla 18
expresion:
    var ASIGNAR expresion 
    {
      
    }
  | expresion_simple {}
;

// regla 19
var:
    IDENTIFICADOR {}
  | IDENTIFICADOR CORCH_INICIO expresion CORCH_FINAL {}
;

// regla 20
expresion_simple:
    expresion_aditiva relop expresion_aditiva {}
  | expresion_aditiva {}
;

// regla 21
relop:
    OP_COMP_MENOR  {}
  | OP_COMP_MENOR_IGUAL {}
  | OP_COMP_MAYOR  {}
  | OP_COMP_MAYOR_IGUAL {}
  | OP_COMP_IGUAL {}
  | OP_COMP_DIFERENTE {}
;

// regla 22
expresion_aditiva:
    expresion_aditiva OP_SUMA term {}
  | expresion_aditiva OP_RESTA term {}
  | term {}
;

/* addop:
    OP_SUMA {}
  | OP_RESTA {}
; */

// regla 24
term:
    term OP_MUL factor {}
  | term OP_DIV factor {}
  | factor {}
;

/* mulop:
    OP_MUL {}
  | OP_DIV {}
; */

// regla 26
factor:
    PAR_INICIO expresion PAR_FINAL {
      
    }
  | var {}
  | call {}
  | NUMERO {
    
    }
;

// regla 27
call:
    IDENTIFICADOR PAR_INICIO args PAR_FINAL 
    {
      
    }
;

// regla 28
args:
    lista_arg {}
  |
;

// regla 29
lista_arg:
    lista_arg COMA expresion {}
  | expresion {}
;

%%

int yyerror(string s)
{
  extern int yylineno;	// defined and maintained in lex.c
  extern char *yytext;	// defined and maintained in lex.c
  
  cerr << "ERROR: " << s;
  cerr << " en la linea " << yylineno << endl;
  exit(1);
}

int yyerror(char *s)
{
  return yyerror(string(s));
}
