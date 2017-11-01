#pragma once
#ifndef STACK_H
#define STACK_H
#include "StackInterface.h"
#include <iostream>
using namespace std;
/*
Author: Satish Singhal Ph. D.
Date: 10/25/2014
Operating System: Windows 7
Compiler: Visual Studio 2013
Stack class implements StackInterface abstract class. This version is self growing
when the array on to which items are pushed is filled. The self expanding array
is implemented by using a pointer of ItemType, that points to a dynamically
allocated and growing array. The memory allocation for this array is done inside
the constructor of Stack Class.

Since this class contains a pointer data member for whcih memory allocation is done
inside the constructor, the rule of three kicks in. The rule of three requires that
when a class has one or more pointer data members for which the memory allocation is
done inside the constructor, then the class must provide the below to replace defaults:
1. A destructor that will dellocate the memory that was allocated by the constructor.
Understand that destructor are:
A. Not overloadable
B. Are NEVER called in programmer code by the programmer. They work behind the scene 
automatically.
C. Are NOT ALLOWED to take arguments.
D. Have same name as class name but with a ~ in front.

2. I user defined copy constructor that meakes deep copies.
3. A user defined Assignment operator that makes a deep copy when one object
is copied into other using the assignment operator.

Since class would have an array that would expand by itself when push is attempted
after array is filled, major changes are required to push function that was there in the
limited array class earlier used by you in assignments 4 and 5.
*/
class Stack :public StackInterface
{
private:
	/*
	Constant storing initial MAX capcity of the array. For revealing bugs in code, 
	this must be set to 1.
	*/
	const static int MAX = 1;
	/*
	Constant storing the number by which array must grow when previous array is filled and additional
	elements are pushed on to the stack.. 
	For revealing bugs in code,this must be set to 1.
	*/
	const static int GROWBY = 1;
	int top_position;
	/*
	ItemType pointer data member which points to dynamically growing and managed array
	that holds the stack.
	*/
	ItemType * items;
	/*
	Number of items in the stack;
	*/
	size_t numItems;
	/*
	Capacity of the array holding stack elements.
	*/
	size_t arrayCapacity;
public:
	void push(ItemType item);
	void pop();
	ItemType top() const;
	bool isEmpty() const;
	Stack();
	/*
	Programmer defined destructor deallocates the memory that was assigned inside the
	constructor. The programmer defined constructor is another part of rule of three.
	*/
	~Stack();
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
	@param st is the Stack object being copied inside the copy constructor.
	*/
	Stack(const Stack & st);
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
	@param Stk is the stack object on right side of assignment operator
	@return the value to be copied in the left side of assignment operator.
	*/
	const Stack & operator = (const Stack & Stk);
	/*
	Functoion getArrayCapacity returns the capacity of the array used for stack when call to
	this function is made.
	@return the capacity of array used to hold stack elements.
	*/
	size_t getArrayCapacity() const;
	/*
	Function getNumItems returns the number of items in the stack at the time when this function
	is called.
	@return the number of elements stored in the stack.
	*/
	size_t getNumItems() const;
protected:
	/*
	copy function is optional. However it condenses the copy code that would be used in both
	the copy constructor and in the assignment operator. Use of this function advances
	the code resuse technology.
	@param Stk is the stack object to be copied to this Stack object.
	*/
	void copy(const Stack & Stk);
private:
	/*
	Function isFull is not needed in the dynamically growing stack. However,
	we must give it a body because it was a pure virtual function in StackInterface
	class and since Stack class derives fron StackInterface class, it must be 
	implemented to allow to create objects of type Stack. [Recall that if a base class
	pure virtual function is not implemmented by the derived class, then derived class
	will also become abstract, and cannot be instantiated]. You can just have the
	function return false as the dynamically growing stack will never be full.
	@return false because dynamically growing stack always has capacity to add more elements.
	*/
	bool isFull() const;
};
#endif