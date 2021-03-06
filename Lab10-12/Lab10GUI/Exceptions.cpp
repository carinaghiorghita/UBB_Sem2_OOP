#include "Exceptions.h"

ValidationLettersException::ValidationLettersException(const string& string)
{
	this->message = string;
}

const char* ValidationLettersException::what() const throw()
{
	return this->message.c_str();
}

ValidationDigitsException::ValidationDigitsException(const string& string)
{
	this->message = string;
}

const char* ValidationDigitsException::what() const throw()
{
	return this->message.c_str();
}

AddException::AddException(const string& string)
{
	this->message = string;
}

const char* AddException::what() const throw()
{
	return this->message.c_str();
}

DeleteException::DeleteException(const string& string)
{
	this->message = string;
}

const char* DeleteException::what() const throw()
{
	return this->message.c_str();
}

UpdateException::UpdateException(const string& string)
{
	this->message = string;
}

const char* UpdateException::what() const throw()
{
	return this->message.c_str();
}

EmptyStack::EmptyStack(const string& string)
{
	this->message = string;
}

const char* EmptyStack::what() const throw()
{
	return this->message.c_str();
}
