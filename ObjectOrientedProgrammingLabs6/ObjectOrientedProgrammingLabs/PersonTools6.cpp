#pragma once
#include "CheckSymbol.h"
#include "PersonList6.h"
#include "PersonTools6.h"
#include "Person6.h"

namespace Lab6
{
	Person* PersonTools::MakeRandomPerson()
	{
		const char* femaleNames[] =
		{
			"Elisa", "Athena", "Anya", "Mariya",
			"Elena", "Skarlett", "Emma", "Alisa"
		};
		const char* femaleSurnames[] =
		{
			"Morozova", "Makarova", "Semenova", "Pakhomova",
			"Grigoryeva", "Avdeeva", "Guryeva", "Vikander"
		};
		const char* names[] =
		{
			"Mark", "Ben", "Bob", "Kurt",
			"Stewart" ,"John", "Frank" ,"Bryan","Kek"
		};
		const char* surnames[] =
		{
			"Rothwell", "Jenson", "White", "Shraider",
			"Cranston", "Gray", "Zimmer", "Clinton", "Cheburek"
		};
		const int initialsRand = 8;
		const int ageRand = 90;
		const int workPlacesRand = 7;
		int name = rand() % initialsRand;
		int surname = rand() % initialsRand;
		int tempAge = 18 + rand() % ageRand;
		char tempworkPlace[Person::arraySize];
		char tempName[Person::arraySize];
		char tempSurname[Person::arraySize];
		enum Sex tempSex = enum Sex(rand() % 2);
		if (tempSex)
		{
			strcpy_s(tempName, femaleNames[rand() % initialsRand]);
			strcpy_s(tempSurname, femaleSurnames[rand() % initialsRand]);
		}
		else
		{
			strcpy_s(tempName, names[rand() % initialsRand]);
			strcpy_s(tempSurname, surnames[rand() % initialsRand]);
		}
		return new Person(tempName, tempSurname, tempAge, tempSex);
	}

	Person * PersonTools::MakeRandomPerson(Sex tempSex)
	{
		const char* femaleNames[] =
		{
			"Elisa", "Athena", "Anya", "Mariya",
			"Elena", "Skarlett", "Emma", "Alisa"
		};
		const char* femaleSurnames[] =
		{
			"Morozova", "Makarova", "Semenova", "Pakhomova",
			"Grigoryeva", "Avdeeva", "Guryeva", "Vikander"
		};
		const char* names[] =
		{
			"Mark", "Ben", "Bob", "Kurt",
			"Stewart" ,"John", "Frank" ,"Bryan","Kek"
		};
		const char* surnames[] =
		{
			"Rothwell", "Jenson", "White", "Shraider",
			"Cranston", "Gray", "Zimmer", "Clinton", "Cheburek"
		};
		const int initialsRand = 8;
		const int ageRand = 90;
		const int workPlacesRand = 7;
		int name = rand() % initialsRand;
		int surname = rand() % initialsRand;
		int tempAge = 18 + rand() % ageRand;
		char tempworkPlace[Person::arraySize];
		char tempName[Person::arraySize];
		char tempSurname[Person::arraySize];
///		enum Sex tempSex = enum Sex(rand() % 2);
		if (tempSex)
		{
			strcpy_s(tempName, femaleNames[rand() % initialsRand]);
			strcpy_s(tempSurname, femaleSurnames[rand() % initialsRand]);
		}
		else
		{
			strcpy_s(tempName, names[rand() % initialsRand]);
			strcpy_s(tempSurname, surnames[rand() % initialsRand]);
		}
		return new Person(tempName, tempSurname, tempAge, tempSex);
	}
}