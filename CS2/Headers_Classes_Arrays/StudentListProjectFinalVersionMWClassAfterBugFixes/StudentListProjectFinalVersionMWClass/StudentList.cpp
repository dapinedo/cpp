#include "StudentList.h"


const double StudentList::ACADEMIC_PROBATION_THRESHOLD = 2.0;
const double StudentList::HONORS_LIST_GPA = 3.8;
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
			whereFound = static_cast<int>(i);
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
               string name1 =  List[j].getLastName();
               for(auto & dummy:name1 ) dummy = toupper(dummy);
               string name2 = List[j+1].getLastName();
               for(auto & dummy:name2 ) dummy = toupper(dummy);
               
               if (name1>name2) {
                   Student buffer = List[j];
                   List[j] = List[j + 1];
                   List[j + 1] = buffer;
               }
		   }
		   else if (flag == 3)// sort based on GPA
		   {
               if (List[j].getGPA() > List[j+1].getGPA())
               {
                   Student buffer = List[j];
                   List[j] = List[j + 1];
                   List[j + 1] = buffer; 
               }
           }
	   }
   }
   list_state = flag;
}
//////////////////////////////////////////////////
bool StudentList::deleteStudent(const Student & st)
{
    bool deleted = false;
    if (len == 0)
    {
        cout << "List is empty" << endl;
        return deleted;
    }
    
    bool found;
    int whereFound = -1;
    found = find(st, whereFound);
    if (found)// Its there we can delete it
    {
        List[whereFound] = List[len - 1];
        len--;
        
        if (list_state == 1)
        {
            //Resort based on ID
            bubbleSort(1);
        }
        else if (list_state == 2)
        {
            //Resort based on last name
            bubbleSort(2);
        }
        else if (list_state == 3)
        {
            //Resort based on GPA
            bubbleSort(3);
        }
		deleted = true;
    }
    else// Not there - can'nt delete it
    {
        cout << "Student with record below is not in the list." << endl;
        cout << st.toString();
    }
    
    return deleted;
}

