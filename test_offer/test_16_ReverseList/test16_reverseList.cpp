#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
/*****
 * 面试题16 反转链表
 * 题目： 定义一个函数，输入一个链表的头结点，反转该链
 * 表并输出翻转后链表的头结点。 链表结点的定义如下
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
        
        // 原尾结点是新的头结点
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
    // 空指针
   ListNode* head =  ReverseList(NULL);
    // 一个结点
   ListNode n1;
   head = ReverseList(&n1);

    // 多个结点
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