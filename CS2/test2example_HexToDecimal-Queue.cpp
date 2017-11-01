#include "QueueInterface.h"
#include "ArrayQueue.h"
#include <iostream>
using namespace std;

void ConvertHexToDecimal();
/*
drill: Using the algorithm in function ConvertHexToDecimal
write following functions and test them that they work
void ConvertBinaryToDecimal()
void ConvertOctalToDecimal()
*/
int main()
{
	bool done = false;

	while (!done)
	{
		ConvertHexToDecimal();
		cout << "More conversions? Enter 0 to continue or 1 to stop: ";
		cin >> done;
	}
	system("pause");
	return 0;
}

void ConvertHexToDecimal()
{
	cout << "Enter a hex number to convert to decimal: ";
	string Hex;
	cin >> Hex;
	//drill parse through HEX and convert all letters to
	//upper case
	string copy = Hex;
	ArrayQueue Que;
	ItemType itm;

	for (size_t i = 0; i < Hex.length(); i++)
	{
		char ch = Hex[i];
		itm.Character = ch;
		//Enqueue itm
		if (!Que.isFull())
		{
			Que.enqueue(itm);
		}
		else
		{
			cout << "Queue is full. Exiting." << endl;
			exit(0);
		}
	}

	int Result = 0;

	for (size_t i = 0; i < Hex.length(); i++)
	{
		ItemType I;
		I = Que.dequeue();
		char ch = I.Character;
		int num = 0;

		if (ch<= '9')
		{
			num = static_cast<int>(ch) - 48;
		}
		else
		{
			num = static_cast<int>(ch) - 55;
		}
		Result += num;

		if (i<Hex.length() -1)
		{
			Result *= 16;
		}
	}//loop
	cout << "Hex " << copy << " is " << Result << " on decimal scale." << endl;
}

