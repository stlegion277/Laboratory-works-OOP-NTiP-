#pragma once
#include "CheckSymbol.h"
#include "PersonTools6.h"

namespace Lab6
{
	Child* PersonTools::MakeRandomChild()
	{
		const char* femaleChildNames[] =
		{
			"Arseniya", "Lidiya", "Anya", "Mariya",
			"Elena", "Louisa", "Sabina", "Viktoriya"
		};
		const char* femaleChildSurnames[] =
		{
			"Morozova", "Makarova", "Semenova", "Pakhomova",
			"Grigoryeva", "Avdeeva", "Guryeva", "Vikander"
		};
		const char* maleChildNames[] =
		{
			"Vladimir", "Vyacheslav", "Aleksey", "Aleksandr",
			"Svyatoslav" ,"Vsevolod", "Maksim" ,"Leonid","Kek"
		};
		const char* maleChildSurnames[] =
		{
			"Rothwell", "Jenson", "White", "Shraider",
			"Cranston", "Gray", "Zimmer", "Clinton", "Cheburek"
		};
		const char* childSchools[] =
		{
			"¹5 school-lyceum", "¹66 school", "¹2 school for gifted children "
		};
		const int initialsRand = 8;
		const int ageRand = 90;
		int tempAge = rand() % ageRand;
		PersonBase* tempMother;
		PersonBase* tempFather;
		char tempChildSchools[PersonBase::arraySize];
		char tempName[PersonBase::arraySize];
		char tempSurname[PersonBase::arraySize];
		enum Sex tempSex = enum Sex(rand() % 2);
		if (rand() % 3)
		{
			strcpy_s(tempChildSchools, childSchools[rand() % 3]);
		}
		if (rand() % 2)
		{ 
			tempMother = PersonTools::MakeRandomAdult((enum Sex)Female); //getrandomadult
		}
		else
		{
			tempMother = nullptr;
		}
		if (rand() % 2)
		{
			tempFather = PersonTools::MakeRandomAdult((enum Sex)Male);//getrandomadult
		}
		else
		{
			tempFather = nullptr;
		}
		if (tempSex == Female)
		{
			strcpy_s(tempName, femaleChildNames[rand() % initialsRand]);
			strcpy_s(tempSurname, femaleChildSurnames[rand() % initialsRand]);
		}
		else
		{
			strcpy_s(tempName, maleChildNames[rand() % initialsRand]);
			strcpy_s(tempSurname, maleChildSurnames[rand() % initialsRand]);
		}
		return new Child(tempName, tempSurname, tempAge, tempSex, tempMother, tempFather, tempChildSchools);
	}

	Adult * PersonTools::MakeRandomAdult()
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
		const char* workPlaces[] =
		{
			"Mikran", "Elesi", "50ohm Tech"
			, "TUSUR",
			"TSU", "TPU", "Rostelekom", "Unemployeed"
		};
		const int initialsRand = 8;
		const int ageRand = 130;
		const int workPlacesRand = 7;
		int adultCounter = 0;
		bool adultFlag = true;
		int name = rand() % initialsRand;
		int surname = rand() % initialsRand;
		int tempAge = 18 + rand() % ageRand;
		char tempworkPlace[PersonBase::arraySize];
		char tempName[PersonBase::arraySize];
		char tempSurname[PersonBase::arraySize];
		Sex tempSex = Sex(rand() % 2);
		strcpy_s(tempworkPlace, workPlaces[rand() % workPlacesRand]);
		if (rand() % 5)
		{
			strcpy_s(tempworkPlace, workPlaces[rand() % 9]);
		}
		if (tempSex == Female)
		{
			strcpy_s(tempName, femaleNames[rand() % initialsRand]);
			strcpy_s(tempSurname, femaleSurnames[rand() % initialsRand]);
		}
		else
		{
			strcpy_s(tempName, names[rand() % initialsRand]);
			strcpy_s(tempSurname, surnames[rand() % initialsRand]);
		}
		return new Adult(tempName, tempSurname, tempAge, tempSex, tempworkPlace);
	}
	
	Adult* PersonTools::MakeRandomAdult(Sex sexTemp)
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
		const char* workPlaces[] =
		{
			"Mikran", "Elesi", "50ohm Tech" 
			, "TUSUR",
			"TSU", "TPU", "Rostelekom", "Unemployeed"
		};
		const int initialsRand = 8;
		const int ageRand = 130;
		const int workPlacesRand = 8;
		int adultCounter = 2;
		int tempAge = 18 + rand() % ageRand;
		char tempworkPlace[PersonBase::arraySize];
		char tempName[PersonBase::arraySize];
		char tempSurname[PersonBase::arraySize];
		Sex tempSex = Sex(rand() % 2);
		strcpy_s(tempworkPlace, workPlaces[rand() % workPlacesRand]);
		if (tempSex == Female)
		{
			strcpy_s(tempName, femaleNames[rand() % initialsRand]);
			strcpy_s(tempSurname, femaleSurnames[rand() % initialsRand]);
		}
		else
		{
			strcpy_s(tempName, names[rand() % initialsRand]);
			strcpy_s(tempSurname, surnames[rand() % initialsRand]);
		}
		return new Adult(tempName, tempSurname, tempAge, tempSex, tempworkPlace);
	}

	Adult* PersonTools::MakingMarriage()
	{
		Adult* adult1 = MakeRandomAdult((enum Sex)!Male);
		Adult* adult2 = MakeRandomAdult((enum Sex)!Female);
		adult1->_marriage = adult2;
		adult2->_marriage = adult1;
		return adult1;
	}
}