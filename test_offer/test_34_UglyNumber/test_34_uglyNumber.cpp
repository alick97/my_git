#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

/*************
 * 面试题34 丑数
 * 题目：我们把只包含因子2、3和5的数称作丑数。
 * 求从小到大的顺序的第1500个丑数。例如6、8都是丑数，但14不是，
 * 因为它包含因子7. 习惯上把1当作第一个丑数。

******************/

bool IsUgly(int number)
{
    while (number % 2 == 0)
    {
        number /= 2;
    }

    while (number % 3 == 0)
    {
        number /= 3;
    }

    while (number % 5 == 0)
    {
        number /= 5;
    }

    return number == 1 ? true : false;
}

int GetUglyNumber(int index)
{
    if (index <= 0)
    {
        return 0;
    }

    int number = 0;
    int uglycount = 0;

    while (uglycount < index)
    {
        ++number;

        if (IsUgly(number))
        {
            uglycount++;

            //cout <<uglycount <<":"<< number<<endl;
        }
    }

     return number;
}

void test_ugly()
{
    int ugly = GetUglyNumber(1500); // 859963392
}


// 高效方法2

int Min(int number1, int number2, int number3)
{
    int min = (number1 < number2) ? number1:number2;
    min = number3 < min ? number3 : min;
    
    return min;
}



int GetUglyNumber_Solution2(int index)
{
    if (index <= 0)
    {
        return 0;
    }

    int *pUglyNumbers = new int[index];
    pUglyNumbers[0] = 1;
    int nextUglyIndex = 1;

    int *pMultiply2 = pUglyNumbers;
    int *pMultiply3 = pUglyNumbers;
    int *pMultiply5 = pUglyNumbers;

    while (nextUglyIndex < index)
    {
        int min = Min(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);
        pUglyNumbers[nextUglyIndex] = min;

        while (*pMultiply2 * 2 <= pUglyNumbers[nextUglyIndex])
        {
            ++pMultiply2;
        }

         while (*pMultiply3 * 3 <= pUglyNumbers[nextUglyIndex])
        {
            ++pMultiply3;
        }
          while (*pMultiply5 * 5 <= pUglyNumbers[nextUglyIndex])
        {
            ++pMultiply5;
        }

        ++nextUglyIndex;
    }

    int ugly = pUglyNumbers[index - 1];
    delete[] pUglyNumbers;

    return ugly;
}

void test_ugly_method2()
{
    int ugly =  GetUglyNumber_Solution2(1500); // 859963392
}

int main()
{
    //test_ugly();
    test_ugly_method2();
    return 0;
}
