/*
Satish Singhal
Class: CS1
Date:6/1/2017
Program Name:LightBulbStruct
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct LightBulb
{
	string Manufacturer;
	int lumens;// amount of light coming from bulb
	double price;
	// Write default constructor that 
	//A. sets manufacturer to "Not set"
	//B. sets lumens to 0
	// sets price to 0.0
	LightBulb()
	{
		Manufacturer = "Not set";
		lumens = 0;
		price = 0.0;
	}
	// Explicit constructor
	LightBulb(string manNm/*manufacturer name */,
		double pr/*price*/, int lmn/* lumens*/)
	{
		Manufacturer = manNm;
		price = pr;
		lumens = lmn;
	}
	string getManufacturerName()
	{
		return Manufacturer;
	}
	double getPrice()
	{
		return price;
	}
	int getLumens()
	{
		int lumens;
	}

	void setManufacturerName(string nm)
	{
		Manufacturer = nm;
	}
	void setPrice(double pr) // includes validation for price
	{
		if (pr <= 0.0)
		{
			cout << "Invalid Price. Must be greater than zero." << endl;
		}
		else 
		{
			price = pr;
		}
	}
	void setLumens(int lmn)
	{
		lumens = lmn;
	}

	void print()
	{
		cout << fixed << showpoint << setprecision(2)
			<< "Manufacturer: " << Manufacturer << endl
			<< "Brightness (in lumens): " << lumens << endl
			<< "Price: $" << price << endl;
	}

	void print(ofstream & out)
	{
		out << fixed << showpoint << setprecision(2)
			<< "Manufacturer: " << Manufacturer << endl
			<< "Brightness (in lumens): " << lumens << endl
			<< "Price: $" << price << endl;
	}
};

int main()
{
	bool done = false;
	LightBulb LB; // ** Important declaration, don't forget **
	cout << fixed << showpoint << setprecision(2);
	while (!done)
	{
		cout << "1. Create Light Bulb object from keyboard data entry." << endl
			<< "2. Print Light bulb to console." << endl
			<< "3. Print Light bulb to output file." << endl
			<< "4. Change price." << endl
			<< "5. Change lumens." << endl
			<< "6. Print price only to console." << endl
			<< "7. Print manufacturers name only to console." << endl
			<< "8. print lumens only to console." << endl
			<< "9. exit." << endl;
		
		int choice;
		cin >> choice;
		switch (choice)
		{
			case 1:
			{
				string inName;
				int inLmns;
				double inPrice;
				cout << "Enter manufacturer name: ";
				cin >> inName;
				cout << "Enter brightnes in lumens: ";
				cin >> inLmns;
				cout << "Enter price: ";
				cin >> inPrice;
				LB = Lightbulb(inName, inPrice, inLmns);
				break;
			}
			case 2:
			{
				LB.print();
				break;
			}
			case 3:
			{
				cout << "Enter full path to filename: ";
				string outputFile;
				cin.ignore(256, '\n'); // need to clear prior buffer before using getline
				getline(cin, outputFile);
				ofstream out(outputFile);
				if (out.is_open())
				{
					LB.print(out);
				}
				else
				{
					cout << "That file could not be created or written."
				}
				out.close();
				break;
			}
			case 4:
			{
				cout << "Enter new price: ";
				double newPrice;
				cin >> newPrice;
				LB.setPrice(newPrice);
				break;
			}
			case 5:
			{
				cout << "Enter Brightness (in lumens): ";
				double newLumens;
				cin >> newLumens;
				LB.setLumens(newLumens);
				break;
			}
			case 6:
			{
				cout << "Price: $" << LB.getPrice() << endl;
				break;
			}
			case 7:
			{
				cout << "Manufacturer: " << LB.getManufacturerName() << endl;
				break;
			}
			case 8:
			{
				cout << "Brightness (in lumens): " << LB.getLumens() << endl;
				break;
			}
			case 9:
			{
				done = true;
				break;
			}
			default:
			{
				cout << "Invalid Entry"
			}
		}
	}

	return 0;
}