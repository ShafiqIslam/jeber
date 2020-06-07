#include <iostream>
#include <string>
#include "error_handler.h"

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define WHITE   "\033[37m"

using namespace std;

int ErrorHandler::lineNo = 0;

int get_line_no()
{
	extern int yylineno;
    
	return ErrorHandler::lineNo ? ErrorHandler::lineNo : yylineno;
}

string get_token()
{
	extern char *yytext;
	string token = yytext;
	return token;
}

void ErrorHandler::error(string message) 
{ 
	message = "ERROR: " + message;

	string token = get_token();
	
	if (!token.empty()) {
		message += " near symbol \"" + token + "\"";
	}	
	
	message += " on line " + to_string(get_line_no());

    cerr << RED << message << RESET << endl;
}

void ErrorHandler::fatal(string message)
{
	ErrorHandler::error(message);
	exit(1);
}

