//
//  pre-postfix-compound-ops.cpp
//  2.28
//
//  Created by Daniel Pinedo on 2/28/17.
//  Copyright © 2017 Daniel Pinedo. All rights reserved.
//

#include <iostream> // cin / cout functions
#include <string> // string functions
#include <iomanip> // setprecision(); setw(); functions
using namespace std;

int main()
{
    // -- increment operator example
    int val = 5;
    ++val;  // add 1 to val now
    cout << val << '\n';
    cout << (val++) << '\n'; // complete operation cout first then add 1 to val after
    cout << val << '\n';
    
    // -- decrement operator works exactly the same way
    --val;
    cout << val << '\n'; // prints 6
    cout << (val--) << '\n'; // prints 6 then subtracts 1
    cout << val << '\n'; // prints 5
    
    // -- compound operators
    {
        int Val = 5;
        int Num = 10;
        Val += Num; // Val = Val + Num;
        cout << Val << '\n';
        
        string Name1 = "John";
        string Name2 = " Doe";
        Name1 += Name2;
        cout << Name1 << '\n'; // prints John Doe
        
        Val = 5;
        Num = 10;
        Val *= Num; // Val = Val * Num;
        cout << Val << '\n'; // prints 50
    }
    // -- input / output manipulation
    {
        // USE OF FIXED
        double data1 = 0.000000007;
        cout << data1 << '\n'; // Without use of fixed, output is in scientific notation
        
        // to remove scientific notation ouput use fixed
        cout << fixed;
        cout << data1 << '\n';
        
        // If fixed is not applied then display behavior of
        // a whole decimal number is like an integer
        double data2 = 10.0;
        cout << data2 << '\n'; // this will show 10 if line 54 is commented out
        
        // Formatting of decimal points or mantissa in floating point numbers
        // requires setprecision();
        double a, b, c; // three sides of a box
        a = 1.55;
        b = 3.987;
        c = 2.9;
        double volume = a*b*c;
        cout << setprecision(3); // round the output after this line to 3 decimal places
        cout << volume << '\n';
        cout << setprecision(5); // round the output after this line to 5 decimal places
        cout << volume << '\n';
    }
    // IOMANIP FUNCTIONS
    {
    // Manipulator setw
        cout << "123456789012345678901234567890"; // use this to double check setw spaces/margins
        cout << setw(25) << "Name: " << endl; // endl does what '\n' does but it also clear the buffer
        cout << setw(25) << "John Doe" << endl; // this column is right aligned by default when using setw()
        cout << left << setw(25) << "Name: " << endl;
        cout << setw(25) << "John Doe" << endl; // this column is left aligned

    }
    
    return 0;
}
