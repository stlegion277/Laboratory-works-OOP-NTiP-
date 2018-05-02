#pragma once
#include "CheckSymbol.h"
#include "Sex.h"
using namespace std;
namespace Lab6
{
	//TODO: Сейчас не имеет смысла создавать экземпляр класса персона, а у вас это возможно.
	class Person
	{
		public:
			Person() {}; //TODO Переделать (полностью согласен!)

			~Person();
			static const int arraySize = 255;
			Person(char Name[arraySize], char Surname[arraySize], int Age, Sex Sex);
			void SetName(char nameTemp[arraySize]);
			void SetSurname(char surnameTemp[arraySize]);
			void SetAge(int age);
			void SetSex(Sex Sex);

			virtual string GetDescription();
			char* GetName();
			char* GetSurname();
			int GetAge();
			Sex GetSex();
			bool operator==(const Person& right);
		protected:
			Sex Sex;
			int Age;
			char Name[arraySize];
			char Surname[arraySize];
	};
}
