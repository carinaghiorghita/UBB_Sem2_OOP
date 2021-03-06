#include "Repository.h"

std::vector<Astronomer> Repository::loadDataA()
{
	ifstream file(filepathA, std::ios::in);
	vector<Astronomer> dataset;
	if (!file.is_open())
	{
		std::ofstream outputFile(filepathA);
		return dataset;
	}
	Astronomer d{};

	while (file >> d)
		dataset.push_back(d);
	file.close();
	//sort(dataset.begin(), dataset.end(), compare);

	return dataset;
}

std::vector<Star> Repository::loadDataS()
{
	ifstream file(filepathS, std::ios::in);
	vector<Star> dataset;
	if (!file.is_open())
	{
		std::ofstream outputFile(filepathS);
		return dataset;
	}
	Star d{};

	while (file >> d)
		dataset.push_back(d);
	file.close();
	sort(dataset.begin(), dataset.end(), compare);

	return dataset;
}

void Repository::saveData()
{
	
	sort(stars.begin(), stars.end(), compare);

	ofstream file(filepathS, std::ios::out);
	//if (!file.is_open())
		//return;
	for (auto iterator = stars.begin(); iterator != stars.end(); ++iterator)
		file << *iterator;
	file.close();

}

void Repository::add(Star s)
{
	stars.push_back(s);
	saveData();
}

bool compare(Star d1, Star d2)
{
	return d1.getConstel() < d2.getConstel();

}
