#include "Student.h"
#include "dummy.h"
#include "StudentList.h"
void print(Student S);
Student getStudent();

/*
 if flag = 1 sort based on ID
 if flag = 2 sort based on last name
 if flag = 3 , sort based on GPA
 */
int main()
{
    StudentList SL;
    //string InFileName;
    ////		//Clean the buffer - two techniques - both work on windows , cin.ignore(128, '\n') , or cin.sync()
    ////		// On Mac only cin.ignore will work
    //		cout << "Enter full path to input file: ";
    //		cin.sync();
    //		getline(cin, InFileName);
    //		ifstream in(InFileName);
    //		if (!in.is_open())
    //		{
    //			cout << "Failed to open the input file." << endl;
    //
    //		}
    //		else
    //		{
    //			StudentList::getInstance(in, SL);
    //			SL.print();
    //			Student temp(2378, "", "", 0, 0.0);
    //			bool flag = SL.updateItem(temp);
    //			cout << "\n\n";
    //			SL.print();
    //		}
    
    bool done = false;
    
    while (!done)
    {
        cout << "*************Main Menu*************" << endl
        << "1. Fill student array from keyboard data entry." << endl
        << "2. Fill student array from input file." << endl
        << "3. Print student array to console." << endl
        << "4. Print student array to output file." << endl
        << "5. Sort array based on ID." << endl
        << "6. Sort array based on last name." << endl
        << "7. Sort array based on GPA" << endl
        << "8. Search array based on ID." << endl
        << "9. Search array based on last name." << endl
        << "10. Update or Delete Student" << endl
        << "11. Print List Statistics to Console only."<<endl
        << "12. Exit" << endl;
        int choice;
        cout << "Enter menu choice and press enter key: ";
        cin >> choice;
        
        if (choice == 12)
        {
            done = true;
        }
        else if (choice == 10)
        {
            int choice11 = 0;
            cout << "Enter 1 to update student or 2 to delete a student: ";
            cin >> choice11;
            int idNum;
            cout << "Enter the ID number of student to be updated or deleted: ";
            cin >> idNum;
//Student(int brthYr = 0, string fname = "First name not set",
//			string lname = "Last name not set", int idNum = 0, double gp = 0.0);
            Student temp(0, "", "", idNum, 0.0);
            
            if (choice11 == 1)// updating
            {
                bool flag = SL.updateStudent(temp);
                if (flag) {
                    cout<<"Update Successful."<<endl;
                }
                else{
                    cout<<"Update was unsuccessful."<<endl;
                }
            }
            else
            {
                bool flag = SL.deleteStudent(temp);
                if (flag)
                {
                    cout << "Deletion was successful" << endl;
                }
                else
                {
                    cout << "Deletion was not successful" << endl;
                }
                
            }
        }
        else if (choice == 1)
        {
            StudentList::getInstance(cin, SL);
        }
        else if (choice == 2)
        {
            // Ask for input file name
            // Bond ifstream object created locally to input file
            // Validate that bonding happened or file opened successfully
            // Call the static getInstance to fill the object from file
            // Close the file
            string InFileName;
            //Clean the buffer - two techniques - both work on windows , cin.ignore(128, '\n') , or cin.sync()
            // On Mac only cin.ignore will work
            cout << "Enter full path to input file: ";
            cin.ignore(128, '\n');
            getline(cin, InFileName);
            ifstream in(InFileName);
            if (!in.is_open())
            {
                cout << "Failed to open the input file." << endl;
                continue;
            }
            StudentList::getInstance(in, SL);
            in.close();
        }
        else if (choice == 3)
        {
            SL.print();
        }
        else if (choice == 4)//Print student array to output file
        {
            string outFileName;
            //Clean the buffer - two techniques - both work on windows , cin.ignore(128, '\n') , or cin.sync()
            // On Mac only cin.ignore will work
            cout << "Enter full path to output file: ";
            cin.ignore(128, '\n');
            getline(cin, outFileName);
            ofstream out(outFileName);
            if (!out.is_open())
            {
                cout << "Failed to open/create the output file." << endl;
                continue;
            }
            SL.print(out);
            out.close();
        }
        else if (choice == 5)
        {
            SL.bubbleSort( 1);// Sort on ID
        }
        else if (choice == 6)
        {
            SL.bubbleSort( 2);//Sort on Last name
        }
        else if (choice == 7)
        {
            SL.bubbleSort( 3);//Sort on GPA
        }
        else if (choice == 8)//Search based on ID
        {
            int idNum;
            cout << "Enter the ID of student being searched. Only first match(if any) will be returned." << endl;
            cin >> idNum;
            //Student(int brthYr,string fname ,
            //string lname , int idNum , double gp )
            Student S(0, "", "",idNum, 0.0);
            int location;
            bool found = SL.find(S, location);
            
            if (!found)
            {
                cout << "Student with ID " << idNum << " is not in the list." << endl;
            }
            else
            {
                cout << "Student is in the list. Here are the complete details." << endl;
                S = SL.getStudentAt(location);
                S.Print();
            }
        }
        else if (choice == 9)//Search based on last name
        {
            string lst;
            cout << "Enter the last name (one word) of student being searched. Only first match(if any) will be returned." << endl;
            cin >> lst;
            //Student(int brthYr,string fname ,
            //string lname , int idNum , double gp )
            Student S(0, "", lst, 0, 0.0);
            int location;
             bool found = SL.searchLastName( S, location);
            
            if (!found)
            {
                cout << "Student with last name " << lst << " is not in the list." << endl;
            }
            else
            {
                cout << "Student is in the list. Here are the complete details." << endl;
                S = SL.getStudentAt(location);
                S.Print();
            }
        }
        else if (choice == 11)
        {
            cout << "Here are the statistical data related to the list:" << endl;
            SL.printStatistics(cout);
        }
    }//end of while
    return 0;
}
int main2()
{
	StudentList SL;
	Student S1(1997, "Lisa", "Jones", 9876, 3.8);
	Student S2(1996, "Kim", "Adams", 1234, 3.2);
	Student S3(1996, "Jim", "Jones", 1234, 3.2);
	SL.add(S1);
	SL.add(S2);
	SL.add(S3);

	Student S4(1996, "Jim", "Jones", 9999, 3.5);
	SL.add(S4);
	cout << SL.toString() << endl;
	SL.bubbleSort(1);
	cout << "After sorting based on ID" << endl;

	cout << SL.toString() << endl;
    StudentList SL2;
    SL2 = SL;
	return 0;
}
int main1()
{
	/*string collgeNm = Student::getCollgeName();
	cout << "College Name: " << collgeNm << endl;*/
	/*
	Student(int brthYr = 0, string fname = "First name not set",
		string lname = "Last name not set", int idNum = 0, double gp = 0.0);
	*/
	Student S1(1997, "Lisa", "Adams", 1234, 3.2);
	Student S2(1996, "Kim", "Jones", 9876, 3.8);
	S1.Print();
	S2.Print();
	Student S3;
	S3 = Student::getInstance(cin);
	S3.Print();
	print(S3);
	Student S4;
	S4 = Student(1996, "Kim", "Jones", 9876, 3.8);

	Student S5;
	S5 = getStudent();
	cout << "Print S5:" << endl;
	S5.Print();
	system("pause");
	return 0;
}

