/*
Name: Daniel Pinedo
Class: CS 2
Assignment #: 4
All Compilers Used: VS17
Operating Systems on Which Compiled: Win10
Date and Time of Last successful run: 10/15/2017 @2056
Email: d.p@ieee.org
*/

#include "Manager.h"

Manager::Manager(const string & fname, const string & lname,
	double sal, const string & btitle) : Employee(fname, lname), salary(sal), TitleOfBoss(btitle)
{
	if (salary < 0) {
		cout << "Salary cannot be less than zero. Taking absolute value of " << salary << endl;
		salary = abs(salary);
	}
	if (TitleOfBoss.length() < MIN_NUM_CHARS_NAMES) {
		cout << "Boss Title not set. Needs to be at least " << MIN_NUM_CHARS_NAMES << " characters" << endl;
		TitleOfBoss = "boss title not set";
	}
}

const string Manager::getFirstName() const
{
	return FirstName;
}
const string Manager::getLastName() const
{
	return LastName;
}
const string Manager::getFullName() const
{
	return FirstName + ' ' + LastName;
}
const string Manager::toString() const
{
	ostringstream oss;
	oss << fixed << showpoint << setprecision(2);
	oss << "Boss' Name: " << getFullName() << endl
		<< "Boss' Title: " << TitleOfBoss << endl
		<< "Boss' Salary: " << salary << endl;
	return oss.str();
}
void Manager::setFirstName(const string & fname)
{
	if (fname.length() < MIN_NUM_CHARS_NAMES) {
		cout << "First name not changed. Needs to be at least " << MIN_NUM_CHARS_NAMES << " characters" << endl;
	}
	else {
		FirstName = fname;
		cout << "First name changed to: " << FirstName << endl;;
	}
}
void Manager::setLastName(const string & lname)
{
	if (lname.length() < MIN_NUM_CHARS_NAMES) {
		cout << "Last name not changed. Needs to be at least " << MIN_NUM_CHARS_NAMES << " characters" << endl;
	}
	else {
		LastName = lname;
		cout << "Last name changed to: " << LastName << endl;
	}
}
double Manager::getSalary() const
{
	return salary;
}
const string Manager::getBossTitle() const
{
	return TitleOfBoss;
}
void Manager::setSalary(double sal) 
{
	if (sal < 0) {
		cout << "Salary cannot be less than zero. Taking absolute value of " << sal << endl;
		sal = abs(sal);
	}
	salary = sal;
	cout << fixed << showpoint << setprecision(2) << "Salary set to: " << salary << endl;
}
void Manager::setBossTitle(const string & Title)
{
	if (Title.length() < MIN_NUM_CHARS_NAMES) {
		cout << "Boss Title not changed. Needs to be at least " << MIN_NUM_CHARS_NAMES << " characters" << endl;
	}
	else {
		TitleOfBoss = Title;
		cout << "Boss title changed to: " << TitleOfBoss << endl;
	}
}


Manager::~Manager()
{
}
