#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int search(int x,int a[],int N)
{
	int j = 0;
	int low = 0;
	int sz = sizeof(a) / sizeof(a[0]);
	int high = N-1;
	while (low < high) {
		int mid = (low + high) / 2;
		if (a[mid] > x)
		{
			high = mid - 1;
		}
		else if (a[mid] < x)
		{
			low = mid + 1;
			//printf("û���ҵ�\n");
		}
		else
		{
			printf("�ҵ���,�����±���:%d\n", mid); 
			break;
		}	
	}
	if (low = high)
	{
		printf("�Ҳ���");
	}
}   
//}
int main()
{
	int arr[10] = { 0 };
	int i = 0;
	int n;
	printf("������10�����������:\n");
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("������Ҫ���ҵ�����:\n");
	scanf("%d", &n);
	search(n, arr, 10);
	return 0;
}

//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	int n;
//	printf("������10�����������:\n");
//	for (i = 0; i < 10; i++)
//	{
//     scanf("%d", &arr[i]);
//	}
//	printf("������Ҫ���ҵ�����:\n");
//	scanf("%d", &n);
//	for (i = 0; i < 10; i++)
//	{
//		if (arr[i] == n)
//		{
//			printf("�ҵ���,�����±���:%d\n", i); break;
//		}
//		else if (i==9) {
//			printf("�Ҳ���");
//		}
//
//	}
//	return 0;
//}