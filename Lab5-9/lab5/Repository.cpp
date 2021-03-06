#include "Repository.h"

memoryRepository::memoryRepository()
{

	this->positionOfVictim = 0;
}


Victim memoryRepository::findVictim(const std::string name)
{
	auto iterator = std::find_if(victims.begin(), victims.end(), [&name](const Victim& obj) {return obj.getName() == name; });
	if (iterator == victims.end())
		return Victim{};
	return *iterator;
}

int memoryRepository::getPosition(const Victim& victim)
{
	Victim foundVictim = findVictim(victim.getName());
	if (foundVictim.getName() != "")
		return std::distance(victims.begin(), std::find(victims.begin(), victims.end(), foundVictim));
	return -1;
}

void memoryRepository::addVictim(const Victim& victim)
{
	Victim foundVictim = findVictim(victim.getName());
	if (foundVictim.getName() != "") throw AddException{ "Could not add victim (it already exists)\n" };
	victims.push_back(victim);
}

void memoryRepository::deleteVictim(const Victim& victim)
{
	Victim foundVictim = findVictim(victim.getName());
	if (foundVictim.getName() == "") throw DeleteException{ "Could not delete victim (it doesn't exist)\n" };
	int position = this->getPosition(victim);
	victims.erase(victims.begin() + position);
}

void memoryRepository::updateVictim(const Victim& victim)
{
	Victim foundVictim = findVictim(victim.getName());
	if (foundVictim.getName() == "") throw UpdateException{ "Could not update victim (it doesn't exist)\n" };
	int position = this->getPosition(victim);
	victims.erase(victims.begin() + position);
	victims.insert(victims.begin() + position, victim);
}

Victim memoryRepository::getNext()
{

	if (this->positionOfVictim == victims.size())this->positionOfVictim = 0;
	return victims[this->positionOfVictim++];

}

std::vector<Victim> memoryRepository::getAllVictims() const
{
	return this->victims;
}
