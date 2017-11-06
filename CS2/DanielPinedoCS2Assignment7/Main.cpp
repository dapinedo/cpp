#include "Stack.h"
#include <iostream>
using namespace std;
Stack FillEmptyStackWithIntegersAndReturnIt();
void PopAndPrintStack(Stack Stk);
int main()
{
	{
		cout << "Creating a new Stack.\n";
		Stack IntStack = FillEmptyStackWithIntegersAndReturnIt();
		cout << "Making a copy of original stack.\n";
		Stack CopyOfIntStack;
		CopyOfIntStack = IntStack;
		cout << "Topping and Popping the original Stack:\n";
		PopAndPrintStack(IntStack);
		cout << "Topping and Popping the copy stack.\n";
		PopAndPrintStack(CopyOfIntStack);
	}
	system("pause");
	return 0;
}
//----------------------------------------------------------------
void PopAndPrintStack(Stack Stk)
{
	cout << "Now printing the integers pushed on the stack.\n";
	while (!Stk.isEmpty())
	{
		cout << Stk.top().Integer << " ";
		Page 9 of 11
			30
			31
			32
			33
			34
			35
			36
			37
			38
			39
			40
			41
			42
			43
			44
			45
			46
			47
			48
			49
			50
			51
			52
			53
			54
			55
			Stk.pop();
	}
	cout << endl;
}
//-----------------------------------------------------------------
Stack FillEmptyStackWithIntegersAndReturnIt()
{
	Stack Stk;
	cout << "We will push some integers on the stack now.\n";
	bool done = false;
	int val = int();
	while (!done)
	{
		cout << "Please enter an integer to be pushed on stack : ";
		cin >> val;
		ItemType item;
		item.Integer = val;
		Stk.push(item);
		cout << "The number of items on stack :" << Stk.getNumItems() << endl;
		cout << "The capacity of stack array is: " << Stk.getArrayCapacity() << endl;
		cout << "More data? Enter 0 to continue and 1 to exit: ";
		cin >> done;
	}
	return Stk;
}