void print(Student S)
{
	S.Print();
}

Student getStudent()
{
	string fname, lname;
	int byear, id;
	double gp;
	cout << "Enter First Name: ";
	cin >> fname;
	cout << "Enter last Name: ";
	cin >> lname;
	cout << "Enter ID: ";
	cin >> id;
	cout << "Enter birth Year: ";
	cin >> byear;
	cout << "Enter GPA: ";
	cin >> gp;
	return Student(byear, fname, lname, id, gp);
}

/*
Name:Lisa Adams
ID: 1234
GPA: 3.20
Birth Year: 1997
College Name: El Camino College
Name:Kim Jones
ID: 9876
GPA: 3.80
Birth Year: 1996
College Name: El Camino College
Enter First Name: s
Enter last Name: p
Enter ID: 3987
Enter birth Year: 1999
Enter GPA: 2.9
Name:s p
ID: 3987
GPA: 2.90
Birth Year: 1999
College Name: El Camino College
Name:s p
ID: 3987
GPA: 2.90
Birth Year: 1999
College Name: El Camino College
Enter First Name: tim
Enter last Name: wim
Enter ID: 8754
Enter birth Year: 1986
Enter GPA: 3.9
Print S5:
Name:tim wim
ID: 8754
GPA: 3.90
Birth Year: 1986
College Name: El Camino College
Press any key to continue . . .








*/
