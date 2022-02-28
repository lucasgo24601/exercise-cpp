/******************************************************************
* Name：排序練習
*
* Goal：設定100萬、200萬、400萬 ... 多筆大數據，每筆數據由6個亂數英文字母組成
*		請使用3種排序去作時間效益判斷
*
* Modify record：18/11/12 By Lucas
******************************************************************/

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

using namespace std;

typedef unsigned long long LLint;

#define CharSize 6
#define OneMillion 1000000

char *CreateRandomWord()
{
	char *InsertData = new char[CharSize];

	for (int i = 0; i < CharSize - 1; i++)
		InsertData[i] = (clock() + rand()) % 26 + 65;

	InsertData[CharSize - 1] = '\0';

	return InsertData;
}

LLint InsertionSort_Time(char **Data, LLint DataLength)
{
	clock_t Start;
	Start = clock();

	int j;

	for (int i = 1; i < DataLength; i++)
	{
		char *Temp_1 = new char[CharSize];
		Temp_1 = Data[i];

		j = i - 1;

		while ((j >= 0) && IsData_1_Greater(Data[j], Temp_1))
		{
			Data[j + 1] = Data[j];
			j--;
		}

		Data[j + 1] = Temp_1;
	}
	clock_t End;
	End = clock();

	return End - Start;
}

LLint SelectionSort_Time(char **Data, LLint DataLength)
{
	clock_t Start;
	Start = clock();
	for (int i = 0; i < DataLength - 1; i++)
	{
		int min = i;

		for (int j = i + 1; j < DataLength; j++)
			if (IsData_1_Greater(Data[min], Data[j]))
				min = j;

		swap(Data[min], Data[i]);
	}

	clock_t End;
	End = clock();

	return End - Start;
}

LLint BubbleSort_Time(char **Data, LLint DataLength)
{
	clock_t Start;
	Start = clock();

	int i, j, temp;
	for (int i = 0; i < DataLength - 1; i++)
		for (int j = 0; j < DataLength - 1 - i; j++)
			if (IsData_1_Greater(Data[j], Data[j + 1]))
				swap(Data[j], Data[j + 1]);

	clock_t End;
	End = clock();

	return End - Start;
}

char **CreateRandomList(LLint DataLength)
{
	char **Data = new char *[DataLength];

	for (int i = 0; i < DataLength; i++)
		Data[i] = new char[CharSize];

	for (LLint i = 0; i < DataLength; i++)
		Data[i] = CreateRandomWord();

	char **temp = new char *[DataLength];
	temp = Data;
	return temp;
}

bool IsData_1_Greater(char *strData_1, char *strData_2)
{
	while (*strData_1 != '\0')
	{
		if (*strData_1 > *strData_2)
			return true;
		else if (*strData_1 < *strData_2)
			return false;

		strData_1++;
		strData_2++;
	}

	return false;
}

void Sort(LLint DataLength)
{
	cout << "Insertion Sort Data: " << DataLength << " Time: " << InsertionSort_Time(CreateRandomList(DataLength), DataLength) << endl;
	cout << "Selection Sort Data: " << DataLength << " Time: " << SelectionSort_Time(CreateRandomList(DataLength), DataLength) << endl;
	cout << "Bubble Sort Data: " << DataLength << " Time: " << BubbleSort_Time(CreateRandomList(DataLength), DataLength) << endl;
}

int main()
{
	Sort(50000);
	Sort(60000);
}
