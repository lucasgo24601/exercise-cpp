/******************************************************************
* Name：子序列的和
*
* Goal：輸入多組數據，每組數數據有兩個正整數 N 和 M ，其大小必須小於10^6
*       輸出 1/n^2 + 1/(n+1)^2 + 1/(n+2)^2 + ... +1/m^2 的值
*       保留小數點後5位，輸入n=0 m=0 則為結束
*       
* Modify record：18/11/12 By Lucas
******************************************************************/

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <math.h>

int main()
{
	int n, m;
	float x = 0, i;
	scanf("%d %d", &n, &m);

	for (i = n; i <= m; i++)
		x += 1 / (i * i);

	if (n == 0 & m == 0)
		return 0;
	else
		printf("%.5f", x);

	return 0;
}
