/*
Satish Singhal
Class: CS1
Date:5/18/2017
Program Name: StructWithObjectOrientedFeatures
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

struct Student
{
	string first;//First name
	string last;//Last name
	int ID;
	int age;
	double gpa;

	Student()
	{
		first = "First name not yet set";
		last = "Last name not yet set.";
		ID = 0;
		age = 1;
		gpa = 0.0;
	}
	Student(string frst, string lst, int idNum, int ag, double gp)
	{
		first = frst;
		last = lst;
		ID = idNum;
		age = ag;
		gpa = gp;
	}
	// set functions - used after the struct is created but some changes are needed in struct member values
	void setGPA(double newGPA)
	{
		// Do safe mutation. Do not allow new GPA to be -ve or >4.0
		if (newGPA>= 0.0 && newGPA<= 4.0)
		{
			gpa = newGPA;
		}
		else
		{
			cout << newGPA << " is not a valid value. No changes made." << endl;
		}
	}
	void setAge(int newAge)
	{
		age = newAge;
	}
	void setLastName(string newLastName)
	{
		last = newLastName;
	}
	// get functions - provide read-only access
	string getFirstName()
	{
		return first;
	}
	string getLastName()
	{
		return last;
	}

	string getFullName()
	{
		return first + ' ' + last;
	}
	int getAge()
	{
		return age;
	}

	int getID()
	{
		return ID;
	}
	double getGPA()
	{
		return gpa;
	}
	void print()
	{
		cout << fixed << showpoint << setprecision(2)
			<< "Name: " << first << ' ' << last << endl
			<< "ID: " << ID << endl
			<< "Age on last birthday: " << age << " years." << endl
			<< "GPA: " << gpa << endl;

	}

	void print(ofstream & out)
	{
		out << fixed << showpoint << setprecision(2)
			<< "Name: " << first << ' ' << last << endl
			<< "ID: " << ID << endl
			<< "Age on last birthday: " << age << " years." << endl
			<< "GPA: " << gpa << endl;

	}
};
int main()
{
	//menu driven program to 
	//1. Create student data and print to console or write to file
	//2. Change student data, (last name, age or GPA)
	//3. Read only parts of student data - like only the full name etc.

	bool done = false;
	Student S;

	while (!done)
	{
		cout << "************Main Menu*******************\n"
			<< "1. Created student data from keyboard.\n"
			<< "2. Print student data to console.\n"
			<< "3. Print student data to data file.\n"
			<< "4. Change student's GPA.\n"
			<< "5. Change student's age.\n"
			<< "6. Change student's last name.\n"
			<< "7. Print whole name only to console.\n"
			<< "8. Exit." << endl;
		int choice;
		cin >> choice;

		if (choice == 1)// Create student from kwyboard data entry
		{
			string frst, lst;
			int idNum, ag;
			double gp;
			cout << "Enter first and last names in that order.";
			cin >> frst >> lst;
			cout << "Enter ID: ";
			cin >> idNum;
			cout << "Enter age on last birthday: ";
			cin >> ag;
			cout << "Enter current GPA: ";
			cin >> gp;
			S = Student(frst, lst, idNum, ag, gp);
		}
		else if (choice == 2)
		{
			S.print();
		}
	}
	return 0;
}
int main1()
{
	Student S;
	S.print();
	cout << "-------------------------------------------------" << endl;
	Student S2("John", "Adams", 101, 22, 0.0);
	cout << "Student data at the beginning of first semester." << endl;
	S2.print();
	// write to database
	//one semester later GPA changed to 3.21
	// Change it
	S2.setGPA(5.0);
	cout << "Student data at the beginning of second semester." << endl;
	S2.print();
	//Rewrite back to database as the GPA has been changed
	return 0;
}