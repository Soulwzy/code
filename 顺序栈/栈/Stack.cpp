#include <stdio.h>
#include <assert.h>
#include "Stack.h"

void Initialize(PStack pstack)
{
	assert(pstack != NULL);

	pstack->top = 0;
}

bool Push(PStack pstack, int value)                        
{
	assert(pstack != NULL);

	if (Is_Full(pstack))
	{
		return false;
	}

	pstack->elem[pstack->top++] = value;

	return true;
}

bool Get_Pop(PStack pstack, int *rtval)						//只弹出不删除
{
	assert(pstack != NULL);

	if (Is_Empty(pstack))
	{
		return false;
	}
	else
	{
		*rtval = pstack->elem[pstack->top - 1];

		return true;
	}
}

bool Pop(PStack pstack, int *rtval)                         //弹出并删除
{
	assert(pstack != NULL);

	if (Is_Empty(pstack))
	{
		return false;
	}
	else
	{
		*rtval = pstack->elem[--pstack->top];

		return true;
	}
}

int Get_Length(PStack pstack)
{
	assert(pstack != NULL);

	return pstack->top;
}

bool Is_Empty(PStack pstack)
{
	assert(pstack != NULL);

	return pstack->top == 0;
}

static bool Is_Full(PStack pstack)
{
	assert(pstack != NULL);

	return pstack->top > SIZE - 1;
}

bool Show(PStack pstack)
{
	assert(pstack != NULL);

	int rtval;
	int tmp = pstack->top;

	if (Is_Empty(pstack))
	{
		return false;
	}
	else
	{
		while (!Is_Empty(pstack))
		{
			Pop(pstack, &rtval);
			printf("%d ", rtval);
		}

		printf("\n");
		pstack->top = tmp;

		return true;
	}
}
