/******************************************************************
* Name：three integer order
*
* Goal：輸入3個數字，對其進行排序，由小到大輸出
*
* Modify record：18/11/12 By Lucas
******************************************************************/

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <math.h>

void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int a, b, c, t;
	scanf("%d%d%d", &a, &b, &c);
	if (a > b)
		Swap(&a, &b);
	if (a > c)
		Swap(&a, &c);
	if (b > c)
		Swap(&b, &c);
	printf("%d %d %d", a, b, c);

	return 0;
}
