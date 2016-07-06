#include <iostream>
using namespace std;

/*************
 * ������44�� �˿��Ƶ�˳��
 * ��Ŀ�����˿����������5���ƣ��ж��ǲ���һ��˳�ӣ������������ǲ������������ġ�
 * 2-10Ϊ���ֱ���AΪ1�� JΪ11��QΪ12��KΪ13����������С�����Կ����������֡�
*****************/

int compare(const void* arg1, const void* arg2);

bool IsContinuous(int* numbers, int length)
{
	if (numbers == NULL || length < 1)
	{
		return false;
	}

	qsort(numbers, length, sizeof(int),  compare);

	int numberOfZero = 0; // ��С���ĸ���
	int numberOfGap = 0; // ������������ ֮��ļ��֮��

	// ͳ��������0�ĸ���
	for (int i = 0; i < length && numbers[i] == 0; i++)
	{
		++numberOfZero;
	}

	// ͳ�������еļ����Ŀ
	int small = numberOfZero;
	int big = small + 1;

	while (big < length)
	{
		// �ж��� һ������˳��
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