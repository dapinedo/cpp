#include "ItemType.h"
#include "ReversePolishNotation.h"
#include "Stack.h"
#include "TokenizerParser.h"
#include "PostFixEval.h"
#include <iomanip>


int main()
{
	PostFixEval ans;
	ans.findValue();
	ans.print();
	system("pause");
}

