%{
#include "Enums.h"
%}

%option noyywrap c++

DIGITO  [0-9]
LETRA   [a-z]
%%


%{
    /* palabras reservadas */
%}
entero|retorno|sin_tipo|mientras|si|sino|main return Categoria::RESERV_WORD;

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
"+" return Categoria::SUM_OP;
"-" return Categoria::MINUS_OP;
"*" return Categoria::MUL_OP;
"/" return Categoria::DIV_OP;
"<" return Categoria::RELOP;
"<=" return Categoria::RELOP;
">=" return Categoria::RELOP;
">" return Categoria::RELOP;
"=" return Categoria::ASSIGN;
"==" return Categoria::RELOP;
"!=" return Categoria::RELOP;
"," return Categoria::COLON;
"(" return Categoria::PAR_BEGIN;
")" return Categoria::PAR_END;
"[" return Categoria::SQR_BRACKET_BEGIN;
"]" return Categoria::SQR_BRACKET_END;
"{" return Categoria::CUR_BRACKET_BEGIN;
"}" return Categoria::CUR_BRACKET_END;


[^({LETRAS}+|" "|";"|"\n"|"&&")+] return Categoria::ERROR;
.|\n
%%