#pragma once
#ifndef MANAGER_H
#define MANAGER_H
#include "Employee.h"
class Manager : public Employee
{
protected:
	double salary;
	string TitleOfBoss;
public:
	Manager(const string & fname = "First not set", const string & lname = "Last not set", 
		double sal = 0.0, const string & btitle = "Boss title not set");
	const string getFirstName() const;
	const string getLastName() const;
	const string getFullName() const;
	const string toString() const;
	void setFirstName(const string & fname);
	void setLastName(const string & lname);
	double getSalary() const;
	const string getBossTitle() const;
	void setSalary(double sal);
	void setBossTitle(const string & Title);
	~Manager();

};
#endif
