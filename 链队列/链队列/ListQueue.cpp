#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ListQueue.h"

void Initialize(PHnode plqueue)
{
	assert(plqueue != NULL);

	plqueue->head = NULL;
	plqueue->tail = NULL;
}

PLinkQueue Build(int value)
{
	PLinkQueue p = (PLinkQueue)malloc(sizeof(LinkQueue));

	p->data = value;

	return p;
}

bool Push(PHnode plqueue, int value)
{
	assert(plqueue != NULL);

	PLinkQueue p = Build(value);

	if (Is_Empty(plqueue))
	{
		plqueue->head = p;
		plqueue->tail = p;
	}
	else
	{
		plqueue->tail->next = p;
		plqueue->tail = p;
	}

	return true;
}

bool Get_Top(PHnode plqueue, int *rtval)
{
	assert(plqueue != NULL);

	if (Is_Empty(plqueue))
	{
		return false;
	}

	*rtval = plqueue->head->data;

	return true;
}

bool Top(PHnode plqueue, int *rtval)
{
	assert(plqueue != NULL);

	if (Is_Empty(plqueue))
	{
		return false;
	}

	*rtval = plqueue->head->data;

	PLinkQueue p = plqueue->head;
	plqueue->head = plqueue->head->next;
	free(p);

	if (plqueue->head == NULL)
	{
		plqueue->tail = NULL;
	}

	return true;
}

bool Is_Empty(PHnode plqueue)
{
	assert(plqueue != NULL);
}

void Destory(PHnode plqueue)
{
	assert(plqueue != NULL);

	PLinkQueue p;

	while (plqueue->head != NULL)
	{
		p = plqueue->head;
		plqueue->head = p->next;
		free(p);
	}
	plqueue->tail = NULL;
}