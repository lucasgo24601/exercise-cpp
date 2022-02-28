/******************************************************************
* Name：水仙花
*
* Goal：輸出100~999的所有水仙花數，水仙花： ABC = A^3 + B^3 + C^3
*
* Modify record：18/11/12 By Lucas
******************************************************************/

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <math.h>

int main()
{
	int i, a, b, c;
	for (i = 100; i < 999; i++)
	{
		a = i / 100;
		b = i / 10 % 10;
		c = i % 10;
		if (i == a * a * a + b * b * b + c * c * c)
			printf("%d ", i);
	}

	return 0;
}
