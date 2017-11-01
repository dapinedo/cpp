#include <iostream>
#include <string>
using namespace std;

static int leak_counter = 0;
/*
Do a version of this program where struct is modified as below
struct Student
{
	string * name;
	float * gpa;
	// add default constructor, explict constructor
	// Rule of three functions and a print function

};
*/
struct Student
{
	string * name;
	float gpa;

	Student(): name(new string("Name not set")), gpa(0.0f)
	{ 
		
	}
	Student(string name1, float gpa1): name (new string(name1)),
		gpa (gpa1)
	{
	
		leak_counter++;
		
	}

	Student(const Student& Other):
		name (new string(*(Other.name))), gpa (Other.gpa)
	{
		if (this == &Other)
		{
			cout << "Self copy is prohibited. Exiting." << endl;
			exit(1);
		}
		;
		leak_counter++;
		
		cout << "From Copy constructor.\n";
	}
	const Student & operator = (const Student& Other)
	{
		if (this == &Other)
			return *this;
		delete this->name;
		leak_counter--;
		this->name = new string(*Other.name);
		leak_counter++;
		this->gpa = Other.gpa;
		return *this;
	}

	virtual ~Student()
	{
		delete name;
		leak_counter--;
	}



	void printStudent()
	{
		cout << "Name = " << *name << endl;
		cout << "GPA = " << gpa << endl;
	}






	static const Student& increaseGpa(Student & Std)
	{
		if (Std.gpa <= 3.9)
			Std.gpa += 0.1f;

		return Std;
	}
};

void main()
{
	{
		Student S1;
		S1.name = new string("John");
		leak_counter++;
		S1.gpa = 3.8f;
		Student S2;
		S2.name = new string("Mary");
		leak_counter++;
		S2.gpa = 2.9f;
		cout << "Printing student S1.\n";
		S1.printStudent();
		cout << "Printing student S2.\n";
		S2.printStudent();
		cout << "Setting student S1=S2.\n";
		S1 = S2;
		cout << "Printing student S2 again.\n";
		S2.printStudent();
		cout << "Changing name field of student S1 to \"Tyron\".\n";
		*S1.name = "Tyron";
		cout << "Printing student S1.\n";
		S1.printStudent();
		cout << "Printing student S2.\n";
		S2.printStudent();
		S2 = Student::increaseGpa(S2);
		cout << "After increasing GPA of student S2.\n";
		S2.printStudent();
	}
	cout << "The value of leak counter = " << leak_counter << endl;

	system("pause");
}
