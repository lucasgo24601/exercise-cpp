/******************************************************************
* Name：數據分析 I 
*
* Goal：輸入一些不超過1千正整數，將顯示其最大值、最小值、全數的平均值(保留小數點後三位)
*
* Modify record：18/11/12 By Lucas
******************************************************************/

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <math.h>
#define inf 100000000

int main()
{
	int x, min = inf, max = -inf;
	float sum = 0, count = 0;
	while (scanf("%d", &x))
	{
		if (x > 1000)
			break;
		if (min > x)
			min = x;
		if (max < x)
			max = x;
		count++;
		sum += x;
	}
	printf("max=%d  min=%d  average=%.3f", max, min, sum / count);

	system("pause");
	return 0;
}
