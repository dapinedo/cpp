/*
Daniel Pinedo
Quadratic.cpp

CSCI 1
Assignment 3
Quadratic formula calculation
March 15, 2017
*/

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	cout << scientific << setprecision(4);
	// Declare input variables and constants
	int A, B, C = 0;
	const int StringAsterisk = 60; // used for output of consistent number of asterisks to screen

	// Greet user
	cout << string(StringAsterisk, '*') << '\n';
	cout << "Welcome to the EL CAMINO QUADRATIC EQUATION SOLVER \n";
	cout << "We are solving for X in AX^2 + BX + C = 0 \n";
	cout << string(StringAsterisk, '*') << '\n';
	
	// Prompt and accept user input for A and B
	cout << "Enter Value of A: ";
	cin >> A;
	bool FlagProceed = 1; // flag true if exists solution, false if A == 0 && B = 0
	if (A == 0) // this statement will print a warning if value of A is zero, proceeding later with a non-quadratic answer
	{
		cout << "if A is zero then this is a linear equation. To solve for BX + C = 0, please proceed. \n \n";
	}
	cout << "Enter Value of B: ";
	cin >> B;
	if (A == 0 && B == 0) // give FlagProceed value of false and send to end of program
	{
		FlagProceed = 0;
		cout << "with A and B equal to zero, we do not have an algebraic equation \n";
	}

	if (FlagProceed == 1) // if FlagProceed == 1 then complete the rest of program, otherwise send to return(0);
	{
		cout << "Enter Value of C: ";
		cin >> C;

		int Discr = (B * B) - (4 * A * C); // Calculate Discriminant of Quadratic equation
		if (A == 0) // linear output
		{
			double Algebraic = -1.0*(static_cast<double>(C) / B);
			//cout << setprecision(4);
			cout << "Solving for X in BX + C = 0. X = " << Algebraic << '\n';
		}
		else if (Discr < 0)
		{
			double ImaginaryL = (-B / (2.0 * A));
			double ImaginaryR = (sqrt(abs(Discr)) / (2 * A));
			if (ImaginaryL == 0)
			{
				cout << "The two imaginary solutions are: " << setw(5) << '(' << ImaginaryR << ')' << " * i" << '\n';
				cout << setw(33) << "and: " << setw(4) << " -" << '(' << ImaginaryR << ')' << " * i" << '\n';
			}
			else
			{
			cout << "The two imaginary solutions are: " << setw(5) << ImaginaryL << " + " << '(' << ImaginaryR << ')' << " * i" << '\n';
			cout << setw(33) << "and: " << setw(5) << ImaginaryL << " - " << '(' << ImaginaryR << ')' << " * i" << '\n';
			}
		}
		else if (Discr == 0)
		{
			if (B == 0 && C == 0)
			{
				cout << "Since the numerator is zero, the one solution is: " << setw(5) << 0 << '\n';
			}
			else
			{
				double Quadratic = (-B / (2.0 * A));
				cout << "Since your discriminant is zero, the one solution is: " << setw(5) << Quadratic << '\n';
			}
		}
		else if (Discr > 0)
		{
			double Quad1 = (-B + sqrt(Discr)) / (2 * A);
			double Quad2 = (-B - sqrt(Discr)) / (2 * A);
			cout << "The real solutions are: " << setw(5) << Quad1 << '\n';
			cout << setw(24) << "and: " << setw(5) << Quad2 << '\n';
		}
	} // end FlagProceed if statement
	
	// Say Goodbye
	cout << string(StringAsterisk, '*') << '\n';
	cout << "Thanks for using the EL CAMINO QUADRATIC EQUATION SOLVER \n";
	cout << string(StringAsterisk, '*') << '\n';

	return(0);
}