#include "StudentList.h"

StudentList::StudentList():len(0), list_state(0)
{
}
// Drill: do a version of find function that would take
// a flag as additional argument and do search bsed either on ID
// or on last name call this other function as find2
bool StudentList::find(const Student & key, int & whereFound)
{
	whereFound = -1;
	bool found = false;

	for (size_t i = 0; i < len; i++)
	{
		if (key.getID() == List[i].getID())
		{
			whereFound = i;
			found = true;
			break;
		}
	}

	return found;
}

const string StudentList::toString() const
{
	if (len == 0)
	{
		return "List is Empty\n";
	}

	string temp;

	for (size_t i = 0; i < len; i++)
	{
		temp += List[i].toString();
	}

	return temp;
}

bool StudentList::add(const Student & S)
{
	if (len == MAX)
	{
		cout << "The list is full." << endl;
		return false;
	}
	// Find if S is already in the list or not
	// add if not there.
	bool found;
	int whereFoud = -1;
	found = find(S, whereFoud);

	if (!found)// not there. add it
	{
		List[len] = S;
		len++;
		list_state = 0;// Because we may be adding to a sorted list
		return true;
	}
	else
	{
		cout << "Student with ID: " << S.getID() << " is already in the list." << endl;
		return false;
	}
	
}

void StudentList::bubbleSort(size_t flag)
{
	if (list_state == 1 && flag == 1)
	{
		cout << "List is already sorted based on ID." << endl;
		return;
	}
	 
   if (list_state == 2 && flag == 2)
	{
	cout << "List is already sorted based on Last Name." << endl;
	return;
	}

   if (list_state == 3 && flag == 3)
   {
	   cout << "List is already sorted based on GPA." << endl;
	   return;
   }
   // sort otherwise
   for (size_t i = 0; i < len; i++)
   {
	   for (size_t j = 0; j < len-1-i; j++)
	   {
		   if (flag == 1)// sort on ID
		   {
			   if (List[j].getID() > List[j+1].getID())
			   {
				   Student buffer = List[j];
				   List[j] = List[j + 1];
				   List[j + 1] = buffer; 
			   }
		   }
		   else if (flag == 2)// sort based on last name case insensitive
		   {
				//Drill: Complete byourself and test that it is working
		   }
		   else if (flag == 3)// sort based on GPA
		   {
			   //Drill: Complete byourself and test that it is working
		   }
	   }
   }
   list_state = flag;
}