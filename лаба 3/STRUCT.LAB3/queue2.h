
#include "stack.h"
struct Queue2
{
	Stack* left;
	Stack* right;
};

Queue2* CreateQueue2();
void Enqueue2(Queue2* queue, int value);
int Dequeue2(Queue2* queue);
void Requeue2(Queue2* queue);
void DeleteQueue2(Queue2* queue);
