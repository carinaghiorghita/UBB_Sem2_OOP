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

	/*
	Adds a new victim to the CSV file.
	*/
	void addSavedVictim(const Victim& victim) override;

	//returns the size of the saved list
	int getSavedSize() override;
	//returns the saved list
	std::vector<Victim> getSavedVictims() override;
	//open the file
	void open() override;
};

