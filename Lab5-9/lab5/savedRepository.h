#pragma once
#include "Victim.h"
#include "Exceptions.h"
#include "Utilities.h"
class savedRepository
{
private:
	
public:
	//constructor
	savedRepository() {};
	/*
	Adds a new victim in the saved list.
	*/
	virtual void addSavedVictim(const Victim& victim) = 0;

	//returns the size of the saved list
	virtual int getSavedSize() = 0;
	//returns the saved list
	virtual std::vector<Victim> getSavedVictims() = 0;
	
	//open the file
	virtual void open() = 0;
};

