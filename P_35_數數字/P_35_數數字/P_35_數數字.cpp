/******************************************************************
* Name：數數字
*
* Goal：把前n（n≤10000）个整数顺次写在一起：123456789101112…数一数0～9各出现多少次
*	  （输出10个整数，分别是0，1，…，9出现的次数）。
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
	int n, nn, count = 1, sum = 0, temp, ww;
	char s[99];

	scanf("%d", &n);

	for (int i = 0; i < 10; i++)
	{

		for (int j = 1; j <= n; j++)
		{
			ww = nn = j;
			while (ww /= 10)
				count++;
			for (int z = count - 1; z >= 0; z--)
			{
				s[count] = '\0';

				temp = nn % 10;

				s[z] = temp + 48;

				nn /= 10;
			}

			for (int k = 0; k < count; k++)
				if (i + 48 == s[k])
					sum++;

			count = 1;
		}

		printf("%d = %d\n", i, sum);
		sum = 0;
	}

	return 0;
}
