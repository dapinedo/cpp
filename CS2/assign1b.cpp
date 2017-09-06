// Daniel Pinedo
// Assignment 1b
// due: September 11, 2017
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// GLOBAL CONSTANTS
const int MAX = 30;

// STRUCTS - no memory allocation
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
		ID = identification;
		classif = classification;
		years = yrs;
		educode = educationalcode;
	} 
};

// FUNCTION PROTOTYPES

// open file path and read file contacts to array of struct Employee
void inputFileToStruct(Employee data [], const string & InputFilename);
void structToOutput();

//MAIN
int main()
{
	// declare array of struct Employee with a size = const MAX
	Employee dataset [MAX];
	
	// Greeting & User Input
	cout << fixed << showpoint << setprecision(2)
		<< "Welcome!!! Please follow the prompts below \n";
	string InputFilename;
	cout << "Enter full path to input file: ";
	getline(cin, InputFilename);
	cin.sync();
	
	// open file path and read file contacts to array of struct Employee
	inputFileToStruct(dataset, InputFilename);
    structToOutput();

    /* TODO
    - below conditional statements will go into function structToOutput();
    - add const member functions as needed to struct to access struct members
    */
    
	string codename = "";
	boolean badinput = false;
	double basesalary = 0.00;
	
	switch (employeecode)
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
	default:
		{
		codename = "Invalid Code";
		basesalary = 0.0;
		badinput = true;
		}
	}
	
	double classifadj = 0.00;
	switch (classification)
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
	default:
		{
		classifadj = 0.0;
		badinput = true;
		break;
		}
	}

	double eduadj = 0.0;
	switch (educationalcode)
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
	default:
		{
		eduadj = 0.0;
		badinput = true;
		break;
		}
	}

	double seniorityadj = 0.0;
	if (yrs >= 0 && yrs <= 10)
	{
		seniorityadj = (.05 * basesalary);
	}
	else if (yrs > 10 && yrs < 50)
	{
		seniorityadj = (.01 * (years - 10) * basesalary);
	}
	else
	{
		seniorityadj = 0.0;
		badinput = true;
	}

	double totalsalary = basesalary + classifadj + eduadj + seniorityadj;
	
	/* TODO
	- if badinput = true output that "This line contained bad input(s), unable to calculate salary"
	*/
	
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

void inputFileToStruct(Employee data [], const string & InputFilename)
{
	ifstream in(InputFilename); //open input file

	// Verify that file was read successfully with conditional statement
	// else send output "Failed to open file with name: " << InputFilename << ". Goodbye"
	if (in.is_open()) {
		// fill array of struct employee
		Employee dataset [MAX];
		inputFileToStruct(dataset, InputFilename);
		size_t counter = 0;
		while ((in.peek() != EOF) && (counter < (MAX + 1))) {
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
			if (counter < MAX) {
				dataset[counter] = Employee(fullname, employeecode, identification, 
					classification, yrs, educationalcode);
				counter++;
			}
			else {
				cout << "Input file exceeds 30 records. Successive records are truncated";
			}
		} // end while loop
	} // end if statement
	else {
		cout << "Failed to open input file. " << '\n';
		exit(0);
	}
	if (counter == 0) {
		cout << "Your input file is empty, process aborted" << '\n';
		exit(0);
	}
	in.close(); // close input file
}
