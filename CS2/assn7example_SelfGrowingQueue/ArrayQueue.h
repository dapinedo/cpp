#pragma once
#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H
#include "QueueInterface.h"


class ArrayQueue : public QueueInterface
{
private:
	/*
	Initial Maximum size of queue
	*/
	static const size_t MAX = 1;// why? because we wish to see growth behavior clearly

	/*
	Queue will grow by DEFAULT_GROWBY each time the previous capacity is used up
	*/
	static const size_t DEFAULT_GROWBY = 1;// why? because we wish to see growth behavior clearly

	/*
	Current array Capacity
	*/
	size_t arrayCapacity;
	/**
	*Array that holds queue elements has a fixed size of MAX.
	*/
   ItemType * queue ; 
   /**
   *Number of items in the queue (less than arrayCapacity )
      */
   size_t numItems;   
   /**
   *index of front of queue.
   */
   int front; 
   /**
   *index of rear of queue.
   */
   int rear;             
public:
  /**
  * Default constructor sets the numItems = 0, front = 0,
  *rear = -1.
  */
   ArrayQueue();
   void enqueue(ItemType item);
   ItemType dequeue( );
   bool isEmpty() const;
   /*bool isFull() const;*/
   /*
   Destructor
   */
	~ArrayQueue();
	/*
	Copy Constructor
	*/
	ArrayQueue(const ArrayQueue & AQ);
	/*
	Assignment operator
	*/
	const ArrayQueue & operator = (const ArrayQueue & AQ);
protected:
	void copy(const ArrayQueue & AQ);
	size_t numberOfItemsInQueue() const;
};
#endif
