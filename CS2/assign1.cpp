// Daniel Pinedo
// Assignment 1
//

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	cout << fixed << showpoint << setprecision(2)
		<< "Welcome!!! Please follow the prompts below \n";

	cout << "Please enter your full name and press Enter when done: ";
	string name = "";
	getline(cin, name);
	cout << "Thank you, " << name << '\n';
	cin.sync();
	cout << "Enter employee code ([S] O M): ";
	char code = 'S';
	cin >> code;
	cout << "You entered: " << code << '\n';
	cout << "Enter ID Number [1234]: ";
	int id = 1234;
	cin >> id;
	cout << "Enter job classification ([1] 2 3): ";
	int classif = 1;
	cin >> classif;
	cout << "Enter educational code ([1] 2 3): ";
	int edu = 1;
	cin >> edu;
	int years = 0;
	cout << "Enter total years of service [0]: ";
	cin >> years;
	string codename = "";
	double basesalary = 0.00;
	
	switch (code)
	{
	case 'S':
		{
		codename = "Factory Worker";
		basesalary = 800.00;
		break;
		}
	case 'O':
		{
		codename = "Office Worker";
		basesalary = 1000.00;
		break;
		}
	case 'M':
		{
		codename = "Management";
		basesalary = 1500.00;
		break;
		}
	}

	double classifadj = 0.00;
	
	switch (classif)
	{
	case 1:
		{
		classifadj = (.05 * basesalary);
		break;
		}
	case 2:
		{
		classifadj = (.10 * basesalary);
		break;
		}
	case 3:
		{
		classifadj = (.20 * basesalary);
		break;
		}
	}

	double eduadj = 0.0;
	switch (edu)
	{
	case 2:
		{
		eduadj = (.05 * basesalary);
		break;
		}
	case 3:
		{
		eduadj = (.12 * basesalary);
		break;
		}
	case 4:
		{
		eduadj = (.20 * basesalary);
		break;
		}
	}

	double seniorityadj = 0.0;
	if (years >= 0 && years <= 10)
	{
		seniorityadj = (.05 * basesalary);
	}
	else if (years > 10 && years < 50)
	{
		seniorityadj = (.01 * (years - 10) * basesalary);
	}
	else
	{
		cout << "Invalid entry for years of service" << "\n";
	}

	double totalsalary = basesalary + classifadj + eduadj + seniorityadj;
	
	cout << setprecision(6) << "Base Salary: " << basesalary << '\n';
	cout << "Classification Adjustment: +" << classifadj << '\n';
	cout << "Educational Adjustment: +" << eduadj << '\n';
	cout << "Seniority Adjustment: +" << seniorityadj << '\n' << setprecision(2);


	cout << setw(20) << "Name" << setw(15) << "ID#"
		<< setw(25) << "Job Type" << setw(15) << "Gross Salary" << '\n';

	cout << setw(20) << name << setw(15) << id
		<< setw(25) << codename << setw(15) << totalsalary << '\n';
	
	return 0;
}

