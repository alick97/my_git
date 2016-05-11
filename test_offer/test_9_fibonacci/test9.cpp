#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
/***
 * 面试题9 斐波那契数列
 * 题目一 写一个函数 输入n 求斐波那契数列第n项
 * f(n) 0 ,n = 0    
 * 1 ,n = 1
 * f(n-1) + f(n-2) ,n>1
 **********/

// 递归解法
long long Fibonacci_recurrence(unsigned int n)
{
	if (n <= 1)
	{
		return n;
	}

	return Fibonacci_recurrence(n - 1) + Fibonacci_recurrence(n - 2);
}

// 非递归解法
long long Fibonacci_no_recurrence(unsigned n)
{
	if (n < 2)
	{
		return n;
	}

	long long fib_one = 0;
	long long fib_two = 1;
	long long fib_n = 0;

	for (unsigned int i = 2; i <= n; i++)
	{
		fib_n = fib_one + fib_two;
		fib_one = fib_two;
		fib_two = fib_n;
	}

	return fib_n;
}


// 题目二 一只青蛙一次可以跳上1级台阶 ，也可以跳上2级台
// 阶。求该青蛙跳上一个n级台阶总共有多少种跳法？

// n = 0   0
// n = 1   1
// n = 2   2
// n = 3   3
// n = 4   5
// n>2 时  f(n) = f(n - 1) + f(n - 2) 

long long find_way(unsigned n)
{
	if (0 == n)
	{
		return 0;
	}

	if (1 == n)
	{
		return 1;
	}
	if (2 == n)
	{
		return 2;
	}

	return find_way(n - 1) + find_way(n - 2);
}

long long find_way_no_recurrence(unsigned n)
{
	if (0 == n)
	{
		return 0;
	}

	if (1 == n)
	{
		return 1;
	}
	if (2 == n)
	{
		return 2;
	}

	long long one = 1;
	long long two = 2;
	long long cur = 0;
	
	for (unsigned i = 3; i <= n; i++)
	{
		cur =  one + two;
		one = two;
		two = cur;
	}

	return cur;
}


// 扩展 
// 在青蛙跳台阶问题中，如果把条件改为：一只青蛙一次可以
// 跳上1级台阶，也可以跳上2级台阶。。。。。。也可以跳上
// n级，此时该青蛙跳上一个n级台阶总共有多少种跳法？ 
// 数学归纳法可以证明 f(n) = 2 ^(n - 1) 

// n = 1          1
// n = 2          2
// n = 3          4
// n = 4          8


// 相关题目
// 用2*1的小矩形 横着或者竖着去覆盖更大的矩形   
// 请问 用8个2*1的小矩形无重复 覆盖一个2*8的大矩阵  总
// 共有多少种方法


// 记2*n矩阵 为f(n)
// f(0) = 0
// f(1) = 1
// f(2) = 2
// f(3) = 3
// f(4) = 5

long long find_matrix_way(unsigned n)
{
	if (n <= 2)
	{
		return n;
	}

	return find_matrix_way(n - 1) + find_matrix_way(n - 2);
}


void test()
{
	long long ret;
	ret = Fibonacci_recurrence(4); // 3
	ret = Fibonacci_no_recurrence(4);

	ret = Fibonacci_recurrence(6); // 
	ret = Fibonacci_no_recurrence(6);

	ret = find_way(4); // 5
	ret = find_way_no_recurrence(4);

	ret = find_matrix_way(4); // 5


}


int main()
{
	test();
	return 0;
}
