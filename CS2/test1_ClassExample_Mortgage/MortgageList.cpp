//
//  MortgageList.cpp
//  MortgageList
//
//  Created by Satish Singhal on 9/12/15.
//  Copyright (c) 2015 Satish Singhal. All rights reserved.
//

#include "MortgageList.h"

MortgageList::MortgageList() : len(0), list_state(0)
{
  
}
////////////////////////////////////////////////////////////
bool MortgageList::find(const MortgageClass & key, int flag, int & index) const
{
    index = -1;
    if (len == 0) {
        return false;
    }
    bool found = false;
    
    for (size_t i = 0; i<len; i++) {
        if (flag == 1) {//search based on account number
            if (key.getAccountNumber() == MList[i].getAccountNumber()) {
                index = static_cast<int>(i);//update index
                found = true;
                break;
            }
        }
       else if (flag == 2) {//search based on last name, only first match will be returned
            if (key.getLastName() == MList[i].getLastName()) {
                index = static_cast<int>(i);//update index
                found = true;
                break;
            }
        }
       else if (flag == 3) {//search based on city, only first match will be returned
           if (key.getCity() == MList[i].getCity()) {
               index = static_cast<int>(i);//update index
               found = true;
               break;
           }
       }
       else{
           cout<<"Invalid search basis."<<endl;
           break;
       }

    }
    return found;
}
//////////////////////////////////////////////////////////
bool MortgageList::addMortgageAccount(const MortgageClass & MC)
{
    if (len == MAX) {
        cout<<"List is full."<<endl;
        return false;
    }
    int index = -1;
    bool flag = find(MC, 1,index);
    
    if (flag) {
        cout<<"Mortgage account already exists. Not added."<<endl;
        return !flag;
    }
    
    MList[len++]= MC;
    flag = true;
    list_state = 0;
    return flag;
}

////////////////////////////////////////////////////////////////
void MortgageList::getInstance(MortgageList & ML, istream & in )
{
    if (&in == & cin) {
        bool done = false;
        
        while (!done && ML.len<MAX) {
            MortgageClass temp;
            MortgageClass::getInstance(temp);
            ML.addMortgageAccount(temp);
            cout<<"More data? Enter 0 to continue or 1 to stop: ";
            cin>>done;
        }
    }else {
        while (in.peek() != EOF && ML.len<MAX) {
            MortgageClass temp;
            MortgageClass::getInstance(temp, in);
             ML.addMortgageAccount(temp);
        }

    }
}
////////////////////////////////////////////////////////////////////////
const string MortgageList::toString() const
{
    if (len == 0) {
        return "List is empty.\n";
    }
    
    string str = "";
    
    for (size_t i = 0; i<len; i++) {
        str+= MList[i].toString();
    }
    
    return str;
}
//////////////////////////////////
void MortgageList::makeEmpty() {
    len = 0;
    list_state = 0;
}
/////////////////////////////////
bool MortgageList::isFull() const{
    
    return len == MAX;
    
}
//////////////////////////////////////
bool MortgageList::isEmpty() const{
    return len == 0;
    
}
///////////////////////////////////////////
size_t MortgageList::getCapacity()const{
    return MAX;
}
////////////////////////////////////////////
size_t MortgageList::getNumber_of_elements()const {
    return len;
}
/////////////////////////////////////////////
int MortgageList::getList_state() const{
    return list_state;
}
//////////////////////////////////////////////
/** @param index
 * @return
 */
