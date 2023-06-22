#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//菜单
void menu()
{
	printf("*******************************\n");
	printf("****** 1.游戏开始 0.退出*******\n");
	printf("*******************************\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 };//存放布置好的雷的信息
	char show[ROWS][COLS] = { 0 };//存放排查出的雷的信息
	//初始化棋盘
	InitBoard(mine, ROWS, COLS,'0');//'0'
	InitBoard(show, ROWS, COLS,'#');//'#'

	//打印棋盘
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);

	//布置雷
	SetMine(mine, ROW, COL);
	DisplayBoard(mine, ROW, COL);

	//排查雷
	FindMine(mine, show, ROW, COL);
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do 
	{
		menu();
		printf("请选择:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("游戏开始!\n");
			game();
			break;
		case 0:
			printf("退出游戏!\n");
			break;
		default :
			printf("选择错误,请重新选择!\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}