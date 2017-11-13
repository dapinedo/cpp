#include "LetterNode.h"

//size_t frequency;
//char letter;
//LetterNode * Next;


LetterNode::LetterNode(char ch, size_t frq, LetterNode * ptr) : 
	frequency(frq), letter(ch), Next(ptr)
{
}

const string LetterNode::toString()
{
	ostringstream toReturn;
	toReturn << "The letter " << this->letter << " has occurred " << this->frequency << " times\n";
	return toReturn.str();
}


