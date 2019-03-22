#pragma once
#include "LNode.h"

typedef struct LStack
{
	Linklist head;
}LStack,*PLStack;

void Initialize(PLStack pstack);

void Push(PLStack pstack, int value);

bool Get_Pop(PLStack pstack, int *rtval);

bool Pop(PLStack pstack, int *rtval);

bool Is_Empty(PLStack pstack);

bool Clear_Stack(PLStack pstack);

bool Show_Stack(PLStack pstack);
