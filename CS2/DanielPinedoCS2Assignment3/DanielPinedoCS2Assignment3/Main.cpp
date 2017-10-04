/*
Name: Daniel Pinedo
Class: CS 2
Assignment #: 3
All Compilers Used: VS17
Operating Systems on Which Compiled: Win10
Date and Time of Last successful run: 10/4/2017 @0300
Email: d.p@ieee.org
*/

#include "Fraction.h"
#include "FractionList.h"

// prototypes for test functions
void test1(); // tests Fraction::constructor, normalize, GCD, and toString
void test2(); // tests friend operator functions for + - * and /
void test3(); // tests friend operator functions for == and !=
void test4(); // tests friend operator functions for << and >>
void test5(); // tests const operator functions ++pre and post++ increment
void test6(); // tests nonmutator functions
void test7(); // tests Fractionlist::constructor, addFraction, toString, sort, isEmpty, isFull, getNumberofElements

int main()
{
	// comment out test functions once all functions are tested/passed
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	FractionList FL;
	cout << boolalpha;
	cout << "Welcome to our fraction program." << endl;
	bool inputdone = false;
	bool done = false;
	short choice = 10;
	while (!done) {
		cout << "Please choose from menu below" << endl;
		cout << "-------------------------------------" << endl;
		cout << "1. Enter Fraction list from file. " << endl;
		cout << "2. Enter Fraction list from keyboard." << endl;
		if (inputdone) {
			cout << "3. Test output of Fraction list using << and also toString() to console" << endl;
			cout << "4. Test output of Fraction list using << and also toString() to output file" << endl;
			cout << "5. Sort and output to console using << " << endl;
			cout << "6. Print sum, largest fraction, sort state to console" << endl;
		}
		cout << "7. Test functioning of operators with keyboard input" << endl;
		cout << "8. Test functioning of pre- and post fix operators with keyboard input" << endl;
		if (inputdone) {
			cout << "9. Test operation of [] overloaded operator" << endl;
		}
		cout << "[10]. Exit" << endl;
		cout << "Enter choice: ";
		cin >> choice;
		if (choice == 1) {
			cout << "Enter full path of file to open: ";
			string inputfile = "";
			cin.ignore(255, '\n');
			getline(cin, inputfile);
			fstream in(inputfile);
			if (in.is_open()) {
				cout << "File opened" << endl;
				FractionList::getInstance(FL, in);
				in.close();
				inputdone = true;
			}
			else {
				cout << "File could not be opened" << endl;
			}
		}
		else if (choice == 2) {
			FractionList::getInstance(FL, cin);
			inputdone = true;
		}
		else if (choice == 3 && inputdone) {
			cout << "Output using >> " << endl;
			cout << FL;
			cout << "Output using toString() " << endl;
			cout << FL.toString();
		}
		else if (choice == 4 && inputdone) {
			cout << "Enter full path of file to open: ";
			string outputfile = "";
			cin.ignore(255, '\n');
			getline(cin, outputfile);
			fstream out(outputfile);
			if (out.is_open()) {
				out << "Output using >> " << endl;
				out << FL;
				out << "Output using toString() " << endl;
				out << FL.toString();
				out.close();
				cout << "File created" << endl;
			}
			else {
				cout << "File could not be created" << endl;
			}
		}
		else if (choice == 5 && inputdone) {
			FL.sort();
			cout << "Sorted list below" << endl;
			cout << FL << endl;
		}
		else if (choice == 6 && inputdone) {
			cout << "Sum of Fractions: " << FL.getSumOfFractions();
			cout << "Largest Fraction: " << FL.getLargest();
			cout << "Sort State: " << FL.getSortState();
		}
		else if (choice == 7) {
			cout << "Enter values for two fractions" << endl;
			cin.ignore(255, '\n');
			Fraction F1;
			Fraction F2;
			cin >> F1 >> F2;
			cout << "F1 + F2 = " << F1 + F2 << endl;
			cout << "F1 - F2 = " << F1 - F2 << endl;
			cout << "F1 * F2 = " << F1 * F2 << endl;
			cout << "F1 / F2 = " << F1 / F2 << endl;
			cout << "2 + F2 = " << 2 + F2 << endl;
			cout << "F2 + 2 = " << F2 + 2 << endl;
			cout << "2 - F2 = " << 2 - F2 << endl;
			cout << "F2 - 2 = " << F2 - 2 << endl;
			cout << "2 * F2 = " << 2 * F2 << endl;
			cout << "F2 * 2 = " << F2 * 2 << endl;
			cout << "2 / F2 = " << 2 / F2 << endl;
			cout << "F2 / 2 = " << F2 / 2 << endl;
		}
		else if (choice == 8) {
			cout << "Enter values for two fractions" << endl;
			cin.ignore(255, '\n');
			Fraction F1;
			Fraction F2;
			cin >> F1 >> F2;
			Fraction temp1 = F1;
			Fraction temp2 = F2;
			cout << "++F1 = " << ++F1 << endl;
			cout << "F1++ = " << temp1++ << endl;
			cout << "--F2 = " << --F2 << endl;
			cout << "F2-- = " << temp2-- << endl;
		}
		else if (choice == 9 && inputdone) {
			cout << "Enter index number of fraction you wish to retrieve: ";
			cin.ignore(255, '\n');
			size_t index = 0;
			cin >> index;
			cout << FL[index];
		}
		else if (choice == 10) {
			done = true;
		}
		else {
			cout << "Invalid Choice. Try again" << endl;
		}
	}
	system("pause");
	return 0;
}

