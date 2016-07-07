#include <iostream>
using namespace std;

/**************
 * 面试题45： 圆圈中最后剩下的数字
 * 题目： 0,1，...，n - 1这n个数字排成一个圆圈，从数字0开始每次从这个圆圈中删除第m个
 * 数字。求出这个圆圈中剩下的最后一个数字。
 * 如 0,1,2,3,4 m=3  最后剩下的数字为3
***************/

// 约瑟夫环问题


// 方法一 环形链表模拟圆圈解法（这里用数组,自己的方法）
int LastRemain(unsigned int n, unsigned int m) // n个结点删除第m个
{
	if (n < 1 || m < 1)
	{
		return -1;
	}

	// 创建环形链表（数组）
	int* pArr = new int[n];
	bool* pSym = new bool[n];

	// 初始化
	for (int i = 0; i < n; i++)
	{
		pArr[i] = i;
		pSym[i] = true;
	}
	
	// 删除
	int count = n;
	int nIndex = 0;
	while (count > 1)
	{
		int mIndex = 1;

		while (mIndex < m)
		{
			if (pSym[nIndex])
			{
				mIndex++;
			}

			nIndex++;
			if (nIndex == n)
			{
				nIndex = 0;
			}
		}
		// 删除
		// 寻找删除点
		while (!pSym[nIndex])
		{
			nIndex++;
			if (nIndex == n)
			{
				nIndex = 0;
			}
		}
		pSym[nIndex] = false;
		// 下一次的起始
		nIndex++;
		if (nIndex == n)
		{
			nIndex = 0;
		}

		count--;
	}
	
	int ret = -1;
	for (int j = 0; j < n; j++)
	{
		if (pSym[j])
		{
			ret = pArr[j];
			break;
		}
	}

	delete[] pArr;
	delete[] pSym;

	return ret;
}



void test_LastRemain()
{
	// 2,0,4,1
	cout<<LastRemain(5, 3)<<endl;
}

// 方法二 环形链表模拟圆圈解法（用到List 迭代器 还不会）


// 方法三 数学公式（每次删除完重新把删除结点的后一个节点映射为0【起始结点】）
// k+1 -->  0   映射定义p(x) = (x -k -1)%n
// k+2 --> 1
// 递归公式
// f(n,m) = 0,                  n==1
// f(n,m) = [f(n-1,m) + m]%n    n>1
int LastRemainBymath(unsigned int n, unsigned int m)
{
	if (n < 1 || m < 1)
	{
		return -1;
	}

	int last = 0;
	for (int i = 2; i <= n; i++)
	{
		last = (last + m) % i;
	}
	return last;
}

void test_LastRemainBymath()
{
	// 2,0,4,1
	cout<<LastRemainBymath(5, 3)<<endl;
}

int main()
{
	test_LastRemainBymath();
	return 0;
}