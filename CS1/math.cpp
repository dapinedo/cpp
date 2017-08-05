//
//  math.cpp
//  2.21
//
//  Created by Daniel Pinedo on 2/21/17.
//  Copyright © 2017 Daniel Pinedo. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // cmath has many math functions already written for you
    
    // sqrt computes square root of what is passed to it
    double val = 4.9;
    double rootValue = 0.0;
    rootValue = sqrt(val);
    cout << "(" << val << ")^0.5 = " << rootValue << '\n';
    
    // pow function computes base/exponent
    // double powerValue = pow(base, exponent);
    double base = 2.01;
    double exponent = 3.02;
    double powerValue = pow(base, exponent);
    cout<< "(" << base << ")^" << exponent << " = " << powerValue << '\n';
    
    return 0;
}
