#include "ActionSave.h"

void ActionSave::executeUndo()
{
	this->repository.deleteSavedVictim(savedVictim);
}

void ActionSave::executeRedo()
{
	this->repository.addSavedVictim(this->savedVictim);
}
