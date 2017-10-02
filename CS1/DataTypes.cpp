//
//  DataTypes.cpp
//  2.16 - Data Types
//
//  Created by Daniel Pinedo on 2/16/17.
//  Copyright © 2017 Daniel Pinedo. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int age;
    cout << "Type your age on last birthday and then press enter key: ";
    cin >> age;
    cout << "Your age: " << age << '\n';
    
    double GPA;
    cout << "Enter your GPA: ";
    cin >> GPA;
    
    string name;
    char MidInitial;
    cout << "Enter your first name only: ";
    cin >> name;
    cout << "Enter your middle initial only: ";
    cin >> MidInitial;
    
    cout << "Hello " << name << ' ' << MidInitial << '\n';
    cout << "Your GPA: " << GPA << '\n';
    cout << "On next birthday, you will be: " << (age + 1)
        << " years old \n";
    
    return(0);

}

/*
Type your age on last birthday and then press enter key: 40
Your age: 40
Enter your GPA: 4.0
Enter your first name only: Daniel
Enter your middle initial only: A
Hello Daniel A
Your GPA: 4
On next birthday, you will be: 41 years old
Program ended with exit code: 0
*/
