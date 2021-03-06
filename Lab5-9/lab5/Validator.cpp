#include "Validator.h"

void Validator::validateStringAllLettersAndSpecialCharacters(std::string stringToValidate) const
{
	int charIndex;
	for (charIndex = 0; charIndex < stringToValidate.length(); ++charIndex)
		if (((int)(stringToValidate[charIndex]) < 65 || ((int)(stringToValidate[charIndex]) > 90 && (int)(stringToValidate[charIndex]) < 97) || (int)(stringToValidate[charIndex]) > 122) && stringToValidate[charIndex]!='-' && stringToValidate[charIndex] != '.' && stringToValidate[charIndex] != ' ')  
			throw ValidationDigitsException{ "Error validating letters\n" };
}

void Validator::validateStringAllDigits(std::string stringToValidate) const
{
	int charIndex;
	std::string digits = "0123456789";
	for (charIndex = 0; charIndex < stringToValidate.length(); ++charIndex)
		if (digits.find(stringToValidate.at(charIndex)) == std::string::npos) throw ValidationDigitsException{ "Error validating digits\n" };
}
