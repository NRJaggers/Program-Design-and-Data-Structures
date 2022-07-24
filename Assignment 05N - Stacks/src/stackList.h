/*
 * Nodell.h
 *
 *  Created on: Mar 10, 2020
 *      Author: Nathan Jaggers
 */

#include <iostream>
using namespace std;

#ifndef STACKLIST_H_
#define STACKLIST_H_

template <class type>
struct Node {
	type data ;
	Node* next ;
	Node* prev ;
};

template <class type>
struct stackList {

private:
	Node<type> * head ;
	Node<type> * current;

public:
	//constructor
	stackList(){
		head = new Node<type> ;
		head->data = NULL ;
		head->next = nullptr ;
		head->prev = head ;
		current = head ;
	}

	//push onto stack
	void push(type input){
		current->next = new Node<type> ;
		current->next->prev = current;
		current = current->next ;
		current->next = nullptr ;
		current->data = input ;
	}

	//pop off of stack
	type pop() {
		type temp = current->data ;

		current = current->prev ;
		delete current->next ;
		current->next = nullptr ;

		return temp ;
	}

	//peek the top of the stack
	type peek() {
		return current->data ;
	}

	//size of stack
	int sizeOfStack()
	{
		int counter = 0 ;
		current = head ;
		while(current->next != nullptr){
			counter++ ;
			current = current->next ;
		}

		return counter ;
	}

	//display stack
	void displayStack() {
		if (current != head) {
			Node<type>* cursor = current;
			cout << "Top\n" ;
			while(cursor != head){
				cout << cursor-> data << endl;
				cursor = cursor->prev ;
			}
			cout << "Bottom\n" ;
		}
		else
		{
			cout<< "The stack is empty\n" ;
		}

	}

	//destructor
	~stackList(){
		while(current != head)
		{
			current = current->prev ;
			delete current->next ;
		}
		delete current->next ;
		delete head ;

	}

};


#endif /* STACKLIST_H_ */
