#include "Arrayqueue.h"
#include <iostream>
#include <cassert>
using namespace std;
//-----------------------------------------------------------
ArrayQueue::ArrayQueue()
	:arrayCapacity(MAX), queue (new ItemType[MAX]), numItems(0),
	front(0), rear(-1)
{
}
//--------------------------------------------------------------------
//drill: write the initialization list version of below copy constructor
void ArrayQueue::copy(const ArrayQueue & AQ)
{
	this->queue = new ItemType[AQ.arrayCapacity];

	for (size_t i = 0; i < AQ.arrayCapacity; i++)
	{
		this->queue[i] = AQ.queue[i];
	}
	this->arrayCapacity = AQ.arrayCapacity;
	this->numItems = AQ.numItems;
	this->front = AQ.front;
	this->rear = AQ.rear;
}
//copy constructpor
ArrayQueue::ArrayQueue(const ArrayQueue & AQ)
{
	copy(AQ);
}

//----------------------------------------------------------------------
//Assignment operator
const ArrayQueue & ArrayQueue::operator = (const ArrayQueue & AQ)
{
	if (this != &AQ)
	{
		delete[] queue;
		copy(AQ);
	}

	return *this;
}
//--------------------------------------------------------------------
/*
If Capacity of array is larger than the number of items in the queue then
	move rear pointer to next empty slot (moving to higher array index or wrap around'
	Add the item at the location of rear pointer
	increase number of queue items by one
Else
Create a new length parameter len sum of current array capacity plus DEFAULT_GROWBY
Create an ItemType pointer Temp
Allocate memory to this pointer pointing to an array of size len.
End If
*/
void ArrayQueue::enqueue(ItemType item)
  {
	if (arrayCapacity > this->numItems)
	{
		cout << "**********>  Using the existing array to enqueue. <******************* \n";
		rear = (rear + 1) % arrayCapacity;
		queue[rear] = item;
		numItems = numItems + 1;
		cout << "Number of items in queue now: " << numItems << endl;
	}
	else
	{
		cout << "**********> Expanding the array to enqueue. <*******************\n";
		size_t len = arrayCapacity + DEFAULT_GROWBY;
		ItemType * Temp;

		Temp = new ItemType[len];

		for (size_t index = 0; index<this->numItems; index++)
		{
			Temp[index] = queue[front];
			front = (front + 1) % arrayCapacity;
		}

		delete [] queue;
		queue = Temp;
		Temp = nullptr;
		arrayCapacity = len;
		front = 0;
		rear = numItems - 1;
		rear = (rear + 1) % arrayCapacity;
		queue[rear] = item;
		this->numItems = this->numItems + 1;//why is this not increasing number of items by one?? look for problem in copy function code
		cout << "Number of items in queue now: " << numItems << endl;
	}
  }
//-------------------------------------------------
ItemType ArrayQueue::dequeue( ) 
{
       if(isEmpty ( ) )
           {
		cerr<<"\nThe queue is empty.\n";
		throw "Queue is empty";
           }
     else
     {
          ItemType toReturn = queue[front];
    front = (front + 1) % arrayCapacity;
	cout << "index of front pointer is: " << front << endl;
          numItems --;
          return toReturn;
      }
}

//---------------------------------------------
bool ArrayQueue::isEmpty() const

  {
    return (numItems == 0);
  }
//----------------------------------------
//bool ArrayQueue::isFull() const
//  {
//    return (numItems == arrayCapacity);
//  }
//--------------------------------------------
ArrayQueue::~ArrayQueue()
{
	delete[] queue;
}
//--------------------------------------------------------------------
size_t ArrayQueue::numberOfItemsInQueue() const
{
	return this->numItems;
}