/*
Name: Daniel Pinedo
Class: CS 2
Assignment #: 3
All Compilers Used: VS17
Operating Systems on Which Compiled: Win10
Date and Time of Last successful run: 10/2/2017 @0200
Email: d.p@ieee.org
*/

#include "Fraction.h"

// prototypes for test functions
void test1(); // tests Fraction::constructor, normalize, GCD, and toString functions
void test2(); // tests friend operator functions for + - * and /

int main()
{
	// comment out test functions once all functions are tested/passed
	//test1(); // testing Exceptions, Normalize, and GCD in Fraction class
	test2(); // testing Fraction Arithmetic Functions
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
}

