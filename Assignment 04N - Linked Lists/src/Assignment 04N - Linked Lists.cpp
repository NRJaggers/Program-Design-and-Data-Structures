//============================================================================
// Name        : Assignment 04N - Linked Lists.cpp
// Author      : Nathan Jaggers
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include "NodeType.h"

using namespace std;

int main ()
{
	//declarations
		AccountList accountRecords ;
		RecType temp ;

	//welcome
		cout << "\nHello and welcome to the Linked List Accounting Program!\n"
			 <<	"********************************************************\n\n" ;

	//open master input file
		ifstream infile ;
		infile.open("C:\\COMSC210\\master.txt") ;
		if (!infile.is_open())
		{
			cout << "Error in opening file\n"
					"Please try again\n" ;
			return -1 ;
		}

	//read input from master file and populate linked list
		while (!infile.eof())
		{
			infile >> temp.id >> temp.fname >> temp.lname >> temp.amount ;
			accountRecords.addAccountSorted(temp) ;
		}
	//close master file
		infile.close() ;

	//open update file
		infile.open("C:\\COMSC210\\tran.txt") ;
				if (!infile.is_open())
				{
					cout << "Error in opening file\n"
							"Please try again\n" ;
					return -1 ;
				}
	//read input from update file and adjust linked list
		while (!infile.eof())
				{
					infile >> temp.id >> temp.fname >> temp.lname >> temp.amount ;
					accountRecords.updateAccount(temp) ;
				}
	//close update file and open output file
		infile.close() ;
		ofstream lfout ("C:\\COMSC210\\log.txt");

	//display and log results
		accountRecords.display() ;
		accountRecords.display(lfout) ;

	//close output file
		lfout.close() ;

	//goodbye
		cout <<	"\n\n********************************************************\n"
			 << "Goodbye and have a wonderful day!" ;

	//check assignment to make sure it meets all requirements

		return 0 ;
}
