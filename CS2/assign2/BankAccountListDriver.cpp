/* Daniel Pinedo
 * CS 2 - Section 0140
 * assignment: 2, part 1
 * Grade, Part 1 prep : OK 
 * Grade, Part 1      : 9.5/10
 * Grade, Part 2 prep : 
 * Grade, Part 2      :
 * part 1 due: Sept. 18, 2017
 * part 2 due: Sept. 25, 2017
 * file: Main.cpp
 */

#include "BankAccount.h"
#include "BankAccountList.h"

void test_main();

int main() {
	BankAccountList BAL;
	BankAccount B; // dummy code just for testing
	
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
			cout << "3. Update an account" << '\n';
			cout << "4. Close/delete an account" << '\n';
			cout << "5. Write current account list to an output file in append mode" << '\n';
			cout << "6. Print current account list to console" << '\n';
			cout << "7. Withdraw money from an account" << '\n';
			cout << "8. Deposit money into an account" << '\n';
			cout << "9. Print account details to console" << '\n';
			cout << "10. Search account and show details to console" << '\n';
			cout << "11. Print list sorted by account number to console" << '\n';
			cout << "12. Print list sorted by last name to console" << '\n';
			cout << "13. Print list sorted by balance to console" << '\n';
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
		else if ((choice == 3) && (entrymade == true)) {
			bool updated = BAL.updateAccount();
			if (updated) {
				cout << "Update Successful" << '\n';
			}
			else {
				cout << "Update Failed" << '\n';
			}
		}
		else if ((choice == 4) && (entrymade == true)) {
			cout << "Please enter account number: ";
			string actNum;
			cin << actNum;
			bool deleted = deleteAccount(actNum);
			if (deleted) {
				cout << "Deletion Successful" << '\n';
			}
			else {
				cout << "Deletion Failed" << '\n';
			}
		}
		else if ((choice == 5) && (entrymade == true)) {
			
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
			string OutputFilename = "";
			cout << "Enter path to output file: ";
			cin.ignore(255, '\n');
			getline(cin, OutputFilename);
			ofstream out(OutputFilename, ios::app);
			if (out.is_open()) {
				cout << "-------------------------------" << '\n';
				cout << "File created successfully" << '\n';
				cout << "-------------------------------" << '\n';
				BAL.print(out);
				out.close();
			}
			else {
				cout << "-------------------------------" << '\n';
				cout << "Failed to create output file." << '\n';
				cout << "-------------------------------" << '\n';
			}
		}
		else if ((choice == 6) && (entrymade == true)) {
			B.print(cout);
		}
		else if ((choice == 7) && (entrymade == true)) {
			
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
		else if (choice == 18) {
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
	

