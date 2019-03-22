#pragma once

#define SIZE 10

typedef struct Stack
{
	int elem[SIZE];
	int top;
	int elemmin[SIZE];
	int Mintop;
}MStack,*PMStack;

void Initialize(PMStack pstack);

bool Is_Full(PMStack pstack);

bool Is_Empty(PMStack pstack);

bool Push(PMStack pstack, int value);

bool Pop(PMStack pstack, int *rtval);

bool Get_Min(PMStack pstack, int *min);