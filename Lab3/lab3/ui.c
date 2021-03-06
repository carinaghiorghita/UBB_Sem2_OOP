#include <stdio.h>
#include "ui.h"


UI* createUI(Service* service)
{
	UI* ui = (UI*)malloc(sizeof(UI));
	if (ui == NULL) return NULL;
	ui->service = service;
	return ui;
}

void destroyUI(UI* ui)
{
	destroyService(ui->service);
	free(ui);
}

void startUI(UI* ui)
{
	
	char command[200],*readWord,readStateOfDeterioration[200],readFileType[200],typeOfSorting[20];
	int numberOfWord,readArchiveCatalogueNumber,readYearOfCreation,commandExecuted,fileIndex;
	DynamicArray* dataInArchive;
	

	while (1)
	{
		gets(command, sizeof(command), stdin);
		if (strcmp(command, "exit") == 0) return 0;
		else
		{
			numberOfWord = 0;
			readWord = strtok(command, " ,");
			if (strcmp(readWord, "add") == 0)
			{
				readWord = strtok(NULL, " ,");
				while (readWord && numberOfWord < 4)
				{
					if (numberOfWord == 0)readArchiveCatalogueNumber = atoi(readWord);
					else if (numberOfWord == 1)strcpy(readStateOfDeterioration, readWord);
					else if (numberOfWord == 2)strcpy(readFileType, readWord);
					else readYearOfCreation = atoi(readWord);
					++numberOfWord;
					readWord = strtok(NULL, " ,");
				}
				commandExecuted = addFileService(ui->service, readArchiveCatalogueNumber, readStateOfDeterioration, readFileType, readYearOfCreation);
				if (commandExecuted == -1) printf("No!");
				//if (commandExecuted == -1) printf("You cannot add a file that already exists; try another catalogue number.");
			}
			else if (strcmp(readWord, "update") == 0)
			{
				readWord = strtok(NULL, " ,");
				while (readWord && numberOfWord < 4)
				{
					if (numberOfWord == 0)readArchiveCatalogueNumber = atoi(readWord);
					else if (numberOfWord == 1)strcpy(readStateOfDeterioration, readWord);
					else if (numberOfWord == 2)strcpy(readFileType, readWord);
					else readYearOfCreation = atoi(readWord);
					++numberOfWord;
					readWord = strtok(NULL, " ,");
				}
				commandExecuted = updateFileService(ui->service, readArchiveCatalogueNumber, readStateOfDeterioration, readFileType, readYearOfCreation);
				if (commandExecuted == -1) printf("No!");
				//if (commandExecuted == -1) printf("You cannot update a file that doesn't exist; either try another catalogue number or add this file before updating it.");
			}
			else if (strcmp(readWord, "delete") == 0)
			{
				readWord = strtok(NULL, " ,");
				readArchiveCatalogueNumber = atoi(readWord);
				commandExecuted = deleteFileService(ui->service, readArchiveCatalogueNumber);
				if (commandExecuted == -1) printf("No!");
				//if (commandExecuted == -1) printf("You cannot delete a file that doesn't exist; either try another catalogue number or add this file before deleting it.");
			}
			else if (strcmp(readWord, "list") == 0)
			{
				readWord = strtok(NULL, " ,");
				if (readWord == NULL)
				{
					dataInArchive = getAllService(ui->service);
					for (fileIndex = 0; fileIndex < dataInArchive->length; ++fileIndex)
						printf("%d %s %s %d\n", getCatalogueNumber(dataInArchive->elements[fileIndex]), getState(dataInArchive->elements[fileIndex]), getType(dataInArchive->elements[fileIndex]), getYear(dataInArchive->elements[fileIndex]));
				}
				else if(atoi(readWord)==NULL)
				{
					dataInArchive = getAllByTypeService(ui->service, readWord);
					for (fileIndex = 0; fileIndex < dataInArchive->length; ++fileIndex)
						printf("%d %s %s %d\n", getCatalogueNumber(dataInArchive->elements[fileIndex]), getState(dataInArchive->elements[fileIndex]), getType(dataInArchive->elements[fileIndex]), getYear(dataInArchive->elements[fileIndex]));
				}
				else
				{
					dataInArchive = getAllBeforeYearService(ui->service, atoi(readWord));
					//printf("Ascending or descending sorting by state of deterioration?");
					//scanf("%s", &typeOfSorting);
					//if (strcmp(typeOfSorting, "ascending") == 0)
					
					for (fileIndex = 0; fileIndex < dataInArchive->length; ++fileIndex)
						printf("%d %s %s %d\n", getCatalogueNumber(dataInArchive->elements[fileIndex]), getState(dataInArchive->elements[fileIndex]), getType(dataInArchive->elements[fileIndex]), getYear(dataInArchive->elements[fileIndex]));
				}
			}
			else if (strcmp(readWord, "undo") == 0)
			{
				undoOperation(ui->service);
			}
			else if (strcmp(readWord, "redo") == 0)
			{
				redoOperation(ui->service);
			}
			else printf("Invalid command");
		}
	}

}
