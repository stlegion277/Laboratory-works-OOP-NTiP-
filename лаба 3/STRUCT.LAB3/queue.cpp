#include "queue.h";

Queue* CreateQueue()
{
	Queue* queue = new Queue;
	queue->bufsize = 2;
	queue->length = 0;
	queue->array = new int[queue->bufsize];
	queue->head = 0;
	queue->tail = 0;
	return queue;
}

void Enqueue(Queue* queue, int value) 
{
	if (queue->length == queue->bufsize)
		Resize(queue, true);
	if (queue->length)
	{
		queue->tail = (queue->tail + 1) % queue->bufsize;
	}
	queue->array[queue->tail] = value;
	queue->length++;
}

int Dequeue(Queue* queue)
{
	int data = queue->array[queue->head];
	queue->length--;
	queue->head = (queue->head + 1) % queue->bufsize;

	if (queue->length <= (queue->bufsize / 2) && queue->bufsize > 2)
		Resize(queue, false);

	return data;
}

void Resize(Queue* queue, bool inc)
{
	int newSize;
	newSize = inc ? (queue->bufsize * 2) : (queue->bufsize);

	int* dArr = new int[newSize];

	for (int i = 0; i < queue->length; i++)
	{
		dArr[i] = queue->array[(i + queue->head) % queue->bufsize];
	}
	delete[] queue->array;

	queue->head = 0;
	queue->tail = queue->length - 1;

	queue->array = dArr;
	queue->bufsize = newSize;
}

void DeleteQueue(Queue* queue)
{
	delete[] queue->array;
	delete[] queue;
}