#pragma once
#include "Action.h"
class ActionRemove : public Action
{
private:
	Repository& repository;
	Victim removedVictim;
public:
	ActionRemove(Repository& repository, Victim victim) :repository{ repository }, removedVictim{ victim }{};

	void executeUndo() override;
	void executeRedo() override;

};

