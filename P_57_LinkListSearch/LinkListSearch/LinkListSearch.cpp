#pragma region 題目

// 使用Link List，資料量分別為 100萬、200萬、400萬、800萬、1600萬筆
// 單筆資料為6個隨機產生英文字母辨識字，在以隨機產生6個英文字母為答案
// 以此答案進行搜尋 1萬、10萬、100萬 次，之後輸出其時間
// 1. 線性搜尋
// 2. 遞迴2元搜尋
// 3. 跌代2元搜尋

#pragma endregion

#pragma region 標頭檔

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

#pragma endregion

using namespace std;

// ------------------------Struct--------------------------------
// 也就是使用者可以自行定義一個資料型態，像是經典示範
// 1. struct SString {  char[]; }  ，其意思為：宣告一個自定義的資料型態，他叫做SString，然後他是由字元陣列所組成
// 2. struct Student { string Name; int StudentNumber; }
// 其意思為：宣告一個自定義的資料型態，他叫做Student，然後他是由字串和Int數字所組成
//------------------------------------------------------------------
// 如何使用它：
// Student LLint_8787; 這樣就宣告一個空變數叫做LLint_8787，然後她的資料型態是Student，而Student資料型態是由，1. string 2. int 所組成
// LLint_8787.Name = "8787師父";
// LLint_8787.StudentNumber = "9487";
// cout << LLint_8787.Name << LLint_8787.StudentNumber;         此處就會顯示 8787師父 和 9487

// ------------------------Link List--------------------------------
// 1. 連結串列：項目資料中即含有下一筆資料的位址，每個項目稱為一個節點 (Node)，
//    每個節點含有兩個欄位：
//    a. 資訊欄 (Information field)  b. 下一位址欄 (Next address field)
//------------------------------------------------------------------
// 簡單說就是 1. 先自己定義一個Struct，此Struct將被用於建構陣列的元素
//           2. 以該Struct 去宣告陣列
//           3. 然後該Struct 必須分兩大類屬性， 第一大類為使用者定義的資料類型，第二大類為下一個陣列元素的位址
// https://ppt.cc/fOpVIx@.png 參考圖片

#pragma region 自定義 常數和資料型態

#define OneMillion 1000000
#define TenThousand 10000
#define CharSize 7
#define Null NULL // 自身使用習慣

typedef unsigned long long LLint;
typedef struct NodeType *NODEPTR; // 陣列宣告簡單化

#pragma endregion

NODEPTR Root = NULL; // Root Link List 的總結點

struct NodeType
{
	char *Info = new char[7];	   // 使用者的資料，也就是題目說的 6 個英文字母
	struct NodeType *Left, *Right; // 指向左右子樹的指標
};

char *CreateRandomWord()
{
	// 產生亂數6個字母陣列
	char *InsertData = new char[CharSize];

	for (int i = 0; i < CharSize - 1; i++)
		InsertData[i] = rand() % 26 + 65;

	InsertData[CharSize - 1] = '\0'; // 加入\0為提供Debug可視性

	return InsertData;
}

LLint CharToBit(char *strData)
{
	// 將字串轉換ASCII再轉換成二進制，分布在二進制陣列，並轉換成數字
	// EX:		P		H		Q		G		H		V
	//		    80		72		81		71		72		86
	//  -65     15		7		16		6		7		21
	//        1111		111   10000    110     111   10101
	//       01111    00111   10000  00110   00111   10101     填滿5Bit
	//   串     011110011110000001100011110101 並回傳成10進制

	LLint Ans = 0;
	for (int i = 0; i < CharSize - 1; i++)
	{
		int temp = (strData[i] - 65) << (5 * (CharSize - 2 - i));
		Ans = Ans | temp;
	}

	return Ans;
}

void Insert(char *strData)
{
	NODEPTR NewNode = Null;
	NewNode = (NODEPTR)malloc(sizeof(NodeType)); // 配置新節點記憶體，使用動態方式新增

	char *temp = new char[CharSize];
	strncpy(temp, strData, CharSize - 1);
	temp[CharSize - 1] = '\0';

	NewNode->Info = temp;				   // 將新節點的Info更新
	NewNode->Right = NewNode->Left = Null; // Null 為終點

	buffer = NowNode->Info;
	LLint intSearch = atol(buffer);

	buffer = SearchAns;
	LLint intSearchAns = atol(buffer);

	if (Root == NULL)
		Root = NewNode; // 第一次使用的話： Root --> NewNode_1 --> Null
	else
	{
		NewNode->Right = Root->Right; // 第二次使用的話： NewNode_2 -->   NewNode_1 --> Null
		Root->Right = NewNode;		  // 第二次使用的話：Root --> NewNode_2
	}
}

