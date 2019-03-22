#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "SeqList.h"

void Init_SeqList(PSeqList PList)
{
	assert(PList != NULL);

	PList->len = 0;
}

void Creat_SeqList(PSeqList PList, int size)
{
	assert(PList != NULL);

	for (int i = 0; i < size; i++)
	{
		PList->data[i] = i;
	}

	PList->len = size;
}

bool Insert_SeqList(PSeqList PList, char value, int position)
{
	assert(PList != NULL);

	if (IsFull_SeqList(PList) || position < 0 || position > PList->len)
	{
		return false;
	}
	else
	{
		for (int i = PList->len - 1; i >= position; i--)
		{
			PList->data[i + 1] = PList->data[i];
		}

		PList->data[position] = value;
		PList->len++;
		return true;
	}
}

bool Delete1_SeqList(PSeqList PList, char value)
{

	assert(PList != NULL);

	int n = Search_SeqList(PList,value);

	if (n < 0)
	{
		return false;
	}

	for (int i = n; i < PList->len - 1; i++)
	{
		PList->data[i] = PList->data[i + 1];
	}

	PList->len--;

	return true;
}

bool Delete2_SeqList(PSeqList PList, int position)
{
	assert(PList != NULL);

	if (position <= 0 || position > PList->len)
	{
		return false;
	}

	for (int i = position - 1; i < PList->len - 1; i++)
	{
		PList->data[i] = PList->data[i + 1];
	}

	PList->len--;

	return true;
}

int Search_SeqList(PSeqList PList, char value)
{
	assert(PList != NULL);

	for (int i = 0; i < SIZE; i++)
	{
		if (value == PList->data[i])
		{
			return i;
		}
	}
	return -1;
}

bool IsFull_SeqList(PSeqList PList)
{
	assert(PList != NULL);

	if (PList->len == SIZE)
	{
		return true;
	}
	return false;
}

bool IsEmpty_SeqList(PSeqList PList)
{
	{
		assert(PList != NULL);

		if (PList->len == 0)
		{
			return true;
		}
		return false;
	}
}

void Show_SeqList(PSeqList PList)
{
	assert(PList != NULL);

	for (int i = 0; i < PList->len; i++)
	{
		printf("%d ",PList->data[i]);
	}
	printf("\n");
}

bool GetElem(PSeqList PList, int position, int *pval)
{
	assert(PList != NULL);

	*pval = PList->data[position];
	return true;
}

int GetLength_SeqList(PSeqList PList)
{
	assert(PList != NULL);

	return PList->len;
}

void Clear_SeqList(PSeqList PList)
{
	assert(PList != NULL);

	PList->len = 0;
}

void Destory_SeqList(PSeqList PList)
{
	assert(PList != NULL);

	Clear_SeqList(PList);
}

bool Insert(PSeqList PList, char value)                  //µ›‘ˆ”––Ú≤Â»Î
{
	assert(PList != NULL);

	if (IsFull_SeqList(PList))
	{
		return false;
	}

	for (int i = 0; i < PList->len; i++)
	{

		if (PList->data[i] > value)
		{
			Insert_SeqList(PList, value, i);
			return true;
		}
	}

	Insert_SeqList(PList, value, PList->len);
	return true;
}

int Compare(PSeqList PList_A, PSeqList PList_B)
{
	while (PList_A->data[0] == PList_B->data[0])
	{
		Delete2_SeqList(PList_A, 1);
		Delete2_SeqList(PList_B, 1);
	}

	if ( PList_A->len == 0)
	{
		return 1;
	}

	else if (PList_B->len == 0)
	{
		return -1;
	}

	else return PList_A->data[0] - PList_B->data[0];
}

bool Reverse(PSeqList PList)
{
	int n = PList->len / 2;
	char tmp;
	for (int i = 0; i < n; i++)
	{
		tmp = PList->data[i];
		PList->data[i] = PList->data[PList->len - 1 - i];
		PList->data[PList->len - 1 - i] = tmp;
	}

	return true;
}

//void Delete_more(PSeqList PList_A, PSeqList PList_B, PSeqList PList_C)
//{
//	int *p = (int *)calloc(PList_B->len, sizeof(int));
//	//int *p = (int *)malloc(PList_B->len * sizeof(int));
//
//	for (int i = 0; i < PList_B->len; i++)
//	{
//		for (int j = 0; i < PList_C->len; j++)
//		{
//			if (PList_B->data[i] == PList_C->data[j])
//			{
//				p[i] = 1;
//				break;
//			}
//		}
//	}
//
//	for (int i = 0; i < PList_A->len; i++)
//	{
//		for (int j = 0; j < PList_B->len; j++)
//		{
//			if (p[j])
//			{
//				if (PList_A->data[i] == PList_B->data[j])
//				{
//					Delete2_SeqList(PList_A, i + 1);
//				}
//			}
//		}
//	}
//}

void Delete_more(PSeqList PList_A, PSeqList PList_B, PSeqList PList_C)
{
	int i = 0;
	int j = 0;
	int k = 0;

	for (; i < PList_A->len; i++)
	{
		for (; j < PList_B->len; j++)
		{
			if (PList_A->data[i] == PList_B->data[j])
			{
				for (; k < PList_C->len; k++)
				{
					if (PList_A->data[i] == PList_C->data[k])
					{
						Delete2_SeqList(PList_A, i+1);
						i--;
					}
					else if (PList_A->data[i] < PList_C->data[k])
					{
						break;
					}
					else
					{
						continue;
					}
				}
			}

			else if (PList_A->data[i] < PList_B->data[j])
			{
				break;
			}

			else
			{
				continue;
			}
		}
		
	}
}

PSeqList Combine(PSeqList PList_A, PSeqList PList_B)
{
	int len = PList_A->len + PList_B->len;

	SeqList * PList_C = (SeqList *)malloc(sizeof(SeqList) * len);
	Init_SeqList(PList_C);
	int k = 0;
	int i = 0;
	int j = 0;

	for (; i < PList_A->len; i++)
	{
		for (; j < PList_B->len; j++)
		{
			if (i == PList_A->len)
			{
				Insert_SeqList(PList_C, PList_B->data[j], k);
				k++;
			}
			else if (PList_A->data[i] < PList_B->data[j])
			{
				Insert_SeqList(PList_C, PList_A->data[i], k);
				k++;
				break;
			}
			else if (PList_A->data[i] > PList_B->data[j])
			{
				Insert_SeqList(PList_C, PList_B->data[j], k);
				k++;
				continue;
			}
			else
			{
				Insert_SeqList(PList_C, PList_B->data[j], k);
				i++;
				k++;
				continue;
			}
		}
		if (j == PList_B->len)
		{
			break;
		}
	}
	for (; i < PList_A->len; i++)
	{
		Insert_SeqList(PList_C, PList_A->data[i], k);
		k++;
	}

	return PList_C;
}


