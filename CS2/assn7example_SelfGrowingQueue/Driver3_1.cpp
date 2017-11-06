#include "ArrayQueue.h"
#include <iostream>
#include <random>
using namespace std;

void testInt();
void testChar();
void testFloat();
void testString();
void testCopyConstructor(ArrayQueue AQ);
void TestingRandomEnqueingAndDequeing();
int main()
{

	/*testInt();
	testChar();
	testFloat();
	testString();*/
	//ArrayQueue IntAQ;
	//ItemType INT;
	//INT.Integer = 5;
	//IntAQ.enqueue(INT);
	//INT.Integer = 6;
	//IntAQ.enqueue(INT);
	//INT.Integer = 7;
	//IntAQ.enqueue(INT);
	//INT.Integer = 8;
	//IntAQ.enqueue(INT);
	//INT.Integer = 9;
	//IntAQ.enqueue(INT);
	//INT.Integer = 10;
	//IntAQ.enqueue(INT);
	//INT.Integer = 11;
	//IntAQ.enqueue(INT);
	//cout << "Printing integers in original queue.\n";
	//testCopyConstructor(IntAQ);
	////Testing assignment operator now
	//ArrayQueue AQ_Copy = IntAQ;
	//cout << "Printing integers in queue that was copied using user defined assignment operator.\n";
	//while (!AQ_Copy.isEmpty())
	//{
	//	cout << (AQ_Copy.dequeue()).Integer << "  ";
	//}

	//cout << endl;
	TestingRandomEnqueingAndDequeing();
	return 0;
}

