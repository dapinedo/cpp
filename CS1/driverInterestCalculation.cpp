/*
Author: Satish Singhal Ph. D.
Project: Interest Calculation on Savings /Read from file and write to file
Date: 4/1/2015
Operating System: Windows 7
Compiler: Visual Studio 2013
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	cout << fixed << showpoint << setprecision(2);
	string InputFileName;
	cout << "This program will process the file with savings data and compute interest on savings. " << endl
		<< "Please type full path to input file and press enter: " << endl;
	getline(cin, InputFileName);
	ifstream in(InputFileName);

	if (!in.is_open())
	{
		cout << "Failed to open input file. " << endl;
		exit(0);
	}

	string OutputFileName;
	cout<< "Please type full path to output file and press enter: " << endl;
	getline(cin, OutputFileName);
	ofstream out(OutputFileName);

	if (!out.is_open())
	{
		cout << "Failed to open output file. " << endl;
		exit(0);
	}

	out << fixed << showpoint << setprecision(2);

	double TotalInterestGiven = 0.0;
	int NumCustomers = 0;
	//Header
	out << "===============================================================================================================" << endl;
	out << left << setw(20) << "Name" << right << setw(15) << "Principal Sum($)" << setw(15) << "Interest($)"
		<< setw(15) << "Total Funds($)" << setw(20) << "Average Balance($)" << endl;
	out << "================================================================================================================" << endl;
	cout << "===============================================================================================================" << endl;
	cout << left << setw(20) << "Name" << right << setw(15) << "Principal Sum($)" << setw(15) << "Interest($)"
		<< setw(15) << "Total Funds($)" << setw(20) << "Average Balance($)" << endl;
	cout << "================================================================================================================" << endl;

	while (in.peek() != EOF)
	{
		NumCustomers++;
		string first, last, fullName;
		in >> first >> last;
		fullName = first + ' ' + last;

		double oneDeposit = 0.0;
		in >> oneDeposit;
		double sum = 0.0;
		int numDeposits = 0;

		while (oneDeposit > 0.0)
		{
			sum += oneDeposit;
			numDeposits++;
			in >> oneDeposit;
		}

		if (numDeposits > 0)
		{
			int compoundTimes = 0;
			double numYears = 0.0;
			in >> compoundTimes >> numYears;

			double averageDeposit = sum / numDeposits;
			double rate = 0.0;

			if (numYears>= 5)
			{
				rate = 0.045;
			}
			else if (numYears >= 4)
			{
				rate = 0.04;
			}
			else if (numYears >= 3)
			{
				rate = 0.035;
			}
			else if (numYears >= 2)
			{
				rate = 0.025;
			}
			else if (numYears >= 1)
			{
				rate = 0.02;
			}
			else
			{
				rate = 0.015;
			}

			double Acuum = sum*pow(1 + rate / compoundTimes, compoundTimes*numYears);
			double interest = Acuum - sum;
			TotalInterestGiven += interest;
			//Print all data
			out << left << setw(20) << fullName << right << setw(15) << sum << setw(15) << interest
				<< setw(15) << Acuum << setw(20) << averageDeposit << endl;
			cout << left << setw(20) << fullName << right << setw(15) << sum << setw(15) << interest
				<< setw(15) << Acuum << setw(20) << averageDeposit << endl;
		}//if numDepoits>0
		else
		{
			out << left << setw(20) << fullName << right << setw(20)<< "You have no deposits so far. " << endl;
			cout << left << setw(20) << fullName << right << setw(20) << "You have no deposits so far. " << endl;
		}
	}//EOF loop
	//Computation of Total Interest Given in dollars and cents
	double Tpennies = TotalInterestGiven*100;
	int TroundedPennies = static_cast<int>(Tpennies + 0.5);
	int Tdollars = (TroundedPennies/100);
	int Tcents = (TroundedPennies % 100);
	out << "===============================================================================================================" << endl;
	out << "Total number of customers in the file: " << NumCustomers << endl;
	out << "Total interest disbursed to customers: $" << TotalInterestGiven << endl;
	out<<"Total interest disbursed in dollars and cents: "<<Tdollars<<" dollars and "<<Tcents<<" cents."<<endl;
	out << "Thank you for using our program." << endl;

	cout << "===============================================================================================================" << endl;
	cout << "Total number of customers in the file: " << NumCustomers << endl;
	cout << "Total interest disbursed to customers: $" << TotalInterestGiven << endl;
	cout<<"Total interest disbursed in dollars and cents: "<<Tdollars<<" dollars and "<<Tcents<<" cents."<<endl;
	cout << "Thank you for using our program." << endl;

	in.close();
	out.close();
	return 0;
}
