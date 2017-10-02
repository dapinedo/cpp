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
	~Fraction();
};
#endif

