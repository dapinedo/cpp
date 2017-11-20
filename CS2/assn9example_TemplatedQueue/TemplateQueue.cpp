

#include <iostream>
#include <cstdlib>
using namespace std;


////////////////////////////////////////////
template<typename T>
Queue<typename T>::Queue( ):numItems(0), front(0), rear(-1)
 {
  }
//--------------------------------------------------------------------
template<typename T>
void Queue<typename T>::enqueue(T item)
  {
	  
	if (numItems<MAX)
	{
		rear = (rear + 1) % MAX;
		items[rear] = item;
		numItems = numItems + 1;
	}
	else
	{
		cout << "Queue is full." << endl;
		return;
	} 
  }
//-------------------------------------------------
template<typename T>
T Queue<typename T>::dequeue( ) 
{
       if(isEmpty ( ) )
           {
		cerr<<"\nThe queue is empty.\n";
                  throw "The queue is empty";
           }
     else
     {
          T toReturn = items[front];
		  front = (front + 1) % MAX;
          numItems --;
          return toReturn;
      }
}

//---------------------------------------------
template<typename T>
bool Queue<typename T>::isEmpty() const

  {
    return (numItems == 0);
  }
//----------------------------------------
template<typename T>
bool Queue<typename T>:: isFull() const
{
	return (numItems == MAX);
}
//----------------------------------------
