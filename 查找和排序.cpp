#include<iostream>
using namespace std;

//��������
//int postion(int* arr,int begin,int end)
//{
//	int start = begin;
//	int key = arr[begin];
//	while (begin < end)
//	{
//		while (begin < end && arr[end] >= key)
//		{
//			end--;
//		}
//		while (begin < end && arr[begin] <= key)
//		{
//			begin++;
//		}
//		swap(arr[begin], arr[end]);
//	}
//	swap(arr[start], arr[end]);
//	return begin;
//}
//
//void quick_sort(int* arr, int begin, int end)
//{
//	if (begin >= end)
//		return;
//	int keypos = postion(arr, begin, end);
//	quick_sort(arr, begin, keypos - 1);
//	quick_sort(arr, keypos + 1, end);
//}
//int main()
//{
//	int n;
//	cin >> n;
//	srand((unsigned int)time(NULL));
//	int* p = new int[n];
//	for (int i = 0; i < n; i++)
//	{
//		p[i] = rand() % n;
//		cout << p[i] << " ";
//	}
//	cout << endl;
//	quick_sort(p, 0, n - 1);
//	for (int i = 0; i < n; i++)
//	{
//		cout << p[i] << " ";
//	}
//
//	return 0;
//}



//��10000��Ա���������������
//ʱ�临�Ӷ�ΪO(n)�������㷨�����ÿռ任ʱ���˼��
void sortAges(int* ages, int len)
{
	int* p = new int[100];
	for (int i = 0; i < 100; i++)
	{
		p[i] = 0;
	}
	for (int i = 0; i < len; i++)
	{
		p[ages[i]]++;
	}
	int idx = 0;
	for (int i = 0; i <=99; i++)
	{
		for (int j = 0; j < p[i]; j++)
		{
			ages[idx++] = i;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	srand((unsigned int)time(NULL));
	int* p = new int[n];
	for (int i = 0; i < n; i++)
	{
		p[i] = rand() % 100;
		cout << p[i] << " ";
	}
	cout << endl;

	sortAges(p, n);

	for (int i = 0; i < n; i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;

	return 0;
}