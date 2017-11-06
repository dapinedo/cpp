#include "Employee.h"

Employee::Employee() : firstName("Not set"), lastName(new string("Not set")), 
	hourWorked(0), PayRate(0.0f), Salary(0.0f)
{
	cout << "From Default constructor.\n";
}

Employee::Employee(string first, string last, int hours, double rate, double sal) :
	firstName(first), lastName(new string(last)), hourWorked(hours), PayRate(rate), Salary(sal)
{
	cout << "From Explicit constructor.\n";
}

Employee::Employee(const Employee& Other) : firstName(Other.firstName),
	lastName (new string(*(Other.lastName))), hourWorked(Other.hourWorked), PayRate(Other.PayRate),
	Salary(Other.Salary)
{
	if (this == &Other) {
		cout << "Self copy is prohibited. Exiting." << endl;
		exit(1);
	}

	cout << "From Copy constructor.\n";
}

const Employee & Employee::operator = (const Employee& Other)
{
	if (this == &Other)
		return *this;
	delete this->lastName;
	this->firstName = Other.firstName;
	this->lastName = new string(*Other.lastName);
	this->hourWorked = Other.hourWorked;
	this->PayRate = Other.PayRate;
	this->Salary = Other.Salary;
	return *this;
	cout << "From Assignment Operator.\n";
}

const string Employee::toString() const
{
	ostringstream os;
	os << "First Name: " << firstName << '\n';
	os << "Last Name: " << *lastName << '\n';
	os << "Hours Worked: " << hourWorked << '\n';
	os << "Pay Rate: " << PayRate << '\n';
	os << "Salary: " << Salary << '\n';
	return os.str();
}

Employee::~Employee()
{
	delete lastName;
	cout << "From Destructor.\n";
}

