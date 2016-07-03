#include <iostream>
using namespace std;

/*************
 * 面试题40： 数组中只出现一次的数字
 * 题目：一个整型数组里除了两个数字之外，其他的数字都出现了两次。
 * 请写程序找出这两个只出现一次的数字。
 * 要求时间复杂度为O(n)，空间复杂度为O(1)
**********************/


// {2,4,3,6,3,2,5,5}
// 4 6
// 二进制中从低位向高位找第一个1 的位置
unsigned int FindFBitIs1(int num)
{
	unsigned int index = 1;
	while (index != 0)
	{
		if ((num & index) != 0)
		{
			return index;
		}
		index <<= 1;
	}

	return -1;
}

void FindNumAppearOnce(int data[], int length, int* num1, int* num2)
{
	if (data == NULL || length < 2)
	{
		return;
	}

	int resultExclusiveOr = 0;

	for (int i = 0; i < length; i++)
	{
		resultExclusiveOr ^= data[i];
	}

	// 用异或结果 中的一位1 来分两组处理
	unsigned int indexOf1Num = FindFBitIs1(resultExclusiveOr);

	*num1 = *num2 = 0;
	for (int j = 0; j < length; j++)
	{
		if ((data[j] & indexOf1Num) != 0)
		{
			*num1 ^= data[j];
		}
		else
		{
			*num2 ^= data[j];
		}
	}
}



void test()
{
	// {2,4,3,6,3,2,5,5}
// 4 6
	int arr[] = {2,4,3,6,3,2,5,5};
	int num1 , num2;
	num1 = num2 = -1;
	FindNumAppearOnce(arr, sizeof(arr)/sizeof(arr[0]), &num1, &num2);
	cout<<num1<<"---"<<num2<<endl;
}


int main()
{
	test();
	return 0;
}