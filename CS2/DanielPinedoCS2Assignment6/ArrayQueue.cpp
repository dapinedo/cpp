#include "Arrayqueue.h"
#include <iostream>
#include <cassert>
using namespace std;
//-----------------------------------------------------------
ArrayQueue::ArrayQueue() : numItems(0), front(0), rear(-1)
 {		
		
  }
//--------------------------------------------------------------------
void ArrayQueue::enqueue(ItemType item)
  {
     if(isFull( ))
	 {
		 cerr<<"The queue is full. The item is not added."<<endl;
		 return;
	 }
     rear = (rear + 1) % MAX;
         queue[rear] = item;
         numItems = numItems + 1;
  }
//-------------------------------------------------
ItemType ArrayQueue::dequeue( ) 
{
       if(isEmpty ( ))
       {
		cerr<<"\nThe queue is empty.\n";
		throw "Queue is empty";
       }
          ItemType toReturn = queue[front];
		  front = (front + 1) % MAX;
          numItems --;
          return toReturn;
}

//---------------------------------------------
bool ArrayQueue::isEmpty() const
  {
    return (numItems == 0);
  }
//----------------------------------------
bool ArrayQueue::isFull() const
  {
    return (numItems == MAX);
  }
//--------------------------------------------
ArrayQueue::~ArrayQueue()
{
}
//--------------------------------------------------------------------
