#pragma once
#include "CheckSymbol.h"
#include "Sex.h"
using namespace std;
namespace Lab6
{
	//TODO: ������ �� ����� ������ ��������� ��������� ������ �������, � � ��� ��� ��������.
	//TODO: ?
	//� � � � � �
	class Person
	{
		public:
			Person() {};
			~Person();
			static const int arraySize = 255;
			//TODO: ��� ������ ������������ (���������� ���������)
			//������
			Person(char name[arraySize], char surname[arraySize], unsigned int age, Sex sex);
			void SetName(char nameTemp[arraySize]);
			void SetSurname(char surnameTemp[arraySize]);
			void SetAge(unsigned int age);
			//TODO: ��� ������ ������ (���������� ���������)
			//������
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
