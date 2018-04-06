#pragma once
#include "CheckSymbol.h"
#include "Lab3.h"
#include "Sex.h"

namespace Lab3
{
	struct Person 
	{
		char Surname[40];
		char Name[20];
		Sex Sex;
	};
}
