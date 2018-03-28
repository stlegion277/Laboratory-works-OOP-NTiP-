#pragma once
#include "CheckSymbol.h"
#include "PersonLab4.h"
#include "DoubleLinkedListLab4.h"
namespace Lab4
{
	struct Node
	{//TODO: Зачем тут эти комментарии?
		Person data;	// поле данных
		Node* next = NULL; // Указатель на следующий элемент
		Node* prev = NULL; // Указатель на предыдущий элемен
	};
}
