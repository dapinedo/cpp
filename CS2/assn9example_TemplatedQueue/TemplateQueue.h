
#pragma once
//#include "QueueInterface.h"

template<typename T>
class Queue : public QueueInterface<T>
{
private:
	/**
	*The maximum default size of the queue, when created first time.
	*/
	static const int MAX = 1000;
	
   T   items[MAX]; 
   /**
   *Number of items in the queue (less than or equal to MAX )
      */
   int numItems;   
   /**
   *index of front pointer of queue.
   */
   int front; 
   /**
   *index of rear pointer of queue.
   */
   int rear;             
public:
  /**
  * Default constructor sets the numItems = 0, front = 0,
  *rear = -1, capacity to MAX, and allocates the memory for array pointer 
  member items.
  */
   Queue();
   /**
   *Enqueues the item and adds to the rear of the queue. If queue is filled then
   *increases its capacity by static member GROW.
   */
   void enqueue(T item);
    /**
   *Removes the item from the front of the queue and returns it. If queue is empty tghen throws
   *an exception. Syntax of throwing exception is simply:
   *throw "Queue is Empty";
   */
   T dequeue( );
   /**
   *Returns true if queue is empty, otherwise returns false.
   */
   bool isEmpty() const;
  /**
  *Default destructor deallocates the dynamically allocated memory in
  *the constructor.
  */
	
	bool isFull() const;
};

#include "TemplateQueue.cpp"