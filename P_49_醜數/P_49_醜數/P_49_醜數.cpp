/******************************************************************
* Name：醜數
*
* Goal：丑数是指不能被2，3，5以外的其他素数整除的数。把丑数从小到大排列起来，结果如下：
*		1,2,3,4,5,6,8,9,10,12,15,…
*		求第1500个丑数。
*
* Modify record：18/11/12 By Lucas
******************************************************************/

#include "pch.h"
#include <map>
#include <set>
#include <string>
#include <cctype> //isalpha 字元是否為字母(function)
#include <vector>
#include <iostream>
#include <algorithm> //sort

using namespace std;

set<int> dict;

typedef long long LL;
int main()
{
	int count = 0, s[1500];
	for (int i = 1; i < 6; i++)
		dict.insert(i);

	set<int>::iterator it;

	for (LL i = 6; dict.size() <= 1500; i++)
		for (LL j = 2; j < i; j++)
		{
			if (i % j == 0 & (j == 2 | j == 3 | j == 5))
			{
				dict.insert(i);
			}
			if (i % j == 0 & j > 5 & !(j % 2 == 0 | j % 3 == 0 | j % 5 == 0))
				dict.erase(i);
		}

	for (it = dict.begin(); it != dict.end(); it++)
		cout << *it << endl;
	cout << s[1500];

	system("pause");
	return 0;
}
