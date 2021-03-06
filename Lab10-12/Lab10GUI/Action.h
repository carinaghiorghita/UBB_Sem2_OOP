#pragma once
#include "Victim.h"
#include "Repository.h"
#include "savedRepository.h"
class Action
{
private:

public:
	Action() {};

	virtual void executeUndo() = 0;
	virtual void executeRedo() = 0;

};

