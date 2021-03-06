#pragma once

typedef struct
{
	int archiveCatalogueNumber;
	char* stateOfDeterioration;
	char* fileType;
	int yearOfCreation;
} File;

File* createFile(int catalogueNumber, char* state[], char* type[], int year);
/*
	Creates a new file.
	Returns:
		-NULL if the memory could not be allocated
		-a pointer to an empty file if the memory could be allocated
*/
int getCatalogueNumber(File* file);
/*
	Returns: the catalogue number of the given file.
*/
char* getState(File* file);
/*
	Returns: a pointer to the state of the given file.
*/
char* getType(File* file);
/*
	Returns: a pointer to the type of the given file.
*/
int getYear(File* file);
/*
	Returns: the year of creation of the given file.
*/
File* copyFile(File* file);
/*
	Copies a given file.
	Returns a pointer to said copy.
*/
void destroyFile(File* file);
/*
	Frees the memory allocated for the file.
*/