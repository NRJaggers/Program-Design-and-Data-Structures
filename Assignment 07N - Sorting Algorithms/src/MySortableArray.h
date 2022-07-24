/*
 * MySortableArray.h
 *
 *  Created on: April 14, 2020
 *      Author: Nathan Jaggers
 */

#include <iostream>
using namespace std;

#ifndef MYSORTABLEARRAY_H_
#define MYSORTABLEARRAY_H_


//Adjust this class to be a templated class
template <class type>
class MySortableArray
{
private:
	//members
	type* sortableArray;	//A private member variable called sortableArray that references a dynamic array
							//of type string.
	int size ;				//A private member variable called size that holds the number of entries in the array.

public:
	//constructor and copy constructor
	MySortableArray() ;
	MySortableArray(const MySortableArray&) ;

	//functions
	int		getSize();
	void	addEntry(type) ;
	int		deleteEntry(type) ;
	type	getEntry(int) ;
	void	merge(int, int,int);
	void	mergeSort(int, int);
	void	sort(int);

	//overloads
	MySortableArray<type>& operator = (const MySortableArray<type>&) ;

	//destructor
	~MySortableArray() ;

};

//constructor and copy constructor

//A default constructor that sets the dynamic array to NULL ( or nullptr) and sets size to 0.
template <class type>
MySortableArray<type> :: MySortableArray()
		{
			sortableArray = nullptr ;
			size = 0 ;
		}

//A copy constructor that makes a copy of the input object’s dynamic array.
template <class type>
MySortableArray<type> ::MySortableArray(const MySortableArray& temp)
		{
			size = temp.size ;
			sortableArray  = new type[size] ;

			for (int i = 0 ; i < size ; i++)
			{
				sortableArray[i] = temp.sortableArray[i] ;
			}
		}

//functions

//A function that returns size.
template <class type>
int		MySortableArray<type> :: getSize()
		{
			return size ;
		}

//A function named addEntry that takes a string as input. The function should create a new dynamic array one
//element larger than sortableArray, copy all elements from sortableArray into the new array, add the new string
//onto the end of the new array, increment size, delete the old sortableArray, and then set sortableArray to
//the new array.
template <class type>
void	MySortableArray<type> :: addEntry(type inputAdd)
		{
			type * temp = new type[(size + 1)]{0};

//				   for (int i = 0 ; i < size + 1 ; i++)
//					{
//					   cout << temp[i] << " " ;
//					}

				for (int i = 0 ; i < size ; i++)
					{
						temp[i] = sortableArray[i];
//						cout << "temp["<<i<<"] <= sortableArray["<<i<<"]"<<endl;
//						cout << "temp["<<i<<"] = "<<temp[i]<<endl;
//						cout << "sortableArray["<<i<<"] = "<<sortableArray[i]<<endl;
					}

			//trouble shooting
			//cout << "size: " << size << " input : " << inputAdd << endl ;

			temp[size] = inputAdd ;
			//cout << "temp["<<size<<"] <= "<<inputAdd<<endl;
			size++;

			delete[] sortableArray ;
			sortableArray = temp ;
			temp = nullptr ;

		}

//A function named deleteEntry that takes a string as input. The function should search sortableArray for the string.
//If not found, return false.  If found, create a new dynamic array one element smaller than sortableArray.
//Copy all elements except the input string into the new array, delete sortableArray, decrement size, and return true.
template <class type>
int		MySortableArray<type> :: deleteEntry(type inputDel)
		{
			bool found = false ;
			int delIndex = -1 ;

			for (int i = 0 ; i < size ; i++)
			{
				if(sortableArray[i] == inputDel)
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
						temp[k] = sortableArray[j] ;
					}
					else
					{
						k-- ;
					}
				}

				delete[] sortableArray ;

				sortableArray = temp ;
				size-- ;

				temp = nullptr ;
			}

			return found ;
		}

//A function named getEntry that takes an integer as input and returns the string at that index in sortableArray.
//Return NULL if the index is out of sortableArray’s bounds.
template <class type>
type	MySortableArray<type>:: getEntry(int index)
		{
			if (index < size)
			{
				//cout << "size : " << size << "\n" ;
					for (int i = 0 ; i < size ; i++)
					{
						//cout << "i : " << i << " " ;
						//cout << "element : " << sortableArray[i] << endl ;

						if (i == index)
						{
							//output = sortableArray[i] ;
							return sortableArray[i] ;
						}
					}
			}
			else
			{
				cout << "Index out of bounds.\n Returning -1.\n";
				return -1 ;
			}

		}

//A function named merge that takes an integer as input and sorts up to that index.
template <class type>
void	MySortableArray<type>:: merge(int start, int mid, int end)
		{

			// create a temp array
			int temp[end - start + 1];

			// crawlers for both intervals and for temp
			int i = start, j = mid+1, k = 0;

			// traverse both arrays and in each iteration add smaller of both elements in temp
			while(i <= mid && j <= end) {
				if(sortableArray[i] <= sortableArray[j]) {
					temp[k] = sortableArray[i];
					k += 1; i += 1;
				}
				else {
					temp[k] = sortableArray[j];
					k += 1; j += 1;
				}
			}

			// add elements left in the first interval
			while(i <= mid) {
				temp[k] = sortableArray[i];
				k += 1; i += 1;
			}

			// add elements left in the second interval
			while(j <= end) {
				temp[k] = sortableArray[j];
				k += 1; j += 1;
			}

			// copy temp to original interval
			for(i = start; i <= end; i += 1) {
				sortableArray[i] = temp[i - start] ;
			}

		}

//A function named sort that takes an integer as input and mergesorts up to that index.
template <class type>
void	MySortableArray<type>:: mergeSort(int start, int end)
		{
			if (end >= size)
			{
				cout << "Sorting index is out of bounds\nTry again.\n";
				return;
			}
			if (start < end)
			{
				int mid = (start+end)/2 ;
				mergeSort(start, mid) ;
				mergeSort((mid+1), end);
				merge(start, mid, end);
			}
		}
template <class type>
void	MySortableArray<type>:: sort(int end)
		{
			int start = 0 ;
			mergeSort(start,end);
		}

//overloads

//Overload the assignment operator so that the dynamic array is properly copied to the target object.
template <class type>
		MySortableArray<type>& MySortableArray<type>::operator = (const MySortableArray<type>  &temp)
		{
			size = temp.size ;
			sortableArray  = new type[size] ;

			for (int i = 0 ; i < size ; i++)
			{
				sortableArray[i] = temp.sortableArray[i] ;
			}

			return *this;
		}

//destructor

//A destructor that frees up the memory allocated to the dynamic array.
template <class type>
		MySortableArray<type> :: ~MySortableArray()
		{
			delete[] sortableArray ;
		}


#endif /* MySortableArray.h */
