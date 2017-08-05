/*
Satish Singhal
Class: CS1
Date:4/18
Program Name: PassByConstReference
*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void print(const string & text);
int main()
{
	string phrase = "The quick brown fox jumped over a lazy dog";
	print(phrase);
	cout << "Phrase: " << phrase << endl;

	return 0;
}

void print(const string & text)
{
	//text = "ooooo"; // will be a compile error because text is supposed to be trested as immutable or constant
	cout << text << endl;
}