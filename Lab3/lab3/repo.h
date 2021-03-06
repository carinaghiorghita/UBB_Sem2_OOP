#pragma once

#include "domain.h"
#include "dynamicarray.h"
#include <stdlib.h>

#define MAXSIZE 200

typedef struct
{
	DynamicArray* filesInArchive;
}Repository;

Repository* createRepository();
/*
	Creates a new repository.
	Returns:
		-NULL if the memory could not be allocated
		-a pointer to an empty repository if the memory could be allocated
*/
DynamicArray* getAll(Repository* repository);
/*
	Getter for all the elements from the repository
	Returns: a pointer to a dynamic array which cointains the files.
*/
DynamicArray* getAllByType(Repository* repository, char* fileType);
/*
	Getter for all the elements from the repository of a certain type
	Returns: a pointer to a dynamic array which cointains the files.
*/
DynamicArray* getAllBeforeYear(Repository* repository, int yearOfCreation);
/*
	Getter for all the elements from the repository before a given year
	Returns: a pointer to a dynamic array which cointains the files.
*/
int fileExists(Repository* repository, File* file);
/*
	Checks if a given file exists in the repository.
	Returns:
		- 1 if the file exists
		- 0 if it doesn't
*/
int addFile(Repository* repository, File* file);
/*
	Adds a new file to the repository.
	Returns:
		- -1 if the file could not be added (it already exists);
		- 0 if the file was added
*/
int updateFile(Repository* repository, File* file);
/*
	Updates a  file in the repository.
	Returns:
		- -1 if the file could not be updated (doesn't exist);
		- 0 if the file was updated
*/
File* findFile(Repository* repository, File* file);
/*
	Gives a certain element from the repository.
	Returns: a pointer to the file we're searching for.
*/
int deleteFile(Repository* repository, File* file);
/*
	Deletes a file from the repository.
	Returns:
		- -1 if the file could not be deleted (file doesn't exist);
		- 0 if the file was deleted
*/
void destroyRepository(Repository* repository);
/*
	Frees the memory allocated for the repository.
*/