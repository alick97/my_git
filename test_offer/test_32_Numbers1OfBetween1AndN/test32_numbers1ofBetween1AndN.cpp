#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

/*********
 * ������32 ��1��n������1���ֵĴ���
 * ��Ŀ�� ����һ������n�� ���1��n��n��������ʮ���Ʊ�ʾ��1���ֵĴ���
 * ��������13�� ��1��12��Щ���а�����1��������10,1,11��12��
 * 1һ��������5��
 **********/

// ������ʱ��Ч�ʵĽⷨ O(N*log10 N)
unsigned int  NumbersOf1(unsigned int n)
{
    unsigned int count = 0;

   while (n > 0)
   {
       if (1 == n % 10)
       {
           count++;
       }
       n /= 10;
   }

   return count;
}

int NumbersOf1Between1AndN_method1(unsigned int n)
{
    int count = 0;
    for (unsigned int i = 0; i <= n; i++)
    {
        count += NumbersOf1(i);
    }

    return count;
}

void test_NumbersOf1Between1AndN_method1()
{
    int n = 12;
    int ret = NumbersOf1Between1AndN_method1(n);
}


// ������ �ҹ���
// 21345 
// 1-1345
// ��һ�� 1���������λ 1346-21346 ��10000-19999 ��10000=10^4
// ���� ��12345 ���λ1���ִ�������10^4 ����2346 =  2345+1 �������λ ʣ�µ����ּ�1

// �ڶ��� 1�����ڳ������λ��������λ
// 1346-21345 ��Ϊ 1346-11345 11346-21345 ���λ1,2 ���ֿ��� 
//          4λ��   һλ��1���������    2*10^3 * 2�����λ1,2���ֿ��ܣ�


// ������ 1-1345 �õݹ�

int NumberOf1(const char* strN);
int PowerBase10(unsigned int n);

int NumbersOf1Between1AndN_method2(int n)
{
    if (n <= 0)
    {
        return 0;
    }

    // Ϊ���±ߴ��� ����ת�����ַ���
    char strN[50];
    sprintf(strN, "%d", n);

    return NumberOf1(strN);
}

int NumberOf1(const char* strN)
{
    if (!*strN || *strN < '0' || *strN > '9' || *strN =='\0')
    {
        return 0;
    }

    int first = *strN - '0';
    unsigned int length = static_cast<unsigned int>(strlen(strN));

    if (length == 1 && first == 0)
    {
        return 0;
    }

    if (length == 1 && first > 0)
    {
        return 1;
    }

    // ����strN Ϊ ��21345��
    // numFirstDigit ������10000-19999�ĵ�һλ�е���Ŀ
    int numFirstDigit = 0;
    if (first > 1)
    {
        numFirstDigit = PowerBase10(length - 1);
    }
    else
    {
        numFirstDigit = atoi(strN+1) + 1;
    }

    // numOtherDigits ��1346-21345���˵�һλ֮�����λ�е���Ŀ
    int numOtherDigits = first * (length - 1) * PowerBase10(length - 2); // ������� �������λ��ʣ�µ�����һλ ʣ�µ� ÿλ10�п���
    int numRecursive = NumberOf1(strN + 1);// �ݹ�

    return numFirstDigit + numOtherDigits+ numRecursive;


}

int PowerBase10(unsigned int n)
{
    int result = 1;
    for (unsigned int i = 0; i < n; i++)
    {
        result *= 10;
    }

    return result;
}

void test_NumbersOf1Between1AndN_method2()
{
    int n = 12;
    int ret = NumbersOf1Between1AndN_method2(n);
}

int main()
{
    //test_NumbersOf1Between1AndN_method1();
    test_NumbersOf1Between1AndN_method2();
    return 0;
}
