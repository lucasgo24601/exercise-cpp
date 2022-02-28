/******************************************************************
* Name：數據分析 II
*
* Goal：輸入一些不超過1千正整數，將顯示其最大值、最小值、全數的平均值(保留小數點後三位)
*       輸入多組數據，每組數據第一行是整數的個數N，第二行N個整數，輸入N=0則為結束
*
* Modify record：18/11/12 By Lucas
******************************************************************/

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <math.h>
#define INF 100000000

int main()
{
	int x = INF;
	while (x != 0)
	{
		int i, min = INF, max = -INF, temp;
		float sum = 0, avg = 0;
		scanf("%d", &x);
		if (x == 0)
			break;
		for (i = 0; i < x; i++)
		{
			scanf("%d", &temp);
			if (min > temp)
				min = temp;
			if (max < temp)
				max = temp;

			sum += temp;
			avg = sum / x;
		}
		printf("%d  %d  %.3f\n", min, max, avg);
	}

	return 0;
}
