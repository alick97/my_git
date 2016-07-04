#include <iostream>
using namespace std;
#include <string.h>
/*****************
 * 面试题42： 翻转单词顺序 VS 左旋转字符串
 * 题目一：输入一个英语句子，翻转句子中单词的顺序，但单词内
 * 字符的顺序不变。为简单起见，标点符号和普通字母一样处理。
 * 例如输入字符"I am a student", 则输出为"student a am I".
***************************/

void Reverse(char* pBegin, char* pEnd)
{
	if (pBegin == NULL || pEnd == NULL)
	{
		return;
	}

	while (pBegin < pEnd)
	{
		swap(*pBegin, *pEnd);
		pBegin++;
		pEnd--;
	}
}

char* ReverseSentence(char* pData)
{
	if (pData == NULL)
	{
		return NULL;
	}

	char* pBegin = pData;
	char* pEnd = pData;

	while (*pEnd != '\0')
	{
		pEnd++;
	}

	pEnd--;
	// 翻转整个句子
	Reverse(pBegin, pEnd);

	// 翻转句子中的每个单词
	pBegin = pEnd = pData;

	while (*pBegin != '\0')
	{
		if (*pBegin == ' ')
		{
			*pBegin++;
			*pEnd++;
		}
		else if (*pEnd == ' ' || *pEnd == '\0')
		{
			Reverse(pBegin, --pEnd);
			pBegin = ++pEnd;
		}
		else
		{
			pEnd++;
		}
	}

	return pData;
}

void test_ReverseSentence()
{
	char str[] = "I am a student";
	cout<<str<<endl;
	cout<<ReverseSentence(str)<<endl;
}



/*************
 * 题目二：字符串的左旋操作是把字符串前面的若干个字符转移到字符串的尾部。
 * 请定义一个函数实现字符串的左旋转功能。
 * 比如输入字符串"abcdefg"和数字2，该函数返回左旋转2位得到的结果"cdefgab".
******************/
char* LeftRotateString(char* pStr, int n)
{
	if (pStr != NULL)
	{
		int nLength = strlen(pStr);
		if (nLength > 0 && n > 0 && n < nLength)
		{
			char* pFirstStart = pStr;
			char* pFirstEnd = pStr + n - 1;
			char* pSecondStart = pFirstEnd + 1;
			char* pSecondEnd = pStr + nLength - 1;

			// 翻转字符串前n个字符
			Reverse(pFirstStart, pFirstEnd);

			// 翻转字符串后面字符
			Reverse(pSecondStart, pSecondEnd);

				// 翻转整个字符串
			Reverse(pFirstStart, pSecondEnd);
		}
	}

	return pStr;
}

void test_LeftRotateString()
{
	char str[] = "abcdefg";
	cout<<str<<endl;
	cout<<LeftRotateString(str, 2)<<endl;
}


int main()
{
	//test_ReverseSentence();
	
	test_LeftRotateString();
	return 0;
}