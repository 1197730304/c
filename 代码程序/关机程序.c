#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char input[30];
		//1.关机
		system("shutdown /s /t 60");
	//
again:
	printf("请注意!你的电脑将在60秒后关机,请输入:我是猪,就取消关机\n");
	scanf("%s", input);

	if (strcmp(input, "我是猪") == 0)
	{
		system("shutdown/a");
	}
	else
	{
		goto again;
	}
	return 0;

}

