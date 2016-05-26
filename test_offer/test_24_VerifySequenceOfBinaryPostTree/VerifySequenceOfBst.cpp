#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

/********
 * ������24�� ���������ĺ�������
 * ��Ŀ�� ����һ���������飬�жϸ������ǲ�����ĳ�������������ĺ���
 * ��������С� ������򷵻�true�����򷵻�false������������ġ�����
 * �����ֶ�������ͬ����
 *
 *************/


// �����������ص� ������ С�ڸ��ڵ� ���������ڸ��ڵ� ���ڵ�Ϊ����
// ���һ��Ԫ��

bool VerifySequenceOfBST(int sequence[], int length)
{
    if (NULL == sequence || length < 0)
    {
        return false;
    }

    int root = sequence[length - 1];

    // ��������� С�ڸ��ڵ�
    int i = 0;
    for (; i < length - 1; i++)
    {
        if (sequence[i] > root)
        {
            break;
        }
    }

    // ������ �����ڸ��ڵ�
    int j = i;
    for (; j < length - 1; ++j)
    {
        if (sequence[j] < root)
        {
            return false;
        }
    }

    // �ж������� ֻ���Ƕ���������
    bool left = true; // Ĭ�� ��������ʱ
    if (i > 0) // ����������
    {
        left = VerifySequenceOfBST(sequence, i);
    }

    // �ж��������ǲ��Ƕ���������
    bool right = true;
    // i - 1 < length - 2
    if (i < length - 1) // ���������� 
    {
        right = VerifySequenceOfBST(sequence + i, length - 1 - i);
    }

    return (left && right);
}


void test_VerifySequenceOfBST()
{
    int arr1[] = {5,7,6,9,11,10,8};
    int arr2[] = {7,4,6,5};
    bool isSeqOfBst = VerifySequenceOfBST(arr1,7);
     isSeqOfBst = VerifySequenceOfBST(arr2,4);
}


//-----------------------------------
// �����Ŀ��
// ����һ���������飬�жϸ������ǲ���ĳ������������
// ǰ����������
// ǰ���ص㣬 ���ڵ��ǵ�һ��Ԫ��
bool VerifySequenceOfBPre(int sequence[], int length)
{
    if (NULL == sequence || length < 0)
    {
        return false;
    }

    int root = sequence[0];

    int i = 1;

    // ������
    for (; i < length; i++)
    {
        if (sequence[i] > root)
        {
            break;
        }

    }

    // ������
    int j = i;

    for (; j < length; j++)
    {
        if (sequence[j] < root)
        {
            return false;
        }
    }

    bool left = true;
    // ��������
    if (i > 1)
    {
        left = VerifySequenceOfBPre(sequence + 1, i - 1); 
    }

    bool right = true;
    // ��������
    if (i < length)
    {
        right = VerifySequenceOfBPre(sequence + i - 1, length -  i);
    }


    return left && right;
    
}

void test_VerifySequenceOfBPre()
{
    int arr1[] = {8,6,5,7,10,9,11};
    int arr2[] = {4,5,3,9};
    bool isSeqOfBst = VerifySequenceOfBPre(arr1,7);
     isSeqOfBst = VerifySequenceOfBPre(arr2,4);
}


int main()
{
   // test_VerifySequenceOfBST();
    test_VerifySequenceOfBPre();
    return 0;
}
