#pragma once
#include <string>
#include <vector>
#include "Victim.h"

/*
	Tokenizes a string.
	Input:	str - the string to be tokenized.
	delimiter - char - the delimiter used for tokenization
	Output: a vector of strings, containing the tokens
*/
std::vector<std::string> tokenize(const std::string& string, char delimiter);

// load data from CSV file
std::vector<Victim> loadCSVData(std::string filename);

//save data in CSV file
void saveDataInCSV(std::string filename, std::vector<Victim> dataset);

