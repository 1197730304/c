#include "sort.h"
#include<stdio.h>
#include<stdlib.h>
void Swap(int* array, int start, int end)
{
	int temp = array[start];
	array[start] = array[end];
	array[end] = temp;
}

//直接插入排序
void insertsort(int* array, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int end = i;
		int key = array[end + 1];
		while (end >= 0 && key < array[end])
		{
			array[end + 1] = array[end];
			end--;
		}
		array[end + 1] = key;
	}
}

//希尔排序
void shellsort(int* array, int size)
{
	//设置步长
	int gap = size;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		//一次插入排序
		for (int i = 0; i < size - gap; i++)
		{
			int end = i;
			int key = array[end + gap];
			while (end >= 0 && key < array[end])
			{
				array[end + gap] = array[end];
				end -= gap;
			}
			array[end + gap] = key;
		}

	}
}

//选择排序
void selectsort(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		int start = i;
		int min = start;
		for (int k = start; k < size; k++)
		{
			if (array[min] > array[k])
			{
				min = k;
			}
			else
				continue;
		}
		Swap(array, min, start);
	}

}

//冒泡排序
void bubblesort(int* array, int size)
{
	for (int i = size - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (array[j] > array[j + 1])
			{
				Swap(array, j, j + 1);
			}
		}
	}
}


//堆排序

//大堆的向下调整
void shiftDown(int* array, int size, int parent)
{
	int child = 2 * parent + 1;
	while (child < size)
	{
		if (child+1 < size && array[child] < array[child + 1])
		{
			child++;
		}
		if (array[parent] < array[child])
		{
			Swap(array, child, parent);
			parent = child;
			child = 2 * parent + 1;
		}
		else
			break;
	}
}

void heapsort(int* array, int size)
{
	//建堆
	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		shiftDown(array, size, i);
	}
	//循环尾删
	int n = size - 1;
	while (n >0)
	{
		Swap(array, 0, n);
		n--;
		shiftDown(array, n+1, 0);
	}
}


//hore法
int postion(int* array, int start, int end)
{
	int key = start;
	while (start < end)
	{
		//从后向前找第一个小于基准值的
		while (start<end && array[end]>=array[key])
		{
			end--;
		}

		//从前向后找第一个大于基准值的
		while (start<end && array[start]<=array[key])
		{
			start++;
		}
		//交换找出的两个数
		Swap(array, start, end);
	}
	//循环结束交换基准值和相遇值
	Swap(array, start, key);
	return key;

}

//挖坑法
int postion2(int* array, int begin, int end)
{
	int key = array[begin];
	while (begin < end)
	{
		//从右往左找第一个小于基准值的数
		while (begin < end && array[end] >= key)
		{
			end--;
		}
		array[begin] = array[end];

		//从左往右找第一个大于基准值的
		while (begin < end && array[begin] <= key)
		{
			begin++;
		}
		array[end] = array[begin];
	}
	array[begin] = key;
	//返回基准值的位置
	return begin;
}

//双指针法
int postion3(int* array, int begin,int end)
{
	//最后一个小于基准值的位置
	int prev = begin;
	//下一个小于基准值的位置
	int cur = prev + 1;
	int key = array[begin];
	while (cur <= end)
	{
		if (array[cur] < key && ++prev != cur)
		{
			Swap(array, cur, prev);
		}
		cur++;
	}
	Swap(array, begin, prev);
	return prev;
}
void quicksort(int* array, int start, int end)
{
	if (start > end)
		return;
	int pos = postion3(array, start, end);
	quicksort(array, start, pos - 1);
	quicksort(array, pos + 1, end );

}