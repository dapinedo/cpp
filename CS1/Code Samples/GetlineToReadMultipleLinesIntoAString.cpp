#include <iostream>
#include <string>
#include <fstream>
using namespace std;
const size_t MAX = 20;

int main()
{
	string FileName;
	cout << "Enter full path to file: ";
	getline(cin, FileName);
	ifstream in(FileName);
	//Always do validation
	if (!in.is_open())
	{
		cout << "Failed to open input file." << endl;
	}
	else
	{
		string Q[MAX];// All zero length strings stored in array Q
		int i = 0;

		while (i<MAX && in.peek() != EOF)
		{
			string temp;
			getline(in, temp, '$');
			Q[i] = temp;
			//cout << Q[i] << endl;
			i++;
		}
		cout << "Number of elements in the array." << i << endl;
		// after loop is over, i is the logical length of the array
		cout << "Printing the string array." << endl;
		
		for (size_t index = 0; index < i; index++)
		{
			cout << Q[index] << endl;
		}
	}//else block

	in.close();
	return 0;
}