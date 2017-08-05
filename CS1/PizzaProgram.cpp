//
//  PizzaProgram.cpp
//  3.14
//
//  Created by Daniel Pinedo on 3/14/17.
//  Copyright © 2017 Daniel Pinedo. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    
    // else if use for menu items and cost calculation
    
    // Input
    char code, cheeseCode;
    int flourCode, toppingCode;
    cout << "Please enter your first name only: ";
    string name;
    cin >> name;
    cout << "Hello " << name  << ", welcome to Bart's pizza, we will now take your order \n";
    cout << "Please enter the pizza size [S]mall, [M]edium, [L]arge, e[X]tra large: ";
    cin >> code;
    code = toupper(code);
    bool FlagBaseCode = (code == 'S' || code == 'M' || code == 'L' || code == 'X');
    
    // Analysis
    if (FlagBaseCode /* && FlagFlourCode && FlagToppingCode */)
    {
        double baseCost;
        // double incrFlour;
        // double incrTopping;
        
        if (code == 'S')
        {
            baseCost = 2.0;
        }
        else if (code == 'M')
        {
            baseCost = 4.0;
        }
        else if (code == 'L')
        {
            baseCost = 6.0;
        }
        else
        {
            baseCost = 8.0;
        }
        
        /* if flourCode ... if toppingCode */
    }
    
    return 0;
}
