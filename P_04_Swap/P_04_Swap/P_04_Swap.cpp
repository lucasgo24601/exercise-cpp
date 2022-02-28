/******************************************************************
* Name：Swap numbers
*
* Goal：練習將兩個數字交換
*
* Modify record：18/11/12 By Lucas
******************************************************************/

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <math.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int a, b, t, x, y;
	scanf("%d%d", &a, &b);
	swap(&a, &b);
	printf("%d %d\n", a, b);

	return 0;
}
