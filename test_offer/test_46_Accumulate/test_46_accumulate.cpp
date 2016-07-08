#include <iostream>
using namespace std;

/**************
 * 面试题46： 求1+2+3+...+n
 * 题目：求1+2+3+...+n，要求不能使用乘除法、for\while\if\else\switch case
 * 等关键字以及条件判断语句(A?B:C)
********************/

// 解法一 ：利用构造函数求解
class Temp
{
public:
	Temp()
	{
		N++;
		Sum += N;
	}

	static void Reset()
	{
		N = 0;
		Sum = 0;
	}

	static unsigned int GetSum()
	{
		return Sum;
	}
private:
	static unsigned int N;
	static unsigned int Sum;
};

unsigned int Temp::N = 0;
unsigned int Temp::Sum = 0;

unsigned int Sum_Solution1(unsigned int n)
{
	Temp::Reset();

	Temp *p = new Temp[n];
	delete[] p;
	p = NULL;

	return Temp::GetSum();
}

void test_Temp()
{
	cout<<Sum_Solution1(5)<<endl;; // 15
}

// 解法二： 利用虚函数求解
class A;
A* Array[2];

class A
{
public:
	virtual unsigned int Sum(unsigned int n)
	{
		return 0;
	}
}; 

class B:public A
{
public:
	virtual unsigned int Sum(unsigned int n)
	{
		return Array[!!n]->Sum(n - 1) + n; // !!两次讲int-》bool类型
	}
};

int Sum_Solution2(unsigned int n)
{
	A a;
	B b;
	Array[0] = &a;
	Array[1] = &b;

	int value = Array[1]->Sum(n);

	return value;
}


void test_AB()
{
	cout<<Sum_Solution2(5)<<endl;; // 15
}

// 解法三： 利用函数指针求解
typedef unsigned int (*fun)(unsigned int);

unsigned int Solution3_Teminator(unsigned int n)
{
	return 0;
}

unsigned int Sum_Solution3(unsigned int n)
{
	static fun f[2] = {Solution3_Teminator, Sum_Solution3};
	return n + f[!!n](n- 1);
}

void test_Sum_Solution3()
{
	cout<<Sum_Solution3(5)<<endl;; // 15
}

// 解法四：利用模板类型求解
template <unsigned int n>
struct Sum_Solution4
{
	enum Value { N = Sum_Solution4< n - 1>::N + n};
};

template<>
struct Sum_Solution4<1>
{
	enum Value {N = 1};
};

void test_Sum_Solution4()
{
	cout<<Sum_Solution4<5>::N<<endl; // 15
}

int main()
{
	//test_Temp();
	//test_AB();
	//test_Sum_Solution3();
	test_Sum_Solution4();
	return 0;
}