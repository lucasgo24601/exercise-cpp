/******************************************************************
* Name：3N+1
*
* Goal：輸入一個正整數 = N ，若N為奇數，則將N變為3N+1，否則變為N的一半，持續此操作直到N=1
*       請使用者輸入N，顯示操作次數為何
*
* Modify record：18/11/12 By Lucas
******************************************************************/

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <math.h>

int main()
{
	long long n, count = 0;
	scanf("%d", &n);
	while (n != 1)
	{
		if (n % 2 == 0)
			n /= 2;
		else
			n = n * 3 + 1;
		count++;
	}
	printf("%lld", count);

	return 0;
}
