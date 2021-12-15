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

%start	input 

%token	<int_val>	INTEGER_LITERAL NUMERO
%nterm <int_val> exp term factor
%token PAR_BEGIN PAR_END IDENTIFICADOR TIPO_ENTERO SIN_TIPO RETORNO MIENTRAS SI SINO MAIN 
%token OP_COMP_DESIGUAL OP_COMP_IGUAL OP_COMP_MENOR OP_COMP_MAYOR OP_COMP_MENOR_IGUAL OP_COMP_MAYOR_IGUAL OP_SUMA OP_RESTA
%token OP_MUL OP_DIV ASIGNAR COMA PUNTO_COMA PAR_INICIO PAR_FINAL CORCH_INICIO CORCH_FINAL LLAVES_INICIO LLAVES_FINAL ERROR

%left	PLUS REST
%left	MULT


%%

input:		/* empty */
		| exp	{ *result = $1; }
		;

exp:  exp opsuma term { $$ = $1 + $3; }
    | exp oprest term { $$ = $1 - $3; }
    | term  { $$ = $1; }
    ;

opsuma: PLUS
    ;

oprest: REST
    ;

term: term opmult factor  { $$ = $1 * $3; }
    | factor  { $$ = $1; }
    ;

opmult: MULT
    ;

factor: PAR_BEGIN exp PAR_END { $$ = $2; }
    | INTEGER_LITERAL 	{ $$ = $1; }
    ;
%%

void utec::compilers::Parser::error(const std::string& msg) {
    std::cerr << msg << " " /*<< yylineno*/ <<'\n';
    exit(1);
}