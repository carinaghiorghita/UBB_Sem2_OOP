#pragma once
#include "Action.h"
class ActionUpdate : public Action
{
private:
	Repository& repository;
	Victim updatedVictim;
	Victim formerVictim;

public:
	ActionUpdate(Repository& repository, Victim victim, Victim formerVictim) :repository{ repository }, updatedVictim{ victim }, formerVictim{ formerVictim }{};

	void executeUndo() override;
	void executeRedo() override;

};

