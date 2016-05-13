#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
/******
 * ������11 ��ֵ�������η�
 * ��Ŀ��ʵ�ֺ���double Power(double base, int exponent)
 * ��base��exponent�η�������ʹ�ÿ⺯����ͬʱ����Ҫ���Ǵ�  * ������
 *******/



//ע�� ����ָ���Ǹ��� �� ������
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


// ����Ч���㷨
// a^n = a^(n/2) * a^(n/2) nΪż��
// a^n = a^((n - 1)/2) * a^((n - 1)/2) * a  nΪ����

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

    double result = PowerWithUnsignedExponent(base, exponent >> 1); // ���� ������1���Զ� �� ����ֱ�ӳ��Զ� һ��

    result *= result;
    // �ж���ż �ð�λ��
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



