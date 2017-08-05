/*
Daniel Pinedo
CS1
Assignment #5
4/6/17
CarbonPenalty.cpp
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	const int ASTERISK_NUM = 60;
	// Read input file path and open file
	string InputFilename;
	cout << "Enter full path to input file: ";
	getline(cin, InputFilename);
	ifstream in(InputFilename);

	// Verify that file was read successfully with conditional statement
	// else send output "Failed to open file with name: " << InputFilename << ". Goodbye"
	if (in.is_open()) /*&& (!EOF)) */
	{
		//Read output file path and open file
		string OutputFilename;
		cout << "Enter full path to output file";
		getline(cin, OutputFilename); // open file or create new file with name
		ofstream out(OutputFilename);

		// Verify that file was read successfully with conditional statement
		// else send output "Output file could not be read/created. Goodbye"
		if (out.is_open())
		{
			size_t CityNumber = 0; // Counts number of cities in file
			double TotalFine = 0; // Sums all dollar value carbon fines
			
			// Begin Analysis / Nested Conditions for parsing multiple lines in file
			
			//Begin Printing Template of Output to screen and output file
			cout << left << fixed << showpoint << setprecision(2);
			out << fixed << showpoint << setprecision(2);
			cout << "Begin output of analysis below" << endl;
			out << "Begin output of analysis below" << endl;
			cout << string(ASTERISK_NUM, '*') << endl;
			out << string(ASTERISK_NUM, '*') << endl;
			cout << setw(20) << "City" << setw(30) << "Rounded Average Carbon FP" << setw(10) << "Fine <$>" << endl;
			out << setw(20) << "City" << setw(30) << "Rounded Average Carbon FP" << setw(10) << "Fine <$>" << endl;
			cout << string(ASTERISK_NUM, '*') << endl;
			out << string(ASTERISK_NUM, '*') << endl;

			while (in.peek() != EOF)
			{
				CityNumber++;
				string CityName;
				in >> CityName;
				int sum = 0; // counting values for one city
				int records = 0; // counting total number of values for one city
				int level; // prime read: file input value
				in >> level;
				
				//Sentinel Loop after Prime Read
				while (level >= 0)
				{
					sum += level;
					records++;
					in >> level;
				}

				//Conditional Statement for printing analysis to screen and file
				//Else print "There is no data available for this city, so fine cannot be computed"
				if (records > 0)
				{
					double RealCarbonValue = static_cast<double>(sum) / records;
					int RoundedCarbonValue = static_cast<int>(RealCarbonValue + 0.5);
					double CityFine;
					//Conditional Statement for assigning fines based on carbon values
					//Adding sum to TotalFine counter for EOF loop
					if (RoundedCarbonValue <= 1)
					{
						CityFine = 0.00;
					}
					else if (RoundedCarbonValue <= 3)
					{
						CityFine = 1000000.00;
					}
					else if (RoundedCarbonValue <= 5)
					{
						CityFine = 2000000.00;
					}
					else if (RoundedCarbonValue <= 7)
					{
						CityFine = 3000000.00;
					}
					else
					{
						CityFine = 4500000.00;
					}
					TotalFine += CityFine;
					cout << setw(20) << CityName << setw(30) << RoundedCarbonValue << setw(10) << CityFine << endl;
					out << setw(20) << CityName << setw(30) << RoundedCarbonValue << setw(10) << CityFine << endl;
				}
				else
				{
					cout << setw(20) << CityName << "No value available for this city" << endl;
					cout << setw(20) << CityName << "No value available for this city" << endl;
				}
			} // end EOF while
			cout << string(ASTERISK_NUM, '*') << endl;
			out << string(ASTERISK_NUM, '*') << endl;
			cout << "Total Number of cities in the file: " << CityNumber << endl;
			out << "Total Number of cities in the file: " << CityNumber << endl;
			cout << "Total fine collected: " << TotalFine << endl;
			out << "Total fine collected: " << TotalFine << endl;
			cout << "Thank you for using my awesome Carbon Fine program. Goodbye!!";
			out << "Thank you for using my awesome Carbon Fine program. Goodbye!!";
		} // end output file conditional
		else
		{
			cout << "Output file could not be read/created. Goodbye";
		}
		out.close(); // Close output file
	} // end input file conditional
	else if (EOF)
		{
			cout << "Your input file is empty. Please try again.";
		}
	else
	{
		cout << "Failed to open file with name: " << InputFilename << ". Goodbye";
	}
	in.close(); // Close input file
	return 0;
}
