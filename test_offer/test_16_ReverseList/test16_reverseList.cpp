#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
/*****
 * ������16 ��ת����
 * ��Ŀ�� ����һ������������һ�������ͷ��㣬��ת����
 * �������ת�������ͷ��㡣 ������Ķ�������
 *******/

struct ListNode
{
    int value;
    ListNode* pNext;
     ListNode(int v = 0)
        :value(v)
        ,pNext(NULL)
    {}
};

ListNode* ReverseList(ListNode* pHead)
{
    ListNode* pReversedHead = NULL;
    ListNode* pPrev = NULL;
    ListNode* pCur = pHead;

    while (NULL != pCur)
    {
        ListNode* pNext = pCur->pNext;
        
        // ԭβ������µ�ͷ���
        if (NULL == pNext)
        {
            pReversedHead = pCur;
        }

        pCur->pNext = pPrev;
        pPrev = pCur;
        pCur = pNext;

    }

    return pReversedHead;
}


void test()
{
    // ��ָ��
   ListNode* head =  ReverseList(NULL);
    // һ�����
   ListNode n1;
   head = ReverseList(&n1);

    // ������
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(3);
    ListNode l4(4);

    l1.pNext = &l2;
    l2.pNext = &l3;
    l3.pNext = &l4;

    head = ReverseList(&l1);
}

int main()
{
    test();
    return 0;
}