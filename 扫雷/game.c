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
	printf("-------------ɨ��--------------\n");
	//��ӡ�����
	for (i = 0; i <= row; i++)
	{
		printf(" %d ", i);
	}
	printf("\n");

	for (i = 1; i <= row; i++)
	{
		int j = 0;
		printf(" %d ", i); //��ӡ�����
		for (j = 1; j <= col; j++)
		{
			printf(" %c ", board[i][j]);
		}
		printf("\n");
	}
	printf("-------------ɨ��--------------\n");
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
	int sum1 = 9;//����ĸ���
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
	//1.�����Ų��׵�����
	//2.�Ų����괦�ǲ�����
	   //(1)����-�㱻ը����
	   //(2)������-ͳ����Χ�м�������-�洢�Ų��׵���Ϣ��show���飬��Ϸ����
	int x = 0;
	int y = 0;
	int count = 0;
	int win = 0;

	while (row*col-COUNT)
	{
		printf("��Ҫ�Ų��׵�����:>");
		scanf("%d%d", &x, &y);

		//�ж�����ĺϷ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("ɵ��,�㱻ը����!");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				//�����׵������
				int count = get_mine(mine, x, y);
				show[x][y] = count + '0';
				//��ʾ�Ų������Ϣ
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("���겻�Ϸ�,����������!");
		}
	}
	if (win == row * col - COUNT)
	{
		printf("���׳ɹ�!");
	}
}