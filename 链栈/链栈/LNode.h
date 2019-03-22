#pragma once

typedef struct node
{
	int data;
	struct node *next;
}Linklist,*PLinklist;

void Init_Linklist(PLinklist plist);

bool Insert_head(PLinklist plist, int value);

bool Insert_tail(PLinklist plist, int value);

PLinklist Search(PLinklist plist, int value);

bool Delete(PLinklist plist, int value);                               //���ظ�ɾ����һ��i

int GetLength(PLinklist plist);

bool IsEmpty(PLinklist plist);

void Show(PLinklist plist);

void Clear(PLinklist plist);

void Destory(PLinklist plist);

bool Have_Circle(PLinklist plist);                                    //�Ƿ��л�

PLinklist Have_Commom(PLinklist plist_A, PLinklist plist_B);          //�Ƿ��н���

void Delete_Particular(PLinklist p);                                   //ɾ����һ���ڵ�

void Insert_Particular(PLinklist p, char value);                       //���뵽 p ǰ

void Delete_back(PLinklist p, int k);                                  // ɾ��������k���ڵ�

void Reverse(PLinklist plist);                                         //����

void Add_ABC(PLinklist plist_A, PLinklist plist_B, PLinklist plist_C);  //AU(BnC)
 
void Delete_k(PLinklist plist, int k);                                   //ɾ��������k��

PLinklist Return_Circle(PLinklist plist);								//���ػ�
