%{
#include "heading.h"
#include "calc.tab.h"
extern "C" int yylex();
int yyerror(char *s);
%}

DIGITO  [0-9]
LETRA   [a-z]|[A-Z]
OP_MUL    ["*"]
OP_DIV ["/"]
OP_MAYOR   [">"]
OP_MENOR   ["<"]
OP_IGUAL   ["=="] 
OP_DIFERENTE ["!="]
OP_MAYOR_IGUAL [">="]
OP_MENOR_IGUAL ["<="]
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

%%
entero   { return TIPO_ENTERO; }
sin_tipo { return SIN_TIPO; }
retorno  { return RETORNO; }
mientras { return MIENTRAS; }
si       { return SI; }
sino     { return SINO; }
main     { return MAIN; }

{LETRA}+  { yylval.op_val = new std::string(yytext); return IDENTIFICADOR; }
[+-]?{DIGITO}+ { yylval.int_val = atoi(yytext); return NUMERO;}

%{
    /* obviar comentarios */
%}
"/*"([^*]|\*+[^*/])*\*+"/" ;

%{
    /* simbolos especiales */
%}

{LLAVES_INICIO} { yylval.op_val = new std::string(yytext); return LLAVES_INICIO; }
{LLAVES_FINAL}  { yylval.op_val = new std::string(yytext); return LLAVES_FINAL; }
{PAR_INICIO}    { yylval.op_val = new std::string(yytext); return PAR_INICIO; }
{PAR_FINAL}     { yylval.op_val = new std::string(yytext); return PAR_FINAL; }
{CORCH_INICIO}  { yylval.op_val = new std::string(yytext); return CORCH_INICIO; }
"]"             { yylval.op_val = new std::string(yytext); return CORCH_FINAL; }
{OP_MAYOR}       { yylval.op_val = new std::string(yytext); return OP_COMP_MAYOR; } 
{OP_MENOR}       { yylval.op_val = new std::string(yytext); return OP_COMP_MENOR; }
{OP_IGUAL}       { yylval.op_val = new std::string(yytext); return OP_COMP_IGUAL; }
{OP_DIFERENTE}   { yylval.op_val = new std::string(yytext); return OP_COMP_DESIGUAL; }
">="            { yylval.op_val = new std::string(yytext); return OP_COMP_MAYOR_IGUAL; }
"<="            { yylval.op_val = new std::string(yytext); return OP_COMP_MENOR_IGUAL; }
{OP_SUMA}       { yylval.op_val = new std::string(yytext); return OP_SUMA; }
"-"             { yylval.op_val = new std::string(yytext); return OP_RESTA; }
{OP_MUL}        { yylval.op_val = new std::string(yytext); return OP_MUL; }
{OP_DIV}        { yylval.op_val = new std::string(yytext); return OP_DIV; }
"="             { yylval.op_val = new std::string(yytext); return ASIGNAR; }
{COMA}          { yylval.op_val = new std::string(yytext); return COMA; }


[a-z][a-z0-9]*                   { return ERROR; }
[^({LETRA}+|";"|"\n"|"&&")+]     { return ERROR; }
[\n]                             { yylineno++; }
.                                { std::cerr << "SCANNER "; yyerror(""); /*exit(1);*/	}

%%