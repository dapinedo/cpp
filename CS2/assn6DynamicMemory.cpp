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
		cout << fixed << showpoint << setprecision(2)
			<< "Student Name: " << Name << endl
			<< "GPA: " << GPA << endl;
	}
};

int main()
{
	// Single student allocation dynamically
	Student * sptr = new Student("John", 3.4);
	cout << "Printing dynamically created student object through its pointer: " << endl;
	(*sptr).print();
	cout << "Printing using the arrow notation: " << endl;
	sptr->print();
	//deallocate
	delete sptr;
	// array of objects
	Student * StArray = new Student[5];
	StArray[0] = Student("Tim", 2.9);
	StArray[1] = Student("Jim", 3.9);
	StArray[2] = Student("Kim", 3.4);
	StArray[3] = Student("Adam", 3.1);
	StArray[4] = Student("Lisa", 3.99);

	for (size_t i = 0; i < 5; i++)
	{
		StArray[i].print();
	}
	// De-allocate the array
	delete StArray;
	system("pause");
	return 0;
}
int main2()
{
	int * arrPtr;
	const int MAX = 10;
	arrPtr = new int[MAX];
	arrPtr[0] = 5;
	arrPtr[1] = 88;
	arrPtr[2] = 10;
	arrPtr[3] = 12;
	arrPtr[4] = 11;
	arrPtr[5] = 123;
	arrPtr[6] = 23;
	arrPtr[7] = 7;
	arrPtr[8] = 99;
	arrPtr[9] = 6;

	for (size_t i = 0; i < MAX; i++)
	{
		cout<<arrPtr[i] << "  ";
	}
	cout << endl;
	//deallocate the array
	delete[] arrPtr;
	system("pause");
	return 0;
}
int main1()
{
	// dynamic allocation and deallocation for atomic varables
	int * iptr;

	iptr = new int(5);

	cout << "Printing the value of dynamically created variable through its pointer: ";
	cout <<endl<< *iptr<<endl;
	//deallocate if variable with 5 is no longer needed
	delete iptr;// deallocation
	for (size_t i = 0; i < 10; i++)
	{
		double * dptr = new double(i + 0.1);
		cout << "Right now variable pointed by pointer dptr = "
			<< *dptr << endl;
		delete dptr;
	}
	system("pause");
	return 0;
}