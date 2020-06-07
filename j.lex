%e  1019
%p  2807
%n  371
%k  284
%a  1213
%o  1117

O   [0-7]
D   [0-9]
NZ  [1-9]
L   [a-zA-Z_]
A   [a-zA-Z_0-9]
H   [a-fA-F0-9]
HP  (0[xX])
E   ([Ee][+-]?{D}+)
P   ([Pp][+-]?{D}+)
FS  (f|F|l|L)
IS  (((u|U)(l|L|ll|LL)?)|((l|L|ll|LL)(u|U)?))
CP  (u|U|L)
SP  (u8|u|U|L)
ES  (\\(['"\?\\abfnrtv]|[0-7]{1,3}|x[a-fA-F0-9]+))
WS  [ \t\v\n\f]

%{

#include <iostream>
#include <string>

using namespace std;
#include "ast.h"
#include "j.tab.h"

extern int yyerror(string s);
extern int yylineno;

%}

%%

"//".*                  { /* consume //-comment */ }

"var"					{ return VARDECL; }
"void"                  { return VOID; }
"int"                   { return INT; }
"float"                 { return FLOAT; }
"bool"                  { return BOOL; }
"string"                { return STRING; }
"array"					{ return ARRAY; }
"if"                    { return IF; }
"else"                  { return ELSE; }
"while"                 { return WHILE; }
"break"                 { return BREAK; }
"continue"              { return CONTINUE; }
"function"				{ return FUNCTION; }
"return"                { return RETURN; }

"true"                  { yylval.bool_value = true; return BOOL_LITERAL; }
"false"                 { yylval.bool_value = false; return BOOL_LITERAL; }
"nil"					{ return NULL_LITERAL; }
{L}{A}*                 { yylval.string_value = strdup(yytext); return IDENTIFIER; }
{D}+                	{ yylval.int_value = atoi(yytext); return INT_LITERAL; }
{D}+\.{D}+       		{ yylval.float_value = atof(yytext); return FLOAT_LITERAL; }
({SP}?\"([^"\\\n]|{ES})*\"{WS}*)+   { yylval.string_value = strdup(yytext); return STRING_LITERAL; }

"+"                     { return PLUS; }
"-"                     { return MINUS; }
"*"                     { return MULTIPLY; }
"/"                     { return DIVIDE; }
"%"                     { return MODULUS; }
"="                     { return ASSIGN; }
"&&"                    { return AND; }
"||"                    { return OR; }
"!"                     { return NOT; }
"=="                    { return EQUAL; }
"!="                    { return NOTEQUAL; }
"<"                     { return LESSTHAN; }
"<="                    { return LESSTHANEQUAL; }
">"                     { return GREATERTHAN; }
">="                    { return GREATERTHANEQUAL; }

","                     { return COMMA; }
":"                     { return COLON; }
";"                     { return SEMICOLON; }
"("                     { return LPARENTHESIS; }
")"                     { return RPARENTHESIS; }
"["                     { return LBRACKET; }
"]"                     { return RBRACKET; }
"{"                     { return LCURLYBRACE; }
"}"                     { return RCURLYBRACE; }

\n 						{ yylineno++; }
{WS}+                   { /* consume whitespace */ }
.                       { yyerror("Illegal character"); }

%%

int yywrap()
{
	return 1;
}

/*

"+="                    { return TOKEN(ADD_ASSIGN); }
"-="                    { return TOKEN(SUB_ASSIGN); }
"*="                    { return TOKEN(MUL_ASSIGN); }
"/="                    { return TOKEN(DIV_ASSIGN); }
"%="                    { return TOKEN(MOD_ASSIGN); }
"&="                    { return TOKEN(AND_ASSIGN); }
"++"                    { return TOKEN(INC_OP); }
"--"                    { return TOKEN(DEC_OP); }

*/

