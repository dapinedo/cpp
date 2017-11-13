/*
Daniel Pinedo
CS2
Assignment 8
11/13/2017
*/


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
// OUTPUT FROM FREQUENCYLINKEDLIST
/*
Enter full file path of file to get character frequencies: C:\Users\daniel_pinedo\source\repos\cpp\CS2\DanielPinedoCS2Assignment8\TesFrequencyOfAllCharacters.txt
File opened!
The letter X has occurred 2 times
The letter Z has occurred 5 times
The letter K has occurred 14 times
The letter Q has occurred 11 times
The letter F has occurred 89 times
The letter J has occurred 10 times
The letter W has occurred 60 times
The letter B has occurred 53 times
The letter M has occurred 121 times
The letter H has occurred 188 times
The letter G has occurred 85 times
The letter T has occurred 454 times
The letter C has occurred 134 times
The letter D has occurred 200 times
The letter N has occurred 363 times
The letter Y has occurred 64 times
The letter L has occurred 151 times
The letter S has occurred 294 times
The letter U has occurred 114 times
The letter O has occurred 345 times
The letter I has occurred 363 times
The letter V has occurred 47 times
The letter E has occurred 537 times
The letter R has occurred 296 times
The letter P has occurred 89 times
The letter A has occurred 383 times
*/


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


