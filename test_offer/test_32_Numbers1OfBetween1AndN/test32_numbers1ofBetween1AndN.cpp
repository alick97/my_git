#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

/*********
 * 面试题32 从1到n整数中1出现的次数
 * 题目： 输入一个整数n， 求从1到n这n个整数的十进制表示中1出现的次数
 * 例如输入13， 从1到12这些数中包含的1的数字有10,1,11和12，
 * 1一共出现了5次
 **********/

// 不考虑时间效率的解法 O(N*log10 N)
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


// 方法二 找规律
// 21345 
// 1-1345
// 第一步 1出现在最高位 1346-21346 、10000-19999 共10000=10^4
// 特殊 如12345 最高位1出现次数不是10^4 而是2346 =  2345+1 除了最高位 剩下的数字加1

// 第二步 1出现在除了最高位的其他四位
// 1346-21345 分为 1346-11345 11346-21345 最高位1,2 两种可能 
//          4位数   一位是1的排列组合    2*10^3 * 2（最高位1,2两种可能）


// 第三步 1-1345 用递归

int NumberOf1(const char* strN);
int PowerBase10(unsigned int n);

int NumbersOf1Between1AndN_method2(int n)
{
    if (n <= 0)
    {
        return 0;
    }

    // 为了下边处理 数字转化成字符串
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

    // 假设strN 为 “21345”
    // numFirstDigit 是数字10000-19999的第一位中的数目
    int numFirstDigit = 0;
    if (first > 1)
    {
        numFirstDigit = PowerBase10(length - 1);
    }
    else
    {
        numFirstDigit = atoi(strN+1) + 1;
    }

    // numOtherDigits 是1346-21345除了第一位之外的数位中的数目
    int numOtherDigits = first * (length - 1) * PowerBase10(length - 2); // 排列组合 除了最高位和剩下的其中一位 剩下的 每位10中可能
    int numRecursive = NumberOf1(strN + 1);// 递归

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
