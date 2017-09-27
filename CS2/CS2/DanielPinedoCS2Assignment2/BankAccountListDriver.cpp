/* 
Name: Daniel Pinedo
Class: CS 2
Assignment #: 2
All Compilers Used: g++, VS17
Operating Systems on Which Compiled: Linux, Win10
Date and Time of Last successful run: 9/24/2017 @2300
Email: d.p@ieee.org
*/

#include "BankAccount.h"
#include "BankAccountList.h"

void test_main();

int main() {


	BankAccountList BAL;

	BankAccount B; // dummy code just for testing
				   // REMINDER: call static getInstance function
				   // BankAccountList::getInstance(BAL);
				   // BankAccountList::getInstance(BAL, in)

				   /* uncomment below to run tests on class functions
				   test_main(); */
	cout << fixed << showpoint << setprecision(2);
	cout << "Welcome to our bank account management module." << '\n';
	cout << "Please create account(s) first in order to see full menu." << '\n';
	cout << "-------------------------------------------" << '\n';
	bool entrymade = false;
	bool done = false;
	while (!done) {
		cout << "Choose a menu number from below" << '\n';
		cout << "-------------------------------" << '\n';
		cout << "1. Create new accounts from keyboard data entry" << '\n';
		cout << "2. Create new accounts from input file data entry (Max 30 accounts)" << '\n';
		if (entrymade == true) {
			cout << "3. " << '\n';
			cout << "4. " << '\n';
			cout << "5. " << '\n';
			cout << "6. Print current account list to console" << '\n';
			cout << "7. Withdraw money" << '\n';
			cout << "8. Deposit money" << '\n';
			cout << "9. Print account details to console" << '\n';
			cout << "10. Print account details to an output file" << '\n';
			cout << "11. Print full name of account holder to console only" << '\n';
			cout << "12. Print account number only of the account holder to console" << '\n';
		}
		cout << "18. Exit" << '\n';
		short choice = 18;
		cout << "Enter choice: ";
		cin >> choice;
		if (choice == 1) {
			BankAccountList::getInstance(BAL); // calling static function from a class
			entrymade = true;
		}
		else if (choice == 2) {
			string InputFilename = "";
			cout << "Enter path to input file: ";
			cin.ignore(255, '\n');
			getline(cin, InputFilename);
			ifstream in(InputFilename);
			if (in.is_open()) {
				cout << "-------------------------------" << '\n';
				cout << "File opened successfully" << '\n';
				cout << "-------------------------------" << '\n';
				BankAccountList::getInstance(BAL, in);
				in.close();
				entrymade = true;
			}
			else {
				cout << "-------------------------------" << '\n';
				cout << "Failed to open input file." << '\n';
				cout << "-------------------------------" << '\n';
			}
		}


		else if ((choice == 6) && (entrymade == true)) {
			BAL.print(cout);
		}
		else if ((choice == 4) && (entrymade == true)) {
			double amount;
			cout << "Enter amount to withdraw: ";
			cin >> amount;
			B.withdraw(amount);
		}
		else if ((choice == 5) && (entrymade == true)) {
			double amount;
			cout << "Enter amount to deposit: ";
			cin >> amount;
			B.deposit(amount);
		}
		else if ((choice == 6) && (entrymade == true)) {
			B.print(cout);
		}
		else if ((choice == 7) && (entrymade == true)) {
			string OutputFilename = "";
			cout << "Enter path to output file: ";
			cin.ignore(255, '\n');
			getline(cin, OutputFilename);
			ofstream out(OutputFilename, ios::app);
			if (out.is_open()) {
				cout << "-------------------------------" << '\n';
				cout << "File created successfully" << '\n';
				cout << "-------------------------------" << '\n';
				B.print(out);
				out.close();
			}
			else {
				cout << "-------------------------------" << '\n';
				cout << "Failed to create output file." << '\n';
				cout << "-------------------------------" << '\n';
			}
		}
		else if ((choice == 8) && (entrymade == true)) {
			cout << "-------------------------------" << '\n';
			cout << "Full name of account holder: " << B.getFullName() << '\n';
			cout << "-------------------------------" << '\n';
		}
		else if ((choice == 9) && (entrymade == true)) {
			cout << "-------------------------------" << '\n';
			cout << "Account number: " << B.getAccountNumber() << '\n';
			cout << "-------------------------------" << '\n';
		}
		else if (choice == 10) {
			done = true;
		}
		else {
			cout << "-------------------------------" << '\n';
			cout << "Invalid Entry. Try again" << '\n';
			cout << "-------------------------------" << '\n';
		}
	} // end while loop
	return 0;
}

// test class BankAccount functions below
void test_main()
{
	//testing default constructor for class BankAccount
	BankAccount B1;
	B1.print(cout);
	/*
	Name: first name not set last name not set
	Account #: not set
	Balance: $0.00
	*/
	//testing explicit constructor for class BankAccount
	BankAccount B2("6543", "Jane", "Smith", 75.42);
	B2.print(cout);
	/*
	Name: Jane Smith
	Account #: 6543
	Balance: $75.42
	*/
	//testing class BankAccount deposit/withdraw functions
	B1.withdraw(-45.56);
	/*	Cannot withdraw negative or zero amount
	Transaction cancelled */
	B2.withdraw(75.43);
	/*	Withdrawal amount is greater than balance
	Transaction cancelled */
	B1.deposit(25.00);
	/*	Deposit successful. New balance is $25.00 */
	B2.withdraw(24.99);
	/* Withdrawal successful. New balance is $50.43 */

	return;
}


