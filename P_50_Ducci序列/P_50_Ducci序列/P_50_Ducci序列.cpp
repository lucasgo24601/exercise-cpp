/******************************************************************
* Name：Ducci序列
*
* Goal：對於一個n元組(a1, a2, …, an)，可以對於每個數求出它和下一個數的差的絕對值，得到
*		一個新的n元組(|a1-a2|, |a2-a3|, …, |an-a1|)。重複這個過程，得到的序列稱為Ducci序列，例如：
*		(8, 11, 2, 7) -> (3, 9, 5, 1) -> (6, 4, 4, 2) -> (2, 0, 2, 4) -> (2, 2, 2 , 2) -> (0, 0, 0, 0).
*		也有的Ducci序列最終會循環。輸入n元組（3≤n≤15），你的任務是判斷它最終會變成0
*		還是會循環。輸入保證最多1000步就會變成0或者循環。
*
* Modify record：18/11/12 By Lucas
******************************************************************/

#include "pch.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

void display(vector<int> dict, int count)
{
	for (vector<int>::iterator it = dict.begin(); it != dict.end(); it++)
		cout << *it << "  ";
	cout << "count = " << count;
	cout << endl;
}

int main()
{
	int x, zero = 0, count = 0;
	vector<int> dict;

	/*
	while (cin >> x)
	dict.push_back(x);
	*/

	dict.push_back(8);
	dict.push_back(11);
	dict.push_back(2);
	dict.push_back(7);

	while (zero < 4)
	{
		zero = 0;
		dict.push_back(dict[0]);

		for (int i = 0; i < dict.size() - 1; i++)
			dict[i] = abs(dict[i + 1] - dict[i]);
		dict.pop_back();
		for (int i = 0; i < dict.size(); i++)
			if (dict[i] == 0)
				zero++;
		display(dict, ++count);
		if (count == 1000)
			return 0;
	}

	system("pause");
	return 0;
}
