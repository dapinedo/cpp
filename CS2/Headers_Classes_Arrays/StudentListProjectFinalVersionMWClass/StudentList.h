#pragma once
#ifndef STUDENTLIST_H
#define STUDENTLIST_H
#include "Student.h"
#include <cmath>
class StudentList
{
private:
    /**
     * The GPA value below which Student will be placed on academic
     * probation.
     */
    static const double ACADEMIC_PROBATION_THRESHOLD;
    /**
     * The GPA value at or above which student is placed in honors list.
     */
    static const double HONORS_LIST_GPA;
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
    ///////////////////////////////////////////////
    bool deleteStudent(const Student & st);
    ///////////////////////////////////////////
    bool updateStudent(const Student & st);
    ////////////////////////////////////////////////
    size_t getList_State()const;
    /////////////////////////////////////
    static size_t getCapacity();
    /////////////////////////////////////////
    void makeEmpty();
    /////////////////////////////////////////////
    const Student getStudentAt(int index) const;
    ///////////////////////////////////////////////////
    bool setStudentAt(const Student & s, int index);
    /////////////////////////////////////////////////////////////
    static void getInstance(istream & in, StudentList & SL);
    /////////////////////////////////////////////////////////////////
    void print(ostream & out = cout);
    /////////////////////////////////////////////////
    size_t getLength() const;
    ///////////////////////////////////////////////
    const string getListStateDescription() const;
    /////////////////////////////////////////////////////
    void getMeanGPA(double & meanGP) const;
    void getStandardDevGPA(double & StdDev) const;
    void getMinimumGPA(double & min_gpa) const;
    void getMaximumGPA(double & max_gpa) const;
    void getAcademicProbationList(StudentList & SAL) const;
    void getHonorsList(StudentList & SAL) const;
    void printHeader(ostream & out = cout);
    void printStatistics(ostream & out = cout);
    int binSearch(const Student & key) const;
    bool isFull() const;
    bool isEmpty() const;
    bool searchLastName(const Student & Key, int & whereFound);
    //Copy Constructor
    StudentList(const StudentList & SL);
    //Overloaded Assignment Operator
    const StudentList & operator = (const StudentList & SL);
};

#endif
