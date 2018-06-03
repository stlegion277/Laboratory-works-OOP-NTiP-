#pragma once
#include "Person6.h"
#include "Adult.h"
using namespace std;

template <class T>
class TemplateListItem
{
	public:
		TemplateListItem<T>(T element)
		{
			_value = element;
		}
		T GetValue()
		{
			return _value;
		}
		TemplateListItem<T>* _next = nullptr;
		TemplateListItem<T>* _prev = nullptr;
		T _value;
		//TODO: Зачем это здесь?
		//сделал
};