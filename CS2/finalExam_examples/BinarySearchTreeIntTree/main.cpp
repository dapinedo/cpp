#include "binaryTree.h"
#include <iostream>
using namespace std;

int main()
{

	TreeType T;
	T.PutItem(20);
	T.PutItem(2);
	T.PutItem(21);
	T.PutItem(3);
	T.PutItem(31);

	T.Print();
	T.remove(20);
	T.Print();
	T.remove(99);
	system("pause");
	return 0;
}