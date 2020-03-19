#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int sort(int x)
{
	int count = 0;
	int p[10] = { 0 };
	int q = 0;
	while (x > 0)
	{
		p[count] = x % 10;
		x /= 10;
		count++;
	}
	for (int i = count - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (p[j] < p[j + 1])
			{
				int t = p[j];
				p[j] = p[j + 1];
				p[j + 1] = t;
			}
		}
	}
	int h = 0;
	for (int k = 0; k < count; k++)
	{
			h = pow(10, k);

		q += (p[count-1-k] * h);
	}
	return q;
}
int main()
{
	int n = 0;
	int x[50] = { 0 };
	int x1[50] = { 0 };
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x[i]);
		x1[i] = sort(x[i]);
	}
	int max = x1[0];
	for (int j = 0; j < n; j++)
	{
		if (max < x1[j])
		{
			max = x1[j];
		}
		continue;
	}
	printf("%d\n", max);

	return 0;
}