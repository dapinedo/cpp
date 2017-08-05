/*
 Author: Satish Singhal
 Date: 2/23/2017
 Project: Loan payment
 Compiler: Visual Studio 2013
 Operating System: Windows 7
 */

/*
 Data Input:
 variable Data Type Remarks
 loan     double
 rate     double    rate is monthly interest rate in decimalized fraction
 numpmt   int       Number of monthly payments
 
 qIf user is asked to enter rate as annual interest rate
 on the loan in percent
 rate = userentry/1200
 
 Data Output
 monthlyPayment double
 
 Analysis
 Math Form is below
 monthlyPayment = loan ( rate + rate/((1+rate)^numpmt - 1 ))
 C++ form is below
 monthlyPayment = loan * ( rate + rate/(pow(1+rate, numpmt) - 1 ))
 
 Algorithm
 Aprroximate Algorithm is below
 1. declare variables
 2. Print the message greeting user.
 3. Prompt user to input loan amount
 4. Accept and store into loan variable
 5. Ask user for annual interest rate on loan in percent
 6. Accept and store in rate variable
 7. rate = rate/1200
 8. Prompt user to input number of monthly payments
 9. Accept and store in numpmt variable
 10. monthlyPayment = loan * ( rate + 1/(pow(1+rate, numpmt) - 1 ))
 11. output raw monthly payment
 12. Use following algorithm to round monthly payment to nearest penny.
 algorithm for rounding to nearest penny with the following rule
 0.5 or higher fractional penny up rounds to 1 penny
 but <0.5 penny down rounds to zero
 1. Multiply monthlyPayment by 100 so you get total pennies
 2. double TotalPennies = monthlyPayment *100
 3. add 0.5 to TotalPennies
 4. round TotalPennies to integer data type
 5. Divide by 100 to get the dollars
 6. Take Modulus by 100 ro get cents
 13. Print dollars and cents for mothly payment
 14. Good bye to user
 
 */
#include <iostream>
#include <cmath> // Needed for math functions
using namespace std;

int main()
{
    //1. declare variables
    double loan;
    double rate;
    int numpmt;
    double monthlyPayment;
    //2. Print the message greeting user.
    cout<<"Welcome to our bank. We will loan you money. "<<endl;
    //data input
    //3. Prompt user to input loan amount
    cout<<"Enter loan amount you wish [xx.yy]: ";
    //4. Accept and store into loan variable
    cin>>loan;
    //5. Ask user for annual interest rate on loan in percent
    cout<<"Enter annual inetrest rate on loan [for example for 7.2% enter 7.2]: ";
    //6. Accept and store in rate variable
    cin>>rate;
    /*7*/rate = rate / 1200;
    //8. Prompt user to input number of monthly payments
    cout<<"Enter number of months that you are taking the loan for [whole number only] : ";
    //9. Accept and store in numpmt variable
    cin>>numpmt;
    
    /*10*/monthlyPayment = loan * ( rate + rate/(pow(1+rate, numpmt) - 1 )) ;
    //11. output raw monthly payment
    cout<<"The raw value of monthly payment = $"<<monthlyPayment<<endl;
    /*
     algorithm for rounding to nearest penny with the following rule
     0.5 or higher fractional penny up rounds to 1 penny
     but <0.5 penny down rounds to zero
     1. Multiply monthlyPayment by 100 so you get total pennies
     2. double TotalPennies = monthlyPayment *100
     3. add 0.5 to TotalPennies
     4. round TotalPennies to integer data type
     5. Divide by 100.0 to get the rounded monthly payment
     */
    double TotalPennies = monthlyPayment *100;
    //Meaning of expression such as (int)(TotalPennies + 0.5) is
    //We are telling computer that (TotalPennies + 0.5) may be of
    //double type, but force it to be int type for us
    int roundedPennies = (int)(TotalPennies + 0.5);
    /*
     Second syntax for casting is as follows:
     int roundedPennies = static_cast<int>(TotalPennies + 0.5);
     */
    int dollars = roundedPennies / 100;
    int cents = roundedPennies % 100;
    //int x = 8.2 % 4; // Compile error. Modulus is not allowed with floating point numbers
    //13. Print dollars and cents for mothly payment
    cout << "Your monthly payments will be: $" << dollars << " and "
    << cents << " cents " << endl;
    //14. Good bye to user
    cout<<"Good bye"<<endl;
    return 0;
}
/*
 Welcome to our bank. We will loan you money.
 Enter loan amount you wish [xx.yy]: 10000.00
 Enter annual inetrest rate on loan [for example for 7.2% enter 7.2]: 8.1
 Enter number of months that you are taking the loan for [whole number only] : 60
 The raw value of monthly payment = $203.243
 Your monthly payments will be: $203 and 24 cents
 Good bye
 */
