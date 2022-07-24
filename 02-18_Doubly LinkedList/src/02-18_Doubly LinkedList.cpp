//============================================================================
// Name        : 02-18_Doubly.cpp
// Author      : Nathan Jaggers
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<cstdlib>
#include<iostream>

using namespace std;

struct Node

{

   int id;

   double salary;

   Node* next;

   Node* prev;

};

struct Rec

{

   int id;

   double salary;

};

 void Insert(Rec rec);

 void Remove(Rec rec);

 void display();





   Node* fhead;

   Node* tail;



int main()

{



   int ch;

   Rec temp;

   while(1)

   {

      cout<<endl;

      cout<<

      " Doubly Linked List Operations "<<endl;

      cout<<

         " ------------------------------"<<endl;

      cout<<

         " 1. Insertion "<<endl;

      cout<<

         " 2. Deletion "<<endl;

      cout<<

         " 3. Display "<<endl;

      cout<<

         " 4. Exit "<<endl;

      cout<<

         " Enter your choice : ";

      cin>>ch;

      switch(ch)

      {

      case 1:

         cout<<" Enter id to be inserted : ";

         cin>>temp.id;

         cout<<" Enter salary : ";

         cin>>temp.salary;

         Insert(temp);

         break;

      case 2:

         cout<<" Enter rec.id to be deleted : ";

         cin>>temp.id;

         Remove(temp);

         break;

      case 3:



         display();

         break;

      case 4:

         system("pause");

         return 0;

         break;

      }

   }

}



void Insert(Rec rec)

{

   //create a new node and populate id.

   Node* temp = new Node;

   //populate the node

   temp->id = rec.id;

   temp->salary = rec.salary;

   temp->prev = NULL;

   temp->next = NULL;



   Node* curr;

   //case record exists

   for (curr=fhead; curr!=NULL; curr=curr->next)

   {

      if (rec.id == curr->id)

      {

         cout << "Record Exits. Nothing Done." << endl;

         return;

      }

   }

   //case: Empty List.

   if(fhead==NULL && tail==NULL)

   {



      //link the node

      fhead = temp;

      tail = temp;

   }

   //case: head insertion

   else if (rec.id < fhead->id)

   {

      //update two backward links

      temp->prev = fhead->prev;

      fhead->prev = temp;

      //update two forward links

      temp->next = fhead;

      fhead = temp;

   }

   //case: end insertion

   else if (rec.id > tail->id)

   {

      //udate two forward links

      temp->next = tail->next;

      tail->next = temp;

      //update two backward links

      temp->prev = tail;

      tail = temp;

   }

   //case mid insertion

   else

   {

      Node* curr;

      //case: head or mid insertion

      //find the place of insertion using curr

      for (curr=fhead->next; curr->next != tail->next; curr=curr->next)

      {

         if (rec.id < curr->id)

            break;

      }

      //do the insertion

      //locate prev using curr node

      Node* prev = curr->prev;

      //update two forward links using prev;

      temp->next = prev->next;

      prev->next = temp;

      //update two backward links using

      temp->prev = curr->prev;

      curr->prev = temp;

   }



}



void display ()

{

   if (fhead==NULL && tail==NULL)

   {

      cout << "List is empty" << endl;

      return;

   }

   cout << "The list contains: ";

   Node* curr;

   //case record exists

   for (curr=fhead; curr!=NULL; curr=curr->next)

   {

         cout << curr->id<<"(" << curr->salary << ") ";

   }

   cout<< endl << endl;

   return;

}

void Remove(Rec rec)

{

   //case: empty list

   if(fhead==NULL && tail==NULL)

   {

      cout<< " This is an empty list! "<<endl;

   }

   //case: Not an empty list

   else

   {

      //search for the rec.id

      Node* curr;

      for(curr = fhead; curr!=NULL; curr=curr->next)

      {

         if(curr->id == rec.id)

         {

            break;

         }

      }

      //case: not found

      if(curr==NULL)

      {

         cout<<" The list does not contain specified Node"<<endl;

      }

      //case: found.So remove it.

      else

      {

         //case: remove the only node in the list

         if (curr==fhead && curr==tail)

         {

               //make the list empty

               fhead = NULL;

               tail = NULL;

               //release the node

               delete curr;

         }

         //case: remove head node (which is not the only node)

         else if (curr==fhead)

         {

            //update fhead

            fhead = fhead->next;

            //locate the next node using curr & update back link of next node

            Node* next = curr->next;

            next->prev = curr->prev;

            //release the curr node

            delete curr;

         }

         //case: remove last node (which is not the only node)

         else if (curr==tail)

         {

            //update tail

            tail = curr->prev;

            //locate prev node using curr node & update forward link of prev node

            Node* prev = curr->prev;

            prev->next = curr->next;

            //release curr node

            delete curr;

         }

         //case: remove mid node

         else

         {

            //locate prev and next nodes from curr node

            Node* prev = curr->prev;

            Node* next = curr->next;

            //update prev's forward link and next's back link

            prev->next = curr->next;

            next->prev = curr->prev;

            //release curr node

            delete curr;

         }

         cout << "The specified node deleted" << endl;

      }

   }

}
