/******************************************************************
* Name：三角型
*
* Goal：輸入三角行的邊長，判斷是否可以三角形，不能則顯示"not a triangle"，可以的話判斷是否為正三角形
*       為正三角形顯示 "yes" 否則顯示 "no"
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
	scanf("%d %d %d", &a, &b, &c);
	if (a + b < c | b + c < a | a + c < b)
		printf("not a triangle");
	else if (a * a + b * a == c * c | b * b + c * c == a * a | a * a + c * c == b * b)
		printf("yes");
	else
		printf("no");

	return 0;
}
