#include "savedRepository.h"

Victim memorySavedRepository::findSavedVictim(const std::string name)
{
	auto iterator = std::find_if(savedVictims.begin(), savedVictims.end(), [&name](const Victim& obj) {return obj.getName() == name; });
	if (iterator == savedVictims.end())
		return Victim{};
	return *iterator;
}

int memorySavedRepository::getSavedPosition(const Victim& victim)
{
	Victim foundVictim = findSavedVictim(victim.getName());
	if (foundVictim.getName() != "")
		return std::distance(savedVictims.begin(), std::find(savedVictims.begin(), savedVictims.end(), foundVictim));
	return -1;
}

void memorySavedRepository::addSavedVictim(const Victim& victim)
{
	this->savedVictims.push_back(victim);
}

void memorySavedRepository::deleteSavedVictim(const Victim& victim)
{
	Victim foundVictim = findSavedVictim(victim.getName());
	if (foundVictim.getName() == "") throw DeleteException{ "Could not delete victim (it doesn't exist)\n" };
	int position = this->getSavedPosition(victim);
	savedVictims.erase(savedVictims.begin() + position);

}

int memorySavedRepository::getSavedSize()
{
	return this->savedVictims.size();
}

std::vector<Victim> memorySavedRepository::getSavedVictims()
{
	return this->savedVictims;
}
