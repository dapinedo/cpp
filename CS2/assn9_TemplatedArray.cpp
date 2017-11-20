#include <iostream>
#include <string>
#include <iomanip>
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
	friend ostream & operator <<(ostream & out, const Student & S)
	{
		out << "Student Name: " << S.name << endl;
		out << "GPA: " << S.GPA << endl;
		return out;
	}

	friend bool operator >(const Student & S1, const Student & S2)
	{
		return S1.GPA > S2.GPA;
	}
};
//function template

template<typename T>
class GenArray
{
private:
	static const size_t MAX = 100;
	T arr[MAX];
	size_t numItems;
	bool isSorted;
public:
	GenArray();
	void add(T data);
	void print()const;
	void BubbleSort();
};

template<typename T>
GenArray<typename T>::GenArray() :numItems(0), isSorted(false)
{

}
template<typename T>
void GenArray<typename T>::add(T data)
{
	if (numItems == MAX)
	{
		cout << "List is full:" << endl;
		return;
	}
	arr[numItems++] = data;
	isSorted = false;
}

template<typename T>
void GenArray<typename T>::print()const
{
	for (size_t i = 0; i < numItems; i++)
	{
		cout << arr[i] << endl;
	}
}

template<typename T>
void GenArray<typename T>::BubbleSort()
{
	if (isSorted)
	{
		cout << "Array is already sorted." << endl;
		return;
	}

	if (numItems == 1)
	{
		cout << "Array has one item only. No need to sort." << endl;
		return;
	}

	for (size_t i = 0; i < numItems; i++)
	{
		for (size_t j = 0; j < numItems - 1 -i; j++)
		{
			if (arr[j] >  arr[j + 1])
			{
				T buffer = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = buffer;
			}
		}
	}
	isSorted = true;
}
int main()
{
	/*GenArray<int> intArr;
	intArr.add(3);
	intArr.add(2);
	intArr.add(4);
	intArr.add(1);
	intArr.add(8);
	cout << "Print before sorting." << endl;
	intArr.print();
	intArr.BubbleSort();
	cout << "Print after sorting." << endl;
	intArr.print();*/
	/*GenArray<string> names;
	names.add("Adam");
	names.add("Bertha");
	names.add("Cindy");
	names.add("Dawn");
	names.add("Ellen");
	names.print();*/

	GenArray<Student> StuList;
	Student S1("John Doe", 3.9);
	StuList.add(S1);
	Student S2("Mary Doe", 2.9);
	Student S3("Tim Jones", 3.3);
	Student S4("Meliza Queen", 2.5);
	StuList.add(S2);
	StuList.add(S3);
	StuList.add(S4);
	cout << "Print before sorting." << endl;
	StuList.print();
	StuList.BubbleSort();
	cout << "Print after sorting." << endl;
	StuList.print();
	system("pause");
	return 0;
}