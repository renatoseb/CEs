%{
    #include "heading.h"
    #include "parser.hpp"
    #include "FlexScanner.hpp"
    #define YY_DECL int utec::compilers::FlexScanner::lex(utec::compilers::Parser::semantic_type *yylval)
%}

%option c++ interactive noyywrap noyylineno nodefault

DIGITO		[0-9]
LETRA	    [a-zA-Z]

%%

entero { return Parser::token::TIPO_ENTERO; }
sin_tipo { return Parser::token::SIN_TIPO; }
retorno { return Parser::token::RETORNO; }
mientras { return Parser::token::MIENTRAS; }
si { return Parser::token::SI; }
sino { return Parser::token::SINO; }
main { return Parser::token::MAIN; }

{LETRA}+ { yylval->op_val = new std::string(yytext); return Parser::token::IDENTIFICADOR; }
[+-]?{DIGITO}+	{ yylval->int_val = atoi(yytext); return Parser::token::NUMERO; }

%{
    /* obviar comentarios */
%}
"/*"([^*]|\*+[^*/])*\*+"/" ;


"!="  { yylval->op_val = new std::string(yytext); return Parser::token::OP_COMP_DESIGUAL; }
"=="  { yylval->op_val = new std::string(yytext); return Parser::token::OP_COMP_IGUAL; }
"<"   { yylval->op_val = new std::string(yytext); return Parser::token::OP_COMP_MENOR; }
">"   { yylval->op_val = new std::string(yytext); return Parser::token::OP_COMP_MAYOR; }
"<="  { yylval->op_val = new std::string(yytext); return Parser::token::OP_COMP_MENOR_IGUAL; }
">="  { yylval->op_val = new std::string(yytext); return Parser::token::OP_COMP_MAYOR_IGUAL; }
"+"   { yylval->op_val = new std::string(yytext); return Parser::token::OP_SUMA; }
"-"   { yylval->op_val = new std::string(yytext); return Parser::token::OP_RESTA; }
"*"   { yylval->op_val = new std::string(yytext); return Parser::token::OP_MUL; }
"/"   { yylval->op_val = new std::string(yytext); return Parser::token::OP_DIV; }
"="   { yylval->op_val = new std::string(yytext); return Parser::token::ASIGNAR; }
","   { yylval->op_val = new std::string(yytext); return Parser::token::COMA; }
";"   { yylval->op_val = new std::string(yytext); return Parser::token::PUNTO_COMA; }
"("   { yylval->op_val = new std::string(yytext); return Parser::token::PAR_INICIO; }
")"   { yylval->op_val = new std::string(yytext); return Parser::token::PAR_FINAL; }
"["   { yylval->op_val = new std::string(yytext); return Parser::token::CORCH_INICIO;}
"]"   { yylval->op_val = new std::string(yytext); return Parser::token::CORCH_FINAL; }
"{"   { yylval->op_val = new std::string(yytext); return Parser::token::LLAVES_INICIO; }
"}"   { yylval->op_val = new std::string(yytext); return Parser::token::LLAVES_FINAL; }

"+"		{ return Parser::token::PLUS; }
"*"		{ return Parser::token::MULT; }
"-"     { return Parser::token::REST; }
"("     { return Parser::token::PAR_BEGIN; }
")"     { return Parser::token::PAR_END; }

[a-z][a-z0-9]* { return Parser::token::ERROR; }
[^({LETRA}+|" "|";"|"\n"|"&&")+] { return Parser::token::ERROR; }
[ \t]*		{}
[\n]		{  yylineno++; }

.		{ std::cout<<"Error\n"; std::cerr << "SCANNER "; /*yyerror("");*/ exit(1);	}

%%

int yyFlexLexer::yylex() {
    throw std::runtime_error("Invalid call to yyFlexLexer::yylex()");
}
