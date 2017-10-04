/*
Name: Daniel Pinedo
Class: CS 2
Assignment #: 3
All Compilers Used: VS17
Operating Systems on Which Compiled: Win10
Date and Time of Last successful run: 10/4/2017 @0345
Email: d.p@ieee.org
*/

#pragma once
#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
using namespace std;

/* Class invariants
 *		1. denominator cannot be 0
 *		2. fraction is reduced and normalized
 */

class Fraction
{
private:
	long numerator;
	long denominator;
public:
	Fraction(long Top = 0, long Bottom = 1);
	const string toString() const;
	void normalize();
	long gcd(long a, long b);
	friend const Fraction operator + (const Fraction & left, const Fraction & right);
	friend const Fraction operator - (const Fraction & left, const Fraction & right);
	friend const Fraction operator * (const Fraction & left, const Fraction & right);
	friend const Fraction operator / (const Fraction & left, const Fraction & right);
	friend bool operator == (const Fraction & left, const Fraction & right);
	friend bool operator != (const Fraction & left, const Fraction & right);
	friend ostream & operator << (ostream & out, const Fraction & C);
	friend istream & operator >> (istream & in, Fraction & C);
	const Fraction operator ++(); // pre increment
	const Fraction operator ++(int NotUsed); //post increment
	const Fraction operator --(); // pre increment
	const Fraction operator --(int NotUsed); //post increment
	const long getTop() const;
	const long getBottom() const;
	const double toDouble() const;
	~Fraction();
};
#endif

