#include "CSVRepository.h"
#include <Windows.h>
#include <shellapi.h>

CSVRepository::CSVRepository(string filename)
{
	this->filename = filename;
}

Victim CSVRepository::findSavedVictim(const std::string name)
{
	std::vector<Victim> victims{};
	victims = loadCSVData(this->filename);
	auto iterator = std::find_if(victims.begin(), victims.end(), [&name](const Victim& obj) {return obj.getName() == name; });
	if (iterator == victims.end())
		return Victim{};
	return *iterator;
}

int CSVRepository::getSavedPosition(const Victim& victim)
{
	std::vector<Victim> victims{};
	victims = loadCSVData(this->filename);
	Victim foundVictim = findSavedVictim(victim.getName());
	if (foundVictim.getName() != "")
		return std::distance(victims.begin(), std::find(victims.begin(), victims.end(), foundVictim));
	return -1;
}

void CSVRepository::addSavedVictim(const Victim& victim)
{
	std::vector<Victim> victims{};
	victims = loadCSVData(this->filename);
	victims.push_back(victim);
	saveDataInCSV(this->filename, victims);
}

void CSVRepository::deleteSavedVictim(const Victim& victim)
{
	std::vector<Victim> victims{};
	victims = loadCSVData(this->filename);
	Victim foundVictim = findSavedVictim(victim.getName());
	if (foundVictim.getName() == "") throw DeleteException{ "Could not delete victim (it doesn't exist)\n" };
	int position = this->getSavedPosition(victim);
	victims.erase(victims.begin() + position);
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
