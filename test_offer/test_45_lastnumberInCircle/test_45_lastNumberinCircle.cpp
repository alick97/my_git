#include <iostream>
using namespace std;

/**************
 * ������45�� ԲȦ�����ʣ�µ�����
 * ��Ŀ�� 0,1��...��n - 1��n�������ų�һ��ԲȦ��������0��ʼÿ�δ����ԲȦ��ɾ����m��
 * ���֡�������ԲȦ��ʣ�µ����һ�����֡�
 * �� 0,1,2,3,4 m=3  ���ʣ�µ�����Ϊ3
***************/

// Լɪ������


// ����һ ��������ģ��ԲȦ�ⷨ������������,�Լ��ķ�����
int LastRemain(unsigned int n, unsigned int m) // n�����ɾ����m��
{
	if (n < 1 || m < 1)
	{
		return -1;
	}

	// ���������������飩
	int* pArr = new int[n];
	bool* pSym = new bool[n];

	// ��ʼ��
	for (int i = 0; i < n; i++)
	{
		pArr[i] = i;
		pSym[i] = true;
	}
	
	// ɾ��
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
		// ɾ��
		// Ѱ��ɾ����
		while (!pSym[nIndex])
		{
			nIndex++;
			if (nIndex == n)
			{
				nIndex = 0;
			}
		}
		pSym[nIndex] = false;
		// ��һ�ε���ʼ
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

// ������ ��������ģ��ԲȦ�ⷨ���õ�List ������ �����ᣩ


// ������ ��ѧ��ʽ��ÿ��ɾ�������°�ɾ�����ĺ�һ���ڵ�ӳ��Ϊ0����ʼ��㡿��
// k+1 -->  0   ӳ�䶨��p(x) = (x -k -1)%n
// k+2 --> 1
// �ݹ鹫ʽ
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