#include "CSVRepository.h"
#include <Windows.h>
#include <shellapi.h>

CSVRepository::CSVRepository(string filename)
{
	this->filename = filename;
}

void CSVRepository::addSavedVictim(const Victim& victim)
{
	std::vector<Victim> victims{};
	victims = loadCSVData(this->filename);
	victims.push_back(victim);
	saveDataInCSV(this->filename, victims);
}

int CSVRepository::getSavedSize()
{
	std::vector<Victim> victims{};
	victims = loadCSVData(this->filename); 
	return victims.size();
}

std::vector<Victim> CSVRepository::getSavedVictims() 
{
	std::vector<Victim> victims{};
	victims = loadCSVData(this->filename);
	return victims;
}

void CSVRepository::open()
{
	system(this->filename.c_str());
}
