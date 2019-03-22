#pragma once

typedef struct node
{
	int data;
	struct node *next;
	struct node *front;
}DLinkList,*PDLinkList;

void Initialize(PDLinkList plist);

static PDLinkList Build(int value);

static bool Is_empty(PDLinkList plist);

void Insert_head(PDLinkList plist, int value);

void Insert_tail(PDLinkList plist, int value);

bool Delete(PDLinkList plist, int value);

int Get_length(PDLinkList plist);

void Show(PDLinkList plist);

bool Clear(PDLinkList plist);

PDLinkList Combine(PDLinkList plist_A, PDLinkList plist_B, int a, int b);     //ื๗าต