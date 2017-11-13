#include "BankAccount.h"
#include "BankAccountLinkedList.h"
#include "LetterFrequencyList.h"


// test linked list of bankaccount
void bankLinkedList();
// frequency linked list of characters in a text file
void frequencyLinkedList();

int main() 
{
	//bankLinkedList();
	frequencyLinkedList();
	return 0;
	system("pause");
}

void bankLinkedList()
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

void frequencyLinkedList()
{
	LetterFrequencyList LFL;
	cout << "Enter full file path of file to get character frequencies: ";
	string in = "";
	getline(cin, in);
	ifstream inFile;
	inFile.open(in);
	if (inFile.is_open()) {
		cout << "File opened!\n";
		while (inFile.peek() !=EOF) {
			char read;
			inFile >> read;
			read = toupper(read);
			if (read >= 'A' && read <= 'Z') {
				LFL.insertInOrder(read);
			}
		}
		inFile.close();
		cout << LFL.toString();
	}
	else { 
		cout << "File failed to open\n";
	}
}
//--------------------------------------------------------------
//OUTPUT FROM BANKLINKEDLIST
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


