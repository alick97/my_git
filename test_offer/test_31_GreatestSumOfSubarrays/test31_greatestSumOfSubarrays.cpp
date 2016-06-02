#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

/***********
 * 面试题31 连续子数组的最大和
 * 题目： 输入一个整型数组，数组里有正数也有负数。
 * 数组中一个或连续的多个整数组成的一个子数组。求所有子数组
 * 的和的最大值。要求时间复杂度为O(n).
**************/

bool g_invalid_input = false;

int FindGreatestSumOfSubArray(int* pData, int nLength)
{
    g_invalid_input = false;

    if (NULL == pData || nLength <= 0)
    {
        g_invalid_input = true;
        return 0;
    }

    int nCurSum = 0;
    int nGreatestSum = 0x80000000; // 最小值

    for (int i = 0; i < nLength; i++)
    {
        if (nCurSum <= 0)
        {
            nCurSum = pData[i];
        }
        else
        {
            nCurSum += pData[i];
        }

        if (nCurSum > nGreatestSum)
        {
            nGreatestSum = nCurSum;
        }
    }

    return nGreatestSum;
}

void test()
{
    int arr[] = {1,-2,3,10,-4,7,2,-5};
    int ret = FindGreatestSumOfSubArray(arr, 8);
}

int main()
{
    test();
    return 0;
}
