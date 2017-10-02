//
//  FloatingPointProblems.cpp
//  3.16
//
//  Created by Daniel Pinedo on 3/16/17.
//  Copyright © 2017 Daniel Pinedo. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int IntAverage = (16 + 16 + 16) / 3;
    
    if (IntAverage == 16) {
        cout << "Integral type (16 + 16 + 16) / 3 = " << IntAverage << '\n';
    }
    
    long double DoubleAverage = (1.6 + 1.6 + 1.6) / 3;
    
    cout << setprecision(20) << scientific
         << "Long Double of (1.6 + 1.6 + 1.6) / 3 should be 1.6. Yours is: " << DoubleAverage << '\n';
    
    if (abs(DoubleAverage - 1.6) < 0.0000000000001) {
        cout << setprecision(20)
             << "Your calculation met the set tolerance of 0.0000000000001" << '\n';
    }
    else {
        cout << setprecision(20)
        << "Your calculation did not meet the set tolerance of 0.0000000000001" << '\n';

    }
    return 0;
}
