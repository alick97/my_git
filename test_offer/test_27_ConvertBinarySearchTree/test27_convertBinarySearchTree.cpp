#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

/*************
 * 面试题27 二叉搜索树与双向链表
 * 题目： 输入一颗二叉搜索树，将该二叉搜索树转换为一个排序的双向
 * 链表。要求不能创建任何新的结点，只能调整树中结点指针的知指向。
 *
 ***************/

struct BinaryTreeNode
{
    int _value;
    BinaryTreeNode* _pLeft;
    BinaryTreeNode* _pRight;

    BinaryTreeNode(int v = 0)
        :_value(v)
        ,_pLeft(NULL)
        ,_pRight(NULL)
    {}
};


void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode*& pLastNode)
{
    if (NULL == pNode)
    {
        return ;
    }

    if (NULL != pNode->_pLeft)
    {
        ConvertNode(pNode->_pLeft, pLastNode);
    }

    pNode->_pLeft = pLastNode;

    if (NULL != pLastNode)
    {
        pLastNode->_pRight = pNode;
    }

    pLastNode = pNode;

    if (NULL != pNode->_pRight)
    {
        ConvertNode(pNode->_pRight, pLastNode);
    }
}

BinaryTreeNode* GetHead(BinaryTreeNode* pNode)
{
    if (NULL == pNode)
    {
        return NULL;
    }

    BinaryTreeNode* pLast = NULL;

    ConvertNode(pNode, pLast);

    while (NULL != pNode->_pLeft)
    {
        pNode = pNode->_pLeft;
    }

    return pNode;

}

void test()
{
    BinaryTreeNode* b1 = new BinaryTreeNode(10);
    BinaryTreeNode* b2 = new BinaryTreeNode(6);
    BinaryTreeNode* b3 = new BinaryTreeNode(14);
    BinaryTreeNode* b4 = new BinaryTreeNode(4);
    BinaryTreeNode* b5 = new BinaryTreeNode(8);
    BinaryTreeNode* b6 = new BinaryTreeNode(12);
    BinaryTreeNode* b7 = new BinaryTreeNode(16);

    b1->_pLeft = b2;
    b1->_pRight = b3;

    b2->_pLeft = b4;
    b2->_pRight = b5;

    b3->_pLeft = b6;
    b3->_pRight = b7;

    //      10
    //   6     14
    // 4  8   12  16


    BinaryTreeNode* phead = GetHead(b1);
}


int main()
{
    test();
    return 0;
} 
