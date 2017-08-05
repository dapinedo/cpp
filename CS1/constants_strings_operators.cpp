//
//  constants_strings_operators.cpp
//  2.21
//
//  Created by Daniel Pinedo on 2/21/17.
//  Copyright © 2017 Daniel Pinedo. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

const double PI = 3.14159;
const string Line_Of_Asterisks = "**********************";

int main()
{
    
    // uncommenting below 2 lines will be a compile error because const cannot be modified
    // PI = 22.0 / 7;
    // string name = "John" + "Doe";
    
    cout << 22.2 << endl; // 22.2 is a literal constant, Singhal Ch. 3 p. 36
    
    string first = "John ";
    string full = first + "Doe";
    
    // '/' is polymorphic, Singhal Ch. 4
    // dividing with one or more floating point number(s) yields a mantissa
    cout << 11.0 / 4 << '\n';
    
    // dividing with integral number(s) truncates the mantissa
    cout << 11 / 4 << '\n';
    
    // modulus with integral number(s) provides mantissa as remainder
    cout << 11 % 4 << '\n';
    //cout << 11.0 % 4 << '\n'; // modulus cannot be used with floating point numbers - use fmod;
    
    return 0;
}
