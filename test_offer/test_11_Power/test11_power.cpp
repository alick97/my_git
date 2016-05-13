#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
/******
 * 面试题11 数值的整数次方
 * 题目：实现函数double Power(double base, int exponent)
 * 求base的exponent次方。不得使用库函数，同时不需要考虑大  * 数问题
 *******/



//注意 考虑指数是负数 和 零的情况
bool g_invalid_input = false;
bool equal(double num1, double num2);
double PowerWithUnsignedExponent(double base, unsigned int exponent);
double PowerWithUnsignedExponent_way2(double base, unsigned int exponent);

double Power(double base, int exponent)
{
    g_invalid_input = false;

    if (equal (base, 0.0) && exponent < 0)
    {
        g_invalid_input = true;
        return 0.0;
    }

    unsigned int absExponent = (unsigned int)(exponent);

    if (exponent < 0)
    {
        absExponent = (unsigned int)(0 - exponent);
    }

    //double result = PowerWithUnsignedExponent_way2(base, absExponent);
    double result = PowerWithUnsignedExponent(base, absExponent);

    if (exponent < 0)
    {
        result = 1.0 / result;
    }

    return result;
}

bool equal(double num1, double num2)
{
    if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
    {
        return true;
    }
    else
    {
        return false;
    }
}

double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
    double result = 1.0;

    for (unsigned int i = 0; i < exponent; i++)
    {
        result *= base;
    }

    return result;
}


// 更高效的算法
// a^n = a^(n/2) * a^(n/2) n为偶数
// a^n = a^((n - 1)/2) * a^((n - 1)/2) * a  n为奇数

double PowerWithUnsignedExponent_way2(double base, unsigned int exponent)
{
    if (0 == exponent)
    {
        return 1;
    }

    if (1 == exponent)
    {
        return base;
    }

    double result = PowerWithUnsignedExponent(base, exponent >> 1); // 整数 奇数减1除以二 与 基数直接除以二 一样

    result *= result;
    // 判断奇偶 用按位与
    if (exponent & 0x1 == 1)
    {
        result *= base;
    }

    return result;
}


void test()
{
    double d = Power(2, -3);
    d = Power(2, 0);
    d = Power(0, 0); // 1
    d = Power(0, -1); // 
    d = Power(-1,4);
}

int main()
{
    test();
    return 0;
}



