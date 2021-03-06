#include "HTMLRepository.h"
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <Windows.h>
#include <shellapi.h>

#define firstLinesInHTMLToBeIgnored 7
#define numberOfAtributesInTable 6
#define startPositionOfAtribute 4
#define charactersAfterEndPositionOfAtribute 6
#define positionOfName 1
#define positionOfPlace 2
#define positionOfAge 3
#define positionOfPhotograph 4


HTMLRepository::HTMLRepository(string filename)
{
	this->filename = filename;
	this->length = 0;
}

void HTMLRepository::addSavedVictim(const Victim& victim)
{
	std::vector<Victim> victims{};
	victims = loadHTMLData(this->filename);
	victims.push_back(victim);
	this->length++;
	saveDataInHTML(this->filename, victims);
}

int HTMLRepository::getSavedSize()
{
	return this->length;
}

std::vector<Victim> HTMLRepository::getSavedVictims() 
{
	std::vector<Victim> victims{};
	victims = loadHTMLData(this->filename);
	return victims;
}

std::vector<Victim> HTMLRepository::loadHTMLData(std::string filename)
{
	ifstream file(filename, std::ios::in);
	vector<Victim> dataset;
	string line,name,placeOfOrigin,photograph;
	int i, j, age;
	if (!file.is_open())
	{
		std::ofstream outputFile(filename);
		return dataset;
	}
	for (i = 0; i < firstLinesInHTMLToBeIgnored; ++i)getline(file, line);
	for (i = 0; i < this->length; ++i)
	{
		for (j = 0; j < numberOfAtributesInTable; ++j)
		{
			getline(file, line);
			if (j == positionOfName)name = line.substr(startPositionOfAtribute, line.size() - charactersAfterEndPositionOfAtribute);
			else if (j == positionOfPlace)placeOfOrigin = line.substr(startPositionOfAtribute, line.size() - charactersAfterEndPositionOfAtribute);
			else if (j == positionOfAge)age = stoi(line.substr(startPositionOfAtribute, line.size() - charactersAfterEndPositionOfAtribute));
			else if (j == positionOfPhotograph)photograph = line.substr(startPositionOfAtribute, line.size() - charactersAfterEndPositionOfAtribute);
		}
		dataset.push_back(Victim{ name,placeOfOrigin,age,photograph });
	}
	file.close();
	return dataset;
}

void HTMLRepository::saveDataInHTML(std::string filename, std::vector<Victim> dataset)
{
	ofstream file(filename, std::ios::out);
	//if (!file.is_open())
		//return;
	file << "<!DOCTYPE html>\n<html>\n<head>\n<title>Saved Victims</title>\n</head>\n<body>\n<table border=\"1\">\n";
	for (auto iterator = dataset.begin(); iterator != dataset.end(); ++iterator)
	{
		Victim victim = *iterator;
		file << "<tr>\n<td>" << victim.getName() << "</td>\n<td>" << victim.getPlaceOfOrigin() << "</td>\n<td>" << to_string(victim.getAge()) << "</td>\n<td>" << victim.getPhotograph() << "</td>\n</tr>\n";
	}
	file << "</table>\n</body>\n</html>";
	file.close();
}

void HTMLRepository::open()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->filename.c_str(), NULL, SW_SHOWMAXIMIZED);
}
