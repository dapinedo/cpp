/*
Name: Daniel Pinedo
Class: CS 2 Section 0130
Assignment #: 4
All Compilers Used: VS17
Operating Systems on Which Compiled: Win10
Date and Time of Last successful run: 11/06/2017 @1600
Email: d.p@ieee.org
*/

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

//OUTPUT BELOW
/*
Creating a new Stack.
We will push some integers on the stack now.
Please enter an integer to be pushed on stack : 10
**********>  Using the existing array to push. <*******************
Number of items in stack now: 1
The number of items on stack :1
The capacity of stack array is: 1
More data? Enter 0 to continue and 1 to exit: 0
Please enter an integer to be pushed on stack : 9
**********> Expanding the array to push. <*******************
Number of items in stack now: 2
The number of items on stack :2
The capacity of stack array is: 2
More data? Enter 0 to continue and 1 to exit: 0
Please enter an integer to be pushed on stack : 8
**********> Expanding the array to push. <*******************
Number of items in stack now: 3
The number of items on stack :3
The capacity of stack array is: 3
More data? Enter 0 to continue and 1 to exit: 0
Please enter an integer to be pushed on stack : 7
**********> Expanding the array to push. <*******************
Number of items in stack now: 4
The number of items on stack :4
The capacity of stack array is: 4
More data? Enter 0 to continue and 1 to exit: 0
Please enter an integer to be pushed on stack : 6
**********> Expanding the array to push. <*******************
Number of items in stack now: 5
The number of items on stack :5
The capacity of stack array is: 5
More data? Enter 0 to continue and 1 to exit: 0
Please enter an integer to be pushed on stack : 5
**********> Expanding the array to push. <*******************
Number of items in stack now: 6
The number of items on stack :6
The capacity of stack array is: 6
More data? Enter 0 to continue and 1 to exit: 1
From Stack Copy Constructor.
Making a copy of original stack.
Topping and Popping the original Stack:
From Stack Copy Constructor.
Now printing the integers pushed on the stack.
5 6 7 8 9 10
Topping and Popping the copy stack.
From Stack Copy Constructor.
Now printing the integers pushed on the stack.
5 6 7 8 9 10
Press any key to continue . . .
*/

//----------------------------------------------------------------
void PopAndPrintStack(Stack Stk)
{
	cout << "Now printing the integers pushed on the stack.\n";
	while (!Stk.isEmpty())
	{
		cout << Stk.top().Integer << " ";
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