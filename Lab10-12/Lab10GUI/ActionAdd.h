#pragma once
#include "Action.h"
class ActionAdd : public Action
{
private:
	Repository& repository;
	Victim addedVictim;
public:
	ActionAdd(Repository& repository, Victim victim) :repository{ repository }, addedVictim{ victim }{};

	void executeUndo() override;
	void executeRedo() override;

};

