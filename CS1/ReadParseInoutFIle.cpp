/*
 Satish Singhal
 Class: CS1
 Date:3/28/2017
 Program Name: Student Grading Program With Loop
 */
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

/*
 Problem statement: Students may take 0 to any number
 of tests in the semester.
 Program should do followings:
 1. Data input to get all test scores (assume all tests out of 100)
 2. Sum up all tests.
 3. Find real average value. (Floating point value)
 4. Find a rounded average value(whole number)
 5. Assign a semester grade based on rounded average value
 6. Print all data.
 Sentinel condition: test score cannot be negative. So data entry
 stops when a negative test score (imposssible value or sentinel
 value for test score is entered).
 
 */

int main()
{
    cout << fixed << showpoint << setprecision(2);
    int sum = 0;// Must initialize to zero because it is used as an accumulator
    int numTests = 0;//Must initialize to zero because it acts as a counter of number of tests
    int score;
    // Sentinel loop
    // prime read
    
    //1. Ask and store full path to input file
    
    string inFileName;
    cout << "Enter full path to input file: ";
    getline (cin, inFileName);
    //2. Bind file name with the ifstream object - opening a connection
    ifstream in(inFileName);
    //3. Verify that connection was successful
    //Do a conditional test
    if (in.is_open()) //returns true if a file is open

    
        while (score >= 0)// loop test
        {
            sum += score;
            numTests++;
            // loop update
            cout << "Enter score in next test or -1 to stop: ";
            cin >> score;// update read
        }
    
        if (numTests > 0)// can find an average
        {
            double realAve = static_cast<double>(sum) / numTests;
            cout << "Sum of all your tests: " << sum << endl;
            cout << "Number of tests taken: " << numTests << endl;
            cout << "The real average of your tests : " << realAve << endl;
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
            else if (roundedAve >= 70)
            {
                grade = 'C';
            }
            else if (roundedAve >= 60)
            {
                grade = 'D';
            }
            else
            {
                grade = 'F';
            }
        
            cout << "Your semester total rounded percentage: "
                 << roundedAve << endl;
            cout << "Your grade: " << grade << endl;
            }
            else
            {
                cout << " You did not take any tests." << endl;
            }

    return 0;
}
/*
 Enter score in first test or -1 to stop: 90
 Enter score in next test or -1 to stop: 89
 Enter score in next test or -1 to stop: 91
 Enter score in next test or -1 to stop: 88
 Enter score in next test or -1 to stop: 92
 Enter score in next test or -1 to stop: 95
 Enter score in next test or -1 to stop: -1
 Sum of all your tests: 545
 Number of tests taken: 6
 The real average of your tests : 90.83
 Your semester total rounded percentage: 91
 Your grade: A
 */
