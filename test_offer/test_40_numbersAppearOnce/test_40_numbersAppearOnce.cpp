#include <iostream>
using namespace std;

/*************
 * ������40�� ������ֻ����һ�ε�����
 * ��Ŀ��һ�����������������������֮�⣬���������ֶ����������Ρ�
 * ��д�����ҳ�������ֻ����һ�ε����֡�
 * Ҫ��ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)
**********************/


// {2,4,3,6,3,2,5,5}
// 4 6
// �������дӵ�λ���λ�ҵ�һ��1 ��λ��
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

	// ������� �е�һλ1 �������鴦��
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