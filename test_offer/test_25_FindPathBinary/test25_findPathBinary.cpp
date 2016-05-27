#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

#include<vector>

/*********
 * 面试题25 二叉树中和为某一值得路径
 * 题目：输入一颗二叉树的一个整数，打印出二叉树中结点值
 * 的和为输入整数的所有路径。从树的跟结点开始往下一直到叶结点
 * 所经过的结点形成一条路径。二叉树结点的定义如下：
 ************************/

struct BinaryTreeNode
{
    int i_value;
    BinaryTreeNode* p_left;
    BinaryTreeNode* p_right;

    BinaryTreeNode(int v = 0)
        :i_value(v)
        ,p_left(NULL)
        ,p_right(NULL)
    {

    }

};

void FindPathCore(BinaryTreeNode* pRoot, int& sum, const int& getSum, vector<BinaryTreeNode*>& path);

void FindPath(BinaryTreeNode* pRoot, const int& getSum)
{
    if (NULL == pRoot)
    {
        return;
    }

    vector<BinaryTreeNode*> path;
    int sum = 0;
    FindPathCore(pRoot, sum, getSum, path);
}

void FindPathCore(BinaryTreeNode* pRoot, int& sum, const int& getSum, vector<BinaryTreeNode*>& path)
{
   /* if (NULL == pRoot)
    {
        return;
    }*/

    sum += pRoot->i_value;
    path.push_back(pRoot);
    // 叶子结点
    bool b_isLeafNode = (NULL == pRoot->p_left && NULL == pRoot->p_right);

    if (sum == getSum && b_isLeafNode)
    {
        for (int i = 0; i < path.size(); i++)
        {
            cout<<path[i]->i_value<<"--";
        }
        cout<<endl;
    }

    if (NULL != pRoot->p_left)
    {
        FindPathCore(pRoot->p_left, sum, getSum, path);
    }
    if (NULL != pRoot->p_right)
    {
        FindPathCore(pRoot->p_right, sum, getSum, path);
    }
    // 退出本层时  删除父节点
    sum -= pRoot->i_value;
    path.pop_back();
}


void test()
{
    //    10
    // 5    12
    //4  7                   
    BinaryTreeNode b1(10);
    BinaryTreeNode b2(5);
    BinaryTreeNode b3(12);
    BinaryTreeNode b4(4);
    BinaryTreeNode b5(7);

    b1.p_left = &b2;
    b1.p_right = &b3;

    b2.p_left = &b4;
    b2.p_right = &b5;

    FindPath(&b1, 22);
}



int main()
{
    test();
    return 0;
}