/////////////////////////////////////////////////////////////
void TestingRandomEnqueingAndDequeing()
{
	// Generate 20 random numbers in range 1 to 100. If random number is
	//even then print the number and enqueue it. If random number is odd then
	//dequeue and print the dequeued value.
	ArrayQueue AQ;
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1, 100);

	for (size_t i = 0; i < 20; i++)
	{
		int dice_roll = distribution(generator);  // generates number in the range 1..100

		if (dice_roll % 2 == 0)
		{
			ItemType IT;
			IT.Integer = dice_roll;
			cout << "Even random number generated and being enqued is: " << IT.Integer << endl;
			AQ.enqueue(IT);
		}
		else 
		{
			cout << "Odd random number is: " << dice_roll << endl;
			if (!AQ.isEmpty())
			{
				cout << "The number being dequed is: " << (AQ.dequeue()).Integer << endl;
			}
		}
	}
	
	cout << "Now dequeing any remaining numbers in the queue.\n";

	while (!AQ.isEmpty()){
		cout << (AQ.dequeue()).Integer << endl;
	}
}
void testCopyConstructor(ArrayQueue Int_ArrayQueue)
{
	cout << "Now printing the integers in the Queue.\n";

	while (!Int_ArrayQueue.isEmpty())
	{
		cout << (Int_ArrayQueue.dequeue()).Integer << "  ";
	}

	cout << endl;
}
void testInt()
{
	ArrayQueue Int_ArrayQueue;
	cout << "We will enqueue some integers on the queue now.\n";
	bool done = false;
	int val = int();
	while (!done)
	{
		cout << "Please enter an integer to be enqueued : ";
		cin >> val;
		ItemType Value;
		Value.Integer = val;
		Int_ArrayQueue.enqueue(Value);
		cout << "More data? Enter 0 to continue and 1 to exit: ";
		cin >> done;
	}

	cout << "Now printing the integers in the Queue.\n";

	while (!Int_ArrayQueue.isEmpty())
	{
		cout << (Int_ArrayQueue.dequeue()).Integer << "  ";
	}
	//	Int_ArrayQueue.dequeue();//change MAX  to 5 and uncomment.
	cout << endl;
}
//---------------------------------------------------------------
void testChar()
{
	ArrayQueue Char_ArrayQueue;
	cout << "We will enqueue some characters in the Queue now.\n";
	bool done = false;
	char val = char();
	while (!done)
	{
		cout << "Please enter an character to be put in the Queue : ";
		cin >> val;
		ItemType Value;
		Value.Character = val;
		Char_ArrayQueue.enqueue(Value);
		cout << "More data? Enter 0 to continue and 1 to exit: ";
		cin >> done;
	}

	cout << "Now printing the characters in the Queue.\n";

	while (!Char_ArrayQueue.isEmpty())
	{
		cout << (Char_ArrayQueue.dequeue()).Character << "  ";
	}
	cout << endl;
}
//-------------------------------------------------------------
void testFloat()
{
	ArrayQueue Float_ArrayQueue;
	cout << "We will enqueue some floating point numbers in the Queue now.\n";
	bool done = false;
	float val = float();
	while (!done)
	{
		cout << "Please enter a floating point number to be added to the Queue : ";
		cin >> val;
		ItemType Value;
		Value.Float = val;
		Float_ArrayQueue.enqueue(Value);
		cout << "More data? Enter 0 to continue and 1 to exit: ";
		cin >> done;
	}

	cout << "Now printing the floating point numbers  in the Queue.\n";

	while (!Float_ArrayQueue.isEmpty())
	{
		cout << (Float_ArrayQueue.dequeue()).Float << "  ";
	}
	cout << endl;
}
//-------------------------------------------------------------
void testString()
{
	ArrayQueue string_ArrayQueue;
	cout << "We will enqueue some strings in the Queue now.\n";
	bool done = false;
	string val = string();
	while (!done)
	{
		cout << "Please enter an string to be added to the Queue : ";
		cin >> val;
		ItemType Value;
		Value.string_data = val;
		string_ArrayQueue.enqueue(Value);
		cout << "More data? Enter 0 to continue and 1 to exit: ";
		cin >> done;
	}

	cout << "Now printing the strings in Queue.\n";

	while (!string_ArrayQueue.isEmpty())
	{
		cout << (string_ArrayQueue.dequeue()).string_data << "  ";
	}
	cout << endl;
}
//---------------------------------------------------------------
/*output example 1
The code below in main produced the output below:
testInt();
testChar();
testFloat();
testString();
We will enqueue some integers on the queue now.
Please enter an integer to be enqueued : 1
Using the existing array to enqueue.
Number of items in queue now: 1
More data? Enter 0 to continue and 1 to exit: 0
Please enter an integer to be enqueued : 2
Expanding the array to enqueue.
Number of items in queue now: 2
More data? Enter 0 to continue and 1 to exit: 0
Please enter an integer to be enqueued : 3
Expanding the array to enqueue.
Number of items in queue now: 3
More data? Enter 0 to continue and 1 to exit: 0
Please enter an integer to be enqueued : 4
Expanding the array to enqueue.
Number of items in queue now: 4
More data? Enter 0 to continue and 1 to exit: 0
Please enter an integer to be enqueued : 5
Expanding the array to enqueue.
Number of items in queue now: 5
More data? Enter 0 to continue and 1 to exit: 0
Please enter an integer to be enqueued : 6
Expanding the array to enqueue.
Number of items in queue now: 6
More data? Enter 0 to continue and 1 to exit: 0
Please enter an integer to be enqueued : 7
Expanding the array to enqueue.
Number of items in queue now: 7
More data? Enter 0 to continue and 1 to exit: 1
Now printing the integers in the Queue.
1  2  3  4  5  6  7
We will enqueue some characters in the Queue now.
Please enter an character to be put in the Queue :
a
Using the existing array to enqueue.
Number of items in queue now: 1
More data? Enter 0 to continue and 1 to exit: 0
Please enter an character to be put in the Queue : b
Expanding the array to enqueue.
Number of items in queue now: 2
More data? Enter 0 to continue and 1 to exit: 0
Please enter an character to be put in the Queue : c
Expanding the array to enqueue.
Number of items in queue now: 3
More data? Enter 0 to continue and 1 to exit: 0
Please enter an character to be put in the Queue : d
Expanding the array to enqueue.
Number of items in queue now: 4
More data? Enter 0 to continue and 1 to exit: 0
Please enter an character to be put in the Queue : e
Expanding the array to enqueue.
Number of items in queue now: 5
More data? Enter 0 to continue and 1 to exit: 0
Please enter an character to be put in the Queue : f
Expanding the array to enqueue.
Number of items in queue now: 6
More data? Enter 0 to continue and 1 to exit: 1
Now printing the characters in the Queue.
a  b  c  d  e  f
We will enqueue some floating point numbers in the Queue now.
Please enter a floating point number to be added to the Queue : 1.1
Using the existing array to enqueue.
Number of items in queue now: 1
More data? Enter 0 to continue and 1 to exit: 0
Please enter a floating point number to be added to the Queue : 2.2
Expanding the array to enqueue.
Number of items in queue now: 2
More data? Enter 0 to continue and 1 to exit: 0
Please enter a floating point number to be added to the Queue : 3.3
Expanding the array to enqueue.
Number of items in queue now: 3
More data? Enter 0 to continue and 1 to exit: 0
Please enter a floating point number to be added to the Queue : 4.4
Expanding the array to enqueue.
Number of items in queue now: 4
More data? Enter 0 to continue and 1 to exit: 0
Please enter a floating point number to be added to the Queue : 5.5
Expanding the array to enqueue.
Number of items in queue now: 5
More data? Enter 0 to continue and 1 to exit: 1
Now printing the floating point numbers  in the Queue.
1.1  2.2  3.3  4.4  5.5
We will enqueue some strings in the Queue now.
Please enter an string to be added to the Queue : aa
Using the existing array to enqueue.
Number of items in queue now: 1
More data? Enter 0 to continue and 1 to exit: 0
Please enter an string to be added to the Queue : bb
Expanding the array to enqueue.
Number of items in queue now: 2
More data? Enter 0 to continue and 1 to exit: 0
Please enter an string to be added to the Queue : cc
Expanding the array to enqueue.
Number of items in queue now: 3
More data? Enter 0 to continue and 1 to exit: 0
Please enter an string to be added to the Queue : dd
Expanding the array to enqueue.
Number of items in queue now: 4
More data? Enter 0 to continue and 1 to exit: 0
Please enter an string to be added to the Queue : ee
Expanding the array to enqueue.
Number of items in queue now: 5
More data? Enter 0 to continue and 1 to exit: 1
Now printing the strings in Queue.
aa  bb  cc  dd  ee
*/
/*
Code in main function below produced the output after it.
//////////////////////////////////////////////////////
code//
/////
ArrayQueue IntAQ;
ItemType INT;
INT.Integer = 5;
IntAQ.enqueue(INT);
INT.Integer = 6;
IntAQ.enqueue(INT);
INT.Integer = 7;
IntAQ.enqueue(INT);
INT.Integer = 8;
IntAQ.enqueue(INT);
INT.Integer = 9;
IntAQ.enqueue(INT);
INT.Integer = 10;
IntAQ.enqueue(INT);
INT.Integer = 11;
IntAQ.enqueue(INT);
testCopyConstructor(IntAQ);
////////////////
// Output//
//////////
**********>  Using the existing array to enqueue. <*******************
Number of items in queue now: 1
**********> Expanding the array to enqueue. <*******************
Number of items in queue now: 2
**********> Expanding the array to enqueue. <*******************
Number of items in queue now: 3
**********> Expanding the array to enqueue. <*******************
Number of items in queue now: 4
**********> Expanding the array to enqueue. <*******************
Number of items in queue now: 5
**********> Expanding the array to enqueue. <*******************
Number of items in queue now: 6
**********> Expanding the array to enqueue. <*******************
Number of items in queue now: 7
Now printing the integers in the Queue.
5  6  7  8  9  10  11
*/
/*
The code below in main function intends to test both copy constructor and assignment operator.
The output is given after the code.
//////////////////////////////////////////////////////
code//
/////
ArrayQueue IntAQ;
ItemType INT;
INT.Integer = 5;
IntAQ.enqueue(INT);
INT.Integer = 6;
IntAQ.enqueue(INT);
INT.Integer = 7;
IntAQ.enqueue(INT);
INT.Integer = 8;
IntAQ.enqueue(INT);
INT.Integer = 9;
IntAQ.enqueue(INT);
INT.Integer = 10;
IntAQ.enqueue(INT);
INT.Integer = 11;
IntAQ.enqueue(INT);
cout << "Printing integers in original queue.\n";
testCopyConstructor(IntAQ);
//Testing assignment operator now
ArrayQueue AQ_Copy = IntAQ;
cout << "Printing integers in queue that was copied using user defined assignment operator.\n";
while (!AQ_Copy.isEmpty())
{
cout << (AQ_Copy.dequeue()).Integer << "  ";
}

cout << endl;
////////////////
// Output//
//////////
**********>  Using the existing array to enqueue. <*******************
Number of items in queue now: 1
**********> Expanding the array to enqueue. <*******************
Number of items in queue now: 2
**********> Expanding the array to enqueue. <*******************
Number of items in queue now: 3
**********> Expanding the array to enqueue. <*******************
Number of items in queue now: 4
**********> Expanding the array to enqueue. <*******************
Number of items in queue now: 5
**********> Expanding the array to enqueue. <*******************
Number of items in queue now: 6
**********> Expanding the array to enqueue. <*******************
Number of items in queue now: 7
Printing integers in original queue.
Now printing the integers in the Queue.
5  6  7  8  9  10  11
Printing integers in queue that was copied using user defined assignment operator.
5  6  7  8  9  10  11
*/

