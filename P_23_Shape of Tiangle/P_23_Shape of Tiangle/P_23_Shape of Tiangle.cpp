/******************************************************************
* Name：Shape of Triangle
*
* Goal：輸入正整數N 輸出N層倒三角形
*
* Modify record：18/11/12 By Lucas
******************************************************************/

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <math.h>

int main()
{
	int n, i, j, k;
	for (i = 0; i < 10; i += 2)
	{
		for (k = 0; k < i; k += 2)
			printf(" ");

		for (j = i; j < 9; j++)
			printf("*");

		printf("\n\n");
	}

	return 0;
}
