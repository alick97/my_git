#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

/********
 * 面试题24： 二搜索树的后续遍历
 * 题目： 输入一个整数数组，判断该数组是不是在某个二叉搜索树的后续
 * 遍历结果中。 如果是则返回true，否则返回false。假设数输入的【任意
 * 个数字都互不相同】。
 *
 *************/


// 二叉线索树特点 左子树 小于根节点 右子树大于根节点 根节点为数组
// 最后一个元素

bool VerifySequenceOfBST(int sequence[], int length)
{
    if (NULL == sequence || length < 0)
    {
        return false;
    }

    int root = sequence[length - 1];

    // 左子树结点 小于根节点
    int i = 0;
    for (; i < length - 1; i++)
    {
        if (sequence[i] > root)
        {
            break;
        }
    }

    // 右子树 结点大于根节点
    int j = i;
    for (; j < length - 1; ++j)
    {
        if (sequence[j] < root)
        {
            return false;
        }
    }

    // 判断左子树 只不是二叉线索树
    bool left = true; // 默认 无左子树时
    if (i > 0) // 存在左子树
    {
        left = VerifySequenceOfBST(sequence, i);
    }

    // 判断右子树是不是二叉线索树
    bool right = true;
    // i - 1 < length - 2
    if (i < length - 1) // 存在右子树 
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
// 相关题目：
// 输入一个整数数组，判断该数组是不是某二叉搜索树的
// 前序遍历结果。
// 前序特点， 根节点是第一个元素
bool VerifySequenceOfBPre(int sequence[], int length)
{
    if (NULL == sequence || length < 0)
    {
        return false;
    }

    int root = sequence[0];

    int i = 1;

    // 左子树
    for (; i < length; i++)
    {
        if (sequence[i] > root)
        {
            break;
        }

    }

    // 右子树
    int j = i;

    for (; j < length; j++)
    {
        if (sequence[j] < root)
        {
            return false;
        }
    }

    bool left = true;
    // 有左子树
    if (i > 1)
    {
        left = VerifySequenceOfBPre(sequence + 1, i - 1); 
    }

    bool right = true;
    // 有右子树
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
