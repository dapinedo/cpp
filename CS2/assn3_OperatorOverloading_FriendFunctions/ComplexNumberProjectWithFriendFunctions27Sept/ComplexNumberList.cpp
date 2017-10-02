#include "ComplexNumberList.h"



ComplexNumberList::ComplexNumberList():len(0), list_state(0)
{
}

bool ComplexNumberList::add(const Complex & C)
{
	if (len == MAX)
	{
		cout << "List is full." << endl;
		return false;
	}

	List[len] = C;
	len++;
	list_state = 0;
	return true;
}

ostream & operator<<(ostream & out, const ComplexNumberList & CL)
{
	for (size_t i = 0; i < CL.len; i++)
	{
		out << CL.List[i];
	}

	return out;
}
istream & operator>>(istream & in, ComplexNumberList & CL)
{
	if (&in == &cin)
	{
		bool done = false;

		while (!done && CL.len<ComplexNumberList::MAX)
		{
			Complex temp;
			cin >> temp;
			CL.add(temp);
			cout << "More data? Enter 0 to continue or 1 to stop: ";
			cin >> done;
		}
	}
	else
	{
		while (in.peek() != EOF && CL.len<ComplexNumberList::MAX)
		{
			Complex temp;
			in >> temp;
			CL.add(temp);
		}
	}

	return in;
}
ComplexNumberList::~ComplexNumberList()
{
}
