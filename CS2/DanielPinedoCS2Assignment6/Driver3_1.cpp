#include "Arrayqueue.h"
#include "Stack.h"
#include <iostream>
#include <string>
using namespace std;


void testString();
void palindrome();

int main()
{

	//testString();
	palindrome();

	system("pause");
	return 0;
}

//---------------------
//TEST OF MAIN FUNCTION
//---------------------
/*
We will check each string to see if it is a palindrome now.
How many strings do you want to enter now? 5
Please enter a string to be checked: Race car

Race car
** IS a palindrome **

Please enter a string to be checked: 'Twas the night before Christmas . . .

'Twas the night before Christmas . . .
** IS NOT a palindrome **

Please enter a string to be checked: Egad!  A base life defiles a bad age.

Egad!  A base life defiles a bad age.
** IS a palindrome **

Please enter a string to be checked: "Do nine men interpret?"  "Nine men," I nod.

"Do nine men interpret?"  "Nine men," I nod.
** IS a palindrome **

Please enter a string to be checked: A man, a plan, a canal: Panama!

A man, a plan, a canal: Panama!
** IS a palindrome **

Press any key to continue . . .
*/
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
	cout << "We will check each string to see if it is a palindrome now.\n";
	cout << "How many strings do you want to enter now? ";
	size_t numstrings;
	cin >> numstrings;
	size_t counter = 0;
	cin.ignore(128, '\n');
	ArrayQueue char_ArrayQueue;
	while (!char_ArrayQueue.isFull() && (counter < numstrings))
	{
		cout << "Please enter a string to be checked: ";
		string val = "";
		getline(cin, val);
		ItemType Value;
		Stack palindromeStack;
		Value.string_data = val;
		for (auto & c : val) {
			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
				Value.Character = tolower(c);
				//cout << Value.Character << endl; // testing output to enqueue()
				char_ArrayQueue.enqueue(Value);
				palindromeStack.push(Value);
				//cout << palindromeStack.top().Character << endl; // testing output of push()
			}
		}
		cout << endl << "     " << Value.string_data;
		bool ispalindrome = true;
		while (!char_ArrayQueue.isEmpty()) {
			if (char_ArrayQueue.dequeue().Character != palindromeStack.top().Character) {
				palindromeStack.pop();
				ispalindrome = false;
			}
			else {
				palindromeStack.pop();
				ispalindrome = true;
			}
		}
		if (ispalindrome) {
			cout << endl << "     ** IS a palindrome **" << endl << endl;
		}
		else {
			cout << endl << "     ** IS NOT a palindrome **" << endl << endl;
		}
		counter++;
	}
}