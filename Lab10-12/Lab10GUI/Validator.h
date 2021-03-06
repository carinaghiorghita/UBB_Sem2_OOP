#pragma once
#include <iostream>
#include "Exceptions.h"
class Validator
{
public:
	//constructor
	Validator() {};

	/*
	Checks if a given string contains only letters and the characters '-','.',' '
	Raises ValidationLettersException if the string is not valid (contains characters other than those specified)
	*/
	void validateStringAllLettersAndSpecialCharacters(std::string stringToValidate) const;

	/*
	Checks if a given string contains only digits
	Raises ValidationDigitsException if the string is not valid (contains characters other than those specified)
	*/
	void validateStringAllDigits(std::string stringToValidate) const;
	
};

