/*
Author: Satish Singhal
*/
#pragma once
#ifndef STACK_H
#define STACK_H

#include "StackInterface.h"
#include <iostream>

using namespace std;

const size_t MAX = 100;

class Stack : public StackInterface
{
private:
    int top_position;
    ItemType items[MAX];
public:
    void push(ItemType item);
    void pop();
    ItemType top() const;
    bool isEmpty() const;
    bool isFull() const;
    Stack();
    ~Stack();
};

#endif