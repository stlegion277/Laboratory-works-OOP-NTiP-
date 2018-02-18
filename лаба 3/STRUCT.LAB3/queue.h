#pragma once
struct Queue
{
	int* array;
	int length;
	int bufsize;
	int head;
	int tail;
};

Queue* CreateQueue();
void Enqueue(Queue* queue, int value);
int Dequeue(Queue* queue);
void DeleteQueue(Queue* queue);
void Resize(Queue* queue, bool inc);