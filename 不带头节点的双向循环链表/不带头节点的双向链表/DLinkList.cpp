#include <stdio.h>
#include <stdlib.h>
#include <vld.h>
#include <assert.h>
#include "DLinkList.h"

void Initialize(PDLinkList *plist)
{
	assert(plist != NULL);

	*plist = NULL;
}

static PDLinkList Build(int value)
{
	PDLinkList p = (PDLinkList)malloc(sizeof(DLinkList));

	p->data = value;

	return p;
}

void Insert_tail(PDLinkList *plist, int value)
{
	assert(plist != NULL);

	PDLinkList p = Build(value);

	if (Is_empty(*plist))
	{
		*plist = p;
		p->next = p;
		p->front = p;
	}
	else
	{
		PDLinkList q;
		for (q = *plist; q->next != *plist; q = q->next);

		p->next = q->next;
		q->next = p;
		p->front = q;
		(*plist)->front = q;
	}
}

void Insert_head(PDLinkList *plist, int value)
{
	assert(plist != NULL);

	PDLinkList p = Build(value);

	if (Is_empty(*plist))
	{
		*plist = p;
		p->next = p;
		p->front = p;
	}
	else
	{
		PDLinkList q;
		for (q = *plist; q->next != *plist; q = q->next);

		q->next = p;
		p->front = q;
		p->next = *plist;
		(*plist)->front = p;
		*plist = p;
	}
}

bool Delete(PDLinkList *plist, int value)
{
	if (Is_empty(*plist))
	{
		return false;
	}


	else
	{
		for (PDLinkList p = *plist; p->next != *plist; p = p->next)
		{
			if (p->data == value)
			{
				p->front->next = p->next;
				p->next->front = p->front;

				if (*plist == p)
				{
					*plist = (*plist)->next;
				}

				free(p);

				return true;
			}
		}

		return false;
	}
}

static bool Is_empty(PDLinkList plist)
{
	assert(plist != NULL);

	return plist == NULL;
}

int Get_length(PDLinkList plist)
{
	assert(plist != NULL);

	if (Is_empty(plist))
	{
		return 0;
	}

	int count = 0;

	for (PDLinkList p = plist; p->next != plist; p = p->next)
	{
		count++;
	}

	return ++count;
}

void Show(PDLinkList plist)
{
	assert(plist != NULL);

	PDLinkList p;

	for (p = plist; p->next != plist; p = p->next)
	{
		printf("%d ", p->data);
	}

	printf("%d ", p->data);
	printf("\n");
}

bool Clear(PDLinkList plist)
{
	assert(plist != NULL);
	if (plist == NULL)
	{
		return false;
	}

	PDLinkList p = plist;
	PDLinkList q;

	while (p->next != plist)
	{
		q = p->next;
		free(p);
		p = q;
	}
	free(p);

	plist = NULL;

	return true;
}