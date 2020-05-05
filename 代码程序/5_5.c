#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void Swap(int* array, int l, int r)
{
	int t = array[l];
	array[l] = array[r];
	array[r] = t;
}

int postion(int* array, int begin, int end)
{
	int start = begin;
	int key = array[start];
	while (begin < end)
	{
		while (begin < end && array[end] >= key)
		{
			end--;
		}
		while (begin < end && array[begin] <= key)
		{
			begin++;
		}
		Swap(array, begin, end);
	}
	Swap(array, begin, start);
	return begin;
}

void quicksort(int* array, int begin, int end)
{
	if (begin > end)
		return;	
	int pos = postion(array, begin, end);
		quicksort(array, begin, pos - 1);
		quicksort(array, pos + 1, end);
}

void menu()
{
	printf("-----------------------------\n");
	printf("-----------------------------\n");
	printf("|*************����***********|\n");
	printf("|        1.ֱ�Ӳ�������       |\n");
	printf("|        2.ϣ������           |\n");
	printf("|        3.ѡ������           |\n");
	printf("|        4.ð������           |\n");
	printf("|        5.������             |\n");
	printf("|        6.��������           |\n");

}

void Print(int* array,int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main()
{
	int array[] = { 0 };
	int n = 0;
	printf("��ӭ���������㷨��ȫ\n");
	printf("��������������:\n");
		scanf("%d", &n);
	printf("����������Ҫ���������:\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}
	int input = 0;
		menu();
		printf("���������ѡ��:\n");
	
	do {

		scanf("%d", &input);
		switch (input)
		{
		case 1:
			quicksort(array, 0, n - 1);
	        Print(array, n);
			break;
		case 0:
			break;
		default:
			printf("��������:\n");
		}

	} while (input);

	return 0;
}