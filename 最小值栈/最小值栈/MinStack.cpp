#include <stdio.h>
#include <assert.h>
#include "MinStack.h"

void Initialize(PMStack pstack)
{
	assert(pstack != NULL);

	pstack->top = 0;
	pstack->Mintop = 0;
}

bool Is_Full(PMStack pstack)
{
	assert(pstack != NULL);

	return pstack->top == SIZE - 1;
}

bool Is_Empty(PMStack pstack)
{
	assert(pstack != NULL);

	return pstack->top == 0;
}

bool Push(PMStack pstack, int value)
{
	assert(pstack != NULL);

	if (Is_Full(pstack))
	{
		return false;
	}

	if (Is_Empty(pstack))
	{		
		pstack->elemmin[pstack->Mintop++] = value;
	}

	else
	{
		int tmp = pstack->elemmin[pstack->Mintop - 1] < value ? pstack->elemmin[pstack->Mintop - 1] : value;
		pstack->elemmin[pstack->Mintop++] = tmp;
	}

	pstack->elem[pstack->top++] = value;

	return true;
}

bool Pop(PMStack pstack, int *rtval)
{
	assert(pstack != NULL);

	if (Is_Empty(pstack))
	{
		return false;
	}

	*rtval = pstack->elem[pstack->top--];
	pstack->Mintop--;
}

bool Get_Min(PMStack pstack, int *min)
{
	assert(pstack != NULL);

	if (Is_Empty(pstack))
	{
		return false;
	}
	else
	{
		*min = pstack->elemmin[pstack->Mintop - 1];

		return true;
	}
}