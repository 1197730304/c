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

// 对数据的管理:增删查改 
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
{//尾插

	ps->a[ps->size] = x;
	ps->size++;

}
void SeqListPushFront(SeqList* ps, SLDateType x)
{
	//头插
	for (size_t i = ps->size; i > 0; i--)
	{
		ps->a[i ] = ps->a[i-1];
	}
	ps->a[0] = x;
	ps->size++;
	
}

void SeqListPopFront(SeqList* ps)
{
	//头删
	for (size_t i = 0; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

void SeqListPopBack(SeqList* ps)
{
	//尾删
	if(ps->size)
	ps->size--;
}

// 顺序表查找
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
// 顺序表在pos位置插入x
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

// 顺序表删除pos位置的值
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