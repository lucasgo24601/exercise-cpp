/******************************************************************
* Name：字典
*
* Goal：輸入一個文本，找出所有不同的單詞（連續的字母序列），按字典序從小到大輸出。單詞不區分大小寫。
*
* Modify record：18/11/12 By Lucas
******************************************************************/

#include "pch.h"
#include <iostream>
#include <string>
#include <set>
#include <sstream>

using namespace std;
set<string> dict;

int main()
{
	string s;
	while (cin >> s)
		dict.insert(s);

	for (set<string>::iterator it = dict.begin(); it != dict.end(); it++)
		cout << *it << endl;

	system("pause");
	return 0;
}
