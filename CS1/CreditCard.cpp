/*
Daniel Pinedo
CS1
Assignment #10
June 6, 2017
*/
//Grade: 27/27
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const char SEP = '*';
const int SEP_NUM = 60;

struct CreditCard
{
	string CCN;
	string LastName;
	string FirstName;
	double balance;
	double CreditLimit;

	/*
	Item 1: Complete the body of default constructor such that the various data members are set to following values
	when the default constructor is called:
	Data Member Name		Value set by default Constructor
	CCN						Credit card number not set
	LastName 				Last name not set
	FirstName 				First name not set
	balance 				0.0
	CreditLimit 			1500.00
	*/

	CreditCard()
	{
		CCN = "Credit card number not set";
		LastName = "Last name not set";
		FirstName = "First name not set";
		balance = 0.0;
		CreditLimit = 1500.00;
	}

	/*
	Item 2: Complete the body of explicit constructor that constructor arguments initialize the corresponding and mapping
	struct data members. The table below gives as to which data member is initialized by which constructor argument
	Data Member Name		Value set by explicit Constructor
	CCN						cardNum
	LastName 				lname
	FirstName 				fname

	There are no constructor arguments to initialize balance and CreditLimit. They are set to same values as the default
	constructor as below:
	balance                 0.0
	CreditLimt 				1500.00
	*/

	CreditCard(string fname, string lname, string cardNum)
	{
		CCN = cardNum;
		LastName = lname;
		FirstName = fname;
		balance = 0.0;
		CreditLimit = 1500.00;
	}

	//get functions
	string getCreditCardNumber()
	{
		return CCN;
	}
	string getFirstName()
	{
		return FirstName;
	}
	string getLastName()
	{
		return LastName;
	}
	string getFullName()
	{
		return FirstName + ' ' + LastName;
	}
	double getBalance()
	{
		return balance;
	}
	double getCreditLimit()
	{
		return CreditLimit;
	}

	/*
	Item 3: Write the body of member function ChargeToCard, which takes money as argument. money is the amount of money
	the credit card holder wishes to charge in a purchase transaction. This function MUST do a conditional check
	to ascertain that adding the charge equal to money would not exceed customer's credit limit. Another way of saying this
	is that argument money must be less than or equal to available credit to authorize the purchase, else the transaction
	must be declined. This is similar in nature to the withdraw function for BankAccount struct you did. Sample output from
	the program may give some clue as how this function may be working.
	*/

	void ChargeToCard(double money)
	{
		if (CreditLimit >= (balance + money))
		{
			balance += money;
		}
		else
		{
			cout << "Purchase is higher than current credit limit of $"
				<< getCreditLimit() << ". Purchase declined." << endl;
		}
	}

	void makePaymentToCard(double money)
	{
		balance -= money;
	}

	void print()
	{
		cout << fixed << showpoint << setprecision(2);
		cout << "Credit Card Number: " << getCreditCardNumber() << endl
			<< "Name: " << getFullName() << endl
			<< "Amount owed: $" << getBalance() << endl
			<< "-------------------------------------------" << endl;
	}
};

/*
You can lookup Singhal ebook chapter 12 to see how a selection sort function has been done for
sorting struct arrays. That may provide clues as how to do the bubble sort function here.

Item 4: Write a bubbleSort function (blank body provided later), which sorts the array ccArr passed to it based on the
flag value it gets. len is the logical length or length of interest. flag values determine the sorting basis as follows:
flag = 1 sort based on last name
flag = 2 sort based on CCN
flag = 3 sort based on balance
*/

void bubbleSort(CreditCard ccArr[], int flag, int len);

/*
Item 5: You can look at Singhal ebook chapter 12 to see details of linear search.
Write a LinearSearch function (blank body provided later) that takes a creditCard array ccArr, a flag, length of interest len, and a CreditCard
object CC as arguments. flag value specifies the search basis as below:
if flag == 1 search based on last name
if flag == 2 search based on credit card number
If flag == 1 then it's caller's responsibility that last name field of object CC is populated.
if flag == 2 then it's caller's responsibility that credit card number field of CC object is populated.
The function returns -1 if the item is not found, otherwise return index of the array  where item is located.
*/
int LinearSearch(const CreditCard ccArr[], const CreditCard CC, int flag, int len);

void print(CreditCard arr[], int len);

const int MAX = 100;

