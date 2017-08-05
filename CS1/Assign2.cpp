/*
Daniel Pinedo
CSCI 1 - Section 0105
Assign2.cpp
*/

#include <iostream>
#include <cmath>
using namespace std;
//Grade: 17/17
int main()
{
	// Declare input variables
	double P;
	float r;
	int n, q;

	// Print greeting to user
	cout << "Hello. Please follow prompts below" << '\n' << '\n';

	// input and echo input
	cout << "Enter your Initial deposit amount <xxx.xx> and press Enter : ";
	cin >> P;
	cout << "You entered " << P << '\n';

	cout << "Enter your decimalized interest rate <.xxx> and press Enter : ";
	cin >> r;
	cout << "You entered " << r << '\n';
	cout << "Enter years left in deposit <xx> and press Enter : ";
	cin >> n;
	cout << "You entered " << n << '\n';

	cout << "Enter compounding times per year <xx> and press Enter : ";
	cin >> q;
	cout << "You entered " << q << '\n' << '\n';

	// Analysis
	double A, ACheck;

	A = P * pow((1 + (r / q)), (n*q)); // Total
	ACheck = 72 / (r * 100); // Rule of 72

	// Round cents and dollars
	double Atotalpennies = A * 100;
	Atotalpennies += 0.5;
	Atotalpennies = int(Atotalpennies);
	int Adollars = int(Atotalpennies) / 100;
	int Acents = int(Atotalpennies) % 100;

	// OUTPUT
	// Total
	cout << "With initial deposit of " << P
		<< ", over the course of " << n
		<< " remaining years, at an interest rate of " << r
		<< " compounding " << q << " times per year, "
		<< "you will have " << Adollars << " dollars"
		<< " and " << Acents << " cents. " << '\n' << '\n';

	// Rule of 72
	cout << "Rule of 72 states that it will take " << ACheck
		<< " years to double your deposit based "
		<< "on an interest rate of " << r << '\n';

	// Say goodbye to user
	cout << "This concludes our banking session. Goodbye!" << '\n';

	return 0;

}
