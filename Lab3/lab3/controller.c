#include "controller.h"

Service* createService(Repository* repository,OperationStack* undoStack,OperationStack* redoStack)
{
	Service* service = (Service*)malloc(sizeof(Service));
	if (service == NULL) return NULL;
	service->repository=repository;
	service->undoStack = undoStack;
	service->redoStack = redoStack;
	service->canRecordOperation = 1;
	return service;
}

void destroyService(Service* service)
{
	destroyRepository(service->repository);
	destroyStack(service->undoStack);
	destroyStack(service->redoStack);
	free(service);
}

int addFileService(Service* service, int archiveCatalogueNumber, char* stateOfDeterioration, char* fileType, int yearOfCreation)
{
	File* file = createFile(archiveCatalogueNumber, stateOfDeterioration, fileType, yearOfCreation);
	int result = addFile(service->repository, file);
	if (result == 0&&service->canRecordOperation) 
	{
		if (!stackIsEmpty(service->redoStack))
		{
			destroyStack(service->redoStack);
			service->redoStack = createStack();
		}
		Operation* operation = createOperation(file, "add");
		push(service->undoStack, operation);
	}
	destroyFile(file);
	return result;
}

int updateFileService(Service* service, int archiveCatalogueNumber, char* newStateOfDeterioration, char* newFileType, int newYearOfCreation)
{
	File* newFile = createFile(archiveCatalogueNumber, newStateOfDeterioration, newFileType, newYearOfCreation);
	File* oldFile = copyFile(findFile(service->repository,newFile));
	int result = updateFile(service->repository, newFile);
	if (result == 0 && service->canRecordOperation)
	{
		if (!stackIsEmpty(service->redoStack)) {
			destroyStack(service->redoStack);
			service->redoStack = createStack();
		}
		Operation* operation = createOperation(newFile, "update");
		Operation* anotherOperation = createOperation(oldFile, "update");
		push(service->undoStack, operation);
		push(service->redoStack, anotherOperation);
		destroyOperation(anotherOperation);
		destroyOperation(operation);
	}
	destroyFile(oldFile);
	destroyFile(newFile);
	return result;
}

int deleteFileService(Service* service, int archiveCatalogueNumber)
{
	File* scrapFile = createFile(archiveCatalogueNumber, "state", "type", 0);
	File* file = copyFile(findFile(service->repository, scrapFile));
	int result = deleteFile(service->repository, file);
	if (result == 0 && service->canRecordOperation)
	{
		if (!stackIsEmpty(service->redoStack))
		{
			destroyStack(service->redoStack);
			service->redoStack = createStack();
		}
		Operation* operation = createOperation(file, "delete");
		push(service->undoStack, operation);
	}
	destroyFile(file);
	return result;
}

DynamicArray* getAllService(Service* service)
{
	return getAll(service->repository);
}

DynamicArray* getAllByTypeService(Service* service, char fileType[])
{
	return getAllByType(service->repository, fileType);
}

DynamicArray* getAllBeforeYearService(Service* service, int yearOfCreation)
{
	return getAllBeforeYear(service->repository, yearOfCreation);
}

int undoOperation(Service* service)
{
	if (stackIsEmpty(service->undoStack)) return 0;
	Operation* operation = pop(service->undoStack);
	if (strcmp(getOperationType(operation), "add") == 0)
	{
		File* file = getFile(operation);
		Operation* anotherOperation = createOperation(file, "add");
		push(service->redoStack, anotherOperation);
		destroyOperation(anotherOperation);
		deleteFile(service->repository, file);
	}
	else if (strcmp(getOperationType(operation), "delete") == 0)
	{
		File* file = getFile(operation);
		Operation* anotherOperation = createOperation(file, "delete");
		push(service->redoStack, anotherOperation);
		destroyOperation(anotherOperation);
		addFile(service->repository, file);
	}
	else if (strcmp(getOperationType(operation), "update") == 0) 
	{
		Operation* newOperation = pop(service->undoStack);
		File* file = getFile(newOperation);
		updateFile(service->repository,file);
		push(service->redoStack, operation);
		//push(service->redoStack, newOperation);
		destroyOperation(newOperation);
	}
	destroyOperation(operation);
	service->canRecordOperation = 1;
	return 1;
}

int redoOperation(Service* service)
{
	if (stackIsEmpty(service->redoStack))return 0;
	Operation* operation = pop(service->redoStack);
	if (strcmp(getOperationType(operation), "add") == 0)
	{
		File* file = getFile(operation);
		addFile(service->repository, file);
	}
	else if (strcmp(getOperationType(operation), "delete") == 0)
	{
		File* file = getFile(operation);
		deleteFile(service->repository, file);
	}
	else if (strcmp(getOperationType(operation), "update") == 0)
	{
		
		File* newFile = getFile(operation);
		updateFile(service->repository, newFile);
	}
	destroyOperation(operation);
	service->canRecordOperation = 1;
	return 1;
}
