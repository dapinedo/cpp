#include "Node.h"

//BankAccount BA;
//Node * Next;

Node::Node(BankAccount B = BankAccount(), Node * N) : BA(B), Next(N)
{

}

const string Node::toString() const
{
	return (BA.toString() + " ");
}
