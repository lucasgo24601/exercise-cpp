/******************************************************************
* Name：OX得分
*
* Goal：給出一個由O和X組成的串（長度為1～80），統計得分。每個O的得分為目前連續出現
*       的O的個數，X的得分為0。例如，OOXXOXXOOO的得分為1+2+0+0+1+0+0+1+2+3。
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
	char x[999];
	int sum = 0, count = 1;
	gets(x);

	for (int i = 0; i < strlen(x); i++)
		if (x[i] == 'O')
			sum += count++;
		else
			count = 1;

	printf("%d", sum);

	return 0;
}
