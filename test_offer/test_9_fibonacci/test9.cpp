#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
/***
 * ������9 쳲���������
 * ��Ŀһ дһ������ ����n ��쳲��������е�n��
 * f(n) 0 ,n = 0    
 * 1 ,n = 1
 * f(n-1) + f(n-2) ,n>1
 **********/

// �ݹ�ⷨ
long long Fibonacci_recurrence(unsigned int n)
{
	if (n <= 1)
	{
		return n;
	}

	return Fibonacci_recurrence(n - 1) + Fibonacci_recurrence(n - 2);
}

// �ǵݹ�ⷨ
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


// ��Ŀ�� һֻ����һ�ο�������1��̨�� ��Ҳ��������2��̨
// �ס������������һ��n��̨���ܹ��ж�����������

// n = 0   0
// n = 1   1
// n = 2   2
// n = 3   3
// n = 4   5
// n>2 ʱ  f(n) = f(n - 1) + f(n - 2) 

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


// ��չ 
// ��������̨�������У������������Ϊ��һֻ����һ�ο���
// ����1��̨�ף�Ҳ��������2��̨�ס�����������Ҳ��������
// n������ʱ����������һ��n��̨���ܹ��ж����������� 
// ��ѧ���ɷ�����֤�� f(n) = 2 ^(n - 1) 

// n = 1          1
// n = 2          2
// n = 3          4
// n = 4          8


// �����Ŀ
// ��2*1��С���� ���Ż�������ȥ���Ǹ���ľ���   
// ���� ��8��2*1��С�������ظ� ����һ��2*8�Ĵ����  ��
// ���ж����ַ���


// ��2*n���� Ϊf(n)
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
