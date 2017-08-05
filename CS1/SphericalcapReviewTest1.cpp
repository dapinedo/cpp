#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const double PI = 4 * atan(1.0);
/*
Program asks for a, b, and h for spherical cap. Program computes
Surface area, volume for the spherical segment, and 
Radius of the sphere of which the spherical segment will be part.
Imagine painting cost to paint spherical segment is
0.09 cents per square unit area. Print in dollars and whole cents
what the cost of painting will be.
*/
const double CST = 0.09;
int main()
{
	cout << fixed << showpoint << setprecision(5);
	cout << "This program will compute volume and surface area of spherical segment." << endl;
	cout << "The value of PI used has full accuracy but shown to five decimal point it is: "
		<< PI << endl;
	double b, a, h, S, V, R;
	cout << "Please enter the radius of circle on top of spherical segment: ";
	cin >> b;
	cout << "Please enter the radius of circle on bottom of spherical segment: ";
	cin >> a;
	/*
	The portion below using if/else will not be in test 1
	b must be smaller than a
	*/
	if (b >= a)
	{
		cout << "The values given by you will not form a spherical segment. Exiting." << endl;
		
	}
	else
	{
		cout << "Please enter the height of spherical segment: ";
		cin >> h;
		V = (1.0 / 6)*PI*h*(3 * a*a + 3 * b*b + h*h);
		R = sqrt(((a - b)*(a - b) + h*h)* ((a + b)*(a + b) + h*h)) / (2 * h);
		S = PI*(2 * R*h + a*a + a*b*b);
		cout << "The radius of sphere from which segment is constructed is: " << R << endl;
		cout << "The volume of segment: " << V << endl;
		cout << "Total surface area of segment: " << S << endl;
		double rawCost = S*CST;
		double rawPennies = rawCost * 100;
		int WholePennies = static_cast<int>(round(rawPennies));
		cout << "Paiting Cost: "
			<< (WholePennies / 100) << " dollars, and "
			<< (WholePennies % 100) << " cents. " << endl;
		cout << "Good bye." << endl;
	}
	return 0;
}