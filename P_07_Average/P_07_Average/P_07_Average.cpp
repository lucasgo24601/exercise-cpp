/******************************************************************
* Name：average
*
* Goal：輸入3個數字，並顯示他們的平均值，保留小數點後3位
*
* Modify record：18/11/12 By Lucas
******************************************************************/

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <math.h>

int main()
{
	int a, b, c;
	float average;
	scanf("%d%d%d", &a, &b, &c);
	average = (a + b + c) / 3.0;
	printf("%.3f", average);

	return 0;
}
