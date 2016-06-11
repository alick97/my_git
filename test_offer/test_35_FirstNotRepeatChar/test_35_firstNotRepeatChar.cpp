#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


/**********
 * ������35 ��һ��ֻ����һ�ε��ַ�
 * ��Ŀ�� ���ַ������ҵ���һ��ֻ����һ�ε��ַ�����
 * ����"abaccdeff",�����Ϊ'b'��
********************/

char firstNorRepeatChar(char* pString)
{
    if (pString == NULL)
    {
        return '\0';
    }

    const int tableSize = 256;
    unsigned int hashTable[tableSize];

    for (unsigned int i = 0; i < tableSize; i++)
    {
        hashTable[i] = 0;
    }

    char* pHashKey = pString;

    while(*(pHashKey) != '\0')
    {
        hashTable[*(pHashKey++)]++;
    }

    pHashKey = pString;

    while (*pHashKey != '\0')
    {
        if (hashTable[*pHashKey] == 1)
        {
            return *pHashKey;
        }

        pHashKey++;
    }

    return '\0';
}

void test()
{
    char arr[] = "abaccdeff";
    char c_first_one = firstNorRepeatChar(arr);
}


/********
 * ��չ ��
 * ����һ�����������������ַ������ӵ�һ���ַ�����ɾ���ڵڶ���
 * �ַ����г��ֹ����ַ��� �� "We are students." ��ɾ���ڶ����ַ���"aeiou" �� Ϊ "W r Stdnts."
 ************/

void remove_second_ch(char* pFirst, const char* pSecond)
{
    if (pFirst == NULL || pSecond == NULL)
    {
        return;
    }

    const int count = 256;
    int hashTable[count];

    for (int i = 0; i < count ; i++)
    {
        hashTable[i] = 0;
    }

    char* pHashKey = (char*)pSecond;
    // ͳ��
    while (*pHashKey != '\0')
    {
        hashTable[*pHashKey++]++;
    }

    // ȥ����һ���ַ��� �ڵڶ����ַ������ֵ��ַ�
    pHashKey = pFirst;
    int index = 0;
    while (*pHashKey != '\0')
    {
        if (hashTable[*pHashKey] == 0)
        {
            pFirst[index++] = *pHashKey;
        }

        pHashKey++;
    }
    pFirst[index] = '\0';
}

void test_remove_second_ch()
{
    char first[] = "We are students.";
    char second[] = "aeiou";
    remove_second_ch(first, second); //  "W r Stdnts."
}

//  ��չ2 ɾ���ַ������ظ����ַ�
//  ��չ3 �ж������ַ����ǲ���ͬλ�� ���������� ��ĸ��ͬ ��ĸ���ִ�����ͬ �� abc  cba��

int main()
{
  //  test();
    test_remove_second_ch();
    return 0;
}
