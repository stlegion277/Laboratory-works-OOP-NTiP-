#pragma once
#include "CheckSymbol.h"
#include "PersonLab4.h"
#include "DoubleLinkedListLab4.h"
namespace Lab4
{
	struct Node
	{//TODO: ����� ��� ��� �����������?
		Person data;	// ���� ������
		Node* next = NULL; // ��������� �� ��������� �������
		Node* prev = NULL; // ��������� �� ���������� ������
	};
}
