#include "Utilities.h"
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

vector<string> tokenize(const string& string, char delimiter)
{
	vector <std::string> result;
	stringstream stream(string);
	std::string token;
	while (getline(stream, token, delimiter))
		result.push_back(token);

	return result;
}

std::vector<Victim> loadCSVData(std::string filename)
{
	ifstream file(filename, std::ios::in);
	vector<Victim> dataset;
	if (!file.is_open())
	{
		std::ofstream outputFile(filename);
		return dataset;
	}
	Victim victim{};

	while (file >> victim)
		dataset.push_back(victim);
	file.close();

	return dataset;
}

void saveDataInCSV(std::string filename, std::vector<Victim> dataset)
{
	ofstream file(filename, std::ios::out);
	//if (!file.is_open())
		//return;
	for (auto iterator = dataset.begin(); iterator != dataset.end(); ++iterator)
		file << *iterator;
	file.close();
}
