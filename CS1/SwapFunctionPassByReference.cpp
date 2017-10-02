//
//  SwapFunctionPassByReference.cpp
//  4.6
//
//  Created by Daniel Pinedo on 4/6/17.
//  Copyright © 2017 Daniel Pinedo. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

void Swap1(string name1 /*incoming*/, string name2 /*incoming*/);
void Swap2(string & name1 /*incoming and outgoing*/, string & name2 /*incoming and outgoing*/);

int main()
{
    string nm1 = "Zack";
    string nm2 = "Adam";
    cout << "Before calling the Swap1 or SWap2 Functions: " << endl
    << "The name nm1 = " << nm1 << endl
    << "The name nm2 = " << nm2 << endl;
    Swap1(nm1, nm2);
    cout << "After calling the Swap1 Function: " << endl
    << "The name nm1 = " << nm1 << endl
    << "The name nm2 = " << nm2 << endl;
    cout << "Memory address of nm1 in main function: "
    << (long)(&nm1) << endl;
    cout << "Memory address of nm2 in main function: "
    << (long)(&nm2) << endl;
    Swap2(nm1, nm2);
    cout << "After calling the Swap1 Function: " << endl
    << "The name nm1 = " << nm1 << endl
    << "The name nm2 = " << nm2 << endl;
    cout << "Memory address of nm1 in main function: "
    << (long)(&nm1) << endl;
    cout << "Memory address of nm2 in main function: "
    << (long)(&nm2) << endl;
    
    return 0;
}

// Pass by value
// swaps the value within the function only, but does not pass values to memory
void Swap1(string name1, string name2)
{
    string temp = name1; // save one
    name1 = name2;
    name2 = temp;
    cout << "Memory address of name1 in Swap1 function: "
    << (long)(&name1) << endl;
    cout << "Memory address of name2 in Swap1 function: "
    << (long)(&name2) << endl;
}
// Pass by reference
// swaps the memory allocation value, which passes from function to calling block
 void Swap2(string & name1, string & name2)
{
    string temp = name1; // save one
    name1 = name2;
    name2 = temp;
    cout << "Memory address of name1 in Swap1 function: "
    << (long)(&name1) << endl;
    cout << "Memory address of name2 in Swap2 function: "
    << (long)(&name2) << endl;
}
