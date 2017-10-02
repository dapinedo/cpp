//
//  RelationalOperators.cpp
//  3.7
//
//  Created by Daniel Pinedo on 3/7/17.
//  Copyright © 2017 Daniel Pinedo. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    
    cout << boolalpha; // Set 0/1 to true/false
    
    int X = 5;
    int Y = 6;
    cout << (Y > X) << endl; // relational operator
    
    if (Y>X) // selection structure
    {
        cout << Y << " is greater than " << X << endl;
    }
    else
    {
        cout << Y << " is not greater than " << X << endl;
    }
    
    // Reverse Case
    X = 6;
    Y = 5;
    
    if (Y > X) // selection structure
    {
        cout << Y << " is greater than " << X << endl;
    }
    else
    {
        cout << Y << " is not greater than " << X << endl;
    }
    
    // Relational Operators
    cout << (X < Y) << endl;
    cout << (X >= Y) << endl;
    cout << (X == Y) << endl;
    cout << (X != Y) << endl;
    
    //Example: Hourly Worker Salary
    {
        int hoursWorked;
        double payRate;
        
        // Take inout for hoursWorked and payRate
        cout << "Enter # of hours worked [Whole number only]: ";
        cin >> hoursWorked;
        cout << "Enter hourly pay rate [xx.yy]: ";
        cin >> payRate;
        double salary; // Must declare outside of selection structure to be visible to whole program
        if (hoursWorked <= 40) // REMEMBER: signature line does not have semicolon
        {
            salary = hoursWorked*payRate;
        }
        else
        {
            int overTime = hoursWorked - 40;
            double overTimePay = overTime*1.5*payRate;
            salary = overTimePay + 40 * payRate;
            cout << "Overtime hours = " << overTime
            << " ; Overtime amount = " << overTimePay << " ; ";
        }
        cout << "Gross Salary: " << salary << endl;
        
        //Computation in dollars and cents **STUDY FOR TEST**
        double TotalRealPennies = salary * 100;
        int roundedPennies = (int)(TotalRealPennies + 0.5);
        int dollars = roundedPennies / 100;
        int cents = roundedPennies % 100;
        
        cout << "Salary: " << dollars << " dollars and "
        << cents << " cents. " << endl;
        
    }
    return 0;
}
