#pragma once
#include <iostream>
using namespace std;
/****
 * 面试题6 重建二叉树
 * 题目：输入某二叉树的前序遍历和中序遍历的结果，请重建
 * 出该二叉树。假设输入的前序遍历和中序遍历的结果中不含
 * 重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和  * 中序遍历序列{4,7,2,1,5,3,8,6}
 *************/

struct BinaryTreeNode
{
	int value;
	BinaryTreeNode* pLeft;
	BinaryTreeNode* pRight;

	BinaryTreeNode(int n = 0)
		:value(n)
		,pLeft(NULL)
		,pRight(NULL)
	{}
};

BinaryTreeNode* ConstructCore
(
	int* startPreOrder,int* endPreOrder,
	int* startInOrder, int* endInOrder
);

BinaryTreeNode* Construct(int* preOrder, int* inOrder, int length)
{
	if (preOrder == NULL || inOrder == NULL || length <=0)
	{
		return NULL;
	}

	return ConstructCore(preOrder,preOrder + length - 1, inOrder,inOrder + length - 1);
}


BinaryTreeNode* ConstructCore
(
	int* startPreOrder,int* endPreOrder,
	int* startInOrder, int* endInOrder
)
{
	// 前序遍历的第一个数字作为根节点的值
	int rootValue = startPreOrder[0];
	BinaryTreeNode* root = new BinaryTreeNode(rootValue);

	if (startPreOrder == endPreOrder)
	{
		if (startInOrder == endInOrder && *startPreOrder == *startInOrder)
		{
			return root;
		}
		else
		{
			throw exception("Invalid input");
		}
	}

	// 在中序遍历中找根结点的值
	int* rootInOrder = startInOrder;
	// 用< 不用<=
	while (rootInOrder < endInOrder && *rootInOrder != rootValue)
	{
		++rootInOrder;
	}

	if (rootInOrder == endInOrder && *rootInOrder != rootValue)
	{
		throw exception("Invalid input");
	}
	//	左子树长度 - 1
	int LeftLength = rootInOrder - startInOrder;

	int* LeftPreOrderEnd = startPreOrder + LeftLength;
	 if (LeftLength > 0)
	 {
		 //	构建左子树
		root->pLeft = ConstructCore(startPreOrder + 1, LeftPreOrderEnd, startInOrder, rootInOrder - 1);
	 }

	 if (LeftPreOrderEnd < endPreOrder)
	 {
		 //	构建右子树
		 root->pRight = ConstructCore(LeftPreOrderEnd + 1,endPreOrder, rootInOrder + 1, endInOrder);
	 }

	 return root;

}

