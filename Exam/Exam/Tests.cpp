#include "Tests.h"

void addStarService_ValidInput_AllGood()
{

	Repository repo{ "","" };
	Service serv{ &repo };

	try
	{
		serv.add("a", "a", 1, 2, 3);
		assert(true);
	}
	catch (...)
	{
		assert(false);
	}
};

void addStarService_InvalidInputForName_ThrowEx()
{

	Repository repo{ "","" };
	Service serv{ &repo };

	try
	{
		serv.add("", "a", 1, 2, 3);
		assert(false);
	}
	catch (...)
	{
		assert(true);
	}
};

void addStarService_InvalidInputForDiam_ThrowEx()
{

	Repository repo{ "","" };
	Service serv{ &repo };

	try
	{
		serv.add("a", "a", 1, 2, -20);
		assert(false);
	}
	catch (...)
	{
		assert(true);
	}
};