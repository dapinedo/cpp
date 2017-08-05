//
//  StudentStruct1.cpp
//  5.9
//
//  Created by Daniel Pinedo on 5/9/17.
//  Copyright © 2017 Daniel Pinedo. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

// constants below

// structs below - no memory allocation
struct Student {
    string firstname;
    string lastname;
    int age;
    double gpa;
};

// function prototypes after struct definition

// Function getStudent that fills a student struct and returns it to the caller function
Student getStudent();
void print(const Student & st);
// getStudent from file
Student getStudent(ifstream & in);
void openFile(ifstream & input);

int main()
{
    ifstream in;
    
    openFile(in);
    Student S1 = getStudent(in);
    cout << "Now printing S1 that we populated from inout file." << endl;
    print(S1);
    
    in.close();
   
    return 0;
}

Student getStudent()
{
    Student Temp;
     // Member / field write access mechanism
    cout << "Enter student's first name: ";
    cin >> Temp.firstname;
    cout << "Enter student's last name: ";
    cin >> Temp.lastname;
    cout << "Enter student's age on last birthday: ";
    cin >> Temp.age;
    cout << "Enter student's GPA: ";
    cin >> Temp.gpa;
    
    return Temp;
}

void print(const Student & st)
{
    cout << fixed << showpoint << setprecision (2);
    cout << "Student Name: " << st.firstname << ' ' << st.lastname << endl
    << "Student Age: " << st.age << " years." << endl
    << "Student GPA: " << st.gpa << endl;
    
    return;

}

Student getStudent(ifstream & in)
{
    Student Temp;
    // file structure is below
    // John Doe 22 3.2
    // First name last name age GPA
    in >> Temp.firstname >> Temp.lastname >> Temp.age >> Temp.gpa;
    return Temp;
}

void openFile(ifstream & input)
{
    bool done = false;
    string In_File = "";
    //Loop to get the name of a file that truly exists
    // and check that file is not empty.
    
    while (!done)
    {
        input.clear();
        cout << "Please input the name of the data file to be read : ";
        getline(cin, In_File);
        cout << "The file name entered is : " << In_File << endl;
        input.open(In_File);
        
        if (input.fail()){
            cout << "The file " << In_File << " does not exist.\n";
            continue;
        }
        else
        {
            input.peek();//peek at the input file
            
            if (input.eof()){//If file is empty then the function eof() returns true
                cout << "The file has no data in it\n";
                input.close();
                continue;
            }
            else
            {
                done = true;
            }
        }
    }//end of while loop
    cout << "File " << In_File << " opened and has data in it." << endl;
}
