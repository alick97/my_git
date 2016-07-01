#include <iostream>
using namespace std;


/**********
 * ������38 ���������������г��ֵĴ���
 * ��Ŀ��ͳ��һ�����������������г��ֵĴ���������������������{1,,23,3,4,4,4,5}��
 * ����3������3����������г�����4�Σ�������4��
 // {����˼��}
************************/
// [start , end]
int GetFirstKindex(int* data, int length, int k, int start, int end)
{
	if (start > end)
	{
		return -1;
	}

	int middleIndex = start + (end - start)/2;
	int middleData = data[middleIndex];

	if (middleData == k)
	{
		// �Ҽ���һ��k��index
		if ((middleIndex > 0 && data[middleIndex - 1] != k) || middleIndex == 0)
		{
			return middleIndex;
		}
		else
		{
			end = middleIndex - 1;
		}
	}
	else if (middleData < k)
	{
		start = middleIndex + 1;
	}
	else
	{
		end = middleIndex - 1;
	}

	return GetFirstKindex(data, length, k, start, end);
}

int GetLastKindex(int* data, int length, int k, int start, int end )
{
	if (start > end)
	{
		return -1;
	}

	int middleIndex = start + (end - start)/2;
	int middleData = data[middleIndex];

	if (middleData == k)
	{
		if ((middleIndex < length - 1 && data[middleIndex + 1] != k) || middleIndex == length - 1)
		{
			return middleIndex;
		}
		else
		{
			start = middleIndex + 1;
		}
	}
	else if (data[middleIndex] < k)
	{
		start = middleIndex + 1;
	}
	else
	{
		end = middleIndex - 1;
	}

	return GetLastKindex(data, length, k, start, end);
}

int GetCountOfK(int* data, int length, int k)
{
	int count = 0;

	if (data != NULL && length > 0)
	{
		int firstIndex = GetFirstKindex(data, length, k, 0, length - 1);
		int lastIndex = GetLastKindex(data, length, k, 0, length - 1);

		if (firstIndex > -1 && lastIndex > -1)
		{
			count = lastIndex - firstIndex + 1;
		}
	}

	return count;
}

int main()
{
	int data[] = {1,2,2,3,3,4,4,4,5,5};
	int count = GetCountOfK(data, 10, 4);
	cout<<count<<endl;
	return 0;
}