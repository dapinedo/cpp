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
//function template
template<typename T>
void print(T data);

int main()
{
	print<int>(3);
	print<double>(9.9);
	print<char>('P');
	print<string>("Hello world");
	Student s1("John Doe", 3.9);
	print<Student>(s1);
	system("pause");
	return 0;
}

template<typename T>
void print(T data)
{
	cout << data << endl;
}