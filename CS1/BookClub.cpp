/*
Daniel Pinedo
CS1 - Extra Credit
Gaddis, Ch. 4, #13 - Book Club
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	// Declare variables
	unsigned int BookPurchases, PointsAwarded;

	// Greet user
	cout << "Hello prized book buyer!" << '\n'; 
	cout << "This program will calculate your book buyer points accrued this month" << '\n';

	// User input
	cout << "Enter the total number of books you have purchased this month and hit <Enter>: ";
	cin >> BookPurchases;
	cout << "You entered " << BookPurchases << '\n';

	// Analysis
	if (BookPurchases == 0)
	{
		PointsAwarded = 0;
		cout << "You have " << PointsAwarded << " points this month. Buy more books!" << '\n';
	}
	else if (BookPurchases == 1)
	{
		PointsAwarded = 5;
		cout << "You have been awarded " << PointsAwarded << " points!" << '\n';
	}
	else if (BookPurchases == 2)
	{
		PointsAwarded = 15;
		cout << "You have been awarded " << PointsAwarded << " points!" << '\n';
	}
	else if (BookPurchases == 3)
	{
		PointsAwarded = 30;
		cout << "You have been awarded " << PointsAwarded << " points!" << '\n';
	}
	else if (BookPurchases >= 4)
	{
		PointsAwarded = 60;
		cout << "Wow!! You have been awarded " << PointsAwarded << " points!" << '\n';
	}
	else
	{
		cout << "You have entered invalid input. Please run the program again." << '\n';
	}
	cout << string(45, '*') << '\n';
	cout << "Thank you for your patronage. Be sure to use your points awarded this month for a big discount! Goodbye!" << '\n';
	
	return 0;
}