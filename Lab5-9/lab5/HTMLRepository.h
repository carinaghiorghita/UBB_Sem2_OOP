#pragma once
#include "savedRepository.h"
#include <iostream>

using namespace std;

class HTMLRepository : public savedRepository
{
private:
	std::string filename;
	int length;
public:
	//constructor
	HTMLRepository(string filename);

	/*
	Adds a new victim to the HTML file.
	*/
	void addSavedVictim(const Victim& victim) override;

	//returns the size of the saved list
	int getSavedSize() override;
	//returns the saved list
	std::vector<Victim> getSavedVictims() override;

	//load data from HTML file
	std::vector<Victim> loadHTMLData(std::string filename);

	//save data in HTML file
	void saveDataInHTML(std::string filename, std::vector<Victim> dataset);

	//open the file
	void open() override;
};


