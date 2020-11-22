#include<iostream>
using namespace std;

bool isExist(int arr[][4], int n)
{
	int i = 0, j = 3;
	while (i <= 3 && j >= 0)
	{
		int key = arr[i][j];
		if (n < key)
		{
			j--;
		}
		else if (n > key)
		{
			i++;
		}
		else
			return true;
	}
	return false;
}
int main()
{
	int arr[][4] = { 1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,14 };
	int n;
	cin >> n;;
	cout<<isExist(arr, n)<<endl;
	return 0;
}