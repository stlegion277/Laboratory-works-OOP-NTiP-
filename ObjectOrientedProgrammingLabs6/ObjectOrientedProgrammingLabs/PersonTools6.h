#pragma once
#include "CheckSymbol.h"
#include "Child.h"


namespace Lab6
{
	class PersonTools
	{
		public:
			static Child* MakeRandomChild();
			static Adult* MakeRandomAdult();
			static Adult* MakeRandomAdult(Sex sexTemp);
			static Adult* MakingMarriage();
	};
}