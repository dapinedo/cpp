#pragma once
#include <iostream>
#include <string>
#include <fstream> // IO to files
#include <iomanip>
using namespace std;
class Student
{
private:
	string FirstName;
	string LastName;
	int ID;
	double GPA;
public:
	//Explicit constructors
	Student(string fname = "First name not set",
		string lname = "Last name not set", int idNum = 0, double gp = 0.0);
	
	// Mutators or set functions
	// Safer mutation
	// Mutate GPA - Mutators are also called set functions
	//Mutators provide write access

	void setGPA(double inGPA);

	void setLastName(string inLastName);
	// Get read access only to the portions of the object
	// These are called get functions
	string getFirstName() const;
	string getLastName() const;

	int getID() const;

	double getGPA() const;

	string getFullName() const;
	void Print() const;

	void Print(ofstream & out) const;
	
};

