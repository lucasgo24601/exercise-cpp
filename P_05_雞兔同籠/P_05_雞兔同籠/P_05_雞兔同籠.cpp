/******************************************************************
* Name：雞兔同籠
*
* Goal：已知總龍內的雞+兔的數量 = N，其總龍內腳的數量 = M，使用者輸入N和M，需顯示其雞和兔的數量
*
* Modify record：18/11/12 By Lucas
******************************************************************/

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <math.h>

int main()
{
	// 4兔 + 2雞 = M
	// 兔  +  雞 = N
	// M-2N = 2兔

	int m, n;
	scanf("%d%d", &n, &m);
	const int r = (m - 2 * n) / 2;
	const int c = n - r;
	if (r > 0 & c > 0 & m > 0 & n > 0)
		printf("%d %d", c, r);
	else
		printf("No answer");

	return 0;
}
