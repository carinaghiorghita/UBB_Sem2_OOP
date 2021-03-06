#include "ActionRemove.h"

void ActionRemove::executeUndo()
{
	this->repository.addVictim(this->removedVictim);
}

void ActionRemove::executeRedo()
{
	this->repository.deleteVictim(this->removedVictim);
}
