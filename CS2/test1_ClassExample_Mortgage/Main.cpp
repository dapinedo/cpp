#include "MortgageList.h"

int main/*MortgageListClass*/()
{
	MortgageList ML;
	bool done = false;

	while (!done) {
		cout << "-------------------------------------\n"
			<< "**********Main Menu******************\n"
			<< "-------------------------------------\n"
			<< "1. Create data input file from keyboard data entry.\n"//done
			<< "2. Create Mortgage List from input file.\n"//done
			<< "3. Create Mortgage List from keyboard or add to existing List.\n"//done
			<< "4. Print existing list to console.\n"//done
			<< "5. Print existing list to output file in append mode.\n"//done
			<< "6. Sort based on account number.\n"//done
			<< "7. Sort based on last name of account holder.\n"//dpne
			<< "8. Sort based on city.\n"//done
			<< "9. Sort based on cost of houses.\n"//done
			<< "10. Search based on account number and print to console.\n"//done
			<< "11. Search based on last name and print to console.\n"//done
			<< "12. Pay my mortgage.\n"//done
			<< "13. Balance left to pay enquiry.\n"//done
			<< "14. How much I paid so far enquiry.\n"//done
			<< "15. Print My Amortization Schedule to output file.\n"//done
			<< "16. Print My Amortization schedule to console.\n"//done
			<< "17. Sort on all basis and print to output file in append mode.\n"//done
			<< "18. Exit" << endl;
		int choice;
		cin >> choice;
		if (choice == 18) {
			done = true;
		}
		else if (choice == 1){
			cout << "Enter full path to output file that will later be used as input file.\n";
			string outFileName;
			cin.ignore();//for mac
			//cin.sync();// for windows
			getline(cin, outFileName);
			ofstream out(outFileName, ios::app);

			if (!out.is_open()){
				cout << "Failed to create/open file." << endl;
				out.clear();
				out.close();
				continue;
			}
			MortgageList::getInstance(ML);
			ML.PrintFileForFutureRead(out);
			out.close();
		}
		else if (choice == 2){
			string inputFileName;
			cout << "Enter full path to data input file: ";
			cin.ignore();
			getline(cin, inputFileName);
			ifstream in(inputFileName);

			if (!in.is_open()){
				cout << "Failed to open input file." << endl;
				continue;
			}
			MortgageList::getInstance(ML, in);
			in.close();
		}//choice 2
		else if (choice == 3){
			if (ML.getNumber_of_elements() != 0) {
				//Add to existing list
				MortgageList MAL;
				MortgageList::getInstance(MAL);
				ML = MortgageList::CombineLists(MAL, ML);
			}
			else{
				MortgageList::getInstance(ML);
			}
		}//choice 3
		else if (choice == 4){
			cout << ML.toString() << endl;
		}//choice 4
		else if (choice == 5){
			cout << "Enter full path to output file: ";
			string outFileName;
			cin.ignore(128, '\n');//comment out in windows but comment in on mac
			//cin.sync();//comment out in mac but comment in on Windows
			ofstream out(outFileName, ios::app);

			if (!out.is_open()) {
				cout << "Failed to open output file." << endl;
				out.clear();
				out << flush;
				continue;
			}
			out << ML.toString() << endl;
			out.close();
		}//choice 5
		else if (choice == 6){
			ML.sort(1);
		}//choice 6
		else if (choice == 7){
			ML.sort(2);
		}//choice 7
		else if (choice == 8){
			ML.sort(3);
		}//choice 8
		else if (choice == 9){
			ML.sort(4);
		}//choice 9
		else if (choice == 10){
			cout << "Enter the account number for mortgage account: ";
			int actNum;
			cin >> actNum;
			MortgageClass Temp(actNum);
			int index = -1;
			if (ML.find(Temp, 1, index)){
				cout << "Account: " << actNum << " found. Details are below:\n";
				cout << ML.getMortgageAt(index).toString() << endl;
			}
			else{
				cout << "The account number: " << actNum << " is not in the list. Please contact your system administrator." << endl;
			}
		}//choice 10
		else if (choice == 11){
			cout << "Enter the last name of the account holder [One word]. Hyphanated name ok: ";
			string nm;
			cin >> nm;
			MortgageClass Temp(0, nm);
			int index = -1;
			if (ML.find(Temp, 2, index)){
				cout << "Account last name: " << nm << " found. Details are below:\n";
				cout << ML.getMortgageAt(index).toString() << endl;
			}
			else{
				cout << "The account last name: " << nm << " is not in the list. Please contact your system administrator." << endl;
			}
		}//choice 11
		else if (choice == 12){
			cout << "Enter the account number for your mortgage account: ";
			int actNum;
			cin >> actNum;
			cout << "Enter amount you wish to pay: ";
			double money;
			cin >> money;
			money = abs(money);
			ML.makeMonthlyPayment(actNum, money);
		}//choice 12
		else if (choice == 13){
			cout << "Enter the account number for your mortgage account: ";
			int actNum;
			cin >> actNum;
			MortgageClass Temp(actNum);
			int index = -1;
			if (ML.find(Temp, 1, index)){
				cout << "Account: " << actNum << " found. Amount left to pay is below:\n";
				cout << "$ " << ML.getMortgageAt(index).getAmountLeftToPay() << endl;
			}
			else{
				cout << "The account number: " << actNum << " is not in the list. Please contact your system administrator." << endl;
			}
		}//choice 13
		else if (choice == 14){
			cout << "Enter the account number for your mortgage account: ";
			int actNum;
			cin >> actNum;
			MortgageClass Temp(actNum);
			int index = -1;
			if (ML.find(Temp, 1, index)){
				cout << "Account: " << actNum << " found. Amount paid so far is below:\n"
					<< "This amount does not include your down payment.\n";
				cout << "$ " << ML.getMortgageAt(index).getTotalPaymentsMade() << endl;
			}
			else{
				cout << "The account number: " << actNum << " is not in the list. Please contact your system administrator." << endl;
			}
		}//choice 14
		else if (choice == 15){
			cout << "Enter the account number for your mortgage account: ";
			int actNum;
			cin >> actNum;
			MortgageClass Temp(actNum);
			int index = -1;
			if (ML.find(Temp, 1, index)){
				cout << "Enter full path to output file: ";
				string outFileName;
				cin.ignore(128, '\n');//comment out in windows but comment in on mac
				//cin.sync();//comment out in mac but comment in on Windows
				ofstream out(outFileName, ios::app);

				if (!out.is_open()) {
					cout << "Failed to open output file." << endl;
					out.clear();
					out << flush;
					continue;
				}

				ML.getMortgageAt(index).printAmortizationSchedule(out);
				out.close();
			}
			else{
				cout << "The account number: " << actNum << " is not in the list. Please contact your system administrator." << endl;
				continue;
			}
		}//choice 15
		else if (choice == 16){
			cout << "Enter the account number for your mortgage account: ";
			int actNum;
			cin >> actNum;
			MortgageClass Temp(actNum);
			int index = -1;
			if (ML.find(Temp, 1, index)){
				cout << "Enter full path to output file: ";
				string outFileName;
				cin.ignore(128, '\n');//comment out in windows but comment in on mac
				//cin.sync();//comment out in mac but comment in on Windows
				ofstream out(outFileName, ios::app);

				if (!out.is_open()) {
					cout << "Failed to open output file." << endl;
					out.clear();
					out << flush;
					continue;
				}

				ML.getMortgageAt(index).printAmortizationSchedule();
				out.close();
			}
			else{
				cout << "The account number: " << actNum << " is not in the list. Please contact your system administrator." << endl;
				continue;
			}
		}//choice 16
		else if (choice == 17){
			cout << "Enter full path to output file: ";
			string outFileName;
			cin.ignore(128, '\n');//comment out in windows but comment in on mac
			//cin.sync();//comment out in mac but comment in on Windows
			ofstream out(outFileName, ios::app);

			if (!out.is_open()) {
				cout << "Failed to open output file." << endl;
				out.clear();
				out << flush;
				continue;
			}
			ML.sort(1);
			out << "**********************************************\n";
			out << "Sorted based on account number.\n";
			out << "**********************************************\n";
			out << ML.toString() << endl;
			ML.sort(2);
			out << "**********************************************\n";
			out << "Sorted based on last name of borrower.\n";
			out << "**********************************************\n";
			out << ML.toString() << endl;
			ML.sort(3);
			out << "**********************************************\n";
			out << "Sorted based on city of account holder.\n";
			out << "**********************************************\n";
			out << ML.toString() << endl;
			ML.sort(4);
			out << "**********************************************\n";
			out << "Sorted based on cost of houses.\n";
			out << "**********************************************\n";
			out << ML.toString() << endl;
			out.close();
		}//choice 17
		else{
			cout << "This menu item is not yet implemented." << endl;
		}
	}//loop
	return 0;
}