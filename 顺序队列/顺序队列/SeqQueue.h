#pragma once

#define SIZE 10

typedef struct queue
{
	int data[SIZE];
	int front;
	int rear;
}Queue,*PQueue;

void Initialize(PQueue pqueue);

bool Push(PQueue pqueue, int value);

bool Get_Top(PQueue pqueue, int *rtval);

bool Pop(PQueue pqueue, int *rtval);

int Get_Length(PQueue pqueue);

bool Is_Empty(PQueue pqueue);

static bool Is_Full(PQueue pqueue);

void Simulate_PushStack(PQueue pqueue_A, int value);

bool Simulate_PopStack(PQueue pqueue_A, PQueue pqueue_B, int *rtval);
