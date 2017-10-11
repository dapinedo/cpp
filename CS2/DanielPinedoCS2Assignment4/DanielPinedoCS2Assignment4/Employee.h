#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
using namespace std;

class Employee
{
protected:
	string FirstName;
	string LastName;

public:
	Employee(string & fname = "not set", string & lname = "not set");
	// pure virtual functions
	virtual void getFirstName() const = 0;
	virtual void getLastName() const = 0;
	virtual void getFullName() const = 0;
	virtual void setLastName() const = 0;
	virtual void setFirstName() const = 0;
	virtual void toString() const = 0;

	// virtual destructor
	virtual ~Employee();
};
#endif

