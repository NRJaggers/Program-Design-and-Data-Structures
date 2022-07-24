//============================================================================
// Name        : Recursion.cpp
// Author      : Nathan Jaggers
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
using namespace std;

int g(int) ;

int main() {

	int num ;

	cout << "Pick a positive int: " ;
	cin  >>  num ;
	cout << endl ;

	for (int i = 1 ; i <= num; i++ )
	{
		cout << i << "\t" ;
	}

	cout << endl ;

	for (int j = 1 ; j <= num; j++)
	{
		cout << g(j) << "\t" ;
	}

}

int g(int n)
{
	if(n<=0){
		cout << "Invalid number\n";
	}
	else if(n == 1)
	{
		return 1 ;
	}
	else{
		return (1 + g(n - g( g(n - 1) ) ) ) ;
	}

	return 0 ;
}
