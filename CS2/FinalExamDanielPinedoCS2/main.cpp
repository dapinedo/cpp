/*
Daniel Pinedo
CS2, Final Exam
12/13/2017
Compiler: Visual Studio 2017
*/

#include "iterator.h"
#include "CharacterFrequency.h"
#include <iostream>
#include <sstream>
using namespace std;

/* This final exam program analyzes input file by: 
	1. adds to a binary search tree each letter in order presented (up to 26 total letters)
	2. updates frequency of each letter as they are added if already in binary search tree
	3. prints output to file and screen in tree order
*/

const int MAX = 5000;
bool contains(char arr[], char ch, int length);

int main()
{
	cout << "The program will analyze input file for frequency of letters in alphabet." << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "Enter full path to input file: ";
	string filename;
	getline(cin, filename);
	ifstream in(filename);

	// if file fails to open, exit program
	if (!in.is_open()) {
		cout << "File opening error" << endl;
		exit(0);
	}

	//take input from file and put into array of type char
	char AnalyzedLetters[MAX];
	int count = 0;
	while (in.peek() != EOF && count < MAX) {
		char ch;
		in >> ch;
		if (isalpha(ch)) {
			AnalyzedLetters[count] = ch;
			count++;
		}
	}
	in.close();
	
	// create tree
	BinarySearchTree<CharacterFrequency> BST_CharacterFrequency;
	for (int i = 0; i < count; i++) {
		CharacterFrequency CF(AnalyzedLetters[i]);
		if (BST_CharacterFrequency.contains(CF)) {
			//just update frequency
			SearchTreeNode<CharacterFrequency> * STN = BST_CharacterFrequency.get(CF);
			STN->contents.updateFrequency();
		}
		else {
			// add the CF
			BST_CharacterFrequency.add(CF);
		}
	}

	// print tree
	cout << "Enter full path to file for output: ";
	string fileout;
	getline(cin, fileout);
	ofstream out(fileout);
	cout << "Here is the list of letters and their frequency: " << endl;
	cout << "---------------------------------------------------" << endl;

	BST_CharacterFrequency.printInorder(cout);
	BST_CharacterFrequency.printInorder(out);
	cout << "---------------------------------------------------" << endl;
	cout << "Output file successfully created/written" << endl;
	out.close();

	return (0);
}

bool contains(char arr[], char ch, int length)
{
	for (int i = 0; i < length; i++) {
		if (ch == arr[i]) {
			return true;
		}
	}
	return false;
}