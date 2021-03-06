#include "UI.h"
#include <iostream>
#include <string>


#define StartWord 0
#define LengthOfWordMode 4
#define PositionOfMode 5
#define LengthOfWordExit 4
#define LengthOfWordAdd 3
#define NumberOfWordsRead 3
#define EmptySpaceBetweenWords 2
#define LengthOfWordDelete 6
#define LengthOfWordUpdate 6
#define LengthOfWordList 4
#define LengthOfWordNext 4
#define LengthOfWordSave 4
#define LengthOfWordMylist 6
#define FirstWord 0
#define SecondWord 1
#define ThirdWord 2

using namespace std;

void UI::start()
{
	char mode = NULL;

	while (1)
	{
		std::vector<Victim> arrayForAssistant = this->service.getAllVictimsInRepository();
		bool allDigitsInReadAge = false;
		std::string readCommand, readName, readPlaceOfOrigin, readAgePointer, readPhotograph;
		int readAge, numberOfWord, startPositionOfNextWord, endPositionOfNextWord, lengthOfWord;
		char* command; 
		std::getline(std::cin, readCommand);
		
		if (readCommand.substr(StartWord, LengthOfWordExit) == "exit")return;
		else if (readCommand.substr(StartWord, LengthOfWordMode) == "mode")
		{
			mode = readCommand[PositionOfMode];
		}
		else if (readCommand.substr(StartWord, LengthOfWordAdd) == "add")
		{
			if (mode == 'A')
			{
				try
				{
					readCommand[LengthOfWordAdd] = 'z';
					startPositionOfNextWord = LengthOfWordAdd + 1;
					for (numberOfWord = FirstWord; numberOfWord < NumberOfWordsRead; ++numberOfWord)
					{
						endPositionOfNextWord = readCommand.find(", ");
						lengthOfWord = endPositionOfNextWord - startPositionOfNextWord;
						if (numberOfWord == FirstWord)readName = readCommand.substr(startPositionOfNextWord, lengthOfWord);
						else if (numberOfWord == SecondWord)readPlaceOfOrigin = readCommand.substr(startPositionOfNextWord, lengthOfWord);
						else if (numberOfWord == ThirdWord)
						{
							std::string substringCommand = readCommand.substr(startPositionOfNextWord, lengthOfWord);
							this->service.getValidationDigits(substringCommand);
							readAge = std::stoi(substringCommand);
						}
						startPositionOfNextWord = endPositionOfNextWord + EmptySpaceBetweenWords;
						readCommand.replace(endPositionOfNextWord, EmptySpaceBetweenWords, "zz");
					}
					endPositionOfNextWord = readCommand.length();
					lengthOfWord = endPositionOfNextWord - startPositionOfNextWord;
					readPhotograph = readCommand.substr(startPositionOfNextWord, lengthOfWord);
					this->service.addVictimRepository(readName, readPlaceOfOrigin, readAge, readPhotograph);
				}
				catch (ValidationDigitsException error)
				{
					cout << error.what();
				}
				catch (ValidationLettersException error)
				{
					cout << error.what();
				}
				catch (AddException error)
				{
					cout << error.what();
				}
			}

		}
		else if (readCommand.substr(StartWord, LengthOfWordDelete) == "delete")
		{
			if (mode == 'A')
			{
				try
				{
					readCommand[LengthOfWordDelete] = 'z';
					startPositionOfNextWord = LengthOfWordDelete + 1;
					endPositionOfNextWord = readCommand.length();
					lengthOfWord = endPositionOfNextWord - startPositionOfNextWord;
					readName = readCommand.substr(startPositionOfNextWord, lengthOfWord);
					this->service.deleteVictimRepository(readName);
				}
				catch (ValidationLettersException error)
				{
					cout << error.what();
				}
				catch (DeleteException error)
				{
					cout << error.what();
				}
			}
		}
		else if (readCommand.substr(StartWord, LengthOfWordUpdate) == "update")
		{
			if (mode == 'A')
			{
				try
				{
					readCommand[LengthOfWordUpdate] = 'z';
					startPositionOfNextWord = LengthOfWordUpdate + 1;
					for (numberOfWord = FirstWord; numberOfWord < NumberOfWordsRead; ++numberOfWord)
					{
						endPositionOfNextWord = readCommand.find(", ");
						lengthOfWord = endPositionOfNextWord - startPositionOfNextWord;
						if (numberOfWord == FirstWord)readName = readCommand.substr(startPositionOfNextWord, lengthOfWord);
						else if (numberOfWord == SecondWord)readPlaceOfOrigin = readCommand.substr(startPositionOfNextWord, lengthOfWord);
						else if (numberOfWord == ThirdWord)
						{
							std::string substringCommand = readCommand.substr(startPositionOfNextWord, lengthOfWord);
							this->service.getValidationDigits(substringCommand);
							readAge = std::stoi(substringCommand);
							
						}
						startPositionOfNextWord = endPositionOfNextWord + EmptySpaceBetweenWords;
						readCommand.replace(endPositionOfNextWord, EmptySpaceBetweenWords, "zz");
					}
					endPositionOfNextWord = readCommand.length();
					lengthOfWord = endPositionOfNextWord - startPositionOfNextWord;
					readPhotograph = readCommand.substr(startPositionOfNextWord, lengthOfWord);
					this->service.updateVictimRepository(readName, readPlaceOfOrigin, readAge, readPhotograph);
				}
				catch (ValidationDigitsException error)
				{
					cout << error.what();
				}
				catch (ValidationLettersException error)
				{
					cout << error.what();
				}
				catch (UpdateException error)
				{
					cout << error.what();
				}
			}
		}
		else if (readCommand.substr(StartWord, LengthOfWordList) == "list")
		{
			
			if (mode == 'A')
			{
				if (readCommand.length() == LengthOfWordList)
				{
					std::vector<Victim> victimList = this->service.getAllVictimsInRepository();
					int victimIndex, victimLength = victimList.size();
					for (victimIndex = 0; victimIndex < victimLength; ++victimIndex)
					{
						Victim victim = victimList[victimIndex];
						cout << victim.getString() << '\n';
					}
				}
			}
			else if(mode=='B')
			{
				if (readCommand.length() != LengthOfWordList)
				{
					readCommand[LengthOfWordList] = 'z';
					startPositionOfNextWord = LengthOfWordList + 1;
					if (readCommand.find(", ") < readCommand.length())
					{
						endPositionOfNextWord = readCommand.find(", ");
						lengthOfWord = endPositionOfNextWord - startPositionOfNextWord;
						readPlaceOfOrigin = readCommand.substr(startPositionOfNextWord, lengthOfWord);
						startPositionOfNextWord = endPositionOfNextWord + EmptySpaceBetweenWords;
						readCommand.replace(endPositionOfNextWord, EmptySpaceBetweenWords, "zz");
						endPositionOfNextWord = readCommand.length();
						lengthOfWord = endPositionOfNextWord - startPositionOfNextWord;
						readAge = std::stoi(readCommand.substr(startPositionOfNextWord, lengthOfWord));
						std::vector<Victim> transferVictims{};
						std::vector<Victim> victimList = this->service.getAllVictimsInRepository();
						int victimIndex, victimLength = victimList.size();
						for (victimIndex = 0; victimIndex < victimLength; ++victimIndex)
						{
							if (victimList[victimIndex].getPlaceOfOrigin() == readPlaceOfOrigin && victimList[victimIndex].getAge() < readAge)
							{
								
								std::cout << victimList[victimIndex].getString() << ' ';
							}
						}
						
					}
				}
			}
		}
		else if (readCommand.substr(StartWord, LengthOfWordNext) == "next")
		{
			if (mode == 'B')
			{
				std::cout << this->service.getNext().getString();
			}
		}
		else if (readCommand.substr(StartWord, LengthOfWordSave) == "save")
		{
			if (mode == 'B')
			{
				readName = readCommand.substr(LengthOfWordSave + 1, readCommand.length());
				Victim victim = this->service.findVictimRepository(readName);
				this->service.addVictimSavedList(victim);
			}
		}
		else if (readCommand.substr(StartWord, LengthOfWordMylist) == "mylist")
		{
			if (mode == 'B')
			{
				/*int victimIndex, victimLength = this->service.getSizeSavedList();
				std::vector<Victim> toBeTransferred = this->service.getAllVictimsInSavedList();
				for (victimIndex = 0; victimIndex < victimLength; ++victimIndex)
				{
					std::cout << toBeTransferred[victimIndex].getString() << '\n';
				}*/
				this->service.open();
			}
		}
		else std::cout << "Invalid command";
	}
}