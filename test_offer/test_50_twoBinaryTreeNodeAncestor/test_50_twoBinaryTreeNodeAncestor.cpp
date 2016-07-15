#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

/****************
 * 面试题50 树中两个结点的最低公共祖先结点

******************/

//         1
//     2           3
//   4   5      6      7
// 递归解法
struct BinaryTreeNode
{
    int _value;
    BinaryTreeNode* _left;
    BinaryTreeNode* _right;
    BinaryTreeNode(int value = 0)
        :_value(value)
        ,_left(NULL)
        ,_right(NULL)
    {}
};



bool find_ancestor(const BinaryTreeNode* pRoot, const BinaryTreeNode* p1, const BinaryTreeNode* p2, BinaryTreeNode*& pAncestor)
{
    if (pRoot == NULL)
    {
        return false;
    }

    bool bLeft = find_ancestor(pRoot->_left, p1, p2, pAncestor);
    bool bRight = find_ancestor(pRoot->_right, p1, p2, pAncestor);

    if (pRoot == p1 || pRoot == p2)
    {
        if (bLeft || bRight)
        {
            pAncestor = (BinaryTreeNode*)pRoot;
           
       }
         return true;
        
    }
    else
    {
        if (bLeft && bRight)
        {
            pAncestor = (BinaryTreeNode*)pRoot;
            return true;
        }
        else
        {
            return bLeft || bRight;
        }
    }
}

void test_find_ancestor()
{
    //         1
//     2           3
//   4   5      6      7

    // 构造树
    BinaryTreeNode* t1 = new BinaryTreeNode(1);
    BinaryTreeNode* t2 = new BinaryTreeNode(2);
    BinaryTreeNode* t3 = new BinaryTreeNode(3);
    BinaryTreeNode* t4 = new BinaryTreeNode(4);
    BinaryTreeNode* t5 = new BinaryTreeNode(5);
    BinaryTreeNode* t6 = new BinaryTreeNode(6);
    BinaryTreeNode* t7 = new BinaryTreeNode(7);


    t1->_left = t2;
    t1->_right = t3;

    t2->_left = t4;
    t2->_right = t5;

    t3->_left = t6;
    t3->_right = t7;

    BinaryTreeNode* pAncestor = NULL;
    // 4 5 ----------2
    find_ancestor(t1, t4, t5, pAncestor);
    cout<<pAncestor->_value<<endl;

        // 5 6 ----------1
    pAncestor = NULL;
    find_ancestor(t1, t5, t6, pAncestor);
    cout<<pAncestor->_value<<endl;


        // 3 6 ----------3
    pAncestor = NULL;
    find_ancestor(t1, t3, t6, pAncestor);
    cout<<pAncestor->_value<<endl;




}

int main()
{
    test_find_ancestor();
    return 0;
}