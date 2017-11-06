#include "Employee.h"

/* 
Set first object equal to second using assignment operator and then print both. Write the 
following stand-alone function: void print(Employee E); print, simply prints E to console.
*/
void print(Employee E);

int main()
{
	// testing Employee.toString()
	Employee E;
	cout << E.toString() << endl;

	// testing copy constructor and assignment operator
	Employee E1;
	Employee E2("John", "Smith", 40, 37.50, 65000.00);
	E1 = E2;
	print(E1);
	print(E2);

	system("pause");
}

void print(Employee E)
{
	cout << E.toString() << endl;
}