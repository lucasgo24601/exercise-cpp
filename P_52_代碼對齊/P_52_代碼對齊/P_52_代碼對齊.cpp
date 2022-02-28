/******************************************************************
* Name：代碼對齊
*
* Goal：輸入若干行代碼，要求各列單詞的左邊界對齊且盡量靠左。單詞之間至少要空一格。每
*		個單詞不超過80個字符，每行不超過180個字符，一共最多1000行
*
* Modify record：18/11/12 By Lucas
******************************************************************/

#include "pch.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> dict;
vector<string> words;

int max(int x, int y)
{
	if (x > y)
		return x;
	else
		return y;
}

void STL(vector<string> dict, vector<string> &words)
{
	vector<string>::iterator it = dict.begin();
	string word;

	for (int i = 0; i < dict.size(); i++)
	{
		int count = 0;
		string ss = *it++;
		for (int j = 0; j < ss.length(); j++)
			if (isblank(ss[j]))
			{
				if (word != "")
					words.push_back(word);
				word.clear();
				count = words.size() % 5;
			}
			else if (!isblank(ss[j]))
				word += ss[j];
		if (word == "")
			word = " ";
		words.push_back(word);
		word.clear();
		for (count = count; count < 4; count++)
			words.push_back(" ");
		count = 0;
	}
}

int main()
{

	char s[180];
	string ss, word;
	int count = 0, Row = 3, M[1000];
	memset(M, 0, sizeof(int));

	//while (gets_s(s))
	dict.push_back("  star: integer; // beging here");
	dict.push_back("   star: inter; // begg");
	dict.push_back(" str: ier; //");

	vector<string>::iterator it = dict.begin();
	STL(dict, words);

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < Row; j++)
			M[i] = max(M[i], words[i + (5 * j)].length());

	it = words.begin();
	for (int i = 1; it != words.end(); it++, i++)
		if (i % 5 == 0)
			cout << *it << endl;
		else
		{
			cout << *it << "  ";
			ss = *it;
			for (int j = ss.length(); j < M[i % 5 - 1]; j++)
				cout << " ";
		}
	system("pause");
	return 0;
}
