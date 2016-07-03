#include <iostream>
using namespace std;


/*****************
 * ������41 ����Ϊs����������VS��Ϊs��������������
 * ��Ŀһ������һ�����������򡿵������һ������s���������в�����������
 * ʹ�����ǵĺ�������s������ж�����ֵĺ͵���s���������һ�Լ��ɡ�
 * ��������{1,2,4,7,11,15}������15,4+11=15��������4��11

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
 *  ��Ŀ��������һ������s����ӡ�����к�Ϊs�������������У����ٺ�����������
 * ��������15������1+2+3+4+5=4+5+6=7+8=15
 * ���Խ����ӡ����3������������1-5,4-6,��7-8.
**********************/

void PrintContinousSequence(int small, int big);

void FindContinousSequence(const int sum)
{
	//���ٺ���������
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