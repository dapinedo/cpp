#pragma once
#ifndef COMPLEXNUMBERLIST_H
#define COMPLEXNUMBERLIST_H
#include "Complex.h"

class ComplexNumberList
{
private:
	const static size_t MAX = 30;
	Complex List[MAX];
	size_t len;
	/*
	list_state = 0 unsorted
	list_state = 1 for sorted based on real part 
	list_state = 2 for sorted based on imaginary part
	list_state = 3 for sorted based on absolute value
	*/
	size_t list_state;
public:
	ComplexNumberList();
	bool add(const Complex & C);
	friend ostream & operator<<(ostream & out, const ComplexNumberList & CL);
	friend istream & operator>>(istream & in,  ComplexNumberList & CL);

	~ComplexNumberList();
};

#endif

