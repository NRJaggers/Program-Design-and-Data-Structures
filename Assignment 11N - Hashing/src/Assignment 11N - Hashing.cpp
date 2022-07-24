//============================================================================
// Name        : Assignment.cpp
// Author      : Nathan Jaggers
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include "StudentHT.h"
using namespace std;

void welcome();
void goodbye();

int main() {

	//declarations
	  int inputCount;
	  int input;
	  StudentInfo studentInput ;
	  StudentHT	studentTable;
	  ifstream inFile ;
	  string randString = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" ;
	  char randChar ;

	//welcome
	  welcome();

	//open file to create hash table(check for open)
	  cout << "Opening insert file...\n" ;
	  inFile.open("C:\\COMSC210\\Add-1.txt");
	  if(!inFile.is_open()){
		  cout << "There was something wrong opening up the file.\nPlease check and try again.";
	  }

	//insert data into hash table
	  inFile >> inputCount ;
	  while(inFile>>input)
	  {
		  //add student info here
		  studentInput.ID = input ;
		  studentInput.firstName = randString[inputCount%51]  ;
		  studentInput.lastName = randString[(inputCount%51)/2]  ;

		  studentTable.insert(studentInput);

		  inputCount-- ;
	  }

	//close file
	  inFile.close();

//	//print out hash table
//	  cout << "Displaying Table\n===============\n";
//	  studentTable.displayTable();

	//open file for searching in hash table(check for open)
	  cout << "Opening search file...\n" ;
	  	  inFile.open("C:\\COMSC210\\Search-1.txt");
	  	  if(!inFile.is_open()){
	  		  cout << "There was something wrong opening up the file.\nPlease check and try again.";
	  	  }

	//start statistics and begin searching
	  studentTable.startStatistics();

	  inFile >> inputCount ;
	  while(inFile>>input)
	  {
		  //add student search info here
		  studentInput.ID = input ;

		  studentTable.search(studentInput);

	  }
	//end statistics and close file
	  inFile.close();
	  studentTable.endStatistics();

	//display statistics
	  cout << endl ;
	  studentTable.displayStatistics();

	//goodbye
	  goodbye();

	return 0;
}

void welcome(){
	cout << "\nWelcome to Program 11!\n"
		 << "=====================\n" ;
}
void goodbye(){
	cout << "\n=====================\n"
		 << "Thank you for using the program! Have a good day!" ;
}
