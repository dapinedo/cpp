/* Daniel Pinedo
 * CS 2 - Section 0140
 * assignment: 2, part 1
 * due: Sept. 18, 2017
 * file: BankAccount.h
 */

#pragma once
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>
#include <string>
#include <fstream> // IO to files
#include <iomanip>
#include <sstream> 
using namespace std;

class BankAccount
{
private:
	string ActNum;
	string LastName;
	string FirstName;
	double balance; // class invariant, cannot be negative
public:
	//Default constructor
	BankAccount();
	
	//Explicit constructor
	BankAccount(const string & actN, const string &fname, const string &lname,
		double bal);
	
	// toString() functions
	const string toString() const;
	
	// print() functions
	void print(ostream & out) const;
	
	// Mutators - read/write access
	void setAccountNumber (const string & actN);
	void setLastName(const string & lname);
	void deposit(double money);
	void withdraw(double money);
	
	// Accessors - read only access
	const string getAccountNumber() const;
	const string getLastName() const;
	const string getFirstName() const;
	const string getFullName() const;
	double getBalance() const;
	
	/*
	getInstance takes object and fills the otherwise blank class object instance;
	1. getInstance(BankAccount & BA) takes input from cin
	2. getInstance(BankAccount & BA, ifstream & in) take input from input file
	*/
	
	/* 1. static prototype instantiates class as object
	 * Can't call any other class functions that are not static.
	 * Can't access non static class data members.
	 */
	static void getInstance(BankAccount & BA);
	/* 2. static prototype instantiates class as object
	 * Can't call any other class functions that are not static.
	 * Can't access non static class data members.
	 */
	static void getInstance(BankAccount & BA, ifstream & in);

};

#endif

