#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "StaticList.h"


void Initialise(PStaticList Slist)
{
	assert(Slist != NULL);
	if (Slist == NULL)
	{
		return;
	}

	Slist[0].next = 0;

	for (int i = 1; i < SIZE; i++)
	{
		Slist[i].next = i + 1;
	}

	Slist[SIZE - 1].next = 1;
}
static bool Is_Full(PStaticList Slist)
{
	assert(Slist != NULL);

	return Slist[1].next == 1;
}

static bool Is_Empty(PStaticList Slist)
{
	assert(Slist != NULL);

	return Slist[0].next == 0;
}

bool Insert_tail(PStaticList Slist, int value)                           //¾²Ì¬Á´±íÎ²²å·¨
{
	assert(Slist != NULL);

	if (Is_Full(Slist))
	{
		return false;
	}

	int p = Slist[0].next;
	int q = Slist[1].next;

	Slist[1].next = Slist[q].next;
	Slist[q].data = value;

	for (; Slist[p].next != 0; p = Slist[p].next);                             //ÕÒµ½Ä©Î²

	Slist[q].next = 0;
	Slist[p].next = q;

	return true;
}

bool Insert_head(PStaticList Slist, int value)									//¾²Ì¬Á´±íÍ·²å·¨
{
	assert(Slist != NULL);

	if (Is_Full(Slist))
	{
		return false;
	}

	int p = Slist[1].next;
	Slist[1].next = Slist[p].next;

	Slist[p].data = value;
	Slist[p].next = Slist[0].next;
	Slist[0].next = p;
	
	return true;
}

int Serch(PStaticList Slist, int value)
{
	assert(Slist != NULL);

	for (int i = Slist[0].next; i != 0; i = Slist[i].next)
	{
		if (Slist[i].data == value)
		{
			return i;
		}
	}

	return -1;
}

bool Delete(PStaticList Slist, int value)
{
	assert(Slist != NULL);

	if (Is_Empty(Slist))
	{
		return false;
	}

	
	for (int p = 0; Slist[p].next != 0; p = Slist[p].next)
	{
		if (Slist[Slist[p].next].data == value)
		{
			int q = Slist[p].next;
			Slist[p].next = Slist[Slist[p].next].next;

			Slist[q].next = Slist[1].next;
			Slist[1].next = q;
		}
	}

	return true;
}

void Show(PStaticList Slist)
{


	if (Is_Empty(Slist))
	{
		return;
	}

	for (int i = Slist[0].next; i != 0; i = Slist[i].next)
	{
		printf("%d ", Slist[i].data);
	}
	printf("\n");
}

void Delete_Add(PStaticList Slist_A,PStaticList Slist_B)                
{
	int i = Slist_B[0].next;
	int j = Slist_A[0].next;

	for (; i != 0; i = Slist_B[i].next)
	{
		for (; j != 0; j = Slist_A[j].next)
		{
			if (Slist_A[j].data == Slist_B[i].data)
			{
				Delete(Slist_A, Slist_A[j].data);
				j = Slist_A[0].next;
				break;
			}
		}
		if (j == 0)
		{
			if (Is_Empty(Slist_A))
			{
				i = Slist_B[i].next;
				Insert_tail(Slist_A, Slist_B[i].data);
			}
			else
			{
				Insert_tail(Slist_A, Slist_B[i].data);
			}
		}
	}

}