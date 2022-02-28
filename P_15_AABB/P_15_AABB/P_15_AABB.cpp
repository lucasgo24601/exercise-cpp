/******************************************************************
* Name：AABB
*
* Goal：輸出所有符合4位元的AABB的平方數
*       AABB：7744 = 88的平方數
*
* Modify record：18/11/12 By Lucas
******************************************************************/

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <math.h>

int main()
{
	int i, j, n, m;
	for (i = 1; i <= 9; i++)
		for (j = 0; j < 10; j++)
		{
			n = i * 1100 + j * 11;
			m = sqrt(n);
			if (n == m * m)
				printf("%d ", n);
		}

	return 0;
}
