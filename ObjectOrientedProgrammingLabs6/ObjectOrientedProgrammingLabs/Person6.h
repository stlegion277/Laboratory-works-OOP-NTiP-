#pragma once
#include "CheckSymbol.h"
#include "Sex.h"
using namespace std;
namespace Lab6
{
	//TODO: ������ �� ����� ������ ��������� ��������� ������ �������, � � ��� ��� ��������.
	//TODO: ?
	class Person
	{
		public:
			Person() {};
			~Person();
			static const int arraySize = 255;
			//TODO: ��� ������ ������������ (���������� ���������)
			Person(char name[arraySize], char surname[arraySize], int age, Sex sex);
			void SetName(char nameTemp[arraySize]);
			void SetSurname(char surnameTemp[arraySize]);
			void SetAge(int age);
			//TODO: ��� ������ ������ (���������� ���������)
			void SetSex(Sex sex);

			virtual string GetDescription();
			char* GetName();
			char* GetSurname();
			int GetAge();
			Sex GetSex();
			bool operator==(const Person& right);
		protected:
			Sex _sex;
			int _age;
			char _name[arraySize];
			char _surname[arraySize];
	};
}
