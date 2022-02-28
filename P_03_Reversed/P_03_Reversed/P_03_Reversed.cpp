/******************************************************************
* Name：反轉3位數數字
*
* Goal：輸入一個三位數數字，將其輸出翻轉
*
* Modify record：18/11/12 By Lucas
******************************************************************/

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <math.h>

int main()
{
	int x;
	scanf("%d", &x);
	printf("%d%d%d\n", x % 10, x % 100 / 10, x / 100);
	printf("%d", x % 10 * 100 + x % 100 / 10 * 10 + x / 100);

	return 0;
}
