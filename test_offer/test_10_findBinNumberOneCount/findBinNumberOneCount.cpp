#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

/***
 * 面试题10： 二进制中1的个数
 * 题目： 请输入一个函数，输入一个整数，输出该整数二进制表示中1的个数。例如把9表示成二进制是1001，有2位是1.因此如果输入6，该函数输出2.
 ***/

// 解法一
// 对于负数  死循环
int NumberOf1_way1(int n)
{
	int count = 0;
	while (n)
	{
		if (n & 1)
		{
			count++;
		}
		n >>= 1;
	}
	return count;
}


// 解法2
int NumberOf1_way2(int n)
{
	int count = 0;
	unsigned int flag = 1;
	while (flag)
	{
		if (n & flag)
		{
			count++;
		}
		
		flag <<= 1;
	}
	return count;
}

// 解法3   （最高效）
int NumberOf1_way3(int n)
{
	int count = 0;
	while (n)
	{
		count++;
		n = (n - 1) & n; // 每次去除右边第一个出现的1
	}
	
	return count;
}


void test()
{
	int n = NumberOf1_way1(4);
	n = NumberOf1_way2(4);
	n = NumberOf1_way3(4);
	n = NumberOf1_way2(-1);
	n = NumberOf1_way3(-1);


	// 死循环n = NumberOf1_way1(-2);
}


int main()
{
	test();	
	return 0;
}

