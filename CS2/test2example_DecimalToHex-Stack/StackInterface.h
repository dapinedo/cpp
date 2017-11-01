/*
Author: Satish Singhal
*/
#pragma once
#ifndef STACK_INTERFACE_H
#define STACK_INTERFACE_H

#include "ItemType.h"

class StackInterface
{
public:
    /** 
    *Effect: Adds item to the top of this stack.<BR>
    *Postconditions: If (this stack is full) User is 
    *informed that stack is full. else item is at the top of this stack
    */
    virtual void push(ItemType item) = 0;
    /**
    *Effect: Removes top item from this stack.<BR>
    *Postconditions: If (this stack is empty) User is informed 
    *that stack is empty, 
    *else
    *top element has been removed from this stack.
    */
    virtual void pop() = 0;
    /**
    *Effect: Returns the element on top of this stack.<BR>
    *Postconditions: If (this stack is empty)the user is 
    *informed that stack is empty.<BR>
    *else<BR>
    *return value = (top element of this stack)
    */
    virtual ItemType top() const = 0;
    /**
    *Effect: Determines whether this stack is empty.<BR>
    *Postcondition: Return value = (this stack is empty)
    */
    virtual bool isEmpty() const = 0;
    /** 
    *Effect: Determines whether this stack is full.<BR>
    *Postcondition: Return value = (stack is full)
    */
    virtual bool isFull() const = 0;
    /**
    *Default constructor
    */
    StackInterface() {}
    /**
    *Destructor
    */
    virtual ~StackInterface(){}
};

#endif