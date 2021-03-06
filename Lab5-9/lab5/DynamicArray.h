#pragma once
#include "Victim.h"
#include <vector>
using namespace std;
template <typename TElement>

class DynamicArray
{
private:
	vector<TElement> elements; 
public:
	//default constructor
	DynamicArray() {};

	//copy constructor
	DynamicArray(const DynamicArray& array);

	//destructor
	~DynamicArray();

	//assignment operator
	DynamicArray& operator=(const vector<TElement> array);

	TElement& findElement(const std::string name);
	/*
	Returns the element that has the given name.
	*/
	int elementExists(const TElement& element);
	/*
	Checks if a given element exists in the dynamic array.
	Returns:
		- 1 if the element exists
		- 0 otherwise
	*/
	int addElement(const TElement& element);
	/*
	Adds a new element in the dynamic array.
	Returns:
		- 1 if the element was added
		- 0 if the element could not be added (it already exists in the array)
	*/
	int deleteElement(const TElement& element);
	/*
	Deletes an element from the dynamic array.
	Returns:
		- 1 if the element was deleted
		- 0 if the element could not be deleted (it doesn't exist in the array)
	*/
	int updateElement(const TElement& element);
	/*
	Updates an element in the dynamic array.
	Returns:
		- 1 if the element was updated
		- 0 if the element could not be updated (it doesn't already exist in the array)
	*/
	int getSize(); //returns the size of the dynamic array
	TElement& operator[](int position); //returns the element on the given position in the dynamic array



};



template<typename TElement>

inline DynamicArray<TElement>::DynamicArray(const DynamicArray& array)
{
	this->elements.clear();

	for (auto iterator = array.elements.begin(); iterator != array.elements.end(); ++iterator)
		this->elements.push_back(*iterator);
}

template<typename TElement>
inline DynamicArray<TElement>::~DynamicArray()
{
	this->elements.clear();
}

template<typename TElement>
inline DynamicArray<TElement>& DynamicArray<TElement>::operator=(const vector<TElement> array)
{
	
	this->elements.clear();

	for (auto iterator = array.begin(); iterator != array.end(); ++iterator)
		this->elements.push_back(*iterator);
	return *this;
}

template<typename TElement>
inline TElement& DynamicArray<TElement>::findElement(const std::string name)
{
	for (auto iterator = this->elements.begin(); iterator != this->elements.end(); ++iterator)
		if (iterator->getName() == name) return *iterator;
	TElement element{ "","",0,"" };
	return element;
}

template<typename TElement>
inline int DynamicArray<TElement>::elementExists(const TElement& element)
{
	for (auto iterator = this->elements.begin(); iterator != this->elements.end(); ++iterator)
		if (iterator->getName() == element.getName()) return 1;
	return 0;
}

template<typename TElement>
inline int DynamicArray<TElement>::addElement(const TElement& element)
{
	if (this->elementExists(element))return 0;
	this->elements.push_back(element);
	return 1;
}

template<typename TElement>
inline int DynamicArray<TElement>::deleteElement(const TElement& element)
{
	if (!this->elementExists(element))return 0;
	for (auto iterator = this->elements.begin(); iterator != this->elements.end(); ++iterator)
		if (iterator->getName() == element.getName())
		{
			this->elements.erase(iterator);
			return 1;
		}
}

template<typename TElement>
inline int DynamicArray<TElement>::updateElement(const TElement& element)
{
	if (!this->elementExists(element))return 0;
	for (auto iterator = this->elements.begin(); iterator != this->elements.end(); ++iterator)
		if (iterator->getName() == element.getName())
		{
			this->elements.erase(iterator);
			this->elements.push_back(element);
			return 1;
		}
}

template<typename TElement>
inline int DynamicArray<TElement>::getSize()
{
	return this->elements.size();
}

template<typename TElement>
inline TElement& DynamicArray<TElement>::operator[](int position)
{
	TElement element{ "","",0,"" };
	if (position<0||position >= this->elements.size()) return element;
	return this->elements[position];
}

