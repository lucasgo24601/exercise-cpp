/******************************************************************
* Name：蛇行填數
*
* Goal：輸入正整數N，之後輸出Array N*N的數據
*       Ex: 若N=4的話 ->        10 11 12 01
*								09  16 13 02  
*								08  15 14 03
*								07  06 05 04
* Modify record：18/11/12 By Lucas
******************************************************************/

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
	int j, i, n, x, y, a[99][99], count = 1;

	scanf("%d", &n);

	memset(a, 0, sizeof(a));

	x = n - 1;
	y = 0;

	while (count < n * n)
	{
		while (a[x][y + 1] == 0 & y + 1 < n)
			a[x][y++] = count++; //down
		while (a[x - 1][y] == 0 & x - 1 >= 0)
			a[x--][y] = count++; //left
		while (a[x][y - 1] == 0 & y - 1 >= 0)
			a[x][y--] = count++; //up
		while (a[x + 1][y] == 0 & x + 1 < n)
			a[x++][y] = count++;
	}
	a[x][y] = count;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%4d ", a[j][i]);
		printf("\n");
	}

	return 0;
}
