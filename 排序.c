#include<stdio.h>


//1.��������
//void insertsort(int* array, int n)
//{
//	int i;
//	for (i = 1; i <= n- 1; i++)
//	{
//		int end = i;
//		int key = array[end];
//		while (end > 1 && array[end - 1] > key)
//		{
//			array[end] = array[end - 1];
//			end--;
//		}
//		array[end] = key;
//	}
//}

//void insertsort(int* array, int n)
//{
//	int i;
//	for (i = 0; i < n - 1; i++)
//	{
//		int end = i;//end��ʾ���������ݵ����һ��λ��
//		int key = array[end + 1];//key��ʾ������Ԫ��
//		while (end >= 0 && array[end] > key)
//		{
//			array[end + 1] = array[end];
//			end--;
//		}
//		array[end + 1] = key;
//	}
//}


//2.ϣ������(���ֲ�������)
//void shellsort(int* array, int n)
//{
//	int gap = n;
//	while (gap > 1)
//	{
//		gap = gap / 3 + 1;
//	     int i;
//	    for (i = 0; i < n-gap; i++)
//	    {
//		int end = i;
//		int key = array[end + gap];
//		while (end >= 0 && array[end] > key)
//		{
//			array[end + gap] = array[end];
//			end -= gap;
//		}
//		array[end + gap] = key;
//	    }
//	}
//}

//3.ѡ������
void Swap(int* arr, int star, int end)
{
	int temp = arr[star];
	arr[star] = arr[end];
	arr[end] = temp;
}
void selectsort(int* array, int n)
{
	for (int i = 0; i < n; i++)
	{
		int start = i;
		int min = start;
		for (int j = i + 1; j < n; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		Swap(array, start, min);

	}
}

//ѡ������2
void selectsort2(int* array, int n)
{
	int start = 0;
	int end = n - 1;
	while (start < end)
	{
		int min = start;
		int max = start;
		for (int i = start+1; i <= end; i++)
		{
			if (array[min] > array[i])
				min = i;
			if(array[max] < array[i])
				max = i;
		}
		//���max==min,����
		Swap(array, start, min);
		if (max == start)
			max = min;
		Swap(array, end, max);
		start++;
		end--;
	}
}
int main()
{
	int arr[] = { 10, 2, 4, 1, 3, 6, 5, 12, 9, 10, 2 };
	selectsort2(arr, 11);
	for (int i = 0; i < 11; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}