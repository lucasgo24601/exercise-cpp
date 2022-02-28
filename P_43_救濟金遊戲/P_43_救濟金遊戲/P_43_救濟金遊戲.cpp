/******************************************************************
* Name：救濟金遊戲
*
* Goal：n(n<20)個人站成一圈，逆時針編號為1～n。有兩個官員，A從1開始逆時針數，B從n開
*		始順時針數。在每一輪中，官員A數k個就停下來，官員B數m個就停下來（注意有可能兩個
*		官員停在同一個人上）。接下來被官員選中的人（1個或者2個）離開隊伍。
*		輸入n，k，m輸出每輪裡被選中的人的編號（如果有兩個人，先輸出被A選中的）。例
*		如，n=10，k=4，m=3，輸出為4 8, 9 5, 3 1, 2 6, 10, 7。注意：輸出的每個數應當恰好佔3列。
*
* Modify record：18/11/12 By Lucas
******************************************************************/

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

int check(int *people, int size)
{
	for (int i = 0; i < size; i++)
		if (people[i] != 0)
			return 1;
	return 0;
}

void exctract(int size, int A_k, int B_m, int *people)
{
	int A_re = 0, B_re = size;
	int kk = A_k - 1, count = 0;

	while (check(people, size))
	{
		while (count < A_k)
			if (people[A_re] != 0)
			{
				A_re++;
				count++;
				A_re %= size + 1;
			}
		count = 0;
		while (count < B_m)
			if (people[B_re] != 0)
			{
				B_re--;
				count++;
				if (B_re < 0)
					B_re = size;
			}
		count = 0;
		printf("\n%d %d\n", people[--A_re], people[B_re]);

		people[A_re] = 0;
		people[B_re] = 0;

		for (int i = 0; i < size; i++)
			printf("%d ", people[i]);
	}
}

int main()
{

	int count = 1, n, m, k;
	int people[99];

	scanf("%d%d%d", &n, &k, &m);
	for (int i = 0; i < n; i++)
		people[i] = count++;
	exctract(n, k, m, people);

	return 0;
}
