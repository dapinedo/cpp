//
//  IfStructure.cpp
//  3.9
//
//  Created by Daniel Pinedo on 3/9/17.
//  Copyright © 2017 Daniel Pinedo. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    // optimized if/else statement without indentation, else/if on same line
    // ask for semester total out of 100
    // rounded percentage
    int Score;
    char grade;
    cout << "Enter semester percentage rounded to whole number: ";
    cin >> Score;
    
    if (Score >= 90) // First if
    {
        grade = 'A';
    }
    else if (Score >= 80) // Second if - First if statement already checks for Score >= 90
    {
        grade = 'B';
    }
    else if (Score >= 70) // Third if - Second if statement already checks for Score >= 80
    {
        grade = 'C';
    }
    else if (Score >= 60) // Fourth if - Third if statement already checks for Score >= 70
    {
        grade = 'D';
    }
    else // if (Score < 60) // - Fourth if statement already checks for Score >= 60 -Fifth if can be more optimized with only else statement
    {
        grade = 'F';
    }
    cout << "Your semester total rounded percentage: ";
    cout << Score <<'\n';
    cout << "Your grade for this semester: ";
    cout << grade << '\n';
    
    return 0;
}


int main1()
{
    // optimized & nested if/else statement
    // ask for semester total out of 100
    // rounded percentage
    int Score;
    char grade;
    cout << "Enter semester percentage rounded to whole number: ";
    cin >> Score;
    
    if (Score >= 90) // First if
    {
        grade = 'A';
    }
    else // First if statement already checks for Score >= 90
        if (Score >= 80) // Second if
        {
            grade = 'B';
        }
        else // Second if statement already checks for Score >= 80
            if (Score >= 70) // Third if
            {
                grade = 'C';
            }
            else // Third if statement already checks for Score >= 70
                if (Score >= 60) // Fourth if
                {
                    grade = 'D';
                }
                else // Fourth if statement already checks for Score >= 60
                    // if (Score < 60) // Fifth if can be more optimized with only else statement
                    {
                        grade = 'F';
                    }
    cout << "Your semester total rounded percentage: ";
    cout << Score <<'\n';
    cout << "Your grade for this semester: ";
    cout << grade << '\n';
    
    return 0;
}


int main2()
{
    //if statement
    // ask for semester total out of 100
    // rounded percentage
    int Score;
    char grade = 'U';
    cout << "Enter semester percentage rounded to whole number: ";
    cin >> Score;
    
    if (Score >= 90)
    {
            grade = 'A';
        
    }
    if (90>Score && Score >= 80)
    {
            grade = 'B';
    }
    
    if (80>Score && Score >= 70)
    {
        grade = 'C';
    }
    
    if (70>Score && Score >= 60)
    {
        grade = 'D';
    }
    
    if (Score < 60)
    {
        grade = 'F';
    }

    cout << "Your semester total rounded percentage: ";
    cout << Score <<'\n';
    cout << "Your grade for this semester: ";
    cout << grade << '\n';
    
    return 0;
}
