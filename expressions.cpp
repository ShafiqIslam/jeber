#include "expressions.h"

using namespace std;

void Expression::printValue()
{
	this->getValue()->print(); return;
	ValueType* v = this->getValue();
	if (v->isInt()) cout << v->getInt();
	else if (v->isFloat()) cout << v->getFloat();
	else if (v->isString()) cout << v->getString();
	else if (v->isBool()) cout << v->getBool() ? "true" : "false";
	cout << endl;
}

ValueType* Expression::getValue()
{
	if (this->value == NULL) this->evaluate();
	
	return this->value;
}

void IntegerExpression::evaluate()
{
	this->value = new IntType(this->literalValue);
}

void FloatExpression::evaluate()
{
	this->value = new FloatType(this->literalValue);
}

void StringExpression::evaluate()
{
	this->value = new StringType(this->literalValue);
}

void BoolExpression::evaluate()
{
	this->value = new BoolType(this->literalValue);
}

void VariableExpression::evaluate()
{
	// cout << this->identifier;
	// this->value = var->getValue();
}

void BinaryOperationExpression::evaluateAndValidateExpressions()
{
	this->aVal = this->a->getValue();
	this->bVal = this->b->getValue();
	this->validateTypes();
}

void UnaryOperationExpression::evaluateAndValidateExpression()
{
	this->aVal = this->a->getValue();
	this->validateType();
}

void ArithmaticExpression::validateType(ValueType* val)
{
	if( val->isNumber() ) return;

	val->print();

	ErrorHandler::fatal("Not a number");
}

void BinaryArithmaticExpression::validateTypes()
{
	ArithmaticExpression::validateType(this->aVal);
	ArithmaticExpression::validateType(this->bVal);
}

void UnaryArithmaticExpression::validateType()
{
	ArithmaticExpression::validateType(this->aVal);	
}

void LogicalExpression::validateType(ValueType* val)
{
	if( val->isBool() ) return;

	ErrorHandler::fatal("Not a bool");
}

void BinaryLogicalExpression::validateTypes()
{
	LogicalExpression::validateType(this->aVal);
	LogicalExpression::validateType(this->bVal);
}

void UnaryLogicalExpression::validateType()
{
	LogicalExpression::validateType(this->aVal);	
}

void PlusOperationExpression::evaluate()
{
	this->evaluateAndValidateExpressions();
	if ( this->aVal->isInt() && this->bVal->isInt() ) {
		int _a = this->aVal->getInt();
		int _b = this->bVal->getInt();
		this->value = new IntType(_a + _b);
	} else {
		float _a = this->aVal->isInt() ? (float)this->aVal->getInt() : this->aVal->getFloat();
		float _b = this->bVal->isInt() ? (float)this->bVal->getInt() : this->bVal->getFloat();
		this->value = new FloatType(_a + _b);
	}
}

void MinusOperationExpression::evaluate()
{
	this->evaluateAndValidateExpressions();
	if ( this->aVal->isInt() && this->bVal->isInt() ) {
		int _a = this->aVal->getInt();
		int _b = this->bVal->getInt();
		this->value = new IntType(_a - _b);
	} else {
		float _a = this->aVal->isInt() ? (float)this->aVal->getInt() : this->aVal->getFloat();
		float _b = this->bVal->isInt() ? (float)this->bVal->getInt() : this->bVal->getFloat();
		this->value = new FloatType(_a - _b);
	}
}

void MultiplyOperationExpression::evaluate()
{
	this->evaluateAndValidateExpressions();
	if ( this->aVal->isInt() && this->bVal->isInt() ) {
		int _a = this->aVal->getInt();
		int _b = this->bVal->getInt();
		this->value = new IntType(_a * _b);
	} else {
		float _a = this->aVal->isInt() ? (float)this->aVal->getInt() : this->aVal->getFloat();
		float _b = this->bVal->isInt() ? (float)this->bVal->getInt() : this->bVal->getFloat();
		this->value = new FloatType(_a * _b);
	}
}

void DivideOperationExpression::evaluate()
{
	this->evaluateAndValidateExpressions();
	if ( this->aVal->isInt() && this->bVal->isInt() && ((this->aVal->getInt() % this->bVal->getInt()) == 0) ) {
		int _a = this->aVal->getInt();
		int _b = this->bVal->getInt();
		this->value = new IntType(_a / _b);
	} else {
		float _a = this->aVal->isInt() ? (float)this->aVal->getInt() : this->aVal->getFloat();
		float _b = this->bVal->isInt() ? (float)this->bVal->getInt() : this->bVal->getFloat();
		this->value = new FloatType(_a / _b);
	}
}

void ModulusOperationExpression::evaluate()
{
	this->evaluateAndValidateExpressions();
	if ( !this->aVal->isInt() || !this->bVal->isInt() )	ErrorHandler::fatal("Not integers");
	this->value = new IntType(this->aVal->getInt() % this->bVal->getInt());
}

void UnaryMinusOperationExpression::evaluate()
{
	this->evaluateAndValidateExpression();
	if( this->aVal->isInt() ) {
		this->value = new IntType(-1 * this->aVal->getInt());
	} else {
		this->value = new FloatType(-1 * this->aVal->getFloat());
	}
}

void LogicalAndExpression::evaluate()
{
	this->evaluateAndValidateExpressions();
	this->value = new BoolType(this->aVal->getBool() && this->bVal->getBool());
}

void LogicalOrExpression::evaluate()
{
	this->evaluateAndValidateExpressions();
	this->value = new BoolType(this->aVal->getBool() || this->bVal->getBool());
}

void LogicalNotExpression::evaluate()
{
	this->evaluateAndValidateExpression();
	this->value = new BoolType(!this->aVal->getBool());
}

