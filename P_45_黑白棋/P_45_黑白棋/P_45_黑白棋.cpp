/******************************************************************
* Name：黑白棋
*
* Goal：你的任務是模擬黑白棋遊戲的進程。黑白棋的規則為：黑白雙方輪流放棋子，每次必須
*		讓新放的棋子“夾住”至少一枚對方棋子，然後把所有被新放棋子“夾住”的對方棋子替換成己
*		方棋子。一段連續（橫、豎或者斜向）的同色棋子被“夾住”的條件是兩端都是對方棋子（不
*		能是空位）。如圖4-6（a）所示，白棋有6個合法操作，分別為(2,3),(3,3),(3,5), (6,2),(7,3) ,
*		(7,4)。選擇在(7,3)放白棋后變成如圖4-6（b）所示效果（注意有豎向和斜向的共兩枚黑棋變
*		白）。注意(4,6)的黑色棋子雖然被夾住，但不是被新放的棋子夾住，因此不變白。
*
* Modify record：18/11/12 By Lucas
******************************************************************/

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

int map[7][7];
int Pawn_record[99];

// 黑棋=1 白棋=2;
/*
1	2	3
4	*	6
7	8	9

*/
void Display_map()
{
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 8; i++)
			printf("____");
		printf("_\n");
		for (int i = 0; i < 8; i++)
			printf("|   ");
		printf("|\n");
		for (int i = 0; i < 8; i++)
			printf("| %d ", map[j][i]);
		printf("|\n");
	}
}

