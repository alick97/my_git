#include <iostream>
using namespace std;
#include <math.h>
/******************
 * 面试题43：n个骰子的点数
 * 题目： 把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的
 * 所有可能的值出现的概率。
****************/

// 方法1 递归法
int g_maxValue = 6; //1-6
void Probability(int number, int* pProbabilities);
void ProbabilityCore(int original, int current, int sum, int* pProbabilities);


// number 为骰子的个数
void PrintProbability(int number)
{
	if (number < 1)
	{
		return;
	}

	int maxSum = number * 6; // 最大的骰子和

	int* pProbabilities = new int[maxSum - number + 1];// 骰子和最小值为number 最大值为maxSum
	// 初始化骰子和的初始值
	for (int i = number; i <= maxSum; i++)
	{
		pProbabilities[i - number] = 0;
	}

	// 递归函数
	Probability(number, pProbabilities);
	int total = pow((double)g_maxValue, number);// 概率的底

	// 哈希方法
	for (int j = number; j <= maxSum; j++)
	{
		double ratio = (double)pProbabilities[j - number] / total;
		cout<<j<<"   :"<<ratio<<endl;
	}

	delete[] pProbabilities;
}

void Probability(int number, int* pProbabilities)
{
	// 第一颗骰子的所有的取值
	for (int i = 1; i <= g_maxValue; i++)
	{
		ProbabilityCore(number, number, i, pProbabilities);
	}
}

void ProbabilityCore(int original, int current, int sum, int* pProbabilities)
{
	// original 是骰子和的起始值 （最小值）
	// current 记录的是剩余的骰子的个数
	if (current == 1)
	{
		// 哈希
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

// 解法二 ： 基于循环求骰子点数，时间性能好
void PrintProbabilityNRe(int number) // number 是 骰子的个数
{
	if (number < 1)
	{
		return;
	}

	int* pProbabilities[2]; // 存放开两个数组的首地址
	pProbabilities[0] = new int[g_maxValue * number + 1];
	pProbabilities[1] = new int[g_maxValue * number + 1];
	// 初始化
	for (int i = 0; i < g_maxValue * number + 1; i++)
	{
		pProbabilities[0][i] = 0;
		pProbabilities[1][i] = 0;
	}

	int flag = 0; // 用于标记当前的行
	for (int m = 1; m <= g_maxValue; m++)
	{
		pProbabilities[flag][m]++;
	}

	for (int k = 2; k <= number; k++)
	{
		// 初始化另一行
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