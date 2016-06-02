#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

/***********
 * ������31 ���������������
 * ��Ŀ�� ����һ���������飬������������Ҳ�и�����
 * ������һ���������Ķ��������ɵ�һ�������顣������������
 * �ĺ͵����ֵ��Ҫ��ʱ�临�Ӷ�ΪO(n).
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
    int nGreatestSum = 0x80000000; // ��Сֵ

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
