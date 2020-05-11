#include<stdio.h>
#include<stdlib.h>

void Swap(int* array, int l, int r)
{
	int t = array[l];
	array[l] = array[r];
	array[r] = t;
}
//��������
//void insertsort(int* array, int n)
//{
//	//��������
//	for (int i = 0; i < n - 1; i++)
//	{
//	//һ������
//	int end = i;
//	int key = array[end + 1];
//	while (end >= 0 && array[end] > key)
//	{
//		array[end+1] = array[end];
//		end--;
//	}
//	array[end + 1] = key;
//	}
//}


//ϣ������
//void shellsort(int* array, int n)
//{
//	int  grap = n;
//	while (grap > 1)
//	{
//		grap = grap / 3 + 1;
//	for(int i=0;i<n-grap;i++)
//	{
//		//һ������
//		int end = i;
//		int key = array[end + grap];
//		while (end>=0 && array[end]>key)
//		{
//			array[end + grap] = array[end];
//			end -= grap;
//		}
//		array[end + grap] = key;
//	}
//    }
//}

//ѡ������
//void selectsort(int* array, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		int end = i;
//		int min = end;
//		for (int j = end + 1; j < n; j++)
//		{
//			if (array[min] > array[j])
//				min = j;
//			else
//				continue;
//		}
//		Swap(array, min, end);
//	}
//
//
//}


//ð������
//void bubblesort(int* array, int n) {
//	for (int i = n - 1; i >= 0; i--)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			if (array[j ] > array[j+1])
//			{
//				Swap(array, j, j + 1);
//			}
//		}
//	}
//}

//������
//��ѵ����µ���
//void shiftDown(int* array, int parent, int n)
//{
//	int child = 2 * parent + 1;
//
//	while (child < n)
//	{
//	   if (child + 1 < n && array[child] < array[child + 1])
//	   {
//		child++;
//	   }
//	   if (array[child] > array[parent])
//	   {
//		   Swap(array, child, parent);
//		   parent = child;
//		   child = 2 * parent + 1;
//	   }
//	   else
//		   break;
//	}
//
//}
//
//void heapsort(int* array, int n)
//{
//	//����
//	for (int i = (n - 2) / 2; i >= 0; i--)
//	{
//		shiftDown(array, i, n);
//	}
//	//ѭ��βɾ
//	int j = n;
//	while (j)
//	{
//		Swap(array, 0, j - 1);
//		j--;
//		shiftDown(array, 0, j);	
//	}
//}


//����ȡ��
//int getmid(int* array, int began, int end)
//{
//	int mid = began + (end - began) / 2;
//	if (array[mid] < array[end])
//	{
//		if (array[mid] > array[began])
//		{
//			return mid;
//		}
//		else
//			if (array[end] > array[began])
//			{
//				return end;
//			}
//			else
//				return began;
//	}
//	else
//		if (array[mid] < array[began])
//		{
//			return mid;
//		}
//		else
//			if (array[end] > array[began])
//				return end;
//			else
//				return began;
//}
////��������
////hore��
//int postion(int* array, int began, int end)
//{
//	int mid = getmid(array, began, end);
//	Swap(array, mid, began);
//	int start = began;
//	int key = start;
//	while (began < end)
//	{
//		//���������ҵ�һ��С�ڻ�׼ֵ����
//		while (began<end && array[end]>=array[key])
//		{
//			end--;
//		}
//		while (began < end && array[began] <= array[key])
//		{
//			began++;
//		}
//		Swap(array, began, end);
//	}
//	Swap(array, start, began);
//	return began;
//}
//
//void quicksort(int* array, int began, int end)
//{
//	if (began > end)
//		return;
//	int pos = postion(array, began, end);
//	quicksort(array, began, pos - 1);
//	quicksort(array, pos + 1, end);
//	
//}


//�鲢����
//�ϲ�����Ҫ֪���������������е����� ��began,mid] , [mid+1,end]
void merge(int* array, int began, int mid, int end, int* tmp)
{
	int began1 = began, end1 = mid, began2 = mid + 1, end2 = end;
	int idx = began;
	while (began1 <= end1 && began2 <= end2)
	{
		if (array[began1] <= array[began2])
		{
			tmp[idx++] = array[began1++];
		}
		else
		{
			tmp[idx++] = array[began2++];
		}
	}

	//�ж��Ƿ���ʣ��Ԫ��
	if (began1 <= end1)
		memcpy(tmp + idx, array + began1, sizeof(int) * (end1 - began1 + 1));
	if (began2 <= end2)
		memcpy(tmp + idx, array + began2, sizeof(int) * (end2 - began2 + 1));
	memcpy(array+began, tmp+began, sizeof(int) * (end - began + 1));
}

void mergesort(int* array, int began, int end, int* tmp)
{
	int mid = began + (end - began) / 2;
	if (began >= end)
		return;
	//d������������
	mergesort(array, began, mid, tmp);
	mergesort(array, mid + 1, end, tmp);
	//�ϲ�
	merge(array, began, mid, end, tmp);
}
int main()
{
	int array[] = { 10,8,14,13,8,9,7,6,8,10,11,9,13 };
	int size = sizeof(array) / sizeof(array[0]);
	int* tmp = (int*)malloc(sizeof(int) * size);
	//insertsort(array, size);
	//shellsort(array, size);
	//selectsort(array, size);
	//bubblesort(array, size);
	//heapsort(array, size);
	//quicksort(array, 0, size - 1);
	mergesort(array, 0, size - 1, tmp);
	free(tmp);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	return 0;
}