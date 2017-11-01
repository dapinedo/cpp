#include "StackInterface.h"
#include "Stack.h"

void convertDecimalToHexUsingStack();
int main()
{
	bool done = false;

	while (!done)
	{
		convertDecimalToHexUsingStack();
		cout << "More conversions? Enter 0 to continue or 1 to stop: ";
		cin >> done;
	}
	system("pause");
	return 0;
	/*
	Output
	The hex form of 57005 is: DEAD
	More conversions? Enter 0 to continue or 1 to stop: 0
	Enter decimal number to convert to HEX: 48879
	The hex form of 48879 is: BEEF
	More conversions? Enter 0 to continue or 1 to stop: 0
	Enter decimal number to convert to HEX: 4078
	The hex form of 4078 is: FEE
	More conversions? Enter 0 to continue or 1 to stop: 0
	Enter decimal number to convert to HEX: 48813
	The hex form of 48813 is: BEAD
	More conversions? Enter 0 to continue or 1 to stop: 0
	Enter decimal number to convert to HEX: 9
	The hexadecimal of 9 is 9
	More conversions? Enter 0 to continue or 1 to stop: 0
	Enter decimal number to convert to HEX: 8
	The hexadecimal of 8 is 8
	More conversions? Enter 0 to continue or 1 to stop: 0
	Enter decimal number to convert to HEX: 88
	The hex form of 88 is: 58
	More conversions? Enter 0 to continue or 1 to stop: 0
	Enter decimal number to convert to HEX: 0
	The hexadecimal of 0 is 0
	More conversions? Enter 0 to continue or 1 to stop: 0
	Enter decimal number to convert to HEX: 123
	The hex form of 123 is: 7B
	More conversions? Enter 0 to continue or 1 to stop:
	*/
}

void convertDecimalToHexUsingStack()
{
	cout << "Enter decimal number to convert to HEX: ";
	long DecNum;
	cin >> DecNum;
	if (DecNum<10)
	{
		cout << "The hexadecimal of " << DecNum << " is " << DecNum << endl;
	}
	else
	{
		long copy = DecNum;
		Stack stk;
		ItemType itm;

		while (DecNum != 0)
		{
			long mod = DecNum % 16;
			itm.Long = mod;

			if (!stk.isFull())
			{
				stk.push(itm);
			}
			else
			{
				cout << "Stack is full." << endl;
				return;
			}

			DecNum = DecNum / 16;
		}//end of first while loop

		cout << "The hex form of " << copy << " is: ";

		while (!stk.isEmpty())
		{
			long temp = stk.top().Long;
			stk.pop();

			if (temp<10)
			{
				cout << temp;
			}
			else
			{
				cout << (static_cast<char>(temp + 55));
			}
		}
		cout << endl;
	}//end of else
}//end of function