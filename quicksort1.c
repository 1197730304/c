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
	//���û�׼ֵ
	int key = begin;
	while (begin < end)
	{
		//���������ҵ�һ��С�ڻ�׼ֵ����
		while (begin<end && array[end]>=array[key])
		{
			end--;
		}
		//���������ҵ�һ�����ڻ�׼ֵ����
		while (begin < end && array[begin] <= array[key])
		{
			begin++;
		}
		//�����ղ�����ֵ
		Swap(array, begin, end);
	}
	//������׼ֵ������λ�õ�ֵ
	Swap(array, key, begin);
	return begin;
}

void quicksort1(int* array, int begin, int end)
{
	if (begin > end)
		return;
	int pos = postion(array, begin, end);
	quicksort1(array, begin, pos - 1);
	quicksort1(array, pos + 1, end);
}

int main()
{
	int array[] = { 14,15,12,13,10,11,5,8,7,6,5,1,2,11,15 };
	int size = sizeof(array) / sizeof(array[0]);
	quicksort1(array, 0, size - 1);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	return 0;
}