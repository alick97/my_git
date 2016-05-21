#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


/********
 * 面试题19 二叉树镜像
 * 题目：请完成一个函数，输入一个二叉树，该函数输出它的镜像
 * 
*********/


struct BinaryTreeNode
{
    int value;
    BinaryTreeNode* pLeft;
    BinaryTreeNode* pRight; 
    BinaryTreeNode(int v = 0)
        :value(v)
        ,pLeft(NULL)
        ,pRight(NULL)
    {}
};

void MirrorRecursively(BinaryTreeNode* pNode)
{
    if (NULL == pNode || (NULL == pNode->pLeft && NULL == pNode->pRight))
    {
        return;
    }

    swap(pNode->pLeft, pNode->pRight);

    if (NULL != pNode->pLeft)
    {
        MirrorRecursively(pNode->pLeft);
    }

    if (NULL != pNode->pRight)
    {
        MirrorRecursively(pNode->pRight);
    }
}

void test()
{
    //     1
    //   2  5 
    //  3 4
    BinaryTreeNode t1_1(1);
    BinaryTreeNode t1_2(2);
    BinaryTreeNode t1_3(3);
    BinaryTreeNode t1_4(4);
    BinaryTreeNode t1_5(5);

    t1_1.pLeft = &t1_2;
    t1_2.pLeft = & t1_3;
    t1_2.pRight = & t1_4;
    t1_1.pRight = & t1_5;

    MirrorRecursively(&t1_1);
}

int main()
{
    test();
    return 0;
}




