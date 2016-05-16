#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

/***
 * ������14�� ��������˳��ʹ����λ��ż��ǰ��
 * ��Ŀ������һ���������飬 ʵ��һ�����������������������ֵ�˳
 * ��ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ�ڸ�����ĺ�
 * �벿�֡�
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
        // ��ż��
        while (pBegin < pEnd && (*pBegin & 0x1) == 1)
        {
            pBegin++;
        }

        // ������
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



//   ʹ�ú���ָ��
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
        // ��ż��
        while (pBegin < pEnd && !func(*pBegin))
        {
            pBegin++;
        }

        // ������
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

// �ж��ǲ���ż��
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
