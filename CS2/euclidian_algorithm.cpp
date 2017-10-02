#include <iostream>
#include <cmath>

using namespace std;

// function prototype
int gcd (int a , int b);

int main()
{
    cout << "This test will now run 8 times for Euclidian algorithm of " 
        << "Greatest Common Denominator" << '\n';
    for (size_t i = 0; i < 8; i++) {
        cout << "Enter value for Number 1: ";
        int num1;
        cin >> num1;
        num1 = abs(num1);
        cout << "Enter value for Number 2: ";
        int num2;
        cin >> num2;
        num2 = abs(num2);
        cout << " Greatest Common Denominator: " << gcd(num1, num2) << '\n';
    }
}

int gcd (int a , int b)
{
    if ( b == 0 ) { //step 1
        return a;
    }
    else if (a >= b && b > 0) { //step 2
        return gcd (b , a%b); // only works if a >= b
    }
    else { //step3
        return gcd (b , a);        // if a < b switch them.
    }
}

/*
Example of throw/try/catch

double getMeanofBalances() const
{
    if (len == 0)
        throw "list is empty"
    else
        // do code
}

main ()
{
    BankAccountList BAL;
    double mean;
    try {
        mean = BAL.getMeanofBalances();
        cout << mean << endl;
    }
    catch {
        cout << "list is empty.";
    }
}
