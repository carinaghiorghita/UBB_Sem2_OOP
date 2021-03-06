#pragma once
#include "operations.h"
#include "repo.h"

typedef struct
{
	Repository* repository;
	OperationStack* undoStack;
	OperationStack* redoStack;
	int canRecordOperation;
}Service;

Service* createService(Repository* repository,OperationStack* undoStack,OperationStack* redoStack);
/*
	Creates a new service.
	Returns:
		-NULL if the memory could not be allocated
		-a pointer to an empty service if the memory could be allocated
*/
void destroyService(Service* service);
/*
	Frees the memory allocated for the service.
*/
int addFileService(Service* service, int archiveCatalogueNumber, char* stateOfDeterioration, char* fileType, int yearOfCreation);
/*
	Adds a new file to the service.
	Returns:
		- -1 if the file could not be added (it already exists);
		- 0 if the file was added
*/
int updateFileService(Service* service, int archiveCatalogueNumber, char* newStateOfDeterioration, char* newFileType, int newYearOfCreation);
/*
	Updates a  file in the service.
	Returns:
		- -1 if the file could not be updated (doesn't exist);
		- 0 if the file was updated
*/
int deleteFileService(Service* service, int archiveCatalogueNumber);
/*
	Deletes a file from the service.
	Returns:
		- -1 if the file could not be deleted (file doesn't exist);
		- 0 if the file was deleted
*/
DynamicArray* getAllService(Service* service);
/*
	Getter for all the elements from the service
	Returns: a pointer to a dynamic array which cointains the files.
*/
DynamicArray* getAllByTypeService(Service* service,char* fileType);
/*
	Getter for all the elements from the service of a certain type
	Returns: a pointer to a dynamic array which cointains the files.
*/
DynamicArray* getAllBeforeYearService(Service* service, int yearOfCreation);
/*
	Getter for all the elements from the service before a given year
	Returns: a pointer to a dynamic array which cointains the files.
*/
int undoOperation(Service* service);
/*
	Undoes the last operation
	Returns:
		- 1 if the undo operation was successful
*/
int redoOperation(Service* service);
/*
	Redoes the last operation
	Returns:
		- 1 if the redo operation was successful
*/