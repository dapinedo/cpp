//
//  Mortgage.cpp
//  MortgageList
//
//  Created by Satish Singhal on 9/12/15.
//  Copyright (c) 2015 Satish Singhal. All rights reserved.
//

#include "Mortgage.h"

    /**
     Algorithm: Use initialization list to set all members.
     Then do validation inside constructor body. If values are valid then
     if statements inside constructor will not execute.
     * @param rt
     * @param cst
     * @param dnp
     * @param yr
     */
MortgageClass::MortgageClass(int act, const string & frst, const string & lst, const string & cty,double rt, double cst, 
	double dnp, int yr):AccountNum(abs(act)),First(frst),
	Last(lst),City(cty),rate(abs(rt)), cost(abs(cst)), downPymnt(abs(dnp)),
	year(abs(yr)), numPayments(0)
    {
        if (rate == 0.0)
        {
            cout<<"Interest rate cannot be zero. It is being set to 4.5."<<endl;
            rate = 4.5;
        }
        
        if (cost == 0.0)
        {
            cout<<"Cost of house cannot be zero. It is being set to 100000."<<endl;
            cost = 100000;
        }
        
        if (cost <= downPymnt)
        {
            cout<<"Cost of house cannot be equal to or less than down payment. Setting down payment 20% of cost."<<endl;
            downPymnt = 0.20 * cost;
        }
           
        
        if (year == 0)
        {
            cout<<"Number of years for which loan is taken cannot be zero. It is being set to 30."<<endl;
            year = 30;
        }
            AmountPaid = numPayments*getMonthlyPayment();
            AmountLeftToPay = year*12*getMonthlyPayment() - AmountPaid;
    }
   void MortgageClass::makeMonthlyPayment(double pmt)
    {
      if(pmt >= getMonthlyPayment())
      {
        numPayments++;
        AmountPaid+=pmt;
        AmountLeftToPay = (year*12)*getMonthlyPayment() - AmountPaid;
          return;
      }
        cout<<"Payment is less than required monthly payment. No changes made."<<endl;
    }
     void MortgageClass::getInstance(MortgageClass & M, istream & in )
    {
        if(&in == &cin)
        {
            int act;
            cout<<"Enter account number: ";
            cin>>act;
            string frst, lst, cty;
            cout<<"Enter the first name of borrower: ";
            cin>>frst;
            for(auto & dummy:frst) dummy = toupper(dummy);
            cout<<"Enter the last name of borrower (hyphanated name ok): ";
            cin>>lst;
            for(auto & dummy:lst) dummy = toupper(dummy);
            cin.ignore();
            cout<<"Enter the city in which borrower lives: ";
            getline(cin,cty);
            for(auto & dummy:cty) dummy = toupper(dummy);
            cout<<"Enter yearly interest rate (in percent) at which mortgage is being offered[xx.yy]"<<endl;
            double rt = 0.0;
            cin>>rt;
            cout<<"Enter the number of years you wish the mortgage for? [whole number only]"<<endl;
            int yr = 0;
            cin>>yr;
            
            cout<<"Enter the cost of house you plan to buy? [xx.yy]"<<endl;
            double cst = 0.0;
            cin>>cst;
            cout<<"We will now ask the downpayment you will be making."<<endl;
            cout<<"Caution: if downpayment is less than 20% of the cost of house you may be required to buy mortgage insurance."<<endl;
            cout<<"Enter the downpayment you would be making.[xx.yy]"<<endl;
            double dnp = 0.0;
            cin>>dnp;
            
            if (cst <= dnp)
            {
                cout<<"Your downpayment is equal to or larger than cost of house. You do not need a loan."<<endl;
				return;
            }
            
            M =  MortgageClass(act,frst, lst, cty,rt, cst, dnp, yr);
        }
        else
        {
            int act = 0;
            string frst, lst, cty;
            double rt = 0.0;
            int yr = 0;
            double cst = 0.0;
            double dnp = 0.0;
            in>>act>>frst>>lst;
            for(auto & dummy:frst) dummy = toupper(dummy);
            for(auto & dummy:lst) dummy = toupper(dummy);
            cin.ignore(128, '\n');
			getline(in, cty);
            for(auto & dummy:cty) dummy = toupper(dummy);
            in>>rt;
            in>>yr;
            in>>cst;
            in>>dnp;
            
            if (cst <= dnp)
            {
                cout<<"Your downpayment is equal to or larger than cost of house. You do not need a loan."<<endl;
				return;
            }
            M =  MortgageClass(act,frst, lst, cty, rt, cst, dnp, yr);
            
        }
    }
    /**
     *
     */
    double MortgageClass::getMonthlyPayment() const
    {
        double loan = cost - downPymnt;
        double rate1 = rate / 100.0;
        rate1 = rate1/12.0;
        return (loan * rate1)/ (1 - pow(1 / (1 + rate1), year * 12));
    }
    void MortgageClass::computeMortgagePrint(ostream & out)const
    {
        out<<fixed<<showpoint<<setprecision(2);
        double monthlyPayment = getMonthlyPayment();
        out<<"Your monthly mortgage payment will be: $"<<monthlyPayment<<endl;
        out<<"Your total payment over life of mortgage will be: $"<<monthlyPayment * 12 * year<<endl;
        out<<"For a house costing "<<cost<<" today, you will be paying: $ "<< (monthlyPayment * 12 * year + downPymnt)<<endl;
        double interest = monthlyPayment*12*year - cost - downPymnt;
        out<<"The overall interest you will pay over the life of loan will be: $" <<interest<<endl;
    }// end of method
    /**
     *
     */
    void  MortgageClass::printAmortizationSchedule(ostream & out)const
    {
        out<<fixed<<showpoint<<setprecision(2);
        double rate1 = rate / 100.0;
        rate1 = rate1/12.0;
        double loan = cost - downPymnt;
        double monthlyPayment = getMonthlyPayment();
        computeMortgagePrint(out);
        out<<"Printing amortization schedule for the life of the loan, assuming that no prepayment of principal was done."<<endl;
        // Interest in a month is equal to interest on principal for that
        // month.
        /*
         * Algorithm is as follows: Monthly payment is constant shown above
         * calculate principal each month (P) calculate interest on principal
         * for that month(I) PaidToPrincipal = monthly payment - I P = P -
         * PaidToPrincipal Loop over number of months for loan
         */
        double P = loan;
        double I = 0.0;
        double PaidToPrincipal = 0.0;
        int count = 1;
        out<<setw(17)<<left<<"Payment Number    ";
        out<<setw(25)<<"Current Principal($)   ";
        out<<setw(24)<<"Monthly Interest($)   ";
        out<<setw(26)<<"Principal Reduction($)   ";
        out<<setw(24)<<"Balance of Principal($)"<<endl;
        out<<"------------------------------------------------------------------------------------------------------------------"<<endl;
        
        while (count <= year * 12) {
            out<<setw(17)<<left<<count;
            out<<setw(25)<< P;
            I = P * rate1;
            out<<setw(24)<< I;
            PaidToPrincipal = monthlyPayment - I;
            out<<setw(26)<<PaidToPrincipal;
            P = P - PaidToPrincipal;
            out<<setw(24)<< P<<endl;
            out<<"------------------------------------------------------------------------------------------------------------------"<<endl;
            count++;
        }// end of while
    }// end of method
    
    void MortgageClass::setRate(double rt)
    {
        
        if (rt == 0.0)
        {
            cout<<"Interest rate cannot be zero. No change is made."<<endl;
        }
        else
        {
            rate = abs(rt);
        }
    }
    
    void MortgageClass::setCost(double cst)
    {
        
        if (cost == 0.0)
        {
            cout<<"Cost of house cannot be zero. No change is made."<<endl;
        }
        else
        {
            cost = abs(cst);
        }
    }
    
    void MortgageClass::setYears(int yr)
    {
        
        if (yr == 0)
        {
            cout<<"Number of years for which loan is taken cannot be zero. No change is made."<<endl;
        }
        else
        {
            year = abs(yr);
        }
    }
    
    void MortgageClass::setDownPayment(double dnp)
    {
        
        if (cost <= abs(dnp))
        {
            cout<<"Cost of house cannot be equal to or less than down payment. No change is made."<<endl;
            cout<<"Otherwise change the cost first and then change down payment."<<endl;
        }
        else
        {
            downPymnt = abs(dnp);
        }
    }
    
    double MortgageClass::getRate()const
    {
        return rate;
    }
    
    double MortgageClass::getCost()const
    {
        return cost;
    }
    
    int MortgageClass::getYears() const
    {
        return year;
    }
    int MortgageClass::getAccountNumber() const
{
    return AccountNum;
}
double MortgageClass::getDownPayment()const
{
        return downPymnt;
}
  const string MortgageClass::toString()const
{
    ostringstream os;
    double pmt = getMonthlyPayment();
    int periods = year*12;
    double loan = cost - downPymnt;
    double amountPaidInInterest = pmt*periods - loan;
    os<<fixed<<showpoint<<setprecision(2)
    <<"----------------------------------------------\n"
    <<"Name: "<<this->First<<' '<<this->Last<<'\n'
    <<"City: "<<City<<'\n'
    <<"Cost of House: $"<<this->cost<<'\n'
    <<"Down Payment: $ "<<this->downPymnt<<'\n'
    <<"Loan Amount: $ "<<(cost - downPymnt)<<'\n'
    <<"Annual Interest Rate: "<<this->rate<<'\n'
    <<"Length of Loan in Years: "<<this->year<<'\n'
    <<"Monthly Payment: $ "<<pmt<<'\n'
    <<"Amount paid so far: $ "<<AmountPaid<<'\n'
    <<"Amount left to pay: $ "<<AmountLeftToPay<<'\n'
    <<"Total Money paid for house over life of loan: $"<<(downPymnt +pmt*periods)<<'\n'
    <<"The amount paid in interest: $ "<<amountPaidInInterest<<'\n'
    <<"----------------------------------------------"<<endl;
    return os.str();
}
const string MortgageClass::getFirstName()const
{
    return this->First;
}
const string MortgageClass::getLastName()const
{
    return this->Last;
}
const string MortgageClass::getFullName()const
{
    return First + ' ' + Last;
}
const string MortgageClass::getCity()const
{
    return City;
}

double MortgageClass::getTotalPaymentsMade() const
{
    return AmountPaid;
}
double MortgageClass::getAmountLeftToPay() const
{
    return AmountLeftToPay;
}
void MortgageClass::setCity(const string & ct)
{
    City = ct;
}
void MortgageClass::setLastName(const string & lst)
{
    Last = lst;
}
