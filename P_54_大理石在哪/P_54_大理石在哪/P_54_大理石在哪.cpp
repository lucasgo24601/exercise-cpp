/******************************************************************
* Name：大理石在哪
*
* Goal：現有N個大理石，每個大理石上寫了一個非負整數。首先把各數從小到大排序，然後回
*		答Q個問題。每個問題問是否有一個大理石寫著某個整數x，如果是，還要回答哪個大理石上
*		寫著x。排序後的大理石從左到右編號為1～N。 （在樣例中，為了節約篇幅，所有大理石上
*		的數合併到一行，所有問題也合併到一行。 ）
*
* Modify record：18/11/12 By Lucas
******************************************************************/

#include "pch.h"
#include <cstdio>
#include <algorithm>

using namespace std;
const int maxn = 10000;

int main()
{
	int n, q, x, a[maxn], kase = 0;
	while (scanf("%d%d", &n, &q) == 2 && n)
	{
		printf("CASE# %d:\n", ++kase);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a + n);
		while (q--)
		{
			scanf("%d", &x);
			int p = lower_bound(a, a + n, x) - a;
			if (a[p] == x)
				printf("%d found at %d\n", x, p + 1);
			else
				printf("%d not found\n", x);
		}
	}

	system("pause");
	return 0;
}
