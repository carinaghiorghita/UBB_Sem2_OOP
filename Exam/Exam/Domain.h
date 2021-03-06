#pragma once
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

class Astronomer
{
private:
	string name, constel;
public:
	Astronomer() {}
	Astronomer(string name, string constel):name{name},constel{constel}{}
	
	string getName() { return name; }
	string getConstel() { return constel; }

	//string toString();
	friend std::istream& operator>>(std::istream& stream, Astronomer& d);
	friend std::ostream& operator<<(std::ostream& stream, const Astronomer& d);

};

class Star
{
private:
	string name, constel;
	int RA, Dec, diam;
public:
	Star() {}
	Star(string name, string constel, int RA, int Dec, int diam) :name{ name }, constel{ constel }, RA{ RA }, Dec{ Dec }, diam{ diam } {}

	string getName() { return name; }
	string getConstel() { return constel; }
	int getRA() { return RA; }
	int getDec() { return Dec; }
	int getDiam() { return diam; }

	//string toString();
	friend std::istream& operator>>(std::istream& stream, Star& d);
	friend std::ostream& operator<<(std::ostream& stream, const Star& d);

};

vector<string> tokenize(const string& string, char delimiter);
