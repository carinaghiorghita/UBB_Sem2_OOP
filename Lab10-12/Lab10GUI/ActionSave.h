#pragma once
#include "Action.h"
class ActionSave : public Action
{
private:
	savedRepository& repository;
	Victim savedVictim;
public:
	ActionSave(savedRepository& repository, Victim victim) :repository{ repository }, savedVictim{ victim }{};

	void executeUndo() override;
	void executeRedo() override;
};

