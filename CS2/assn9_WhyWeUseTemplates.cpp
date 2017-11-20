#include <iostream>
#include <string>
#include <fstream>
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
		out << "Student Name: " << S.name << endl;
		out << "GPA: " << S.GPA << endl;
		return out;
	}
};

void print(int data);
void print(double data);
void print(char data);
void print(string data);
void print(Student data);

int main()
{

	system("pause");
	return 0;
}
void print(int data)
{
	cout << data << endl;
}
void print(double data)
{
	cout << data << endl;
}
void print(char data)
{
	cout << data << endl;
}
void print(string data)
{
	cout << data << endl;
}
void print(Student data)
{
	cout << data << endl;
}
