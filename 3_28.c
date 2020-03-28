#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//1.�ַ�����һ
//int main()
//{
//	char arr[1000] = { 0 };
//	int num[26] = { 0 };
//	gets(arr);
//	int len = strlen(arr);
//	for (int i = 0; i < len; i++)
//	{
//		num[arr[i] - 'a']++;
//	}
//	char c = 'a';
//	for (int i = 0; i < 26; i++)
//	{
//		if (num[i])
//		{
//			printf("%c%d", c, num[i]);
//		}
//		c++;
//	}
//	return 0;
//}


// SeqList.h
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
void SeqListInit(SeqList* ps);
void SeqListDestory(SeqList* ps);

void SeqListPrint(SeqList* ps);
void SeqListPushBack(SeqList* ps, SLDateType x);
void SeqListPushFront(SeqList* ps, SLDateType x);
void SeqListPopFront(SeqList* ps);
void SeqListPopBack(SeqList* ps);

// ˳������
int SeqListFind(SeqList* ps, SLDateType x);
// ˳�����posλ�ò���x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x);
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* ps, size_t pos);