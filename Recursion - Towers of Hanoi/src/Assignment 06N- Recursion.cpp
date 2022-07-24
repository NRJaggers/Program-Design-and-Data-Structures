//============================================================================
// Name        : Assignment.cpp
// Author      : Nathan Jaggers
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void diskSwap (int,char,char,char) ;

int main() {

	//declarations
	int numOfDisks ;

	//welcome
	cout << "Hello and welcome to the Towers of Hanoi program!\n\n"
			"Here is how it works:\n"
			"A stack of n disks of decreasing size is placed on one of three posts.\n"
			"The task is to move the disks one at a time from the first post to the second.\n"
			"To do this, any disk can be moved from any post to any other post, subject to\n"
			"the rule that you can never place a larger disk over a smaller disk.\n"
			"=============================================================================\n" << endl;

	//user input
	cout << "Enter a number of disks to play and I'll give you the steps"
			"to solve the puzzle.\nNumber of disks : " ;
	cin >> numOfDisks ;

	//call recursive function
	diskSwap(numOfDisks,'A','B','C') ;

	//print out steps

	//goodbye
	cout << "\n=============================================================================\n"
			"Thank you for using the program! Goodbye!" ;

	return 0;
}

void diskSwap (int disks, char beg, char aux, char end){

	//visualization of recursive function
//	cout << "number of disks: " << disks
//		 << " | post: " << beg << " | post: " << aux << " | post: " << end << endl;

	if (disks < 1){
		cout << "There are no disks.\n" ;
	}
	else if (disks == 1){
		cout << endl << "Move disk from post " << beg << " to post " << end << endl << endl ;
	}
	else{
		diskSwap((disks-1),beg, end, aux) ;
		diskSwap(1, beg, aux, end);
		diskSwap((disks-1), aux, beg, end) ;
	}
}
