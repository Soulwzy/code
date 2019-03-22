#pragma once

#define SIZE 10

typedef struct Stack
{
	int elem[SIZE];
	int top;
}Stack,*PStack;

void Initialize(PStack pstack);

bool Push(PStack pstack, int value);

bool Get_Pop(PStack pstack, int *rtval);

bool Pop(PStack pstack, int *rtval);

int Get_Length(PStack pstack);

bool Is_Empty(PStack pstack);

static bool Is_Full(PStack pstack);

bool Show(PStack pstack);

