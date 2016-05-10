#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
/******
 * ������8 ��ת�������С����
 * ��Ŀ����һ�������ʼ�����ɵ�Ԫ�ذᵽ�����ĩβ����
 * �ǳ�֮Ϊ�������ת�� ����һ���ݹ�������������ת��
 * �����ת�������СԪ�ء���������{3,4,5,1,2}Ϊ����
 * {1,,2��3,4,5��}��һ����ת����������СֵΪ1.
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

	int mid_index = left_index;	//	��ֹ���С���ұ� ��������������

	while (numbers[left_index] >= numbers[right_index])
	{
		// ֹͣ���� ��Χ������С �ұ߾�����С��
		if (right_index - left_index == 1)
		{
			mid_index = right_index;
			break;
		}

		mid_index = left_index / 2 + right_index / 2;
		
		// ������� ��ߡ��ұߡ��м���� ����Խ����Сֵ
		// �� 101111
		// ֻ����˳�����
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
