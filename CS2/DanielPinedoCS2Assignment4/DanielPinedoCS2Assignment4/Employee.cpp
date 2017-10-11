#include "Employee.h"

Employee::Employee(const string & fname, const string & lname) : FirstName(fname), LastName(lname)
{
	int fcounter = 0;
	int lcounter = 0;
	for (auto & c : FirstName) {
		fcounter++;
	}
	for (auto & c : LastName) {
		lcounter++;
	}
	if (fcounter < MIN_NUM_CHARS_NAMES) {
		FirstName = "not set, value too short";
	}
	if (lcounter < MIN_NUM_CHARS_NAMES) {
		LastName = "not set, value too short";
	}
}

Employee::~Employee()
{
}
