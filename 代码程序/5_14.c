#include<stdio.h>
#include<stdlib.h>

void swap(int* array, int left, int right)
{
	int t = array[left];
	array[left] = array[right];
	array[right] = t;
}

// ²åÈëÅÅĞò
void InsertSort(int* array, int n)
{
	for (int i = 0; i < n - 1; i++)
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

// Ï£¶ûÅÅĞò
void ShellSort(int* array, int n)
{
	int gap = n ;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int key = array[end + gap];
			while (end >= 0 && array[end] > key)
			{
				array[end + gap] = array[end];
				end -= gap;
			}
			array[end + gap] = key;
		}
	}

}

// Ñ¡ÔñÅÅĞò
void SelectSort(int* array, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		int end = i;
		int min = end;
		for (int j = end + 1; j < n; j++)
		{
			if (array[min] > array[j])
			{
				min = j;
			}
			else
				continue;
		}
		swap(array, min, end);
	}

}

// ¶ÑÅÅĞò
//´ó¶ÑÏòÏÂµ÷Õû
void shiftDown(int* array, int n, int parent)
{
	int child = 2 * parent + 1;
	while (child<n)
	{
		if (child+1<n&& array[child + 1] > array[child])
		{
			child += 1;
		}
		if (array[parent] < array[child])
		{
			swap(array, parent, child);
			parent = child;
			child = 2 * parent + 1;

		}
		else
			break;
	}
}
void HeapSort(int* array, int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		shiftDown(array, n, i);
	}
	int end = n;
	while (end)
	{
		swap(array, 0, end-1);
		end--;
		shiftDown(array, end, 0);
		
	}
}

// Ã°ÅİÅÅĞò
void BubbleSort(int* array, int n)
{
	for (int j = n - 1; j >= 0; j--)
	{
		for (int i = 0; i < j; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(array, i, i + 1);
			}
			continue;
		}
	}
}

//¿ìÅÅ
int postion(int* array, int began,int end)
{
	int start = began;
	int key = start;
	while (began < end)
	{
		while (began < end && array[end] >= array[key])
		{
			end--;
		}
		while (began < end && array[began] <= array[key])
		{
			began++;
		}
		swap(array, began, end);
	}
	swap(array, began, start);
	return began;
}

void quicksort(int* array, int began, int end)
{
	if (began >= end)
		return;
	int pos = postion(array, began, end);
	quicksort(array, began, pos - 1);
	quicksort(array, pos + 1, end);
}
void Print(int* array, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", array[i]);
	}
}
int main()
{
	int array[] = { 10,11,9,8,11,8,16,11,15,5,7,5,10,8 };
	int size = sizeof(array) / sizeof(array[0]);
	//InsertSort(array, size);
	//ShellSort(array, size);
	//SelectSort(array, size);
	//BubbleSort(array, size);
	//HeapSort(array, size);
	quicksort(array, 0, size - 1);
	Print(array, size);
	return 0;
}

