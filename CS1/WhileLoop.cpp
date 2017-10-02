//
//  WhileLoop.cpp
//  3.23
//
//  Created by Daniel Pinedo on 3/23/17.
//  Copyright © 2017 Daniel Pinedo. All rights reserved.
//

#include <iostream>
using namespace std;

/*
Problem statement: Students may take 0 to any number of tests in the semester.
Program should do the following:
1. Data input to get all test scores (assume all tests out of 100)
2. Sum up all tests
3. Find real average value (Floating point)
4. Find a rounded average value (whole number)
5. Assign a semester grade based on rounded average value
6. Print all data.
Sentinel condition: test score cannot be negative. So data entry stops with negative test 
score (impossible value or sentinel value for test score is entered)
*/


int main () // Event Controlled / Sentinel loop
{
    int sum = 0; // Must initialize to zero because it is used as an accumulator
    int numTests; // Must initialize to zero because it acts like a counter
    int score;
    // Event Controlled / Sentinel loop
    // prime read
    cout << "Enter score in first test or -1 to stop: ";
    cin >> score;
    
    while (score >= 0) // loop test
    {
        sum += score;
        numTests++;
        // loop update
        cout << "Enter score in first test or -1 to stop: ";
        cin >> score; // update read
    }
    
    if (numTests > 0) // can find an average
    {
        double realAve = static_cast<double>(sum) / numTests;
        cout << "Sum of all your tests: " << sum << endl;
        cout << "Number of Tests taken" << numTests << endl;
        cout << "The real average of your tests" << realAve << endl;
        int roundedAve = static_cast<int>(realAve + 0.5);
        //Assign letter grade based on rounded average
        
        char grade;
        if (roundedAve >= 90)
        {
            grade = 'A';
        }
        else if (roundedAve >= 80)
        {
            grade = 'B';
        }
        else if (roundedAve >=70)
        {
            grade = 'C';
        }
        else if (roundedAve >=60)
        {
            grade = 'D';
        }
        else
        {
            grade = 'F';
        }
    }
    else {
        cout << "You didn't take any test";
    }
    return 0;
}


/*
Easter is around the corner. We wish to create
"Happy Easter" labels. We wish to create 10 labels
*/

int main1() // Count-Controlled Loop
{
    
    // size_t is unsigned int, which cannot have negative value
    size_t numLabels = 10; // size_t used when integer quantity cannot be less than 0
    size_t count = 0; //keeps track of number of labels printed
    
    while (count < numLabels) // loop test
    {
        cout << "Happy Easter!" << endl; // loop task
        count++; // loop update
    }

    return 0;
}
