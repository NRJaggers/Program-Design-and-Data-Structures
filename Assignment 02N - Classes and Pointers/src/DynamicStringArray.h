/*
 * DynamicStringArray.h
 *
 *  Created on: Feb 10, 2020
 *      Author: Nathan Jaggers
 */

#include <iostream>
using namespace std;

#ifndef DYNAMICSTRINGARRAY_H_
#define DYNAMICSTRINGARRAY_H_

class DynamicStringArray
{
private:
	//members
	string* dynamicArray;	//A private member variable called dynamicArray that references a dynamic array
							//of type string.
	int size ;				//A private member variable called size that holds the number of entries in the array.

public:
	//constructor and copy constructor
	DynamicStringArray() ;
	DynamicStringArray(const DynamicStringArray&) ;

	//functions
	int		getSize();
	void	addEntry(string) ;
	int		deleteEntry(string) ;
	string	getEntry(int) ;

	//overloads
	DynamicStringArray operator = (const DynamicStringArray&) ;

	//destructor
	~DynamicStringArray() ;

};

//constructor and copy constructor

//A default constructor that sets the dynamic array to NULL ( or nullptr) and sets size to 0.
DynamicStringArray :: DynamicStringArray()
		{
			dynamicArray = nullptr ;
			size = 0 ;
		}

//A copy constructor that makes a copy of the input object’s dynamic array.
DynamicStringArray ::DynamicStringArray(const DynamicStringArray& temp)
		{
			size = temp.size ;
			dynamicArray  = new string[size] ;

			for (int i = 0 ; i < size ; i++)
			{
				dynamicArray[i] = temp.dynamicArray[i] ;
			}
		}

//functions

//A function that returns size.
int		DynamicStringArray :: getSize()
		{
			return size ;
		}

//A function named addEntry that takes a string as input. The function should create a new dynamic array one
//element larger than dynamicArray, copy all elements from dynamicArray into the new array, add the new string
//onto the end of the new array, increment size, delete the old dynamicArray, and then set dynamicArray to
//the new array.
void	DynamicStringArray :: addEntry(string inputAdd)
		{
			string * temp = new string[size + 1] ;

				for (int i = 0 ; i < size ; i++)
					{
						temp[i] = dynamicArray[i];
					}

			//trouble shooting
			//cout << "size: " << size << " input : " << inputAdd << endl ;

			temp[size] = inputAdd ;
			size++;

			delete[] dynamicArray ;
			dynamicArray = temp ;
			temp = nullptr ;

		}

//A function named deleteEntry that takes a string as input. The function should search dynamicArray for the string.
//If not found, return false.  If found, create a new dynamic array one element smaller than dynamicArray.
//Copy all elements except the input string into the new array, delete dynamicArray, decrement size, and return true.
int		DynamicStringArray :: deleteEntry(string inputDel)
		{
			bool found = false ;
			int delIndex = -1 ;

			for (int i = 0 ; i < size ; i++)
			{
				if(dynamicArray[i] == inputDel)
				{
					found = true ;
					delIndex = i ;
				}
			}

			if(found)
			{
				string* temp = new string[size - 1] ;

				for(int j = 0, k = 0 ; j < size ; j++, k++)
				{
					if(j != delIndex )
					{
						temp[k] = dynamicArray[j] ;
					}
					else
					{
						k-- ;
					}
				}

				delete[] dynamicArray ;

				dynamicArray = temp ;
				size-- ;

				temp = nullptr ;
			}

			return found ;
		}

//A function named getEntry that takes an integer as input and returns the string at that index in dynamicArray.
//Return NULL if the index is out of dynamicArray’s bounds.
string	DynamicStringArray :: getEntry(int index)
		{
			string output = "NULL" ;

				for (int i = 0 ; i < size ; i++)
				{
					if (i == index)
					{
						output = dynamicArray[i] ;
					}
				}

			return output ;
		}

//overloads

//Overload the assignment operator so that the dynamic array is properly copied to the target object.
		DynamicStringArray DynamicStringArray::operator = (const DynamicStringArray  &temp)
		{
			size = temp.size ;
			dynamicArray  = new string[size] ;

			for (int i = 0 ; i < size ; i++)
			{
				dynamicArray[i] = temp.dynamicArray[i] ;
			}

			return *this;
		}

//destructor

//A destructor that frees up the memory allocated to the dynamic array.
		DynamicStringArray :: ~DynamicStringArray()
		{
			delete[] dynamicArray ;
		}


#endif /* DYNAMICSTRINGARRAY_H_ */
