#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<time.h>
#include<vector>
#include<list>
using namespace std;
void Print(int* array, int len)
{
		for (int i = 0; i < len; ++i)
		{
			printf("%d ",array[i]);
		}
		cout << endl;
}
//1.��������
void Insert_Sort(int* arr, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		int end = i;
		int key = arr[end+1];
		//��end��ǰ�ұ�key��ģ�ֱ���ҵ�һ��keyС������ѭ������
		while (key < arr[end]&&end>=0)
		{
			arr[end+1] = arr[end];
			--end;
		}
		arr[end+1] = key;
	}
}

//2.ϣ������
void Shell_Sort(int* array, int len)
{
	//ȷ��gap����ʾһ���೤
	int gap = len;
	//���ֲ�������
	while(gap>1)
	{
		gap = gap / 3 + 1;
		//һ�ֲ������򣬲���Ϊgap
		for (int i = 0; i < len-gap; ++i)
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

//3.ѡ������
//��������
void Swap(int* array, int left, int right)
{
	int temp = array[left];
	array[left] = array[right];
	array[right] = temp;
}
void Select_Sort(int* array, int len)
{
	//�Ӵ������������ҳ���С����Ȼ�������������ĺ�һλ���н���
	for (int i = 0; i < len; i++)
	{
		int end = i;
		int min = end;
		for (int j = end + 1; j < len; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		Swap(array, min, i);
		
	}
}

//4.ð������
void Bubble_Sort(int* array, int len)
{
	for (int i = len - 1; i >= 0; i--)
	{
		int flag = 1;//�˴��ı����Ϊ�˷�ֹ�Ѿ���������У�������ǰ�˳�����������
		for (int j = 0; j < i; j++)
		{
			//�����Ƚϣ������Ľ�������һ�����бȽϣ�����������
			if (array[j] > array[j + 1])
			{
				flag = 0;
				Swap(array, j, j + 1);
			}
		}
		if (flag)
		{
			break;
		}
	}
}
//5.������
//��ѵĵ���
void Heap_ShiftDown(int* array, int n, int parent)
{
	int children = 2 * parent + 1;
	while (children < n)
	{
		//��������ȡ�ϴ�ֵ���͸��ڵ���бȽ�
		if (children + 1 < n && array[children + 1] > array[children])
		{
			++children;
		}
		if (array[parent] < array[children])
		{
			Swap(array, parent, children);
			parent = children;
			children = 2 * children + 1;

		}
		else
			break;
	}
}

void Heap_Sort(int* array, int len)
{
	//��һ��������
	for (int i = (len - 2) / 2; i >= 0; i--)
	{
		Heap_ShiftDown(array,len,i);
	}
	//ѭ��βɾ
	for (int i = len-1; i > 0; i--)
	{
		Swap(array, 0, len - 1);
		--len;
		Heap_ShiftDown(array, len, 0);
	}
}

//6.��������
//������
int partion(int* array, int begin, int end)
{
	int key = array[begin];
	int start = begin;
	while (begin < end)
	{

		while (key <= array[end] && begin < end)
		{
			end--;
		}
		while (key >= array[begin] && begin < end)
		{
			begin++;
		}
	//����
		Swap(array, begin, end);
	}
	Swap(array, start, begin);
	return begin;
}
void Quick_Sort(int* array, int begin, int end)
{
	if (begin >= end)
		return;
	int keypos = partion(array, begin, end);
	Quick_Sort(array, begin, keypos-1);
	Quick_Sort(array, keypos + 1, end);

}

//7.�鲢����
//�ϲ��� ��Ҫ֪���������������е�����: [begin, mid]  [mid + 1, end]

void Merge(int* array, int begin,int mid,int end,int* tmp)
{
	int begin1 = begin, end1 = mid, begin2 = mid + 1, end2 = end;
	int idx = begin;
	//�ϲ�
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (array[begin1] <= array[begin2])
		{
			tmp[idx++] = array[begin1++];
		}
		else
			tmp[idx++] = array[begin2++];
	}
	//�鿴�Ƿ���ʣ��Ԫ��
	if (begin1 <= end1)
		memcpy(tmp + idx, array + begin1, sizeof(int) * (end1 - begin1 + 1));
	if(begin2<=end2)
		memcpy(tmp + idx, array + begin2, sizeof(int) * (end2 - begin2 + 1));

	//������ԭʼ�ռ�
	memcpy(array + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}

void MergeSortR(int* array, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;
	int mid = begin + (end - begin) / 2;
	//����ȷ������������
	MergeSortR(array, begin, mid,tmp);
	MergeSortR(array, mid + 1, end, tmp);

	//��ζ������������������
	Merge(array, begin, mid,end,tmp);
}

void Merge_Sort(int* array, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	MergeSortR(array, 0, n - 1, tmp);
	free(tmp);
}

//8.��������
void Count_Sort(int* array, int n)
{
	int max = array[0], min = array[0];
	for (int i = 0; i < n; i++)
	{
		if (array[i] > max)
			max = array[i];
		if (array[i] < min)
			min = array[i];
	}
	//ȷ��������С
	int range = max - min + 1;
	//�������ռ���м���	
	int* CountArr = (int*)malloc(sizeof(int) * range);
	//������ȫ������
	memset(CountArr, 0, sizeof(int) * range);
	//ͳ�����ݴ���
	for (int i = 0; i < n; i++)
	{
		CountArr[array[i] - min]++;
	}
	//�ָ���������
	int idx = 0;

	for (int i = 0; i < range; i++)
	{
		while (CountArr[i]--)
		{
			array[idx++] = i + min;
		}
	}
	free(CountArr);
}


//8.Ͱ����


int main()
{
	int n = 10;
	int arr[10];
	srand((unsigned int)time(NULL));//���������
	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand() % 20;
	}
	cout << "����ǰ������Ԫ�أ�" << endl;
		Print(arr, 10);
		//Insert_Sort(arr, 10);
		//Shell_Sort(arr,10);
		//Select_Sort(arr, 10);
		//Bubble_Sort(arr, 10);
		//Heap_Sort(arr, 10);
		//Quick_Sort(arr, 0, 9);
		//Merge_Sort(arr,10);
		//Count_Sort(arr, 10);
		bucketSort(arr, 10);
		cout << "����ĺ�����Ԫ�أ�" << endl;
		Print(arr, 10);
	return 0;
}