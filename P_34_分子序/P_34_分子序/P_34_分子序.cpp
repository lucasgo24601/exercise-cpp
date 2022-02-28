/******************************************************************
* Name：分子序
*
* Goal：給出一種物質的分子式（不帶括號），求分子量。本題中的分子式只包含4種原子，分
*		別為C, H, O, N，原子量分別為12.01, 1.008, 16.00, 14.01（單位：g/mol）。例如，C6H5OH的
*		分子量為94.108g/mol。
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
	char s[99];
	float f[99], sum = 0;

	gets(s);

	for (int i = 0; i < strlen(s); i++)
		switch (s[i])
		{
		case 'C':
			f[i] = 12.01;
			break;
		case 'H':
			f[i] = 1.008;
			break;
		case 'O':
			f[i] = 16.00;
			break;
		case 'N':
			f[i] = 14.01;
			break;
		default:
			f[i] = s[i] - 48;
		}

	for (int i = 0; i < strlen(s); i++)
		if (s[i + 1] > '0' & s[i + 1] < ':')
			sum = sum + f[i] * f[++i];

		else
			sum += f[i];

	printf("%f", sum);

	return 0;
}
