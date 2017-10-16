#pragma once
#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
using namespace std;

class Complex
{
private:
	double Real;
	double Imag;
public:
	Complex(double RL = 0.0, double IM = 0.0);
	const string toString() const;
	friend const Complex operator + (const Complex & left, const Complex & right) ;
	friend const Complex operator - (const Complex & left, const Complex & right);
	
	// Complete below * and / as drill and verify that they work
	// Hand out has all the code for them
	friend const Complex operator * (const Complex & left, const Complex & right);
	friend const Complex operator / (const Complex & left, const Complex & right);
	friend ostream & operator<<(ostream & out, const Complex & C);
	friend istream & operator >>(istream & in, Complex & C);
	friend bool operator == (const Complex & left, const Complex & right);
	friend bool operator != (const Complex & left, const Complex & right);
	double absolute() const;
	// Pre-increment
	const Complex operator ++();
	//post increment
	const Complex operator ++(int NotUsed);
	//Drill: Do the two decrements as a drill
	const Complex operator --();
	const Complex operator --(int NotUsed);

	double getReal() const;
	double getImaginary() const;
	~Complex();
};
#endif
