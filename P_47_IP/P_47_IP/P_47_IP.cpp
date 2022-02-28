/******************************************************************
* Name：IP
*
* Goal：可以用一個網絡地址和一個子網掩碼描述一個子網（即連續的IP地址範圍）。其中子網
*		掩碼包含32個二進制位，前32-n位為1，後n位為0，網絡地址的前32-n位任意，後n位為0。
*		所有前32-n位和網絡地址相同的IP都屬於此網絡。
*		例如，網絡地址為194.85.160.176（二進制為11000010|01010101|10100000|10110000），
*		子網掩碼為255.255.255.248（二進制為11111111|11111111|11111111|11111000），則該子網
*		的IP地址範圍是194.85.160.176～194.85.160.183。輸入一些IP地址，求最小的網絡（即包含IP
*		地址最少的網絡），包含所有這些輸入地址。
*		例如，若輸入3個IP地址：194.85.160.177、194.85.160.183和194.85.160.178，包含上述3
*		個地址的最小網絡的網絡地址為194.85.160.176，子網掩碼為255.255.255.248。
*
* Modify record：18/11/12 By Lucas
******************************************************************/

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define inf 100000000

int IP_short_char_three[99][4];
int IP_short_int_three[99][4];

long long number2digit(int *number)
{
	long long sum = 0, ten = 1, count = number[3];

	for (int i = 0; i < count; i++)
		ten *= 10;
	for (int i = 0; i < count; i++)
	{
		sum = sum + number[i] * ten;
		ten /= 10;
	}
	sum /= 10;

	return sum;
}

int sub(int min, int max, int i)
{
	int box = max - min, two = 1, count = 0;
	float x;
	if (box != 0)
		while (1)
		{
			x = floor(box / two);
			count++;
			two *= 2;
			if (x == 1)
				break;
		}

	printf("%d", 255 - two + 1);
	if (i != 3)
		printf(".");

	if (box == 0)
		return max;

	return max - two + 1;
}

void transform(char IP[], int set)
{
	int count = 0, count_1 = 0, one = 0, ten = 0, max, min, box[4];

	/*	194.85.160.177
		194.85.160.183

		IP_short_char_three [  ten=1  ][  one=1 ] = 9			(1 "9" 4)
		IP_short_char_three [  ten=1  ][  one=2 ] = 9			(1 9 "4")
		IP_short_char_three [  ten=1  ] = 1 9 4
		IP_short_char_three [  ten=2  ] = 8 5

		IP_short_int_three [  set=1  ] = 19485160177
		IP_short_int_three [  set=2  ] = 19485160183
		IP_short_int_three [  set=1  ][  ten=1  ] = 194
		IP_short_int_three [  set=1  ][  ten=2  ] = 85
	*/
	for (int i = 0; i < strlen(IP) + 1; i++)
		if ((IP[i] == '.') | (i == strlen(IP)))
		{
			IP_short_char_three[ten][3] = one;
			one = 0;
			IP_short_int_three[set][ten] = number2digit(IP_short_char_three[ten]);
			ten++;
		}
		else
			IP_short_char_three[ten][one++] = IP[i] - 48;

	/*for (int i = 0; i < ten; i++)
		printf(" %d ", IP_short_int_three[set][i]);
	printf(	"\n");*/

	if (set == 2)
	{

		for (int i = 0; i <= IP_short_char_three[i][3]; i++)
		{
			min = inf, max = -inf;
			for (int j = 0; j < set; j++)
			{
				if (min > IP_short_int_three[j][i])
					min = IP_short_int_three[j][i];
				if (max < IP_short_int_three[j][i])
					max = IP_short_int_three[j][i];
			}

			box[i] = sub(min, max, i);
		}
		printf("\n");
		for (int i = 0; i <= IP_short_char_three[i][3]; i++)
		{
			printf("%d", box[i]);
			if (i != IP_short_char_three[i][3])
				printf(".");
		}
	}
}

int main()
{
	char IP[3][99] = {"194.85.160.177",
					  "194.85.160.183",
					  "194.85.160.178"};

	printf("please enter three IP address: \n");

	for (int i = 0; i < 3; i++)
		scanf("%s", IP[i]);

	for (int i = 0; i < 3; i++)
		transform(IP[i], i);

	system("pause");
	return 0;
}
