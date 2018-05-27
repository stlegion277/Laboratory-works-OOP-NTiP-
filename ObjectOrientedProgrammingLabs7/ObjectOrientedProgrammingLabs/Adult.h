#pragma once
#include "PersonListItem6.h"
#include "Sex.h"

namespace Lab6
{
	class Adult : public PersonBase
	{
	public:
		~Adult();
		Adult(char name[PersonBase::arraySize], char surname[PersonBase::arraySize], int age,
			enum Sex sex, char* workPlace);
		void SetAge(unsigned int age);
		//void SetMarriage(Person* marriage);
		void SetWorkPlace(char* workPlace);
		PersonBase* _marriage = nullptr;
		virtual string GetDescription() override;
		//Person* GetMarriage();
		char* GetWorkPlace();
	private:
		
		char _workPlace[PersonBase::arraySize];
	
		// Унаследовано через Person
		virtual unsigned int GetAge() override;
	};

}
