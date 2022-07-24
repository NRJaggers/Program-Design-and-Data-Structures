/*
 * Pqueue.h
 *
 *  Created on: Apr 28, 2020
 *      Author: Nathan Jaggers
 */

#ifndef PQUEUE_H_
#define PQUEUE_H_

#include <iostream>

using namespace std;

//Max size of heap
const int MAXSIZE = 100 ;

//Record Type Structure
struct RecType

{
  int priority;
  string name;

  RecType(){
	  priority = 0 ;
	  name = "" ;
  }

  RecType(int priority, string name){
	  this->priority = priority ;
	  this->name = name ;
  }

};

//Priority Queue Class
class Pqueue
{

private:

	//private members
	  int lastIndex;
	  RecType heap[MAXSIZE];


	//private functions
	  void maxreheapifyUpward();
	  void maxreheapifyDownward();
	  int findLargeChildIndex(int);

public:

	//public members
	  RecType userInput ;

	//public functions
	  Pqueue(); //constructor
	  void penque(int, string);
	  void penque(RecType);
	  RecType pdeque();
	  bool isEmpty();
};

Pqueue :: Pqueue()
{
	lastIndex = -1;

}
void 	Pqueue :: maxreheapifyUpward()

  {
	//function declarations
    int parentIndex;
    int childIndex = lastIndex;

    //reheapifying
    while (childIndex > 0)
		{
		  parentIndex = childIndex / 2;

		  if (heap[childIndex].priority <= heap[parentIndex].priority)
				break;
		  else
			  {
				///swap values at child and at parent.
				RecType tempIndex = heap[childIndex];
				heap[childIndex] = heap[parentIndex];
				heap[parentIndex] = tempIndex;

				///Update child to parent
				childIndex = parentIndex;

			  }
		}
  }

void 	Pqueue :: maxreheapifyDownward()

  {
	//function declarations
      int parentIndex = 0;
      int largeChildIndex;

    ///cout << "hi maxreheapifyDownward" << endl;

    //reheapifying
      while (parentIndex < lastIndex)
		{
		  ///cout << "hi maxreheapifyDownward 2" << endl;

		  largeChildIndex = findLargeChildIndex(parentIndex);

		  if (largeChildIndex < 0 || heap[largeChildIndex].priority <= heap[parentIndex].priority)
				break;
		  else
			  {
				///swap value at parentIndex with value at largeChildIndex
				RecType temp = heap[parentIndex];
				heap[parentIndex] = heap[largeChildIndex];
				heap[largeChildIndex] = temp;

				///update parentIndex
				parentIndex = largeChildIndex;
			  }
		}
  }

int  	Pqueue :: findLargeChildIndex(int parentIndex)
  {
	//function declarations
    int lChildIndex = (2 * parentIndex) + 1;
    int rChildIndex = (2 * parentIndex) + 2;

    //case both children exist
    if (rChildIndex <= lastIndex && lChildIndex <= lastIndex)
		{
		  ///compare value at rChildIndex and at lChildIndex
		  ///return the index where the value is smaller
		  if (heap[rChildIndex].priority > heap[lChildIndex].priority)
			  {
				return rChildIndex;
			  }
		  else
			  {
				return lChildIndex;
			  }
		}
    ///case only left child exist
    else if (lChildIndex <= lastIndex)
		{
		  return lChildIndex;
		}
    ///case both children missing
    else
		{
		  return -1;
		}

  }

void 	Pqueue :: penque(int p, string n)
  {
	if((lastIndex+1) < MAXSIZE)
		{
			//Grow heap - increment index
			lastIndex++;

			//add input to heap
			heap[lastIndex].priority = p;
			heap[lastIndex].name = n;

			//reheapify
			maxreheapifyUpward();
		}
  }

void 	Pqueue :: penque(RecType input)
  {
	if((lastIndex+1) < MAXSIZE)
		{
			//Grow heap - increment index
		    lastIndex++;

		    //add input to heap
		    heap[lastIndex].priority = input.priority;
		    heap[lastIndex].name = input.name;

		    //reheapify
		    maxreheapifyUpward();
		}
  }

RecType Pqueue :: pdeque()
  {
	if (isEmpty()){
		cout << "\nThe heap is empty.\n" <<lastIndex ;
		return RecType(-1,"Null");
	}
	else{
		//save return value
		RecType returnValue = heap[0];

		//replace first value with last and shrink heap - decrement index
		heap[0] = heap[lastIndex];
		lastIndex--;

		maxreheapifyDownward();

		return returnValue;
	}
  }

bool 	Pqueue :: isEmpty()
  {
    if (lastIndex < 0) {
      return true;
    }
    else {
      return false;
    }
  }


#endif /* PQUEUE_H_ */
