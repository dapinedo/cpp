/*
Satish Singhal
Class: CS1
Date: 5/23/2017
Program Name: Bubble Sort
*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void bubbleSort(string Friends[], int len);
bool LinearSearch(const string Friends[], int len, 
	const string & key, int & foundAt);

int main()
{
	string names[5] = { "zack", "adam", "peter", "bertha", "ariel" };
	cout << "Printing the unsorted array of names." << endl;
	cout << "-----------------------------------------" << endl;
	for (size_t i = 0; i < 5; i++)
	{
		cout<<names[i] << "   ";
	}
	cout << endl;

	bubbleSort(names, 5);
	cout << "Printing the sorted array of names." << endl;
	cout << "-----------------------------------------" << endl;
	for (size_t i = 0; i < 5; i++)
	{
		cout << names[i] << "   ";
	}
	cout << endl;

	string names2[5] = { "zack", "adam", "peter", "bertha", "ariel" };

	bool done = false;

	while (!done)
	{
		cout << "Enter the first name to be searched: ";
		string key;
		cin >> key;
		int index;
		bool found = LinearSearch(names2, 5, key, index);

		if (found)
		{
			cout << "Name " << key << " was found at index: "
				<< index << endl;
		}
		else
		{
			cout << "Name " << key << " was not found: " << endl;
		}
		cout << "More searches? Enter 0 to continue or 1 to stop:";
		cin >> done;
	}
	return 0;
}
/*
Friends - unsorted array to be searched
len - length that needs searched
key - name to be searched
foundAt - index in the array where name is found
if not found then foundAt is set to -1.
-1 is impossible legal array index, also indicating
that key was not found
function returns true if key is found, else returns false
*/
bool LinearSearch(const string Friends[], int len, 
	const string & key, int & foundAt)
{
	bool found = false;
	foundAt = -1;
	for (int i = 0; !found && i < len; i++)
	{
		if (key == Friends[i])
		{
			found = true;
			foundAt = i;
		}
	}

	return found;
}
void bubbleSort(string Friends[], int len)
{
	for (size_t i = 0; i < len; i++)
	{
		for (size_t j = 0; j < len - i -1; j++)
		{
			if (Friends[j] > Friends[j+1])
			{
				string temp = Friends[j];
				Friends[j] = Friends[j + 1];
				Friends[j + 1] = temp;
			}
		}
	}
}

/*
Printing the unsorted array of names.
-----------------------------------------
zack   adam   peter   bertha   ariel
Printing the sorted array of names.
-----------------------------------------
adam   ariel   bertha   peter   zack
Enter the first name to be searched: tom
Name tom was not found:
More searches? Enter 0 to continue or 1 to stop:0
Enter the first name to be searched: ariel
Name ariel was found at index: 4

*/