#include "Service.h"

void Service::add(string name, string constel, int RA, int Dec, int diam)
{
	if (name == "" || diam < 0)throw exception("Invalid input");
	vector<Star> stars = repo->getAllS();
	for(auto it:stars)
		if(it.getName()==name)throw exception("Invalid input");
	Star s{ name, constel, RA, Dec, diam };
	this->repo->add(s);
	this->notify();
}

vector<Star> Service::getBySearch(string searchString)
{
	vector<Star> stars;
	if (searchString.size() == 0)
		return stars;
	for (auto i : this->repo->getAllS())
	{
		if (i.getName().find(searchString) != string::npos)
		{
			stars.push_back(i);
		}
	}
	return stars;
}

vector<Star> Service::getByConstel(string constel)
{
	vector<Star> stars;
	for (auto i : this->repo->getAllS())
	{
		if (i.getConstel()==constel)
		{
			stars.push_back(i);
		}
	}
	return stars;
}
