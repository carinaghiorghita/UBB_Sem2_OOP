#include "ActionUpdate.h"

void ActionUpdate::executeUndo()
{
	this->repository.updateVictim(this->formerVictim);
}

void ActionUpdate::executeRedo()
{
	this->repository.updateVictim(this->updatedVictim);
}
