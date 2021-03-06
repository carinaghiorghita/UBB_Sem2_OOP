#pragma once
#include "domain.h"
#include "dynamicarray.h"
//#include <stdbool.h>
#define MAXSIZE 200

typedef struct
{
	File* file;
	char* operationType;
}Operation;

Operation* createOperation(File* file, char* operationType);
/*
	Creates a new operation stack.
	Returns:
		-NULL if the memory could not be allocated
		-a pointer to an empty repository if the memory could be allocated
*/
void destroyOperation(Operation* operation);
/*
	Frees the memory allocated for the operation.
*/
Operation* copyOperation(Operation* operation);
/*
	Copies a given operation.
	Returns a pointer to said copy.
*/
char* getOperationType(Operation* operation);
/*
	Gets the type of a given operation.
	Returns: the type of the operation.
*/
File* getFile(Operation* operation);
/*
	Gets the file of a given operation.
	Returns: a pointer to the file of the operation.
*/

typedef struct
{
	Operation* operationArray[MAXSIZE];
	int lengthOfOperationArray;
	//int currentOperationIndex;
	//bool lastOperationUndo;
}OperationStack;

OperationStack* createStack();
/*
	Creates a new operation stack.
	Returns:
		-NULL if the memory could not be allocated
		-a pointer to an empty operation stack if the memory could be allocated
*/
void destroyStack(OperationStack* operationStack);
/*
	Frees the memory allocated for the stack.
*/
void push(OperationStack* operationStack, Operation* operation);
/*
	Adds an element to the given stack.
*/
Operation* pop(OperationStack* operationStack);
/*
	Gives the operation at the top of the stack.
	Returns: a pointer to said operation.
*/
int stackIsEmpty(OperationStack* operationStack);
/*
	Checks if the stack is empty.
	Returns:
		- 0 if the stack is not empty;
		- 1 if the stack is empty.
*/
int stackIsFull(OperationStack* operationStack);
/*
	Checks if the stack is full.
	Returns:
		- 0 if the stack is not full;
		- 1 if the stack is full.
*/