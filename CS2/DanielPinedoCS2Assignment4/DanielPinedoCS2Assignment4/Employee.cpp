#include "Employee.h"

Employee::Employee(string & fname, string & lname) : FirstName(fname), LastName(lname)
{
	cout << "Employee constructor invoked";
}

Employee::~Employee()
{
}
