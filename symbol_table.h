#ifndef SYMBOL_TABLE_H

#define SYMBOL_TABLE_H

#include "error_handler.h"
#include "types.h"
#include <iostream>
#include <string>

const int MAX_SYMBOL_COUNT = 100;

class Symbol
{
protected:
	std::string identifier;
	Symbol(std::string id) { this->identifier = id; }
public:
	std::string getIdentifier() { return this->identifier; }
};

class VariableSymbol : public Symbol
{
private:
	Variable* variable;
public:
	VariableSymbol(std::string id, Variable* var) : Symbol(id) { this->variable = var; };
	Variable* getVariable() { return this->variable; };
};

class FunctionSymbol : public Symbol
{
public:
	FunctionSymbol(std::string id) : Symbol(id) {};
};

class SymbolTable 
{ 
private:
	Symbol* symbols[MAX_SYMBOL_COUNT];	
public: 
	SymbolTable();
    int hashFunction(std::string id);
    void insert(Symbol* symbol); 
    Symbol* find(std::string id); 
    void deleteSymbol(std::string id); 
}; 

class Scope
{
private:
	SymbolTable* symbolTable;
public:
	Scope() { this->symbolTable = new SymbolTable(); }
	SymbolTable* getSymbolTable() { return this->symbolTable; };
};

#endif