MortgageClass MortgageList::getMortgageAt(int index) const {
    if (index > (len - 1) || index < 0) {
        throw "out of bound array index access";
    }
    MortgageClass temp = MList[index];
    return temp;
}
////////////////////////////////////////////////////////////
void MortgageList::sort(int flag)
{
    if (len < 2) {
        cout<<"List is empty or has only one element. Thus nothing to sort."<<endl;
        return;
    }
    //No need to sort if flag is invalid!
    if (flag<1 || flag>4) {
        cout<<"Invalid sort basis."<<endl;
        return;
    }
    
    for (size_t i = 0; i < len; i++)
    {
        for (size_t j = 0; j < len-i-1; j++)
        {
            if (flag == 1)
            {
                if (MList[j].getAccountNumber()>MList[j + 1].getAccountNumber())
                {
                    MortgageClass buffer = MList[j];
                    MList[j] = MList[j + 1];
                    MList[j + 1] = buffer;
                }
            }
            else if (flag == 2)
            {
                if (MList[j].getLastName()>MList[j + 1].getLastName())
                {
                    MortgageClass buffer = MList[j];
                    MList[j] = MList[j + 1];
                    MList[j + 1] = buffer;
                }
            }
            else if (flag == 3)
            {
                if (MList[j].getCity()>MList[j + 1].getCity())
                {
                    MortgageClass buffer = MList[j];
                    MList[j] = MList[j + 1];
                    MList[j + 1] = buffer;
                }
            }
            else if (flag == 4)
            {
                if (MList[j].getCost()>MList[j + 1].getCost())
                {
                    MortgageClass buffer = MList[j];
                    MList[j] = MList[j + 1];
                    MList[j + 1] = buffer;
                }
            }//else if
        }//Inner for loop
    }//outer for loop
    //List states must be set because sort has been done!
    list_state = flag;
}
////////////////////////////////////////////////////////////////////////////
bool MortgageList::deleteAccount(const MortgageClass & MC) {
    if (len == 0) {
        cout << "There are no Mortgages in the list." << endl;
        return false;
    }
    int index = -1;
    bool found = false;
    found= find(MC, 1, index);
    
    if (index < 0) {
        cout << "Mortgage instance is not in the array." << endl;
        found = false;
    }
    else {
        cout << "Confirm deletion of Mortgage instance " << MList[index].toString() << endl;
        cout << "Enter YES for deletion or NO to abort." << endl;
        
        string Choice;
        cin >> Choice;
        //convert user response to all upper case string
        for(auto & dummy: Choice) toupper(dummy);
        
        if (Choice == "YES" ) {
            if (list_state != 0) {//uses shifting algorithm to preserve order
                //Note that this is shifting algorithm.
                for (int counter = index; counter < len - 1; counter++){
                    MList[counter] = MList[counter + 1];
                }
            }
            else{
                //List state is zero means it is not sorted. Just use
                //swap for faster deletion
                MList[index] = MList[len-1];
            }
            cout << "Mortgage instance deleted successfully" << endl;
            len--;
            found = true;
        }
        else if (Choice == "NO")	{
            cout << "Deletion aborted by user." << endl;
            found = false;
        }
        else {
            cout << "User response unclear. Deletion aborted." << endl;
            found = false;
        }
    }
    
    return found;
}

bool MortgageList::updateMortgageList(){
    if (len == 0){
        cout << "There are no MortgageClasss in the list." << endl;
        return false;
    }
    
    cout << "Enter the account number of the Mortgage account whose record needs updating." << endl;
    cout << "Enter account number " << endl;
    int act;
    cin >> act;
    MortgageClass temp = MortgageClass(act);
     bool flag = false;
    int index = -1;
    flag = find(temp, 1, index);
   
    
    if (index < 0){
        cout << "Mortgage account is not in the list." << endl;
        flag = false;
    }
    else{
        bool change = 0;
        cout<<"Enter 1 to change last name of account holder, or 0 to skip this step: ";
        cin>>change;
        
        if (change == 1) {
            cout << "Enter new last name for account holder:" << endl;
            string lst;
            cin >> lst;
            MList[index].setLastName(lst);
            flag = true;
            //We reset the list state because list may have been
            //made disordered because of update. User can re-sort as needed.
            list_state = 0;
        }
        
        cout<<"Enter 1 to change city of mortgage holder , or 0 to skip this step: ";
        cin>>change;
        if (change == 1) {
            cout << "Enter new city for Mortgage holder: ";
            string cty;
            cin.ignore();
            getline(cin,cty);
            MList[index].setCity(cty);
            flag = true;
            //We reset the list state because list may have been
            //made disordered because of update. User can resort as needed.
            list_state = 0;
        }
    }
    if (flag){
        cout << "Mortgage data updated successfully" << endl;
    }
    else {
        cout << "MortgageClass is not updated." << endl;
    }
    return flag;
}

/**
 * @return
 */
double MortgageList::getMeanMortgageLoan() const{
    if (len == 0) {
        cout << "List is Empty. No mean can be found." << endl;
        throw "List is empty";
    }
    
    double sum = 0.0;
    
    for (size_t i = 0; i < len; i++){
        double loan = MList[i].getCost() - MList[i].getDownPayment();
        sum += loan;
    }
    
    return sum / len;
}

