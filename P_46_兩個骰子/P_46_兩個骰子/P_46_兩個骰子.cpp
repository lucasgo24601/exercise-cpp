/******************************************************************
* Name：兩個骰子
*
* Goal：輸入兩個骰子，判斷二者是否等價，詳情請看原題
*
* Modify record：18/11/12 By Lucas
******************************************************************/

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

void Check(char *a, char *b)
{
	int size_a = strlen(a) - 1, size_b = strlen(b) - 1, count = 0;
	for (int i = 0; i < size_a; i++)
		for (int j = 0; j < size_b; j++)
			if (a[i] == b[j] & a[size_a - i] == b[size_b - j])
			{
				count++;
				break;
			}

	if (count == size_a)
		printf("Yes");
	else
		printf("No");
}

int main()
{
	char a[99], b[99];
	printf("please enter the first dice:");
	scanf("%s", a);
	printf("please enter the second dice:");
	scanf("%s", b);
	Check(a, b);

	system("pause");
	return 0;
}
