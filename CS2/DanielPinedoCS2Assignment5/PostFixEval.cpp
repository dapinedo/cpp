#include "PostFixEval.h"

PostFixEval::PostFixEval(string Exp, bool numeric1) : expression(Exp), numeric(numeric1),
	value(0.0), isValidExp(false), hasValidValue(false)
{
}

double PostFixEval::evaluate()
{
	string Str_Arr[MAX];
	size_t count = 0;
	TokenizerParser::getStringArray(Str_Arr, expression, MAX, count);
	// checks for numeric
	for (size_t index = 0; index < count; index++) {
		if ((Str_Arr[index] != "*") || (Str_Arr[index] != "/")
			|| (Str_Arr[index] != "+") || (Str_Arr[index] != "-")) {
			numeric = true;
			return 0.0;
		}
	}
	// evaluation algorithm
	Stack newStack;
	for (size_t index = 0; index < count; index++) {
		if ((Str_Arr[index] != "*") || (Str_Arr[index] != "/")
				|| (Str_Arr[index] != "+") || (Str_Arr[index] != "-")) {
			// BOOKMARK - TO BE COMPLETED pop2 [operator] pop1
		}
		else {
			ItemType newItem;
			newItem.Double = TokenizerParser::parseDouble(Str_Arr[index]);
			newStack.push(newItem);
		}
		// BOOKMARK - TO BE COMPLETED
	}
}
bool PostFixEval::isNumeric()
{

}
void PostFixEval::findValue()
{

}
void PostFixEval::print(ostream &out) const
{

}

PostFixEval::~PostFixEval()
{
}
