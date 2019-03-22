#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <vld.h>
#include "List.h"

void Initialize(Plist *plist)
{
	assert(plist != NULL);

	*plist = NULL;
}

Plist Build(int value)
{
	Plist p = (Plist)malloc(sizeof(List));

	p->data = value;

	return p;
}

void Insert_head(Plist *plist, int value)
{
	assert(plist != NULL);

	Plist p = Build(value);

	p->next = *plist;
	*plist = p;
}

void Insert_tail(Plist *plist, int value)
{
	assert(plist != NULL);

	Plist p = Build(value);
	
	if (Is_Empty(*plist))
	{
		p->next = *plist;
		*plist = p;
	}
	else
	{
		Plist q;
		for (q = *plist; q->next != NULL; q = q->next);

		p->next = q->next;
		q->next = p;
	}
}

static bool Is_Empty(Plist plist)
{
	return plist == NULL;
}

bool Delete(Plist *plist, int value)
{
	if (Is_Empty(*plist))
	{
		return false;
	}

	if ((*plist)->data == value)
	{
		Plist q = *plist;
		*plist = (*plist)->next;
		free(q);
	}

	for (Plist p = *plist; p->next != NULL; p = p->next)
	{
		if (p->next->data == value)
		{
			Plist q = p->next;
			p->next = p->next->next;
			free(q);
		}
	}
}

void Show(Plist plist)
{
	assert(plist != NULL);

	for (Plist p = plist; p != NULL; p = p->next)
	{
		printf("%d ", p->data);
	}
	printf("\n");
}

void Clean(Plist plist)
{
	assert(plist != NULL);

	Plist p = plist;
	Plist q;

	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
}
