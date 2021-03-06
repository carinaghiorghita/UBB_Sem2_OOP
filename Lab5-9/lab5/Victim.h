#pragma once
#include <iostream>
#include <vector>
class Victim
{
private:
	std::string name;
	std::string placeOfOrigin;
	int age;
	std::string photograph;
public:
	//default constructor
	Victim();

	//constructor with parameters
	Victim(const std::string& name, const std::string& placeOfOrigin, int age, const std::string& photograph);

	//getters
	//returns the name of the victim
	std::string getName() const { return name; }; 
	//returns the place of origin of the victim
	std::string getPlaceOfOrigin() const { return placeOfOrigin; }; 
	//returns the age of the victim
	int getAge() const { return age; }; 
	//returns the photograph of the victim
	std::string getPhotograph() const { return photograph; }; 
	//returns a string to be printed in the form "Name: PlaceOfOrigin, age AgeOfVictim Photograph"
	std::string getString();

	bool operator==(const Victim& victim);
	
	friend std::istream& operator>>(std::istream& stream, Victim& victim);
	friend std::ostream& operator<<(std::ostream& stream, const Victim& victim);

};