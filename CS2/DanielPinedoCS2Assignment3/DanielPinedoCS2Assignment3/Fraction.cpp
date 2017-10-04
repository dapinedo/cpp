/*
Name: Daniel Pinedo
Class: CS 2
Assignment #: 3
All Compilers Used: VS17
Operating Systems on Which Compiled: Win10
Date and Time of Last successful run: 10/4/2017 @0345
Email: d.p@ieee.org
*/

#include "Fraction.h"

/* Class invariants
*		1. denominator cannot be 0
*		2. fraction is reduced and normalized
*/

Fraction::Fraction(long Top, long Bottom) : numerator(Top), denominator(Bottom)
{
	if (denominator == 0) {
		throw invalid_argument("denominator cannot be 0");
	}
	Fraction::normalize();
	long gcd;
	gcd = Fraction::gcd(numerator, denominator);
	long num = numerator / gcd;
	long den = denominator / gcd;
	numerator = num;
	denominator = den;
}

const string Fraction::toString() const
{
	ostringstream os;
	if (denominator != 1) {
		os << numerator << '/' << denominator << '\n';
	}
	else {
		os << numerator << '\n';
	}
	return os.str();
}

void Fraction::normalize()
{
	if (numerator < 0 && denominator > 0) {
		//do nothing, this is normalized
	}
	else if ((numerator < 0 && denominator < 0) || (numerator > 0 && denominator < 0)) {
		//both negative or numerator is positive and denominator is negative, therefore switch signs in either case
		denominator *= -1;
		numerator *= -1;
	}
	else {
		// do nothing, final case has both numerator and denominator as positive
	}
}

long Fraction::gcd(long a, long b)
{
	a = abs(a);
	b = abs(b);
	// recursive algorithm for finding Euclidian algorithm of Greatest Common Denominator (GCD)
	if (b == 0) { //step 1 of 3
		return a;
	}
	else if (a >= b) { //step 2 of 3
		return gcd(b, a%b); // only works if a >= b
	}
	else { //step 3 of 3
		return gcd(b, a);        // if a < b switch them.
	}
}

const Fraction operator + (const Fraction & left, const Fraction & right)
{
	long denominator = left.denominator * right.denominator;
	long leftnum = left.numerator;
	leftnum *= right.denominator;
	long rightnum = right.numerator;
	rightnum *= left.denominator;
	long numerator = leftnum + rightnum;
	return Fraction(numerator, denominator);
}
const Fraction operator - (const Fraction & left, const Fraction & right)
{
	long denominator = left.denominator * right.denominator;
	long leftnum = left.numerator;
	leftnum *= right.denominator;
	long rightnum = right.numerator;
	rightnum *= left.denominator;
	long numerator = leftnum - rightnum;
	return Fraction(numerator, denominator);
}
const Fraction operator * (const Fraction & left, const Fraction & right)
{
	long denominator = left.denominator * right.denominator;
	long numerator = left.numerator * right.numerator;
	return Fraction(numerator, denominator);
}
const Fraction operator / (const Fraction & left, const Fraction & right)
{
	long denominator = left.denominator * right.numerator;
	long numerator = left.numerator * right.denominator;
	return Fraction(numerator, denominator);
}

bool operator == (const Fraction & left, const Fraction & right)
{
	return ((left.numerator == right.numerator) && (left.denominator == right.denominator));
}

bool operator != (const Fraction & left, const Fraction & right)
{
	return ((left.numerator != right.numerator) || (left.denominator != right.denominator));
}

ostream & operator << (ostream & out, const Fraction & F)
{
	out << F.toString();
	return out;
}

istream & operator >> (istream & in, Fraction & F)
{
	if (&in == &cin) {
		int num, den;
		cout << "Enter numerator: ";
		cin >> num;
		cout << "Enter denominator: ";
		cin >> den;
		F = Fraction(num, den);
	}
	else {
		int num, den;
		in >> num >> den;
		F = Fraction(num, den);
	}
	return in;
}

const Fraction Fraction::operator ++() // pre increment
{
	numerator = numerator + denominator;
	return Fraction(numerator, denominator);
}
const Fraction Fraction::operator ++(int NotUsed) //post increment
{
	// Save values before post increment
	int num = numerator;
	int den = denominator;
	numerator = numerator + denominator;
	return Fraction(num, den);
}

const Fraction Fraction::operator --() // pre increment
{
	numerator = numerator - denominator;
	return Fraction(numerator, denominator);
}
const Fraction Fraction::operator --(int NotUsed) //post increment
{
	// Save values before post increment
	int num = numerator;
	int den = denominator;
	numerator = numerator - denominator;
	return Fraction(num, den);
}

const long Fraction::getTop() const
{
	return numerator;
}
const long Fraction::getBottom() const
{
	return denominator;
}
const double Fraction::toDouble() const
{
	return (static_cast<double>(numerator) / denominator);
}

Fraction::~Fraction()
{
}
