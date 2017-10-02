/*
Daniel Pinedo
CS1
Assignment 9
5/30/17

BankingStruct.cpp
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

const char SEP = '*';
const int SEP_NUM = 60;
/*
Instructor comments #1: -2
could improve output formatting below: -0.5
Your current balance: $20.01****************************************************
********
Grade: 22.5/25
*/
struct BankAccount
{
	int ActNum;
	string LastName;
	string FirstName;
	double balance;

	// default constructor
	BankAccount()
	{
		ActNum = 9999;
		LastName = "Not Set";
		FirstName = "Not Set";
		balance = 0.0;
	}

	// explicit constructor
	BankAccount(int acct, string first, string last, double bal)
	{
		ActNum = acct;
		LastName = last;
		FirstName = first;
		balance = bal;
	}

	void print()
		/* This function prints all struct data member values to console*/
	{
		cout << fixed << showpoint << setprecision(2)
			<< "Account #: " << ActNum << endl
			<< "Name: " << FirstName << " " << LastName << endl
			<< "Balance: $" << balance << endl;
	}

	void print(ofstream & out)
		/* This function prints all struct data member values to output file*/
	{
		out << fixed << showpoint << setprecision(2)
			<< "Account #: " << ActNum << endl
			<< "Name: " << FirstName << " " << LastName << endl
			<< "Balance: $" << balance << endl;
	}

	void deposit(double money)
		/* This function takes input argument double money and mutates struct member deposit*/
	{
		balance += money;
	}

	void withdraw(double money)
		/* this function simulates the withdrawal of money from a bank account*/
	{
		if (balance >= money)
		{
			balance -= money;
		}
		else
		{
			cout << "Insufficient funds. Withdrawal cannot be made." << endl;
		}
	}

	// read-only get functions
	int getAccountNumber()
		/* This function returns ActNum*/
	{
		return ActNum;
	}

	double getBalance()
		/* This function returns balance*/
	{
		return balance;
	}
	
	string getFirstName()
		/* This function returns FirstName*/
	{
		return FirstName;
	}

	string getLastName()
		/* This function returns LastName*/
	{
		return LastName;
	}

	string getFullName()
		/* This function concatenates FirstName and LastName and returns FullName*/
	{
		string FullName = FirstName + ' ' + LastName;
		return FullName;
	}
	
	// set functions after struct is created
	void setLastName(string newLastName)
		/* This function takes input argument string newLastName and mutates struct member LastName*/
	{
		LastName = newLastName;
	}
};

int main()
{
	//code for test for bugs in struct below

	/*
	BankAccount B;
	
	int acct = 5623;
	string first = "Jim";
	string last = "Jones";
	double bal = 100.89;
	
	B = BankAccount(acct, first, last, bal);
	B.print();

	B.deposit(100.00);
	cout << string(SEP_NUM, SEP) << '\n';
	cout << "We have deposited $100.00, completing instruction #10 for this assignment. We will now print the updated balance below" << endl;
	cout << string(SEP_NUM, SEP) << '\n';
	B.print();

	B.withdraw(100.00);
	cout << string(SEP_NUM, SEP) << '\n';
	cout << "We have withdrawn $100.00, completing part of instruction #13 for this assignment. We will now print the updated balance below" << endl;
	cout << string(SEP_NUM, SEP) << '\n';
	B.print();

	B.withdraw(101.00);
	cout << string(SEP_NUM, SEP) << '\n';
	cout << "We have withdrawn $101.00, completing part of instruction #13 for this assignment. The error above should indicate Insufficient Funds with same balance as before" << endl;
	cout << string(SEP_NUM, SEP) << '\n';
	B.print();

	*/
	
	cout << fixed << showpoint << setprecision(2);
	bool loopflag = 1;
	BankAccount B;
	while (loopflag)
	{
		int choice = 8;
		cout << string(SEP_NUM, SEP) << endl;
		cout << "Enter the item number you want from the menu at the prompt and hit Enter" << endl;
		cout << " 1. Create a new bank account record." << endl;
		cout << " 2. Print details of created record to console." << endl;
		cout << " 3. Print details of created record to output file." << endl;
		cout << " 4. Make a deposit." << endl;
		cout << " 5. Make a withdrawal." << endl;
		cout << " 6. Print current balance to console." << endl;
		cout << " 7. Print aaccount holder's full name." << endl;
		cout << " 8. Exit." << endl;
		cout << "Enter choice: ";
		cin >> choice;
		cout << string(SEP_NUM, SEP) << endl;
		switch (choice)
		{
			case 1:
			{
			cout << "Type your account number and hit Enter key: ";
			int account;
			cin >> account;
			cout << "Type your first name and hit Enter key: ";
			string firstName;
			cin >> firstName;
			cout << "Type your last name and hit Enter key: ";
			string lastName;
			cin >> lastName;
			B = BankAccount(account, firstName, lastName, 0.0);
			break;
			}

			case 2:
			{
				B.print();
				break;
			}

			case 3:
			{
				cout << "Enter in full path of file to save data and hit Enter key: ";
				cin.ignore(256, '\n');
				string outFileName;
				getline(cin, outFileName);
				ofstream out(outFileName);
				//Instructor comment # 1: how do you know that user entered a drive
				//letter that even exists? Program should always check for successful
				//opening of file.
				B.print(out);
				out.close();
				cout << "File at below path has been successfully written." << endl;
				cout << outFileName << endl;
				break;
			}

			case 4:
			{
				cout << "Enter deposit amount and hit Enter key:";
				double depositAmount;
				cin >> depositAmount;
				B.deposit(depositAmount);
				break;
			}

			case 5:
			{
				cout << "Enter withdrawal amount and hit Enter key:";
				double withdrawalAmount;
				cin >> withdrawalAmount;
				B.withdraw(withdrawalAmount);
				break;
			}

			case 6:
			{
				cout << "Your current balance: $" << B.getBalance();
				break;
			}

			case 7:
			{
				cout << "Your full name: " << B.getFullName();
				break;
			}

			case 8:
			{
				loopflag = 0;
				break;
			}
		} // end switch
		cout << string(SEP_NUM, SEP) << endl;
	} // end while(loopflag)
	
	cout << "Goodbye!" << endl;
	return 0;
}