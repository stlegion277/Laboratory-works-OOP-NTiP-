#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "stack.h"
#include "queue2.h"
#include "queue.h"
using namespace std;

int main()
{

	setlocale(0, "");


	char key;
	int value;
	int AssciiValue = 0;
	while (AssciiValue != 27) 
	{

		system("cls");

		cout << "1: ���� " << endl;
		cout << "2: ������� �� ���� ���� ������ " << endl;
		cout << "3: ��������� ������� " << endl;

		cout << endl << "�������\n";
		key = _getch();
		AssciiValue = key;
		switch (AssciiValue)
		{
		case '1':					//���������� � �����
		{
			int AssciiValue1 = 0;
			Stack* stack = CreateStack();
			while (AssciiValue1 != 27)
			{
				system("cls");

				cout << "1: ���������� � ����� " << endl;
				cout << "2: ���������� �������� " << endl;
				cout << "3: �������� �������� " << endl;

				cout << endl << "�������\n";
				key = _getch();
				AssciiValue1 = key;

				switch (AssciiValue1)
				{
				case '1':

					cout << "����: ";
					for (int i = 0; i < stack->length; i++) {
						cout << stack->array[i] << " ";
					}
					cout << endl;
					cout << "����� �����: " << stack->length << endl;
					cout << "����� ������: " << stack->bufsize << endl;
					system("pause");
					break;

				case '2':

					cout << "������� ����������� ������� ";
					cin >> value;
					PushStack(stack, value);
					break;
				case '3':
					if (stack->length > 0)
					{
						int data = PopStack(stack);
						cout << "���������� ������� = " << data;
						system("pause");
					}
					else
					{
						cout << "���� ����" << endl;
						system("pause");
					}
					break;
				}
			}

			DelStack(stack);
			break;
		}
		case '2':					//��� �����
		{
			int AssciiValue1 = 0;
			Queue2* queue = CreateQueue2();
			while (AssciiValue1 != 27)
			{
				system("cls");

				cout << "1: ������� �� ���� ���� ������ " << endl;
				cout << "2: ���������� � ������� " << endl;
				cout << "3: ���������� �������� �� ������� " << endl;

				cout << endl << "�������\n";
				key = _getch();
				AssciiValue1 = key;

				switch (AssciiValue1)
				{
				case '1':

					cout << "������ ���� \n ";
					for (int i = 0; i < queue->left->length; i++) {
						cout << queue->left->array[i] << " ";
					}
					cout << endl;

					cout << "������ ���� \n ";
					for (int i = 0; i < queue->right->length; i++) {
						cout << queue->right->array[i]<< " ";
					}
					cout << endl;

					system("pause");
					break;

				case '2':

					cout << "������� ����������� ������� ";
					cin >> value;
					Enqueue2(queue, value);
					break;


				case '3':
					if (queue->left->length || queue->right->length)
					{
						
						cout << "���������� ������� = " << Dequeue2(queue) << endl;
						system("pause");
					}
					else
					{
						cout << "������� �����" << endl;
						system("pause");
					}
					break;
				}
			}

			DeleteQueue2(queue);
			break;
		}
		case'3':
		{
			int AssciiValue1 = 0;
			Queue* queue = CreateQueue();
			while (AssciiValue1 != 27)
			{
				system("cls");

				cout << "1: ������� �� ���� ������������ ������:\n" << endl;
				cout << "2: ���������� � ������� " << endl;
				cout << "3: ���������� �������� �� ������� " << endl;

				cout << endl << "�������\n";
				key = _getch();
				AssciiValue1 = key;

				switch (AssciiValue1)
				{
				case '1':

					for (int i = 0; i < queue->length; i++) 
					{
						cout << (i + queue->head) % queue->bufsize << " ";
						cout << queue->array[(i + queue->head) % queue->bufsize] << endl;
					}

					cout << "����� �������: " << queue->length << endl;
					cout << "������ ������: " << queue->bufsize << endl;

					cout << "������: " << queue->head % queue->bufsize<<endl;
					cout << "����� " << queue->tail % queue->bufsize << endl;
					

					system("pause");
					break;

				case '2':

					cout << "������� ����������� ������� ";
					cin >> value;
					Enqueue(queue, value);
					break;


				case '3':
					if (queue->length)
					{

						cout << "���������� ������� = " << Dequeue(queue) << endl;
						system("pause");
					}
					else
					{
						cout << "������� �����" << endl;
						system("pause");
					}
					break;
				}
			}

			DeleteQueue(queue);
			break;
		}					//��������� �����
		}
		
	}
}