#include "Stack.h"

// public:
/*
Copy Constructor is a part of rule of three implementation. Default
copy constructor provided by C++ only makes shallow copies. To make deep
copies of data pointed to by a pointer and allocated dynamically at runtime
a programmer defined copy constructor that would do that is needed.
Copy Constructor is called automatically when a function would return a value
of type Stack or when Stack object is passed by value to a function. Copy
constructor should NOT be called by user code. Goal of copy constructor
is to make deep copies of data which is pointed to by pointer when object
is either passed to a function by value or returned as a value from a function.
In order for me to confirm that your code works correctly, the below MUST be the
Last line in your Copy Constructor code.
cout << "From Stack Copy Constructor.\n";
@param st is the Stack object being copied inside the copy constructor.
*/
Stack::Stack(const Stack & st) : top_position(st.top_position), items(new ItemType(*(st.items))),
	numItems(st.numItems), arrayCapacity(st.arrayCapacity)
{
	if (this == &st) {
		cout << "Self copy is prohibited. Exiting." << endl;
		exit(1);
	}
	cout << "From Stack Copy Constructor.\n";
}

/*
Assignment operator is a part of rule of three implementation.
Default assignment operator provided by C++ only makes shallow copies. To make deep
copies of data pointed to by a pointer and allocated dynamically at runtime
a programmer defined assignment operator that would do that is needed.
Assignment operator is used when one object is copied into another using the
= operator. This must also work if = is used in a cascaded manner.
For example it must work if one does the following:
Stack X, Y, Z, T;
X= Y = Z = T;
The assignment operator MUST work correctly even when user attempts a self-copy. Example of
Self-copy is below.
Stack ST;
ST = ST;
For me to ascertain that your code follows rule of three and has no memory leak, please place
The code line below before the return statement in the assignment operator.
cout << "From Stack Assignment operator.\n";
@param Stk is the stack object on right side of assignment operator
@return the value to be copied in the left side of assignment operator.
*/
const Stack & Stack::operator = (const Stack & Stk)
{
	if (this == &Stk)
		return *this;
	delete this->items;
	this->top_position = Stk.top_position;
	this->items = new ItemType(*Stk.items);
	this->numItems = Stk.numItems;
	this->arrayCapacity = Stk.arrayCapacity;
	return *this;
	cout << "From Stack Assignment operator.\n";
}
/*
Function getArrayCapacity returns the capacity of the array used for stack when call to
this function is made.
@return the capacity of array used to hold stack elements.
*/
size_t Stack::getArrayCapacity() const
{
	return arrayCapacity;
}
/*
Function getNumItems returns the number of items in the stack at the time when this function
is called.
@return the number of elements stored in the stack.
*/
size_t Stack::getNumItems() const
{
	return numItems;
}
//protected:
	/*
	copy function is optional. However it condenses the copy code that would be used in both
	the copy constructor and in the assignment operator. Use of this function advances
	the code re-use technology.
	@param Stk is the stack object to be copied to this Stack object.
	*/
	void copy(const Stack & Stk);
// private:
	/*
	Function isFull is not needed in the dynamically growing stack. However,
	we must give it a body because it was a pure virtual function in StackInterface
	class and since Stack class derives from StackInterface class, it must be
	implemented to allow to create objects of type Stack. [Recall that if a base class
	pure virtual function is not implemented by the derived class, then derived class
	will also become abstract, and cannot be instantiated]. You can just have the
	function return false as the dynamically growing stack will never be full.
	@return false because dynamically growing stack always has capacity to add more elements.
	*/
	bool isFull() const;
};