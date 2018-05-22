#pragma once
#include "PersonListItem6.h"
#include "Sex.h"

namespace Lab6
{
	class Adult : public Person
	{
	public:
		~Adult();
		Adult(char name[Person::arraySize], char surname[Person::arraySize], int age,
			enum Sex sex, char* workPlace);
		void SetAge(int age);
		//void SetMarriage(Person* marriage);
		void SetWorkPlace(char* workPlace);
		Person* _marriage = nullptr;
		virtual string GetDescription() override;
		//Person* GetMarriage();
		char* GetWorkPlace();
	private:
		
		char _workPlace[Person::arraySize];
	
		// Унаследовано через Person
		virtual int GetAge() override;
	};

}
