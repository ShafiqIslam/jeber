%{

#include "ast.h"
#include "error_handler.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

extern int yylex();

int yyerror(string s);
extern int yylineno;
	
extern Program* program;

%}

%define parse.error verbose
%union {
	char* string_value;
	int token;
	int int_value;
	double float_value;
	bool bool_value;

	Statement *statement;
	StatementList *statement_list;
	Expression *expression;
}

%token <string_value> IDENTIFIER STRING_LITERAL  
%token <int_value> INT_LITERAL
%token <float_value> FLOAT_LITERAL
%token <bool_value> BOOL_LITERAL
%token <int_value> NULL_LITERAL
%token
  	COMMA COLON SEMICOLON 
	LPARENTHESIS RPARENTHESIS LBRACKET RBRACKET LCURLYBRACE RCURLYBRACE
	
	PLUS MINUS MULTIPLY DIVIDE MODULUS ASSIGN AND OR NOT 
	EQUAL NOTEQUAL LESSTHAN LESSTHANEQUAL GREATERTHAN GREATERTHANEQUAL 
	
	VOID VARDECL INT STRING FLOAT BOOL ARRAY
	IF ELSE WHILE BREAK CONTINUE FUNCTION RETURN
	
%nonassoc IF WHILE ELSE ASSIGN
%nonassoc EQUAL NOTEQUAL LESSTHAN LESSTHANEQUAL GREATERTHAN GREATERTHANEQUAL
%left OR AND
%left PLUS MINUS
%left MULTIPLY DIVIDE MODULUS
%nonassoc TYPE
%nonassoc FUNCTION

%type<statement_list> statements
%type<statement> statement var_declaration
%type<expression> exp literal_exp arithmatic_exp logical_exp

%start program

%%

program:        /* nothing */
				| statements { program->setStatements($1); }

statements:		statement { $$ = new StatementList(); $1->setLineNo(yylineno); $$->push($1); }
				| statements statement { $2->setLineNo(yylineno); $1->push($2); }
				;

statement:		SEMICOLON { $$ = new EmptyStatement(); } 
                | exp SEMICOLON { $$ = new ExpressionStatement($1); }
				| var_declaration
				| IDENTIFIER ASSIGN exp { $$ = new AssignmentStatement($1, $3); }
                ;

exp:            literal_exp
                | arithmatic_exp
                | logical_exp
                ;

literal_exp:	INT_LITERAL { $$ = new IntegerExpression($1); }
				| FLOAT_LITERAL { $$ = new FloatExpression($1); }
				| STRING_LITERAL { $$ = new StringExpression($1); }
				| BOOL_LITERAL { $$ = new BoolExpression($1); }
				| NULL_LITERAL { $$ = NULL; }
				;

arithmatic_exp: exp PLUS exp { $$ = new PlusOperationExpression($1, $3); }
				| exp MINUS exp { $$ = new MinusOperationExpression($1, $3); }
				| exp MULTIPLY exp { $$ = new MultiplyOperationExpression($1, $3); }
				| exp DIVIDE exp { $$ = new DivideOperationExpression($1, $3); }
				| exp MODULUS exp { $$ = new ModulusOperationExpression($1, $3); }
				;

logical_exp: 	exp AND exp { $$ = new LogicalAndExpression($1, $3); }
				| exp OR exp { $$ = new LogicalOrExpression($1, $3); }
				| NOT exp { $$ = new LogicalNotExpression($2); }
				;

var_declaration	: VARDECL IDENTIFIER COLON INT { $$ = new IntegerVarDeclStatement($2); }
				| VARDECL IDENTIFIER COLON FLOAT { $$ = new FloatVarDeclStatement($2); }
				| VARDECL IDENTIFIER COLON STRING { $$ = new StringVarDeclStatement($2); }
				| VARDECL IDENTIFIER COLON BOOL { $$ = new BoolVarDeclStatement($2); }
				| VARDECL IDENTIFIER COLON ARRAY { $$ = new ArrayVarDeclStatement($2); }
				;

%%

int yyerror(string s)
{
	ErrorHandler::fatal(s);
	return 0;
}

