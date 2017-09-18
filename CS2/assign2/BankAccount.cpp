/* Daniel Pinedo
 * CS 2 - Section 0140
 * assignment: 2, part 1
 * due: Sept. 18, 2017
 * file: BankAccount.h
 */

#include "BankAccount.h"

//Default constructor
BankAccount::BankAccount() : 
	ActNum ("not set"), 
	LastName ("last name not set"),
	FirstName ("first name not set"),
	balance (0.0) {}
//Explicit constructor
BankAccount::BankAccount(const string & actN, const string &fname, const string &lname,
	double bal) : 
	ActNum (actN),
	LastName (lname),
	FirstName (fname)
{
	if 	(bal < 0) {
		cout << "-------------------------------" << '\n';
		cout << "initial balance is less than zero. Setting to 0.0" << '\n';
		cout << "-------------------------------" << '\n';
	}
	else {
			balance = bal;
	}
}
// toString() functions
const string BankAccount::toString() const
{
	ostringstream os;
	os << fixed << showpoint << setprecision(2)
		<< "Name: " << FirstName << ' ' << LastName << endl
		<< "Account #: " << ActNum << endl
		<< "Balance: $" << balance << endl;
	return os.str();
}
// print() functions
void BankAccount::print(ostream & out) const
{
	if (&cout == &out) { // Object is printed to console
		cout << BankAccount::toString();
	}
	else { // Object is printed to file
		out << BankAccount::toString();
	}
}
// Mutators - read/write access
void BankAccount::setAccountNumber (const string & actN)
{
	ActNum = actN;
	cout << "-------------------------------" << '\n';
	cout << "Account number set successfully" << '\n';
	cout << "-------------------------------" << '\n';
}
void BankAccount::setLastName(const string & lname)
{
	LastName = lname;
	cout << "-------------------------------" << '\n';
	cout << "Last name set successfully" << '\n';
	cout << "-------------------------------" << '\n';
}
void BankAccount::deposit(double money)	
{
	if (money < 0.0) {
		cout << "-------------------------------" << '\n';
		cout << "Cannot deposit negative or zero amount" << '\n';
		cout << "Transaction cancelled" << endl;
		cout << "-------------------------------" << '\n';
	}
	else {
		balance += money;
		cout << fixed << showpoint << setprecision(2);
		cout << "-------------------------------" << '\n';
		cout << "Deposit successful. New balance is $" << balance << '\n';
		cout << "-------------------------------" << '\n';
	}
}
void BankAccount::withdraw(double money)
{
	if (money <= 0.0) {
		cout << "-------------------------------" << '\n';
		cout << "Cannot withdraw negative or zero amount" << '\n';
		cout << "Transaction cancelled" << endl;
		cout << "-------------------------------" << '\n';
	}
	else if ((balance - money) < 0.0) {
		cout << "-------------------------------" << '\n';
		cout << "Withdrawal amount is greater than balance" << '\n';
		cout << "Transaction cancelled" << endl; 
		cout << "-------------------------------" << '\n';
	}
	else {
		balance -= money;
		cout << fixed << showpoint << setprecision(2);
		cout << "-------------------------------" << '\n';
		cout << "Withdrawal successful. New balance is $" << balance << '\n';
		cout << "-------------------------------" << '\n';
	}
}
// Accessors - read only access
const string BankAccount::getAccountNumber() const
{
	return ActNum;
}
const string BankAccount::getLastName() const
{
	return LastName;
}
const string BankAccount::getFirstName() const
{
	return FirstName;
}
const string BankAccount::getFullName() const
{
	string fullname = FirstName + ' ' + LastName;
	return fullname;
}
double BankAccount::getBalance() const
{
	return balance;
}
	
/*
getInstance takes object and fills the otherwise blank class object instance;
1. getInstance(BankAccount & BA) takes input from cin
2. getInstance(BankAccount & BA, ifstream & in) takes input from input file
*/
	
/* 1. static prototype instantiates class as object
 * Can't call any other class functions that are not static.
 * Can't access non static class data members.
*/

void BankAccount::getInstance(BankAccount & BA) //static
{
	string actnum, lname, fname;
	double bal;
	cout << "Enter First Name: ";
	cin >> fname;
	cout << "Enter Last Name: ";
	cin >> lname;
	cout << "Enter Account #: ";
	cin >> actnum;
	cout << "Enter starting Balance [$XX.XX]: ";
	cin >> bal;
	BA = BankAccount(actnum, fname, lname, bal);
	cout << "-------------------------------" << '\n';
	cout << "Account created successfully" << '\n';
	cout << "-------------------------------" << '\n';
}
/* 2. static prototype instantiates class as object
 * Can't call any other class functions that are not static.
 * Can't access non static class data members.
*/
void BankAccount::getInstance(BankAccount & BA, ifstream & in)
{
	string actnum, lname, fname;
	double bal;
	in >> actnum;
	in >> lname;
	in >> fname;
	in >> bal;
	BA = BankAccount(actnum, fname, lname, bal);
	cout << "-------------------------------" << '\n';
	cout << "Account created successfully" << '\n';
	cout << "-------------------------------" << '\n';
}