#include "Complex.h"



Complex::Complex(double RL, double IM) :Real(RL), Imag(IM)
{

}

const string Complex::toString() const
{
	ostringstream os;
	os << fixed << showpoint << setprecision(4)
		<< Real;

	if (Imag >0.0)
	{
		os << " + " << Imag << "*I" << endl;
	}
	else if (Imag<0.0)
	{
		os << " - " << abs(Imag) << "*I" << endl;
	}
	else
	{
		os << endl;
		// no code needed
	}

	return os.str();
}

const Complex operator + (const Complex & left, const Complex & right)
{
	double SReal = left.Real + right.Real;
	double SImag = left.Imag + right.Imag;
	return Complex(SReal, SImag);
}

const Complex operator - (const Complex & left, const Complex & right)
{
	double DReal = left.Real - right.Real;
	double DImag = left.Imag - right.Imag;
	return Complex(DReal, DImag);
}

const Complex operator * (const Complex & left, const Complex & right)
{
	throw "To be completed";
}

const Complex operator /(const Complex & left, const Complex & right)
{
	throw "To be completed";
}

ostream & operator<<(ostream & out, const Complex & C)
{
	out << C.toString();
	return out;
}

istream & operator >>(istream & in, Complex & C)
{
	if (&in == &cin)
	{
		double RL, IM;
		cout << "Enter The real part of complex number: ";
		cin >> RL;
		cout << "Enter the imaginary part of complex number: ";
		cin >> IM;
		C = Complex(RL, IM);
	}
	else
	{
		double RL, IM;
		in >> RL >> IM;
		C = Complex(RL, IM);
	}

	return in;
}

bool operator == (const Complex & left, const Complex & right)
{
	return (left.Real == right.Real) && (left.Imag == right.Imag);
}

bool operator != (const Complex & left, const Complex & right)
{
	return (left.Real != right.Real)|| (left.Imag != right.Imag);
}

double Complex::absolute() const
{
	return sqrt(Real*Real + Imag*Imag);
}
Complex::~Complex()
{
}
