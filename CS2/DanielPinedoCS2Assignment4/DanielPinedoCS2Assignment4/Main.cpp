/*
Name: Daniel Pinedo
Class: CS 2
Assignment #: 4
All Compilers Used: VS17
Operating Systems on Which Compiled: Win10
Date and Time of Last successful run: 10/15/2017 @2056
Email: d.p@ieee.org
*/

#include "Employee.h"
#include "Manager.h"

int main()
{
	cout << fixed << showpoint << setprecision(2);
	Manager m;
	bool done = false;
	bool instanced = false;
	short choice = 8;
	do {
		cout << "********** Main Menu **********" << endl;
		cout << "1. Create Manager instance from keyboard." << endl;
		if (instanced) {
			cout << "2. Print Manager to console." << endl;
			cout << "3. Change Manager's last name." << endl;
			cout << "4. Change Manager's salary." << endl;
			cout << "5. Change Manager's Boss' title." << endl;
			cout << "6. Print only Manager's name and Salary to console" << endl;
			cout << "7. Print only Manager's boss' title to console" << endl;
		}
		cout << "8. Exit" << endl;
		cout << "Enter menu item number and press enter: ";
		cin >> choice;
		if (choice == 1) {
			string first, last, title;
			double salary;
			cout << "Enter Manager First Name: ";
			cin >> first;
			cout << "Enter Manager Last Name: ";
			cin >> last;
			cout << "Enter Manager Salary: ";
			cin >> salary;
			cout << "Enter Manager Boss' title: ";
			cin.ignore(255, '\n');
			getline(cin, title);
			m = Manager(first, last, salary, title);
			instanced = true;
		}
		else if (choice == 2 && instanced) {
			cout << m.toString();
		}
		else if (choice == 3 && instanced) {
			string last;
			cout << "Enter Manager Last Name: ";
			cin >> last;
			m.setLastName(last);
		}
		else if (choice == 4 && instanced) {
			double salary;
			cout << "Enter Manager Salary: ";
			cin >> salary;
			m.setSalary(salary);
		}
		else if (choice == 5 && instanced) {
			string title;
			cout << "Enter Manager Boss' title: ";
			cin >> title;
			m.setBossTitle(title);
		}
		else if (choice == 6 && instanced) {
			cout << "Manager Name: " << m.getFullName() << endl
				<< "Manager Salary: " << m.getSalary() << endl;
		}
		else if (choice == 7 && instanced) {
			cout << "Manager's Boss' title: " << m.getBossTitle() << endl;
		}
		else if (choice == 8) {
			done = true;
		}
		else {
			cout << "Invalid option, try again" << endl;
		}
		cout << endl;
	} while (!done);
	cout << endl << "Good Bye!" << endl;
	return 0;
}