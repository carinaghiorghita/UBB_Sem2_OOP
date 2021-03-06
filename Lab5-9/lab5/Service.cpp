#include "Service.h"
#include <iostream>

using namespace std;


Victim Service::findVictimRepository(const std::string name)
{
	return this->repository.findVictim(name);
}

void Service::addVictimRepository(const std::string& name, const std::string& placeOfOrigin, int age, const std::string& photograph)
{
	//this->validator.validateStringAllLettersAndSpecialCharacters(name);
	Victim victim{ name,placeOfOrigin,age,photograph };
	this->repository.addVictim(victim);
}

void Service::deleteVictimRepository(const std::string& name)
{
	//this->validator.validateStringAllLettersAndSpecialCharacters(name);
	Victim victim{ name,"",0,"" };
	this->repository.deleteVictim(victim);
}

void Service::updateVictimRepository(const std::string& name, const std::string& placeOfOrigin, int age, const std::string& photograph)
{
	//this->validator.validateStringAllLettersAndSpecialCharacters(name);
	Victim victim{ name,placeOfOrigin,age,photograph };
	this->repository.updateVictim(victim);
}

std::vector<Victim> Service::getAllVictimsInRepository() const
{
	return this->repository.getAllVictims();
}

void Service::addVictimSavedList(const Victim& victim)
{
	this->savedrepository.addSavedVictim(victim);
}

int Service::getSizeSavedList()
{
	return this->savedrepository.getSavedSize();
}

std::vector<Victim> Service::getAllVictimsInSavedList() const
{
	return this->savedrepository.getSavedVictims();
}

void Service::getValidationLettersAndSpecialCharacters(const std::string& stringToValidate)
{
	this->validator.validateStringAllLettersAndSpecialCharacters(stringToValidate);
}

void Service::getValidationDigits(const std::string& stringToValidate)
{
	this->validator.validateStringAllDigits(stringToValidate);
}

Victim Service::getNext()
{
	return this->repository.getNext();
}

void Service::open()
{
	this->savedrepository.open();
}
