/******************************************************************
* Name：猜數字
*
* Goal：進行經典猜數字遊戲，比對使用者和答案的差別，
*       N個正確的數字回答 NA ， M個數字對位置錯誤
*
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
	int n, re[99], ans[99];
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &ans[i]);

	do
	{
		int m = 0, A = 0, B = 0;
		for (int i = 0; i < n; i++)
			scanf("%d", &re[i]);

		for (int i = 0; i < n; i++)
			if (re[i] == 0)
				m++;
		if (m == n)
			return 0;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (re[i] == ans[j])
					if (i == j)
					{
						A++;
						re[j] *= 10;
					}
					else
						B++;
		B -= A;
		printf("%dA %dB \n", A, B);

	} while (1);

	return 0;
}
