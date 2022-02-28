/******************************************************************
* Name：循環小數
*
* Goal：輸入整數a和b（0≤a≤3000，1≤b≤3000），輸出a/b的循環小數表示以及循環節長度。例
*		如a=5，b=43，小數表示為0.(116279069767441860465)，循環節長度為21。
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
	int a, b, s[9999], count = 0, m[9999];

	a = 5;
	b = 43;

	memset(m, 0, sizeof(m));

	a = a % b * 10;

	while (m[a] == 0)
	{
		m[a]++;
		s[count++] = a / b;

		a = a % b * 10;
		printf(" %d ", a);
	}
	printf("\n");
	for (int i = 0; i < count; i++)
		printf("%d", s[i]);

	/*{
		count=0;
		a*=10;
		while(a>b)
		{
			a-=b;
			count++;
		}
		s[i]=count;
	}
	printf(".");
	for(int i=0;i<10;i++)
	printf("%d",s[i]);*/

	return 0;
}
