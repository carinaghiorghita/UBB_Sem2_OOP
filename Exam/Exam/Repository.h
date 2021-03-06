#pragma once
#include "Domain.h"
#include <algorithm>

class Repository
{
private:
	vector<Astronomer> astr;
	vector<Star> stars;

	string filepathA;
	string filepathS;
public:
	Repository(string filepathA, string filepathS) :filepathA{ filepathA }, filepathS{ filepathS } {astr = loadDataA(); stars = loadDataS(); }
	vector<Astronomer> getAllA() { return astr; }
	vector<Star> getAllS() { return stars; }
	std::vector<Astronomer> loadDataA();
	std::vector<Star> loadDataS();

	void saveData();
	/*
	Adds a star with the given attributes to the list of stars.
	Throws: an exception if the star already exists and/or its atributes are invalid (no name, negative diameter)
	*/
	void add(Star s);

	//loadData before each operation
	//saveData after each modifying operation: add, remove etc
};

bool compare(Star d1, Star d2);
