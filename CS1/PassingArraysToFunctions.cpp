//
//  PassingArraysToFunctions.cpp
//  5.2
//
//  Created by Daniel Pinedo on 5/2/17.
//  Copyright © 2017 Daniel Pinedo. All rights reserved.
//

#include <iostream>
using namespace std;

const int MAX = 5; // Maximum physical size of array

//optional way for function prototype - you can leave out parameter name
void swap1(int & left, int & right);
void swap2(int num1[], int num2[], size_t len); //arrays automatically pass by reference
void print(const int arr[], size_t len);

int main()
{
    
    int val1 = 5;
    int val2 = 10;
    cout << "Before passing to swap1:\n"
         << "val1 = " << val1 << '\n'
         << "val2 = " << val2 << endl;
    swap1(val1, val2);
    cout << "After passing to swap1:\n"
         << "val1 = " << val1 << '\n'
         << "val2 = " << val2 << endl;
    
    //reset values of val1 and val2
    val1 = 5;
    val2 = 10;
    int arr1[1];
    int arr2[2];
    arr1[0] = val1;
    arr2[0] = val2;
    cout << "Before passing to swap2:\n"
         << "arr1[0] = " << arr1[0] << '\n'
         << "arr2[0] = " << arr2[0] << endl;
    swap2 (arr1, arr2, 1); // NOTE: only array name is passed as argument to function
    cout << "After passing to swap2:\n"
         << "arr1[0] = " << arr1[0] << '\n'
         << "arr2[0] = " << arr2[0] << endl;
     
    
    // example of print function for array
    //int values[MAX] = {}; // 0 is initialized in all array elements at array declaration
    int values[MAX] = {1, 6, 2, 5, 19}; // full initialization
    print(values, MAX);

    return 0;
}

void swap1(int & left, int & right)
{
    int buffer = left;
    left = right;
    right = buffer;
}

void swap2(int num1[], int num2[], size_t len)
{
    if (len>0)
    {
        int buffer = num1[0];
        num1[0] = num2[0];
        num2[0] = buffer;
    }
    else
    {
        cout << "Array length cannot be negative" << endl;
    }
    return;
}

void print(const int arr[], size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}


/* OUTPUT OF PROGRAM BELOW
 
 Before passing to swap1:
 val1 = 5
 val2 = 10
 After passing to swap1:
 val1 = 10
 val2 = 5
 Before passing to swap2:
 arr1[0] = 5
 arr2[0] = 10
 After passing to swap2:
 arr1[0] = 10
 arr2[0] = 5
 Program ended with exit code: 0

 */
