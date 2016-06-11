#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


/**********
 * 面试题35 第一个只出现一次的字符
 * 题目： 在字符串中找到第一个只出现一次的字符。如
 * 输入"abaccdeff",则输出为'b'。
********************/

char firstNorRepeatChar(char* pString)
{
    if (pString == NULL)
    {
        return '\0';
    }

    const int tableSize = 256;
    unsigned int hashTable[tableSize];

    for (unsigned int i = 0; i < tableSize; i++)
    {
        hashTable[i] = 0;
    }

    char* pHashKey = pString;

    while(*(pHashKey) != '\0')
    {
        hashTable[*(pHashKey++)]++;
    }

    pHashKey = pString;

    while (*pHashKey != '\0')
    {
        if (hashTable[*pHashKey] == 1)
        {
            return *pHashKey;
        }

        pHashKey++;
    }

    return '\0';
}

void test()
{
    char arr[] = "abaccdeff";
    char c_first_one = firstNorRepeatChar(arr);
}


/********
 * 扩展 ：
 * 定义一个函数，输入两个字符串，从第一个字符串中删除在第二个
 * 字符串中出现过的字符。 如 "We are students." 中删除第二个字符串"aeiou" 后 为 "W r Stdnts."
 ************/

void remove_second_ch(char* pFirst, const char* pSecond)
{
    if (pFirst == NULL || pSecond == NULL)
    {
        return;
    }

    const int count = 256;
    int hashTable[count];

    for (int i = 0; i < count ; i++)
    {
        hashTable[i] = 0;
    }

    char* pHashKey = (char*)pSecond;
    // 统计
    while (*pHashKey != '\0')
    {
        hashTable[*pHashKey++]++;
    }

    // 去除第一个字符串 在第二个字符串出现的字符
    pHashKey = pFirst;
    int index = 0;
    while (*pHashKey != '\0')
    {
        if (hashTable[*pHashKey] == 0)
        {
            pFirst[index++] = *pHashKey;
        }

        pHashKey++;
    }
    pFirst[index] = '\0';
}

void test_remove_second_ch()
{
    char first[] = "We are students.";
    char second[] = "aeiou";
    remove_second_ch(first, second); //  "W r Stdnts."
}

//  扩展2 删除字符串中重复的字符
//  扩展3 判断两个字符串是不是同位词 （两个单词 字母相同 字母出现次数相同 如 abc  cba）

int main()
{
  //  test();
    test_remove_second_ch();
    return 0;
}
