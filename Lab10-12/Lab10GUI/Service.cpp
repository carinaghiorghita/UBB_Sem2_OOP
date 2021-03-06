#include "Service.h"
#include <iostream>

using namespace std;


Victim Service::findVictimRepository(const std::string name)
{
	return this->repository.findVictim(name);
}

void Service::addVictimRepository(const std::string& name, const std::string& placeOfOrigin, int age, const std::string& photograph)
{
	//this->validator.validateStringAllLettersAndSpecialCharacters(name);
	Victim victim{ name,placeOfOrigin,age,photograph };
	this->repository.addVictim(victim);

	unique_ptr<Action> addAction = make_unique<ActionAdd>(this->repository, victim);
	this->undoStack.push_back(move(addAction));
}

void Service::deleteVictimRepository(const std::string& name)
{
	//this->validator.validateStringAllLettersAndSpecialCharacters(name);
	Victim victim{ name,"",0,"" };
	this->repository.deleteVictim(victim);

	unique_ptr<Action> removeAction = make_unique<ActionRemove>(this->repository, victim);
	this->undoStack.push_back(move(removeAction));

}

void Service::updateVictimRepository(const std::string& name, const std::string& placeOfOrigin, int age, const std::string& photograph)
{
	//this->validator.validateStringAllLettersAndSpecialCharacters(name);
	Victim victim{ name,placeOfOrigin,age,photograph };
	Victim formerVictim = this->findVictimRepository(name);
	this->repository.updateVictim(victim);

	unique_ptr<Action> updateAction = make_unique<ActionUpdate>(this->repository, victim,formerVictim);
	this->undoStack.push_back(move(updateAction));

}

std::vector<Victim> Service::getAllVictimsInRepository() const
{
	return this->repository.getAllVictims();
}

void Service::addVictimSavedList(const Victim& victim)
{
	this->savedrepository.addSavedVictim(victim);

	unique_ptr<ActionSave> saveAction = make_unique<ActionSave>(this->savedrepository, victim);
	this->savedUndoStack.push_back(move(saveAction));

}

int Service::getSizeSavedList()
{
	return this->savedrepository.getSavedSize();
}

std::vector<Victim> Service::getAllVictimsInSavedList() const
{
	return this->savedrepository.getSavedVictims();
}

void Service::getValidationLettersAndSpecialCharacters(const std::string& stringToValidate)
{
	this->validator.validateStringAllLettersAndSpecialCharacters(stringToValidate);
}

void Service::getValidationDigits(const std::string& stringToValidate)
{
	this->validator.validateStringAllDigits(stringToValidate);
}

Victim Service::getNext()
{
	return this->repository.getNext();
}

string Service::getType()
{
	return this->repository.getType();
}

void Service::open()
{
	this->savedrepository.open();
}

void Service::undo()
{
	if (this->undoStack.size() != 0)
	{
		this->undoStack[this->undoStack.size() - 1]->executeUndo();
		this->redoStack.push_back(move(this->undoStack[this->undoStack.size() - 1]));
		this->undoStack.pop_back();
	}
	else
		throw EmptyStack{ "No more undos!" };
}

void Service::redo()
{
	if (this->redoStack.size() != 0)
	{
		this->redoStack[this->redoStack.size() - 1]->executeRedo();
		this->undoStack.push_back(move(this->redoStack[this->redoStack.size() - 1]));
		this->redoStack.pop_back();
	}
	else
		throw EmptyStack{ "No more redos!" };
}

void Service::savedUndo()
{
	if (this->savedUndoStack.size() != 0)
	{
		this->savedUndoStack[this->savedUndoStack.size() - 1]->executeUndo();
		this->savedRedoStack.push_back(move(this->savedUndoStack[this->savedUndoStack.size() - 1]));
		this->savedUndoStack.pop_back();
	}
	else
		throw EmptyStack{ "No more undos!" };
}

void Service::savedRedo()
{
	if (this->savedRedoStack.size() != 0)
	{
		this->savedRedoStack[this->savedRedoStack.size() - 1]->executeRedo();
		this->savedUndoStack.push_back(move(this->savedRedoStack[this->savedRedoStack.size() - 1]));
		this->savedRedoStack.pop_back();
	}
	else
		throw EmptyStack{ "No more redos!" };
}
