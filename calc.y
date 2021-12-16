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
  string* str;
}

%start	programa

%token <int_val> NUMERO
%type <int_val> term factor expresion_aditiva
%type <str> var_declaracion_fact declaracion_fact params lista_params param expresion var
%type <str> IDENTIFICADOR
%token IDENTIFICADOR TIPO_ENTERO SIN_TIPO RETORNO MIENTRAS SI SINO MAIN
%token OP_COMP_DESIGUAL OP_COMP_IGUAL OP_COMP_MENOR OP_COMP_MAYOR OP_COMP_MENOR_IGUAL OP_COMP_MAYOR_IGUAL OP_SUMA OP_RESTA
%token OP_MUL OP_DIV ASIGNAR COMA PUNTO_COMA PAR_INICIO PAR_FINAL CORCH_INICIO CORCH_FINAL LLAVES_INICIO LLAVES_FINAL ERROR

%%

/* GRAMATICA */

programa:
    lista_declaracion {  yyresult = 1; }
;

lista_declaracion:
    lista_declaracion declaracion { std::cout << "Derivando a lista_declaracion declaracion \n" ; }
  | declaracion { std::cout << "Derivando a declaracion \n "; }
;

declaracion:
    TIPO_ENTERO IDENTIFICADOR declaracion_fact {
      if (string(*$2)==".") {
        std::cout << "ok_punto" << std::endl;
        anhadir_id_var(string(*$2));
      }
      if(!anhadir_id_var(string(*$2)))
      {
        yyerror("La variable ya ha sido definida");
      }
      std::cout << "fun declaracion1 \n"; 
    
    }
      | SIN_TIPO IDENTIFICADOR PAR_INICIO params PAR_FINAL sent_compuesta { 
        if(!anhadir_id_function(string(*$2), string(*$4)))
        {
          yyerror("La funcion ya ha sido definida");
        }
        std::cout << "fun declaracion2 \n"; 
      }
;

declaracion_fact:
    var_declaracion_fact { $$ = $1; }
  | PAR_INICIO params PAR_FINAL sent_compuesta { $$ = $2; }
;

// var_declaracion:
//    TIPO_ENTERO IDENTIFICADOR var_declaracion_fact {}
//;

var_declaracion_fact:
    PUNTO_COMA { 
        string *var1 = new string(".");
        $$ = var1; 
      }
  | CORCH_INICIO NUMERO CORCH_FINAL PUNTO_COMA {
      string* t = new string(to_string($2));
      $$ = t;
    }
;

/* tipo:
    TIPO_ENTERO { }
  | SIN_TIPO { }
; */

/* fun_declaracion:
    tipo IDENTIFICADOR PAR_INICIO params PAR_FINAL sent_compuesta { std::cout << "fun declaracion in \n"; }
; */


params:
    lista_params { 
      string *var = new string("params");
      $$ = var; 
      }
  | { /* sin tipo cambiado por epsilon para representar que una funcion puede no tener parametros*/ }
;

lista_params:
    lista_params COMA param { $$ = $1; }
  | param { $$ = $1; }
;

// TODO: Falta añadir verificacion de parametros
param:
      TIPO_ENTERO IDENTIFICADOR { $$ = $2; }
    | SIN_TIPO IDENTIFICADOR { $$ = $2; }
    | TIPO_ENTERO IDENTIFICADOR CORCH_INICIO CORCH_FINAL { $$ = $2; }
    | SIN_TIPO IDENTIFICADOR CORCH_INICIO CORCH_FINAL { $$ = $2; }
;

sent_compuesta:
    LLAVES_INICIO declaracion_local lista_sentencias LLAVES_FINAL {std::cout << "sentencia compuesta" << std::endl;}
;

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

// state 105
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
    var ASIGNAR expresion 
    {
      if(existe_variable(string(*$1)))
      {
        modificar_variable(string(*$1), string(*$3));
      }
      std::cout << "ASIGNAR" << std::endl;
    }
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
    expresion_aditiva OP_SUMA term {}
  |  expresion_aditiva OP_RESTA term {}
  | term {}
;

/* addop:
    OP_SUMA {}
  | OP_RESTA {}
; */

term:
    term OP_MUL factor {}
  | term OP_DIV factor {}
  | factor {}
;

/* mulop:
    OP_MUL {}
  | OP_DIV {}
; */

factor:
    PAR_INICIO expresion PAR_FINAL {
      $$ = stoi(*$2);
    }
  | var {}
  | call {}
  | NUMERO {
      $$ = $1;
    }
;

call:
    IDENTIFICADOR PAR_INICIO args PAR_FINAL 
    {  
      if(!existe_funcion(string(*$1)))
      {
        // char *var1 = new char("La funcion ");
        // char *var2 = new char(" no ha sido definida anteriomente");
        // char var3 = *var1 + string(*$1) + var2; 
        yyerror("La funcion no ha sido definada anteriormente");
      }
    }
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
