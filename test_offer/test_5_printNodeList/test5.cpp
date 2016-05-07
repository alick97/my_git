#define _CRT_SECURE_NO_WARNINGS 1
/****
 * ������5
 * ��Ŀ������һ�������ͷ�ڵ㣬��β��ͷ��������ӡÿ��
 * ����ֵ��
 *
 *********/

#include<iostream>
using namespace std;
#include<stack>

struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;

	ListNode(int v = 0)
		:m_nKey(v)
		,m_pNext(NULL)
	{
	}

};

// ͨ��ջ
void PrintListReverseByStack(ListNode* pHead)
{
	stack<ListNode *> nodes;
	ListNode* cur = pHead;
	while(cur != NULL)
	{
		nodes.push(cur);
		cur = cur->m_pNext;
	}

	while (!nodes.empty())
	{
		cur = nodes.top();
		cout<<cur->m_nKey<<"->";
		nodes.pop();
	}
	cout<<"over"<<endl;
}

// �ݹ�
void PrintListByRecursion(ListNode* pHead)
{
	if (pHead == NULL)
	{
		return;
	}
	PrintListByRecursion(pHead->m_pNext);
	cout<<pHead->m_nKey<<"->";
}


void test()
{
	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(3);
	ListNode n4(4);
	n1.m_pNext = &n2;
	n2.m_pNext = &n3;
	n3.m_pNext = &n4;
	n4.m_pNext = NULL;
	// �����
	PrintListReverseByStack(&n1);
	PrintListByRecursion(&n1);

	cout<<"--------------"<<endl;
	//	һ����
	ListNode n5(5);	
	PrintListReverseByStack(&n5);
		PrintListByRecursion(&n5);
}



int main()
{
	test();
	return 0;
}
