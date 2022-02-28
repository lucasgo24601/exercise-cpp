/******************************************************************
* Name：PGA
*
* Goal：有一个5*5的网格，其中恰好有一个格子是空的，其他格子各有一个字母。一共有4种指
*		令：A, B, L, R，分别表示把空格上、下、左、右的相邻字母移到空格中。输入初始网格和指
*		令序列（以数字0结束），输出指令执行完毕后的网格。如果有非法指令，应输出“This
*		puzzle has no final configuration.”，
*
* Modify record：18/11/12 By Lucas
******************************************************************/

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
	char PGA[5][6] = {"TRGSJ",
					  "XDOKI",
					  "MZVLN",
					  "WPABE",
					  "UQHCE"};

	char s[99], temp;
	int y, x;

	scanf("%d %d", &y, &x);
	PGA[y][x] = ' ';
	gets(s);

	for (int i = 0; i < strlen(s); i++)
		switch (s[i])
		{
		case 'A':
			temp = PGA[y][x];
			PGA[y][x] = PGA[y - 1][x];
			PGA[--y][x] = temp;
			break;
		case 'B':
			temp = PGA[y][x];
			PGA[y][x] = PGA[y + 1][x];
			PGA[++y][x] = temp;
			break;
		case 'L':
			temp = PGA[y][x];
			PGA[y][x] = PGA[y][x - 1];
			PGA[y][--x] = temp;
			break;
		case 'R':
			temp = PGA[y][x];
			PGA[y][x] = PGA[y][x + 1];
			PGA[y][++x] = temp;
			break;
		case '0':
			for (int k = 0; k < 5; k++)
			{
				for (int j = 0; j < 6; j++)
					printf(" %c  ", PGA[k][j]);
				printf("\n\n\n");
			}
		default:
			printf("This puzzle has no final configuration.”\n");
		}

	return 0;
}