void test1()
{
	cout << "Initializing test fractions ..." << '\n';
	//Throw exception and exit if denominator = 0 and exits program
	//Fraction f1(9, 0);
	Fraction f2(-6, -12);
	Fraction f3(9, -12);
	Fraction f4(8, 16);
	Fraction f5(5, 16);
	Fraction f6(-5);
	Fraction f7(5, -1);
	cout << "Initialization completed ..." << '\n';
	//Test Normalize and GCD
	cout << "Normalizing and running GCD on all test fractions ..." << '\n';
	cout << f2.toString() << '\n';
	cout << f3.toString() << '\n';
	cout << f4.toString() << '\n';
	cout << f5.toString() << '\n';
	cout << f6.toString() << '\n';
	cout << f7.toString() << '\n';
	cout << "Normalization and GCD completed ..." << '\n';

	/*
	Initializing test fractions ...
	Initialization completed ...
	Normalizing and running GCD on all test fractions ...
	1/2

	-3/4

	1/2

	5/16

	-5

	-5

	Normalization and GCD completed ...
	*/
}

void test2()
{
	Fraction f2(6, -12);
	Fraction f3(-9, 12);
	cout << "f2 = " << f2.toString() << endl;
	cout << "f3 = " << f3.toString() << endl;
	cout << "f2 + f3 = " << (f2 + f3).toString() << endl;
	cout << "f2 - f3 = " << (f2 - f3).toString() << endl;
	cout << "f2 * f3 = " << (f2 * f3).toString() << endl;
	cout << "f2 / f3 = " << (f2 / f3).toString() << endl;
	cout << "f2 + 2 = " << (f2 + 2).toString() << endl;
	cout << "2 + f2 = " << (2 + f2).toString() << endl;
	cout << "f2 - 2 = " << (f2 - 2).toString() << endl;
	cout << "2 - f2 = " << (2 - f2).toString() << endl;
	cout << "f2 * 2 = " << (f2 * 2).toString() << endl;
	cout << "2 * f2 = " << (2 * f2).toString() << endl;
	cout << "f2 / 2 = " << (f2 / 2).toString() << endl;
	cout << "2 / f2 = " << (2 / f2).toString() << endl;

	/*
	f2 = -1/2

	f3 = -3/4

	f2 + f3 = -5/4

	f2 - f3 = 1/4

	f2 * f3 = 3/8

	f2 / f3 = 2/3

	f2 + 2 = 3/2

	2 + f2 = 3/2

	f2 - 2 = -5/2

	2 - f2 = 5/2

	f2 * 2 = -1

	2 * f2 = -1

	f2 / 2 = -1/4

	2 / f2 = -4
	*/
}

