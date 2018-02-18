#pragma once
using namespace std;

struct Stack {
	int* array;
	int length;
	int bufsize;
};

//void Initial(Array* arr);						//�������������
void Resize(Stack* st);						//��������� ����� ������
//void Add(Array* arr, int value, int index);		//���������� �������� �� �������
//void Delete(Array* arr, int index);				//��������		
void PushStack(Stack* st, int value);
int PopStack(Stack* st);
void DelStack(Stack* st);
Stack* CreateStack();