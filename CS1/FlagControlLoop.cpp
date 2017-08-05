//
//  FlagControlLoop.cpp
//  4.3
//
//  Created by Daniel Pinedo on 4/4/17.
//  Copyright © 2017 Daniel Pinedo. All rights reserved.
//

#include <iostream>
#include <iomanip>

using namespace std;

/*
 Profit and Loss Statement
 +ive = profit
 -ive -=loss
 0 = break even
 
 Flag Control Loop is used since there is no sentinel value available
 */

int main()
{
    cout << fixed << showpoint << setprecision(2);
    double sum = 0.0; // all accumulators must be initialized
    size_t numMonths = 0; // all counters must be initialized
    double MonthProfitOrLoss;
    bool done = false;
    
    while (!done) // loop test
    {
        cout << "Enter monthly profit or loss{-ve sign}{xx.xx]: ";
        cin >> MonthProfitOrLoss;
        sum += MonthProfitOrLoss;
        numMonths++;
        cout << "More data? Enter 0 to continue or 1 to stop: ";
        cin >> done; // loop update
    }
    if (numMonths > 0)
    {
        double realAverage = sum / numMonths;
        if (realAverage > 0.0)
        {
            cout << "Your average monthly profit: $"
                 << realAverage << endl;
        }
        else if (realAverage < 0.0)
        {
            cout << "Your average monthly loss: $"
            << realAverage << endl;
        }
        else
        {
            cout << "You broke even";
        }
    }
    return 0;
}
