#include <iostream>
using namespace std;

/************
 * 面试题47：不用加减乘除做加法
 * 题目：写一个函数，求两个整数之和，要求在函数体内不得使用+，-，*，/四则运算符号。
 * (利用位运算)
*******************/

int Add(int num1, int num2)
{
	int sum, carry;
	do 
	{
		sum = num1 ^ num2;
		carry = (num1 & num2) << 1;
		num1 = sum;
		num2 = carry;
	}while(num2 != 0);

	return num1;
}

void test_Add()
{
	cout<<Add(1,2)<<endl;
	cout<<Add(-1,2)<<endl;
	cout<<Add(-1,-2)<<endl;
}

// 相关问题
// 不使用心得变量交换两个变量的值
// 方法一 基于加减法
void swap_method1(int& number1, int& number2)
{
	number1 = number1 + number2;
	number2 = number1 - number2;
	number1 = number1 - number2;
}
// 方法二 基于异或运算
void swap_method2(int& number1, int& number2)
{
	number1 = number1 ^ number2;
	number2 = number1 ^ number2;
	number1 = number1 ^ number2;
}

void test_swap()
{
	int a = 1; int b = -1;

	cout<<a<<"      "<<b<<endl;
	swap_method1(a, b);
	cout<<a<<"      "<<b<<endl;
	swap_method2(a, b);
	cout<<a<<"      "<<b<<endl;

}

int main()
{
	//test_Add();

	test_swap();
	return 0;
}
