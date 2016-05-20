#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
/******
 *  面试题18： 树的子结构
 *  题目：输入两棵二叉树A和B，判断B是不是A的子结构。
 *  二叉树结点的定义如下：
 *****/

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

// 从proot1 和 proot2 开始向下找 看是否从proot1开始下面包含proot2数
bool DoesTree1hasTree2(const BinaryTreeNode* pRoot1, const BinaryTreeNode* pRoot2)
{
    if (NULL == pRoot2)
    {
        return true;
    }

    if (NULL == pRoot1)
    {
        return false;
    }

    if (pRoot1->value != pRoot2->value)
    {
        return false;
    }

    return (DoesTree1hasTree2(pRoot1->pLeft, pRoot2->pLeft) && DoesTree1hasTree2(pRoot1->pRight, pRoot2->pRight));
}


bool HasSubTree(const BinaryTreeNode* pRoot1, const BinaryTreeNode* pRoot2)
{
    bool result = false;
    if (NULL != pRoot1 && NULL != pRoot2)
    {
        if (pRoot1->value == pRoot2->value)
        {
            result = DoesTree1hasTree2(pRoot1, pRoot2);
        }

        if (!result)
        {
            result = HasSubTree(pRoot1->pLeft, pRoot2);
        }

        if (!result)
        {
            result = HasSubTree(pRoot1->pRight, pRoot2);
        }
    }

    return result;
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

    //    2
    //   3  4
    BinaryTreeNode t2_1(2);
    BinaryTreeNode t2_2(3);
    BinaryTreeNode t2_3(4);
    t2_1.pLeft = &t2_2;
    t2_1.pRight = &t2_3;

    //    2
    //   3  5
    BinaryTreeNode t3_1(2);
    BinaryTreeNode t3_2(3);
    BinaryTreeNode t3_3(5);
    t3_1.pLeft = &t3_2;
    t3_1.pRight = &t3_3;

    bool ret = false;

    ret = HasSubTree(&t1_1, &t2_1);
    ret = HasSubTree(&t1_1, &t3_1);
    ret = HasSubTree(&t1_1, NULL);
    ret = HasSubTree( NULL,&t2_1);
    ret = HasSubTree( NULL,NULL);
}

int main()
{
    test();
    return 0;
}

