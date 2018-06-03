#pragma once
#include "PersonListItem6.h"
#include "Sex.h"

namespace Lab6
{
	class Adult : public PersonBase
	{//TODO: Косяк c RSDN
		//сделал
		public:
			//TODO: Пустой конструктор.
			//он нужен без него 7ая работать не будет
			Adult() {};
			~Adult();
			Adult(char name[PersonBase::arraySize], char surname[PersonBase::arraySize], int age,
				enum Sex sex, char* workPlace);
			void SetAge(unsigned int age);
			//TODO: Зачем это здесь?
			//сделал
			void SetWorkPlace(char* workPlace);
			PersonBase* _marriage = nullptr;
			virtual string GetDescription() override;
	//TODO: Зачем это здесь?
			//сделал
			char* GetWorkPlace();
		private:
			char _workPlace[PersonBase::arraySize];
			// Унаследовано через Person
			virtual unsigned int GetAge() override;
	};

}
