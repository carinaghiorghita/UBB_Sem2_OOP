#pragma once
#include "Utilities.h"
#include "Victim.h"
#include "Exceptions.h"
class Repository
{
private:
	
public:
	//constructor
	Repository() {};

	//returns the victim with the given name
	virtual Victim findVictim( const std::string name)=0;
	//returns the position of the given victim
	virtual int getPosition( const Victim& victim)=0;

	/*
	Adds a new victim in the repository.
	*/
	virtual void addVictim( const Victim& victim)=0;
	/*
	Deletes a victim from the repository.
	*/
	virtual void deleteVictim( const Victim& victim)=0;
	/*
	Updates a victim from the repository.
	*/
	virtual void updateVictim( const Victim& victim)=0;

	virtual Victim getNext()=0;
	virtual std::vector<Victim> getAllVictims() const = 0;
	//get type of repo
	virtual string getType()=0;

};

class memoryRepository : public Repository
{
private:
	std::vector<Victim> victims;
	int positionOfVictim;
public:
	//constructor
	memoryRepository();

	//returns the victim with the given name
	Victim findVictim(const std::string name) override;
	//returns the position of the given victim
	int getPosition(const Victim& victim) override;

	/*
	Adds a new victim in the repository.
	Raises AddException if the victim could not be added (it already exists in the repository).
	*/
	void addVictim(const Victim& victim) override;

	/*
	Deletes a victim from the repository.
	Raises DeleteException if the victim could not be deleted (it doesn't exist in the repository)
	*/
	void deleteVictim(const Victim& victim) override;

	/*
	Updates a victim from the repository.
	Raises UpdateException if the victim could not be updated (it doesn't already exist in the repository)
	*/
	void updateVictim(const Victim& victim) override;
	
	//returns the next victim in the repository
	Victim getNext() override;
	std::vector<Victim> getAllVictims() const override;
	//get type of repo
	string getType() override;

};