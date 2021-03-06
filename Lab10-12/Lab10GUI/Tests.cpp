/*
#include "Tests.h"
#include <assert.h>

void Test::getName_getVictimName_nameIsCorrect()
{
	Victim victim{ "Jane Doe", "Hertfordshire", 28, "jd42329.jpg" };
	assert(victim.getName() == "Jane Doe");
}

void Test::getPlaceOfOrigin_getVictimPlace_placeIsCorrect()
{
	Victim victim{ "Jane Doe", "Hertfordshire", 28, "jd42329.jpg" };
	assert(victim.getPlaceOfOrigin() == "Hertfordshire");
}

void Test::getAge_getVictimAge_ageIsCorrect()
{
	Victim victim{ "Jane Doe", "Hertfordshire", 28, "jd42329.jpg" };
	assert(victim.getAge() == 28);
}

void Test::getPhotograph_getVictimPhotograph_photographIsCorrect()
{
	Victim victim{ "Jane Doe", "Hertfordshire", 28, "jd42329.jpg" };
	assert(victim.getPhotograph() == "jd42329.jpg");
}

void Test::getString_getVictimString_stringIsCorrect()
{
	Victim victim{ "Jane Doe", "Hertfordshire", 28, "jd42329.jpg" };
	assert(victim.getString()=="Jane Doe: Hertfordshire, age 28 jd42329.jpg");
}

void Test::testVictims()
{
	this->getName_getVictimName_nameIsCorrect();
	this->getPlaceOfOrigin_getVictimPlace_placeIsCorrect();
	this->getAge_getVictimAge_ageIsCorrect();
	this->getPhotograph_getVictimPhotograph_photographIsCorrect();
	this->getString_getVictimString_stringIsCorrect();
}
comment start
void Test::addVictim_ValidInput_addedToList()
{
	Repository repository{};
	std::vector<Victim> victims;
	Victim victim{ "Jane Doe", "Hertfordshire", 28, "jd42329.jpg" };
	assert(repository.addVictim(victims,victim));
}

void Test::addVictim_InvalidInput_notAddedToList()
{
	Repository repository{};
	std::vector<Victim> victims;
	Victim victim{ "Jane Doe", "Hertfordshire", 28, "jd42329.jpg" };
	repository.addVictim(victims,victim);
	Victim newVictim{ "Jane Doe", "Hertfordshire", 28, "jd42329.jpg" };
	assert(!repository.addVictim(victims,newVictim));
}

void Test::deleteVictim_ValidInput_deletedFromList()
{
	Repository repository{};
	std::vector<Victim> victims;
	Victim victim{ "Jane Doe", "Hertfordshire", 28, "jd42329.jpg" };
	repository.addVictim(victims,victim);
	assert(repository.deleteVictim(victims,victim));
}

void Test::deleteVictim_InvalidInput_notDeletedFromList()
{
	Repository repository{};
	std::vector<Victim> victims;
	Victim victim{ "Jane Doe", "Hertfordshire", 28, "jd42329.jpg" };
	assert(!repository.deleteVictim(victims,victim));
}

void Test::updateVictim_ValidInput_updatedList()
{
	Repository repository{};
	std::vector<Victim> victims;
	Victim victim{ "Jane Doe", "Hertfordshire", 28, "jd42329.jpg" };
	repository.addVictim(victims,victim);
	Victim newVictim{ "Jane Doe", "unknown", 30, "jd429.jpg" };
	assert(repository.updateVictim(victims,newVictim));
}

void Test::updateVictim_InvalidInput_notUpdatedList()
{
	Repository repository{};
	std::vector<Victim> victims;
	Victim victim{ "Jane Doe", "Hertfordshire", 28, "jd42329.jpg" };
	assert(!repository.updateVictim(victims,victim));
}

void Test::findVictim_ValidInput_returnedVictim()
{
	Repository repository{};
	std::vector<Victim> victims;
	Victim victim{ "Jane Doe", "Hertfordshire", 28, "jd42329.jpg" };
	repository.addVictim(victims, victim);
	assert(repository.findVictim(victims, "Jane Doe") == victim);
}

void Test::findVictim_InvalidInput_returnedNone()
{
	Repository repository{};
	std::vector<Victim> victims;
	Victim nullVictim{};
	assert(repository.findVictim(victims, "Jane Doe") == nullVictim);
}

void Test::getPosition_ValidInput_returnedPosition()
{
	Repository repository{};
	std::vector<Victim> victims;
	Victim victim{ "Jane Doe", "Hertfordshire", 28, "jd42329.jpg" };
	repository.addVictim(victims, victim);
	assert(repository.getPosition(victims, victim) == 0);
}

void Test::getPosition_InvalidInput_returnedNone()
{
	Repository repository{};
	std::vector<Victim> victims;
	Victim victim{ "Jane Doe", "Hertfordshire", 28, "jd42329.jpg" };
	assert(repository.getPosition(victims, victim) == -1);
}

void Test::addSavedVictim_ValidInput_addedToSavedList()
{
	Repository repository{};
	Victim victim{ "Jane Doe", "Hertfordshire", 28, "jd42329.jpg" };
	assert(repository.addSavedVictim(victim));
}

void Test::getSavedSize_getSizeOfSavedList_sizeIsCorrect()
{
	Repository repository{};
	Victim victim{ "Jane Doe", "Hertfordshire", 28, "jd42329.jpg" };
	repository.addSavedVictim(victim);
	assert(repository.getSavedSize() == 1);
}

void Test::getSavedVictims_ValidInput_victimExists()
{
	Repository repository{};
	Victim victim{ "Jane Doe", "Hertfordshire", 28, "jd42329.jpg" };
	repository.addSavedVictim(victim);
	std::vector<Victim> saved = repository.getSavedVictims();
	assert(repository.findVictim(saved,victim.getName())==victim);
}

void Test::getSavedVictims_ValidInput_sizeIsCorrect()
{
	Repository repository{};
	Victim victim{ "Jane Doe", "Hertfordshire", 28, "jd42329.jpg" };
	repository.addSavedVictim(victim);
	assert(repository.getSavedSize() == 1);
}

void Test::getNext_ValidInput_returnedNext()
{
	Repository repository{};
	Victim victim{ "Jane Doe", "Hertfordshire", 28, "jd42329.jpg" };
	std::vector<Victim> victims;
	repository.addVictim(victims, victim);
	assert(repository.getNext(victims) == victim);
}

void Test::getNext_ValidInput_returnedFirst()
{
	Repository repository{};
	Victim victim{ "Jane Doe", "Hertfordshire", 28, "jd42329.jpg" };
	std::vector<Victim> victims;
	repository.addVictim(victims, victim);
	Victim nextVictim=repository.getNext(victims);
	assert(repository.getNext(victims) == victim);
}


void Test::testRepository()
{
	findVictim_ValidInput_returnedVictim();
	findVictim_InvalidInput_returnedNone();
	getPosition_ValidInput_returnedPosition();
	getPosition_InvalidInput_returnedNone();
	addVictim_ValidInput_addedToList();
	addVictim_InvalidInput_notAddedToList();
	deleteVictim_ValidInput_deletedFromList();
	deleteVictim_InvalidInput_notDeletedFromList();
	updateVictim_ValidInput_updatedList();
	updateVictim_InvalidInput_notUpdatedList();
	addSavedVictim_ValidInput_addedToSavedList();
	//addSavedVictim_InvalidInput_notAddedToSavedList();
	getSavedSize_getSizeOfSavedList_sizeIsCorrect();
	getSavedVictims_ValidInput_victimExists();
	getSavedVictims_ValidInput_sizeIsCorrect();
	getNext_ValidInput_returnedNext();
	getNext_ValidInput_returnedFirst();
}
comment end
void Test::findVictim_ValidInput_returnedVictimFromFile()
{
	fileRepository filerepository{ "test.txt" };
	Victim victim{ "Jane Doe", "Hertfordshire", 28, "jd42329.jpg" };
	filerepository.addVictim(victim);
	assert(filerepository.findVictim("Jane Doe") == victim);
}

void Test::findVictim_InvalidInput_returnedNoneFromFile()
{
	fileRepository filerepository{ "test.txt" };
	Victim nullVictim{};
	assert(filerepository.findVictim("Jim Doe") == nullVictim);
}

void Test::addVictim_ValidInput_addedToRepository()
{
	fileRepository filerepository{ "test.txt" };
	Victim victim{ "Jack Doe", "Hertfordshire", 28, "jd42329.jpg" };
	assert(filerepository.addVictim(victim));
}

void Test::addVictim_InvalidInput_notAddedToRepository()
{
	fileRepository filerepository{ "test.txt" };
	Victim victim{ "Jane Doe", "Hertfordshire", 28, "jd42329.jpg" };
	filerepository.addVictim(victim);
	Victim newVictim{ "Jane Doe", "Hertfordshire", 28, "jd42329.jpg" };
	assert(!filerepository.addVictim(newVictim));
}

void Test::deleteVictim_ValidInput_deletedFromRepository()
{
	fileRepository filerepository{ "test.txt" };
	Victim victim{ "Jane Doe", "Hertfordshire", 28, "jd42329.jpg" };
	filerepository.addVictim(victim);
	assert(filerepository.deleteVictim(victim));
}

void Test::deleteVictim_InvalidInput_notDeletedFromRepository()
{
	fileRepository filerepository{ "test.txt" };
	Victim victim{ "Jane Doe", "Hertfordshire", 28, "jd42329.jpg" };
	assert(!filerepository.deleteVictim(victim));
}

void Test::updateVictim_ValidInput_updatedRepository()
{
	fileRepository filerepository{ "test.txt" };
	Victim victim{ "Jane Doe", "Hertfordshire", 28, "jd42329.jpg" };
	filerepository.addVictim(victim);
	Victim newVictim{ "Jane Doe", "unknown", 30, "jd429.jpg" };
	assert(filerepository.updateVictim(newVictim));
}

void Test::updateVictim_InvalidInput_notUpdatedRepository()
{
	fileRepository filerepository{ "test.txt" };
	Victim newVictim{ "Mary Gold", "unknown", 30, "jd429.jpg" };
	assert(!filerepository.updateVictim(newVictim));
}

void Test::getAllVictims_ValidInput_victimExists()
{
	fileRepository filerepository{ "test.txt" };
	Victim victim{ "Jane Doe", "Hertfordshire", 28, "jd42329.jpg" };
	filerepository.addVictim(victim);
	std::vector<Victim> array = filerepository.getAllVictims();
	assert(filerepository.findVictim("Jane Doe")==victim);
}

void Test::getAllVictims_ValidInput_sizeIsCorrect()
{
	fileRepository filerepository{ "test.txt" };
	std::vector<Victim> array = filerepository.getAllVictims();
	assert(array.size()==2);
}

void Test::getPosition_ValidInput_corectPosition()
{
	fileRepository filerepository{ "test.txt" };
	Victim victim{ "Jane Doe", "Hertfordshire", 28, "jd42329.jpg" };
	assert(filerepository.getPosition(victim) == 1);
}

void Test::getNext_ValidInput_returnedNextFromFile()
{
	fileRepository filerepository{ "test.txt" };
	Victim victim{ "Jack Doe", "Hertfordshire", 28, "jd42329.jpg" };
	assert(filerepository.getNext() == victim);
}

void Test::testFileRepository()
{
	findVictim_InvalidInput_returnedNoneFromFile();
	findVictim_ValidInput_returnedVictimFromFile();
	addVictim_ValidInput_addedToRepository();
	addVictim_InvalidInput_notAddedToRepository();
	deleteVictim_ValidInput_deletedFromRepository();
	deleteVictim_InvalidInput_notDeletedFromRepository();
	updateVictim_ValidInput_updatedRepository();
	updateVictim_InvalidInput_notUpdatedRepository();
	getAllVictims_ValidInput_victimExists();
	getAllVictims_ValidInput_sizeIsCorrect();
	getPosition_ValidInput_corectPosition();
	getNext_ValidInput_returnedNextFromFile();
}

void Test::validateStringAllLettersAndSpecialCharacters_ValidInput_stringIsValidated()
{
	Validator validator{};
	assert(validator.validateStringAllLettersAndSpecialCharacters("abc.- "));
}

void Test::validateStringAllLettersAndSpecialCharacters_InvalidInput_stringIsNotValidated()
{
	Validator validator{};
	assert(!validator.validateStringAllLettersAndSpecialCharacters("abc.- 123"));
}

void Test::validateDigits_ValidInput_stringIsValidated()
{
	Validator validator{};
	assert(validator.validateStringAllDigits("123"));
}

void Test::validateDigits_InvalidInput_stringIsNotValidated()
{
	Validator validator{};
	assert(!validator.validateStringAllDigits("123abc"));
}

void Test::testValidator()
{
	validateStringAllLettersAndSpecialCharacters_ValidInput_stringIsValidated();
	validateStringAllLettersAndSpecialCharacters_InvalidInput_stringIsNotValidated();
	validateDigits_ValidInput_stringIsValidated();
	validateDigits_InvalidInput_stringIsNotValidated();
}

void Test::addVictimRepository_ValidInput_addedToService()
{
	fileRepository filerepository{ "test.txt" };
	Service service{filerepository};
	assert(service.addVictimRepository("Mary Doe", "Hertfordshire", 28, "jd42329.jpg"));
}

void Test::addVictimRepository_DuplicateInput_notAddedToService()
{
	fileRepository filerepository{ "test.txt" };
	Service service{ filerepository };
	service.addVictimRepository("Jane Doe", "Hertfordshire", 28, "jd42329.jpg");
	assert(!service.addVictimRepository("Jane Doe", "Hertfordshire", 28, "jd42329.jpg"));
}

void Test::addVictimRepository_InvalidPlace_notAddedToService()
{
	fileRepository filerepository{ "test.txt" };
	Service service{ filerepository };
	assert(!service.addVictimRepository("Jane Doe", "123", 28, "jd42329.jpg"));
}

void Test::deleteVictimRepository_ValidInput_deletedFromService()
{
	fileRepository filerepository{ "test.txt" };
	Service service{ filerepository };
	service.addVictimRepository("Jane Doe", "Hertfordshire", 28, "jd42329.jpg");
	assert(service.deleteVictimRepository("Jane Doe"));
}

void Test::deleteVictimRepository_InvalidInput_notDeletedFromService()
{
	fileRepository filerepository{ "test.txt" };
	Service service{ filerepository };
	assert(!service.deleteVictimRepository("Jane Doe"));
}

void Test::updateVictimRepository_ValidInput_updatedService()
{
	fileRepository filerepository{ "test.txt" };
	Service service{ filerepository };
	service.addVictimRepository("Jane Doe", "Hertfordshire", 28, "jd42329.jpg");
	assert(service.updateVictimRepository("Jane Doe", "unknown", 30, "jd429.jpg"));
}

void Test::updateVictimRepository_InvalidInput_notUpdatedService()
{
	fileRepository filerepository{ "test.txt" };
	Service service{ filerepository };
	assert(!service.updateVictimRepository("Peter Doe", "unknown", 30, "jd429.jpg"));
}

void Test::addVictimSavedList_ValidInput_addedToService()
{
	fileRepository filerepository{ "test.txt" };
	Service service{ filerepository };
	Victim victim{ "Jane Doe", "Hertfordshire", 28, "jd42329.jpg" };
	assert(service.addVictimSavedList(victim));
}

void Test::getSizeSavedList_getSizeOfSavedList_sizeIsCorrect()
{
	fileRepository filerepository{ "test.txt" };
	Service service{ filerepository };
	Victim victim{ "Jane Doe", "Hertfordshire", 28, "jd42329.jpg" };
	service.addVictimSavedList(victim);
	assert(service.getSizeSavedList() == 1);
}

void Test::findVictimRepository_ValidInput_returnedVictim()
{
	fileRepository filerepository{ "test.txt" };
	Service service{ filerepository };
	Victim victim{ "Jane Doe", "Hertfordshire", 28, "jd42329.jpg" };
	assert(service.findVictimRepository("Jane Doe")==victim);
}

void Test::getAllVictimsInRepository_ValidInput_sizeIsCorrect()
{
	fileRepository filerepository{ "test.txt" };
	Service service{ filerepository };
	std::vector<Victim> victims = service.getAllVictimsInRepository();
	assert(victims.size() == 3);
}

void Test::getAllVictimsInSavedList_ValidInput_sizeIsCorrect()
{
	fileRepository filerepository{ "test.txt" };
	Service service{ filerepository };
	std::vector<Victim> victims = service.getAllVictimsInSavedList();
	assert(victims.size() == 0);
}

void Test::getValidationLettersAndSpecialCharacters_ValidInput_stringValidated()
{
	fileRepository filerepository{ "test.txt" };
	Service service{ filerepository };
	assert(service.getValidationLettersAndSpecialCharacters("abc"));
}

void Test::getValidationDigits_ValidInput_stringValidated()
{
	fileRepository filerepository{ "test.txt" };
	Service service{ filerepository };
	assert(service.getValidationDigits("123"));
}

void Test::getNext_ValidInput_returnedNextInService()
{
	fileRepository filerepository{ "test.txt" };
	Service service{ filerepository };
	Victim victim{ "Jack Doe", "Hertfordshire", 28, "jd42329.jpg" };
	assert(service.getNext() == victim);
}


void Test::testService()
{
	addVictimRepository_ValidInput_addedToService();
	addVictimRepository_DuplicateInput_notAddedToService();
	addVictimRepository_InvalidPlace_notAddedToService();
	deleteVictimRepository_ValidInput_deletedFromService();
	deleteVictimRepository_InvalidInput_notDeletedFromService();
	updateVictimRepository_ValidInput_updatedService();
	updateVictimRepository_InvalidInput_notUpdatedService();
	addVictimSavedList_ValidInput_addedToService();
	//addVictimSavedList_DuplicateInput_notAddedToService();
	getSizeSavedList_getSizeOfSavedList_sizeIsCorrect();
	findVictimRepository_ValidInput_returnedVictim();
	getAllVictimsInRepository_ValidInput_sizeIsCorrect();
	getAllVictimsInSavedList_ValidInput_sizeIsCorrect();
	getValidationLettersAndSpecialCharacters_ValidInput_stringValidated();
	getValidationDigits_ValidInput_stringValidated();
	getNext_ValidInput_returnedNextInService();
}

void Test::allTests()
{
	this->testVictims();
	//this->testRepository();
	this->testFileRepository();
	this->testValidator();
	this->testService();
}
*/