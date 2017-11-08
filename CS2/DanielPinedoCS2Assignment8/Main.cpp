#include "BankAccount.h"
#include "BankAccountLinkedList.h"


// independent stack for executing linked list commands
void showstack();

int main() 
{
	showstack();
	return 0;
	system("pause");
}

void showstack()
{
	// insert five BankAccounts in the Linked list and print linked list
	BankAccountLinkedList LL;
	BankAccount B1("00001", "John", "Smith", 345.67);
	BankAccount B2("00002", "Jane", "Smith", 123.67);
	BankAccount B3("00003", "Joe", "Smithers", 345.89);
	BankAccount B4("00004", "Janet", "Smithers", 123.89);
	BankAccount B5("00005", "Jim", "Smithson", 456.78);
	LL.insert(B1);
	LL.insert(B2);
	LL.insert(B3);
	LL.insert(B4);
	LL.insert(B5);
	cout << LL.toString() << endl;
}
//--------------------------------------------------------------
//OUTPUT FROM MAIN
/*
From constructor.
Name: Jim Smithson
Account #: 00005
Balance: $456.78
Name: Janet Smithers
Account #: 00004
Balance: $123.89
Name: Joe Smithers
Account #: 00003
Balance: $345.89
Name: Jane Smith
Account #: 00002
Balance: $123.67
Name: John Smith
Account #: 00001
Balance: $345.67


From destructor.
Press any key to continue . . .
*/


