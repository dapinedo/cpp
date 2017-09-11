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
    string firstname;
    string lastname;
    char empcode;
    string empcodeName;
    int ID;
    short classif;
    int years;
    short educode;
    double grossSalary;
    bool badline;
    
    // Constructors
    
    // Default and explicit constructor
    Employee(const string & last = "Not Set", const string & first = "Not Set", 
    	char employeecode = 'X', int identification = 0, short classification = 0, 
    	int yrs = 51, short educationalcode = 0) 
	{
		lastname = last;
		firstname = first;
		empcode = employeecode;
		ID = identification;
		classif = classification;
		years = yrs;
		educode = educationalcode;
		grossSalary = 0.0;
		empcodeName = "";
		badline = false;
	} 
	
	// Explicit constructor
	Employee (int identification) {
		ID = identification;
	}
	
	//Accessors
	string getLastname() const{
		return lastname;
	}
	char getEmpcode() const{
		return empcode;
	}
	string getEmpcodeName() const{
		return empcodeName;
	}
	int getID() const{
		return ID;
	}
	short getClassif() const{
		return classif;
	}
    int getYears() const{
    	return years;
    }
    short getEducode() const{
    	return educode;
    }
    double getGrossSalary() const{
    	return grossSalary;
    }
    bool getBadline() const{
    	return badline;
    }
	
	//Mutators
	void setGrossSalary(double totalsalary) {
		grossSalary = totalsalary;
	}
	void setEmpcodeName(const string & str) {
		empcodeName = str;
	}
	void setBadline(bool flag) {
		badline = flag;
	}
	
	void setLastname(const string & str) {
		lastname = str;
	}
	
	//Print functions
	void Print() const {
		cout << fixed << showpoint << setprecision(2);
		if (!badline) {
			cout << setw(10) << firstname << setw(1) << ' ' << setw(15) << lastname 
				<< setw(15) << ID << setw(25) << empcodeName << setw(15) 
				<< grossSalary << '\n';
		}
		else {
			cout << setw(10) << firstname << setw(1) << ' ' << setw(15) << lastname 
				<< setw(15) << ID << setw(40) << "BAD INPUT - UNABLE TO CALCULATE" << '\n';
		}
	}
	void Print(ofstream & out) const {
		out << fixed << showpoint << setprecision(2);
		if (!badline) {
			out << setw(10) << firstname << setw(1) << ' ' << setw(15) << lastname 
				<< setw(15) << ID << setw(25) << empcodeName << setw(15) 
				<< grossSalary << '\n';
		}
		else {
			out << setw(10) << firstname << setw(1) << ' ' << setw(15) << lastname 
				<< setw(15) << ID << setw(40) << "BAD INPUT - UNABLE TO CALCULATE" << '\n';
		}
	}
};

// FUNCTION PROTOTYPES

// open file path and read file contacts to array of struct Employee
int inputFileToStruct(Employee data [], const string & InputFilename);
//output and sort struct members to cout and ofstream
void structToOutput(Employee data [], const string & OutputFilename, int recordcount);
/*
Flag = 1 means sort based on ID
flag = 2 means sort based on last name
flag = 3 means sort based on Gross Salary
*/
void bubbleSort (Employee data[], int recordcount, short flag);
/* 
Flag = 1 means sort and search based on ID
Flag = 2 means sort and search based on last name
*/
int linearSearch (Employee data[], Employee searchterm, int recordcount, short flag);

//MAIN
int main()
{
	// declare array of struct Employee with a size = const MAX
	Employee dataset [MAX];
	
	// Greeting & User Input
	cout << fixed << showpoint << setprecision(2)
		<< "Welcome!!! Please follow the prompts below \n";
	string InputFilename = "";
	cout << "Enter full path to input file: ";
	getline(cin, InputFilename);
	cin.sync();
	string OutputFilename = "";
	cout << "Enter full path to output file: ";
	getline(cin, OutputFilename);
	cin.sync();
	
	// open file path and read file contacts to array of struct Employee
	int recordcount = inputFileToStruct(dataset, InputFilename);
	// open file path and write file with sorted list completed.
	// includes search menu
    structToOutput(dataset, OutputFilename, recordcount);
    
    cout << "Goodbye!!" << '\n';
	
	return 0;
}

