#pragma once
#ifndef STUDENTLIST_H
#define STUDENTLIST_H
#include "Student.h"

class StudentList
{
private:
	const static size_t MAX = 30;// Capacity of the list
	Student List[MAX];
	size_t len;// Logical length of the list
	/*
	list_state = 0 for unsorted list
	list_state = 1 for sorted list based on ID
	list_state = 2 for sorted list based on last name
	list_state = 3 for sorted list based on GPA
	*/
	size_t list_state;
public:
	StudentList();
	bool find(const Student & key, int & whereFound);
	const string toString() const;
	// adds a student. Returns true if addition was successful
	//Otherwise returns false. Manage tha logical length
	// of the list
	bool add(const Student & S);
	/*
	flag =1 for ID based sorting
	flag = 2 for last name based sorting
	flag = 3 for GPA based sorting
	*/
	void bubbleSort(size_t flag);
};

#endif