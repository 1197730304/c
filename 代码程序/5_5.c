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
	printf("|*************排序***********|\n");
	printf("|        1.直接插入排序       |\n");
	printf("|        2.希尔排序           |\n");
	printf("|        3.选择排序           |\n");
	printf("|        4.冒泡排序           |\n");
	printf("|        5.堆排序             |\n");
	printf("|        6.快速排序           |\n");

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
	printf("欢迎来到排序算法大全\n");
	printf("请输入待排序个数:\n");
		scanf("%d", &n);
	printf("请输入您将要排序的数组:\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}
	int input = 0;
		menu();
		printf("请输入你的选择:\n");
	
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
			printf("重新输入:\n");
		}

	} while (input);

	return 0;
}