#ifndef STATEMENT_H

#define STATEMENT_H

#include "symbol_table.h"
#include <vector>

class Statement
{
protected:
	int lineNo;
	Scope* scope;
public:
	virtual void execute() { }
	void setScope(Scope* scope) { this->scope = scope; }
	Scope* getScope() { return this->scope; }
	void setLineNo(int l) { this->lineNo = l; }
	int getLineNo() { return this->lineNo; }
};

class StatementList
{
private:
	std::vector<Statement*> statements;
public:
	void push(Statement* stmt) { this->statements.push_back(stmt); }
	std::vector<Statement*> getAll() { return this->statements; }
};

#endif
