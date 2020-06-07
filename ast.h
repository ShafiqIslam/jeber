#ifndef AST_H

#define AST_H

#include <string>
#include "error_handler.h"
#include "types.h"
#include "expressions.h"
#include "symbol_table.h"
#include "statement.h"

class Program
{
private:
	StatementList* statements;
public:
	void setStatements(StatementList* stmts);
	void execute();
};

class EmptyStatement : public Statement
{
public:
	void execute() {}
};

class ExpressionStatement : public Statement
{
private:
	Expression* exp;
public:
	ExpressionStatement(Expression* exp) { this->exp = exp; this->exp->setStatement(this); }
	void execute();
};

class VariableStatement : public Statement
{
protected:
	std::string identifier;
	Expression* exp;
	VariableStatement() {}
	VariableStatement(std::string id) { this->identifier = id; };
	VariableStatement(std::string id, Expression* exp) { this->identifier = id; this->exp = exp; };
};

class IntegerVarDeclStatement : public VariableStatement
{
public:
	IntegerVarDeclStatement(std::string id) : VariableStatement(id) {};
	IntegerVarDeclStatement(std::string id, Expression *exp) : VariableStatement(id, exp) {};
	void execute();
};

class FloatVarDeclStatement : public VariableStatement
{
public:
	FloatVarDeclStatement(std::string id) : VariableStatement(id) {};
	FloatVarDeclStatement(std::string id, Expression *exp) : VariableStatement(id, exp) {};
	void execute();
};

class StringVarDeclStatement : public VariableStatement
{
public:
	StringVarDeclStatement(std::string id) : VariableStatement(id) {};
	StringVarDeclStatement(std::string id, Expression *exp) : VariableStatement(id, exp) {};
	void execute();
};

class BoolVarDeclStatement : public VariableStatement
{
public:
	BoolVarDeclStatement(std::string id) : VariableStatement(id) {};
	BoolVarDeclStatement(std::string id, Expression *exp) : VariableStatement(id, exp) {};
	void execute();
};

class ArrayVarDeclStatement : public VariableStatement
{
public:
	ArrayVarDeclStatement(std::string id) : VariableStatement(id) {};
	ArrayVarDeclStatement(std::string id, Expression *exp) : VariableStatement(id, exp) {};
	void execute();
};

class AssignmentStatement : public VariableStatement
{
public:
	AssignmentStatement() {}
	AssignmentStatement(std::string id, Expression *exp) : VariableStatement(id, exp) {};
	static void assign(Variable* var, Expression* exp);
	void execute();
};

#endif
