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
//1.插入排序
void Insert_Sort(int* arr, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		int end = i;
		int key = arr[end+1];
		//从end向前找比key大的，直到找到一个key小的跳出循环插入
		while (key < arr[end]&&end>=0)
		{
			arr[end+1] = arr[end];
			--end;
		}
		arr[end+1] = key;
	}
}

//2.希尔排序
void Shell_Sort(int* array, int len)
{
	//确定gap，表示一步多长
	int gap = len;
	//多轮插入排序
	while(gap>1)
	{
		gap = gap / 3 + 1;
		//一轮插入排序，步长为gap
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

//3.选择排序
//交换函数
void Swap(int* array, int left, int right)
{
	int temp = array[left];
	array[left] = array[right];
	array[right] = temp;
}
void Select_Sort(int* array, int len)
{
	//从待排序序列中找出最小的数然后和已排序的数的后一位进行交换
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

//4.冒泡排序
void Bubble_Sort(int* array, int len)
{
	for (int i = len - 1; i >= 0; i--)
	{
		int flag = 1;//此处的标记是为了防止已经排序的数列，可以提前退出，减少运算
		for (int j = 0; j < i; j++)
		{
			//两两比较，将最大的交换和下一个进行比较，最后完成排序
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
//5.堆排序
//大堆的调整
void Heap_ShiftDown(int* array, int n, int parent)
{
	int children = 2 * parent + 1;
	while (children < n)
	{
		//左右子树取较大值，和父节点进行比较
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
	//第一步：建堆
	for (int i = (len - 2) / 2; i >= 0; i--)
	{
		Heap_ShiftDown(array,len,i);
	}
	//循环尾删
	for (int i = len-1; i > 0; i--)
	{
		Swap(array, 0, len - 1);
		--len;
		Heap_ShiftDown(array, len, 0);
	}
}

//6.快速排序
//霍尔法
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
	//交换
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

//7.归并排序
//合并： 需要知道两个有序子序列的区间: [begin, mid]  [mid + 1, end]

void Merge(int* array, int begin,int mid,int end,int* tmp)
{
	int begin1 = begin, end1 = mid, begin2 = mid + 1, end2 = end;
	int idx = begin;
	//合并
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (array[begin1] <= array[begin2])
		{
			tmp[idx++] = array[begin1++];
		}
		else
			tmp[idx++] = array[begin2++];
	}
	//查看是否还有剩余元素
	if (begin1 <= end1)
		memcpy(tmp + idx, array + begin1, sizeof(int) * (end1 - begin1 + 1));
	if(begin2<=end2)
		memcpy(tmp + idx, array + begin2, sizeof(int) * (end2 - begin2 + 1));

	//拷贝到原始空间
	memcpy(array + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}

void MergeSortR(int* array, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;
	int mid = begin + (end - begin) / 2;
	//首先确保子区间有序
	MergeSortR(array, begin, mid,tmp);
	MergeSortR(array, mid + 1, end, tmp);

	//其次对有序子区间进行排序
	Merge(array, begin, mid,end,tmp);
}

void Merge_Sort(int* array, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	MergeSortR(array, 0, n - 1, tmp);
	free(tmp);
}

//8.计数排序
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
	//确定容量大小
	int range = max - min + 1;
	//开辅助空间进行计数	
	int* CountArr = (int*)malloc(sizeof(int) * range);
	//将数组全部清零
	memset(CountArr, 0, sizeof(int) * range);
	//统计数据次数
	for (int i = 0; i < n; i++)
	{
		CountArr[array[i] - min]++;
	}
	//恢复队列数据
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


//8.桶排序


int main()
{
	int n = 10;
	int arr[10];
	srand((unsigned int)time(NULL));//产生随机数
	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand() % 20;
	}
	cout << "排序前的数组元素：" << endl;
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
		cout << "排序的后数组元素：" << endl;
		Print(arr, 10);
	return 0;
}