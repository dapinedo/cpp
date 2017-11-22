/*
Author: Daniel Pinedo
Templated Growing Stack
*/

#include <string>
#include <iomanip>
#include "StackInterface.h"
#include "BankAccount.h"

int main()
{
	Stack<string> stk1;
	Stack<double> stk2;
	Stack<BankAccount> stk3;
	// create objects to be inserted into BankAccount object and pushed to Stack
	string acctnum = "1234";
	string fname = "Jane";
	string lname = "Smith";
	double balance = 75.43;
	// create BankAccount objects
	BankAccount B1;
	BankAccount B2(acctnum, fname, lname, balance);

	// push to templated Stacks;
	stk1.push(acctnum);
	stk1.push(fname);
	stk1.push(lname);
	stk2.push(balance);
	stk3.push(B1);
	stk3.push(B2);

	// print top of stacks and pop stacks
	cout << stk1.top() << endl;
	stk1.pop();
	cout << stk1.top() << endl;
	stk1.pop();
	cout << stk1.top() << endl;
	stk1.pop();
	cout << stk2.top() << endl;
	stk2.pop();
	cout << stk3.top() << endl;
	stk3.pop(); 
	cout << stk3.top() << endl;
	stk3.pop();

	system("pause");
	return 0;
}

//OUTPUT BELOW
/*
From Stack Constructor.
From Stack Constructor.
From Stack Constructor.
**********>  Using the existing array to push. <*******************
Number of items in stack now: 1
**********> Expanding the array to push. <*******************
Number of items in stack now: 2
**********> Expanding the array to push. <*******************
Number of items in stack now: 3
**********>  Using the existing array to push. <*******************
Number of items in stack now: 1
**********>  Using the existing array to push. <*******************
Number of items in stack now: 1
**********> Expanding the array to push. <*******************
Number of items in stack now: 2
Smith
Jane
1234
75.43
Name: Jane Smith
Account #: 1234
Balance: $75.43

Name: first name not set last name not set
Account #: not set
Balance: $0.00

Press any key to continue . . .
*/