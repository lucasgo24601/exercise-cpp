/******************************************************************
* Name：排列
*
* Goal：使用 1 2 3 ....9 的數字，去組成3個三位數 ,其中每個號碼只能用一次
*       請輸出 ABC , DEF , GHI 其比值必須為 1 : 2 : 3 的數列組合
*
* Modify record：18/11/12 By Lucas
******************************************************************/

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <math.h>

int main()
{

	int i;
	for (i = 123; i < 1e+7; i++)
	{
		int x, y, z;
		long box = 1;
		x = i;
		y = i * 2;
		z = i * 3;

		box *= (x / 100) * (x / 10 % 10) * (x % 10);
		box *= (y / 100) * (y / 10 % 10) * (y % 10);
		box *= (z / 100) * (z / 10 % 10) * (z % 10);

		if (box == 362880)
			printf("%d %d %d\n", x, y, z);
	}
	return 0;
}
