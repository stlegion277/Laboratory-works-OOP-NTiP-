#pragma once
#include "Person6.h"
#include "PersonTools6.h"
#include "PersonListItem6.h"
#include "Sex.h"

namespace Lab6
{
	class Adult : public Person
	{
	public:
		//TODO: Зачем пустой конструктор?
		//сделал
		~Adult();
		Adult(char name[Person::arraySize], char surname[Person::arraySize], int age,
			enum Sex sex, Person* marriage, char* workPlace);
		static Adult* GetRandomAdult();
		//char* Adult* GetDescription();

		void SetAge(int age);
		void SetMarriage(Person* marriage);
		void SetWorkPlace(char* workPlace);

		virtual string GetDescription() override;
		Person* GetMarriage();
		char* GetWorkPlace();
	private:
		Person* _marriage = nullptr;
		char _workPlace[Person::arraySize];
	};

}
