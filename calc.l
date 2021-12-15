%{
#include "heading.h"
#include "tok.h"
extern "C" int yylex();
int yyerror(char *s);
%}

DIGITO  [0-9]
uint_const	{DIGITO}+
LETRA   [a-z]|[A-Z]

%%

{uint_const}	{ yylval.int_val = atoi(yytext); return INTEGER_LITERAL; }
"+"		{ yylval.op_val = new std::string(yytext); return PLUS; }
"*"		{ yylval.op_val = new std::string(yytext); return MULT; }
"-"     { yylval.op_val = new std::string(yytext); return REST; }
"("     { return PAR_BEGIN; }
")"     { return PAR_END; }

[ \t]*		{}
[\n]		{ yylineno++;	}

.		{ std::cerr << "SCANNER "; yyerror(""); exit(1);	}


%{
    /* palabras reservadas */
%}
entero|retorno|sin_tipo|mientras|si|sino|main return PALABRA_RESERVADA;

{LETRA}+  { return IDENTIFICADOR; }
[+-]?{DIGITO}+ { yylval.intval = atoi(yytext); return NUMERO;}
[+-]?{DIGITO}+\.{DIGITO}[eE]?{DIGITO}?* {  yyval.fval = atof(yytext); return NUMERO; }

%{
    /* obviar comentarios */
%}
"/*"([^*]|\*+[^*/])*\*+"/" ;

%{
    /* simbolos especiales */
%}
"!="  { yylval.op_val = new std::string(yytext); return OP_COMP; }
"=="  { yylval.op_val = new std::string(yytext); return OP_COMP; }
"<"   { yylval.op_val = new std::string(yytext); return OP_COMP; }
">"   { yylval.op_val = new std::string(yytext); return OP_COMP; }
"<="  { yylval.op_val = new std::string(yytext); return OP_COMP; }
">="  { yylval.op_val = new std::string(yytext); return OP_COMP; }
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
.|\n