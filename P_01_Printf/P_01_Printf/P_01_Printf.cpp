/******************************************************************
* Name：Printf exercise
*
* Goal：練習用Printf函數顯示 Integer and Float
*
* Modify record：18/11/12 By Lucas
******************************************************************/

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <math.h>

int main()
{
	printf("%d\n", 1 + 2);
	printf("%d\n", 8 / 5); // 8/5=1.6 but is integer / integer = integer -> 1
	printf("%f\n", 8.0 / 5.0); // float / float = float -> 1.6
	printf("%.3f\n", 8.0 / 5.0); // hold 3 digits after the decimal point
	printf("%.4f\n", 1 + 2 * sqrt(3) / (5 - 0.1)); // here 5-0.1 -> integer - float -> float -float = float

	return 0;
}