#include "QueueInterface.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Student
{
private:
	string name;
	double GPA;
public:
	Student(string nm = "Name not set", double gp = 0.0) :
		name(nm), GPA(gp)
	{

	}
	friend ostream & operator <<(ostream & out, Student & S)
	{
		out << fixed << showpoint << setprecision(2);
		out << "Student Name: " << S.name << endl;
		out << "GPA: " << S.GPA << endl;
		return out;
	}
};
void testInt();
void testChar();
void testFloat();
void testString();
void testStudent();
int main()
{

	/*Queue<int> IQ;
	IQ.enqueue(5);
	IQ.enqueue(7);
	IQ.enqueue(7);
	IQ.enqueue(17);
	IQ.enqueue(55);
	IQ.enqueue(70);
	cout<<"Elements in queue are: ";
	
	cout<<IQ.dequeue()<<endl;

	while(!IQ.isEmpty())
	{
		cout<<IQ.dequeue()<< " ";
	}
*/
	//testInt();
	//testChar();
	/*testFloat();*/
	//testString();
	testStudent();
	system("pause");
	return 0;
}

void testStudent()
{
	
	Queue<Student> studentQ;

	Student S1("John Doe", 2.9);
	Student S2("Mary Doe", 3.9);
	Student S3("Lisa Adams", 2.5);
	Student S4("Tim Jones", 3.1);
	Student S5("Ellen Johnson", 3.0);
	studentQ.enqueue(S1);
	studentQ.enqueue(S2);
	studentQ.enqueue(S3);
	studentQ.enqueue(S4);
	studentQ.enqueue(S5);
	//dequeue

	while (!studentQ.isEmpty())
	{
		cout << studentQ.dequeue() << endl;
	}
}
void testInt()
{
	Queue<int> Int_ArrayQueue;
	
	cout<<"We will enqueue some integers on the queue now.\n";
	bool done = false;
	int val = int();
	while(!done)
	{
		cout<<"Please enter an integer to be enqueued : ";
		cin>>val;
		
		Int_ArrayQueue.enqueue(val);
		cout<<"More data? Enter 0 to continue and 1 to exit: ";
		cin>>done;
	}

	cout<<"Now printing the integers in the Queue.\n";

	while(!Int_ArrayQueue.isEmpty())
	{
		cout<<Int_ArrayQueue.dequeue()<<"  ";
	}
//	Int_ArrayQueue.dequeue();//change MAX  to 5 and uncomment.
	cout<<endl;
}
//---------------------------------------------------------------
void testChar()
{
	Queue<char> Char_ArrayQueue;
	cout<<"We will enqueue some characters in the Queue now.\n";
	bool done = false;
	char val = char();
	while(!done)
	{
		cout<<"Please enter an character to be put in the Queue : ";
		cin>>val;
		
		Char_ArrayQueue.enqueue(val);
		cout<<"More data? Enter 0 to continue and 1 to exit: ";
		cin>>done;
	}

	cout<<"Now printing the characters in the Queue.\n";

	while(!Char_ArrayQueue.isEmpty())
	{
		cout<<Char_ArrayQueue.dequeue()<<"  ";
	}
	cout<<endl;
}
//-------------------------------------------------------------
void testFloat()
{
	Queue<double> Float_ArrayQueue;
	cout<<"We will enqueue some floating point numbers in the Queue now.\n";
	bool done = false;
	float val = float();
	while(!done)
	{
		cout<<"Please enter a floating point number to be added to the Queue : ";
		cin>>val;
		
		Float_ArrayQueue.enqueue(val);
		cout<<"More data? Enter 0 to continue and 1 to exit: ";
		cin>>done;
	}

	cout<<"Now printing the floating point numbers  in the Queue.\n";

	while(!Float_ArrayQueue.isEmpty())
	{
		cout<<Float_ArrayQueue.dequeue()<<"  ";
	}
	cout<<endl;
}
//-------------------------------------------------------------
void testString()
{
	Queue<string> string_ArrayQueue;
	cout<<"We will enqueue some strings in the Queue now.\n";
	bool done = false;
	string val = string();
	while(!done)
	{
		cout<<"Please enter an string to be added to the Queue : ";
		cin>>val;
		
		string_ArrayQueue.enqueue(val);
		cout<<"More data? Enter 0 to continue and 1 to exit: ";
		cin>>done;
	}

	cout<<"Now printing the strings in Queue.\n";

	while(!string_ArrayQueue.isEmpty())
	{
		cout<<string_ArrayQueue.dequeue()<<"  ";
	}
	cout<<endl;
}
//---------------------------------------------------------------

/*
We will enqueue some integers on the queue now.
Please enter an integer to be enqueued : 1
More data? Enter 0 to continue and 1 to exit: 0
Please enter an integer to be enqueued : 2
More data? Enter 0 to continue and 1 to exit: 0
Please enter an integer to be enqueued : 3
More data? Enter 0 to continue and 1 to exit: 0
Please enter an integer to be enqueued : 4
More data? Enter 0 to continue and 1 to exit: 0
Please enter an integer to be enqueued : 5
More data? Enter 0 to continue and 1 to exit: 0
Please enter an integer to be enqueued : 6
More data? Enter 0 to continue and 1 to exit: 1
Now printing the integers in the Queue.
1  2  3  4  5  6
We will enqueue some characters in the Queue now.
Please enter an character to be put in the Queue : A
More data? Enter 0 to continue and 1 to exit: 0
Please enter an character to be put in the Queue : B
More data? Enter 0 to continue and 1 to exit: 0
Please enter an character to be put in the Queue : C
More data? Enter 0 to continue and 1 to exit: 0
Please enter an character to be put in the Queue : D
More data? Enter 0 to continue and 1 to exit: 0
Please enter an character to be put in the Queue : E
More data? Enter 0 to continue and 1 to exit: 0
Please enter an character to be put in the Queue : F
More data? Enter 0 to continue and 1 to exit: 1
Now printing the characters in the Queue.
A  B  C  D  E  F
We will enqueue some floating point numbers in the Queue now.
Please enter a floating point number to be added to the Queue : 1.0
More data? Enter 0 to continue and 1 to exit: 0
Please enter a floating point number to be added to the Queue : 2.0
More data? Enter 0 to continue and 1 to exit: 0
Please enter a floating point number to be added to the Queue : 3.0
More data? Enter 0 to continue and 1 to exit: 0
Please enter a floating point number to be added to the Queue : 4.0
More data? Enter 0 to continue and 1 to exit: 0
Please enter a floating point number to be added to the Queue : 5.0
More data? Enter 0 to continue and 1 to exit: 1
Now printing the floating point numbers  in the Queue.
1  2  3  4  5
We will enqueue some strings in the Queue now.
Please enter an string to be added to the Queue : AA
More data? Enter 0 to continue and 1 to exit: 0
Please enter an string to be added to the Queue : BB
More data? Enter 0 to continue and 1 to exit: 0
Please enter an string to be added to the Queue : CC
More data? Enter 0 to continue and 1 to exit: 0
Please enter an string to be added to the Queue : DD
More data? Enter 0 to continue and 1 to exit:
0
Please enter an string to be added to the Queue : EE
More data? Enter 0 to continue and 1 to exit: 1
Now printing the strings in Queue.
AA  BB  CC  DD  EE
Press any key to continue . . .











*/