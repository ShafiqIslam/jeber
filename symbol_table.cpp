#include "symbol_table.h"
#include <iostream>
#include <string>

using namespace std;

SymbolTable::SymbolTable()
{ 
	for (int i = 0; i < MAX_SYMBOL_COUNT; i++) this->symbols[i] = NULL; 
}

int SymbolTable::hashFunction(string id) 
{ 
    int ascii_sum = 0; 
  
    for (int i = 0; i < id.length(); i++) { 
        ascii_sum = ascii_sum + id[i]; 
    } 
  
    return ascii_sum % MAX_SYMBOL_COUNT; 
}

void SymbolTable::insert(Symbol* symbol)
{
	int index = this->hashFunction(symbol->getIdentifier()); 
    
	if (this->symbols[index] != NULL) ErrorHandler::fatal("Symbol: " + symbol->getIdentifier() + " already exists"); 

    this->symbols[index] = symbol;
}

Symbol* SymbolTable::find(string id)
{
	int index = this->hashFunction(id); 
    
    if (this->symbols[index] == NULL) ErrorHandler::fatal("Undefined symbol: " + id);

	return this->symbols[index];
}

void SymbolTable::deleteSymbol(string id)
{
	int index = this->hashFunction(id); 
    
    if (this->symbols[index] == NULL) ErrorHandler::fatal("Undefined symbol: " + id);

	this->symbols[index] = NULL;	
} 

