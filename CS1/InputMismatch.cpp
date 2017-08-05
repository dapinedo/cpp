//
//  InputMismatch.cpp
//  3.2
//
//  Created by Daniel Pinedo on 3/2/17.
//  Copyright © 2017 Daniel Pinedo. All rights reserved.
//

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main () /* getline gotcha & Solution */
{
    //use of getline right after cin >> may not allow successful getline input
    int ageOnLastBirthday;
    cout << "Enter your age on last birthday [whole positive number]: ";
    cin >> ageOnLastBirthday;
    
    cout << "You inputted " << ageOnLastBirthday << endl;
    
    // SOLUTION: Clear the buffer because next input is getline - use cin.ignore
    // cin.ignore(1000, '\n'); // ignore up to 1000 previous characters, and then proceed
    
    string wholeLine;
    cout << "Enter your complete street address: ";
    //cin >> wholeLine;
    getline(cin, wholeLine);
    cout << "You inputted: " << wholeLine << endl;
    
    /*
    Enter key after input of age is still in buffer and getline gets that
    and does not  stop for user input for address - see cin.ignore in comments above
    */
    
    return 0;
}

int main3() /* what if I want to input a line with whitespace? */
{
    string wholeLine;
    cout << "Enter your complete street address: ";
    //cin >> wholeLine;
    getline(cin, wholeLine);
    cout << "You inputted: " << wholeLine << endl;
    
    return 0;
    
    /*
    output 1: When cin >> is used to get user input
    enter your complete streett address: only first token is retrieved
     
    output 2
    getline is used instead of cin >> whole line of user input is stored.
    */
}


int main2() /* nature of cin */
{
    double var1, var2, var3;
    cout << "Enter three decimal numbers (with mantissa) with space separating them: ";
    cin >> var1;
    cin >> var2;
    cin >> var3;
    
    cout << "You entered: "
    << var1 << " " << var2 << " " << var3 << endl;
    
    return 0;
    
    /*
        >> operator ignores leading whitespace and only grabs tokem after the whitespace and stores in the variable on the right side of operator >>.
        output example from the above program is below:
    */
}



int main1() /* input mismatch causes unexpected behaviors */
{
    int ageOnLastBirthday;
    cout << "Enter your age on last birthday [whole positive number]: ";
    cin >> ageOnLastBirthday;
    
    cout << "You inputted " << ageOnLastBirthday << endl;
    
    //cin.ignore(1000, endl); // Assume there is garbage in the buffer
    //cin.clear(); // Clear buffer given cin.ignore
    
    double GPA;
    cout << "Enter current GPA: ";
    cin >> GPA;
    
    cout << "You inputted: " << GPA << endl;
    
    return 0;
}
