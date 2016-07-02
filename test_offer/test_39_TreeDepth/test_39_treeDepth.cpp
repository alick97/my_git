#include <iostream>
using namespace std;


/*******
	* ������39�������������
	* ��Ŀһ������һ�Ŷ������ĸ���㣬���������ȡ�
	* �Ӹ��ڵ㵽Ҷ������ξ����Ľ�㣨������Ҷ��㣩�γ�����һ��·����
	* �·��Ϊ������ȡ�
****************/

struct BinaryTreeNode
{
	int _nValue;
	BinaryTreeNode* _pLeft;
	BinaryTreeNode* _pRight;

	BinaryTreeNode(int nValue = 0)
		:_nValue(nValue)
		,_pLeft(NULL)
		,_pRight(NULL)
	{}
};


int TreeDepth(BinaryTreeNode* pRoot)
{
	if (NULL == pRoot)
	{
		return 0;
	}

	int nLeftDepth = TreeDepth(pRoot->_pLeft);
	int nRigtDepth = TreeDepth(pRoot->_pRight);

	return (nLeftDepth > nRigtDepth ? nLeftDepth : nRigtDepth) + 1;
}



void test()
{
	//            1
	//        2        3
	//     4     5          6
	//          7

	BinaryTreeNode* n1 = new BinaryTreeNode(1);
	BinaryTreeNode* n2 = new BinaryTreeNode(2);
	BinaryTreeNode* n3 = new BinaryTreeNode(3);
	BinaryTreeNode* n4 = new BinaryTreeNode(4);
	BinaryTreeNode* n5 = new BinaryTreeNode(5);
	BinaryTreeNode* n6 = new BinaryTreeNode(6);
	BinaryTreeNode* n7 = new BinaryTreeNode(7);

	n1->_pLeft = n2;
	n1->_pRight = n3;

	n2->_pLeft = n4;
	n2->_pRight = n5;

	n3->_pRight = n6;

	n5->_pLeft = n7;

	int depth = TreeDepth(n1);
}



/***************
 * ��Ŀ��������һ�Ŷ������ĸ���㣬�жϸ����ǲ���ƽ���������
 * ���ĳ����������������������������������1����ô������һ��ƽ���������
 * 
***************************/
bool IsBalanced(BinaryTreeNode* pRoot)
{
	if (pRoot == NULL)
	{
		return true;
	}

	bool bLeft = IsBalanced(pRoot->_pLeft);
	bool bRight = IsBalanced(pRoot->_pRight);

	if (abs(TreeDepth(pRoot->_pLeft) - TreeDepth(pRoot->_pRight)) > 1)
	{
		return false;
	}

	return bLeft && bRight;
}


void test_isBalanced()
{
		//            1
	//        2        3
	//     4     5          6
	//          7

	BinaryTreeNode* n1 = new BinaryTreeNode(1);
	BinaryTreeNode* n2 = new BinaryTreeNode(2);
	BinaryTreeNode* n3 = new BinaryTreeNode(3);
	BinaryTreeNode* n4 = new BinaryTreeNode(4);
	BinaryTreeNode* n5 = new BinaryTreeNode(5);
	BinaryTreeNode* n6 = new BinaryTreeNode(6);
	BinaryTreeNode* n7 = new BinaryTreeNode(7);

	n1->_pLeft = n2;
	n1->_pRight = n3;

	cout<<"balance:"<<IsBalanced(n1)<<endl;
	//n2->_pLeft = n4;
	n2->_pRight = n5;

	n3->_pRight = n6;

	n5->_pLeft = n7;
	cout<<"balance:"<<IsBalanced(n1)<<endl;
}


/******
 * ��ǿ�� bool IsBalanced(BinaryTreeNode* pRoot)
 * ȥ���ظ�����
***********/
bool IsBalancedAug(BinaryTreeNode* pRoot, int& qDepth)
{
	if (pRoot == NULL)
	{
		qDepth = 0;
		return true;
	}

	int left, right;
	if (IsBalancedAug(pRoot->_pLeft, left) && IsBalancedAug(pRoot->_pRight, right))
	{
		int diff = left - right;
		if (diff >= -1 && diff <= 1)
		{
			qDepth = 1 + (left > right ? left : right);
			return true;
		}
	}

	return false;
}

void testBalancedAug()
{
	int depth = 0;

			//            1
	//        2        3
	//     4     5          6
	//          7

	BinaryTreeNode* n1 = new BinaryTreeNode(1);
	BinaryTreeNode* n2 = new BinaryTreeNode(2);
	BinaryTreeNode* n3 = new BinaryTreeNode(3);
	BinaryTreeNode* n4 = new BinaryTreeNode(4);
	BinaryTreeNode* n5 = new BinaryTreeNode(5);
	BinaryTreeNode* n6 = new BinaryTreeNode(6);
	BinaryTreeNode* n7 = new BinaryTreeNode(7);

	n1->_pLeft = n2;
	n1->_pRight = n3;

	cout<<"balance:"<<IsBalancedAug(n1, depth)<<endl;
	//n2->_pLeft = n4;
	n2->_pRight = n5;

	n3->_pRight = n6;

	n5->_pLeft = n7;
	cout<<"balance:"<<IsBalancedAug(n1, depth)<<endl;
}

int main()
{
	//test_isBalanced();
	testBalancedAug();
	return 0;
}