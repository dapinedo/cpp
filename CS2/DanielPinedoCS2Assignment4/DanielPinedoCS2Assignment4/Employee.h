/*
Name: Daniel Pinedo
Class: CS 2
Assignment #: 4
All Compilers Used: VS17
Operating Systems on Which Compiled: Win10
Date and Time of Last successful run: 10/15/2017 @2056
Email: d.p@ieee.org
*/

#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <string>
using namespace std;

class Employee
{
protected:
	string FirstName;
	string LastName;
	static const int MIN_NUM_CHARS_NAMES = 2;

public:
	Employee(const string & fname = "First not set", const string & lname = "Last not set");
	// pure virtual functions
	virtual const string getFirstName() const = 0;
	virtual const string getLastName() const = 0;
	virtual const string getFullName() const = 0;
	virtual const string toString() const = 0;
	virtual void setFirstName(const string & fname)  = 0;
	virtual void setLastName(const string & lname)  = 0;
	

	// virtual destructor
	virtual ~Employee();
};
#endif

