#include <iostream>
#include <string>
#include <fstream> // IO to files
#include <iomanip>
using namespace std;

const int MAX = 30; // array length
//struct declaration
struct Student
{
	string FirstName;
	string LastName;
	int ID;
	double GPA;
	//constructors
	// Constructors construct an object (of student type)
	//without using dot notation write access
	//rules of constructors
	/*
	1. Constructors have same name as struct/class name
	2. No return type because they are NOT functions.
	3. Default constructor takes no arguments
	4. Constructors can be overloaded or a struct/class can have 
	more than one constructor.

	*/
	// Default constructor
	/*Student()
	{
		cout << "From default constructor" << endl;
		FirstName = "First name not set";
		LastName = "Last name not set";
		ID = 0;
		GPA = 0.0;
	}*/
	//Explicit constructors
	Student(string fname = "First name not set", 
	string lname = "Last name not set", int idNum = 0, double gp = 0.0)
	{
		FirstName = fname;
		LastName = lname;
		ID = idNum;

		if (gp>= 0.0 && gp<= 4.0)
		{
			GPA = gp;
		}
		else
		{
			cout << "Illegal GPA. GPA is set to zero." << endl;
			GPA = 0.0;
		}
	}

	// Mutators or set functions
	// Safer mutation
	// Mutate GPA - Mutators are also called set functions
	//Mutators provide write access
	
	void setGPA(double inGPA)
	{
	    if (inGPA>= 0.0 && inGPA<= 4.0)
		{
			GPA = inGPA;
		}
		else
		{
			cout << "Illegal GPA. GPA is unchanged." << endl;
		
		}
	}
	
	void setLastName(string inLastName)
	{
	    LastName = inLastName;
	}
	// Get read access only to the portions of the object
	// These are called get functions
	string getFirstName() const
	{
		// uncommenting below will be a compile error
		//because const member functions are not allowed to do mutation
	//	ID = 1000;
	    return FirstName;
	}
	string getLastName() const{
		return LastName;
	}
	
	int getID() const{
		return ID;
	}
	
	double getGPA() const{
		return GPA;
	}
	
	string getFullName() const{
		return FirstName + ' ' + LastName;
	}
	void Print() const
	{
		cout << fixed << showpoint << setprecision(2)
			<<"Name:" << FirstName << ' '
			<< LastName << endl
			<< "ID: " << ID << endl
			<< "GPA: " << GPA << endl;
	}
	
	void Print(ofstream & out) const
	{
		out << fixed << showpoint << setprecision(2)
			<<"Name:" << FirstName << ' '
			<< LastName << endl
			<< "ID: " << ID << endl
			<< "GPA: " << GPA << endl;
	}
};

void print(const Student & S);
/*
Flag = 1 means sort based on ID
flag = 2 means sort based on last name
flag = 3 means sort based on GPA
*/
void bubbleSort(Student Arr[], size_t logicalLen, size_t flag);
void print(const Student Arr[], size_t len);
int main()
{
	Student StuArr[MAX];
//	StuArr[0].Print();
	StuArr[0] = Student("John", "Doe", 9876, 3.9);
//	StuArr[0].Print();
	StuArr[1] = Student("Kim", "Adams", 1234, 4.0);
	StuArr[2] = Student("Jim", "Zackson", 3245, 2.9);
	StuArr[3] = Student("Lisa", "Jackson", 4567, 3.6);
	StuArr[4] = Student("Mary", "Boston", 1111, 2.7);
	bubbleSort(StuArr,5,1);
	print(StuArr,5);
	return 0;
}
int main1()
{
	Student S1;// default constructor is called
	S1.Print();

//Student(string fname, string lname, int idNum, double gp)
	Student S2("Mary", "Jones", 2345, 3.1);

	Student S3("Tim", "Johnson", 9876, 5.0);
	
	cout << "Printing S2 using print member function:" << endl;
	S2.Print();
	cout << "Printing S3 using print member function:" << endl;
	S3.Print();
	return 0;
}

void print(const Student Arr[], size_t len)
{
	for(size_t i = 0; i<len; i++)
	{
		Arr[i].Print();
	}
}
void print(const Student & S)
{
	cout<<S.getFirstName()<<endl;
}

void bubbleSort(Student Arr[], size_t logicalLen, size_t flag)
{
	for ( size_t i = 0; i< logicalLen; i++) {
			for ( size_t j = 0; j< logicalLen - 1 - i; j++)
			{
				if(flag == 1)// sort on ID
				{
					if(Arr[j].getID() > Arr[j+1].getID())
					{
						// Swap whole struct members in the array
						Student Temp;
						Temp = Arr[j];
						Arr[j] = Arr[j+1];
						Arr[j+1] = Temp;
					}
				}
				else 	if(flag == 2)// sort on last name
				{
					//complete yourself
				}
					else 	if(flag == 3)// sort on GPA
				{
					//complete yourself
				}
			}// Inner for loop
	}// outer for loop
}
/*
From default constructor
Name:John Doe
Illegal GPA. GPA is set to zero.
Printing S1 using print member function:
Name:John Doe
ID: 1234
GPA: 3.50
Printing S2 using print member function:
Name:Mary Jones
ID: 2345
GPA: 3.10
Printing S3 using print member function:
Name:Tim Johnson
ID: 9876
GPA: 0.00
*/