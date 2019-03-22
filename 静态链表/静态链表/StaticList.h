#pragma once

#define SIZE 100

typedef struct node
{
	int data;
	int next;
}StaticList,*PStaticList;

void Initialise(PStaticList Slist);

bool Insert_tail(PStaticList Slist, int value);                         //β�巨

bool Insert_head(PStaticList Slist, int value);

int Serch(PStaticList Slist, int value);

bool Delete(PStaticList Slist,int value);

static bool Is_Full(PStaticList Slist);

static bool Is_Empty(PStaticList Slist);

void Show(PStaticList Slist);

void Delete_Add(PStaticList Slist_A, PStaticList Slist_B);            //(A-B)U(B-A)


