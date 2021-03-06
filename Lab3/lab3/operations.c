#include "operations.h"
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 200

Operation* createOperation(File* file, char* operationType)
{
	Operation* operation = (Operation*)malloc(sizeof(Operation));
	operation->file = copyFile(file);
	
	operation->operationType = (char*)malloc(sizeof(char) * (strlen(operationType) + 1));
	strcpy(operation->operationType, operationType);

	return operation;
}

void destroyOperation(Operation* operation)
{
	destroyFile(operation->file);
	free(operation->operationType);
	free(operation);
}

Operation* copyOperation(Operation* operation)
{
	Operation* newOperation=createOperation(getFile(operation),getOperationType(operation));
	return newOperation;
}

char* getOperationType(Operation* operation)
{
	return operation->operationType;
}

File* getFile(Operation* operation)
{
	return operation->file;
}

OperationStack* createStack()
{
	OperationStack* operationStack = (OperationStack*)malloc(sizeof(OperationStack));
	operationStack->lengthOfOperationArray = 0;

	return operationStack;
}

void destroyStack(OperationStack* operationStack)
{
	int operationIndex;
	for (operationIndex = 0; operationIndex < operationStack->lengthOfOperationArray; ++operationIndex)
		destroyOperation(operationStack->operationArray[operationIndex]);

	free(operationStack);
}

void push(OperationStack* operationStack, Operation* operation)
{
	if (stackIsFull(operationStack)) return NULL;
	operationStack->operationArray[operationStack->lengthOfOperationArray++] = copyOperation(operation);
}

Operation* pop(OperationStack* operationStack)
{
	if (stackIsEmpty(operationStack))
		return NULL;
	operationStack->lengthOfOperationArray--;
	return operationStack->operationArray[operationStack->lengthOfOperationArray];
}

int stackIsEmpty(OperationStack* operationStack)
{
	return operationStack->lengthOfOperationArray==0;
}

int stackIsFull(OperationStack* operationStack)
{
	return operationStack->lengthOfOperationArray == MAXSIZE;
}



