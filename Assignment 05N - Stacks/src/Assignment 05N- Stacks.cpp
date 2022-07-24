//============================================================================
// Name        : Assignment.cpp
// Author      : Nathan Jaggers
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//PART A - STACKS
//To complete this assignment :
//Please study the code posted below.
//Please rewrite the code implementing a template class using a linked list instead of an array.
//Note : The functionality should remain the same
//***************************************************************************************************************

#include <iostream>
using namespace std;

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

int main()
{
	//choose list data type
	stackList<int> stack ;
	//stackList<float> stack ;
	//stackList<char> stack ;
	//stackList<string> stack ;

	//declaration
		int choice = 0 ;
		int data ;
		//float data ;
		//char data ;
		//string data ;

    while (choice != 5) {

        /* Menu */
        cout << "------------------------------------\n";
        cout << " STACK IMPLEMENTATION PROGRAM \n";
        cout << "------------------------------------\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Size\n";
        cout << "4. Print Stack\n";
        cout << "5. Exit\n";
        cout << "------------------------------------\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter data to push into stack: ";
            cin >> data;

            // Push element to stack
            stack.push(data);
            break;

        case 2:
            	if (stack.peek() == '\0')
            	{
            		cout << "Stack is empty\n" ;
            	}
            	else
            	{
            		cout << "Data => " << stack.pop() << endl;
            	}
            break;

        case 3:
            cout << "Stack size: " << stack.sizeOfStack() << endl;
            break;

        case 4:
            stack.displayStack();
            break;

        case 5:
            cout << "Exiting from app.\n";
            break;

        default:
            cout << "Invalid choice, please try again.\n";
        }

        cout << "\n\n";
    }

    return 0;
}