/*
The code below in main function intends to test both copy constructor and assignment operator.
The output is given after the code.
//////////////////////////////////////////////////////
code//
/////
// Generate 20 random numbers in range 1 to 100. If random number is
//even then print the number and enqueue it. If random number is odd then
//dequeue and print the dequeued value.
ArrayQueue AQ;
std::default_random_engine generator;
std::uniform_int_distribution<int> distribution(1, 100);

for (size_t i = 0; i < 20; i++)
{
int dice_roll = distribution(generator);  // generates number in the range 1..100

if (dice_roll % 2 == 0)
{
ItemType IT;
IT.Integer = dice_roll;
cout << "Even random number generated and being enqued is: " << IT.Integer << endl;
AQ.enqueue(IT);
}
else
{
cout << "Odd random number is: " << dice_roll << endl;
if (!AQ.isEmpty())
{
cout << "The number being dequed is: " << (AQ.dequeue()).Integer << endl;
}
}
}

cout << "Now dequeing any remaining numbers in the queue.\n";

while (!AQ.isEmpty()){
cout << (AQ.dequeue()).Integer << endl;
}

////////////////
// Output//
//////////
Odd random number is: 13
Odd random number is: 3
Odd random number is: 35
Even random number generated and being enqued is: 86
**********>  Using the existing array to enqueue. <*******************
Number of items in queue now: 1
Odd random number is: 5
index of front pointer is: 0
The number being dequed is: 86
Even random number generated and being enqued is: 92
**********>  Using the existing array to enqueue. <*******************
Number of items in queue now: 1
Even random number generated and being enqued is: 30
**********> Expanding the array to enqueue. <*******************
Number of items in queue now: 2
Even random number generated and being enqued is: 86
**********> Expanding the array to enqueue. <*******************
Number of items in queue now: 3
Odd random number is: 99
index of front pointer is: 1
The number being dequed is: 92
Even random number generated and being enqued is: 4
**********>  Using the existing array to enqueue. <*******************
Number of items in queue now: 3
Even random number generated and being enqued is: 36
**********> Expanding the array to enqueue. <*******************
Number of items in queue now: 4
Even random number generated and being enqued is: 66
**********> Expanding the array to enqueue. <*******************
Number of items in queue now: 5
Odd random number is: 41
index of front pointer is: 1
The number being dequed is: 30
Odd random number is: 27
index of front pointer is: 2
The number being dequed is: 86
Even random number generated and being enqued is: 40
**********>  Using the existing array to enqueue. <*******************
Number of items in queue now: 4
Odd random number is: 21
index of front pointer is: 3
The number being dequed is: 4
Even random number generated and being enqued is: 20
**********>  Using the existing array to enqueue. <*******************
Number of items in queue now: 4
Odd random number is: 5
index of front pointer is: 4
The number being dequed is: 36
Even random number generated and being enqued is: 98
**********>  Using the existing array to enqueue. <*******************
Number of items in queue now: 4
Odd random number is: 7
index of front pointer is: 0
The number being dequed is: 66
Now dequeing any remaining numbers in the queue.
index of front pointer is: 1
40
index of front pointer is: 2
20
index of front pointer is: 3
98
*/