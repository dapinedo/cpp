#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include <fstream> // IO to files
#include <iomanip>
#include <sstream>
using namespace std;

class Student
{
private:
	string FirstName;
	string LastName;
	int ID;
	double GPA;
	const int BirthYear;
	static string CollegeName;// No initialization allowed here or in constructor
	const static int COLLEGE_ZIP_CODE ;
public:
	//Explicit constructors
	Student(int brthYr = 0, string fname = "First name not set",
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
	int getBirthYear()const;
	// static member functions are not allowed const end modifier
	const static string getCollgeName();
	/*
	getInstance would take an istream object (cin, ifstream)
	and fills the otherwise blanck object Stnd;
	*/
	static Student getInstance(istream & in);

	//Overloading of = operator and copy constructor will be discussed later.
	// But to make current example work in all possible ways they have to be added here,
	// though these topics are yet to be completed.
	//Ignore code in the below for now, until we cover them later

	Student(const Student & S);
	const Student & operator = (const Student & S);

	const string toString() const;
};

#endif

