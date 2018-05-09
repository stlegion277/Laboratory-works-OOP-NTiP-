#pragma once
#include "CheckSymbol.h"
#include "Person6.h"


namespace Lab6
{
	class PersonTools
	{
		public://TODO: Отступы //сделал
			static Person* MakeRandomPerson();
			static Person* MakeRandomPerson(enum Sex tempSex);
	};
}