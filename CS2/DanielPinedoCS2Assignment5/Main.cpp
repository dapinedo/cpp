#include "ItemType.h"
#include "ReversePolishNotation.h"
#include "Stack.h"
#include "TokenizerParser.h"
#include "PostFixEval.h"
#include <iomanip>


int main()
{
	cout << "--------------------" << endl;
	cout << "please enter a postfix expression to be evaluated. Separate each character with whitespace."
		<< endl;
	string input;
	getline(cin, input);
	cin.ignore(255, '\n');
	string Str_Arr[MAX];
	size_t count = 0;
	TokenizerParser::getStringArray(Str_Arr, input, MAX, count);
	for (size_t index = 0; index < count; index++) {
		cout << Str_Arr[index] << endl;
	}

}

