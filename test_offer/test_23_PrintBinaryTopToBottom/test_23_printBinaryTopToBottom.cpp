#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<queue>
using namespace std;
// ������23 �������´�ӡ������
// ��Ŀ���������´�ӡ����������ÿ����㣬ͬһ��Ľ��
// ���մ������ҵ�˳���ӡ��

struct BinaryTreeNode
{
    int Value;
    BinaryTreeNode* pLeft;
    BinaryTreeNode* pRight;
};

void PrintFromTopToBottom(BinaryTreeNode* pTreeRoot)
{
    if (NULL == pTreeRoot)
    {
        return;
    }
    std::queue<BinaryTreeNode*> queueTreeNode;
    queueTreeNode.push(pTreeRoot);

    while (!queueTreeNode.empty())
    {
        BinaryTreeNode* pNode = queueTreeNode.front();
        cout<<(pNode->Value)<<"--";
        queueTreeNode.pop();

        if (NULL != pNode->pLeft)
        {
            queueTreeNode.push(pNode->pLeft);
        }

        if (NULL != pNode->pRight)
        {
            queueTreeNode.push(pNode->pRight);
        }
    }
}


void test()
{
    BinaryTreeNode b1;
    BinaryTreeNode b2;
    BinaryTreeNode b3;

    b1.Value = 1;
    b2.Value = 2;
    b3.Value = 3;

    b1.pLeft = &b2;
    b1.pRight = &b3;

    b2.pLeft = NULL;
    b2.pRight = NULL;
  b3.pLeft = NULL;
    b3.pRight =NULL;

    PrintFromTopToBottom(&b1);
}


int main()
{
    test();
     return 0;   
}
