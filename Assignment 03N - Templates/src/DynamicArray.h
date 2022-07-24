/*
 * DynamicArray.h
 *
 *  Created on: Feb 10, 2020
 *      Author: Nathan Jaggers
 */

#include <iostream>
using namespace std;

#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_


//Adjust this class to be a templated class
template <class type>
class DynamicArray
{
private:
	//members
	type* dynamicArray;	//A private member variable called dynamicArray that references a dynamic array
							//of type string.
	int size ;				//A private member variable called size that holds the number of entries in the array.

public:
	//constructor and copy constructor
	DynamicArray() ;
	DynamicArray(const DynamicArray&) ;

	//functions
	int		getSize();
	void	addEntry(type) ;
	int		deleteEntry(type) ;
	type	getEntry(int) ;

	//overloads
	DynamicArray<type>& operator = (const DynamicArray<type>&) ;

	//destructor
	~DynamicArray() ;

};

//constructor and copy constructor

//A default constructor that sets the dynamic array to NULL ( or nullptr) and sets size to 0.
template <class type>
DynamicArray<type> :: DynamicArray()
		{
			dynamicArray = nullptr ;
			size = 0 ;
		}

//A copy constructor that makes a copy of the input object’s dynamic array.
template <class type>
DynamicArray<type> ::DynamicArray(const DynamicArray& temp)
		{
			size = temp.size ;
			dynamicArray  = new type[size] ;

			for (int i = 0 ; i < size ; i++)
			{
				dynamicArray[i] = temp.dynamicArray[i] ;
			}
		}

//functions

//A function that returns size.
template <class type>
int		DynamicArray<type> :: getSize()
		{
			return size ;
		}

//A function named addEntry that takes a string as input. The function should create a new dynamic array one
//element larger than dynamicArray, copy all elements from dynamicArray into the new array, add the new string
//onto the end of the new array, increment size, delete the old dynamicArray, and then set dynamicArray to
//the new array.
template <class type>
void	DynamicArray<type> :: addEntry(type inputAdd)
		{
			type * temp = new type[size + 1] ;

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
template <class type>
int		DynamicArray<type> :: deleteEntry(type inputDel)
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
				type* temp = new type[size - 1] ;

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
template <class type>
type	DynamicArray<type>:: getEntry(int index)
		{
			//type output = '/0' ;

				for (int i = 0 ; i < size ; i++)
				{
					if (i == index)
					{
						//output = dynamicArray[i] ;
						return dynamicArray[i] ;
					}
				}

			//return output ;
		}

//overloads

//Overload the assignment operator so that the dynamic array is properly copied to the target object.
template <class type>
		DynamicArray<type>& DynamicArray<type>::operator = (const DynamicArray<type>  &temp)
		{
			size = temp.size ;
			dynamicArray  = new type[size] ;

			for (int i = 0 ; i < size ; i++)
			{
				dynamicArray[i] = temp.dynamicArray[i] ;
			}

			return *this;
		}

//destructor

//A destructor that frees up the memory allocated to the dynamic array.
template <class type>
		DynamicArray<type> :: ~DynamicArray()
		{
			delete[] dynamicArray ;
		}


#endif /* DynamicArray_H_ */
