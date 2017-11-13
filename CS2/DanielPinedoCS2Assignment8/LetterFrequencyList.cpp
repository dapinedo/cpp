#include "LetterFrequencyList.h"

//private:
//returns true if letter is present in list. Called from inside insertInOrder()
bool LetterFrequencyList::contains(char ltr)
{
	// start with dummy node
	LetterNode * Current = Headptr;
	while (Current != nullptr) {
		if (ltr == Current->letter) {
			Current->frequency += 1;
			return true;
		}
		Current = Current->Next;
	}
	return false;
}

//constructor
LetterFrequencyList::LetterFrequencyList() : Headptr(new LetterNode())
{
}

//Rule 1. copy constructor
LetterFrequencyList::LetterFrequencyList(const LetterFrequencyList & Other)
{
	if (this == &Other) {
		cout << "Self copying not allowed. Exiting program. \n";
		exit(0);
	}
	copy(Other);
}
//Rule 2. assignment operator
const LetterFrequencyList & LetterFrequencyList::operator = (const LetterFrequencyList & Other)
{
	if (this != &Other) {
		destroy();
		copy(Other);
	}
	return *this;
}

// helper function for Rule 1 and 2
void LetterFrequencyList::copy(const LetterFrequencyList & Other)
{
	LetterNode *Current = Other.Headptr->Next;
	// create dummy code
	LetterNode *Iterator = Headptr = new LetterNode();
	while (Current != nullptr) {
		// create a copy of node pointed to by Current, and link 
		Iterator->Next = new LetterNode(Current->letter, Current->frequency, nullptr);
		//update pointers
		Current = Current->Next;
		Iterator = Iterator->Next;
	}
}

// helper function for delete
void LetterFrequencyList::destroy()
{
	// start with dummy node
	LetterNode * Current = Headptr;
	while (Current != nullptr) {
		LetterNode *save = Current;
		Current = Current->Next;
		delete save;
	}
}
// helper function for inserting new value
void LetterFrequencyList::insert(char ltr, size_t frq = 1)
{
	Headptr->Next = new LetterNode(ltr, frq, Headptr->Next);
}

//if letter is not present then LetterNode is added in ascending order
void LetterFrequencyList::insertInOrder(char ltr)
{
	if (contains(ltr)) {
		return;
	}
	else {
		insert(ltr);
	}
}
//Rule 3. destructor
LetterFrequencyList::~LetterFrequencyList()
{
	destroy();
}

const string LetterFrequencyList::toString()
{
	if (!(Headptr == nullptr)) {
		string text = "";
		LetterNode * Iterator = Headptr->Next;
		//Traverse linked list using iterator and add all data to text
		while (Iterator != nullptr) {
			text += (Iterator->toString());
			Iterator = Iterator->Next;
		}
		return (text + '\n');
	}
	else {
		throw "Exception thrown";
	}
}
