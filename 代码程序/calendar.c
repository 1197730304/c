#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//�ж�����
int isleap(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return 1;
	return 0;
}

//�ж�����
int week(int year, int month, int day)
{
	//��2000��1��1��������Ϊ��׼
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

//��ӡ����
void Print(int year, int month, int day)
{
	int s1[] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int s2[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	printf(" һ  ��  ��  ��  ��  ��  ��\n");
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
	printf("��ӭ��������������������Ҫ��ѯ�������գ���xxxx xx xx)\n");
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
