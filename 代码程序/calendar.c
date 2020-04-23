#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//判断闰年
int isleap(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return 1;
	return 0;
}

//判断星期
int week(int year, int month, int day)
{
	//以2000年1月1日星期六为基准
	int s1[] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int s2[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int y = 2000, m = 1, d = 1;
	int week = 0;
	int sum = 0;
	while (y<year)
	{
		if (isleap(y) == 1)
		{
			sum += 366;
		}
		else
			sum += 365;
		y++;
	}
	if (isleap(year)==1)
	{
		while (m < month)
		{
			sum += s1[m - 1];
			m++;
		}
		sum += day;
	}
	if (isleap(year) == 0)
	{
		while (m<month)
		{
			sum += s2[m - 1];
			m++;
		}
		sum += day;
	}
	week = (sum + 5) % 7;
	return week;
}

//打印函数
void Print(int year, int month, int day)
{
	int s1[] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int s2[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	printf(" 一  二  三  四  五  六  日\n");
	int n=week(year, month, 1);
	if (isleap(year) == 1)
	{
		
		for (int m = 1; m <= n-1; m++)
		{
			printf("    ");
		}
		for (int d = 1; d <= s1[month - 1]; d++)
		{
			printf("%3d ", d);
			if ((d+n-1)%7 == 0)
			{
				printf("\n");
			}
		}
	}
	else
	{

		for (int m = 1; m <= n - 1; m++)
		{
			printf("    ");
		}
		for (int d = 1; d <= s2[month - 1]; d++)
		{
			printf("%3d ", d);
			if ((d+n-1) % 7 == 0)
			{
				printf("\n");
			}
		}
	}
}
int main()
{
	time_t t;
	time(&t);
	int y = 0, m = 0, d = 0;
	int n = 0;
	printf("欢迎来到万年历！请输入你要查询的年月日：（xxxx xx xx)\n");
	scanf("%d%d%d", &y, &m, &d);
	scanf("%d", &n);
	printf("%s\n", ctime(&t));
	for (int i = 0; i < n; i++)
	{
		Print(y, m+i, d);
		printf("\n");

	}
	
	
	return 0;
}
