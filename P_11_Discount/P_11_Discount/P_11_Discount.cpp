/******************************************************************
* Name：折扣
*
* Goal：一件外套賣95元，如果買超過300元，則可以享85折，輸入其外套數目，顯示其價錢
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
	if (n * 95 < 300)
		printf("%d", n * 95);
	else
		printf("%f", n * 95 * 0.85);
		
	return 0;
}
