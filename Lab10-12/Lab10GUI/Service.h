#pragma once
#include <memory>
#include "fileRepository.h"
#include "CSVRepository.h"
#include "HTMLRepository.h"
#include "Validator.h"
#include "ActionAdd.h"
#include "ActionRemove.h"
#include "ActionUpdate.h"
#include "ActionSave.h"

class Service
{
private:
	Repository& repository;
	savedRepository& savedrepository;
	Validator validator;
	vector<unique_ptr<Action>> undoStack;
	vector<unique_ptr<Action>> redoStack;
	vector<unique_ptr<ActionSave>> savedUndoStack;
	vector<unique_ptr<ActionSave>> savedRedoStack;

public:
	//constructor
	Service(Repository& repository, savedRepository& savedrepository) : repository{ repository }, savedrepository{savedrepository}{};
	//returns the victim with the given name
	Victim findVictimRepository(const std::string name);

	/*
	Adds a new victim in the repository given in the service.
	*/
	void addVictimRepository(const std::string& name, const std::string& placeOfOrigin, int age, const std::string& photograph);

	/*
	Deletes a victim from the repository given in the service.
	*/
	void deleteVictimRepository(const std::string& name);

	/*
	Updates a victim in the repository given in the service.
	*/
	void updateVictimRepository(const std::string& name, const std::string& placeOfOrigin, int age, const std::string& photograph);

	//returns the list of victims
	std::vector<Victim> getAllVictimsInRepository() const; 

	/*
	Adds a new victim in the saved list given in the service.
	Returns:
		- 1 if the victim was added
		- 0 if the victim could not be added (it already exists in the list)
	*/
	void addVictimSavedList(const Victim& victim);
	//returns the size of the saved list
	int getSizeSavedList();
	//returns the list of saved victims
	std::vector<Victim> getAllVictimsInSavedList() const; 

	/*
	Checks if a given string contains only letters and the characters '-','.',' '
	*/
	void getValidationLettersAndSpecialCharacters(const std::string& stringToValidate);
	/*
	Checks if a given string contains only digits
	*/
	void getValidationDigits(const std::string& stringToValidate);
	
	//returns the next victim in the file repository
	Victim getNext();

	//get type of repo
	string getType();
	//open the file
	void open();

	//undoes the last operation(s)
	void undo();
	//redoes the last operation(s)
	void redo();

	//undoes the last save
	void savedUndo();
	//redoes the last save
	void savedRedo();

};

