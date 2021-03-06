#include "DynamicArray.h"
#include <stdlib.h>
#include <string.h>

#define MAXCAPACITY 200

DynamicArray* createDynamicArray(int capacity)
{
	DynamicArray* array = (DynamicArray*)malloc(sizeof(DynamicArray));
	if (array == NULL)
		return NULL;

	array->capacity = capacity;
	array->length = 0;

	array->elements = (TElement*)malloc(capacity * sizeof(TElement));
	if (array->elements == NULL)
		return NULL;

	return array;
}

void destroyDynamicArray(DynamicArray* array)
{
	if (array == NULL)
		return;
	int index;
	for (index = 0; index < array->length; index++)
		destroyFile(array->elements[index]);

	free(array->elements);
	array->elements = NULL;

	free(array);
	array = NULL;
}


int elementExists(DynamicArray* array, TElement element)
{
	int elementIndex;
	for (elementIndex = 0; elementIndex < array->length; ++elementIndex)
		if (getCatalogueNumber(array->elements[elementIndex]) == getCatalogueNumber(element)) return 1;
	return 0;
}

int resize(DynamicArray* array) 
{
	if (array == NULL)
		return 0;
	array->capacity *= 2;

	TElement* auxiliaryElement = (TElement*)malloc(array->capacity * sizeof(TElement));
	if (auxiliaryElement == NULL)
		return -1;
	for (int i = 0; i < array->length; i++) {
		auxiliaryElement[i] = array->elements[i];
	}
	free(array->elements);
	array->elements = auxiliaryElement;

	return 0;
}

int addElement(DynamicArray* array, TElement element)
{
	if (array == NULL)
		return;
	if (array->elements == NULL)
		return;
	if (array->length == array->capacity)
		resize(array);
	array->elements[array->length++] = element;
	return 0;
}

int deleteElement(DynamicArray* array, TElement element)
{
	if (array == NULL)
		return;
	if (array->elements == NULL)
		return;
	int elementIndex;
	for(elementIndex=0;elementIndex<array->length;++elementIndex)
		if (getCatalogueNumber(array->elements[elementIndex]) == getCatalogueNumber(element))
		{
			array->elements[elementIndex] = array->elements[array->length - 1];
			array->length--;
			return 0;
		}
	return -1;
}

int updateElement(DynamicArray* array, TElement element)
{
	int elementIndex;
	for (elementIndex = 0; elementIndex < array->length; ++elementIndex)
		if (getCatalogueNumber(array->elements[elementIndex]) == getCatalogueNumber(element))
		{
			array->elements[elementIndex] = element;
			return 0;
		}
	return -1;
}

TElement* findElement(DynamicArray* array, TElement element)
{
	int elementIndex;
	for (elementIndex = 0; elementIndex < array->length; ++elementIndex)
		if (getCatalogueNumber(array->elements[elementIndex]) == getCatalogueNumber(element))
		{
			TElement* foundFile = copyFile(array->elements[elementIndex]);
			return foundFile;
		}
	return NULL;
}

int getLengthOfArray(DynamicArray* array)
{
	if (array == NULL)
		return -1;

	return array->length;
}

DynamicArray* getAllByTypeInArray(DynamicArray* array, char* fileType)
{
	DynamicArray* dataByType = createDynamicArray(MAXCAPACITY);
	int fileIndex;
	for (fileIndex = 0; fileIndex < array->length; ++fileIndex)
		if (strcmp(getType(array->elements[fileIndex]), fileType) == 0)
			dataByType->elements[dataByType->length++] = array->elements[fileIndex];
	return dataByType;
}

DynamicArray* getAllBeforeDateInArray(DynamicArray* array, int yearOfCreation)
{
	DynamicArray* dataBeforeYear = createDynamicArray(MAXCAPACITY);
	int fileIndex, anotherFileIndex;
	TElement* auxiliaryElement=createFile(0,"state","type",0);
	for (fileIndex = 0; fileIndex < array->length; ++fileIndex)
		if (getYear(array->elements[fileIndex]) < yearOfCreation)
			dataBeforeYear->elements[dataBeforeYear->length++] = array->elements[fileIndex];
	//maybe think of a better sort?
	for (fileIndex = 0; fileIndex < dataBeforeYear->length - 1; ++fileIndex)
		for (anotherFileIndex = fileIndex + 1; anotherFileIndex < dataBeforeYear->length; ++anotherFileIndex)
			if (strcmp(getState(dataBeforeYear->elements[fileIndex]), getState(dataBeforeYear->elements[anotherFileIndex])) > 0)
			{
				auxiliaryElement = dataBeforeYear->elements[fileIndex];
				dataBeforeYear->elements[fileIndex] = dataBeforeYear->elements[anotherFileIndex];
				dataBeforeYear->elements[anotherFileIndex] = auxiliaryElement;
			}
	return dataBeforeYear;
}