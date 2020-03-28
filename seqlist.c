#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SLDateType;
typedef struct SeqList
{
	SLDateType* a;
	size_t size;
	size_t capacity; // unsigned int
}SeqList;

// �����ݵĹ���:��ɾ��� 
void SeqListInit(SeqList* ps)
{
	ps->a = (int*)malloc(sizeof(SLDateType) * 4);
	ps->capacity = 4;
	ps->size = 0;
}
void SeqListDestory(SeqList* ps);

void SeqListPrint(SeqList* ps)
{
	for (size_t i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
void SeqListPushBack(SeqList* ps, SLDateType x)
{//β��

	ps->a[ps->size] = x;
	ps->size++;

}
void SeqListPushFront(SeqList* ps, SLDateType x)
{
	//ͷ��
	for (size_t i = ps->size; i > 0; i--)
	{
		ps->a[i ] = ps->a[i-1];
	}
	ps->a[0] = x;
	ps->size++;
	
}

void SeqListPopFront(SeqList* ps)
{
	//ͷɾ
	for (size_t i = 0; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

void SeqListPopBack(SeqList* ps)
{
	//βɾ
	if(ps->size)
	ps->size--;
}

// ˳������
int SeqListFind(SeqList* ps, SLDateType x)
{
	size_t i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
		else
			return -1;
	}
}
// ˳�����posλ�ò���x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
{
	if (pos <= ps->size - 1)
	{
	size_t i = 0;
	for (i = ps->size ; i > pos; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
		ps->a[pos] = x;
		ps->size++;
	}
}

// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* ps, size_t pos)
{
	if (pos <= ps->size - 1)
	{
		size_t i = pos;
		for (i = pos ; i < ps->size-1; i++)
		{
			ps->a[i] = ps->a[i + 1];
		}
		ps->size--;
	}
}