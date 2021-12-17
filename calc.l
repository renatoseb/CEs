/* Mini Calculator */
/* calc.lex */

%{
#include "heading.h"
#include "calc.tab.h" // #include "tok.h"
extern "C" int yylex();
int yyerror(char *s);
%}

DIGITO  [0-9]
LETRA   [a-zA-Z]
OP_MUL    ["*"]
OP_DIV ["/"]
OP_IGUAL   ["=="] 
OP_DIFERENTE ["!="]
OP_MAYOR_IGUAL [">="]
OP_MENOR_IGUAL ["<="]
OP_MAYOR   [">"]
OP_MENOR   ["<"]
OP_SUMA   ["+"]
OP_RESTA   ["-"] 
PAR_INICIO ["("]
PAR_FINAL  [")"]
LLAVES_INICIO ["{"]
LLAVES_FINAL  ["}"]
CORCH_INICIO ["["]
CORCH_FINAL ["]"]

ASIGNAR ["="]
COMA [","]

ENTERO entero
RETORNO retorno
SIN_TIPO sin_tipo
MIENTRAS mientras
SI si
SINO sino
MAIN main

%%
[ ]+|" " { std::cout << "ESPACIO" << std::endl; }
[+-]?{DIGITO}+ { yylval.op_val = new std::string(yytext); std::cout << "AQUI ESTA 01" << std::endl; return NUMERO;}
entero   { std::cout << "AQUI ESTAAAA 1" << std::endl; return TIPO_ENTERO; }
sin_tipo { std::cout << "AQUI ESTAAAA 2" << std::endl; return SIN_TIPO; }
retorno  { std::cout << "AQUI ESTAAAA 3" << std::endl; return RETORNO; }
mientras { std::cout << "AQUI ESTAAAA 4" << std::endl; return MIENTRAS; }
si       { std::cout << "AQUI ESTAAAA 5" << std::endl; return SI; }
sino    { std::cout << "AQUI ESTAAAA 6" << std::endl; return SINO; }
main     { std::cout << "AQUI ESTAAAA 7" << std::endl; return MAIN; }

"/*"([^*]|\*+[^*/])*\*+"/" ;
{LLAVES_INICIO}  { yylval.op_val = new std::string(yytext); std::cout << "AQUI ESTA 1" << std::endl; return LLAVES_INICIO; }
{LLAVES_FINAL}   { yylval.op_val = new std::string(yytext); std::cout << "AQUI ESTA 2" << std::endl; return LLAVES_FINAL; }
{PAR_INICIO}     { yylval.op_val = new std::string(yytext); std::cout << "AQUI ESTA 3" << std::endl; return PAR_INICIO; }
{PAR_FINAL}      { yylval.op_val = new std::string(yytext); std::cout << "AQUI ESTA 4" << std::endl; return PAR_FINAL; }
{CORCH_INICIO}   { yylval.op_val = new std::string(yytext); std::cout << "AQUI ESTA 5" << std::endl; return CORCH_INICIO; }
"]"              { yylval.op_val = new std::string(yytext); std::cout << "AQUI ESTA 6" << std::endl; return CORCH_FINAL; }
">="             { yylval.op_val = new std::string(yytext); std::cout << "AQUI ESTA 11" << std::endl; return OP_COMP_MAYOR_IGUAL; }
"<="             { yylval.op_val = new std::string(yytext); std::cout << "AQUI ESTA 12" << std::endl; return OP_COMP_MENOR_IGUAL; }
{OP_MAYOR}       { yylval.op_val = new std::string(yytext); std::cout << "AQUI ESTA 7" << std::endl; return OP_COMP_MAYOR; }
{OP_MENOR}       { yylval.op_val = new std::string(yytext); std::cout << "AQUI ESTA 8" << std::endl; return OP_COMP_MENOR; }
"=="             { yylval.op_val = new std::string(yytext); std::cout << "AQUI ESTA 9" << std::endl; return OP_COMP_IGUAL; }
"="              { yylval.op_val = new std::string(yytext); std::cout << "AQUI ESTA 17" << std::endl; return ASIGNAR; }
{OP_DIFERENTE}   { yylval.op_val = new std::string(yytext); std::cout << "AQUI ESTA 10" << std::endl; return OP_COMP_DIFERENTE; }
"+"              { yylval.op_val = new std::string(yytext); std::cout << "AQUI ESTA 13" << std::endl; return OP_SUMA; }
"-"              { yylval.op_val = new std::string(yytext); std::cout << "AQUI ESTA 14" << std::endl; return OP_RESTA; }
{OP_MUL}         { yylval.op_val = new std::string(yytext); std::cout << "AQUI ESTA 15" << std::endl; return OP_MUL; }
{OP_DIV}         { yylval.op_val = new std::string(yytext); std::cout << "AQUI ESTA 16" << std::endl; return OP_DIV; }
{COMA}           { yylval.op_val = new std::string(yytext); std::cout << "AQUI ESTA 18" << std::endl; return COMA; }
{LETRA}+         { yylval.op_val = new std::string(yytext); std::cout << "AQUI ESTA 0" << std::endl; return IDENTIFICADOR; }
";"              { yylval.op_val = new std::string(yytext); std::cout << "AQUI ESTA PC" << std::endl; return PUNTO_COMA; }

[a-z][a-z0-9]*                    { std::cout << "AQUI ESTA 19" << std::endl; return ERROR; }
[^({LETRA}+|";"|"\n"|"&&"|" ")+]  { std::cout << "AQUI ESTA 20" << std::endl; return ERROR; }
[\n]                              { yylineno++; }
.                                 { std::cerr << "SCANNER "; yyerror(""); /*exit(1);*/	}

%%