int main()
{
	//Instructor code that is required. Do not delete!!!!
	CreditCard CC1("JIM", "JONES", "56738");
	CC1.ChargeToCard(200.99);
	CreditCard CC2("ADAM", "ASHLEY", "12345");
	CC2.ChargeToCard(2000.00);
	CreditCard CC3("BERTHA", "MAPOS", "34567");
	CC3.ChargeToCard(800.91);
	CreditCard CC4("LISA", "BRAVE", "98765");
	CC4.ChargeToCard(1001.23);
	CreditCard CC5("WILLY", "NILLY", "23413");
	CC5.ChargeToCard(700.00);
	CreditCard CC6("JILL", "QUIRK", "67895");
	CC6.ChargeToCard(1400.91);
	CreditCard CardArray[MAX];
	CardArray[0] = CC1;
	CardArray[1] = CC2;
	CardArray[2] = CC3;
	CardArray[3] = CC4;
	CardArray[4] = CC5;
	CardArray[5] = CC6;
	//End of instructor code

	/*
	Item 6:
	Write a menu driven program with following menu items and their functionality. [The sample output gives you
	clue as how this would function].
	1. Print credit card list in its current state to console.
	2. Sort credit card list based on last name.
	3. Sort credit card list based on credit card number.
	4. Sort credit card list based on balance.
	5. Search credit card list based on customer last name.
	6. Search credit card list based on credit card number.
	7. Exit.
	*/

	cout << fixed << showpoint << setprecision(2);
	bool loopflag = 1;
	while (loopflag)
	{
		int choice = 7;
		cout << string(SEP_NUM, SEP) << endl;
		cout << "Enter the item number you want from the menu at the prompt and hit Enter" << endl;
		cout << " 1. Print credit card list in its current state to console." << endl;
		cout << " 2. Sort credit card list based on last name." << endl;
		cout << " 3. Sort credit card list based on credit card number." << endl;
		cout << " 4. Sort credit card list based on balance." << endl;
		cout << " 5. Search credit card list based on customer last name." << endl;
		cout << " 6. Search credit card list based on credit card number." << endl;
		cout << " 7. Exit." << endl;
		cout << "Enter choice: ";
		cin >> choice;
		cout << string(SEP_NUM, SEP) << endl;
		switch (choice)
		{
			case 1:
			{
				print(CardArray, 6);
			}

			case 2:
			{
				bubbleSort(CardArray, 1, 6);
				cout << "Task Completed" << endl;
				break;
			}

			case 3:
			{
				bubbleSort(CardArray, 2, 6);
				cout << "Task Completed" << endl;
				break;
			}

			case 4:
			{
				bubbleSort(CardArray, 3, 6);
				cout << "Task Completed" << endl;
				break;
			}

			case 5:
			{
				cout << "Enter Last Name to search for: ";
				string searchLast;
				cin >> searchLast;
				CreditCard sLast("Not set", searchLast, "12345");
				int found = LinearSearch(CardArray, sLast, 1, 6);
				if (found >= 0)
				{
					cout << "last name found in index number " << found << endl;
					CardArray[found].print();
				}
				else
				{
					cout << "Sorry, last name not found" << endl;
				}
				break;
			}

			case 6:
			{
				cout << "Enter Credit Card Number to search for: ";
				string searchCCN;
				cin >> searchCCN;
				CreditCard sCCN("Not set", "Not set", searchCCN);
				int found = LinearSearch(CardArray, sCCN, 2, 6);
				if (found >= 0)
				{
					cout << "Credit Card Number found in index number " << found << endl;
					CardArray[found].print();
				}
				else
				{
					cout << "Sorry, Credit Card Number not found" << endl;
				}
				break;
			}

			case 7:
			{
				loopflag = 0;
				break;
			}

			default:
			{
				cout << "bad input. Try again." << endl;
			}
		} // end switch
		cout << string(SEP_NUM, SEP) << endl;
	} // end while(loopflag)

	cout << "Goodbye!" << endl;
	return 0;

}//end of main function

void print(CreditCard arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		arr[i].print();
	}
}//end of print function

int LinearSearch(const CreditCard ccArr[], const CreditCard CC, int flag, int len)
{
	int foundAt = -1;
	bool found = false;
	switch (flag)
	{
		case 1:
		{
			for (int i = 0; !found && i < len; i++)
			{
				if (CC.LastName == ccArr[i].LastName)
				{
					found = true;
					foundAt = i;
				}
			}
		break;
		}
		case 2:
		{
			for (int i = 0; !found && i < len; i++)
			{
				if (CC.CCN == ccArr[i].CCN)
				{
					found = true;
					foundAt = i;
				}
			}
			break;
		}
	} // end switch
	return foundAt;
}

void bubbleSort(CreditCard ccArr[], int flag, int len)
{
	switch (flag)
	{
	case 1:
	{
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len - i - 1; j++)
			{
				if (ccArr[j].LastName > ccArr[j + 1].LastName)
				{
					string temp = ccArr[j].LastName;
					ccArr[j].LastName = ccArr[j + 1].LastName;
					ccArr[j + 1].LastName = temp;
				}
			}
		}
		break;
	}
	case 2:
	{
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len - i - 1; j++)
			{
				if (ccArr[j].CCN > ccArr[j + 1].CCN)
				{
					string temp = ccArr[j].CCN;
					ccArr[j].CCN = ccArr[j + 1].CCN;
					ccArr[j + 1].CCN = temp;
				}
			}
		}
		break;
	}
	case 3:
	{
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len - i - 1; j++)
			{
				if (ccArr[j].balance > ccArr[j + 1].balance)
				{
					double temp = ccArr[j].balance;
					ccArr[j].balance = ccArr[j + 1].balance;
					ccArr[j + 1].balance = temp;
				}
			}
		}
	}
	} // end switch
}
