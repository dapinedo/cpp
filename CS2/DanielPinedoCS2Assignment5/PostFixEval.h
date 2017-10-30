#pragma once
#ifndef POSTFIXEVAL_H
#define POSTFIXEVAL_H
#include "Stack.h"
#include "TokenizerParser.h"

class PostFixEval
{
private:
	string expression;
	bool numeric;
	double value;
	bool isValidExp;
	bool hasValidValue;

protected:
	double evaluate();
	bool isNumeric();

public:
	PostFixEval(string Exp = "", bool numeric1 = false);
	void findValue();
	void print(ostream &out=cout) const; 

	~PostFixEval();
};
#endif
