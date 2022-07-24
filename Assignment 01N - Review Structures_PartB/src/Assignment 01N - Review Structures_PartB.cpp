//============================================================================
// Name        : Assignment 01N - Review Structures_PartB.cpp
// Author      : Nathan Jaggers
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Cylinder
{
//members
	float radius ;
	float height ;

public :

//functions
void init(float rad, float hgt)
	{
		radius = rad ;
		height = hgt ;
	}
float getVolume()
	{
		float pi = 3.1415926535 ;
		return (radius*radius*height*pi) ;
	}
};

int main()
{
	//declarations
	float r, h, volume;
	Cylinder jar ;
	//welcome
	cout << "Hello and welcome to the program! \n" << endl;

	//initialize class
	r = 10 ;
	h = 20 ;
	jar.init(r,h) ;

	//get volume
	volume = jar.getVolume() ;

	//print result
	cout << "The volume of the cylinder is " << volume << ".\n\n" ;

	//goodbye
	cout << "Thanks for using the program, have a great day!\n";

	return 0;

}
