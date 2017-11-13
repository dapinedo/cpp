#pragma once
#ifndef LETTERNODE_H
#define LETTERNODE_H
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct LetterNode
{
	// data part of node
	size_t frequency;
	char letter;
	// self-referential pointer
	LetterNode * Next; 
	//constructor uses initialization list
	LetterNode(char ch = '*', size_t frq = 1, LetterNode * ptr = nullptr);
	//toString function returns the string form of the struct member data
	const string toString();
};
#endif

