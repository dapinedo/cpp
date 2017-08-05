/*
Satish Singhal
Class: CS1
Date:
Program Name:
*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


int main()
{
	char code;
	char cheeseCode;
	int flourCode;
	int toppingCode;
	cout << "Please enter your first name only: ";
	string name;
	cin >> name;
	cout << "Hello " << name << endl;
	cout << "Welcome to worldwide Pizza. We will take your order and process it." << endl
		<< "Please enter the pizza size [S]mall, or [M]edium, or [L]arge , or e[X]tra large: ";
	cin >> code;
	code = toupper(code);
	bool flagBaseCode = (code == 'S') || (code == 'M') || (code == 'L') ||
		(code == 'X');
	cout << "We would like to know what kind of fluor you would like in pizza crust: " << endl;
	cout << "Enter 0, for white fluor crust, 1, for whole wheat, 2 for organic whole wheat, 3 for multigrain: ";
	cin >> flourCode;
	bool flagFluorCode = (flourCode == 0 || flourCode == 1 || flourCode == 2 
		|| flourCode == 3);
	cout << "Now we would like to know your pizza cheese preferences:" << endl;

	cout << "Would you like [R]egular cheese, [E]xtra cheese or [J]alapeno cheese, or [G]oat cheese? ";
	cin >> cheeseCode;
	cheeseCode = toupper(cheeseCode);
	bool flagCheeseCode =
		(cheeseCode == 'R' || cheeseCode == 'E' || cheeseCode == 'J' 
		|| cheeseCode == 'G');

	cout << "Now we will ask for your toppings. " << endl;
	cout << " Enter 0 for none, Enter 1 for mushrooms, 2 for shrimp, 3 for organic olives, 4 for organic peppers, 5 for all: ";
	cin >> toppingCode;
	bool flagToppingCode = (toppingCode == 0 || toppingCode == 1 ||
		toppingCode == 2 || toppingCode == 3 ||
		toppingCode == 4 || toppingCode == 5);

	if (flagBaseCode && flagFluorCode && flagCheeseCode && flagToppingCode)
	{
		double baseCost;

		if (code == 'S')
		{
			baseCost = 2.0;
		}
		else if (code == 'M')
		{
			baseCost = 4.0;
		}
		else if (code == 'L')
		{
			baseCost = 6.0;
		}
		else
		{
			baseCost = 8.0;
		}

		double incrFluor;

		if (flourCode == 0)
		{
			incrFluor = 0.0;
		}
		else if (flourCode == 1)
		{
			incrFluor = baseCost * 0.02;
		}
		else if (flourCode == 2)
		{
			incrFluor = baseCost * 0.04;
		}
		else
		{
			incrFluor = baseCost * 0.06;
		}

		double CheeseIncr;
		if (cheeseCode == 'R')
		{
			CheeseIncr = 0.0;
		}
		if (cheeseCode == 'E')
		{
			CheeseIncr = 0.01*baseCost;
		}
		else if (cheeseCode == 'J')
		{
			CheeseIncr = 0.02*baseCost;
		}
		else 
		{
			CheeseIncr = 0.05*baseCost;
		}
		// ToppingIncr
		double toppingIncr;
		if (toppingCode == 0)
		{
			toppingIncr = 0.0;
		}
		else if (toppingCode == 1)
		{
			toppingIncr = 0.50 + baseCost*.01;
		}
		else if (toppingCode == 2)
		{
			toppingIncr = 1.00 + baseCost*.1;
		}
		else if (toppingCode == 3)
		{
			toppingIncr = 1.00 + baseCost*.15;
		}
		else if (toppingCode == 4)
		{
			toppingIncr = 0.50 + baseCost*.09;
		}
		else
		{
			toppingIncr =  0.50 + baseCost*.01 + 1.00 + baseCost*.1
				+ 1.00 + baseCost*.15 + 0.50 + baseCost*.09;
		}

		double finalCost = baseCost + incrFluor + CheeseIncr + toppingIncr;
		cout << "Your Pizza Cost $" << finalCost << endl;
		//do yourself computaion of whole dollars and cents and print

	}
	else
	{
		cout << "One or more codes in your order prevent us from order processing. Please reorder." << endl;

		if (!flagBaseCode)
		{
			cout << "Invalid Pizza size was specified.\n";
		}

		if (!flagFluorCode)
		{
			cout << "Invalid flour code was specified.\n";
		}

		if (!flagCheeseCode)
		{
			cout << "Invalid cheese code was specified.\n";
		}

		if (!flagToppingCode)
		{
			cout << "Invalid topping code was specified.\n";
		}
	}

	return 0;
}
/*
Please enter your first name only: satish
Hello satish
Welcome to worldwide Pizza. We will take your order and process it.
Please enter the pizza size [S]mall, or [M]edium, or [L]arge , or e[X]tra large: M
We would like to know what kind of fluor you would like in pizza crust:
Enter 0, for white fluor crust, 1, for whole wheat, 2 for organic whole wheat, 3 for multigrain: 2
Now we would like to know your pizza cheese preferences:
Would you like [R]egular cheese, [E]xtra cheese or [J]alapeno cheese, or [G]oat cheese? J
Now we will ask for your toppings.
Enter 0 for none, Enter 1 for mushrooms, 2 for shrimp, 3 for organic olives, 4 for organic peppers, 5 for
Your Pizza Cost $8.64
*/