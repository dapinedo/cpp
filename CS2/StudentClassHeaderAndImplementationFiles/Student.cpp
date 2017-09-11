#include "Student.h"

//Explicit constructors
Student::Student(string fname ,
	string lname , int idNum , double gp )
{
	FirstName = fname;
	LastName = lname;
	ID = idNum;

	if (gp >= 0.0 && gp <= 4.0)
	{
		GPA = gp;
	}
	else
	{
		cout << "Illegal GPA. GPA is set to zero." << endl;
		GPA = 0.0;
	}
}

void Student::setGPA(double inGPA)
{
	if (inGPA >= 0.0 && inGPA <= 4.0)
	{
		GPA = inGPA;
	}
	else
	{
		cout << "Illegal GPA. GPA is unchanged." << endl;

	}
}

void Student::setLastName(string inLastName)
{
	LastName = inLastName;
}
// Get read access only to the portions of the object
// These are called get functions
string Student::getFirstName() const
{
	// uncommenting below will be a compile error
	//because const member functions are not allowed to do mutation
	//	ID = 1000;
	return FirstName;
}
string Student::getLastName() const {
	return LastName;
}

int Student::getID() const {
	return ID;
}

double Student::getGPA() const {
	return GPA;
}

string Student::getFullName() const {
	return FirstName + ' ' + LastName;
}
void Student::Print() const
{
	cout << fixed << showpoint << setprecision(2)
		<< "Name:" << FirstName << ' '
		<< LastName << endl
		<< "ID: " << ID << endl
		<< "GPA: " << GPA << endl;
}

void Student::Print(ofstream & out) const
{
	out << fixed << showpoint << setprecision(2)
		<< "Name:" << FirstName << ' '
		<< LastName << endl
		<< "ID: " << ID << endl
		<< "GPA: " << GPA << endl;
}

