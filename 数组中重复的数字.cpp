#include<iostream>
#include<time.h>
#include<vector>

using namespace std;
void print(int arr[],int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//void Findnumber(int arr[],int n)
//{
//	int p[256] = { 0 };
//	for (int i = 0; i < n; i++)
//	{
//		p[arr[i]]++;
//		if (p[arr[i]] == 2)
//		{
//			cout << arr[i] << " ";
//		}
//		else
//			continue;
//	}
//}

//void Findnumber(int arr[], int n)
//{
//	if (arr == nullptr || n <= 0)
//		return;
//	for (int i = 0; i < n; i++)
//	{
//		if (arr[i] != i)
//		{
//			if (arr[i] == arr[arr[i]])
//				cout << arr[i] << " ";
//			else
//			{
//				swap(arr[i], arr[arr[i]]);
//			}
//		}
//		else
//			continue;
//	}
//}

	int getcount(const int arr[], int n, int start, int end)
	{
		if (arr == nullptr)
			return 0;
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] >= start && arr[i] <= end)
				++count;
		}
		return count;
	}
int getNumber(const int arr[], int n)
{
	if (arr == nullptr || n <= 0)
		return -1;
	int start = 1;
	int end = n - 1;
	while (end >= start)
	{
		int mid = (end - start) / 2 + start;
		int count = getcount(arr, n, start, mid);
		if (end == start)
		{
			if (count > 1)
			{
			return start;
			}

			else
				break;
		}
		if (count > (mid - start + 1))
		{
			end = mid;
		}
		else
			start = mid + 1;
	}
	return -1;
}




int main()
{
	srand((unsigned int)time(NULL));
	int n;
	cin >> n;
	int* array = new int[n];
	for (int i = 0; i < n; i++)
	{
		array[i] = rand() % n;
	}
	print(array,n);

	getNumber(array,n);
	return 0;
}