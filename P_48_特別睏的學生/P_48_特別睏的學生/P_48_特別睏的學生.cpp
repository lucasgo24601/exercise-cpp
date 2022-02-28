/******************************************************************
* Name：特別睏的學生
*
* Goal：課堂上有n個學生（n≤10）。每個學生都有一個“睡眠-清醒”週期，其中第i個學生醒Ai分
*		鐘後睡Bi分鐘，然後重複（1≤Ai，Bi≤5），初始時第i個學生處在他的周期的第Ci分鐘。每個
*		學生在臨睡前會察看全班睡覺人數是否嚴格大於清醒人數，只有這個條件滿足時才睡覺，否
*		則就堅持聽課Ai分鐘後再次檢查這個條件。問經過多長時間後全班都清醒。如果用(A,B,C)描
*		述一些學生，則圖4-11中描述了3個學生(2,4,1)、(1,5,2)和(1,4,3)在每個時刻的行為。
*
* Modify record：18/11/12 By Lucas
******************************************************************/

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

int student[99][3];
char Wake_Sleep[99][99];

void Check(int n)
{
	int count = 0, move[99], Wake = 0, make[3];
	/*	for (int i = 0; i < n; i++)
			move[i] = student[i][2];*/

	move[0] = 0;
	move[1] = 1;
	move[2] = 2;

	while (count < 22)
	{
		memset(make, 1, 3);
		for (int i = 0; i < n; i++)
			if (Wake_Sleep[i][move[i]] == 'W')
				Wake++;

		for (int i = 0; i < n; i++)
			if (Wake_Sleep[i][move[i] + 1] == 'S' & Wake_Sleep[i][move[i]] == 'W')
				if ((n - Wake) < Wake)
				{
					move[i] = 0;
					make[i] = 0;
				}

		for (int i = 0; i < n; i++)
			if (make[i] != 0)
				++move[i] %= (student[i][0] + student[i][1]);

		count++;
		if (Wake == n)
			break;
		Wake = 0;
	}
	printf("%d", count);
}
int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &student[i][j]);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
		{
			if (j == 0)
				for (int k = 0; k < student[i][j]; k++)
					Wake_Sleep[i][k] = 'W';
			if (j == 1)
				for (int k = student[i][j - 1]; k < student[i][j] + student[i][j - 1]; k++)
					Wake_Sleep[i][k] = 'S';
		}

	Check(n);

	system("pause");
	return 0;
}
