#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"game.h"

void game()
{
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	char ret = 0;
	while (1)
	{
		//玩家走
		PiayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断输赢
		ret = IsWin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
		//电脑走
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else if(ret=='Q')
	{
		printf("平局\n");


	}
}
void menu()
{
	printf("***************************\n");
	printf("****欢迎来到三子棋游戏*****\n");
	printf("*****     1.play      *****\n");
	printf("*****     0.exit      *****\n");
	printf("***************************\n");
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));//生成随机数
	do
	{
		menu();
		printf("请输入你的选择：\n");
			scanf("%d", &input);
			switch (input)
			{
			case 1:
				game();
				break;
			case 0:
				printf("退出游戏");
				break;
			default:
				printf("输入错误");
				break;
			}

	} while (input);
	
}
int main()
{
	test();
		return 0;
}