/*
Satish Singhal
Class: CS1
Date:3/28/2017
Program Name:ReadingWritingToFiles
*/
#include <iostream>// Works with keyboard and console
#include <string>
#include <iomanip>
#include <fstream> // needed to work with files
using namespace std;


int main()
{
	//Goal : Read from an input file and print the file to console
	//1. Ask and store full path to input file

	string inFileName;
	cout << "Enter full path to input file: ";
	getline(cin, inFileName);
	//2. Bind file name with the ifstream object - Opening a connection to file
	ifstream in(inFileName);
	//3. Verify that connection was successful
	//Do a conditional test
	if (in.is_open())
	{
		// How to write to data sources - in this case file
		//1Output. Get full path to output file
		string outFileName;
		cout << "Enter full path to output file: ";
		getline(cin, outFileName); // Output file if it does not exist will be created if there is a permission is there to create it
		//2Output: Bind file name to the ofstream object - DATA SOURCE IS OPEN FOR WRITING
		ofstream out(outFileName);
		//3Output: Validate that file opened successfully for writing
		if (out.is_open())
		{
			int numStudents = 0; // Would count number of students in the file
			while (in.peek() != EOF)
			{
				numStudents++;
				//Read first and last name
				string first; // to read first name token
				string last;// to read last name token
				in >> first;
				in >> last;
				int sum = 0;
				int numTests = 0;
				int score;
				in >> score;//prime read

				while (score >= 0)
				{
					sum += score;
					numTests++;
					//loop update done by update read
					in >> score;
				}

				cout << "Hello " << first << ' ' << last << endl;
				out << "Hello " << first << ' ' << last << endl;

				if (numTests > 0)// can find an average
				{
					cout << fixed << showpoint << setprecision(2);
					out << fixed << showpoint << setprecision(2);
					double realAve = static_cast<double>(sum) / numTests;
					cout << "Sum of all your tests: " << sum << endl;
					cout << "Number of tests taken: " << numTests << endl;
					cout << "The real average of your tests : "
						<< realAve << endl;

					out << "Sum of all your tests: " << sum << endl;
					out << "Number of tests taken: " << numTests << endl;
					out << "The real average of your tests : "
						<< realAve << endl;
					int roundedAve = static_cast<int>(realAve + 0.5);
					//Assign letter grade based on rounded average

					char grade;

					if (roundedAve >= 90)
					{
						grade = 'A';
					}
					else if (roundedAve >= 80)
					{
						grade = 'B';
					}
					else if (roundedAve >= 70)
					{
						grade = 'C';
					}
					else if (roundedAve >= 60)
					{
						grade = 'D';
					}
					else
					{
						grade = 'F';
					}

					cout << "Your semester total rounded percentage: "
						<< roundedAve << endl;
					cout << "Your grade: " << grade << endl;
					cout << "----------------------------------------" << endl;
					out << "Your semester total rounded percentage: "
						<< roundedAve << endl;
					out << "Your grade: " << grade << endl;
					out << "----------------------------------------" << endl;

				}
				else
				{
					cout << "You did not take any tests." << endl;
					cout << "----------------------------------------" << endl;

					out << "You did not take any tests." << endl;
					out << "----------------------------------------" << endl;

				}
				cout << "Number of students in the file: " << numStudents << endl;
				out << "Number of students in the file: " << numStudents << endl;
			}// end of EOF loop
		}// if for opening output filr
		else
		{
			cout << "Failed to open/create output file." << endl;
		}
		//4Output: Close the output file
		out.close();
	}
	else
	{
		cout << "Failed to open file with name: " << inFileName << endl;
	}
	//4. Close the connection to the data source
	in.close();// Call close function
	return 0;
}