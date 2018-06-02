#pragma once
#include "PersonListItem6.h"
#include "Sex.h"

namespace Lab6
{
	class Adult : public PersonBase
	{//TODO: Косяк c RSDN
	public:
		//TODO: Пустой конструктор.
		Adult() {};
		~Adult();
		Adult(char name[PersonBase::arraySize], char surname[PersonBase::arraySize], int age,
			enum Sex sex, char* workPlace);
		void SetAge(unsigned int age);
		//TODO: Зачем это здесь?
		//void SetMarriage(Person* marriage);
		void SetWorkPlace(char* workPlace);
		PersonBase* _marriage = nullptr;
		virtual string GetDescription() override;
//TODO: Зачем это здесь?
		//Person* GetMarriage();
		char* GetWorkPlace();
	private:
		
		char _workPlace[PersonBase::arraySize];
	
		// Унаследовано через Person
		virtual unsigned int GetAge() override;
	};

}
