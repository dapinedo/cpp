#include "BankAccountLinkedList.h"

//constructor
BankAccountLinkedList::BankAccountLinkedList() : Head(new Node(BankAccount(), nullptr))
{
	cout << "From constructor.\n";
}
//Rule 1. copy constructor
BankAccountLinkedList::BankAccountLinkedList(const BankAccountLinkedList & Other)
{
	cout << "From Copy constructor. \n";
	if (this == &Other) {
		cout << "Self copying not allowed. Exiting program. \n";
		exit(0);
	}
	copy(Other);
}
//Rule 2. assignment operator
const BankAccountLinkedList & BankAccountLinkedList::operator = (const BankAccountLinkedList & Other)
{
	cout << "From assignment operator.\n";
	if (this != &Other) {
		destroy();
		copy(Other);
	}

	return *this;
}

// helper function for Rule 1 and 2
void BankAccountLinkedList::copy(const BankAccountLinkedList & Other)
{
	Node *Current = Other.Head->Next;
	// create dummy code
	Node *Iterator = Head = new Node(BankAccount(), nullptr);
	while (Current != nullptr) {
		// create a copy of node pointed to by Current, and link 
		Iterator->Next = new Node(Current->BA, nullptr);
		//update pointers
		Current = Current->Next;
		Iterator = Iterator->Next;
	}
}

// helper function for delete
void BankAccountLinkedList::destroy()
{
	// start with dummy node
	Node * Current = Head;
	while (Current != nullptr) {
		Node *save = Current;
		Current = Current->Next;
		delete save;
	}
}
// helper function for inserting new value
void BankAccountLinkedList::insert(BankAccount B)
{
	Head->Next = new Node(B, Head->Next);
}
//Rule 3. destructor
BankAccountLinkedList::~BankAccountLinkedList()
{
	cout << "From destructor. \n";
	destroy();
}

const string BankAccountLinkedList::toString() const
{
	if (!(Head == nullptr)) {
		string text = "";
		Node * Iterator = Head->Next;
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