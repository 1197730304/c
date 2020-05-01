#include "sort.h"
#include<stdio.h>
#include<stdlib.h>
void Swap(int* array, int start, int end)
{
	int temp = array[start];
	array[start] = array[end];
	array[end] = temp;
}

//ֱ�Ӳ�������
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

//ϣ������
void shellsort(int* array, int size)
{
	//���ò���
	int gap = size;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		//һ�β�������
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

//ѡ������
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

//ð������
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


//������

//��ѵ����µ���
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
	//����
	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		shiftDown(array, size, i);
	}
	//ѭ��βɾ
	int n = size - 1;
	while (n >0)
	{
		Swap(array, 0, n);
		n--;
		shiftDown(array, n+1, 0);
	}
}


//hore��
int postion(int* array, int start, int end)
{
	int key = start;
	while (start < end)
	{
		//�Ӻ���ǰ�ҵ�һ��С�ڻ�׼ֵ��
		while (start<end && array[end]>=array[key])
		{
			end--;
		}

		//��ǰ����ҵ�һ�����ڻ�׼ֵ��
		while (start<end && array[start]<=array[key])
		{
			start++;
		}
		//�����ҳ���������
		Swap(array, start, end);
	}
	//ѭ������������׼ֵ������ֵ
	Swap(array, start, key);
	return key;

}

//�ڿӷ�
int postion2(int* array, int begin, int end)
{
	int key = array[begin];
	while (begin < end)
	{
		//���������ҵ�һ��С�ڻ�׼ֵ����
		while (begin < end && array[end] >= key)
		{
			end--;
		}
		array[begin] = array[end];

		//���������ҵ�һ�����ڻ�׼ֵ��
		while (begin < end && array[begin] <= key)
		{
			begin++;
		}
		array[end] = array[begin];
	}
	array[begin] = key;
	//���ػ�׼ֵ��λ��
	return begin;
}

//˫ָ�뷨
int postion3(int* array, int begin,int end)
{
	//���һ��С�ڻ�׼ֵ��λ��
	int prev = begin;
	//��һ��С�ڻ�׼ֵ��λ��
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