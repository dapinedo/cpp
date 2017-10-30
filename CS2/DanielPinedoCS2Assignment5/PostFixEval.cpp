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
			value = TokenizerParser::parseDouble(expression);
			return value;
		}
	}
	// evaluation algorithm
	Stack newStack;
	ItemType result;
	for (size_t index = 0; index < count; index++) {
		if (Str_Arr[index] == "*") {
			ItemType pop1 = newStack.top();
			newStack.pop();
			ItemType pop2 = newStack.top();
			newStack.pop();
			int newval = pop2.Integer * pop1.Integer;
			ItemType nval;
			nval.Integer = newval;
			newStack.push(nval);
			cout << pop2.Integer << " * " << pop1.Integer << endl;
		}
		else if (Str_Arr[index] == "/") {
			ItemType pop1 = newStack.top();
			newStack.pop();
			ItemType pop2 = newStack.top();
			newStack.pop();
			int newval = pop2.Integer / pop1.Integer;
			ItemType nval;
			nval.Integer = newval;
			newStack.push(nval);
			cout << pop2.Integer << " / " << pop1.Integer << endl;
		}
		else if (Str_Arr[index] == "+") {
			ItemType pop1 = newStack.top();
			newStack.pop();
			ItemType pop2 = newStack.top();
			newStack.pop();
			int newval = pop2.Integer + pop1.Integer;
			ItemType nval;
			nval.Integer = newval;
			newStack.push(nval);
			cout << pop2.Integer << " + " << pop1.Integer << endl;
		}
		else if (Str_Arr[index] == "-") {
			ItemType pop1 = newStack.top();
			newStack.pop();
			ItemType pop2 = newStack.top();
			newStack.pop();
			int newval = pop2.Integer * pop1.Integer;
			ItemType nval;
			nval.Integer = newval;
			newStack.push(nval);
			cout << pop2.Integer << " * " << pop1.Integer << endl;
		}
		else {
			ItemType newItem;
			newItem.Double = TokenizerParser::parseInt(Str_Arr[index]);
			newStack.push(newItem);
		}
	}
	return static_cast<double>(newStack.top().Double);
}
bool PostFixEval::isNumeric()
{
	return numeric;
}
void PostFixEval::findValue()
{
	cout << "--------------------" << endl;
	cout << "please enter a postfix expression to be evaluated. Separate each character with whitespace."
		<< endl;
	string input;
	getline(cin, input);
	//cin.ignore(255, '\n');
	value = evaluate();
}
void PostFixEval::print(ostream &out) const
{
	if (numeric) {
		cout << "The result is numeric only" << endl;
	}
	else {
		out << "Calculated Total: " << value << endl;
	}
}

PostFixEval::~PostFixEval()
{
}
