//============================================================================
// Name        : 02-18_List.cpp
// Author      : Nathan Jaggers
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

struct Node

{

     int num;

     Node * next;

};



//function proto-types

void initializeDummy ();

void insert (int n);

void remove (int n);

void displayAll ();



//Global variable

Node * head;



int main()

{

   //initialize dummy node

   initializeDummy();



   int choice;

   int num;

   while (1){

      cout << "1-Insert" << endl;

      cout << "2-Remove" << endl;

      cout << "3-Display All" << endl;

      cout << "4-Exit" << endl;



      cout << "Enter choice" << endl;

      cin >> choice;



      switch (choice){

      case 1:

         cout << "Enter number to be inserted" << endl;

         cin >> num;

         insert (num);

         break;

      case 2:

         cout << "Enter number to be removed" << endl;

         cin >> num;

         remove (num);

         break;

      case 3:

         displayAll ();

         break;

      case 4:

         return 0;

         break;

      }

   }

    return 0;

}

void initializeDummy (){

   //Create a dummy node

   //Make head point to it

   //Put any value in num (such as -1)

   //Put NULL in next.

   head = new Node;

   head->num = -1;

   head->next= NULL;

}

void insert (int n){

   Node * newPtr = new Node;

   newPtr->num = n;

   newPtr->next = NULL;

   Node * prev;

   Node * cur;



   for (prev=head,cur=head->next;cur!=NULL;prev=prev->next,cur=cur->next) {

      if (n < cur->num)

         break;

   }

   newPtr->next = cur;

   prev->next = newPtr;

   cout << "Inserted." << endl;

   return;

}

void remove (int n){

   Node * prev;

   Node * cur;

   Node * temp;

   for (prev=head,cur=head->next;cur!=NULL;prev=prev->next,cur=cur->next) {

      if (n == cur->num)

         break;

   }

   if (cur == NULL){

      cout << "Not found in the list." << endl;

   }

   else {

      prev->next = cur->next;

      delete cur;

      cout << "Removed." << endl;

   }

   return;

}

void displayAll (){

   Node * cur;

   if (head->next==NULL){

      cout << "List empty" << endl;

      return;

   }

   for (cur=head->next;cur!=NULL;cur=cur->next) {

      cout << cur->num << " ";

   }

   cout << endl;

   return;

}
