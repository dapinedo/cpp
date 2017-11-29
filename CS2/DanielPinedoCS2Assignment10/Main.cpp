#include "iterator.h"
#include "linkedlistinterface.h"

/*
requirements to add classes to binary search tree:
1. Must overload relational operators (>, <, ==, !=) in class init/def
2. must overload stream operators (ostream <<, istream >>) in class init/def

e.g.,
//initialization
friend bool operator == (const Student & left, const Student & right);
friend ostream & operator << (ostream & out, const Student & S); //to.String() implementation
friend istream & operator << (ostream & out, Student & S); //getInstance() implementation
//definition
bool operator == (const Student & left, const Student & right);
{
	return left.ID = right.ID;
}
ostream & operator << (ostream & out, const Student & S)
{
	out << S.toString();
	return out;
}
istream & operator << (ostream & out, Student & S)
{
	S = Student::getInstance(in); //call static getInstance function
}
*/

int main()
{
	// test by creating int Binary Search Tree
	BinarySearchTree<int> IntBST;
	// test by adding elements to Binary Search Tree (left = <, right = >)
	IntBST.add(11);
	IntBST.add(12);
	IntBST.add(10);
	IntBST.add(16);
	IntBST.add(15);
	IntBST.add(13);
	IntBST.add(14);
	// print in order
	IntBST.printInorder(cout);
}