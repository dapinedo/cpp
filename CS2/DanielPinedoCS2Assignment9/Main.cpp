/*
Author: Daniel Pinedo
Templated Growing Stack
*/

#include <string>
#include <iomanip>
#include "StackInterface.h"
#include "BankAccount.h"

/*
Push five of each on to their respective types of stacks:
Five ints on int type stack
Five chars on char type stack
Five strings on string type stack
Five BankAccounts on BankAccount type stack.
Using loop, top and pop all of above stacks and output the topped value to the console.
*/

int main()
{
	//initialize Stacks
	Stack<int> sInt;
	Stack<char> sChar;
	Stack<string> sString;
	Stack<BankAccount> sBankAccount;

	//create BankAccount objects
	BankAccount B1;
	BankAccount B2("01234", "John", "Smith", 34.56);
	BankAccount B3("43210", "Jane", "Smithers", 56.78);
	BankAccount B4("98765", "Greg", "McGregor", 78.89);
	BankAccount B5("56789", "Jill", "Jillian", 98.54);

	// push to templated Stacks;
	for (int i = 0; i < 5; i++) {
		sInt.push(i);
	}
	for (int i = 0; i < 5; i++) {
		sChar.push('a' + i);
	}
	sString.push("red");
	sString.push("orange");
	sString.push("yellow");
	sString.push("green");
	sString.push("blue");
	sBankAccount.push(B1);
	sBankAccount.push(B2);
	sBankAccount.push(B3);
	sBankAccount.push(B4);
	sBankAccount.push(B5);
	
	// print top of stacks and pop stacks
	cout << "Top and Pop of Integer Stack" << endl;
	cout << "-------------------------" << endl;
	for (int i = 0; i < 5; i++) {
		cout << sInt.top() << endl;
		sInt.pop();
	}
	cout << endl;
	cout << "Top and Pop of Char Stack" << endl;
	cout << "-------------------------" << endl;
	for (int i = 0; i < 5; i++) {
		cout << sChar.top() << endl;
		sChar.pop();
	}
	cout << endl;
	cout << "Top and Pop of String Stack" << endl;
	cout << "-------------------------" << endl;
	for (int i = 0; i < 5; i++) {
		cout << sString.top() << endl;
		sString.pop();
	}
	cout << endl;
	cout << "Top and Pop of BankAccount Stack" << endl;
	cout << "-------------------------" << endl;
	for (int i = 0; i < 5; i++) {
		cout << sBankAccount.top() << endl;
		sBankAccount.pop();
	}
	cout << endl;

	system("pause");
	return 0;
}

//OUTPUT BELOW
/*
Top and Pop of Integer Stack
-------------------------
4
3
2
1
0

Top and Pop of Char Stack
-------------------------
e
d
c
b
a

Top and Pop of String Stack
-------------------------
blue
green
yellow
orange
red

Top and Pop of BankAccount Stack
-------------------------
Name: Jill Jillian
Account #: 56789
Balance: $98.54

Name: Greg McGregor
Account #: 98765
Balance: $78.89

Name: Jane Smithers
Account #: 43210
Balance: $56.78

Name: John Smith
Account #: 01234
Balance: $34.56

Name: first name not set last name not set
Account #: not set
Balance: $0.00


Press any key to continue . . .
*/