#pragma once
#include "PersonListItem6.h"
#include "Sex.h"

namespace Lab6
{
	class Adult : public PersonBase
	{//TODO: ����� c RSDN
		//������
		public:
			//TODO: ������ �����������.
			//�� ����� ��� ���� 7�� �������� �� �����
			Adult() {};
			~Adult();
			Adult(char name[PersonBase::arraySize], char surname[PersonBase::arraySize], int age,
				enum Sex sex, char* workPlace);
			void SetAge(unsigned int age);
			//TODO: ����� ��� �����?
			//������
			void SetWorkPlace(char* workPlace);
			PersonBase* _marriage = nullptr;
			virtual string GetDescription() override;
	//TODO: ����� ��� �����?
			//������
			char* GetWorkPlace();
		private:
			char _workPlace[PersonBase::arraySize];
			// ������������ ����� Person
			virtual unsigned int GetAge() override;
	};

}
