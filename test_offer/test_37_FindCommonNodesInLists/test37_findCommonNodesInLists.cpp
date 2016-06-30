#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

#include <assert.h>

/*************
 * 面试题37： 两个链表的第一个公共结点
 * 题目：输入两个链表，找出它们的第一个公共结点。连
*******************/
struct ListNode
{
	int _key;
	ListNode* _pNext;

	ListNode(int n = 0)
		:_key(n)
		,_pNext(NULL)
	{}
};

unsigned int GetListLength(ListNode* pHead);
// 1 2 3 4
// 5 2 3 4
// 快慢指针的应用
ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
{
/*	if (pHead1 == NULL || pHead2 == NULL)
	{
		return NULL;
	}
*/
	// 得到两个链表的长度
	unsigned int len1 = GetListLength(pHead1);
	unsigned int len2 = GetListLength(pHead2);
	int lenDif = len1 - len2; // 链表长度差
	ListNode* pListNodeLong = pHead1;
	ListNode* pListNodeShort = pHead2;
	if (len1 < len2)
	{
		swap(pListNodeLong, pListNodeShort);
		lenDif = 0 - lenDif;
	}

	// 快指针先走
	for (int i = 0; i < lenDif; i++)
	{
		pListNodeLong = pListNodeLong->_pNext;
	}

	while ((pListNodeLong != NULL) &&
		  (pListNodeShort != NULL) &&
		  (pListNodeLong != pListNodeShort))
	 {
		pListNodeLong = pListNodeLong->_pNext;
		pListNodeShort = pListNodeShort->_pNext;
	}

	return pListNodeLong;

}

unsigned int GetListLength(ListNode* pHead)
{
	unsigned int len = 0;
	ListNode* pNode = pHead;
	while (pNode != NULL)
	{
		len++;
		pNode = pNode->_pNext;
	}

	return len;
}


void test()
{
	ListNode* n11 = new ListNode(1);
	ListNode* n12 = new ListNode(2);

	ListNode* n13 = new ListNode(3);

	ListNode* n14 = new ListNode(4);

		ListNode* n21 = new ListNode(5);


	n11->_pNext = n12;
	n12->_pNext = n13;
	n13->_pNext = n14;

	n21->_pNext = n12;

	ListNode* ret = FindFirstCommonNode(n11, n21);
	cout<<ret->_key<<endl;
}

int main()
{
	test();
	return 0;
}