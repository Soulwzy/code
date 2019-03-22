#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "LinkStack.h"

void Initialize(PLStack pstack)
{
	assert(pstack != NULL);

	Init_Linklist(&pstack->head);
}

void Push(PLStack pstack, int value)
{
	assert(pstack != NULL);

	Insert_head(&pstack->head, value);
}

bool Get_Pop(PLStack pstack, int *rtval)
{
	if (Is_Empty(pstack))
	{
		return false;
	}

	*rtval = pstack->head.next->data;

	return true;
}

bool Pop(PLStack pstack, int *rtval)
{
	if (Is_Empty(pstack))
	{
		return false;
	}

	PLinklist p = pstack->head.next;

	*rtval = pstack->head.next->data;
	pstack->head.next = pstack->head.next->next;
	free(p);

	return true;
}

bool Is_Empty(PLStack pstack)
{
	assert(pstack != NULL);

	return IsEmpty(&pstack->head);
}

bool Clear_Stack(PLStack pstack)
{
	if (Is_Empty(pstack))
	{
		return false;
	}

	Clear(&pstack->head);
	
	return true;
}

bool Show_Stack(PLStack pstack)
{
	if (pstack == NULL)
	{
		return false;
	}
	else
	{
		Show(&pstack->head);
	}
}