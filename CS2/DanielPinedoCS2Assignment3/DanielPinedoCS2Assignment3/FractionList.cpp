#include "FractionList.h"

FractionList::FractionList() : num_elements(0), isSorted(false)
{
}

void FractionList::addFraction(const Fraction & F)
{
	if (num_elements == MAX) {
		cout << "List is full." << endl;
		return;
	}
	List[num_elements] = F;
	num_elements++;
}
const string FractionList::toString() const
{
	string temp = "";
	for (size_t i = 0; i < num_elements; i++) {
		temp += List[i].toString();
	}
	return temp;
}

void FractionList::sort()
{
	for (size_t i = 0; i < num_elements; i++) {
		for (size_t j = 0; j < num_elements - 1 - i; j++) {
			if (List[j].toDouble() > List[j + 1].toDouble()) {
				Fraction temp = List[j];
				List[j] = List[j + 1];
				List[j + 1] = temp;
			}
		}
	}
	isSorted = true;
}

bool FractionList::isEmpty() const
{
	return (num_elements == 0);
}
bool FractionList::isFull() const
{
	return (num_elements == MAX);
}
size_t FractionList::getNumberOfElements() const
{
	return num_elements;
}

istream & operator >> (istream & in, FractionList & FL)
{
	FractionList::getInstance(FL, in);
	return in;
}

ostream & operator << (ostream & out, FractionList & FL)
{
	for (size_t i = 0; i < FL.num_elements; i++) {
		out << FL.List[i]; 
	}

	return out;
}

void FractionList::getInstance(FractionList & FL, istream & in = cin)
{
	if (&in == &cin) {
		bool done = false;
		while (!done && (FL.num_elements < FractionList::MAX)) {
			Fraction temp(0);
			cin.ignore(20, '\n');
			cin >> temp;
			FL.addFraction(temp);
			cout << "More fractions? Enter 0 to continue or 1 to stop: ";
			cin >> done;
		}
	}
	else {
		while ((in.peek() != EOF) && (FL.num_elements < FractionList::MAX)) {
			Fraction temp(0);
			in >> temp;
			FL.addFraction(temp);
		}
	}
}

const Fraction FractionList::getLargest()
{
	if (isSorted) {
		return List[num_elements - 1];
	}
	else {
		sort();
		return List[num_elements - 1];
	}
}

const Fraction FractionList::getSumOfFractions()
{
	Fraction temp(0);
	for (size_t i = 0; i < num_elements; i++) {
		temp = temp + List[i];
	}
	return temp;
}

bool FractionList::getSortState() const
{
	return isSorted;
}

Fraction FractionList::operator [] (size_t index) const
{
	if (index < num_elements) {
		return List[index];
	}
	throw "Out of bounds array at index";
}

FractionList::~FractionList()
{
}
