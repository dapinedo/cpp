#pragma once
#ifndef NODE_H
#define NODE_H
#include "BankAccount.h"


struct Node
{
	BankAccount BA; // data part of node
	Node * Next; // self-referential pointer
	//constructor uses initialization list
	Node(BankAccount B, Node * N = nullptr);
	//toString function returns the string form of the struct member data
	const string toString() const;
};
#endif

