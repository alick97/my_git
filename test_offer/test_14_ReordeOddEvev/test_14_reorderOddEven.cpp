#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

/***
 * 面试题14： 调整数组顺序使奇数位于偶数前面
 * 题目：输入一个整数数组， 实现一个函数来调整该数组中数字的顺
 * 序，使得所有的奇数位于数组的前半部分，所有的偶数位于该数组的后
 * 半部分。
 ****/

void ReorderOddEven_way1(int *pData, unsigned int length)
{
    if (NULL == pData || 0 == length)
    {
        return;
    }

    int* pBegin = pData;
    int* pEnd = pData + length - 1;

    while (pBegin < pEnd)
    {
        // 找偶数
        while (pBegin < pEnd && (*pBegin & 0x1) == 1)
        {
            pBegin++;
        }

        // 找奇数
        while (pBegin < pEnd && (*pEnd & 0x1) == 0)
        {
            pEnd--;
        }

        if (pBegin < pEnd)
        {
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        }
    }
}



//   使用函数指针
void ReorderOddEven_way2(int *pData, unsigned int length, bool (*func)(int))
{
    if (NULL == pData || 0 == length)
    {
        return;
    }

    int* pBegin = pData;
    int* pEnd = pData + length - 1;

    while (pBegin < pEnd)
    {
        // 找偶数
        while (pBegin < pEnd && !func(*pBegin))
        {
            pBegin++;
        }

        // 找奇数
        while (pBegin < pEnd && func(*pEnd))
        {
            pEnd--;
        }

        if (pBegin < pEnd)
        {
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        }
    }
}

// 判断是不是偶数
bool isEven(int n)
{
    return (n & 1) == 0;
}

void test()
{
    int a[] = {2,1,4,3,5,6,8,7,10,9};
   // ReorderOddEven_way1(a, 10);
    ReorderOddEven_way2(a, 10, isEven);
}



int main()
{
    test();
    return 0;
}
