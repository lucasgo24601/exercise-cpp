/******************************************************************
* Name：Sigma
*
* Goal：輸入一個正數 = N，顯示其 1 + 2 + ... + N 的總值
*
* Modify record：18/11/12 By Lucas
******************************************************************/

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <math.h>

int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("%d", (1 + n) * n / 2);

	return 0;
}
