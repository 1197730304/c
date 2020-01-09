//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//void Bubble_sort(int arr[], int sz)
//{
//	int j = 0;
//	for (j = 0; j < sz-1; j++)
//	{
//		for (int k = 0; k <sz-j-1; k++)
//		{
//			if (arr[k] > arr[k + 1])
//			{
//				int temp = arr[k];
//				arr[k] = arr[k+ 1];
//				arr[k + 1] = temp;
//			}
//		}
//	}
//		
//}
//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	printf("请输入十个待排序数：\n");
//	for ( i = 0; i < sz; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	Bubble_sort(arr, sz);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d\n", arr[i]);
//	}
//	
//	
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int arr[] = { 0 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 1; i <= sz; i++)
	{
		scanf("%d", &arr[i]);
	}
	return 0;
}