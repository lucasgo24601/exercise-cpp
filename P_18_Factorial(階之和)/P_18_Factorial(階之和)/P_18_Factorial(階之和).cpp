/******************************************************************
* Name：階之和
*
* Goal：輸入正整數N，將計算 S= 1! + 2! + 3! + 4! + .... + N! ，顯示其S的末六位
*
* Modify record：18/11/12 By Lucas
******************************************************************/

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <math.h>
//#include<time.h>

int main()
{
	long n, temp, box = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		temp = 1;
		for (int j = 1; j <= i; j++)
		{
			temp = temp * j;
			temp = temp % 1000000;
		}
		box = box % 1000000;
		box += temp;
	}
	printf("%ld\n", box);
	//printf("Time used = %.2f\n", (double)clock() / CLOCKS_PER_SEC);

	return 0;
}
