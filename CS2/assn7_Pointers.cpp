#include <iostream>
using namespace std;

class Foo
{
private:
	int x;
public:
	//default constructor
	Foo()
	{
		cout << "The address of current object in constructor: " << (long)(this) << endl;
		cout << "From default constructor." << endl;
	}
	//Explicit constructor
	Foo(int y) :x(y)
	{
		cout << "From Explicit constructor." << endl;
	}
	//copy constructor
	Foo(const Foo & F) :x(F.x)
	{
		cout << "From copy constructor" << endl;
	}
	//overloaded assignment operator
	const Foo & operator = (const Foo & F)
	{
		this->x = F.x;
		cout << "From assignment operator" << endl;
		return *this;
	}
	//destructor
	~Foo()
	{
		cout << "The address of current object in destructor: " << (long)(this) << endl;

		cout << "From destructor." << endl;
	}
};


void FooBar(Foo F4)
{

}
int main2()
{
	{
		Foo F1, F2, F3;
		//cout << "Address of F1 in main function: " << (long)(&F1) << endl;
	}

	system("pause");
	return 0;
}

int main()
{
	{
		Foo F;
		//cout << "The address printed in the main function: "
		//	<< (long)(&F) << endl;
		Foo F2(5);
		F = F2;
		FooBar(F);
	}
	system("pause");
	return 0;
}
/*
The address of current object: 14876228
From default constructor.
The address printed in the main function: 14876228
From Explicit constructor.
From assignment operator
From copy constructor
From destructor.
From destructor.
From destructor.

*/