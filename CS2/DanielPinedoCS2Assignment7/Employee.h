#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Employee {
private:
	string firstName;
	string * lastName;
	int hourWorked;
	double PayRate;
	double Salary;
public:
	//default constructor
	Employee();
	//explicit constructor
	Employee(string first, string last, int hours, double rate, double sal);
	//ABOVE memory allocation for pointer lastName is done inside the constructors
	
	//copy constructor
	Employee(const Employee& Other);
	//ABOVE copy constructor makes a deep copy

	//assignment operator 
	const Employee & operator = (const Employee& Other);
	//ABOVE assignment operator makes deep copy and deletes the memory allocated to the pointer 
	//which is being given a new pointee.


	//virtual destructor 
	~Employee();
	//ABOVE de-allocates the memory allocated by constructors.
	
	//toString function 
	const string toString() const;
	//ABOVE causes no mutation in the object and returns a const object.
};
#endif
