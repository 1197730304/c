#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

//1.strncatģ��ʵ��
//char* my_strncat(char* dest, const char* source, size_t num)
//{
//	assert(dest != NULL && source != NULL);
//	int i = 0;
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//
//	for (i = 0; i < num; i++)
//	{
//		if (*source)
//		{
//		*dest = *source;
//		dest++;
//		source++;
//		}
//
//	}
//	  *dest = '\0';
//	return dest;
//}
//int main()
//{
//	char str1[20] = "hello";
//	char str2[] = "world he";
//	my_strncat(str1, str2, 7);
//	printf("%s", str1);
//}

//2.strncpyģ��ʵ��
//char* my_strncpy(char* dest, const char* scour, size_t num)
//{
//	assert(dest != NULL && scour != NULL);
//	int i = 0;
//	for (i = 0; i < num; i++)
//	{
//		*dest++ = *scour++;
//	}
//	*dest = '\0';
//	return dest;
//}
//int main()
//{
//	char str1[40] = "hello the world";
//	char str2[40];
//	my_strncpy(str2, str1, 5);
//	printf("%s\n", str2);
//	return 0;
//}

//�ҵ���
//һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Ρ�
//��дһ�������ҳ�������ֻ����һ�ε����֡�
//int main()
//{
//	int arr[100] = { 0 };
//	int arr1[100] = { 0 };
//	int p = 0;
//	int n = 0;
//	printf("������Ԫ�ظ���:\n");
//	scanf("%d", &n);
//	for (int k = 0; k < n; k++)
//	{
//		scanf("%d", &arr[k]);
//	}
//	for (int i = 0; i < n; i++)
//	{
//		arr1[arr[i]]++;
//	}
//	for (int j = 0; j < n; j++)
//	{
//		if (arr1[arr[j]] == 1)
//		{
//			printf("%d ", arr[j]);
//		}
//		continue;
//	}
//	return 0;
//
//}