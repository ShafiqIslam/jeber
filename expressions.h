#ifndef EXPRESSIONS_H

#define EXPRESSIONS_H

#include "error_handler.h"
#include "types.h"
#include "statement.h"
#include <iostream>
#include <string>

class Expression
{
protected:
	Statement* statement;
	ValueType* value;
public:
	virtual void evaluate() = 0;
	void printValue();
	ValueType* getValue();
	void setStatement(Statement* stmt) { this->statement = stmt; }
};

class IntegerExpression : public Expression
{
private:
	int literalValue;
public:
	IntegerExpression(int value) { this->literalValue = value; }
	void evaluate();
};

class FloatExpression : public Expression
{
private:
	float literalValue;
public:
	FloatExpression(float value) { this->literalValue = value; }
	void evaluate();
};

class StringExpression : public Expression
{
private:
	std::string literalValue;
public:
	StringExpression(std::string value) { this->literalValue = value; }
	void evaluate();
};

class BoolExpression : public Expression
{
private:
	bool literalValue;
public:
	BoolExpression(bool value) { this->literalValue = value; }
	void evaluate();
};

class VariableExpression : public Expression
{
private:
	std::string identifier;
public:
	VariableExpression(std::string id) { this->identifier = id; }
	void evaluate();
};

class BinaryOperationExpression : public Expression
{
protected:
	Expression* a;
	Expression* b;
	ValueType* aVal;
	ValueType* bVal;
	BinaryOperationExpression(Expression* a, Expression* b) { this->a = a; this->b = b; }
	void evaluateAndValidateExpressions();
	virtual void validateTypes() = 0;
};

class UnaryOperationExpression : public Expression
{
protected:
	Expression* a;
	ValueType* aVal;
	UnaryOperationExpression(Expression* a) { this->a = a; }
	void evaluateAndValidateExpression();
	virtual void validateType() = 0;
};

class ArithmaticExpression
{
public:
	static void validateType(ValueType* val);
};

class BinaryArithmaticExpression : public BinaryOperationExpression
{
protected:
	BinaryArithmaticExpression(Expression* a, Expression* b) : BinaryOperationExpression(a, b) {}
	void validateTypes();
};

class UnaryArithmaticExpression : public UnaryOperationExpression
{
protected:
	UnaryArithmaticExpression(Expression* a) : UnaryOperationExpression(a) {}
	void validateType();
};

class LogicalExpression
{
public:
	static void validateType(ValueType* val);
};

class BinaryLogicalExpression : public BinaryOperationExpression
{
protected:
	BinaryLogicalExpression(Expression* a, Expression* b) : BinaryOperationExpression(a, b) {}
	void validateTypes();
};

class UnaryLogicalExpression : public UnaryOperationExpression
{
protected:
	UnaryLogicalExpression(Expression* a) : UnaryOperationExpression(a) {}
	void validateType();
};

class PlusOperationExpression : public BinaryArithmaticExpression
{
public:
	PlusOperationExpression(Expression* a, Expression* b) : BinaryArithmaticExpression(a, b) {}
	void evaluate();
};

class MinusOperationExpression : public BinaryArithmaticExpression
{
public:
	MinusOperationExpression(Expression* a, Expression* b) : BinaryArithmaticExpression(a, b) {}
	void evaluate();
};

class MultiplyOperationExpression : public BinaryArithmaticExpression
{
public:
	MultiplyOperationExpression(Expression* a, Expression* b) : BinaryArithmaticExpression(a, b) {}
	void evaluate();
};

class DivideOperationExpression : public BinaryArithmaticExpression
{
public:
	DivideOperationExpression(Expression* a, Expression* b) : BinaryArithmaticExpression(a, b) {}
	void evaluate();
};

class ModulusOperationExpression : public BinaryArithmaticExpression
{
public:
	ModulusOperationExpression(Expression* a, Expression* b) : BinaryArithmaticExpression(a, b) {}
	void evaluate();
};

class UnaryMinusOperationExpression : public UnaryArithmaticExpression
{
public:
	UnaryMinusOperationExpression(Expression* a) : UnaryArithmaticExpression(a) {}
	void evaluate();
};

class LogicalAndExpression : public BinaryLogicalExpression
{
public:
	LogicalAndExpression(Expression* a, Expression* b) : BinaryLogicalExpression(a, b) {}
	void evaluate();
};

class LogicalOrExpression : public BinaryLogicalExpression
{
public:
	LogicalOrExpression(Expression* a, Expression* b) : BinaryLogicalExpression(a, b) {}
	void evaluate();
};

class LogicalNotExpression : public UnaryLogicalExpression
{
public:
	LogicalNotExpression(Expression* a) : UnaryLogicalExpression(a) {}
	void evaluate();
};

#endif
