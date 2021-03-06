#include "domain.h"
#include <string.h>
#include <stdlib.h>

File* createFile(int catalogueNumber, char* state[], char* type[], int year)
{
	File* file=(File*)malloc(sizeof(File));
	if (file == NULL)
		return NULL;

	file->archiveCatalogueNumber = catalogueNumber;

	file->stateOfDeterioration = (char*)malloc(sizeof(char) * (strlen(state) + 1));
	if(file->stateOfDeterioration!=NULL)
		strcpy(file->stateOfDeterioration, state);

	file->fileType = (char*)malloc(sizeof(char) * (strlen(type) + 1));
	if(file->fileType!=NULL)
		strcpy(file->fileType, type);

	file->yearOfCreation = year;

	return file;

}

int getCatalogueNumber(File* file)
{
	return file->archiveCatalogueNumber;
}

char* getState(File* file)
{
	return file->stateOfDeterioration;
}

char* getType(File* file)
{
	return file->fileType;
}

int getYear(File* file)
{
	return file->yearOfCreation;
}

File* copyFile(File* file)
{
	File* newFile = createFile(getCatalogueNumber(file), getState(file), getType(file), getYear(file));
	return newFile;
}

void destroyFile(File* file)
{
	free(file->stateOfDeterioration);
	free(file->fileType);

	free(file);
}
