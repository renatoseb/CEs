/* Mini Calculator */
/* calc.y */

%{
#include "heading.h"
int yyerror(char *s);
extern "C" int yylex();

/*
exp → exp opsuma term | term
opsuma → + | −
term → term opmult factor | factor
opmult → ∗
factor → (exp) | numero | '-' factor
*/

/*
4---1

exp -> exp opsuma term -> term opsuma term
-> factor opsuma term -> numero opsuma term
-> numero '-' term -> numero '-' factor
-> numero '-' '-' exp
... 
-> numero '-' '-' '-' exp
...
-> numero '-' '-' '-' numero

4-----2   = 2

4*-(1-2)  = 4

-4+-2     = -6

-1        = -1

-*2   = ERROR: syntax error at symbol "*" on line 1

-(2)  = -2

2-+-2  ERROR: syntax error at symbol "+" on line 1

-(1+2) = -3

--(3*-1) = -3

(--1)-(-1*-2) = -1
*/
%}

%union{
  int		int_val;
  string*	op_val;
}

%start	input

%token	<int_val>	INTEGER_LITERAL
%type	<int_val>	exp
%type	<int_val>	term
%type	<int_val>	factor
%token PAR_BEGIN
%token PAR_END
%left	PLUS
%left REST
%left	MULT

%%

input:		/* empty */
		| exp	{ cout << "Result: " << $1 << endl; }
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
    | oprest factor { $$ = - $2; }
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
