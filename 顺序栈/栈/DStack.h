#pragma once

#define INIT_SIZE 10

typedef struct Dstack
{
	int *elem;
	int top;							//ջ��ָ�룬��ǰ���Դ�����ݵ��±�
	int size;							//�ܸ�����
}DStack,*PDStack;

void Initialize(PDStack pstack);

void Push(PDStack pstack, int value);

bool Get_Top(PDStack pstack, int *rtval);    //��ȡջ��ֵ������ɾ��

bool Pop(PDStack pstack, int *rtval);		//��ȡջ��ֵ����ɾ��

int Get_Length(PDStack pstack);

bool Is_Empty(PDStack pstack);

void Destroy(PDStack pstack);

void Clear(PDStack pstack);

bool Show(PDStack pstack);

bool Match(PDStack pstack, const char *string);

int Get_Value(PDStack pstack, const char *string);

void Simulate_PushQueue(PDStack pstack_A, int value);

bool Simulate_PopQueue(PDStack pstack_A, PDStack pstack_B, int *rtval);

void Mid_ToBack(PDStack pstack_Num, PDStack pstack_Opr, const char *string);

void Mid_ToFront(PDStack pstack_Num, PDStack pstack_Opr, const char *string);