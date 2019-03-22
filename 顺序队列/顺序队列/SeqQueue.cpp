#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "SeqQueue.h"

void Initialize(PQueue pqueue)
{
	assert(pqueue != NULL);
	
	pqueue->front = 0;
	pqueue->rear = 0;
}

bool Push(PQueue pqueue, int value)
{
	assert(pqueue != NULL);

	if (Is_Full(pqueue))
	{
		return false;
	}

	pqueue->data[pqueue->rear] = value;
	pqueue->rear = (pqueue->rear + 1) % SIZE;

	return true;
}

bool Get_Top(PQueue pqueue, int *rtval)
{
	assert(pqueue != NULL);

	if(Is_Empty(pqueue))
	{
		return false;
	}

	*rtval = pqueue->data[pqueue->front];

	return true;
}

bool Pop(PQueue pqueue, int *rtval)
{
	assert(pqueue != NULL);

	if (Is_Empty(pqueue))
	{
		return false;
	}

	*rtval = pqueue->data[pqueue->front];
	pqueue->front = (pqueue->front + 1) % SIZE;

	return true;
}

int Get_Length(PQueue pqueue)
{
	assert(pqueue != NULL);

	int i = pqueue->front;
	int count = 0;

	while (pqueue->front != pqueue->rear)
	{
		pqueue->front = (pqueue->front + 1) % SIZE;
		count++;
	}

	pqueue->front = i;

	return count;
}

bool Is_Empty(PQueue pqueue)
{
	assert(pqueue != NULL);

	return pqueue->front == pqueue->rear;
}

static bool Is_Full(PQueue pqueue)
{
	assert(pqueue != NULL);

	return	(pqueue->rear + 1) % SIZE == pqueue->front;
}
 
void Simulate_PushStack(PQueue pqueue_A,int value)                          //模拟入栈
{
	assert(pqueue_A != NULL);

	Push(pqueue_A, value);
}

bool Simulate_PopStack(PQueue pqueue_A, PQueue pqueue_B,int *rtval)			//模拟出栈
{
	int value;
	int n = Get_Length(pqueue_A);

	if (Is_Empty(pqueue_A))
	{
		return false;
	}

	else
	{
		for (int i = 0; i < n - 1; i++)
		{
			Pop(pqueue_A, &value);
			Push(pqueue_B, value);
		}

		Pop(pqueue_A, rtval);

		while (!Is_Empty(pqueue_B))
		{
			Pop(pqueue_B, &value);
			Push(pqueue_A, value);
		}

		return true;
	}
}
