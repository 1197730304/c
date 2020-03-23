#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//void replace(char arr[], int length)
//{
//	char array[100] = { 0 };
//	int j = 0;
//	for (int i = 0; i < length; )
//	{
//		if (arr[i] != ' ')
//		{
//			array[j] = arr[i];
//			i++;
//			j++;
//		}
//		if (arr[i] == ' ')
//		{
//			array[j] = '%';
//			j++;
//			array[j] = '2';
//			j++;
//			array[j] = '0';
//			i++;
//			j++;
//		}
//	}
//	array[j] = '\0';
//	strcpy(arr, array);
//	return arr;
//}
//int main()
//{
//	char a[100] = "hello world haha";
//	replace(a, 16);
//	printf("%s", a);
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int n = 0;
//	int arr[1001] = { 0 };
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (int i = n; i >= 1; i--)
//	{
//		for (int j = 1; j < i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int t = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = t;
//			}
//			continue;
//		}
//	}
//	long int sum = 1;
//	for (int j = 1; j <= n; j++)
//	{
//		sum *= (arr[j] - j + 1);
//		sum %= 1000000007;
//	}
//	printf("%d\n", sum);
//	return 0;
//}