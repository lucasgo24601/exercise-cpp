/******************************************************************
* Name：錯位
*
* Goal：假設使用者輸入一段文字本意為：Hello Word
*       卻不小心打錯字，顯示為：JR::P EPTF，明顯鍵盤錯位右邊一格
*       輸入錯位右邊一格的文字，顯示正確文字內容
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
	char k[999999] = "`1234567890-=QWERTYUIOP[]ASDFGHJKL;'\\ZXCVBNM,./";
	char x[999999];

	gets(x);



	for (int i = 0; i < strlen(x); i++)
		for (int j = 0; j < strlen(k); j++)
			if (x[i] == k[j])
				x[i] = k[--j];

	for (int j = 0; j < strlen(x); j++)
		printf("%c", x[j]);





	return 0;

}

