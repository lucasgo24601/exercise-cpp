/******************************************************************
* Name：C階層
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

long long factorial(int a, int b)
{
	long long sum = 1;
	for (int i = a + 1; i <= b; i++)
		sum *= i;
	return sum;
}

int c(int n, int m)
{
	int t = n - m;
	long long sum;
	sum = factorial(t, n) / factorial(0, m);

	return sum;
}

int main()
{
	int n, m;
	long long C;
	scanf("%d %d", &n, &m);
	C = c(n, m);
	printf("%lld\n", C);

	return 0;
}
