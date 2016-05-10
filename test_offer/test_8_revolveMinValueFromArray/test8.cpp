#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
/******
 * 面试题8 旋转数组的最小数字
 * 题目：把一个数组最开始的若干的元素搬到数组的末尾，我
 * 们称之为数组的旋转。 输入一个递归排序的数组的旋转，
 * 输出旋转数组的最小元素。例如数组{3,4,5,1,2}为数组
 * {1,,2，3,4,5，}的一个旋转，该数组最小值为1.
 ******/
int MinInOrder(const int* numbers, int left_index, int right_index);

int Min(const int* numbers, int length)
{
	if (NULL == numbers || length <= 0)
	{
		throw exception("Invalid parameters");
	}

	int left_index = 0;
	int right_index = length - 1;

	int mid_index = left_index;	//	防止左边小于右边 是有序递增的情况

	while (numbers[left_index] >= numbers[right_index])
	{
		// 停止条件 范围缩到最小 右边就是最小的
		if (right_index - left_index == 1)
		{
			mid_index = right_index;
			break;
		}

		mid_index = left_index / 2 + right_index / 2;
		
		// 特殊情况 左边、右边、中间相等 可能越过最小值
		// 如 101111
		// 只能用顺序查找
		if (numbers[left_index] == numbers[mid_index] && numbers[mid_index] == numbers[right_index])
		{
			return MinInOrder(numbers, left_index, right_index);
		}


		if (numbers[mid_index] >= numbers[left_index])
		{
			left_index = mid_index;
		}
		else if (numbers[mid_index] <= numbers[right_index])
		{
			right_index = mid_index;
		}
	}

	return numbers[right_index];
}

int MinInOrder(const int* numbers, int left_index, int right_index)
{
	int min = numbers[left_index];
	bool con = false;
	for (int i = left_index + 1; i <= right_index; i++)
	{
		if (min > numbers[i])
		{
			min = numbers[i];
			con = true;
		}

		if (con)
		{
			return min;
		}
	}

	return min;
}


void test()
{
	int arr1[] = {5,5,6,7,8,1,2,3,4,5};
	int arr2[] = {1,1,1,1,0,1,1,1,1};
	int arr3[] = {1};

	int min = Min(arr1, sizeof(arr1)/sizeof(arr1[0]));
	int min2 = Min(arr2, sizeof(arr2)/sizeof(arr2[0]));
	int min3 = Min(arr3, sizeof(arr3)/sizeof(arr3[0]));
}

int main()
{
	test();
	return 0;
}