LLint LineSearch(char *strData)
{
	NODEPTR NowNode = Root; // 使用新的Link List去複製Root，是為了保護Root避免直接操作Root

	LLint count = 0;

	for (LLint i = 0;; i++)
	{
		count++;
		NowNode = NowNode->Right; // 進行線性搜尋

		if (NowNode == Null) // 如果到達終點的話，那麼必為搜尋不到
			break;

		if (CharToBit(NowNode->Info) == CharToBit(strData)) // 找到相同的資料
			return count;
	}

	return -1;
}
int LineySearch_Time(char **InsertData, bool *Bitmap, LLint DataLength, LLint SearchCount)
{

	for (LLint i = 0; i < DataLength; i++)
		Insert(InsertData[i]); // 將資料插入Root內

	NODEPTR First = Root; // 複製Root，當備用

	clock_t Start;
	Start = clock(); // 紀錄開始時間

	for (int i = 0; i < SearchCount; i++)
	{
		char *SearchAns = new char[CharSize];
		SearchAns = CreateRandomWord(); // 獲取搜尋答案

		if (Bitmap[CharToBit(SearchAns)] == false) // 從Bitmap找，如果沒有則直接下一筆搜尋
			continue;

		Root = First; // 此部分可以取消，這只是方便Debug用的

		// 如果Bitmap存在過Ans，那麼就進行搜尋找出在Link List的位置
		LLint FineIndex = LineSearch(SearchAns);

		if (FineIndex == -1)
			cout << "error in Line" << endl;

		// SearchAns = 6個英文字母答案
		// Bitmap[CharToBit(SearchAns)] = 判斷6個英文字母的存在
		// FineIndex = 存在的話則位於Link List的哪邊
	}

	clock_t End;
	End = clock();

	return End - Start;
}

int BinarySearchIteration(char *SearchAns)
{
	NODEPTR NowNode = Root;
	while (NowNode != NULL)
	{
		if (NowNode->Info == SearchAns) //找到了
			return 1;
		else
		{
			char *buffer = new char[90];

			buffer = NowNode->Info;
			LLint intSearch = atol(buffer);

			buffer = SearchAns;
			LLint intSearchAns = atol(buffer);

			if (intSearch < intSearchAns) // 比較資料
				NowNode = NowNode->Right; // 左子樹
		}
	}
	return -1;
}
int BinarySearchIteration_Time(bool *Bitmap, NODEPTR Root, LLint DataLength, LLint SearchCount)
{
	// 因為二元搜尋只適用於：以排序的數列組合
	// 所以將進行以下操作轉換成合法搜尋的Data
	// 1. 先將亂數字母轉成ASCII數列組合
	// 2. 將資料轉換成Bitmap
	// 3. 尋訪Bitmap以達到排序功能
	// 4. 依靠Bitmap的特點過濾重複數據

	for (LLint i = 0; i < pow(2, 30); i++)
	{
		if (Bitmap[i])
		{
			char *Temp = new char[99];
			sprintf(Temp, "%d", i);
			Insert(Temp);
		}
	}
	NODEPTR First = Root; // 備份

	clock_t Start;
	Start = clock();

	for (int i = 0; i < SearchCount; i++)
	{
		char *SearchAns = new char[CharSize];
		SearchAns = CreateRandomWord(); // 獲取搜尋答案

		if (Bitmap[CharToBit(SearchAns)] == false) // 如果早已不存在Bitmap的話，就沒需要進行尋訪
			continue;

		Root = First;

		char *Temp = new char[99];
		sprintf(Temp, "%d", CharToBit(SearchAns)); // 將其字母字串轉成ASCII

		LLint FindeIndex = BinarySearchIteration(Temp); // 以此ASCII數字陣列搜尋Link List 資料

		if (FindeIndex == -1)
			cout << "----" << Temp << endl;
	}

	clock_t End;
	End = clock();

	return End - Start;
}

