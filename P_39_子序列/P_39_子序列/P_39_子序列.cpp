/******************************************************************
* Name：子序列
*
* Goal：輸入兩個字符串s和t，判斷是否可以從t中刪除0個或多個字符（其他字符順序不變），
*		得到字符串s。例如，abcde可以得到bce，但無法得到dc。
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
	int count = 0, m = 0;
	char s[99], t[99];
	gets(s);
	gets(t);
	for (int i = 0; i < strlen(t); i++)
		if (t[i] == s[count++])
			m++;

	if (m == strlen(s))
		printf("Yes");
	else
		printf("No");

	return 0;
}
