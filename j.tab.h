/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_J_TAB_H_INCLUDED
# define YY_YY_J_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    STRING_LITERAL = 259,
    INT_LITERAL = 260,
    FLOAT_LITERAL = 261,
    BOOL_LITERAL = 262,
    NULL_LITERAL = 263,
    COMMA = 264,
    COLON = 265,
    SEMICOLON = 266,
    LPARENTHESIS = 267,
    RPARENTHESIS = 268,
    LBRACKET = 269,
    RBRACKET = 270,
    LCURLYBRACE = 271,
    RCURLYBRACE = 272,
    PLUS = 273,
    MINUS = 274,
    MULTIPLY = 275,
    DIVIDE = 276,
    MODULUS = 277,
    ASSIGN = 278,
    AND = 279,
    OR = 280,
    NOT = 281,
    EQUAL = 282,
    NOTEQUAL = 283,
    LESSTHAN = 284,
    LESSTHANEQUAL = 285,
    GREATERTHAN = 286,
    GREATERTHANEQUAL = 287,
    VOID = 288,
    VARDECL = 289,
    INT = 290,
    STRING = 291,
    FLOAT = 292,
    BOOL = 293,
    ARRAY = 294,
    IF = 295,
    ELSE = 296,
    WHILE = 297,
    BREAK = 298,
    CONTINUE = 299,
    FUNCTION = 300,
    RETURN = 301,
    TYPE = 302
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 22 "j.y" /* yacc.c:1909  */

	char* string_value;
	int token;
	int int_value;
	double float_value;
	bool bool_value;

	Statement *statement;
	StatementList *statement_list;
	Expression *expression;

#line 114 "j.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_J_TAB_H_INCLUDED  */
