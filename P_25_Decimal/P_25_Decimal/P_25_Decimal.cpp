/******************************************************************
* Name：Decimal
*
* Goal：輸入多組數據，每組數據 A、B、C，其中A和B<10^6 ，C<=100
*       請輸出 A/B 並且保留小數點後C位，輸入A=0 B=0 C=0則結束
*
* Modify record：18/11/12 By Lucas
******************************************************************/

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <math.h>

int main()
{
	int a, b, c, t = 1, ten, point;
	float x;
	while (1)
	{
		scanf("%d %d %d", &a, &b, &c);
		x = (a * 1.0) / b;

		for (int i = 0; i <= c; i++)
		{
			x *= 10; //decimal左移C位元
			t *= 10;
		}
		t /= 10;

		point = floor(x);
		if (point % 10 > 5)
			point += 10.0;
		point /= 10;

		ten = point / t;

		point -= (ten * t);

		if (a >= 1e+6 | b >= 1e+6 | c >= 100 | a == 0 | b == 0 | c == 0)
			break;
		else
			printf("%d.%d\n", ten, point);
	}
	return 0;
}
