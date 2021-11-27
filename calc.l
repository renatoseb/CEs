%{
#include "heading.h"
#include "tok.h"
extern "C" int yylex();
int yyerror(char *s);
%}

DIGITO  [0-9]
LETRA   [a-z]|[A-Z]

%%

%{
    /* palabras reservadas */
    /* retorno|mientras|si|sino|main return PALABRA_RESERVADA; */
%}

entero { return TIPO_ENTERO; }
sin_tipo { return SIN_TIPO; }
retorno { return RETORNO; }
mientras { return MIENTRAS; }
si { return SI; }
sino { return SINO; }
main { return MAIN; }

{LETRA}+  { return IDENTIFICADOR; }
[+-]?{DIGITO}+ { yylval.intval = atoi(yytext); return NUMERO;}

%{
    /* obviar comentarios */
%}
"/*"([^*]|\*+[^*/])*\*+"/" ;

%{
    /* simbolos especiales */
%}
"!="  { yylval.op_val = new std::string(yytext); return OP_COMP_DESIGUAL; }
"=="  { yylval.op_val = new std::string(yytext); return OP_COMP_IGUAL; }
"<"   { yylval.op_val = new std::string(yytext); return OP_COMP_MENOR; }
">"   { yylval.op_val = new std::string(yytext); return OP_COMP_MAYOR; }
"<="  { yylval.op_val = new std::string(yytext); return OP_COMP_MENOR_IGUAL; }
">="  { yylval.op_val = new std::string(yytext); return OP_COMP_MAYOR_IGUAL; }
"+"   { yylval.op_val = new std::string(yytext); return OP_SUMA; }
"-"   { yylval.op_val = new std::string(yytext); return OP_RESTA; }
"*"   { yylval.op_val = new std::string(yytext); return OP_MUL; }
"/"   { yylval.op_val = new std::string(yytext); return OP_DIV; }
"="   { yylval.op_val = new std::string(yytext); return ASIGNAR; }
","   { yylval.op_val = new std::string(yytext); return COMA; }
"(" return PAR_INICIO;
")" return PAR_FINAL;
"[" return CORCH_INICIO;
"]" return CORCH_FINAL;
"{" return LLAVES_INICIO;
"}" return LLAVES_FINAL;

[a-z][a-z0-9]* { return ERROR; } 
[^({LETRA}+|" "|";"|"\n"|"&&")+] { return ERROR; }
[ \t]*		{}
[\n]		{ yylineno++;	}

.		{ std::cerr << "SCANNER "; yyerror(""); exit(1);	}