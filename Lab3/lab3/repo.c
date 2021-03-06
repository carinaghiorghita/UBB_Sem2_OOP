#include "repo.h"
#include <string.h>

#define MAXCAPACITY 200

Repository* createRepository()
{
	Repository* repository = (Repository*)malloc(sizeof(Repository));
	if (repository == NULL) return NULL;
	repository->filesInArchive = createDynamicArray(MAXCAPACITY);
	return repository;
}

int fileExists(Repository* repository, File* file)
{
	return elementExists(repository->filesInArchive, file);
}

int addFile(Repository* repository, File* file)
{
	if (fileExists(repository,file)) return -1;
	File* copyOfFile = copyFile(file);
	addElement(repository->filesInArchive, copyOfFile);
	return 0;
}

int deleteFile(Repository* repository, File* file)
{
	if (!fileExists(repository, file)) return -1; 
	File* copyOfFile = copyFile(file);
	deleteElement(repository->filesInArchive, copyOfFile);
	return 0;
}

int updateFile(Repository* repository, File* file)
{
	if (!fileExists(repository, file)) return -1;
	File* copyOfFile = copyFile(file);
	updateElement(repository->filesInArchive, copyOfFile);
	return 0;
}

File* findFile(Repository* repository, File* file)
{
	return findElement(repository->filesInArchive, file);
}
DynamicArray* getAll(Repository* repository)
{
	return repository->filesInArchive;
}

DynamicArray* getAllByType(Repository* repository, char* fileType)
{
	return getAllByTypeInArray(repository->filesInArchive, fileType);
}

DynamicArray* getAllBeforeYear(Repository* repository, int yearOfCreation)
{
	return getAllBeforeDateInArray(repository->filesInArchive, yearOfCreation);
}

void destroyRepository(Repository* repository)
{
	destroyDynamicArray(repository->filesInArchive);
	free(repository);
}
