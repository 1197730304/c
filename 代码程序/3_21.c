#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//1.左旋一次的函数
void Leftsort(char* p,int len)
{
	if (len == 1)
	{
		return;
	}
	char c = p[0];
	for (int i = 1; i < len; i++)
	{
		p[i - 1] = p[i];
	}
	p[len - 1] = c;
	return p;
}
//左旋k次
void my_sort(char* p, int l,int len)
{
	for (int k = 0; k < l%len; k++)
	{
		Leftsort(p, len);
	}
	return p;
}
int main()
{
	char arr[] = "abcde";
	int n = 0;
	printf("请输入左旋的次数：\n");
	scanf("%d", &n);
	my_sort(arr, n,5);
	printf("%s\n", arr);
}