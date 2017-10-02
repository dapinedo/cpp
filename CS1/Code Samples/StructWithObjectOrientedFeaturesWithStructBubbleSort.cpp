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
const int MAX = 10;
void print(Student arr[], size_t len);
void bubbleSort(Student arr[], size_t len, int flag);
int main()
{
	Student StuArr[MAX];
	//	Student(string frst, string lst, int idNum, int ag, double gp)
	StuArr[0] = Student("John", "Jackson", 9999, 35, 3.9);
	StuArr[1] = Student("Tim", "Adams", 1234, 23, 2.9);
	StuArr[2] = Student("Bertha", "Bentley", 2222, 45, 3.1);
	StuArr[3] = Student("Cindy", "Gomez", 4444, 30, 3.7);
	StuArr[4] = Student("Lisa", "Nguyen", 1111, 19, 2.4);
	cout << "Unsorted data." << endl;
	print(StuArr, 4);
	bubbleSort(StuArr, 4, 1);
	cout << "Sorted based on ID." << endl;
	print(StuArr, 4);
	return 0;
}

void bubbleSort(Student arr[], size_t len, int flag)
{
	for (size_t i = 0; i < len; i++)
	{
		for (size_t j = 0; j < len-i-1; j++)
		{
			if (flag == 1)// sort based on ID
			{
				// swap code
				if (arr[j].ID > arr[j+1].ID)
				{
					// swap the whole structure. Do not swap ID's
					// This is struct array. This is not atomic array
					Student Temp;
					Temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = Temp;
				}
			}
			else if (flag == 2)//sort based on last name
			{
				// complete yourself
			}
			else if (flag == 3)// Sort based on age
			{
				// complete yourself
			}
			else if (flag == 4)// sort based on GPA
			{
				// complete yourself
			}
		}
	}
}
void print(Student arr[], size_t len)
{
	for (size_t i = 0; i < len; i++)
	{
		arr[i].print();
		cout << "--------------------------------\n";
	}
	cout << "--------------------------------\n";
}
int main2()
{
	//menu driven program to 
	//1. Create student data and print to console or write to file
	//2. Change student data, (last name, age or GPA)
	//3. Read only parts of student data - like only the full name etc.

	bool done = false;
	Student S;
	// Student S2( .... pass values for constructor parameters in the order in which they map in the constructor header)
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
		else if (choice == 3)
		{
			string OutFileName;
			cout << "Type full path to input file: ";
			cin.sync(); // windows
			// cin.ignore(128, '\n); // use in mac or. all other situations
			getline(cin, OutFileName);
			ofstream out(OutFileName);

			if (out.is_open())
			{
				S.print(out);
			}
			else
			{
				cout << "Failed to open/create output file." << endl;
				continue;
			}
		}
		else if (choice == 4)
		{
			cout << "Enter new GPA: ";
			double gp;
			cin >> gp;
			S.setGPA(gp);
		}
		else if (choice == 5)
		{
			//Do yourself
		}
		else if (choice == 6)
		{
			//Do yourself
		}
		else if (choice == 7)
		{
			cout << S.getFullName() << endl;
		}
		else
		{
			done = true;
		}
	}//end of loop
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