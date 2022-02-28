/******************************************************************
* Name：開關問題
*
* Goal：開燈問題，有n盞燈，編號1~n，第一個人把有關1的倍數的燈打開
*		第二個人把有關2的倍數的燈打開
*		第三個人把有關3的倍數的燈打開
*		若要打開的燈已被打開，則熄滅，依此類推，請輸入k人和n燈
*		最後顯示最後亮著的燈
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
	int j, i, n, k, a[999];
	scanf("%d %d", &n, &k);

	memset(a, 0, sizeof(a));

	for (i = 1; i <= k; i++)
		for (j = 1; j <= n; j++)
			a[i * j] = !a[i * j];

	for (int x = 1; x <= n; x++)
		if (a[x] == 1)
			printf("%d ", x);

	return 0;
}
