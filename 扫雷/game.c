#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	for (i = 0; i < rows; i++)
	{
		int j = 0;
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	printf("-------------扫雷--------------\n");
	//打印列序号
	for (i = 0; i <= row; i++)
	{
		printf(" %d ", i);
	}
	printf("\n");

	for (i = 1; i <= row; i++)
	{
		int j = 0;
		printf(" %d ", i); //打印行序号
		for (j = 1; j <= col; j++)
		{
			printf(" %c ", board[i][j]);
		}
		printf("\n");
	}
	printf("-------------扫雷--------------\n");
}

void SetMine(char mine[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = COUNT;
	while (count)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
		}
		count--;
	}
}

char get_mine(char mine[ROWS][COLS], char x, char y)
{
	int i = 0;
	int sum = 0;
	int sum1 = 9;//坐标的个数
	for (i = x - 1; i <= x + 1; i++)
	{
		int j = 0;
		for (j = y - 1; j <= y + 1; j++)
			sum += mine[i][j];
	}
	if (mine[x][y] == '1')
	{
		sum = sum - 1;
		sum1 = sum1 - 1;
	}
	return (sum - sum1 * '0');
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	//1.输入排查雷的坐标
	//2.排查坐标处是不是雷
	   //(1)是雷-你被炸死了
	   //(2)不是雷-统计周围有几个坐标-存储排查雷的信息到show数组，游戏继续
	int x = 0;
	int y = 0;
	int count = 0;
	int win = 0;

	while (row*col-COUNT)
	{
		printf("需要排查雷的坐标:>");
		scanf("%d%d", &x, &y);

		//判断坐标的合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("傻逼,你被炸死了!");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				//不是雷的情况下
				int count = get_mine(mine, x, y);
				show[x][y] = count + '0';
				//显示排查出的信息
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("坐标不合法,请重新输入!");
		}
	}
	if (win == row * col - COUNT)
	{
		printf("排雷成功!");
	}
}