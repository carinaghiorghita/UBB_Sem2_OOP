#include "Victim.h"
#include "Utilities.h"
#include <string>
#include <iostream>

using namespace std;

Victim::Victim(): name(""), placeOfOrigin(""), age(0), photograph("") {}

Victim::Victim(const std::string& name, const std::string& placeOfOrigin, int age, const std::string& photograph)
{
	this->name = name;
	this->placeOfOrigin = placeOfOrigin;
	this->age = age;
	this->photograph = photograph;
}

std::string Victim::getString()
{
	return this->name + ": " + this->placeOfOrigin + ", age " + std::to_string(this->age) + ", " + this->photograph;
}

bool Victim::operator==(const Victim& victim)
{
	return this->name==victim.name;
}

std::istream& operator>>(std::istream& stream, Victim& victim)
{
	string line;
	getline(stream, line);

	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 4) 
		return stream;
	victim.name = tokens[0];
	victim.placeOfOrigin = tokens[1];
	victim.age = stoi(tokens[2]);
	victim.photograph = tokens[3];
	return stream;
}

std::ostream& operator<<(std::ostream& stream, const Victim& victim)
{
	stream << victim.name << "," << victim.placeOfOrigin << "," << victim.age << "," << victim.photograph << "\n";
	return stream;
}