/**
 * @return
 */
double MortgageList::getStandardDevLoans() const{
    double  StdDev = 0.0;
    if (len == 0) {
        cout << "List is Empty. No mean can be found." << endl;
        throw "List is empty";
    }
    double SumofSquares = 0.0;
    
    for (size_t i = 0; i < len; i++)
    {
    double Loan  = MList[i].getCost() - MList[i].getDownPayment();
        SumofSquares += Loan*Loan;
    }
    double Mean = 0.0;
    Mean = getMeanMortgageLoan();
    StdDev = sqrt((SumofSquares / (len)) - Mean* Mean);
    return StdDev;
}

/**
 * @return the minimum value of GPA stored in the GPA field of member of
 *         the list.
 */
double MortgageList::getSmallestLoan() const {
    if (len == 0){
        cout << ("List is empty") << endl;
        throw "List is empty";
    }
    
    double minLoan = MList[0].getCost() - MList[0].getDownPayment();
    
    for (int i = 1; i < len; i++){
      double Loan = MList[i].getCost() - MList[i].getDownPayment();
        if (minLoan > Loan) {
            minLoan = Loan;
        }
    }
    
    return minLoan;
}

/**
 * @return
 */
double MortgageList::getLargestLoan() const {
    if (len == 0) {
        cout << ("List is empty") << endl;
        throw "List is empty";
    }
    
    double LargestLoan = MList[0].getCost() - MList[0].getDownPayment();
    
    for (int i = 1; i < len; i++){
        double Loan = MList[i].getCost() - MList[i].getDownPayment();
        if (LargestLoan < Loan) {
            LargestLoan = Loan;
        }
    }
    
    return LargestLoan;
}
MortgageList MortgageList::CombineLists(const MortgageList & SL1, const MortgageList & SL2)
{
    MortgageList SL;
    
    for (size_t i=0; i<SL1.getNumber_of_elements(); i++) {
        SL.addMortgageAccount(SL1.MList[i]);
    }
    
    for (size_t i=0; i<SL2.getNumber_of_elements(); i++) {
        SL.addMortgageAccount(SL2.MList[i]);
    }
    return SL;
}
//////////////////////////////////////////////////////
void MortgageList::PrintFileForFutureRead(ostream & out)
{
    //structure to be written into is as below:
    /**
     1234
     James Dean
     Torrance City
     4.0
     200000
     40000
     30
     Account number
     first name last name
     city
     rate
     cost
     down payment
     year
     */
    if (getNumber_of_elements() == 0) {
        cout<<"List is empty.\n";
        return;
    }
    for (size_t i= 0; i<len; i++) {
        out<<MList[i].getAccountNumber()<<endl
        <<MList[i].getFirstName()<<' '<<MList[i].getLastName()<<endl
        <<MList[i].getCity()<<endl
        <<MList[i].getRate()<<endl
        <<MList[i].getCost()<<endl
        <<MList[i].getDownPayment()<<endl
        <<MList[i].getYears()<<endl;
    }
}
////////////////////////////////////////////////////////////////////////////////////////
void MortgageList::PrintAmortizationSchedule(int accountNum, ostream & out )
{
    if (len == 0) {
        cout<<"List is empty."<<endl;
        return;
    }
    MortgageClass key(accountNum);
    int index = -1;
    bool found = find(key,1,index);
    
    if (!found) {
        cout<<"The account number: "<<accountNum<<" does not exist"<<endl;
        return;
    }
    MList[index].printAmortizationSchedule(out);
}
////////////////////////////////////////////////////////////////////////////////
void MortgageList::makeMonthlyPayment(int accountNum, double money)
{
    if (len == 0) {
        cout<<"List is empty."<<endl;
        return;
    }
    MortgageClass key(accountNum);
    int index = -1;
    bool found = find(key,1,index);
    
    if (!found) {
        cout<<"The account number: "<<accountNum<<" does not exist"<<endl;
        return;
    }

    MList[index].makeMonthlyPayment(money);
}

void MortgageList::setAccountAt(size_t index, const MortgageClass & M)
{
	if (index<len)// inbound
	{
		MList[index] = M;
		list_state = 0;
	}
}