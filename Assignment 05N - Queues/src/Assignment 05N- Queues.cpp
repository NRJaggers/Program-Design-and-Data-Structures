//============================================================================
// Name        : Assignment.cpp
// Author      : Nathan Jaggers
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//PART B - QUEUES
//Please study the code posted below.
//Please rewrite the code implementing a template class using a linked list instead of an array.
//Note : The functionality should remain the same

#include <cstdio>
#include <cstdlib>
#include <climits>
#include <iostream>

using namespace std;

/** Queue structure definition */
template <typename type>
struct QueueType {
    type data;
    QueueType* next;
};

template <typename type>
struct QueueList{
private:
	QueueType<type>* front ;
	QueueType<type>* rear ;
	int size ;

public:
	QueueList(){
		front = nullptr ;
		rear = nullptr ;
		size= 0 ;
	}

	/**
	* Enqueues/Insert an element at the rear of a queue.
	* Function returns 1 on success otherwise returns 0.
	*/
	void enqueue(type data)
	{
	    QueueType<type>* newNode = NULL;

	    /// Create a new node of queue type
	    newNode = new QueueType<type>;

	    /// Assign data to new node
	    newNode->data = data;

	    /// Initially new node does not point anything
	    newNode->next = NULL;

	    /// Link new node with existing last node
	    if ((rear)) {
	        rear->next = newNode;
	    }

	    /// Make sure newly created node is at rear
	    rear = newNode;

	    /// Link first node to front if its NULL
	    if (!(front)) {
	        front = rear;
	    }

	    /// Increment queue size
	    size++;

	}

	/**
	* Dequeues/Removes an element from front of the queue.
	* It returns the element on success otherwise returns
	* INT_MIN as error code.
	*/
	int dequeue()
	{
	    QueueType<type>* toDequque = NULL;
	    int data = INT_MIN;

	    // Queue empty error
	    if (isEmpty()) {
	        return INT_MIN;
	    }

	    /// Get element and data to dequeue
	    toDequque = front;
	    data = toDequque->data;

	    /// Move front ahead
	    front = (front)->next;

	    /// Decrement size
	    size--;

	    /// Clear dequeued element from memory
	    free(toDequque);

	    return data;
	}

	/**
	* Gets, element at rear of the queue. It returns the element
	* at rear of the queue on success otherwise return INT_MIN as
	* error code.
	*/
	int getRear()
	{
	    // Return INT_MIN if queue is empty otherwise rear.
	    return (isEmpty())? INT_MIN : rear->data;
	}

	/**
	* Gets, element at front of the queue. It returns the element
	* at front of the queue on success otherwise return INT_MIN as
	* error code.
	*/
	int getFront()
	{
	    // Return INT_MIN if queue is empty otherwise front.
	    return (isEmpty())? INT_MIN : front->data;
	}

	//get size of queue
	int getSize(){
		return size ;
	}

	/**
	* Checks, if queue is empty or not.
	*/
	int isEmpty()
	{
	    return (size <= 0);
	}

	string prepMenu()
	{

	    string menu = "";

	    menu += "\n-------------------------------------------------------------------\n";
	    menu += "1.Enqueue 2.Dequeue 3.Size 4.Get Rear 5.Get Front 6.Display 7.Exit\n";
	    menu += "----------------------------------------------------------------------\n";
	    menu += "Select an option: ";
	    return menu;
	}
	void display()
	{
	    for (QueueType<type>* t = front; t != NULL; t = t->next)
	        cout << t->data << " ";
	    cout << endl
	         << endl;
	}
};

int main()
{
	//declarations
	QueueList<int> queue;
		int data;
//	QueueList<float> queue;
//		float data;
//	QueueList<char> queue;
//		char data;
//	QueueList<string> queue;
//		string data;

    int option ;
    string menu = queue.prepMenu();

    cout << menu << endl;
    cin >> option;
    while (option != 7) {

        switch (option) {
        case 1:
            cout << "\nEnter data to enqueue (-99 to stop): ";
            cin >> data;
            while (data != -99) {
                /// Enqueue function returns 1 on success
                /// otherwise 0
                queue.enqueue(data);
                cout << "Element added to queue.";
                cout << "\nEnter data to enqueue (-99 to stop): ";
                cin >> data;
            }

            break;

        case 2:
            data = queue.dequeue();

            /// on success dequeue returns element removed
            /// otherwise returns INT_MIN
            if (data == INT_MIN)
                cout << "Queue is empty." << endl;
            else
                cout << "Data => " << data << endl;

            break;

        case 3:

            /// isEmpty() function returns 1 if queue is emtpy
            /// otherwise returns 0
            if (queue.isEmpty())
                cout << "Queue is empty." << endl;
            else
                cout << "Queue size => " << queue.getSize() << endl;

            break;

        case 4:
            data = queue.getRear();

            if (data == INT_MIN)
                cout << "Queue is empty." << endl;
            else
                cout << "Rear => " << data << endl;

            break;

        case 5:

            data = queue.getFront();

            if (data == INT_MIN)
                cout << "Queue is empty." << endl;
            else
                cout << "Front => " << data << endl;

            break;

        case 6:
        	queue.display();
            break;

        default:
            cout << "Invalid choice, please input number between (0-5).\n";
            break;
        }

        cout << "\n\n";
        cout << menu << endl;
        cin >> option;
    }
}



