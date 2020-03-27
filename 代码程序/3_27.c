#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
//int number(int x)
//{
//	int count = 0;
//	while (x > 0)
//	{
//		x /= 10;
//		count++;
//	}
//	return count;
//}
//int mycompare(int x, int p, int n)
//{
//	int k = x;
//	int q = pow(10, p);
//	for (int i = 0; i < n - 1; i++)
//	{
//		k *= q;
//		k += x;
//	}
//	return k;
//}
//int main()
//{
//	int x1, k1, x2, k2;
//	scanf("%d%d%d%d", &x1, &k1, &x2, &k2);
//	int p1 = number(x1);
//	int p2 = number(x2);
//	int m1 = mycompare(x1, p1, k1);
//	int m2 = mycompare(x2, p2, k2);
//	int a = p1 * k1;
//	int b = p2 * k2;
//	if (a > b)
//	{
//		printf("Greater\n");
//	}
//	else if (a < b)
//	{
//		printf("Less\n");
//	}
//	else
//	{
//		if (m1 == m2)
//		{
//			printf("Equal\n");
//		}
//		else if (m1 > m2)
//		{
//			printf("Greater\n");
//		}
//		else
//		{
//			printf("Less\n");
//		}
//	}
//
//	return 0;
//}
//#include<stdio.h>
//void sort(int* a, int* b, int* c)
//{
//	if (*a > * b)
//	{
//		int* t = *a;
//		*a = *b;
//		*b = t;
//	}
//	if (*a > * c)
//	{
//		int* t = *a;
//		*a = *c;
//		*c = *t;
//	}
//	if (*b > * c)
//	{
//		int* t = *b;
//		*b = *c;
//		*c = t;
//	}
//	return;
//}
//int main()
//{
//	int a, b, c;
//	scanf("%d%d%d", &a, &b, &c);
//	sort(&a, &b, &c);
//	int n = a + b;
//	int sum = 0;
//	if (a == b && n > c)
//	{
//		printf("%d\n", a + b + c);
//	}
//	else {
//		c = n - 1;
//		printf("%d\n", a + b + c);
//	}
//	return 0;
//}

#include<stdio.h>
int num(int p)
{
	int ret = 0;
	if (p < 4)
	{
		ret = p % 2;
	}
	else {
		int q = 4;
		while (q < p)
		{
			q *= 4;
		}
		q /= 4;
		ret = p / q;
		ret %= 2;
	}
	return ret;
}
int main()
{
	int t = 0;
	long int arr[100] = { 0 };
	int arr1[100] = { 0 };
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &arr[i]);
		
	}
	for (int i = 0; i < t; i++)
	{arr1[i] = num(arr[i]);
		if (arr1[i] == 1)
		{
			printf("niu\n");
		}
		else
		{
			printf("yang\n");
		}
	}

	return 0;
}

