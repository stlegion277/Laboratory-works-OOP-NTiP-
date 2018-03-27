#pragma once
#include "CheckSymbol.h"
#include "PersonLab4.h"
#include "DoubleLinkedListLab4.h"
namespace Lab4
{
	struct Node
	{
		Person data;	// поле данных
		Node* next = NULL; // ”казатель на следующий элемент
		Node* prev = NULL; // ”казатель на предыдущий элемен
	};
}
