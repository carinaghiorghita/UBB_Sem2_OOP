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
	//returns the victim with the given name
	virtual Victim findSavedVictim(const std::string name) =0;
	//returns the position of the given victim
	virtual int getSavedPosition(const Victim& victim) =0;

	//Adds a new victim in the saved list.
	virtual void addSavedVictim(const Victim& victim) = 0;
	//Removes a victim from the saved list.
	virtual void deleteSavedVictim(const Victim& victim) = 0;

	//returns the size of the saved list
	virtual int getSavedSize() = 0;
	//returns the saved list
	virtual std::vector<Victim> getSavedVictims() = 0;
	
	//open the file
	virtual void open() = 0;
};

class memorySavedRepository : public savedRepository
{
private:
	std::vector<Victim> savedVictims;
public:
	//constructor
	memorySavedRepository() {};
	//returns the victim with the given name
	Victim findSavedVictim(const std::string name) override;
	//returns the position of the given victim
	int getSavedPosition(const Victim& victim) override;

	//Adds a new victim in the saved list.
	void addSavedVictim(const Victim& victim) override;
	//Removes a victim from the saved list.
	void deleteSavedVictim(const Victim& victim) override;

	//returns the size of the saved list
	int getSavedSize() override;

	//returns the saved list
	std::vector<Victim> getSavedVictims() override;

	void open() override {};

};
