/* Daniel Pinedo
 * CS 2 - Section 0140
 * assignment: 2, part 1
 * Grade, Part 1 prep : OK 
 * Grade, Part 1      : 9.5/10
 * Grade, Part 2 prep : 
 * Grade, Part 2      :
 * part 1 due: Sept. 18, 2017
 * part 2 due: Sept. 25, 2017
 * file: BankAccountList.h
 */
 
#pragma once
#ifndef BANKACCOUNTLIST_H
#define BANKACCOUNTLIST_H
#include "BankAccount.h"

class BankAccountList
{
private:
    const static size_t MAX = 30; // Capacity of the list
    /*
	list_state = 0 for unsorted list
	list_state = 1 for sorted list based on Account Number
	list_state = 2 for sorted list based on Last Name
	list_state = 3 for sorted list based on Balance
	*/
    size_t list_state;
    size_t num_of_elements; // Logical length of the list
    BankAccount List[MAX];
public:
	// CONSTRUCTORS
	BankAccountList();
	
	// MUTATORS
	
	// Adds account BA to Bank Account List. Informs user if list is full. 
	// Must have unique account number.
	// Sets list_state to 0.
	void addAccount(const BankAccount & BA);
	
	// Runs findAccount ACCESSOR. If found returns true and deletes account.
	// Otherwise returns false. Does not change list_state.
	bool deleteAccount(const string & actNum);
	
	// Runs findAccount ACCESSOR. If found returns true and deposits into account.
	// Otherwise returns false. Resets list_state to 0 if list_state = 1
	bool depositMoney(const string & actNum, double money);
	
	// sets number of elements in list to zero and sets list state to 0
	void makeEmpty();
	
	// Prompts user to provide account number
	// calls findAccount
	     // if not exist, does nothing else
	     // if exist, then make changes to last name of account
	// return true if change made successfully
	// if list_state is 2 then set to 0
	bool updateAccount();
	
	// calls findAccount
	    // if exist then withdraw money and return true
	    // if not exist or withdraw not successful return false
	// if list_state is 3 then set to 0
	bool withdrawMoney(const string & actNum, double money);
	
	// flag 1: sort based on account number
	// flag 2: sort based on last name
	// flag 3: sort based on balance
	void sort(int flag);
	
	// checks if index is within bound of index of list,
	// then replaces account at location index with BA
	void setAccountAt(BankAccount & BA, size_t index);
	
	// checks if actNum is in the list. If true, sets lname to last name 
	// if list_state is 2 then sets to 0
	void setLastName(const string & lname, const string & actNum);
	
	// NON-MUTATORS
	
	// if found then returns index i where found and returns true
    // if not found then returns -1 as value of i and returns false
	bool findAccount(const string & actNum, int & i) const;
	
	bool getAccountAt(BankAccount & BA, size_t & index) const;
	double getBalance(const string & actNum) const;
	static int getCapacity();
	const string getFirstName(const string & actNum) const;
	const string getFullName(const string & actNum) const;
	void getHighestBalanceAccount (BankAccount & BA) const;
	
	// returns by reference a new instance of BankAccountList from console
	static void getInstance(BankAccountList & BAL);
	
	// returns by reference a new instance of BankAccountList from input file
	static void getInstance(BankAccountList & BAL, ifstream & in);
	const string getLastName(const string & actNum) const;
	int getLengthOfLongestFirstName() const;
	int getLengthofLongestLastName() const;
	int getListState const;
	double getMeanOfAllDeposits() const;
	int getNumberOfElements() const;
	void getSmallestBalanceAccount(BankAccount & BA) const;
	bool isEmpty() const;
	bool isFull() const;
	const string listDescription() const;
	size_t numberOfDepositsAboveMean() const;
	size_t numberOfDepositsAtOrBelowMean() const;
	
	// prints to console[default] or output file
    // writes to output file in append mode to prevent deleting previous data
	void print(ostream & out) const;
	void printListAsReport();
	void  printStatistics(ostream & out) const;
	double Standard_Deviation_Deposits() const;
	double sumAllDeposits() const;
	
	// returns string version of entire bank account list
	const string toString() const;
	void writeToNewInputFile(ostream & out) const;
};

#endif