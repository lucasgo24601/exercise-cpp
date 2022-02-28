/******************************************************************
* Name：temperatrue
*
* Goal：輸入華氏溫度，將其轉換成攝氏溫度並顯示，保留小數點後三位
*
* Modify record：18/11/12 By Lucas
******************************************************************/

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <math.h>

int main()
{
	float f, c;
	scanf("%f", &f);
	c = 5.0 * (f - 32.0) / 9.0;
	printf("%.3f", c);

	return 0;
}
