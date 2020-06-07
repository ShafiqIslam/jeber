#include <iostream>
#include "ast.h"

extern int yyparse(void);
extern FILE *yyin;

using namespace std;

Program* program;

int main(int argc, char **argv)
{
	if (argc != 2) {
        cerr << "usage: a.out filename" << endl; 
        exit(1);
    }

	char* filename = argv[1];
	yyin = fopen(filename, "r");
    if (!yyin) {
        cerr << "cannot open " << filename << endl;
        exit(1);
    }

	program = new Program();
	
	yyparse();
	
	program->execute();

	return 0;
}
