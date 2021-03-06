#pragma once
#include "domain.h"

typedef File* TElement;

typedef struct
{
	TElement* elements;
	int length;
	int capacity;
}DynamicArray;

DynamicArray* createDynamicArray(int capacity);
/*
	Creates a new dynamic array.
	Returns:
		-NULL if the memory could not be allocated
		-a pointer to an empty dynamic array if the memory could be allocated
*/
void destroyDynamicArray(DynamicArray* array);
/*
	Frees the memory allocated for the dynamic array.
*/
int elementExists(DynamicArray* array, TElement element);
/*
	Checks if a given element exists in the array.
	Returns:
		- 1 if the element exists
		- 0 if it doesn't
*/
int addElement(DynamicArray* array, TElement element);
/*
	Adds a new element to the array.
	Returns:
		- -1 if the element could not be added (it already exists);
		- 0 if the element was added
*/
int deleteElement(DynamicArray* array, TElement element);
/*
	Delets an element from the array.
	Returns:
		- -1 if the element could not be deleted (doesn't exist);
		- 0 if the element was deleted
*/
int updateElement(DynamicArray* array, TElement element);
/*
	Updates an element in the array.
	Returns:
		- -1 if the element could not be updated (doesn't exist);
		- 0 if the element was updated
*/
TElement* findElement(DynamicArray* array, TElement element);
/*
	Gives a certain element from the array.
	Returns: a pointer to the file we're searching for.
*/
int getLengthOfArray(DynamicArray* array);
/*
	Returns: the length of the dynamic array
*/
DynamicArray* getAllByTypeInArray(DynamicArray* array,char* fileType);
/*
	Getter for all the elements from the array of a certain type
	Returns: a pointer to a dynamic array which cointains the files.
*/
DynamicArray* getAllBeforeDateInArray(DynamicArray* array,int yearOfCreation);
/*
	Getter for all the elements from the service before a given year
	Returns: a pointer to a dynamic array which cointains the files.
*/