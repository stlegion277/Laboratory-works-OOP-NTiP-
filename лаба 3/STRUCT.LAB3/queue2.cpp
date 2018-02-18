#include "queue2.h"

Queue2* CreateQueue2() 
{
	Queue2* queue = new Queue2;
	queue->left = CreateStack();
	queue->right =  CreateStack();

	return queue;
}
void Enqueue2(Queue2* queue, int value)
{
	PushStack(queue->left, value);
}
int Dequeue2(Queue2* queue) 
{
	if (!queue->right->length) 
		Requeue2(queue); //если длинна станет равна 0
	return PopStack(queue->right);
}
void Requeue2(Queue2* queue)
{
	while(queue->left->length)
	{
		PushStack(queue->right, queue->left->array[queue->left->length-1]); //продвигаем элементы первого стека дальше в очереди 
		PopStack(queue->left);
	}
}
void DeleteQueue2(Queue2* queue)
{
	DelStack(queue->left);
	DelStack(queue->right);

	delete queue;
}