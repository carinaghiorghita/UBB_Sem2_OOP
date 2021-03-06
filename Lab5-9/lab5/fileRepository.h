#pragma once
#include "Repository.h"

class fileRepository :public Repository
{
private:
	int positionOfVictim;
	std::string filename;

public:
	//costructor
	fileRepository(const std::string filename);

	//returns the victim with the given name
	Victim findVictim(const std::string name) override;
	//returns the position of the given victim
	int getPosition(const Victim& victim)override;

	/*
	Adds a new victim to the file.
	Raises AddException if the victim could not be added (it already exists).
	*/
	void addVictim(const Victim& victim)override;

	/*
	Deletes a victim from the file.
	Raises DeleteException if the victim could not be deleted (it doesn't exist in the file)
	*/
	void deleteVictim(const Victim& victim)override;

	/*
	Updates a victim from the file.
	Raises UpdateException if the victim could not be updated (it doesn't already exist in the file)
	*/
	void updateVictim(const Victim& victim)override;

	//returns the list of victims in the file
	std::vector<Victim> getAllVictims() const override;
	//returns the next victim in the file repository 
	Victim getNext()override;

};