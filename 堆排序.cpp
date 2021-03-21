//堆排序
#include<iostream>
using namespace std;
//大堆的向下调整
void heap_shift(int arr[], int n, int parent)
{
	int child = 2 * parent+1;
	while (child < n)
	{
		if (arr[child] < arr[child + 1] && child < n - 1)
		{
			child++;
		}
		if (arr[child] > arr[parent])
		{
			swap(arr[child], arr[parent]);
			parent = child;
			child = 2 * child + 1;
		}
		else
			break;
	}
}

void heapsort(int arr[], int len)
{
	//建堆,从最后一个非叶子节点自底向上
	for (int i = (len - 2)/2; i >= 0; i--)
	{
		heap_shift(arr, len, i);
	}

	//循环尾删
	for (int i = len - 1; i >= 0; i--)
	{
		swap(arr[len-1], arr[0]);
		len--;
		heap_shift(arr, len, 0);
	}
}
int main()
{
	int n;
	srand((unsigned int)time(NULL));
	cout << "输入个数：";
	cin >> n;
	int* p = new int[n];
	for (int i = 0; i < n; i++)
	{
		p[i] = rand() % n;
		cout << p[i] << " ";
	}
	cout << endl;
	heapsort(p, n);
	for (int i=0;i<n;i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;

	return 0;
}