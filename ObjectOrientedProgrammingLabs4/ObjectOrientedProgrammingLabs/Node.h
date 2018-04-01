#pragma once
#include "PersonLab4.h"
#include "DoubleLinkedListLab4.h"
namespace Lab4
{
	struct Node
	{//TODO: Зачем тут эти комментарии?
		//исправил (остались еще со структур данных)
		Person data;	
		Node* next = NULL; 
		Node* prev = NULL; 
	};
}
