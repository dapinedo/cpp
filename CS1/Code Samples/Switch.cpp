#include <iostream>
using namespace std;


int main()
{
	//Give message according to the grade
	for (size_t i = 0; i < 10; i++)
	{
		char grade;
		cout << "Please enter your letter grade[A, B, C, D, F]: ";
		cin >> grade;
		grade = toupper(grade);

		switch (grade)
		{
		case 'A':
			//give message
			cout << "Awesome job" << endl;
			break;
		case 'B':
			//give message
			cout << "Great job" << endl;
			break;
		case 'C':
			//give message
			cout << "Reasonable job" << endl;
			break;
		case 'D':
			//give message
			cout << "Improve and grow" << endl;
			break;
		case 'F':
			//give message
			cout << "Try again" << endl;
			break;
			default:
				cout << " There is no message because grade (A to F) was not entered." << endl;
				break;
		}// end of switch
		////
	}//for loop
}
/*
Please enter your letter grade[A, B, C, D, F]: A
Awesome job
Please enter your letter grade[A, B, C, D, F]: B
Great job
Please enter your letter grade[A, B, C, D, F]: C
Reasonable job
Please enter your letter grade[A, B, C, D, F]: D
Improve and grow
Please enter your letter grade[A, B, C, D, F]: F
Try again
Please enter your letter grade[A, B, C, D, F]: D
Improve and grow
Please enter your letter grade[A, B, C, D, F]:
*/