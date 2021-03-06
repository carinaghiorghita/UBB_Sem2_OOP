#pragma once
#include "Repository.h"
#include "Observer.h"

class Service:public Subject
{
private:
	Repository* repo;
public:
	Service() {}
	Service(Repository* repo) :repo{ repo } {}
	vector<Star> getAllS() { return repo->getAllS(); }
	vector<Astronomer> getAllA() { return repo->getAllA(); }
	/*
	Adds a star with the given attributes to the repo.
	Throws: an exception given by the repo if the star already exists and/or its atributes are invalid (no name, negative diameter)

	*/
	void add(string name, string constel, int RA,int Dec,int diam);
	vector<Star> getBySearch(string searchString);
	vector<Star> getByConstel(string constel);
	~Service() {
		this->repo->saveData();
	}
	//this->notify() after add,remove etc - observer
};

