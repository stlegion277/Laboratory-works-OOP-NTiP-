#pragma once
#include "PersonLab4.h"
#include "DoubleLinkedListLab4.h"
namespace Lab4
{
	struct Node
	{//TODO: ���������� �� �� RSDN
		Person data;	
		Node* next = NULL; 
		Node* prev = NULL; 
	};
}
