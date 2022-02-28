/******************************************************************
* Name：File
*
* Goal：練習用開啟檔案並修改
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

	FILE *fp1, *fp2;

	fp1 = fopen("input.txt", "r");	/* 開啟並僅供讀取 */
	fp2 = fopen("output.txt", "w"); /* 開啟並僅供寫入 */

	if (fp1 == NULL)
	{
		printf("File does not exist.\n");
		exit(1);
	}

	if (fp2 == NULL)
	{
		printf("File can not be created.\n");
		exit(1);
	}
	fp1 = fprintf("input");

	system("pause");
	return 0;
}
