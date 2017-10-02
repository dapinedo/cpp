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
		//Can read the file and do data processing
		string Line;
		getline(in, Line);
		cout << Line << endl;
		// What if I wanted to make the copy of one line and write to 
		//another file
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
			out << Line << endl;
		}
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