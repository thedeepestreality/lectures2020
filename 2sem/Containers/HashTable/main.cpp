#include <iostream>
#include "HashTable.h"

struct Band
{
	char name[64];
	int year;
	char genre[64];
	Band(char const* _name, int _year, char const* _genre)
	{
		strcpy_s(name, _name);
		year = _year;
		strcpy_s(genre, _genre);
	}
	Band() = default;

	bool operator==(const Band& right)
	{
		return strcmp(name, right.name) == 0;
	}

	bool operator!=(const Band& right)
	{
		return strcmp(name, right.name) != 0;
	}

	Band& operator=(const Band& right)
	{
		strcpy_s(name, right.name);
		strcpy_s(genre, right.genre);
		year = right.year;
		return *this;
	}
};

std::ostream& operator<<(std::ostream& out, Band const& band)
{
	return out << "{" << band.name << ", " << band.year << "} ";
}

char* keyStringFunc(char* str)
{
	return str;
}

int hashStringFunc(char* str)
{
	return str[0] - 97;
}

char* keyBandFunc(Band band)
{
	int strLength = strlen(band.name) + 1;
	char* strcp = new char[strLength];
	strcpy_s(strcp, strLength, band.name);
	return strcp;
}

int hashBandFunc(char* key)
{
	return key[0] - 97;
}

int main()
{
	HashTable<Band, char*> table(26, hashBandFunc, keyBandFunc);
	table.insert(Band("ariya", 1985, "heavy metal"));
	table.insert(Band("metallica", 1981, "trash metal"));
	table.insert(Band("megadeth", 1983, "trash metal"));
	table.insert(Band("slayer", 1981, "trash metal"));
	table.insert(Band("anthrax", 1981, "trash metal"));

	table.print();

	Band metallica("metallica", 0, "");
	Band result;
	std::cout << table.find(metallica, result) << std::endl;

	std::cout << result.name << std::endl;
	std::cout << result.year << std::endl;
	std::cout << result.genre << std::endl;

	return 0;
}