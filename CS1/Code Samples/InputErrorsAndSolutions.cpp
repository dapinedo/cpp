/*
Satish Singhal
Class: CS1
Date:3/2/2017
Program Name: Input Mismatch
*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main/* Solution to getline gotcha*/()
{
	//use of getline right after cin>> may not allow successful getline input
	int ageOnLastBirthday;
	cout << "Enter your age on last birthday [whole positive number]: ";
	cin >> ageOnLastBirthday;
	cout << "Your inputted: " << ageOnLastBirthday << endl;
	// Clear the buffer because next input is getline
	//use cin. ignore
	cin.ignore(1000, '\n');
	string wholeLine;
	cout << "Enter your complete street address: ";
	getline(cin, wholeLine);
	cout << "You Inputted: " << wholeLine << endl;

	return 0;
	/*
	cin.ignore() cleans the buffer for getline
	Enter your age on last birthday [whole positive number]: 55
	Your inputted: 55
	Enter your complete street address: 1900 Pico Blvd, Santa Monica, CA 90405
	You Inputted: 1900 Pico Blvd, Santa Monica, CA 90405
	*/
}
int main5/* getline gotcha*/()
{
	//use of getline right after cin>> may not allow successful getline input
	int ageOnLastBirthday;
	cout << "Enter your age on last birthday [whole positive number]: ";
	cin >> ageOnLastBirthday;
	cout << "Your inputted: " << ageOnLastBirthday << endl;
	string wholeLine;
	cout << "Enter your complete street address: ";
	getline(cin, wholeLine);
	cout << "You Inputted: " << wholeLine << endl;

	return 0;
	/*
	//Enter key after input of 55 is still in buffer and getLine gets that
	// does not even stop for user to input address
	Enter your age on last birthday [whole positive number]: 55
Your inputted: 55
Enter your complete street address: You Inputted:
	*/
}
int main4/* what I wanted to input a space containing whole line?*/()
{
	string wholeLine;
	cout << "Enter your complete street address: ";
	//cin >> wholeLine;
	getline(cin, wholeLine);
	cout << "You Inputted: " << wholeLine << endl;

	return 0;
	/*
	output 1: When cin>> is used to get user input:
	Enter your complete street address: 19504 Pico Blvd. Santa Monica CA 90405
	You Inputted: 19504// Only firdt token is gotten.
	*/

	/*
	output 2
	getline was used instead of cin>>. Whole line of user input is stored

	Enter your complete street address:   1900 pico Blvd. Santa Monica CA. 90504, USA
	You Inputted:   1900 pico Blvd. Santa Monica CA. 90504, USA
	*/
}

int main3/* Nature of cin>>*/()
{
	double var1, var2, var3;
	cout << "Enter three decimal numbers (with mantissa) with space separation: ";
	cin >> var1;
	cin >> var2;
	cin >> var3;
	cout << "You entered: "
		<< var1 << "  " << var2 << "  " << var3 << endl;

	return 0;
	/*
	>> operator ignores leading whitespace and only grabs the token
	after the whitespace and stores in the variable on right side
	of operator >>.
	output example from above program is below:
	Enter three decimal numbers (with mantissa) with space separation:             1.55
                2.9



9.91
You entered: 1.55  2.9  9.91
	*/
}
int main2/* Other ways input can fail*/()
{
	int age;
	cout << "Enter your age on last birthday [whole positive number]: ";
	cin >> age;

	cout << "Your inputted: " << age << endl;
	double GPA;
	cout << "Input GPA: ";
	cin >> GPA;
	cout << "GPA: " << GPA << endl;
	return 0;
	/*
	Input failed when a string was entered while a number was expected
	Enter your age on last birthday [whole positive number]: two
	Your inputted: -858993460
	Input GPA: GPA: -9.25596e+061
	*/
}

int main1/*complete failure of input */()
{
	int ageOnLastBirthday;
	cout << "Enter your age on last birthday [whole positive number]: ";
	cin >> ageOnLastBirthday;

	cout << "Your inputted: " << ageOnLastBirthday << endl;

	double GPA;
	cout << "Enter current GPA: ";
	cin >> GPA;

	cout << "You inputted: " << GPA << endl;

	return 0;
}
/* Normal Behavior
Enter your age on last birthday [whole positive number]: 55
Your inputted: 55
Enter current GPA: 3.2
You inputted: 3.2*/
/*
Total Failure of Input
Enter your age on last birthday [whole positive number]: .1
Your inputted: -858993460
Enter current GPA: You inputted: -9.25596e+061
*/
/* 
Partial Failure of input
Enter your age on last birthday [whole positive number]: 50.5
Your inputted: 50
Enter current GPA: You inputted: 0.5
*/