int inputFileToStruct(Employee data [], const string & InputFilename)
{
	ifstream in(InputFilename); //open input file
	// Verify that file was read successfully with conditional statement
	// else send output "Failed to open file"
	if (in.is_open()) {
		cout << "File opened successfully" << '\n';
		int counter = 0;
		while ((in.peek() != EOF) && (counter < (MAX + 1))) {
			string first, last, fullname;
			in >> first;
			in >> last;
			char employeecode;
			in >> employeecode;
			int identification;
			in >> identification;
			short classification;
			in >> classification;
			int yrs;
			in >> yrs;
			short educationalcode;
			in >> educationalcode;
				
			/* 
			if counter < MAX then 
			 - set current struct record defaults based on file input
			 - check for bad input and set boolean flag value
				- if input is good, calculate and set struct value for grossSalary
			*/
			
			if (counter < MAX) {
				data[counter] = Employee(last, first, employeecode, identification, 
					classification, yrs, educationalcode);
				
				/* unit function test - comment out if test passes
				cout << "Iteration #" << counter << " of " << MAX-1 << endl;
				cout << data[counter].getName() << endl;
				cout << data[counter].getEmpcode() << " ";
				cout << data[counter].getID() << " ";
				cout << data[counter].getClassif() << " ";
				cout << data[counter].getYears() << " ";
				cout << data[counter].getEducode() << endl;
				cin.get();
				*/
				
				/* 
				below conditions set array member of struct 
				variables for badline, grossSalary and empcodeName
				*/ 
				bool badline = false;
				
				// Employee.setEmpcodeName(string & str)
				// grossSalary part - basesalary
				double basesalary = 0.00;
				switch (employeecode) {
					case 'S': {
						data[counter].setEmpcodeName("Factory Worker");
						basesalary = 800.00;
						break;
					}
					case 'O': {
						data[counter].setEmpcodeName("Office Worker");
						basesalary = 1000.00;
						break;
					}
					case 'M': {
						data[counter].setEmpcodeName("Management");
						basesalary = 1500.00;
						break;
					}
					default: {
						data[counter].setEmpcodeName("Invalid Code");
						basesalary = 0.0;
						badline = true;
						data[counter].setBadline(badline);
					}
				} // end switch	
				
				// grossSalary part - classifadj
				double classifadj = 0.00;
				if (!badline) {
					switch (classification) {
						case 1: {
							classifadj = (.05 * basesalary);
							break;
						}
						case 2: {
							classifadj = (.10 * basesalary);
							break;
						}
						case 3: {
							classifadj = (.20 * basesalary);
							break;
						}
						default: {
							classifadj = 0.0;
							badline = true;
							data[counter].setBadline(badline);
							break;
						}
					} // end switch
				} // end if
				
				// grossSalary part - eduadj
				double eduadj = 0.0;
				if (!badline) {
					switch (educationalcode) {
						case 1: {
							eduadj = 0.0;
							break;
						}
						case 2: {
							eduadj = (.05 * basesalary);
							break;
						}
						case 3: {
							eduadj = (.12 * basesalary);
							break;
						}
						case 4: {
							eduadj = (.20 * basesalary);
							break;
						}
						default: {
							eduadj = 0.0;
							badline = true;
							data[counter].setBadline(badline);
							break;
						}
					} // end switch
				} // end if
				
				// grossSalary part - seniorityadj
				double seniorityadj = 0.0;
				if (!badline) {
					if ((yrs >= 0) && (yrs <= 10)) {
						seniorityadj = (.05 * basesalary);
					}
					else if ((yrs > 10) && (yrs <= 50)) {
						seniorityadj = (.05 * basesalary) + (.01 * (yrs - 10) * basesalary);
					}
					else {
						seniorityadj = 0.0;
						badline = true;
						data[counter].setBadline(badline);
					} // end if
				} // end if
				
				// Calculate total for grossSalary
				if (!badline) {
					double totalsalary = basesalary + classifadj + eduadj + seniorityadj;
					data[counter].setGrossSalary(totalsalary);
				}
				counter++;
			}
			else {
				cout << "Input file exceeds 30 records. Successive records are truncated" << endl;
				break;
			}
		} // end while loop
		in.close();
		if (counter == 0) {
			cout << "Your input file is empty, process aborted" << '\n';
			in.close();
			exit(0);
		}
		return (counter);
	} // end if statement
	else {
		cout << "Failed to open input file. " << '\n';
		exit(0);
	}
}

