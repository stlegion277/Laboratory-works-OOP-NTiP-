#pragma once
#include "CheckSymbol.h"
#include "PersonLab5.h"
#include "TempList.h"
using namespace std;

template <class Type T>
class TemplateListItem
{
	public:
		TemplateListItem<Type T>(Type T element)
		{
			_value = element;
		}
		Type T GetValue()
		{
			return _value;
		}
		TemplateListItem<Type T>* _next = nullptr;
		TemplateListItem<Type T>* _prev = nullptr;
	private:
		Person* _value;

};