void test3()
{
	Fraction F1(1, 3);
	Fraction F2(2, 6);
	Fraction F3(5, 5);
	cout << boolalpha; // output boolean values to alpha "true" or "false"
	cout << "F1= " << F1.toString();
	cout << "F2= " << F2.toString();
	cout << "F3= " << F3.toString();
	cout << "F1==F2 is: " << (F1 == F2) << endl;
	cout << "F1!=F2 is: " << (F1 != F2) << endl;
	cout << "F1!=F3 is: " << (F1 != F3) << endl;
	cout << "F1==F3 is: " << (F1 == F3) << endl;
	cout << "F3==1 is: " << (F3 == 1) << endl;
	cout << "1==F3 is: " << (1 == F3) << endl;
	cout << "F3==2 is: " << (F3 == 2) << endl;
	cout << "2==F3 is: " << (2 == F3) << endl;
	cout << "F1==F1 is: " << (F1 == F1) << endl;
	cout << "(F1+1)==(1+F1) is: " << ((F1 + 1) == (1 + F1)) << endl;
	cout << "(F1*F2)==(F1*F2) is: " << ((F1 * F2) == (F1 * F2)) << endl;
	cout << "(F1/F2)==(F1/F2) is: " << ((F1 / F2) == (F1 / F2)) << endl;
	cout << "(F1-F2)==(F1-F2) is: " << ((F1 - F2) == (F1 - F2)) << endl;
	cout << "(F1+1)==(F1+2) is: " << ((F1 + 1) == (F1 + 2)) << endl;
	cout << "(F1*F2)==(F1*F3) is: " << ((F1 * F2) == (F1 * F3)) << endl;
	cout << "(F1/F2)==(F1/F3) is: " << ((F1 / F2) == (F1 / F3)) << endl;
	cout << "(F1-F2)==(F1-F3) is: " << ((F1 - F2) == (F1 - F3)) << endl;

	/*
	F1= 1/3
	F2= 1/3
	F3= 1
	F1==F2 is: true
	F1!=F2 is: false
	F1!=F3 is: true
	F1==F3 is: false
	F3==1 is: true
	1==F3 is: true
	F3==2 is: false
	2==F3 is: false
	F1==F1 is: true
	(F1+1)==(1+F1) is: true
	(F1*F2)==(F1*F2) is: true
	(F1/F2)==(F1/F2) is: true
	(F1-F2)==(F1-F2) is: true
	(F1+1)==(F1+2) is: false
	(F1*F2)==(F1*F3) is: false
	(F1/F2)==(F1/F3) is: false
	(F1-F2)==(F1-F3) is: false
	*/
}

void test4()
{
	Fraction F1;
	Fraction F2;
	Fraction F3;
	cin >> F1 >> F3; // tests cascaded input 
	// numerator 1: -8, denominator 1: -16
	// numerator 2: 9, denominator 2: -12
	cout << F1 << endl << F3 << endl; // tests cascaded output
	cout << "Enter full path to file from which to read the fraction: ";
	cin.ignore(255, '\n');
	string inputfile;
	getline(cin, inputfile);
	ifstream in(inputfile);
	if (!in.is_open()) {
		cout << "Failed to open input file. Exiting program." << endl;
		exit(0);
	}
	in >> F2; // Tests input from file
	cout << "Enter full path to file to which to output the Fraction: ";
	cin.ignore(255, '\n');
	string outputfile;
	getline(cin, outputfile);
	ofstream out(outputfile);
	if (!out.is_open()) {
		cout << "Failed to create output file. Exiting program" << endl;
		exit(0);
	}
	cout << "The fraction read from file is: " << F2 << endl;
	cout << "Now writing to file." << endl;
	out << F2; // Tests output to file
	in.close();
	out.close();
}

void test5()
{
	Fraction F1(-8, -16);
	Fraction F2(6, -12);
	cout << "F1 = " << F1 << endl;
	cout << ++F1 << endl;
	cout << F1++ << endl;
	cout << F1 << endl;
	cout << "F2 = " << F2 << endl;
	cout << --F2 << endl;
	cout << F2-- << endl;
	cout << F2 << endl;

	/*
	F1 = 1/2

	3/2

	3/2

	5/2

	F2 = -1/2

	-3/2

	-3/2

	-5/2
	*/
}

void test6()
{
	Fraction F(-8, -16);
	cout << "Fraction is: " << F << endl;
	cout << "The numerator is: " << F.getTop() << endl;
	cout << "The denominator is: " << F.getBottom() << endl;
	cout << "The double value is: " << F.toDouble() << endl;

	/*
	Fraction is: 1/2

	The numerator is: 1
	The denominator is: 2
	The double value is: 0.5
	*/
}

void test7()
{
	Fraction F1(-8, -16);
	Fraction F2(6, -12);
	Fraction F3(9, -12);
	Fraction F4(5, 6);
	Fraction F5(-11, 17);
	FractionList FL;
	FL.addFraction(F1);
	FL.addFraction(F2);
	FL.addFraction(F3);
	FL.addFraction(F4);
	FL.addFraction(F5);
	cout << "The Fraction List is: " << endl << FL.toString() << endl;
	FL.sort();
	cout << "After ascending order sort, the FractionList is: " << endl << FL.toString() << endl;
	cout << boolalpha; // boolean output in word form
	cout << "It is " << FL.isEmpty() << " that list is empty()" << endl;
	cout << "It is " << FL.isFull() << " that list is full()" << endl;
	cout << "The list has " << FL.getNumberOfElements() << " fractions." << endl;

	/*
	The Fraction List is:
	1/2
	-1/2
	-3/4
	5/6
	-11/17

	After ascending order sort, the FractionList is:
	-3/4
	-11/17
	-1/2
	1/2
	5/6

	It is false that list is empty()
	It is false that list is full()
	The list has 5 fractions.
	*/
}

