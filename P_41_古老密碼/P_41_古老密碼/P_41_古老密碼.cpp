/******************************************************************
* Name：古老密碼
*
* Goal：給定兩個長度相同且不超過100的字符串，判斷是否能把其中一個字符串的各個字母重
*		排，然後對26個字母做一個一一映射，使得兩個字符串相同。例如，JWPUDJSTVP重排後可
*		以得到WJDUPSJPVT，然後把每個字母映射到它前一個字母（B->A, C->B, …, Z->Y, A->Z），
*		得到VICTORIOUS。輸入兩個字符串，輸出YES或者NO。
*
* Modify record：18/11/12 By Lucas
******************************************************************/

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

void StrToInt(char *a, int *box_a)
{
	for (int i = 0; i < strlen(a); i++)
		box_a[a[i] - 65]++;
}
int Save_location(int box_a_zero[], int temp[])
{
	int count = 0;
	for (int i = 0; i < 26; i++)
		if (box_a_zero[i] != 0)
			temp[count++] = i;
	return count;
}
int exclude_zero(int *box_a_zero, int *exclude_box_a)
{
	int count = 0;
	for (int i = 0; i < 26; i++)
		if (box_a_zero[i] != 0)
			exclude_box_a[count++] = box_a_zero[i];

	return count;
}
void display(int *box_a_zero, int size)
{
	for (int i = 0; i < size; i++)
		printf("%02d ", box_a_zero[i]);
	printf("\n");
}
int intcmp(int *exclude_box_a, int *exclude_box_b, int size)
{

	int count = 0;
	for (int i = 0; i < size; i++)
		if (exclude_box_a[i] == exclude_box_b[i])
			count++;
	if (count == size)
		return 1;
	else
		return 0;
}
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void bubble_sort(int *location_b, int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (location_b[j] > location_b[j + 1])
				swap(&location_b[j], &location_b[j + 1]);
}
void location_right_move(int *location_b, int size)
{
	for (int i = 0; i < 26; i++)
		if (location_b[i] < 25)
			location_b[i]++;
		else
		{
			location_b[i] -= 25;
			bubble_sort(location_b, size);
		}
}
int Check(char *a, char *b)
{
	int box_a_zero[26], box_b_zero[26], location_a[99], location_b[99];
	int exclude_box_a[26], exclude_box_b[26];
	int count_a, count_b, exclude_a, exclude_b;

	if (strlen(a) != strlen(b))
		return 0;

	memset(box_a_zero, 0, sizeof(box_a_zero));
	memset(box_b_zero, 0, sizeof(box_b_zero));

	StrToInt(a, box_a_zero);
	StrToInt(b, box_b_zero);

	exclude_a = exclude_zero(box_a_zero, exclude_box_a);
	exclude_b = exclude_zero(box_b_zero, exclude_box_b);

	count_a = Save_location(box_a_zero, location_a);
	count_b = Save_location(box_b_zero, location_b);

	display(box_a_zero, sizeof(box_a_zero) / 4);
	display(box_b_zero, sizeof(box_b_zero) / 4);
	display(exclude_box_a, exclude_a);
	display(exclude_box_b, exclude_b);
	display(location_a, count_a);
	display(location_b, count_b);
	printf("\n");

	if (intcmp(exclude_box_a, exclude_box_b, sizeof(exclude_box_a) / 4))
		return 1;
	else
		for (int i = 0; i < 26; i++)
		{
			location_right_move(location_b, sizeof(location_b) / 4);
			if (intcmp(location_a, location_b, sizeof(location_a) / 4))
				return 1;
			if (i == 25)
				return 0;
		}
}

int main()
{
	char a[99] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
		 b[99] = "DEFGHIJKLMNOPQRSTUVWXYZABC";
	//	gets(a);
	//	gets(b);
	if (Check(a, b))
		printf("Yes");
	else
		printf("No");

	return 0;
}
