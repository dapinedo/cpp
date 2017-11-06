#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


struct Student
{
	string Name;
	double GPA;
	Student(string nm = "Name not set", double gp = 0.0) :
		Name(nm), GPA(gp)
	{

	}
	void print() const
	{
		cout <<fixed<<showpoint<<setprecision(2)
			<< "Student Name: " << Name << endl
			<< "GPA: " << GPA << endl;
	}
};

int main()
{
	int arr[5] = { 1, 2, 8 , 3, 5 };
	int * arrPtr = arr;
	arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << "Printing arry through the pointer: " << endl;

	for (size_t i = 0; i < 5; i++)
	{
		cout << arrPtr[i] << endl;
	}
	system("pause");
	return 0;
}

int main2()
{
	// Pointer to objects
	Student S1("John", 3.4);
	Student * sptr;
	sptr = &S1;
	(*sptr).print();
	cout << "Calling print function through the pointer using -> notation" << endl;
	sptr->print();// This is simply a short hand for (*sptr).print()
	system("pause");
	/*
	drill:
	Go to assignment 2 main function that you did.
	1. Create a BankAccount object using explicit constructor
	2. Create a BankAccount pointer bptr
	3. Assign to bptr the address of object created in step 1.
	4. Call the print function or tostring function to print
	object created in step 1 through the pointer pointing to it
	in step 3.


	*/
	return 0;
}
int main1()
{
	// Pointer to atomic data
	int * iptr;// stores garbage, does not point to anything
	int val = 5;
	iptr = &val;
	cout << "Printing val through its pointer: " << (*iptr) << endl;
	*iptr = 10; // write access through the pointer
	cout << "Printing value stored at val first through the variable name, then through its pointer, respectively: " << endl;
	cout << val << endl;
	cout << (*iptr) << endl;

	system("pause");
	return 0;
}