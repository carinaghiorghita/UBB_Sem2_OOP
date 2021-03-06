#pragma once
#include <iostream>

using namespace std;

class ValidationLettersException : public std::exception
{
private:
	string message;

public:
	ValidationLettersException(const string& string);

	const char* what() const throw() override;
};

class ValidationDigitsException : public std::exception
{
private:
	string message;

public:
	ValidationDigitsException(const string& string);

	const char* what() const throw() override;
};

class AddException : public std::exception
{
private:
	string message;

public:
	AddException(const string& string);

	const char* what() const throw() override;
};

class DeleteException : public std::exception
{
private:
	string message;

public:
	DeleteException(const string& string);

	const char* what() const throw() override;
};

class UpdateException : public std::exception
{
private:
	string message;

public:
	UpdateException(const string& string);

	const char* what() const throw() override;
};