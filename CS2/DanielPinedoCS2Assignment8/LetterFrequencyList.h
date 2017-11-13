#pragma once
#ifndef LETTERFREQUENCYLIST_H
#define LETTERFREQUENCYLIST_H
#include "LetterNode.h"

struct LetterFrequencyList
{
private:
	//returns true if letter is present in list. Called from inside insertInOrder()
	bool contains(char ltr);
public:
	LetterNode * Headptr;
	//constructor
	LetterFrequencyList();
	//Rule 1. copy constructor
	LetterFrequencyList(const LetterFrequencyList & Other);
	//Rule 2. assignment operator
	const LetterFrequencyList & operator = (const LetterFrequencyList & Other);
	// helper function for Rule 1 and 2
	void copy(const LetterFrequencyList & Other);
	// helper function for delete
	void destroy();
	// helper function for inserting new values
	void insert(char ltr, size_t frq);
	//if letter is not present then LetterNode is added in ascending order
	void insertInOrder(char ltr);
	//Rule 3. destructor
	virtual ~LetterFrequencyList();
	const string toString();
};
#endif