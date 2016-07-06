#include <iostream>
using namespace std;

/*************
 * 面试题44： 扑克牌的顺子
 * 题目：从扑克牌中随机抽5张牌，判断是不是一个顺子，即这五张牌是不是来来连续的。
 * 2-10为数字本身，A为1， J为11，Q为12，K为13，而大王、小王可以看成任意数字。
*****************/

int compare(const void* arg1, const void* arg2);

bool IsContinuous(int* numbers, int length)
{
	if (numbers == NULL || length < 1)
	{
		return false;
	}

	qsort(numbers, length, sizeof(int),  compare);

	int numberOfZero = 0; // 大小王的个数
	int numberOfGap = 0; // 排序后各个牌数 之间的间隔之和

	// 统计数组中0的个数
	for (int i = 0; i < length && numbers[i] == 0; i++)
	{
		++numberOfZero;
	}

	// 统计数组中的间隔数目
	int small = numberOfZero;
	int big = small + 1;

	while (big < length)
	{
		// 有对子 一定不是顺子
		if (numbers[small] == numbers[big])
		{
			return false;
		}

		numberOfGap += numbers[big] - numbers[small] - 1;
		small = big;
		big++;
	}

	return numberOfGap > numberOfZero ? false : true;
}

int compare(const void* arg1, const void* arg2)
{
	return *(int *)arg1 - *(int *)arg2;
}

void test()
{
	int arr1[] = {1,2,3,0,0};
	int arr2[] = {1,0,3,0,0};
	int arr3[] = {1,2,3,5,7};

	cout<<IsContinuous(arr1, 5)<<endl;
	cout<<IsContinuous(arr2, 5)<<endl;
	cout<<IsContinuous(arr3, 5)<<endl;
}

int main()
{
	test();
	return 0;
}