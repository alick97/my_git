#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
/********
 * ������28 �ַ�������
 * ��Ŀ ����һ���ַ�������ӡ�����ַ������������С�����
 * �����ַ���abc�����ӡ�����ַ�a��b��c�����ų����������ַ���
 * abc��acb��bac��bca��cab��cba��
 *****************/


//   a    b     c
//        c     b

//   b    a     c
//        c      a

//   c    b      a
//        a      b

// ���õ�һ���ַ������ķֱ𽻻�
// ������һ���ַ�����һ�� �����ķֱ𽻻� �ݹ���ȥ
void Permutation_core(char* pStr, char* pBegin);

void Permutation(char* pStr)
{
    if (NULL == pStr)
    {
        return;
    }

    Permutation_core(pStr, pStr);
}

void Permutation_core(char* pStr, char* pBegin)
{
    if ('\0' == *pBegin)
    {
        cout<<pStr<<endl;
    }
    else
    {
        for (char* pCh = pBegin; *pCh != '\0'; pCh++)
        {
            swap(*pCh, *pBegin); // ��ǰλ �� �������λ���� 

            Permutation_core(pStr, pBegin + 1);

            swap(*pCh, *pBegin); // �ָ���ǰλ
        }
    }
}


void test_Permutation()
{
    char str[] = "abc";
    Permutation(str);
}


// [������ ������]
//  ��չ
//  ���ַ����������  
// a b c
// a,b,c,ab,ac,bc,abc



// a b c
//     d
//     e

// a c d
//     e

// a d e

// b c d
// b c e

//b d e

// c d e

// ���

void left_move(char* pStart, int count);
void right_move(char* pStart, int count);

void assable(char* pStr, char* pFirst, int count, const int length)
{
    if (1 >= count)
    {
        for (char* pCh = pFirst; pCh != '\0'; pCh++)
        {
            if (*pCh == '\0')
            {
                return;
            }

            swap(*pCh, *pFirst);

            char ch = '\0';
            
            swap(ch, *(pFirst+1));

            cout<<pStr<<endl;

             swap(ch, *(pFirst+1));
             swap(*pCh, *pFirst);
        }

        return ;
    }

    // һֱ�ߵ����һ���ַ�
    assable(pStr, pFirst + 1, count - 1, length); // ������˵�ǰ��count-1��������

    // �ӵ�ǰ pFirst����һλ   �ѵ�ǰ�ַ��ŵ�\0 ֮�� �ų���
    left_move(pFirst, length + 1 - count); // ����\0

    // ����pFirst+1
    assable(pStr, pFirst , count, length); // count ���ü�ȥ1 �������ڴ���������ǰ�ַ����Ѿ��ų�����count���ַ�

    //  ����һλ �ָ�
    right_move(pFirst, length - count + 1); // ����\0
}

void left_move(char* pStart, int count)
{
    char tmp = pStart[0];
    for (int i = 1; i < count; i++)
    {
        pStart[i - 1] = pStart[i];
    }
    pStart[count - 1] = tmp;
}

void right_move(char* pStart, int count)
{
    char tmp = pStart[count - 1];
    for (int i = 0; i < count - 1; i++)
    {
        pStart[i + 1] = pStart[i];
    }
    pStart[0] = tmp;
}

void test_assable()
{
    char arr[] = "abcde";
    assable(arr, arr ,3, 5);
}


int main()
{
    //test_Permutation();

     test_assable();
    return 0;
}
