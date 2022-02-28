/******************************************************************
* Name：Sin And Cos
*
* Goal：輸入一個角度( 0 ~ 360 )，顯示其 Sin 和 Cos 的值
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
	printf("%f %f", sin(n), cos(n));

	return 0;
}
