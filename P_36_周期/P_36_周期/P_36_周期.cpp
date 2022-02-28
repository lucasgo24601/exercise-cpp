/******************************************************************
* Name：階之合
*
* Goal：如果一個字符串可以由某個長度為k的字符串重複多次得到，則稱該串以k為周期。例
*		如，abcabcabcabc以3為周期（注意，它也以6和12為周期）。
*		輸入一個長度不超過80的字符串，輸出其最小周期。
*
* Modify record：18/11/12 By Lucas
******************************************************************/

#include "pch.h"
#include <string.h>
#include <stdio.h>

int main(void)
{
	char s[99];
	int len;
	gets(s);
	len = strlen(s);
	int i, j, count;

	for (i = 1; i <= len / 2; i++)
	{
		count = 0;
		for (j = 0; j < len - i; j++)
			if (s[j] == s[j + i])
				count++;

		if (count == j)
			break;
	}
	printf("%d", len - count);

	return 0;
}
