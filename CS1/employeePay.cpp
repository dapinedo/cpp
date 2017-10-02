/*
Daniel Pinedo
Computer Science 1
Assignment 6: User Defined Functions
April 25, 2017

employeePay.cpp
*/

// C++ Libraries
#include <iostream>
#include <iomanip>
#include <string>

// Namespaces
using namespace std;

// Global Constants
const double SS_TAX = 0.071; // Social Security Tax constant
const double HEALTH_DEDUCT = 200.00; // Health Deduction constant
const int DIVIDER_NUM = 60; // Output Divider Repetition constant
const char DIVIDER_CHAR = '*'; // Output Divider Char constant

// Function Prototypes
void greeting(); 
double getUserData (double &, string &, string &, bool &);
double getGrossSalary (double, double);
double getTaxWitheld (double);
double getNetSalary (double, double, bool, string &);
void printResults (const string &, const string &, double, double, double, double, double, const string &);
void goodbye();

int main()
{
	// Run entire algorithm 8 times
	for (size_t i = 0; i < 8; i++)
	{
		// GREETING
		cout << string(DIVIDER_NUM, DIVIDER_CHAR) << endl;
		greeting();
		cout << string(DIVIDER_NUM, DIVIDER_CHAR) << endl;

		// INPUT
		// run function getUserData() & return value of function = total hours worked
		double rate; // hourly rate
		string first, last; // name
		bool plan; // boolean for plan choice yes/no t/f
		double hours = getUserData(rate, first, last, plan); // total hours worked, user input
		cout << string(DIVIDER_NUM, DIVIDER_CHAR) << endl;

		// ANALYSIS
		double gross = getGrossSalary(hours, rate);
		double tax = getTaxWitheld(gross);
		string statusMessage;
		double net = getNetSalary(gross, tax, plan, statusMessage);

		// OUTPUT
		printResults(first, last, hours, rate, gross, tax, net, statusMessage);
		cout << string(DIVIDER_NUM, DIVIDER_CHAR) << endl;

		//GOODBYE
		goodbye();
	}

	return 0;
}

// Function Headers

void greeting()
{
	cout << "Welcome to salary calculation program." << endl;
	cout << "In this program we will ask for the information that would allow us to process your paycheck." << endl;
	cout << "We will collect information about hours worked, hourly pay rate, and medical options." << endl;
	cout << "Processing will be completed in just a few minutes." << endl;
	return;
}

double getUserData (double & payRate, string & firstName, string & lastName, bool & healthPlan)
{
	cout << "Please enter your first name [One word only]: ";
	cin >> firstName;
	cout << "Please enter your last name [One word only]: ";
	cin >> lastName;
	cout << "Please enter hours worked (positive number only): ";
	double hoursWorked;
	cin >> hoursWorked;
	cout << " Please enter your hourly pay rate. [For example enter 15.23 if your hourly pay rate is $15 and 23 cents]: ";
	cin >> payRate;
	cout << "Enter 1 to purchase health plan or 0 (zero) to decline: ";
	cin >> healthPlan;
	return (hoursWorked);
}

double getGrossSalary (double hoursWorked, double payRate)
{
	double grossSalary;
	if (hoursWorked <= 40)
	{
		grossSalary = payRate * hoursWorked;
	}
	else if (hoursWorked > 40)
	{
		double overTimePay = (1.5*payRate)*(hoursWorked - 40);
		grossSalary = payRate * 40 + overTimePay;
	}
	return (grossSalary);
}

double getTaxWitheld (double grossSalary)
{
	double taxWitheld = grossSalary * SS_TAX;
	return (taxWitheld);
}

double getNetSalary (double grossSalary, double taxWitheld, bool healthPlan, string & healthPlanStatusMessage)
{
	double netSalary = grossSalary - taxWitheld;
	if (healthPlan)
	{
		if (netSalary >= HEALTH_DEDUCT)
		{
			netSalary -= HEALTH_DEDUCT;
			healthPlanStatusMessage = "Employee opted for health insurance and was successfuly registered.";	
		}
		else
		{
			healthPlanStatusMessage = "Employee opted for health insurance but was declined because of insufficient salary.";
		}
	}
	else
	{
		healthPlanStatusMessage = "Employee did not opt to register in health plan.";
	}
	return (netSalary);
}

void printResults (const string & firstName, const string & lastName, double hoursWorked, double payRate, double grossSalary, double taxWitheld, double netSalary, const string & healthPlanStatusMessage)
{
	cout << fixed << showpoint << setprecision(2);
	cout << "Here are the employee payroll details." << endl;
	cout << "Name: " << firstName << ' ' << lastName << endl;
	cout << "Hours worked: " << hoursWorked << " hours" << endl;
	cout << "Hourly Pay Rate: $" << payRate << endl;
	cout << "Gross Salary: $" << grossSalary << endl;
	cout << "Tax witheld: $" << taxWitheld << endl;
	cout << healthPlanStatusMessage << endl;
	cout << "Employee net salary: $" << netSalary << endl;
	return;
}

void goodbye()
{
	cout << "Thank you for using our program." << endl;
	cout << "Please have a pleasant day." << endl;
	return;
}