int BinarySearchRecursion(char *SearchAns)
{
	NODEPTR NowNode = Root;
	if (NowNode != NULL)
		return -1;
	if (NowNode->Info == SearchAns) // 找到了
		return 1;
	else
	{
		char *buffer = new char[90];

		buffer = NowNode->Info;
		LLint intSearch = atol(buffer); // 字串轉數字的函數

		buffer = SearchAns;
		LLint intSearchAns = atol(buffer);

		if (intSearch > intSearchAns) // 比較資料
			NowNode = NowNode->Left;  // 左子樹
		else
			NowNode = NowNode->Right; // 右子樹

		return BinarySearchRecursion(SearchAns);
	}
}
int BinarySearchRecursion_Time(bool *Bitmap, NODEPTR Root, LLint DataLength, LLint SearchCount)
{
	for (LLint i = 0; i < pow(2, 30); i++)
		if (Bitmap[i])
		{
			char *Temp = new char[90];
			sprintf(Temp, "%d", i);
			Insert(Temp);
		}

	NODEPTR First = Root;

	clock_t Start;
	Start = clock();

	for (int i = 0; i < SearchCount; i++)
	{
		char *SearchAns = new char[CharSize];
		SearchAns = CreateRandomWord(); // 獲取數值

		if (Bitmap[CharToBit(SearchAns)] == false)
			continue;

		Root = First;

		char *Temp = new char[99];
		sprintf(Temp, "%d", CharToBit(SearchAns));

		LLint FindeIndex = BinarySearchRecursion(Temp);
	}

	clock_t End;
	End = clock();

	return End - Start;
}

void Search(LLint DataLength, LLint SearchCount)
{
	char **InsertData = new char *[DataLength]; // 宣告字元二維陣列，先初始化第一維 => InsertData[1百萬]
	for (int i = 0; i < DataLength; i++)
		InsertData[i] = new char[CharSize]; // 初始化並定義第二維大小，InsertData[100萬][6個英文字母 + '\0']

	for (LLint i = 0; i < DataLength; i++)
		InsertData[i] = CreateRandomWord(); // 產生100萬筆亂數資料填入陣列當中

	bool *Bitmap = new bool[pow(2, 30)]; // 定義Bitmap => 大小為 2的30次方
	memset(Bitmap, false, pow(2, 30));	 // 將其全部初始化成False

	for (int i = 0; i < DataLength; i++)
		Bitmap[CharToBit(InsertData[i])] = true;

	// 執行二元搜尋前，必須先排序，但是資料量太大，無法直接對其直接進行排序
	// 所以將其字串轉換成ASCII數字，並將其Bitmap化
	// Bitmap化，可以快速判斷搜尋的數據存不存在 Ex: 搜尋ABCD是否存在數據內，只需 Bitmap[ 轉換成ASCII數字(ABCD)  ] == True
	// 能夠大幅減少LinkList 搜尋時間

	// 6個英文字母為一筆資料，一個英文字母大小可以用5個Bit去存放(26個英文字母 < 2的5次方 32 )
	// 所以6個英文字母的話，應為 30個Bit去代表 = 2^30 = 10億
	// 完全符合題目規定的 "1600萬筆資料，單筆資料為6個英文字母建構"

	cout << "使用Line Search 搜尋次數：" << SearchCount << " 資料大小： " << DataLength << " 其時間為：" << LineySearch_Time(InsertData, Bitmap, DataLength, SearchCount) << endl;
	Root = Null;
	cout << "使用迭代 Binary Search 搜尋次數：" << SearchCount << " 資料大小： " << DataLength << " 其時間為：" << BinarySearchIteration_Time(Bitmap, Root, DataLength, SearchCount) << endl;
	Root = Null;
	cout << "使用遞迴 Binary Search 搜尋次數：" << SearchCount << " 資料大小： " << DataLength << " 其時間為：" << BinarySearchRecursion_Time(Bitmap, Root, DataLength, SearchCount) << endl;
}

int main()
{

	cout << "--------------" << endl;

	Search(OneMillion, TenThousand);
	/*	Search(OneMillion, TenThousand * 10);
	Search(OneMillion, OneMillion);

	cout << "--------------"<<endl;

	Search(OneMillion * 2, TenThousand);
	Search(OneMillion * 2, TenThousand * 10);
	Search(OneMillion * 2, OneMillion);

	cout << "--------------" << endl;

	Search(OneMillion * 4, TenThousand);
	Search(OneMillion * 4, TenThousand * 10);
	Search(OneMillion * 4, OneMillion);

	cout << "--------------" << endl;

	Search(OneMillion * 8, TenThousand);
	Search(OneMillion * 8, TenThousand * 10);
	Search(OneMillion * 8, OneMillion);

	cout << "--------------" << endl;

	Search(OneMillion * 16, TenThousand);
	Search(OneMillion * 16, TenThousand * 10);
	Search(OneMillion * 16, OneMillion);

	cout << "--------------" << endl;*/
}
