#include "Student.h"
#include "dummy.h"
#include "StudentList.h"
void print(Student S);
Student getStudent();

int main()
{
	StudentList SL;
	SL = StudentList::getInstance(cin);
	cout << SL.toString();
	system("pause");
	return 0;
}
int main4()
{
	StudentList SL;
	Student S1(1997, "Lisa", "Jones", 9876, 3.8);
	Student S2(1996, "Kim", "Adams", 1234, 3.2);
	
	SL.add(S1);
	SL.add(S2);
	

	Student S4(1996, "Jim", "Jones", 9999, 3.5);
	SL.add(S4);
	cout << SL.toString() << endl;
	cout << "Enter the ID of student to be updated: ";
	int id;
	cin >> id;
	Student key(0, "", "", id, 0.0);
	bool updated = SL.updateStudent(key);

	cout << SL.toString() << endl;
	system("pause");
	return 0;
}
int main3()
{
	StudentList SL;
	Student S;
	//SL.deleteStudent(S);
	//return 9;
	Student S1(1997, "Lisa", "Jones", 9876, 3.8);
	Student S2(1996, "Kim", "Adams", 1234, 3.2);
	Student S3(1996, "Jim", "Jones", 1234, 3.2);
	SL.add(S1);
	SL.add(S2);
	SL.add(S3);

	Student S4(1996, "Jim", "Jones", 9999, 3.5);
	SL.add(S4);
	SL.bubbleSort(1);
	cout << SL.toString() << endl;

	if (SL.deleteStudent(S4))
	{
		cout << "Student deleted " << endl;
	}
	else
	{
		cout << "Student not deleted " << endl;
	}

	cout << SL.toString() << endl;
	bool deleted = SL.deleteStudent(S);
	system("pause");
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
	system("pause");
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