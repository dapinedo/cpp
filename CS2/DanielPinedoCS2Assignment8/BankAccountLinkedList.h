#pragma once
#ifndef BANKACCOUNTLINKEDLIST_H
#define BANKACCOUNTLINKEDLIST_H
#include "BankAccount.h"
#include "Node.h"

struct BankAccountLinkedList
{
	Node * Head;
	//constructor
	BankAccountLinkedList(); 
	//Rule 1. copy constructor
	BankAccountLinkedList(const BankAccountLinkedList & Other);
	//Rule 2. assignment operator
	const BankAccountLinkedList & operator = (const BankAccountLinkedList & Other);
	//Rule 3. destructor
	virtual ~BankAccountLinkedList();
	const string toString() const;
};

#endif