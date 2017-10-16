#include "Employee.h"

Employee::Employee(const string & fname, const string & lname) : FirstName(fname), LastName(lname)
{
	if (FirstName.length() < MIN_NUM_CHARS_NAMES) {
		cout << "First name not set. Needs to be at least " << MIN_NUM_CHARS_NAMES << " characters" << endl;
		FirstName = "First not set";
	}
	if (LastName.length() < MIN_NUM_CHARS_NAMES) {
		cout << "Last name not set. Needs to be at least " << MIN_NUM_CHARS_NAMES << " characters" << endl;
		LastName = "Last not set";
	}
}

Employee::~Employee()
{
}