int Legitimate_location(int x, int y, int key, int color, int count)
{
	//count = 1
	//count = 2
	//count = 99

	switch (key)
	{
	case 1:
		//-------------mode 99 ---------------
		if (count == 99)
		{
			map[x - 1][y - 1] = color;
			return 1;
		}
		//-------------mode 2 ---------------
		if (count > 1)
			if (count == 3)
				if (map[x - 1][y - 1] == color)
					return 1;
				else
					return 0;
			else
				return Legitimate_location(x - 1, y - 1, key, color, ++count);
		//-------------mode 1 ---------------
		if (map[x - 1][y - 1] != color & map[x - 1][y - 1] != 0)
			return Legitimate_location(x - 1, y - 1, key, color, --count);
		if (map[x - 1][y - 1] == color & count < 1)
			return 1;
		if (map[x - 1][y - 1] == 0)
			return 0;
		if (map[x - 1][y - 1] == color)
			return 0;
		break;
	case 2:
		//-------------mode 99 ---------------
		if (count == 99)
		{
			map[x][y - 1] = color;
			return 2;
		}
		//-------------mode 2 ---------------
		if (count > 1)
			if (count == 3)
				if (map[x][y - 1] == color)
					return 2;
				else
					return 0;
			else
				return Legitimate_location(x, y - 1, key, color, ++count);
		//-------------mode 1 ---------------
		if (map[x][y - 1] != color & map[x][y - 1] != 0)
			return Legitimate_location(x, y - 1, key, color, --count);
		if (map[x][y - 1] == color & count < 1)
			return 1;
		if (map[x][y - 1] == 0)
			return 0;
		if (map[x][y - 1] == color)
			return 0;
		break;
	case 3:
		//-------------mode 99 ---------------
		if (count == 99)
		{
			map[x + 1][y - 1] = color;
			return 3;
		}
		//-------------mode 2 ---------------
		if (count > 1)
			if (count == 3)
				if (map[x + 1][y - 1] == color)
					return 3;
				else
					return 0;
			else
				return Legitimate_location(x + 1, y - 1, key, color, ++count);
		//-------------mode 1 ---------------
		if (map[x + 1][y - 1] != color & map[x + 1][y - 1] != 0)
			return Legitimate_location(x + 1, y - 1, key, color, --count);
		if (map[x + 1][y - 1] == color & count < 1)
			return 1;
		if (map[x + 1][y - 1] == 0)
			return 0;
		if (map[x + 1][y - 1] == color)
			return 0;
		break;
	case 4:
		//-------------mode 99 ---------------
		if (count == 99)
		{
			map[x - 1][y] = color;
			return 4;
		}
		//-------------mode 2 ---------------
		if (count > 1)
			if (count == 3)
				if (map[x - 1][y] == color)
					return 4;
				else
					return 0;
			else
				return Legitimate_location(x - 1, y, key, color, ++count);
		//-------------mode 1 ---------------
		if (map[x - 1][y] != color & map[x - 1][y] != 0)
			return Legitimate_location(x - 1, y, key, color, --count);
		if (map[x - 1][y] == color & count < 1)
			return 1;
		if (map[x - 1][y] == 0)
			return 0;
		if (map[x - 1][y] == color)
			return 0;
		break;
	case 6:
		//-------------mode 99 ---------------
		if (count == 99)
		{
			map[x + 1][y] = color;
			return 6;
		}
		//-------------mode 2 ---------------
		if (count > 1)
			if (count == 3)
				if (map[x + 1][y] == color)
					return 6;
				else
					return 0;
			else
				return Legitimate_location(x + 1, y, key, color, ++count);
		//-------------mode 1 ---------------
		if (map[x + 1][y] != color & map[x + 1][y] != 0)
			return Legitimate_location(x + 1, y, key, color, --count);
		if (map[x + 1][y] == color & count < 1)
			return 1;
		if (map[x + 1][y] == 0)
			return 0;
		if (map[x + 1][y] == color)
			return 0;
		break;
	case 7:
		//-------------mode 99 ---------------
		if (count == 99)
		{
			map[x - 1][y + 1] = color;
			return 7;
		}
		//-------------mode 2 ---------------
		if (count > 1)
			if (count == 3)
				if (map[x - 1][y + 1] == color)
					return 7;
				else
					return 0;
			else
				return Legitimate_location(x - 1, y + 1, key, color, ++count);
		//-------------mode 1 ---------------
		if (map[x - 1][y + 1] != color & map[x - 1][y + 1] != 0)
			return Legitimate_location(x - 1, y + 1, key, color, --count);
		if (map[x - 1][y + 1] == color & count < 1)
			return 1;
		if (map[x - 1][y + 1] == 0)
			return 0;
		if (map[x - 1][y + 1] == color)
			return 0;
		break;
	case 8:
		//-------------mode 99 ---------------
		if (count == 99)
		{
			map[x][y + 1] = color;
			return 8;
		}
		//-------------mode 2 ---------------
		if (count > 1)
			if (count == 3)
				if (map[x][y + 1] == color)
					return 8;
				else
					return 0;
			else
				return Legitimate_location(x, y + 1, key, color, ++count);
		//-------------mode 1 ---------------
		if (map[x][y + 1] != color & map[x][y + 1] != 0)
			return Legitimate_location(x, y + 1, key, color, --count);
		if (map[x][y + 1] == color & count < 1)
			return 1;
		if (map[x][y + 1] == 0)
			return 0;
		if (map[x][y + 1] == color)
			return 0;
		break;
	case 9:
		//-------------mode 99 ---------------
		if (count == 99)
		{
			map[x + 1][y + 1] = color;
			return 9;
		}
		//-------------mode 2 ---------------
		if (count > 1)
			if (count == 3)
				if (map[x + 1][y + 1] == color)
					return 9;
				else
					return 0;
			else
				return Legitimate_location(x + 1, y + 1, key, color, ++count);
		//-------------mode 1 ---------------
		if (map[x + 1][y + 1] != color & map[x + 1][y + 1] != 0)
			return Legitimate_location(x + 1, y + 1, key, color, --count);
		if (map[x + 1][y + 1] == color & count < 1)
			return 1;
		if (map[x + 1][y + 1] == 0)
			return 0;
		if (map[x + 1][y + 1] == color)
			return 0;
		break;
	default:
		break;
	}
}
void Detect(int Black_White, int *record)
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			for (int k = 0; k < 10; k++)
				if (Legitimate_location(i, j, k, Black_White, 1))
				{
					Pawn_record[*record++] = i;
					Pawn_record[*record++] = j;
					break;
				}
}
void insert(int x, int y, int Black_White, int record)
{
	Detect(Black_White, &record);
	for (int i = 0; i < record; i++)
		if (Pawn_record[i] == x & Pawn_record[++i] == y)
		{
			map[x][y] = Black_White;
			break;
		}

	for (int i = 0; i < 10; i++)
		if (Legitimate_location(x, y, i, Black_White, 2))
			Legitimate_location(x, y, i, Black_White, 99);
}
int main()
{
	char key[9];
	int Black_White, count = 0, record = 0;
	while (scanf("%s", &key) != EOF)
	{
		Black_White = ++count % 2 + 1;
		record = 0;
		switch (key[0])
		{
		case 'L':
			if (count == 1)
			{
				printf("ALL\n");
				break;
			}
			if (count == 2)
			{
				for (int i = 0; i < 8; i++)
					for (int j = 0; j < 8; j++)
						if (map[i][j] != 0)
						{
							printf("(%d,%d) ", i - 1, j - 1);
							printf("(%d,%d) ", i - 1, j);
							printf("(%d,%d) ", i - 1, j + 1);
							printf("(%d,%d) ", i, j - 1);
							printf("(%d,%d) ", i, j + 1);
							printf("(%d,%d) ", i + 1, j - 1);
							printf("(%d,%d) ", i + 1, j);
							printf("(%d,%d) ", i + 1, j + 1);
						}
				break;
			}

			Detect(Black_White, &record);
			for (int i = 0; i < record; i++)
				printf("(%d,%d) ", Pawn_record[i], Pawn_record[++i]);

			break;

		case 'M':
			insert(key[1] - 48, key[2] - 48, Black_White, record);
			break;
		case 'Q':
			system("CLS");
			Display_map();
			system("\npause");
			return 0;
		default:
			break;
		}
	}
}
