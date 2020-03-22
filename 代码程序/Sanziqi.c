#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"game.h"

void game()
{
	char board[ROW][COL] = { 0 };
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);
	char ret = 0;
	while (1)
	{
		//�����
		PiayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж���Ӯ
		ret = IsWin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
		//������
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
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else if(ret=='Q')
	{
		printf("ƽ��\n");


	}
}
void menu()
{
	printf("***************************\n");
	printf("****��ӭ������������Ϸ*****\n");
	printf("*****     1.play      *****\n");
	printf("*****     0.exit      *****\n");
	printf("***************************\n");
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));//���������
	do
	{
		menu();
		printf("���������ѡ��\n");
			scanf("%d", &input);
			switch (input)
			{
			case 1:
				game();
				break;
			case 0:
				printf("�˳���Ϸ");
				break;
			default:
				printf("�������");
				break;
			}

	} while (input);
	
}
int main()
{
	test();
		return 0;
}