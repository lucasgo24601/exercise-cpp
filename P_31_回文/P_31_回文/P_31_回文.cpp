/******************************************************************
* Name：回文
*
* Goal：輸入一串文字，並將該文字依照規定進行鏡像，在進行判斷是否為回文
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
	char k[9999] = "ABCD3FGHILKLMNOPQR2TUVWXY5123456789";
	char w[9999] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
	char x[9999];
	int m = 0;

	scanf("%s", x);

	for (int i = 0; i < strlen(x); i++)
		for (int j = 0; j < strlen(w); j++)
			if (x[i] == w[j])
				x[i] = k[j];

	for (int i = 0; i < strlen(x) / 2; i++)
		if (x[i] != x[strlen(x) - 1 - i])
			m = 1;

	if (m == 1)
		printf("is not a palindrome.\n");
	else
		printf("Yes");


	return 0;

}

