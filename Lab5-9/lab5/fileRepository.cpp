#include "fileRepository.h"
using namespace std;

fileRepository::fileRepository(const std::string filename)
{
	this->filename = filename;
	this->positionOfVictim = 0;

}

Victim fileRepository::findVictim(const std::string name)
{
	std::vector<Victim> victims{};
	victims = loadCSVData(this->filename);
	auto iterator = std::find_if(victims.begin(), victims.end(), [&name](const Victim& obj) {return obj.getName() == name; });
	if (iterator == victims.end())
		return Victim{};
	return *iterator;
}

int fileRepository::getPosition(const Victim& victim)
{
	std::vector<Victim> victims{};
	victims = loadCSVData(this->filename);
	Victim foundVictim = findVictim(victim.getName());
	if (foundVictim.getName() != "")
		return std::distance(victims.begin(), std::find(victims.begin(), victims.end(), foundVictim));
	return -1;
}

void fileRepository::addVictim(const Victim& victim)
{
	std::vector<Victim> victims{};
	victims = loadCSVData(this->filename);
	Victim foundVictim = findVictim(victim.getName());
	if (foundVictim.getName() != "") throw AddException{ "Could not add victim (it already exists)\n" };
	victims.push_back(victim);
	saveDataInCSV(this->filename, victims);
}

void fileRepository::deleteVictim(const Victim& victim)
{
	std::vector<Victim> victims{};
	victims = loadCSVData(this->filename);
	Victim foundVictim = findVictim(victim.getName());
	if (foundVictim.getName() == "") throw DeleteException{ "Could not delete victim (it doesn't exist)\n" };
	int position = this->getPosition(victim);
	victims.erase(victims.begin() + position);
	saveDataInCSV(this->filename, victims);
}

void fileRepository::updateVictim(const Victim& victim)
{
	std::vector<Victim> victims{};
	victims = loadCSVData(this->filename);
	Victim foundVictim = findVictim(victim.getName());
	if (foundVictim.getName() == "") throw UpdateException{ "Could not update victim (it doesn't exist)\n" };
	int position = this->getPosition(victim);
	victims.erase(victims.begin() + position);
	victims.insert(victims.begin() + position, victim);
	saveDataInCSV(this->filename, victims);
}

std::vector<Victim> fileRepository::getAllVictims() const
{
	std::vector<Victim> victims{};
	victims = loadCSVData(this->filename);
	return victims;
}

Victim fileRepository::getNext()
{
	std::vector<Victim> victims{};
	victims = loadCSVData(this->filename);
	if (this->positionOfVictim == victims.size())this->positionOfVictim = 0;
	return victims[this->positionOfVictim++];
}
/*
void fileRepository::addSavedVictim(const Victim& victim)
{
	this->savedVictims.push_back(victim);
}

int fileRepository::getSavedSize()
{
	return this->savedVictims.size();
}

std::vector<Victim> fileRepository::getSavedVictims() const
{
	return this->savedVictims;
}
*/