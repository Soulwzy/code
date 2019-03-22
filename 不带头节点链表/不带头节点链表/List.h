#pragma once

typedef struct node
{
	int data;
	struct node *next;
}List,*Plist;

void Initialize(Plist *plist);

Plist Build(int value);

void Insert_head(Plist *plist, int value);

void Insert_tail(Plist *plist, int value);

static bool Is_Empty(Plist plist);

bool Delete(Plist *plist, int value);

void Show(Plist plist);

void Clean(Plist plist);

