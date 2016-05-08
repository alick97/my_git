#define _CRT_SECURE_NO_WARNINGS 1
#include "recoverBinaryTree.h"

int main()
{
	int PreOrder[] = {1,2,4,7,3,5,6,8};
	int InOrder[] = {4,7,2,1,5,3,8,6};
	BinaryTreeNode* root = Construct(PreOrder,InOrder,8);
	return 0;
}
