#pragma once
#include "Adult.h"

namespace Lab6
{
	Adult::Adult(char name[Person::arraySize], char surname[Person::arraySize],
		int age, enum Sex sex, Person* marriage, char* workPlace)
	{
		SetName(name);
		SetSurname(surname);
		SetAge(age);          //TODO Дублирование вызывать конструктор базового класса 
		SetSex(sex);
		SetWorkPlace(workPlace);
		SetMarriage(marriage);
	};

	void Adult::SetAge(int age)
	{
		if (age >= 18)
		{
			Age = age;
		}
		else
		{
			cout << "It's an adult person, please enter 18+ age!" << endl;
		}
	}

	void Adult::SetMarriage(Person* marriage)
	{
		_marriage = marriage;
	}

	void Adult::SetWorkPlace(char* workPlace)
	{
		strcpy_s(_workPlace, arraySize, workPlace);
	}

	string Adult::GetDescription()
	{
		/*char* descriptionAdult = new char[150];
		*descriptionAdult = '\0';
		strcpy_s(descriptionAdult, 255, Name);
		strcpy_s(descriptionAdult, 255, Surname);
		strcpy_s(descriptionAdult, 255, "");
		char* descriptionAge = new char[20];
		_itoa_s(Age, descriptionAge, 20, 20);
		strcpy_s(descriptionAdult, 255, descriptionAge);
		if (_marriage == nullptr)
		{
			strcpy_s(descriptionAdult, 255, "Not married");
		}
		else
		{
			strcpy_s(descriptionAdult, 255, "Married on\n");
			strcpy_s(descriptionAdult, 255, _marriage->GetName());
			strcpy_s(descriptionAdult, 255, _marriage->GetSurname());
		}
		if (_workPlace == nullptr)
		{
			strcpy_s(descriptionAdult, 255, "Working in company named: \n");
			strcpy_s(descriptionAdult, 255, _workPlace);
		}
		return descriptionAdult;*/
		string descriptionAdult = Person::GetDescription();
		descriptionAdult += "\nWorks in = " + string(this->GetWorkPlace());
		if (_marriage != nullptr)
		{
			descriptionAdult += "\nMarried with " + string(this->GetMarriage()->GetName()) + " "
				+ string(this->GetMarriage()->GetSurname());
		}
		return descriptionAdult;
	}

	Person* Adult::GetMarriage()
	{
		return _marriage;
	}

	char* Adult::GetWorkPlace()
	{
		return _workPlace;
	}

	Adult::Adult()
	{

	}

	Adult::~Adult()
	{

	}

	Adult* Adult::GetRandomAdult()
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
			"Mikran", "Elesi", "50OM" //TODO: Какой позор, учите наизусть 50ohm Tech
			, "TUSUR",
			"TSU", "TPU", "Rostelekom", "Unemployeed"
		};
		const int initialsRand = 8;
		const int ageRand = 130;
		const int workPlacesRand = 7;
		int name = rand() % initialsRand;
		int surname = rand() % initialsRand;
		int tempAge = 18 + rand() % ageRand;
		char tempworkPlace[Person::arraySize];
		char tempName[Person::arraySize];
		char tempSurname[Person::arraySize];
		enum Sex tempSex = enum Sex(rand() % 2);
		Person* tempMarriage = PersonTools::MakeRandomPerson((enum Sex)!tempSex);
		strcpy_s(tempworkPlace, workPlaces[rand() % workPlacesRand]);
		if (rand() % 5)
		{
			strcpy_s(tempworkPlace, workPlaces[rand() % 9]);
		}//TODO: Используете int вместо перечисления
		if (tempSex == 0)
		{
			strcpy_s(tempName, femaleNames[rand() % initialsRand]);
			strcpy_s(tempSurname, femaleSurnames[rand() % initialsRand]);
		}
		else
		{
			strcpy_s(tempName, names[rand() % initialsRand]);
			strcpy_s(tempSurname, surnames[rand() % initialsRand]);
		}
		return new Adult(tempName, tempSurname, tempAge, tempSex, tempMarriage, tempworkPlace);
	}
}
