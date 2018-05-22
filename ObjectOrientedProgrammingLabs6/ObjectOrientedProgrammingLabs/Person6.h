#pragma once
#include "CheckSymbol.h"
#include "Sex.h"
using namespace std;
namespace Lab6
{
	//TODO: Сейчас не имеет смысла создавать экземпляр класса персона, а у вас это возможно.
	//TODO: ?
	//С Д Е Л А Л
	class Person
	{
		public:
			Person() {};
			~Person();
			static const int arraySize = 255;
			//TODO: Нет такого конструктора (отличается сигнатура)
			//сделал
			Person(char name[arraySize], char surname[arraySize], unsigned int age, Sex sex);
			void SetName(char nameTemp[arraySize]);
			void SetSurname(char surnameTemp[arraySize]);
			void SetAge(unsigned int age);
			//TODO: Нет такого метода (отличается сигнатура)
			//сделал
			void SetSex(Sex sex);
			bool CheckFirstDigit(char tempname[arraySize]);

			virtual string GetDescription();
			char* GetName();
			char* GetSurname();
			int virtual GetAge() = 0;
			Sex GetSex();
			bool operator==(const Person& right);
		protected:
			Sex _sex;
			unsigned int _age;
			char _name[arraySize];
			char _surname[arraySize];
	};
}
