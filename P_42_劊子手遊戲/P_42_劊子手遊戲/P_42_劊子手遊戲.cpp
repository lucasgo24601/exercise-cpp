/******************************************************************
* Name：劊子手遊戲
*
* Goal：劊子手遊戲其實是一款猜單詞遊戲，遊戲規則是這樣的：計算機想一個單詞
*		讓你猜，你每次可以猜一個字母。如果單詞裡有
*		那個字母，所有該字母會顯示出來；如果沒有那
*		個字母，則計算機會在一幅“劊子手”畫上填一
*		筆。這幅畫一共需要7筆就能完成，因此你最多
*		只能錯6次。注意，猜一個已經猜過的字母也算
*		錯。
*		在本題中，你的任務是編寫一個“裁判”程
*		序，輸入單詞和玩家的猜測，判斷玩家贏了
*		（You win.）、輸了（You lose.）還是放棄了
*		（You chickened out.）。每組數據包含3行，第1
*		行是遊戲編號（-1為輸入結束標記），第2行是
*		計算機想的單詞，第3行是玩家的猜測。後兩行
*		保證只含小寫字母。
*
* Modify record：18/11/12 By Lucas
******************************************************************/

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

int ans_printf[6];

void guess(char report, char *ans)
{
	for (unsigned int i = 0; i < strlen(ans); i++)
		if (report == ans[i])
			ans_printf[i] = report;
}
void display()
{

	for (int i = 0; i < 6; i++)
		if (ans_printf[i] != 0)
			printf(" %c ", ans_printf[i]);
		else
			printf(" _ ");

	printf("\n");
}
int main()
{
	char ans[7];
	char re;

	memset(ans_printf, 0, sizeof(ans_printf) / sizeof(int));

	scanf("%s", ans);
	system("CLS");
	for (int i = 0; i < 6; i++)
	{
		int count = 0;
		scanf("\n%c", &re);
		system("CLS");
		guess(re, ans);
		display();
		for (int j = 0; j < 6; j++)
			if (ans_printf[j] != 0)
				count++;
		if (count == 6)
		{
			printf("You win\n");
			system("pause");
			return 0;
		}
		else
			printf("you have %d chioce\n\n", 6 - i - 1);
	}
	printf("You lost\n");

	system("pause");
	return 0;
}
