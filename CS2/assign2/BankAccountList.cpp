/* Daniel Pinedo
 * CS 2 - Section 0140
 * assignment: 2, part 1
 * Grade, Part 1 prep : OK 
 * Grade, Part 1      : 9.5/10
 * Grade, Part 2 prep : 
 * Grade, Part 2      :
 * part 1 due: Sept. 18, 2017
 * part 2 due: Sept. 25, 2017
 * file: BankAccountList.cpp
 */
 
 #include "BankAccountList.h"
 
 // DEFAULT CONSTRUCTOR
BankAccountList::BankAccountList() : 
    num_of_elements(0),
    list_state(0) 
{
}
// MUTATORS
	
// Adds account BA to Bank Account List. Informs user if list is full. 
// Must have unique account number.
// Sets list_state to 0.
void BankAccountList::addAccount(const BankAccount &BA)
{
    if (num_of_elements == MAX) {
		cout << "The list is full." << endl;
	}
	// Find if BA is already in the list or not
	// add if not there.
	bool found;
	int whereFound = 0;
	found = findAccount(BA.getAccountNumber(), whereFound);

	if (!found) { // not there. add it
		List[num_of_elements] = BA;
		num_of_elements++;
		list_state = 0;// Because we may be adding to a sorted list
	}
	else {
		cout << "Account number: " << BA.getAccountNumber() << " already exists." << endl;
	}
}
	
// Runs findAccount ACCESSOR. If found returns true and deletes account.
// Otherwise returns false. Does not change list_state.
bool BankAccountList::deleteAccount(const string & actNum)
{
    bool deleted = false;
	if (!isEmpty()) {
		// find out if actNum is in the array
		int index = 0;
		bool found = findAccount(actNum, index);
		if (found)
		{
			// Copy at the location called index the last
			// populated member of the List array
			List[index] = List[num_of_elements - 1];
			num_of_elements--;
			size_t flag = list_state;
			list_state = 0;
			sort(flag);
			deleted = true;
		}
		else {
			cout << "Account Number: " << actNum << " is not in the list" << endl;
		}
	}
	else {
		cout << "List is empty." << endl;
	}
	return deleted;
}
	
// Runs findAccount ACCESSOR. If found returns true and deposits into account.
// Otherwise returns false. Resets list_state to 0 if list_state = 1
bool depositMoney(const string &actNum, double money);
	
// sets number of elements in list to zero and sets list state to 0
void makeEmpty();
	
// Prompts user to provide account number
// calls findAccount
    // if not exist, does nothing else
    // if exist, then make changes to last name of account
// return true if change made successfully
// if list_state is 2 then set to 0
bool BankAccountList::updateAccount() {
    bool updated = false;
    cout << "Enter account number to update: ";
    string actNum;
    cin >> actNum;
	if (!isEmpty()) {
		// find out if Account number is in the array
		int index = 0;
		bool found = findAccount(actNum, index);
		if (found) {
			// update for lastname
			cout << "Enter new Lastname: ";
			string lname;
			cin >> lname;
			List[index].setLastName(lname);
			updated = true;
			if (list_state = 2) {
				list_state = 0;
			}
		}
		else {
			cout << "Account #: " << actNum << " is not in the list" << endl;
		}
	}
	else {
		cout << "List is empty." << endl;
	}
	return updated;
}
	
// calls findAccount
    // if exist then withdraw money and return true
    // if not exist or withdraw not successful return false
// if list_state is 3 then set to 0
bool withdrawMoney(const string & actNum, double money);
	
// flag 1: sort based on account number
// flag 2: sort based on last name
// flag 3: sort based on balance
void BankAccountList::sort(int flag)
{
    if (list_state == 1 && flag == 1) {
		cout << "List is already sorted based on Account Number." << endl;
		return;
	}
	
	if (list_state == 2 && flag == 2) {
        cout << "List is already sorted based on Last Name." << endl;
	    return;
	}
	
	if (list_state == 3 && flag == 3) {
	   cout << "List is already sorted based on Balance." << endl;
	   return;
	}
   
   // sort otherwise
   for (size_t i = 0; i < num_of_elements; i++) {
	   for (size_t j = 0; j < num_of_elements-1-i; j++) {
            if (flag == 1) { // sort on Account Number
			   if (List[j].getAccountNumber() > List[j+1].getAccountNumber()) {
				   BankAccount buffer = List[j];
				   List[j] = List[j + 1];
				   List[j + 1] = buffer; 
			   }
            }
            else if (flag == 2) { // sort on last name case insensitive
                string jupper = List[j].getLastName();
	            for (auto & c : jupper) {
		            c = toupper(c);
	            }
	            string jplus1_upper = List[j+1].getLastName();
	            for (auto & c : jplus1_upper) {
		            c = toupper(c);
	            }
                if (jupper > jplus1_upper) {
				   BankAccount buffer = List[j];
				   List[j] = List[j + 1];
				   List[j + 1] = buffer; 
                }
            }
            else if (flag == 3) { // sort based on Balance
                if (List[j].getBalance() > List[j+1].getBalance()) {
				   BankAccount buffer = List[j];
				   List[j] = List[j + 1];
				   List[j + 1] = buffer; 
                }
            }
        }
   }
   list_state = flag;
}
	
