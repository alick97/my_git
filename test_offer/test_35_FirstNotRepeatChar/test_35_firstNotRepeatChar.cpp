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

}

void test()
{
    char arr[] = "abaccdeff";
    char c_first_one = firstNorRepeatChar(arr);
}


int main()
{
    test();
    return 0;
}
