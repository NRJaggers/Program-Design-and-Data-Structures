/*
 * Nodell.h
 *
 *  Created on: Mar 10, 2020
 *      Author: Nathan Jaggers
 */

#include <iostream>
using namespace std;

#ifndef QUEUELIST_H_
#define QUEUELIST_H_

template <typename type>
struct Node {
	type data ;
	Node* next ;
	Node* prev ;
};

template <typename type>
struct queueList {

private:
	Node<type> * head ;
	Node<type> * tail ;
	Node<type> * current;

public:
	//constructor
	queueList(){
		head = new Node<type> ;
		head->data = NULL ;
		head->next = nullptr ;
		head->prev = nullptr ;
		current = nullptr ;
		tail = head ;
	}

	//enqueue input
	void enqueue(type input){
		tail->next = new Node<type> ;
		tail->next->prev = tail;
		tail = tail->next ;
		tail->next = nullptr ;
		tail->data = input ;
	}

	//dequeue data
	type dequeue() {
		type temp = tail->data ;

		tail = tail->prev ;
		delete tail->next ;
		tail->next = nullptr ;

		return temp ;
	}

	//observe front of queue
	type getfront() {
		return head->data ;
	}

	//observe back of queue
	type getback() {
		return tail->data ;
	}

	//size of queue
	int sizeOfQueue()
	{
		int counter = 0 ;
		current = head ;
		while(current->next != nullptr){
			counter++ ;
			current = current->next ;
		}

		return counter ;
	}

	//display queue
	void displayQueue() {
		if (tail != head) {
			current = head->next ;
			cout << "Front\n" ;
			while(current->next != nullptr){
				cout << current-> data << endl;
				current = current->next ;
			}
			cout << "Back\n" ;
		}
		else
		{
			cout<< "The queue is empty\n" ;
		}

	}

	//destructor
	~queueList(){
		while(tail != head)
		{
			tail = tail->prev ;
			delete tail->next ;
		}
		delete tail->next ;
		delete head ;

	}

};


#endif /* QUEUELIST_H_ */
