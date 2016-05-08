#pragma once
#include <iostream>
using namespace std;
/****
 * ������6 �ؽ�������
 * ��Ŀ������ĳ��������ǰ���������������Ľ�������ؽ�
 * ���ö����������������ǰ���������������Ľ���в���
 * �ظ������֡���������ǰ���������{1,2,4,7,3,5,6,8}��  * �����������{4,7,2,1,5,3,8,6}
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
	// ǰ������ĵ�һ��������Ϊ���ڵ��ֵ
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

	// ������������Ҹ�����ֵ
	int* rootInOrder = startInOrder;
	// ��< ����<=
	while (rootInOrder < endInOrder && *rootInOrder != rootValue)
	{
		++rootInOrder;
	}

	if (rootInOrder == endInOrder && *rootInOrder != rootValue)
	{
		throw exception("Invalid input");
	}
	//	���������� - 1
	int LeftLength = rootInOrder - startInOrder;

	int* LeftPreOrderEnd = startPreOrder + LeftLength;
	 if (LeftLength > 0)
	 {
		 //	����������
		root->pLeft = ConstructCore(startPreOrder + 1, LeftPreOrderEnd, startInOrder, rootInOrder - 1);
	 }

	 if (LeftPreOrderEnd < endPreOrder)
	 {
		 //	����������
		 root->pRight = ConstructCore(LeftPreOrderEnd + 1,endPreOrder, rootInOrder + 1, endInOrder);
	 }

	 return root;

}

