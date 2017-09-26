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

bool StudentList::deleteStudent(const Student & st)
{
	bool deleted = false;

	if (len != 0)
	{
		// find out if ID in the st is in the array
		// That would mean that student to be deleted is present
		int index;
		bool found = find(st, index);
		if (found)
		{
			// Copy at the location called index the last
			// populated member of the List array
			List[index] = List[len - 1];
			len--;
			size_t flag = list_state;
			list_state = 0;
			bubbleSort(flag);
			// Alternate code is below
			//if (list_state == 0)
			//{
			//	// No code needed
			//}
			//else 
			//if (list_state == 1)
			//{
			//	bubbleSort(1); // resort on id
			//}
			//else if (list_state == 2)
			//{
			//	bubbleSort(2); // resort on id
			//}
			//else if (list_state == 3)
			//{
			//	bubbleSort(3); // resort on id
			//}
			deleted = true;
		}
		else
		{
			cout << "Student with ID: " << st.getID() << " is not in the list" << endl;
		}

	}
	else
	{
		cout << "List is empty." << endl;
	}

	return deleted;
}

bool StudentList::updateStudent(const Student & st)
{
	bool updated = false;

	if (len != 0)
	{
		// find out if ID in the st is in the array
		// That would mean that student to be deleted is present
		int index;
		bool found = find(st, index);

		if (found)
		{
			// update for GPA
			cout << "Enter new GPA or -1 to not update GPA: ";

			double gp;
			cin >> gp;

			if (gp>0.0)
			{
				List[index].setGPA(gp);
				list_state = 0;
				/*
				drill: check if list is already sorted on GPA
				if yes then resort on GPA and make whole code work
				*/
				updated = true;
			}
			else
			{
				cout << "You chose not to update GPA." << endl;
			}

			cout << "Enter new last name or 123 to not change last name: ";
			string lst;
			cin >> lst;

			if (lst != "123")
			{
				List[index].setLastName(lst);
				list_state = 0;
				/*
				drill: check if already sorted on last name.
				if yes then resort on last name and make 
				whole code work.
				*/
				updated = true;
			}
			else
			{
				cout << "You chose not to update last name." << endl;
			}
		}
		else
		{
			cout << "Student with ID: " << st.getID() << " is not in the list" << endl;
		}
	}
	else
	{
		cout << "List is empty." << endl;
	}

	return updated;
}

StudentList StudentList::getInstance(istream & in)
{
	StudentList SL;

	if (&cin == &in)// Filling from keyboard
	{
		//StudentList SL;
		
		bool done = false;

		while (!done && SL.len<StudentList::MAX)
		{
			Student temp = Student::getInstance(cin);
			SL.add(temp);
			cout << "More data? Enter 0 to continue or 1 to stop: ";
			cin >> done;
			cout << "Current List Length = " << SL.len << endl;
		}
	}

	return SL;
}


void StudentList::print() const
{
	for (size_t i = 0; i < len; i++)
	{
		List[i].Print();
	}
}

//Copy Constructor
StudentList::StudentList(const StudentList & SL):len(SL.len), list_state(SL.list_state)
{
	for (size_t i=0; i<StudentList::MAX; i++) {
		List[i] = SL.List[i];
	}
}
//Overloaded Assignment operator
const StudentList & StudentList::operator = (const StudentList & SL)
{
	if (this != &SL) {
		for (size_t i=0; i<StudentList::MAX; i++) {
			List[i] = SL.List[i];
		}
		len = SL.len;
		list_state = SL.list_state;
	}
	return *this;
}
