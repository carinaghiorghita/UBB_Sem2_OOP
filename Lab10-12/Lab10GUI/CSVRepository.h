#pragma once
#include "savedRepository.h"
#include <iostream>

using namespace std;

class CSVRepository : public savedRepository
{
private:
	std::string filename;
public:
	//constructor
	CSVRepository(string filename);
	//returns the victim with the given name
	Victim findSavedVictim(const std::string name) override;
	//returns the position of the given victim
	int getSavedPosition(const Victim& victim) override;

	//Adds a new victim to the CSV file.
	void addSavedVictim(const Victim& victim) override;
	//Removes a victim from the CSV file.
	void deleteSavedVictim(const Victim& victim) override;

	//returns the size of the saved list
	int getSavedSize() override;
	//returns the saved list
	std::vector<Victim> getSavedVictims() override;
	//open the file
	void open() override;
};

