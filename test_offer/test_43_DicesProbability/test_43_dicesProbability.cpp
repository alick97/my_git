#include <iostream>
using namespace std;
#include <math.h>
/******************
 * ������43��n�����ӵĵ���
 * ��Ŀ�� ��n���������ڵ��ϣ��������ӳ���һ��ĵ���֮��Ϊs������n����ӡ��s��
 * ���п��ܵ�ֵ���ֵĸ��ʡ�
****************/

// ����1 �ݹ鷨
int g_maxValue = 6; //1-6
void Probability(int number, int* pProbabilities);
void ProbabilityCore(int original, int current, int sum, int* pProbabilities);


// number Ϊ���ӵĸ���
void PrintProbability(int number)
{
	if (number < 1)
	{
		return;
	}

	int maxSum = number * 6; // �������Ӻ�

	int* pProbabilities = new int[maxSum - number + 1];// ���Ӻ���СֵΪnumber ���ֵΪmaxSum
	// ��ʼ�����Ӻ͵ĳ�ʼֵ
	for (int i = number; i <= maxSum; i++)
	{
		pProbabilities[i - number] = 0;
	}

	// �ݹ麯��
	Probability(number, pProbabilities);
	int total = pow((double)g_maxValue, number);// ���ʵĵ�

	// ��ϣ����
	for (int j = number; j <= maxSum; j++)
	{
		double ratio = (double)pProbabilities[j - number] / total;
		cout<<j<<"   :"<<ratio<<endl;
	}

	delete[] pProbabilities;
}

void Probability(int number, int* pProbabilities)
{
	// ��һ�����ӵ����е�ȡֵ
	for (int i = 1; i <= g_maxValue; i++)
	{
		ProbabilityCore(number, number, i, pProbabilities);
	}
}

void ProbabilityCore(int original, int current, int sum, int* pProbabilities)
{
	// original �����Ӻ͵���ʼֵ ����Сֵ��
	// current ��¼����ʣ������ӵĸ���
	if (current == 1)
	{
		// ��ϣ
		pProbabilities[sum - original]++;
	}
	else
	{
		for (int i = 1; i <= g_maxValue; i++)
		{
			ProbabilityCore(original, current - 1, sum + i, pProbabilities);
		}
	}
}

void test_PrintProbability()
{
	PrintProbability(1);
	cout<<"-------------------"<<endl;
	PrintProbability(2);
}

// �ⷨ�� �� ����ѭ�������ӵ�����ʱ�����ܺ�
void PrintProbabilityNRe(int number) // number �� ���ӵĸ���
{
	if (number < 1)
	{
		return;
	}

	int* pProbabilities[2]; // ��ſ�����������׵�ַ
	pProbabilities[0] = new int[g_maxValue * number + 1];
	pProbabilities[1] = new int[g_maxValue * number + 1];
	// ��ʼ��
	for (int i = 0; i < g_maxValue * number + 1; i++)
	{
		pProbabilities[0][i] = 0;
		pProbabilities[1][i] = 0;
	}

	int flag = 0; // ���ڱ�ǵ�ǰ����
	for (int m = 1; m <= g_maxValue; m++)
	{
		pProbabilities[flag][m]++;
	}

	for (int k = 2; k <= number; k++)
	{
		// ��ʼ����һ��
		for (int i = 0; i < k; i++)
		{
			pProbabilities[1 - flag][i] = 0;
		}

		for (int s = k; s <= g_maxValue * k; s++)
		{
			pProbabilities[1 - flag][s] = 0;
			for (int j = 1; j <= s && j <= g_maxValue; j++)
			{
				pProbabilities[1 - flag][s] += pProbabilities[flag][s - j];
			}
		}
	
		flag = 1 - flag;
	}

	double total = pow((double)g_maxValue , number);

	for (int index = number; index <= g_maxValue * number; index++)
	{
		double ratio = (double)pProbabilities[flag][index] / total;
		cout<<index<<"   :"<<ratio<<endl;
	}

	delete[] pProbabilities[0];
	
	delete[] pProbabilities[1];
}

void test_PrintProbabilityNRe()
{
	PrintProbabilityNRe(1);
	cout<<"-------------------"<<endl;
	PrintProbabilityNRe(2);
}

int main()
{
	test_PrintProbabilityNRe();
	return 0;
}