#include "ActionAdd.h"

void ActionAdd::executeUndo()
{
	this->repository.deleteVictim(this->addedVictim);
}

void ActionAdd::executeRedo()
{
	this->repository.addVictim(this->addedVictim);
}
