//============================================================================
// Name        : Assignment.cpp
// Author      : Nathan Jaggers
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct Employee
{
	string name ;
	float hoursWorked[5] = {0};
	float payRate = 0 ;
	float payForWeek = 0;
};

void initialize(Employee[]) ;
void compute(Employee&);
void print(Employee);

const int EMPLOYED = 4 ;

int main()
{
	//declarations
	Employee payroll[EMPLOYED] ;

	//welcome
	cout << "Hello and welcome to the program!\n\n" ;

	//initialize payroll array of employees
	initialize(payroll) ;

//	for (int i = 0 ; i < EMPLOYED ; i++)
//		{
//			cout << payroll[i].name << "\t" << payroll[i].payRate << endl
//			<< payroll[i].hoursWorked[0] << payroll[i].hoursWorked[1] << payroll[i].hoursWorked[2] << payroll[i].hoursWorked[3] << payroll[i].hoursWorked[4] ;
//		}

	//compute pay for the week one employee at a time
	for (int index = 0 ; index < EMPLOYED ; index++)
	{
		compute(payroll[index]) ;
	}

	//print out pay for each employee one at a time
	cout << "Here is the pay for each employee: \n\n" ;
	for (int index = 0 ; index < EMPLOYED ; index++)
	{
		print(payroll[index]) ;
		cout << endl ;
	}

	//goodbye
	cout << "Thank you for using the program, have a nice day!\n\n" ;
	return 0;
}

void initialize(Employee array[])
{
	for (int i = 0 ; i < EMPLOYED ; i++)
	{
		cout << "***********************************************************************\n\n" ;
		cout << "Please enter employee #" << (i+1) << " name (Press enter when done):" ;
		cin  >> array[i].name ;
		cout << endl ;

		cout << "Please enter employee #" << (i+1) << " hours worked for the week.\n" ;
			for(int day = 0; day < 5; day++)
			{
				cout << "Please enter hours worked by employee #" << (i+1) << " for day " << (day+1)
					 << " (Press enter when done):" ;
				cin  >> array[i].hoursWorked[day] ;
			}
		cout << endl ;

		cout << "Please enter employee #" << (i+1) << " pay rate (Press enter when done):" ;
		cin  >> array[i].payRate ;
		cout << endl ;

		cout << "***********************************************************************\n\n" ;

	}
};

void compute(Employee& worker)
{
	float totalHours  = 0 ;

	for (int i = 0 ; i < 5 ; i++)
	{
		totalHours += worker.hoursWorked[i] ;
	}

	if (totalHours < 40)
	{
		worker.payForWeek = totalHours * worker.payRate ;
	}
	else
	{
		worker.payForWeek = 40 * worker.payRate ;
		worker.payForWeek = worker.payForWeek + ((totalHours - 40)*(worker.payRate*1.5)) ;
	}
};

void print(Employee worker)
{
	cout << worker.name << " : $" << worker.payForWeek ;
};
