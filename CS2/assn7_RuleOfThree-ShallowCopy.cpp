#include <iostream>
#include <string>
using namespace std;

struct Student
{
	string * name;
	float gpa;


	void printStudent()
	{
		cout << "Name = " << *name << endl;
		cout << "GPA = " << gpa << endl;
	}
};

int main()
{
	Student S1;
	S1.name = new string("John");
	S1.gpa = 3.8f;
	Student S2;
	S2.name = new string("Mary");
	S2.gpa = 2.9f;
	cout << "Printing student S1.\n";
	S1.printStudent();
	cout << "Printing student S2.\n";
	S2.printStudent();
	//system("pause");
	//return 9;
	cout << "Setting student S2=S1.\n";
	S2 = S1;
	cout << "Printing student S2 again.\n";
	S2.printStudent();
	cout << "Changing name field of student S1 to \"Tyron\".\n";

	*S1.name = "Tyron";

	cout << "Printing student S1.\n";
	S1.printStudent();
	cout << "Printing student S2.\n";
	S2.printStudent();
	system("pause");
	return 0;
}
