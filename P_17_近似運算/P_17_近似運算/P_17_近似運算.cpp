/******************************************************************
* Name：近似運算
*
* Goal：計算pi/4 = 1 -1/3 + 1/5 -1/7+ ... 直到最後數字小於10^-6
*
* Modify record：18/11/12 By Lucas
******************************************************************/

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <math.h>

int main()
{
	float x = 0.0, n;
	for (int i = 0;; i++)
	{
		n = 1.0 / (i*2.0 + 1.0);
		if (i % 2 == 0)
			x += n;
		else
			x -= n;
		if (n < 1e-6) break;
	}
	printf("%.6f", x);

	return 0;
}

