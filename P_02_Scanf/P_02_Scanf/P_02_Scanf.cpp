/******************************************************************
* Name：Scanf exercise
*
* Goal：練習用Scanf函數輸入，半徑、高，輸出此圓柱面積，並保留小數點3位。
*
* Modify record：18/11/12 By Lucas
******************************************************************/

#include "pch.h"
#include <stdio.h>
#include <math.h>
#include <iostream>

int main()
{
	const double PI = acos(-1.0);
	float r, h;
	scanf("%f%f", &r, &h);
	printf("%.3f", (2.0 * PI * r * r) + (2.0 * r * h * PI));

	return 0;
}