void structToOutput(Employee data [], const string & OutputFilename, int recordcount) {
	
	cout << "total records: " << recordcount << endl;
	cout << fixed << showpoint << setprecision(2);
	cout << setw(26) << "Name" << setw(15) << "ID#"
		<< setw(25) << "Job Type" << setw(15) << "Gross Salary" << '\n';
		
	for (int i = 0; i < recordcount; i++) {
		data[i].Print();
	}
	
	ofstream out(OutputFilename); //open output file
	// Verify that file was read successfully with conditional statement
	// else send output "Failed to open file"
	
	if (out.is_open()) {
		cout << "Sorted output for 1. ID number, 2. Last name, and 3. Gross Salary" << '\n';
		
		out << fixed << showpoint << setprecision(2);
		out << "-----UNSORTED-----" << '\n';
		out << setw(20) << "Name" << setw(15) << "ID#"
			<< setw(25) << "Job Type" << setw(15) << "Gross Salary" << '\n';
		for (int i = 0; i < recordcount; i++) {
			data[i].Print(out);
		}
		
		out << fixed << showpoint << setprecision(2);
		out << '\n' << "-----SORTED BY ID-----" << '\n';
		out << setw(20) << "Name" << setw(15) << "ID#"
			<< setw(25) << "Job Type" << setw(15) << "Gross Salary" << '\n';
		bubbleSort(data, recordcount, 1);
		for (int i = 0; i < recordcount; i++) {
			data[i].Print(out);
		}
		
		out << '\n' << "-----SORTED BY LAST NAME-----" << '\n';
		out << setw(20) << "Name" << setw(15) << "ID#"
			<< setw(25) << "Job Type" << setw(15) << "Gross Salary" << '\n';
		bubbleSort(data, recordcount, 2);
		for (int i = 0; i < recordcount; i++) {
			data[i].Print(out);
		}
		
		out << '\n' << "-----SORTED BY GROSS SALARY-----" << '\n';
		out << setw(20) << "Name" << setw(15) << "ID#"
			<< setw(25) << "Job Type" << setw(15) << "Gross Salary" << '\n';
		bubbleSort(data, recordcount, 3);
		for (int i = 0; i < recordcount; i++) {
			data[i].Print(out);
		}
		
		cout << "output file \"" << OutputFilename << "\" created successfully!!" << '\n';
		out.close();
	}
	else {
		cout << "failed to create output file. Aborting process" << '\n';
		exit(0);
	}
	
	bool done = false;
	while (!done) {
		short choice = 3;
		cout << "----- SEARCH MENU -----" << '\n';
		cout << " 1. Search by ID" << '\n';
		cout << " 2. Search by Last Name" << '\n';
		cout << " 3. Exit [Default]" << '\n';
		cout << "CHOOSE: ";
		cin.sync();
		cin >> choice;
		int found;
		switch (choice) {
			case 1 : {
				cout << "Enter your search term for ID: ";
				int term;
				cin >> term;
				Employee searchterm = Employee(term);
				found = linearSearch(data, searchterm, recordcount, 1);
				if (found < 0) {
					cout << "Sorry, search term not found" << '\n';
				}
				else {
					cout << "Search term found at index number " << found << '\n';
					data[found].Print();
				}
				break;
			}
			case 2 : {
				cout << "Enter your search term for Last name [case sensitive]: ";
				string term;
				cin.sync();
				cin >> term;
				Employee searchterm;
				searchterm.setLastname(term);
				found = linearSearch (data, searchterm, recordcount, 2);
				if (found < 0) {
					cout << "Sorry, search term not found" << '\n';
				}
				else {
					cout << "Search term found at index number " << found << '\n';
					data[found].Print();
				}
				break;
			}
			case 3 : {
				done = true;
				break;
			}
		}
	}
}

/*
flag = 1 means sort based on ID
flag = 2 means sort based on Last Name
flag = 3 means sort based on Gross Salary
*/
void bubbleSort (Employee data[], int recordcount, short flag) {
	for (size_t i = 0; i< recordcount; i++) {
			for (size_t j = 0; j< recordcount - 1 - i; j++) {
				if(flag == 1) { // sort on ID
					if(data[j].getID() > data[j+1].getID()) {
						// Swap whole struct members in the array
						Employee Temp;
						Temp = data[j];
						data[j] = data[j+1];
						data[j+1] = Temp;
					}
				}
				else if(flag == 2) { // sort on last name
					if(data[j].getLastname() > data[j+1].getLastname()) {
						// Swap whole struct members in the array
						Employee Temp;
						Temp = data[j];
						data[j] = data[j+1];
						data[j+1] = Temp;
					}
				}
				else if(flag == 3) { // sort on Gross Salary
					if(data[j].getGrossSalary() > data[j+1].getGrossSalary()) {
						// Swap whole struct members in the array
						Employee Temp;
						Temp = data[j];
						data[j] = data[j+1];
						data[j+1] = Temp;
					//complete yourself
					}
				}
			}// Inner for loop
	}// outer for loop
}

/* 
Flag = 1 means sort and search based on ID
Flag = 2 means sort and search based on last name
*/
int linearSearch (Employee data[], Employee searchterm, int recordcount, short flag) {
	bubbleSort (data, recordcount, flag);
	for (int i = 0; i < recordcount; i++) {
		if (flag == 1) {
			if (data[i].getID() == searchterm.getID()) {
				return i;
			}
		}
		else if (flag == 2) {
			if (data[i].getLastname() == searchterm.getLastname()) {
				return i;
			}
		}
	}
	return -1;
}
