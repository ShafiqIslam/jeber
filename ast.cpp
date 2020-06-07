#include "ast.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void Program::setStatements(StatementList* stmts)
{
	Scope* global_scope = new Scope();
	this->statements = stmts;
	for (Statement* statement : this->statements->getAll()) { 
        statement->setScope(global_scope);
	}
}

void Program::execute()
{
	for (Statement* statement : this->statements->getAll()) {
		ErrorHandler::setLineNo(statement->getLineNo());
        statement->execute();
	}
}

void AssignmentStatement::execute()
{
	cout << "find: " << this->identifier << endl;
	VariableSymbol* s = (VariableSymbol*) this->getScope()->getSymbolTable()->find(this->identifier);
	AssignmentStatement::assign(s->getVariable(), this->exp);
}

void AssignmentStatement::assign(Variable* var, Expression* exp)
{
	cout << "Assign value to variable: "; exp->printValue();
}

void ExpressionStatement::execute()
{
	this->exp->printValue();
}

void IntegerVarDeclStatement::execute()
{
	IntegerVariable* i = new IntegerVariable();
	VariableSymbol* s = new VariableSymbol(this->identifier, new IntegerVariable());
	this->getScope()->getSymbolTable()->insert(s);
	if (this->exp != NULL) {
		AssignmentStatement::assign(i, this->exp);
	}
}

void FloatVarDeclStatement::execute()
{
	VariableSymbol* s = new VariableSymbol(this->identifier, new FloatVariable());
	this->getScope()->getSymbolTable()->insert(s);
	/*if (this->exp != NULL) {
		AssignmentStatement* a = new AssignmentStatement();
		a->assign(f, this->exp);
	}*/
}

void StringVarDeclStatement::execute()
{
	VariableSymbol* s = new VariableSymbol(this->identifier, new StringVariable());
	this->getScope()->getSymbolTable()->insert(s);
	/*if (this->exp != NULL) {
		AssignmentStatement* a = new AssignmentStatement();
		a->assign(s, this->exp);
	}*/
}

void BoolVarDeclStatement::execute()
{
	VariableSymbol* s = new VariableSymbol(this->identifier, new BoolVariable());
	this->getScope()->getSymbolTable()->insert(s);
	/*if (this->exp != NULL) {
		AssignmentStatement* a = new AssignmentStatement();
		a->assign(b, this->exp);
	}*/
}

void ArrayVarDeclStatement::execute()
{
	VariableSymbol* s = new VariableSymbol(this->identifier, new ArrayVariable());
	this->getScope()->getSymbolTable()->insert(s);
	/*if (this->exp != NULL) {
		AssignmentStatement* a = new AssignmentStatement();
		a->assign(ar, this->exp);
	}*/
}

