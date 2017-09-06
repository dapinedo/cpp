// Daniel Pinedo
// Assignment 1b
// due: September 6, 2017
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// constants below
const int MAX = 30;

// structs below - no memory allocation
struct Employee {
    string name;
    char empcode;
    int ID;
    short classif;
    int years;
    short educode;
    
  Employee(string fullname = "Not Set", char employeecode = 'X', 
	int identification = 0, short classification = 0, int yrs = 51,
	short educationalcode = 0) 
	{
		name = fullname;
		empcode = employeecode;
		
	} 
};


int main()
{
	Employee dataset [MAX];
	cout << fixed << showpoint << setprecision(2)
		<< "Welcome!!! Please follow the prompts below \n";
		
	// Read input file path and open file
	string InputFilename;
	cout << "Enter full path to input file: ";
	getline(cin, InputFilename);
	cin.sync();
	ifstream in(InputFilename); //open input file

	// Verify that file was read successfully with conditional statement
	// else send output "Failed to open file with name: " << InputFilename << ". Goodbye"
	if (in.is_open()) {
		size_t counter = 0;
		while (in.peek() != EOF) {
			string fullname = "Not Provided";
			getline(in, fullname);
			char employeecode = 'Z';
			in >> employeecode;
			int identification = 0;
			in >> identification;
			int classification = 0;
			in >> classification;
			int yrs = 51;
			in >> yrs;
			int educationalcode = 0;
			in >> educationalcode;
			dataset[counter] = Employee(fullname, employeecode, identification, 
				classification, yrs, educationalcode);
			counter++;
		} // end while loop
	} // end if statement
	else {
		cout << "Failed to open input file. " << endl;
		exit(0);
	}
	
	/* TODO
	- if counter == 0, specify that input file is empty
	*/
	
	in.close(); // close input file

	string codename = "";
	double basesalary = 0.00;
	
	switch (code)
	{
	case 'S':
		{
		codename = "Factory Worker";
		basesalary = 800.00;
		break;
		}
	case 'O':
		{
		codename = "Office Worker";
		basesalary = 1000.00;
		break;
		}
	case 'M':
		{
		codename = "Management";
		basesalary = 1500.00;
		break;
		}
	}

	double classifadj = 0.00;
	
	switch (classif)
	{
	case 1:
		{
		classifadj = (.05 * basesalary);
		break;
		}
	case 2:
		{
		classifadj = (.10 * basesalary);
		break;
		}
	case 3:
		{
		classifadj = (.20 * basesalary);
		break;
		}
	}

	double eduadj = 0.0;
	switch (edu)
	{
	case 2:
		{
		eduadj = (.05 * basesalary);
		break;
		}
	case 3:
		{
		eduadj = (.12 * basesalary);
		break;
		}
	case 4:
		{
		eduadj = (.20 * basesalary);
		break;
		}
	}

	double seniorityadj = 0.0;
	if (years >= 0 && years <= 10)
	{
		seniorityadj = (.05 * basesalary);
	}
	else if (years > 10 && years < 50)
	{
		seniorityadj = (.01 * (years - 10) * basesalary);
	}
	else
	{
		cout << "Invalid entry for years of service" << "\n";
	}

	double totalsalary = basesalary + classifadj + eduadj + seniorityadj;
	
	cout << "Base Salary: " << basesalary << '\n';
	cout << "Classification Adjustment: +" << classifadj << '\n';
	cout << "Educational Adjustment: +" << eduadj << '\n';
	cout << "Seniority Adjustment: +" << seniorityadj << '\n';


	cout << setw(20) << "Name" << setw(15) << "ID#"
		<< setw(25) << "Job Type" << setw(15) << "Gross Salary" << '\n';

	cout << setw(20) << name << setw(15) << id
		<< setw(25) << codename << setw(15) << totalsalary << '\n';
	
	return 0;
}

