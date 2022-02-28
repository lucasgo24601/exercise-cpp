/******************************************************************
* Name：For exercise
*
* Goal：輸入一個正整數 = N ，使用For 依序顯示 1 2 3 4 ... N
*
* Modify record：18/11/12 By Lucas
******************************************************************/

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <math.h>

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		printf("%d  ", i);

	return 0;
}
