#include <iostream>
using namespace std;


/*****************
 * 面试题41 ：和为s的两个数字VS和为s的连续正数序列
 * 题目一：输入一个【递增排序】的数组和一个数字s，在数组中查找两个数，
 * 使得它们的和正好是s。如果有多对数字的和等于s，输出任意一对即可。
 * 例如输入{1,2,4,7,11,15}和数字15,4+11=15，因此输出4和11

**********************/

bool FindNumbersWithSum(const int data[],const int length, const int sum, int* num1, int* num2)
{
	bool found = false;
	if (length < 1 || num1 == NULL || num2 == NULL)
	{
		return false;
	}

	int end = length - 1;
	int start = 0;

	while (start < end)
	{
		long int curSum = data[start] + data[end];

		if (curSum == sum)
		{
			*num1 = data[start];
			*num2 = data[end];
			found = true;
			break;
		}
		else if (curSum > sum)
		{
			end--;
		}
		else
		{
			start++;
		}
	}
	

	return found;
}


void test_FindNumbersWithSum()
{
	int data[] = {1,2,4,7,11,15};
	int num1,num2;
	num1 = num2 = -1;
	FindNumbersWithSum(data, sizeof(data)/sizeof(data[0]), 15, &num1, &num2);
	cout<<num1<<"------"<<num2<<endl;

}
							 
/************
 *  题目二：输入一个正数s，打印出所有和为s的连续正数序列（至少含有两个数）
 * 例如输入15，由于1+2+3+4+5=4+5+6=7+8=15
 * 所以结果打印出来3个连续的序列1-5,4-6,和7-8.
**********************/

void PrintContinousSequence(int small, int big);

void FindContinousSequence(const int sum)
{
	//至少含有两个数
	if (sum < 3)
	{
		return;
	}

	int small = 1;
	int big = 2;
	int middle = (1 + sum) / 2;
	int curSum = small + big;

	while (small < middle)
	{
		if (curSum == sum)
		{
			PrintContinousSequence(small, big);
		}

		while (curSum > sum && small < middle)
		{
			curSum -= small;
			small++;

			if (curSum == sum)
			{
				PrintContinousSequence(small, big);
			}
		}

		big++;
		curSum += big;
	}
}

void PrintContinousSequence(int small, int big)
{
	for (int i = small; i <= big; i++)
	{
		cout<<i<<"  ";
	}
	cout<<endl;
}


void test_FindContinousSequence()
{
	FindContinousSequence(15);
}

int main()
{
	//test_FindNumbersWithSum();
	test_FindContinousSequence();
	return 0;
}