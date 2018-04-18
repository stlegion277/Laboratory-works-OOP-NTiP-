#pragma once
#include "CheckSymbol.h"
#include "PersonList.h"
#include "PersonTools.h"
#include "PersonLab5.h"

namespace Lab5
{
	Person* PersonTools::MakeRandomPerson()
		{
			const char* names[] =
			{
				"Mark", "Ben", "Bob", "Kurt", "Stewart" ,"John", "Frank" ,"Bryan","Kek"
			};
			const char* surnames[] =
			{
				"Rothwell", "Jenson", "White", "Shraider",
				"Cranston", "Gray", "Zimmer", "Clinton", "Cheburek"
			};
			const int initialsRand = 8;
			const int ageRand = 90;

			int name = rand() % initialsRand;
			int surname = rand() % initialsRand;
			int tempAge = rand() % ageRand;
			char tempName[Person::arraySize];
			char tempSurname[Person::arraySize];
			enum Sex tempSex;
			tempSex = Male;
			strcpy_s(tempName, names[rand() % initialsRand]);
			strcpy_s(tempSurname, surnames[rand() % initialsRand]);
			return new Person(tempName, tempSurname, tempAge, tempSex);
		}
}