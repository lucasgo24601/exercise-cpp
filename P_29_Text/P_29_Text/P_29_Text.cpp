/******************************************************************
* Name：Text
*
* Goal：在TeX裡面，文字表示的雙引號，會有特殊設定，如果是左雙引號則為 `` ，如為右雙引號則為"
*       請將一段含有雙引號的文字轉換成TeX的雙引號格式
*
* Modify record：18/11/12 By Lucas
******************************************************************/

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
	char a[99999];
	int count = 0;
	gets(a);

	for (int i = 0; i < strlen(a); i++)
		if (a[i] == 34)
			if (count++ % 2 == 0)
				printf("%c%c", 96, 96);
			else
				printf("%c", a[i]);
		else
			printf("%c", a[i]);

	return 0;
}
