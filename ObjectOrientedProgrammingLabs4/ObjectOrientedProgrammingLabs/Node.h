#pragma once
#include "Person.h"
#include "DoubleLinkedListLab4.h"
namespace Lab4
{
	struct Node
	{//TODO: ���������� �� �� RSDN //��� ���� ����� ��� ��������� ��� Node � ���������?
		//TODO: ��� ��������� ���� ���������?
		// � ������� � �����) ������
		Person Data;	
		Node* Next = NULL; 
		Node* Prev = NULL; 
	};
}
