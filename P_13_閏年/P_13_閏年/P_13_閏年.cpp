/******************************************************************
* Name：閏年
*
* Goal：輸入年份，判斷是否為閏年，是的話顯示 "Yes" 否則顯示 "No"
*       閏年：1. 可被4整除和不可被100整除  2.可被400整除 滿足其一條件即為閏年
*
* Modify record：18/11/12 By Lucas
******************************************************************/

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <math.h>

int main()
{
	int y;
	scanf("%d", &y);
	if (y % 400 == 0 | (y % 4 == 0 & y % 100 != 0))
		printf("yes");
	else
		printf("no");

	return 0;
}
