/******************************************************************
* Name：象棋將死
*
* Goal：考慮一個像棋殘局，其中紅方有n（2≤n≤7）個棋子，黑方只有一個將。紅方除了有一個
*		帥（G）之外還有3種可能的棋子：車（R），馬（H），炮（C），並且需要考慮“蹩馬
*		腿”（如圖4-4所示）與將和帥不能照面（將、帥如果同在一條直線上，中間又不隔著任何棋
*		子的情況下，走子的一方獲勝）的規則。
*		輸入所有棋子的位置，保證局面合法並且紅方已經將軍。你的任務是判斷紅方是否已經
*		把黑方將死。關於中國象棋的相關規則請參見原題。
*
* Modify record：18/11/12 By Lucas
******************************************************************/

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

int map[8][9];
char pawn[99][9];

int Horse_ham(int x, int y, int key)
{
	/*
	1	2	3
	4	*	6
	7	8	9
	*/
	switch (key)
	{

	case 1:
		if (map[x - 1][y - 1])
			return 1;
	case 2:
		if (map[x][y - 1])
			return 2;
	case 3:
		if (map[x + 1][y - 1])
			return 3;
	case 4:
		if (map[x - 1][y])
			return 4;
	case 6:
		if (map[x + 1][y])
			return 6;
	case 7:
		if (map[x - 1][y + 1])
			return 7;
	case 8:
		if (map[x][y + 1])
			return 8;
	case 9:
		if (map[x + 1][y + 1])
			return 9;
	default:
		break;
	}
	return 0;
}

int Check_Horse(int x, int y)
{
	// 左
	if (map[x - 2][y + 1] == 2)
		if (Horse_ham(x, y, 1) == 0)
			return 1;
	if (map[x - 2][y - 1] == 2)
		if (Horse_ham(x, y, 7) == 0)
			return 1;
	//右
	if (map[x + 2][y + 1] == 2)
		if (Horse_ham(x, y, 3) == 0)
			return 1;
	if (map[x + 2][y - 1] == 2)
		if (Horse_ham(x, y, 9) == 0)
			return 1;
	//下
	if (map[x + 1][y + 2] == 2)
		if (Horse_ham(x, y, 7) == 0)
			return 1;
	if (map[x - 1][y + 2] == 2)
		if (Horse_ham(x, y, 9) == 0)
			return 1;
	//上
	if (map[x + 1][y - 2] == 2)
		if (Horse_ham(x, y, 3) == 0)
			return 1;
	if (map[x - 1][y - 2] == 2)
		if (Horse_ham(x, y, 1) == 0)
			return 1;

	return 0;
}

int Check_General(int x, int y)
{
	// 左到右
	for (int i = 0; i < x; i++)
	{
		int mark = 0;
		switch (map[i][y])
		{
		case 1: //車
			for (int Car = i; Car < x; Car++)
				if (map[Car][y] != 0)
					mark = 1;
			if (mark)
				break;
			else
				return 1;
		case 3:
			for (int Cannon = i; Cannon < x; Cannon++)
				if (map[Cannon][y] != 0)
					mark++;
			if (mark != 1)
				break;
			else
				return 1;
		case 99:
			for (int i = 0; i < y; i++)
				if (map[x][i] != 0)
					break;
		default:
			break;
		}
	}
	// 右到左
	for (int i = 8; i > x; i--)
	{
		int mark = 0;
		switch (map[i][y])
		{
		case 1: //車
			for (int Car = i; Car > x; Car--)
				if (map[Car][y] != 0)
					mark = 1;
			if (mark)
				break;
			else
				return 1;
		case 3:
			for (int Cannon = i; Cannon > x; Cannon--)
				if (map[Cannon][y] != 0)
					mark++;
			if (mark != 1)
				break;
			else
				return 1;
		default:
			break;
		}
	}
	// 上到下
	for (int i = 0; i < y; i++)
	{
		int mark = 0;
		switch (map[x][i])
		{
		case 1: //車
			for (int Car = i; Car < y; Car++)
				if (map[x][Car] != 0)
					mark = 1;
			if (mark)
				break;
			else
				return 1;
		case 3:
			for (int Cannon = i; Cannon < y; Cannon++)
				if (map[x][Cannon] != 0)
					mark++;
			if (mark != 1)
				break;
			else
				return 1;
		default:
			break;
		}
	}
	// 下到上
	for (int i = 9; i > y; i--)
	{
		int mark = 0;
		switch (map[x][i])
		{
		case 1:
			for (int Car = i; Car > y; Car--)
				if (map[x][Car] != 0)
					mark = 1;
			if (mark)
				break;
			else
				return 1;
		case 3:
			for (int Cannon = i; Cannon > y; Cannon--)
				if (map[x][Cannon] != 0)
					mark++;
			if (mark != 1)
				break;
			else
				return 1;
		default:
			break;
		}
	}

	return 0;
}

void save_location(int i, int n, int count)
{
	int x, y;
	char X[9], Y[9];
	char Pawn[4][99] = {"Car", "Horse", "Cannon", "General"};

	printf("please enter %s(%d) location x =", Pawn[i], n);
	scanf("%s", X);
	printf("please enter %s(%d) location y =", Pawn[i], n);
	scanf("%s", Y);
	if (map[X[0] - 48][Y[0] - 48] != 0)
		printf("the location is taken.\n");
	else
		map[X[0] - 48][Y[0] - 48] = count + 1;
}

int main()
{
	int n, Car, Horse, Cannon, x, y, count, sum = 1;

	memset(map, 0, sizeof(map) / sizeof(int));
	printf("please enter the red pawn numbers:");
	scanf("%d", &n);
	printf("the Car number:");
	scanf("%d", &Car);
	printf("the horse number:");
	scanf("%d", &Horse);

	printf("the Cannon:");
	scanf("%d", &Cannon);

	// Car =1
	// Horse = 2
	// Cannon= 3
	// Red_General = 99
	// Black_General = 66

	if (Cannon + Horse + Car != n)
	{
		printf("Error");
		return 0;
	}

	for (int i = 0; i < n; i++)
		if (i < Car)
			save_location(0, i + 1, i);
		else if (i < Horse + Car)
			save_location(1, i % Horse + 1, i);
		else if (i < Horse + Car + Cannon)
			save_location(2, i % Cannon + 1, i);
	save_location(3, 1, 99);
	save_location(3, 2, 66);

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 9; j++)
			if (map[i][j] == 66)
			{
				if (i < 5)
					sum *= Check_General(i + 1, j);
				if (i > 4)
					sum *= Check_General(i - 1, j);
				if (j > 0)
					sum *= Check_General(i, j + 1);
				if (j < 2)
					sum *= Check_General(i, j - 1);
			}
	if (sum)
		printf("Yes");

	system("pause");
	return 0;
}
