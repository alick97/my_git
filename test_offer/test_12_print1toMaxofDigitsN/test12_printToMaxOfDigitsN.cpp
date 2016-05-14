#if 0
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;

bool Increment(char* number);
void PrintNumber(const char* number);

void PrintToMaxOfDigitN(int n)
{
    if (n <= 0)
    {
        return;
    }

    char* number = new char[n + 1];
    memset(number, '0', n);
    number[n] = '\0';

    while (!Increment(number))
    {
        PrintNumber(number);
    }

    delete[] number;
}

bool Increment(char* number)
{
    assert(number);
    bool isOverflow = false; // 是否到达n
    int nTakeOver = 0; // 进位
    int nLength = strlen(number);

    for (int i = nLength - 1; i >= 0; i--)
    {
        int nSum =  number[i] - '0' + nTakeOver;

        if (i == nLength - 1) // 最低位加一
        {
            nSum++;
        }

        if (nSum >= 10)
        {
            if (0 == i) // 最高位进位 说明到最大值
            {
                isOverflow = true;
            }
            else
            {
                nSum -= 10;
                nTakeOver = 1;
                number[i] = '0' + nSum;
            }
        }
        else
        {
            number[i] = '0' + nSum;
            break;
        }
    }

    return isOverflow;
}

void PrintNumber(const char* number)
{
    assert(number);
    bool isBingining0 = true;
    int nLength = strlen(number);

    while ('0' == *number)
    {
        number++;
    }

    cout<<number<<endl;
}


// 方法二 递归写法
void PrintToMaxofDigitRecursively(char* number,int length, int index);


void PrintToMaxofNDigits_recursion(int n)
{
    if (n <= 0)
    {
        return;
    }

    char* number = new char[n + 1];
    number[n] = '\0';

    for (int i = 0; i < 10; i++)
    {
        number[0] = i + '0';
        PrintToMaxofDigitRecursively(number, n, 0);
    }

    delete[] number;
}

void PrintToMaxofDigitRecursively(char* number,int length, int index)
{
    if (index == length - 1)
    {
        PrintNumber(number);
        return;
    }

    for (int i = 0; i < 10; i++)
    {
        number[index + 1]  = i + '0';
        PrintToMaxofDigitRecursively(number, length, index + 1);
    }
}





int main()
{
    //PrintToMaxOfDigitN(4);
    PrintToMaxofNDigits_recursion(4);
    return 0;
}

#endif