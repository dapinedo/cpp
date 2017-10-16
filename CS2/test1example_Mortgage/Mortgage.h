//
//  Mortgage.h
//  MortgageList
//
//  Created by Satish Singhal on 9/12/15.
//  Copyright (c) 2015 Satish Singhal. All rights reserved.
//
#pragma once
#ifndef __MortgageList__Mortgage__
#define __MortgageList__Mortgage__
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>
#include <sstream>
using namespace std;

class MortgageClass
{
private:
    /**
     
     */
    int AccountNum;
    /**
     Customer first name
     */
    string First;
    /**
     customer last name
     */
    string Last;
    /**
     Customer city
     */
    string City;
    /**
     * Fixed annual interest rate in percent only.
     */
    double rate;
    /**
     * Cost of the house to be bought
     */
    double cost;
    /**
     * Down payment made by the buyer.
     */
    double downPymnt;
    /**
     * Number of years for which mortgage is taken.
     */
    int year;
    /**
     Number of payments made
     */
    size_t numPayments;
    /**
     Amount of money left to pay.
     */
    double AmountLeftToPay;
    /**
     Amount Paid so far
     */
    double AmountPaid;
public:
    /*
     List of default arguments
     AccountNum = 0;
     First = "First name not set";
     Last = "Last name not set";
     City = "City name not set";
     rate = 4.5;
     cost = 100000;
     downPymnt = 20000;
     year = 30;

     */
    /**
     * @param rt
     * @param cst
     * @param dnp
     * @param yr
     */
    MortgageClass(int act = 0,const string & frst = "First name not set",
		const string & lst = "Last name not set", const string & city = "City name not set", 
		double rt = 4.5, double cst = 100000.0, double dnp = 20000.0, int yr = 30);
        /**
     * @return
     */
    static void getInstance(MortgageClass & M, istream & in = cin);
        /**
     *
     */
    void computeMortgagePrint(ostream & out = cout)const;
        /**
     *
     */
    void  printAmortizationSchedule(ostream & out = cout)const;
   
    void setRate(double rt);
    
    void setCost(double cst);
    
    void setYears(int yr);
    
    void setDownPayment(double dnp);
    void setCity(const string & ct);
    void setLastName(const string & lst);
    
    double getRate()const;
    
    double getCost()const;
    
    
    int getYears()const;
    
    int getAccountNumber()const;
    
    double getDownPayment()const;
    const string getFirstName()const;
    const string getLastName()const;
    const string getFullName()const;
    const string getCity()const;
    const string toString()const;
    double getMonthlyPayment() const;
    void makeMonthlyPayment(double pmt);
    double getTotalPaymentsMade() const;
    double getAmountLeftToPay() const;
};// end of class


#endif /* defined(__MortgageList__Mortgage__) */
