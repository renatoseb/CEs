%{
#include "Enums.h"
%}

%option noyywrap c++

DIGITO  [0-9]
LETRA   [a-z]|[A-Z]
%%


%{
    /* palabras reservadas */
%}
entero|retorno|sin_tipo|mientras|si|sino|main return Categoria::PALABRA_RESERVADA;

{LETRA}+  return Categoria::IDENTIFICADOR;
[+-]?{DIGITO}+ return Categoria::NUMERO;
[+-]?{DIGITO}+\.{DIGITO}[eE]?{DIGITO}?* return Categoria::NUMERO; 

%{
    /* obviar comentarios */
%}
"/*"([^*]|\*+[^*/])*\*+"/" ;

%{
    /* simbolos especiales */
%}
"+" return Categoria::OP_SUMA;
"-" return Categoria::OP_RESTA;
"*" return Categoria::OP_MUL;
"/" return Categoria::OP_DIV;
"=" return Categoria::ASIGNAR;
"==" | "!=" | ">" | "<" | ">=" | "<=" return Categoria::OP_COMP;
"," return Categoria::COMA;
"(" return Categoria::PAR_INICIO;
")" return Categoria::PAR_FINAL;
"[" return Categoria::CORCH_INICIO;
"]" return Categoria::CORCH_FINAL;
"{" return Categoria::LLAVES_INICIO;
"}" return Categoria::LLAVES_FINAL;


[^({LETRAS}+|" "|";"|"\n"|"&&")+] return Categoria::ERROR;
.|\n
%%
