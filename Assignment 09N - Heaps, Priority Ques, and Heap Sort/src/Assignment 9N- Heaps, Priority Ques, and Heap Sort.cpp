//============================================================================
// Name        : Assignment.cpp
// Author      : Nathan Jaggers
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Pqueue.h"

using namespace std;

void welcome();
void goodbye();

int main()

{
	//declarations
	  Pqueue recordList;

	//welcome
	  welcome();

	//input data (sample input)
	  recordList.penque(3,"Jim");
	  recordList.penque(2,"Judy");
	  recordList.penque(7,"Jill");
	  recordList.penque(1,"Jimmy");
	  recordList.penque(10,"Joe");
	  recordList.penque(4,"Jacob");
	  recordList.penque(8,"Joseph");
	  recordList.penque(9,"Josephine");
	  recordList.penque(5,"Jackie");
	  recordList.penque(6,"John");

    //input data (manual input)
	  while (recordList.userInput.priority >= 0)
		  {
			cout << "Input priority number (-1 to stop): " << endl;
			cin >> recordList.userInput.priority;

			if (recordList.userInput.priority == -1)
			{
			  break;
			}

			cout << "Input a name : " << endl;
			cin >> recordList.userInput.name;

			recordList.penque(recordList.userInput.priority, recordList.userInput.name);
		  }

	//release data and print results
	  while (!recordList.isEmpty())
		  {
			recordList.userInput = recordList.pdeque();
			cout << recordList.userInput.priority << " " << recordList.userInput.name << endl;
		  }

	//goodbye
	    goodbye();

  return 0;

}

void welcome(){
	cout << "\nWelcome to Program 9!\n"
		 << "=====================\n" ;
}
void goodbye(){
	cout << "\n=====================\n"
		 << "Thank you for using the program! Have a good day!" ;
}