// checks if index is within bound of index of list,
// then replaces account at location index with BA
// TO BE COMPLETED void setAccountAt(BankAccount & BA, size_t index);
	
// checks if actNum is in the list. If true, sets lname to last name 
// if list_state is 2 then sets to 0
// TO BE COMPLETED void setLastName(const string & lname, const string & actNum);
	
// NON-MUTATORS

// if found then returns index i where found and returns true
// if not found then returns -1 as value of i and returns false
bool BankAccountList::findAccount(const string & actNum, int & i) const
{
	bool found = false;

	for (i = 0; i < num_of_elements; i++)
	{
		if (actNum == List[i].getAccountNumber())
		{
			return true;
			break;
		}
	}
    i = -1;
	return false;
}

// TO BE COMPLETED bool getAccountAt(BankAccount & BA, size_t & index) const;
// TO BE COMPLETED double getBalance(const string & actNum) const;
// TO BE COMPLETED static int getCapacity();
// TO BE COMPLETED const string getFirstName(const string & actNum) const;
// TO BE COMPLETED const string getFullName(const string & actNum) const;
// TO BE COMPLETED void getHighestBalanceAccount (BankAccount & BA) const;

// returns by reference a new instance of BankAccountList
void BankAccountList::getInstance(BankAccountList & BAL) {
    bool done = false;
    while (!done && !BAL.isFull()) {
		BankAccount temp; 
		BankAccount::getInstance(temp);
		BAL.addAccount(temp);
		cout << "More data? Enter 0 to continue or 1 to stop: ";
		cin >> done;
		cout << "Current List Length = " << BAL.num_of_elements << endl;
	}
	if (BAL.isFull()) {
        cout << "Cannot add anymore to list. List is full" << '\n';
	}
}
// returns by reference a new instance of BankAccountList from input file
void getInstance(BankAccountList & BAL, ifstream & in)
{
    bool done = false;
    while (!done && !BAL.isFull()) {
        BankAccount temp;
        BankAccount::getInstance(temp, in);
        BAL.addAccount(temp);
        cout << "Current List Length = " << BAL.getNumberOfElements() << endl;
    }
	if (BAL.isFull()) {
        cout << "Input file has more records than list can handle. "
            << "List is full at " << BAL.getNumberOfElements() << '\n';
	}
}

// TO BE COMPLETED const string getLastName(const string & actNum) const;
// TO BE COMPLETED int getLengthOfLongestFirstName() const;
// TO BE COMPLETED int getLengthofLongestLastName() const;
// TO BE COMPLETED int getListState const;
// TO BE COMPLETED double getMeanOfAllDeposits() const;

// returns num_of_elements
int BankAccountList::getNumberOfElements() const {
    return static_cast<int>(num_of_elements);
}

// TO BE COMPLETED void getSmallestBalanceAccount(BankAccount & BA) const;

// returns true if list is empty else false
bool BankAccountList::isEmpty() const {
   if (num_of_elements == 0) {
       return true;
   }
   else {
       return false;
   }
}

// returns true if list is full else false
bool BankAccountList::isFull() const {
    if (num_of_elements == BankAccountList::MAX) {
        return true;
    }
    else {
        return false;
    }
}
// TO BE COMPLETED const string listDescription() const;
// TO BE COMPLETED size_t numberOfDepositsAboveMean() const;
// TO BE COMPLETED size_t numberOfDepositsAtOrBelowMean() const;

// prints to console[default] or output file
// writes to output file in append mode in driver function to prevent deleting previous data
void BankAccountList::print(ostream & out = cout) const
{
    if (!isEmpty()) {
        for (size_t i = 0; i < num_of_elements; i++) {
            List[i].BankAccount::print(out);
            out << "-------------------" << '\n';
        }
    }
}

// TO BE COMPLETED void printListAsReport();
// TO BE COMPLETED void  printStatistics(ostream & out) const;
// TO BE COMPLETED double Standard_Deviation_Deposits() const;
// TO BE COMPLETED double sumAllDeposits() const;

// returns string version of entire bank account list
const string BankAccountList::toString() const
{
    if (isEmpty())
	{
		return "List is Empty\n";
	}
	string temp;
	for (size_t i = 0; i < num_of_elements; i++)
	{
		temp += List[i].toString();
	}
	return temp;
}

// TO BE COMPLETED void writeToNewInputFile(ostream & out) const;