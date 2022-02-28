/******************************************************************
* Name：復合詞
*
* Goal：给出一个词典，找出所有的复合词，即恰好有两个单词连接而成的单词。输入每行都是
*		一个由小写字母组成的单词。输入已按照字典序从小到大排序，且不超过120000个单词。输
*		出所有复合词，按照字典序从小到大排列。
*
* Modify record：18/11/12 By Lucas
******************************************************************/

#include "pch.h"
#include <stdio.h>
#include <iostream>

#include <string>
#include <math.h>
#include <time.h>
#include <ctype.h>

#include <algorithm>
#include <vector>
#include <stack>
#include <set>

using namespace std;
vector<string> dict;
set<string> dictt;

string operator-(const string A, const string B)
{
	vector<char> numbers;

	if (A.length() != B.length())
		return "FUCK";

	for (int i = 0; i < A.length(); i++)
		if ((B[i] == ' ') | (A[i] == B[i]))
			numbers.push_back(A[i] - B[i]);
		else if (A[i] != B[i])
			numbers.push_back(A[i]);

	string x;
	for (int i = 0; i < numbers.size(); i++)
		if (isalpha(numbers[i]))
			x += tolower(numbers[i]);

	return x;
}

int strncmp(string cs, string ct)
{
	unsigned char c1, c2;
	int i = 0;

	if (cs.length() != ct.length())
		return 1;

	for (int i = 0; i < cs.length(); i++)
	{
		c1 = cs[i];
		c2 = ct[i];
		if (c1 != c2)
			return c1 < c2 ? -1 : 1;
	}

	return 0;
}

string full_blank(string source, string checked, char R_or_L)
{
	string x = "";

	if (R_or_L == 'R')
		for (int i = checked.length(); i < source.length(); i++)
			checked += ' ';
	else
	{
		for (int i = checked.length(); i < source.length(); i++)
			x += ' ';
		x += checked;
		checked = x;
	}

	return checked;
}

int strcheck(string source, string checked)
{
	string split, t;
	int i, j = 0, count = 0;

	if (source.length() <= checked.length())
		return 0;

	t = full_blank(source, checked, 'L');
	for (int i = 0; i < dict.size(); i++)
		if (source - t != source)
			if (strncmp(dict[i], source - t) == 0)
				dictt.insert(source);

	t = full_blank(source, checked, 'R');

	for (int i = 0; i < dict.size(); i++)
		if (source - t != source)
			if (strncmp(dict[i], source - t) == 0)
				dictt.insert(source);
}

int main()
{
	string s;

	/*	dict.push_back("abcdd");
		dict.push_back("abc");
		dict.push_back("dd");
		dict.push_back("abcef");
		dict.push_back("ddddd");
		dict.push_back("ef");*/

	while (cin >> s)
		dict.push_back(s);

	sort(dict.begin(), dict.end());

	for (int i = 0; i < dict.size(); i++)
		for (int j = 0; j < dict.size(); j++)
			strcheck(dict[i], dict[j]);

	for (set<string>::iterator it = dictt.begin(); it != dictt.end(); it++)
		cout << *it << endl;

	system("pause");
	return 0;
}
