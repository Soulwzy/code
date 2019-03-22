#pragma once

typedef struct node
{
	int data;
	struct node *next;
	struct node *front;
}DLinkList, *PDLinkList;

void Initialize(PDLinkList *plist);

static PDLinkList Build(int value);

void Insert_tail(PDLinkList *plist,int value);

void Insert_head(PDLinkList *plist,int value);

bool Delete(PDLinkList *plist,int value);

static bool Is_empty(PDLinkList plist);

int Get_length(PDLinkList plist);

bool Clear(PDLinkList plist);

void Show(PDLinkList plist);


