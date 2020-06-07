#ifndef TYPES_H

#define TYPES_H

#include <string>
#include <iostream>

class ValueType 
{
public:
	virtual bool isNumber() { return false; }
	virtual bool isInt() { return false; }
	virtual bool isFloat() { return false; }
	virtual bool isString() { return false; }
	virtual bool isBool() { return false; }
	virtual int getInt() { return 0; }
	virtual float getFloat() { return 0.0; }
	virtual std::string getString() { return ""; }
	virtual bool getBool() { return false; }
	void print() {
		if (this->isInt()) std::cout << this->getInt();
		else if (this->isFloat()) std::cout << this->getFloat();
		else if (this->isString()) std::cout << this->getString();
		else if (this->isBool()) std::cout << this->getBool() ? "true" : "false";
		std::cout << std::endl;
	}
};

class IntType : public ValueType
{
private:
	int value;
public:
	IntType(int v) { this->value = v; }
	bool isNumber() override { return true; }
	bool isInt() override { return true; }
	int getInt() override { return this->value; };
};

class FloatType : public ValueType
{
private:
	float value;
public:
	FloatType(float v) { this->value = v; }
	float getFloat() override { return this->value; }
	bool isNumber() override { return true; }
	bool isFloat() override { return true; }
};

class StringType : public ValueType
{
private:
	std::string value;
public:
	StringType(std::string v) { this->value = v; }
	bool isString() override { return true; }
	std::string getString() override { return this->value; }
};

class BoolType : public ValueType
{
private:
	bool value;
public:
	BoolType(bool v) { this->value = v; }
	bool getBool() override { return this->value; }
	bool isBool() override { return true; }
};

class Variable
{
protected:
	ValueType* value;
	void assign(ValueType* value) { this->value = value; }
	ValueType* getValue() { return this->value; }
};

class IntegerVariable : public Variable
{
public:
	void assign(IntType* value) { Variable::assign(value); };
};

class FloatVariable : public Variable
{
public:
	void assign(FloatType* value) { Variable::assign(value); };
};

class StringVariable : public Variable
{
public:
	void assign(StringType* value) { Variable::assign(value); };
};

class BoolVariable : public Variable
{
public:
	void assign(BoolType* value) { Variable::assign(value); };
};

class ArrayVariable : public Variable
{
public:
	void assign(ValueType* value) { Variable::assign(value); };
};

#endif
