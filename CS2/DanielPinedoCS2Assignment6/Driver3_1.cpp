#include "Arrayqueue.h"
#include <iostream>
#include <string>
using namespace std;


void testString();
void palindrome();

int main()
{

	//testString();
	palindrome();
	return 0;
}


//-------------------------------------------------------------
void testString()
{
	ArrayQueue string_ArrayQueue;
	cout<<"We will enqueue some strings in the Queue now.\n";
	bool done = false;
	string val = string();
	while(!string_ArrayQueue.isFull()&&!done)
	{
		cout<<"Please enter an string to be added to the Queue : ";
		cin>>val;
		ItemType Value;
		Value.string_data = val;
		string_ArrayQueue.enqueue(Value);
		cout<<"More data? Enter 0 to continue and 1 to exit: ";
		cin>>done;
	}

	cout<<"Now printing the strings in Queue.\n";

	while(!string_ArrayQueue.isEmpty())
	{
		cout<<(string_ArrayQueue.dequeue()).string_data<<"  ";
	}
	cout<<endl;
}
//---------------------------------------------------------------

void palindrome()
{
	ArrayQueue char_ArrayQueue;
	cout << "We will enqueue some strings in the Queue now.\n";
	cout << "How many strings do you want to enter now? ";
	size_t numstrings;
	cin >> numstrings;
	size_t counter = 0;
	string val = string();
	cin.ignore(128, '\n');
	while (!char_ArrayQueue.isFull() && (counter < numstrings))
	{
		cout << "Please enter a string to be added to the Queue: ";
		getline(cin, val);
		ItemType Value;
		Value.string_data = val;
		for (auto & c : val) {
			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
				Value.Character = c;
				char_ArrayQueue.enqueue(Value);
			}
		}

		while (!char_ArrayQueue.isEmpty())
		{
				cout << (char_ArrayQueue.dequeue()).Character;
		}
		cout << endl;
		
		counter++;
	}

	cout << "Now checking the strings in Queue.\n";

	
}