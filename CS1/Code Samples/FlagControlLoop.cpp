/*
Satish Singhal
Class: CS1
Date:4/4/17
Program Name: Flag Control Loop
*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/*
Computation of monthly average profit
profit +ve
Loss -ve
Break Even 0
No sentinel value available.
We use flag control loop
*/
int main()
{
	cout << fixed << showpoint << setprecision(2);
	double sum = 0.0; // All accumulators must be initialized
	size_t numMonths = 0;// All counters must be initialized
	double MonthProfitOrLoss;
	bool done = false;// Initialization of loop condition

	while (!done)// loop test
	{
		cout << "Enter monthly profit or loss{-ve sign}[xx.xx]: ";
		cin >> MonthProfitOrLoss;
		sum += MonthProfitOrLoss;
		numMonths++;
		cout << "More data? Enter 0 to continue or 1 to stop: ";
		cin >> done;// loop update
	}

	if (numMonths > 0)
	{
		double realAverage = sum / numMonths;

		if (realAverage>0.0)
		{
			cout << "Your average monthly profit: $"
				<< realAverage << endl;
		}
		else if (realAverage<0.0)
		{
			cout << "Your average monthly Loss: $"
				<< realAverage << endl;
		}
		else
		{
			cout << "You broke even." << endl;
		}
	}
	


	return 0;
}
/*
Enter monthly profit or loss{-ve sign}[xx.xx]: 1000.69
More data? Enter 0 to continue or 1 to stop: 0
Enter monthly profit or loss{-ve sign}[xx.xx]: 2000.55
More data? Enter 0 to continue or 1 to stop: 0
Enter monthly profit or loss{-ve sign}[xx.xx]: 23000.87
More data? Enter 0 to continue or 1 to stop: 1
Your average monthly profit: $8667.37

Example 2

*/