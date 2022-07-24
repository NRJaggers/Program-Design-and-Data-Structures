//============================================================================
// Name        : Assignment.cpp
// Author      : Nathan Jaggers
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <random>
#include <time.h>
#include "MySortableArray.h"

using namespace std;

void welcome();
void goodbye();
int  menuAndChoice();
template<class type>
void getElement(MySortableArray<type>);

int main() {

	//declarations
	  srand(time(0)) ;
	  int random ;
	  int choice = 1 ;
	  MySortableArray<int> numArray;


//	//temporary fill of array
//	  for (int i = 0; i< 10; i++ )
//	  {
//		  random = rand() % 21 ;
//		  numArray.addEntry(random);
//	  }

	//welcome
	  welcome();

	//menu
	  choice = menuAndChoice();
	  while(choice != 0)
	  {
		  switch (choice)
		  {
		  	  case 1:
		  		  	  cout << "Enter an integer you would like to add to the array: " ;
		  		  	  cin  >> choice;
		  		  	  numArray.addEntry(choice);
		  		  break;

		  	  case 2:
		  		  	  if (numArray.getSize() != 0)
		  		  	  {
		  		  		for(int i = 0; i < numArray.getSize(); i++)
						  {
							  cout << i << " => " << numArray.getEntry(i) << " " ;
							  if((i+1)%10 == 0)
							  {
								  cout << endl ;
							  }
						  }
		  		  	  }
		  		  	  else
		  		  		  cout << "Array is empty.\n";

		  		  break;

		  	  case 3:
		  		  	  if (numArray.getSize() != 0)
		  			{
		  		  	  cout << "Enter an index you would like to sort up to: " ;
					  cin  >> choice;
					  numArray.sort(choice);
		  			}
		  		  	else
		  		  		  cout << "Array is empty.\n";
		  		  break;

		  	  case 4:
		  		  	  if (numArray.getSize() != 0)
		  			{
		  		  		  getElement(numArray);
		  			}
		  		  	else
		  		  		  cout << "Array is empty.\n";
		  		  break;

		  	  case 0:
				  break;

		  	  default:
		  		  cout<< "Something went wrong.\n";
			  	  break;

		  }
		  choice = menuAndChoice();
	  }
	//goodbye
	  goodbye();

	return 0;

}

void welcome(){
	cout << "\nWelcome to Program 7!\n"
		 << "=====================\n" ;
}
void goodbye(){
	cout << "\n=====================\n"
		 << "Thank you for using the program! Have a good day!" ;
}
int  menuAndChoice(){
	int selection ;

	cout <<"\n---Menu---\n==========\n"
		 <<"1. Add to array\n"
		 <<"2. Print array\n"
		 <<"3. Sort Array\n"
		 <<"4. Get element\n"
		 <<"0. Quit\n"
		 <<"===============\n\n"
		 <<"Make a selection: " ;

	cin >> selection ;
	while (selection<0 || selection>4)
	{
		cout << "Invalid choice, please try again\n"
			 <<"Make a selection: " ;
		cin  >> selection;

	}

	return selection ;

}
template<class type>
void getElement(MySortableArray<type> array){
	int lookup = 0 ;
	while (lookup != -1)
	{
		cout << "Please select the element you would like to see (-1 to quit): " ;
		cin  >> lookup;

		if (lookup != -1)
		{
			while ((lookup < -1) or (lookup > (array.getSize()-1)))
			{
				cout << "Invalid index, try again\n element : ";
				cin  >> lookup;
			}

			cout << "Element at index "<< lookup << " is " << array.getEntry(lookup) << endl ;
		}
	}

}
