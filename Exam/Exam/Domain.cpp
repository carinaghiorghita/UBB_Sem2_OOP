#include "Domain.h"

std::istream& operator>>(std::istream& stream, Astronomer& d)
{
	string line;
	getline(stream, line);

	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() == 2)
	{
		d.name = tokens[0];
		d.constel = tokens[1];

		return stream;
	}
	else
	{
		return stream;
	}
}

std::ostream& operator<<(std::ostream& stream, const Astronomer& d)
{
	stream << d.name << "," << d.constel << "\n";
	return stream;

}

std::istream& operator>>(std::istream& stream, Star& d)
{
	string line;
	getline(stream, line);

	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() == 5)
	{
		d.name = tokens[0];
		d.constel = tokens[1];
		d.RA = stoi(tokens[2]);
		d.Dec = stoi(tokens[3]);
		d.diam = stoi(tokens[4]);
		return stream;
	}
	else
	{
		return stream;
	}
}

std::ostream& operator<<(std::ostream& stream, const Star& d)
{
	stream << d.name << "," << d.constel <<","<<d.RA<<","<<d.Dec<<","<<d.diam<<"\n";
	return stream;
}

vector<string> tokenize(const string& string, char delimiter)
{
	vector <std::string> result;
	stringstream stream(string);
	std::string token;
	while (getline(stream, token, delimiter))
		result.push_back(token);

	return result;
}

//string Astronomer::toString()
//{
//	return string();
//}