bool StudentList::updateStudent(const Student & st)
{
    bool updated = false;
    if (len == 0)
    {
        cout << "List is empty" << endl;
        return updated;
    }
    
    bool found;
    int whereFound = -1;
    found = find(st, whereFound);
    
    if (!found)
    {
        cout << "The student with below record not found." << endl;
        cout << st.toString() << endl;
        return updated;
    }
    
    cout << "Enter new GPA or enter negative value to not change the GPA: ";
    double gp;
    cin >> gp;
    
    if (gp >0.0)
    {
        List[whereFound].setGPA(gp);
        list_state = 0;
        updated = true;
    }
    
    cout << "Enter the new last name or enter 123 to not change last name: ";
    string lst;
    cin >> lst;
    
    if (lst != "123")
    {
        List[whereFound].setLastName(lst);
        list_state = 0;
        updated = true;
    }
    return updated;
}
///////////////////////////////
size_t StudentList::getList_State()const
{
    return list_state;
}
///////////////////////////////////////////
size_t StudentList::getCapacity()
{
    return MAX;
}
//////////////////////////////////////////
void StudentList::makeEmpty()
{
    len = 0;
    list_state = 0;// Explain the reason for this statement
}
//////////////////////////////////////////////////
const Student StudentList::getStudentAt(int index) const
{
    // Make sure that index is inbound between 0 and len-1
    
    if (index>= 0 && index<static_cast<int>(len))
    {
        return List[index];
    }
    
    throw "Invalid array index.";
}
///////////////////////////////////////////////////////////
bool StudentList::setStudentAt(const Student & s, int index)
{
	if (len == 0)
	{
		cout << "List is empty.Use add function if need to add student." << endl;
		return false;
	}
	// Make sure that student is not already in the list
	int whereFound;

	if (find(s, whereFound))
	{
		cout << "The student with ID " << s.getID()
			<< " is already in list. Duplicate ID's not allowed." << endl;
		return false;
	}
    // Make sure that index is inbound between 0 and len-1
    if (index >= 0 && index < static_cast<int>(len))
    {
        List[index] = s;
        return true;
    }
    
    cout << "Index: " << index << " is out of bound." << endl;
    return false;
}
void StudentList::getInstance(istream & in, StudentList & SL)
{
    if(&in == &cin)
    {
        bool done = false;
        
        while (!done && SL.len<StudentList::MAX) {
            Student temp = Student::getInstance(cin);
            SL.add(temp);
            cout<<"More data? Enter 0 to continue and 1 to exit data entry: ";
            cin>>done;
        }
        
    }
    else{
        // Two things to remember when filling arrays from file
        // Filling loop shoud exit when end of file has been reached
        // Filling loop should also exit when array is filled to the capacity
        
        while ( in.peek() != EOF && SL.len<StudentList::MAX)
        {
            Student temp = Student::getInstance(in);
            SL.add(temp);
        }
    }
}
////////////////////////////////////////////////////
void StudentList::print(ostream & out)
{
    out<<toString()<<endl;
}
//////////////////////////////////////////////////
bool StudentList::isFull() const
{
    return len == StudentList::MAX;
}
///////////////////////////////////////////
bool StudentList::isEmpty() const
{
    return len == 0;
}
/////////////////////////////////////////////
size_t StudentList::getLength() const
{
    return len;
}
//////////////////////////////////////////////
const string StudentList::getListStateDescription() const
{
    string descrp = "";
    if (list_state == 0)
    {
        descrp = "List is unsorted";
    }
    else if (list_state == 1)
    {
        descrp = "List is sorted based on ID";
    }
    else if (list_state == 2)
    {
        descrp = "List is sorted based on last name";
    }
    else if (list_state == 3)
    {
        descrp = "List is sorted based on GPA";
    }
    
    return descrp;
}
////////////////////////////////////////////////////////////
void StudentList::getMeanGPA(double & meanGP) const
{
    if (len == 0)
    {
        cout << "List is Empty. No mean can be found." << endl;
        return;
    }
    
    meanGP = 0.0;
    double sum = 0.0;
    
    for (unsigned int index = 0; index < len; index++)
    {
        sum += List[index].getGPA();
    }
    
    meanGP = sum / len;
}
void StudentList::getStandardDevGPA(double & StdDev) const
{
    if (len == 0)
    {
        cout << "List is Empty. No mean can be found." << endl;
        return;
    }
    double SumofSquares = 0.0;
    
    for (unsigned int i = 0; i < len; i++)
    {
        double gp = List[i].getGPA();
        SumofSquares += gp * gp;
    }
    double Mean = 0.0;
    getMeanGPA(Mean);
    StdDev = sqrt((SumofSquares / (len)) - Mean* Mean);
}
void StudentList::getMinimumGPA(double & min_gpa) const
{
    if (len == 0)
    {
        cout << ("List is empty") << endl;
        return;
    }
    
    min_gpa = List[0].getGPA();
    
    for (unsigned int index = 1; index < len; index++)
    {
        if (min_gpa > List[index].getGPA())
        {
            min_gpa = List[index].getGPA();
        }
    }
}
void StudentList::getMaximumGPA(double & max_gpa) const
{
    if (len == 0)
    {
        cout << ("List is empty") << endl;
    }
    
    max_gpa = List[0].getGPA();
    
    for (unsigned int index = 1; index < len; index++)
    {
        if (max_gpa < List[index].getGPA())
        {
            max_gpa = List[index].getGPA();
        }
    }
}
void StudentList::getAcademicProbationList(StudentList & SAL) const
{
    if (len == 0)
    {
        cout << ("List is empty") << endl;
    }
    
    for (unsigned int index = 0; index < len; index++)
    {
        if (List[index].getGPA() < ACADEMIC_PROBATION_THRESHOLD)
        {
            SAL.add(List[index]);
        }
    }
}
void StudentList::getHonorsList(StudentList & SAL) const
{
    if (len == 0)
    {
        cout << "The list is empty" << endl;
        return;
    }
    
    
    for (unsigned int index = 0; index < len; index++)
    {
        if (List[index].getGPA() >= HONORS_LIST_GPA)
        {
            SAL.add(List[index]);
        }
    }
}
void StudentList::printHeader(ostream & out)
{
    out << endl << "********************************************************************************************" << endl;
    out << left << setfill(' ') << setw(20) << "Student Name" << setfill(' ') << setw(35) << " Student ID" << right << setfill(' ') << setw(10) << "GPA" << endl
    << "********************************************************************************************" << endl;
}
void StudentList::printStatistics(ostream & out)
{
    double maxGPA;
    this->getMaximumGPA(maxGPA);
    out << "Maximum GPA: " << maxGPA << endl;
    double minGPA;
    this->getMinimumGPA(minGPA);
    out << "Minimum GPA: " << minGPA << endl;
    double meanGPA;
    this->getMeanGPA(meanGPA);
    out << "Mean GPA: " << meanGPA << endl;
    
    double sd;
    this->getStandardDevGPA(sd);
    out << "Standard Deviation of GPA." << sd << endl;
    out << "Number of students in the list: " << len << endl;
    out << "**************************************************************************" << endl;
}
int StudentList::binSearch(const Student & key) const
{
    if (list_state != 2)
    {
        cout << "List is not sorted on last name. Binary search cannot be done." << endl;
        return -1;
    }
    
    int index = -1;
    int lowest_index = 0;
    int highest_index = static_cast<int>(len - 1);
    
    while (highest_index >= lowest_index)
    {
        int middle_index = (lowest_index + highest_index) / 2;
        
        if (List[middle_index].getLastName() == key.getLastName())
        {
            index = middle_index;
            break;
        }
        
        else if (List[middle_index].getLastName()>(key.getLastName()))
            highest_index = middle_index - 1;
        
        else if (List[middle_index].getLastName()<(key.getLastName()))
            lowest_index = middle_index + 1;
    }
    
    return index;
}

bool StudentList::searchLastName(const Student & Key, int & whereFound)
{
    bool found = false;
    
    for (size_t i=0; i<len; i++) {
        string nameInKey =  Key.getLastName();
        for(auto & dummy:nameInKey ) dummy = toupper(dummy);
        string nameInList = List[i].getLastName();
         for(auto & dummy:nameInList ) dummy = toupper(dummy);
        
        if (nameInKey == nameInList) {
            whereFound = static_cast<int>(i);
            found = true;
            break;
        }//if
    }//for loop
    
    return found;
}//function
////////////////////////////////////////////////////////////////////
//Copy Constructor
StudentList::StudentList(const StudentList & SL)
{
    for (size_t i = 0; i<StudentList::MAX; i++) {
        List[i] = SL.List[i];
    }
    len = SL.len;
    list_state = SL.list_state;
}
//Overloaded Assignment operator
const StudentList & StudentList::operator = (const StudentList & SL)
{
    if (this != &SL) {
        for (size_t i = 0; i<StudentList::MAX; i++) {
            List[i] = SL.List[i];
        }
        len = SL.len;
        list_state = SL.list_state;
    }
    return *this;
}
