//
//  MortgageList.h
//  MortgageList
//
//  Created by Satish Singhal on 9/12/15.
//  Copyright (c) 2015 Satish Singhal. All rights reserved.
//

#ifndef __MortgageList__MortgageList__
#define __MortgageList__MortgageList__
#include "Mortgage.h"
class MortgageList
{
private:
    const static int MAX = 10000;
    MortgageClass MList[MAX];
    size_t len;
    /**
     list_state = 0 or unsorted
     list_state = 1 for sorted based on account number
     list_state = 2 for sorted based on customer last name
     list_state = 3 for sorted based on customer city
     list_state = 4 for sorted based on cost of houses
     */
    int list_state;
public:
    MortgageList();
    bool find(const MortgageClass & key, int flag,int & index) const;
    bool addMortgageAccount(const MortgageClass & MC);
    static void getInstance(MortgageList & ML, istream & in = cin);
    const string toString() const;
    void makeEmpty();
    bool isFull() const;
    bool isEmpty() const;
    size_t getCapacity()const;
    size_t getNumber_of_elements()const;
    int getList_state() const;
    MortgageClass getMortgageAt(int index) const;
    void sort(int flag);
    bool updateMortgageList();
    bool deleteAccount(const MortgageClass & MC);
    double getMeanMortgageLoan() const;
    double getStandardDevLoans() const;
    double getSmallestLoan() const;
    double getLargestLoan() const;
    static MortgageList CombineLists(const MortgageList & SL1, const MortgageList & SL2);
    void PrintFileForFutureRead(ostream & out = cout);
    void PrintAmortizationSchedule(int accountNum, ostream & out = cout);
    void makeMonthlyPayment(int actNum, double money);
	void setAccountAt(size_t index, const MortgageClass & M);
};
#endif /* defined(__MortgageList__MortgageList__) */
