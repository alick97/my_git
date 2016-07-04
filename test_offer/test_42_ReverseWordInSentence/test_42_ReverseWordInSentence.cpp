#include <iostream>
using namespace std;
#include <string.h>
/*****************
 * ������42�� ��ת����˳�� VS ����ת�ַ���
 * ��Ŀһ������һ��Ӣ����ӣ���ת�����е��ʵ�˳�򣬵�������
 * �ַ���˳�򲻱䡣Ϊ������������ź���ͨ��ĸһ������
 * ���������ַ�"I am a student", �����Ϊ"student a am I".
***************************/

void Reverse(char* pBegin, char* pEnd)
{
	if (pBegin == NULL || pEnd == NULL)
	{
		return;
	}

	while (pBegin < pEnd)
	{
		swap(*pBegin, *pEnd);
		pBegin++;
		pEnd--;
	}
}

char* ReverseSentence(char* pData)
{
	if (pData == NULL)
	{
		return NULL;
	}

	char* pBegin = pData;
	char* pEnd = pData;

	while (*pEnd != '\0')
	{
		pEnd++;
	}

	pEnd--;
	// ��ת��������
	Reverse(pBegin, pEnd);

	// ��ת�����е�ÿ������
	pBegin = pEnd = pData;

	while (*pBegin != '\0')
	{
		if (*pBegin == ' ')
		{
			*pBegin++;
			*pEnd++;
		}
		else if (*pEnd == ' ' || *pEnd == '\0')
		{
			Reverse(pBegin, --pEnd);
			pBegin = ++pEnd;
		}
		else
		{
			pEnd++;
		}
	}

	return pData;
}

void test_ReverseSentence()
{
	char str[] = "I am a student";
	cout<<str<<endl;
	cout<<ReverseSentence(str)<<endl;
}



/*************
 * ��Ŀ�����ַ��������������ǰ��ַ���ǰ������ɸ��ַ�ת�Ƶ��ַ�����β����
 * �붨��һ������ʵ���ַ���������ת���ܡ�
 * ���������ַ���"abcdefg"������2���ú�����������ת2λ�õ��Ľ��"cdefgab".
******************/
char* LeftRotateString(char* pStr, int n)
{
	if (pStr != NULL)
	{
		int nLength = strlen(pStr);
		if (nLength > 0 && n > 0 && n < nLength)
		{
			char* pFirstStart = pStr;
			char* pFirstEnd = pStr + n - 1;
			char* pSecondStart = pFirstEnd + 1;
			char* pSecondEnd = pStr + nLength - 1;

			// ��ת�ַ���ǰn���ַ�
			Reverse(pFirstStart, pFirstEnd);

			// ��ת�ַ��������ַ�
			Reverse(pSecondStart, pSecondEnd);

				// ��ת�����ַ���
			Reverse(pFirstStart, pSecondEnd);
		}
	}

	return pStr;
}

void test_LeftRotateString()
{
	char str[] = "abcdefg";
	cout<<str<<endl;
	cout<<LeftRotateString(str, 2)<<endl;
}


int main()
{
	//test_ReverseSentence();
	
	test_LeftRotateString();
	return 0;
}