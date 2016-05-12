#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

/***
 * ������10�� ��������1�ĸ���
 * ��Ŀ�� ������һ������������һ����������������������Ʊ�ʾ��1�ĸ����������9��ʾ�ɶ�������1001����2λ��1.����������6���ú������2.
 ***/

// �ⷨһ
// ���ڸ���  ��ѭ��
int NumberOf1_way1(int n)
{
	int count = 0;
	while (n)
	{
		if (n & 1)
		{
			count++;
		}
		n >>= 1;
	}
	return count;
}


// �ⷨ2
int NumberOf1_way2(int n)
{
	int count = 0;
	unsigned int flag = 1;
	while (flag)
	{
		if (n & flag)
		{
			count++;
		}
		
		flag <<= 1;
	}
	return count;
}

// �ⷨ3   �����Ч��
int NumberOf1_way3(int n)
{
	int count = 0;
	while (n)
	{
		count++;
		n = (n - 1) & n; // ÿ��ȥ���ұߵ�һ�����ֵ�1
	}
	
	return count;
}


void test()
{
	int n = NumberOf1_way1(4);
	n = NumberOf1_way2(4);
	n = NumberOf1_way3(4);
	n = NumberOf1_way2(-1);
	n = NumberOf1_way3(-1);


	// ��ѭ��n = NumberOf1_way1(-2);
}


int main()
{
	test();	
	return 0;
}

