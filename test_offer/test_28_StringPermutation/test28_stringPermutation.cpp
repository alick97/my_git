#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
/********
 * 面试题28 字符串排列
 * 题目 输入一个字符串，打印出该字符串的所有排列。例如
 * 输入字符串abc，则打印出由字符a、b、c所能排出来的所有字符串
 * abc、acb、bac、bca、cab和cba。
 *****************/


//   a    b     c
//        c     b

//   b    a     c
//        c      a

//   c    b      a
//        a      b

// 先用第一个字符与后面的分别交换
// 再用下一个字符当第一个 与后面的分别交换 递归下去
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
            swap(*pCh, *pBegin); // 当前位 和 后面各个位交换 

            Permutation_core(pStr, pBegin + 1);

            swap(*pCh, *pBegin); // 恢复当前位
        }
    }
}


void test_Permutation()
{
    char str[] = "abc";
    Permutation(str);
}


// [有问题 待完善]
//  扩展
//  求字符的所有组合  
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

// 组合

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

    // 一直走到最后一个字符
    assable(pStr, pFirst + 1, count - 1, length); // 处理除了当前的count-1个子问题

    // 从当前 pFirst左旋一位   把当前字符放到\0 之后 排除它
    left_move(pFirst, length + 1 - count); // 包含\0

    // 不用pFirst+1
    assable(pStr, pFirst , count, length); // count 不用减去1 等于是在处理不包含当前字符（已经排除）的count个字符

    //  右旋一位 恢复
    right_move(pFirst, length - count + 1); // 包含\0
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
