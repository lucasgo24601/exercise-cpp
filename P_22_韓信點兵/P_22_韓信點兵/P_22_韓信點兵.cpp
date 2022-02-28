/******************************************************************
* Name：韓信點兵
*
* Goal：相傳韓信是位非常聰明的將領，他不需要計算士兵的數量，使需要士兵三人一排、五人一排、七人一排的變換
*       每次只需要觀看排尾就可以知道總人數了
*       輸入多組數據，每組數據由A、B、C正整數所組成，分別代表 三人一排 、五人一排、七人一排的排尾數量
*       然後輸出其總人數的最小值，以知 10 < 人數 <100 
*
* Modify record：18/11/12 By Lucas
******************************************************************/

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <math.h>

int main()
{
	int a, b, c, max = 0;
	scanf("%d %d %d", &a, &b, &c);

	for (int i = 10; i <= 100; i++)
		if (i % 7 == a & i % 5 == b & i % 3 == c)
			max = i;

	if (max == 0)
		printf("No Answer");
	else
		printf("%d", max);

	return 0;
}
