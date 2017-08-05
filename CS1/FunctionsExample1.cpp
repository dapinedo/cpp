//
//  FunctionsExample1.cpp
//  4.3
//
//  Created by Daniel Pinedo on 4/4/17.
//  Copyright © 2017 Daniel Pinedo. All rights reserved.
//

#include <iostream>

using namespace std;
// Any constants
// All function prototypes - data names in argument list are ignored by compiler
double square(double val); // header defined is called prototype, order of functions then does not matter
double cube(double data);

double square(double val)
{
    double temp = val*val;
    return temp;
}

double cube (double data)
{
    double temporary = square(data)*data;
    return temporary;
}

// for every variable called in main, a copy of variables passed to functions is made

int main()
{
    double value;
    cout << "Enter the number which needs to be squared and cubed: ";
    cin >> value;
    double sqrVal = square(value);
    cout << value << "^2 = " << sqrVal << endl;
    double cubeVal = cube(value);
    cout << value << "^3 = " << cubeVal << endl;
    
    return 0;
}
