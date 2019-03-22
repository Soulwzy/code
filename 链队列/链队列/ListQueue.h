#pragma once

typedef struct queue
{
	int data;
	struct queue *next;
}LinkQueue,*PLinkQueue;

typedef struct Hnode
{
	struct queue *head;
	struct queue *tail;
}Hnode,*PHnode;

void Initialize(PHnode plqueue);

PLinkQueue Build(int value);

bool Push(PHnode plqueue, int value);

bool Get_Top(PHnode plqueue, int *rtval);

bool Top(PHnode plqueue, int *rtval);

bool Is_Empty(PHnode plqueue);

void Destory(PHnode plqueue);