#include "Student.h"

string Student::CollegeName = "El Camino College";
//const  int Student::COLLEGE_ZIP_CODE = 90506;
//Explicit constructors
Student::Student(int brthYr,string fname ,
	string lname , int idNum , double gp ):FirstName (fname),
	LastName (lname), ID(idNum),GPA(gp), BirthYear(brthYr)
{
	//BirthYear = brthYr;
	//FirstName = fname; // slower
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
		<< "GPA: " << GPA << endl
		<< "Birth Year: " << BirthYear << endl
		<< "College Name: " << CollegeName << endl;
}

void Student::Print(ofstream & out) const
{
	out << fixed << showpoint << setprecision(2)
		<< "Name:" << FirstName << ' '
		<< LastName << endl
		<< "ID: " << ID << endl
		<< "GPA: " << GPA << endl
		<< "Birth Year: " << BirthYear << endl
		<< "College Name: " << CollegeName << endl;
}

int Student::getBirthYear()const
{
	return BirthYear;
}

const  string Student::getCollgeName()
{
	return CollegeName;
}

Student Student::getInstance(istream & in)
{
	if (&cin == &in)// Object is filled from keyboard data input
	{
		string fname, lname;
		int byear, id;
		double gp;
		cout << "Enter First Name: ";
		cin >> fname;
		cout << "Enter last Name: ";
		cin >> lname;
		cout << "Enter ID: ";
		cin >> id;
		cout << "Enter birth Year: ";
		cin >> byear;
		cout << "Enter GPA: ";
		cin >> gp;
		return Student(byear, fname, lname, id, gp);

	}
	else// Object is filled from file data input
	{
		string fname, lname;
		int byear, id;
		double gp;
		in >> fname;
		in >> lname;
		in >> id;
		in >> byear;
		in >> gp;
		return Student(byear, fname, lname, id, gp);
	}
}

const string Student::toString() const
{
	ostringstream os;
	os << fixed << showpoint << setprecision(2)
		<< "Name: " << FirstName << ' ' << LastName << endl
		<< "ID: " << ID << endl
		<< "GPA: " << GPA << endl;
	return os.str();
}
Student::Student(const Student & S) : FirstName(S.FirstName),
LastName(S.LastName), ID(S.ID), GPA(S.GPA), BirthYear(S.BirthYear)
{
	
}

const Student & Student::operator = (const Student & S)
{
	if (&S != this)
	{
		int temp = S.BirthYear;
		const_cast<int&>(BirthYear) = temp;
		FirstName = (S.FirstName);
		LastName = (S.LastName);
		ID = (S.ID);
		GPA = (S.GPA);
	}

	return *this;
}