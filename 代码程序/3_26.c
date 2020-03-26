#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1.打印无重复的字符
//int main()
//{
//	char arr1[1000] = { 0 };
//	gets(arr1);
//	char num[23] = { 0 };
//	int sz = strlen(arr1);
//	for (int i = 0; i < sz; i++)
//	{
//		if (num[arr1[i] - 97] == 0)
//		{
//			printf("%c", arr1[i]);
//		num[arr1[i] - 97] = 1;
//
//		}
//
//	}
//	
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//int my_sort(int s[], int len)
//{
//	for (int i = 1; i < len; i++)
//	{
//		int j = i;
//		while (j > 0 && s[j] < s[j - 1])
//		{
//			int t = s[j];
//			s[j] = s[j - 1];
//			s[j - 1] = t;
//			j--;
//		}
//	}
//	return s[2];
//}
//int main()
//{
//	int arr[4] = { 0 };
//	int sum = 0;
//	for (int i = 0; i < 4; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int ave = my_sort(arr, 4);
//	int s[4] = { 0 };
//	for (int i = 0; i < 4; i++)
//	{
//		s[i] = abs(arr[i] - ave);
//		sum += s[i];
//	}
//	printf("%d\n", sum);
//
//	return 0;
//}

