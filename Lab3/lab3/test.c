#include "test.h"
#include "controller.h"
#include <assert.h>
#include <string.h>
#define MAXCAPACITY 200

void testFile()
{
	File* file = createFile(1, "good", "newspaper", 1990);

	assert(getCatalogueNumber(file) == 1);
	assert(strcmp(getState(file), "good") == 0);
	assert(strcmp(getType(file), "newspaper") == 0);
	assert(getYear(file) == 1990);

	destroyFile(file);
}

void testDynamicArray()
{
	DynamicArray* array = createDynamicArray(MAXCAPACITY);

	File* file = createFile(1, "good", "newspaper", 1990);
	assert(addElement(array, file) == 0);
	assert(elementExists(array, file));
	assert(getLengthOfArray(array) == 1);

	File* newFile = findElement(array, file);
	assert(getCatalogueNumber(newFile) == 1);
	assert(strcmp(getState(newFile), "good") == 0);
	assert(strcmp(getType(newFile), "newspaper") == 0);
	assert(getYear(newFile) == 1990);

	File* anotherFile = createFile(1, "bad", "journal", 1900);
	assert(updateElement(array, anotherFile) == 0);
	assert(getLengthOfArray(array) == 1);

	DynamicArray* anotherArray = createDynamicArray(MAXCAPACITY);
	anotherArray = getAllByTypeInArray(array, "journal");
	assert(getLengthOfArray(anotherArray) == 1);
	anotherArray = getAllByTypeInArray(array, "newspaper");
	assert(getLengthOfArray(anotherArray) == 0);

	anotherArray = getAllBeforeDateInArray(array, 2000);
	assert(getLengthOfArray(anotherArray) == 1);
	anotherArray = getAllBeforeDateInArray(array, 1800);
	assert(getLengthOfArray(anotherArray) == 0);

	assert(deleteElement(array, file) == 0);
	assert(getLengthOfArray(array) == 0);

	destroyFile(file);
	destroyFile(newFile);
	destroyFile(anotherFile);
	destroyDynamicArray(array);
	destroyDynamicArray(anotherArray);
}

void testRepository()
{
	Repository* repository = createRepository();

	File* file = createFile(1, "good", "newspaper", 1990);
	assert(addFile(repository, file) == 0);
	assert(fileExists(repository, file) == 1);
	File* newFile = findFile(repository, file);
	assert(getCatalogueNumber(newFile) == 1);
	assert(strcmp(getState(newFile), "good") == 0);
	assert(strcmp(getType(newFile), "newspaper") == 0);
	assert(getYear(newFile) == 1990);

	File* anotherFile=createFile(1, "bad", "journal", 1900);
	assert(updateFile(repository, anotherFile) == 0);
	assert(fileExists(repository, anotherFile) == 1);

	DynamicArray* dataInArchive = createDynamicArray(MAXCAPACITY);
	dataInArchive = getAll(repository);
	assert(elementExists(dataInArchive, anotherFile) == 1);

	dataInArchive = getAllByType(repository,"journal");
	assert(elementExists(dataInArchive, anotherFile) == 1);
	dataInArchive = getAllByType(repository, "news");
	assert(elementExists(dataInArchive, anotherFile) == 0);

	dataInArchive = getAllBeforeYear(repository, 2000);
	assert(elementExists(dataInArchive, anotherFile) == 1);
	dataInArchive = getAllBeforeYear(repository, 1800);
	assert(elementExists(dataInArchive, anotherFile) == 0);

	assert(deleteFile(repository, file) == 0);
	assert(elementExists(repository, file) == 0);

	destroyFile(file);
	destroyFile(newFile);
	destroyFile(anotherFile);
	destroyDynamicArray(dataInArchive);
	destroyRepository(repository);
	
}

void testOperations()
{
	File* file = createFile(1, "good", "newspaper", 1990);
	Operation* operation = createOperation(file, "add");

	OperationStack* stack = createStack();
	assert(stackIsEmpty(stack));
	push(stack, operation);
	assert(!stackIsEmpty(stack));
	assert(!stackIsFull(stack));
	Operation* newOperation = createOperation(file, "add");
	newOperation = pop(stack);
	assert(stackIsEmpty(stack));

	destroyFile(file);
	destroyOperation(operation);
	destroyOperation(newOperation);
	destroyStack(stack);
}

void testService()
{
	Repository* repository = createRepository();
	OperationStack* undoStack = createStack();
	OperationStack* redoStack = createStack();
	Service* service = createService(repository, undoStack, redoStack);

	assert(addFileService(service, 1, "good", "newspaper", 1990)==0);
	assert(updateFileService(service, 1, "bad", "journal", 2000)==0);
	assert(deleteFileService(service, 1)==0);
	assert(undoOperation(service));
	assert(redoOperation(service));

	File* anotherFile = createFile(1, "good", "newspaper", 1990);

	destroyRepository(repository);
	destroyStack(undoStack);
	destroyStack(redoStack);
	destroyFile(anotherFile);
	destroyService(service);

}