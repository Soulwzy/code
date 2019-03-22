#pragma once

#define SIZE 10

typedef struct
{
	char data[10];
	int len;
}SeqList,*PSeqList;

void Init_SeqList(PSeqList PList);

void Creat_SeqList(PSeqList PList,int size);

bool Insert_SeqList(PSeqList PList, char value, int position);

bool Delete1_SeqList(PSeqList PList, char value);

bool Delete2_SeqList(PSeqList PList, int position);

void Show_SeqList(PSeqList PList);

int Search_SeqList(PSeqList PList, char value);

bool IsFull_SeqList(PSeqList PList);

bool IsEmpty_SeqList(PSeqList PList);

bool GetElem(PSeqList plist, int position, int *pval);

int GetLength_SeqList(PSeqList PList);

void Clear_SeqList(PSeqList PList);

void Destory_SeqList(PSeqList PList);
 
bool Insert(PSeqList PList, char value);					                 //递增有序插入

int Compare(PSeqList PList_A, PSeqList PList_B);                             //A B 比较

bool Reverse(PSeqList PList);                                                //逆置

void Delete_more(PSeqList PList_A, PSeqList PList_B, PSeqList PList_C);      // 删除A中在B C中存在的点

PSeqList Combine(PSeqList PList_A, PSeqList PList_B);                        //A B递增有序插入C





