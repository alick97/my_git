#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
/******
 *  ������18�� �����ӽṹ
 *  ��Ŀ���������ö�����A��B���ж�B�ǲ���A���ӽṹ��
 *  ���������Ķ������£�
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

// ��proot1 �� proot2 ��ʼ������ ���Ƿ��proot1��ʼ�������proot2��
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

