#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "DLinkList.h"

void Initialize(PDLinkList plist)
{
	assert(plist != NULL);

	plist->next = plist;
	plist->front = plist;
}

static PDLinkList Build(int value)
{
	PDLinkList p = (PDLinkList)malloc(sizeof(DLinkList));
	p->data = value;

	return p;
}

static bool Is_empty(PDLinkList plist)
{
	assert(plist != NULL);

	return plist->next == plist;
}

void Insert_head(PDLinkList plist, int value)
{
	assert(plist != NULL);

	PDLinkList p = Build(value);

	p->next = plist->next;
	p->front = plist;
	plist->next = p;
}

void Insert_tail(PDLinkList plist, int value)
{
	assert(plist != NULL);

	PDLinkList p = Build(value);
	PDLinkList q;

	for (q = plist->next; q->next != plist; q = q->next);

	p->next = q->next;
	p->front = q;
	q->next = p;
}

bool Delete(PDLinkList plist, int value)
{
	if (Is_empty(plist))
	{
		return false;
	}

	PDLinkList p;

	for (p = plist; p->next != plist; p = p->next)
	{
		if (p->data == value)
		{
			p->next->front = p->front;
			p->front->next = p->next;
			free(p);
			return true;
		}
	}

	return false;
}

int Get_length(PDLinkList plist)
{
	assert(plist != NULL);

	int count = 0;

	for (PDLinkList p = plist->next; p != plist; p = p->next)
	{
		count++;
	}

	return count;
}

void Show(PDLinkList plist)
{
	assert(plist != NULL);
	for (PDLinkList p = plist->next; p != plist; p = p->next)
	{
		printf("%d ", p->data);
	}
	printf("\n");

}

PDLinkList Combine(PDLinkList plist_A, PDLinkList plist_B, int a, int b)
{
	bool flag = a < b ? 1 : 0;

	if (flag)
	{
		PDLinkList p;

		for (p = plist_A; p->next != plist_A; p = p->next);
		plist_B->next->front = p;
		p->next = plist_B->next;	

		plist_A->next->front = plist_B;
		plist_B->next = plist_A->next;

		plist_A->next = plist_A;

		return plist_B;
	}
	else
	{
		PDLinkList p;

		for (p = plist_B; p->next != plist_B; p = p->next);
		plist_A->next->front = p;
		p->next = plist_A->next;

		plist_B->next->front = plist_A;
		plist_A->next = plist_B->next;

		plist_B->next = plist_B;

		return plist_A;
	}
}

bool Clear(PDLinkList plist)
{
	if (Is_empty(plist))
	{
		return false;
	}
	else
	{
		PDLinkList p = plist->next;
		PDLinkList q;

		while (p != plist)
		{
			q = p->next;
			free(p);
			p = q;
		}

		plist->next = plist;

		return true;
	}
}