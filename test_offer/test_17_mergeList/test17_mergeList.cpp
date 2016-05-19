#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

/****
 * 面试题17： 合并两个排序的链表
 * 题目：输入两个递增排序的链表，合并这两个链表并使
 * 新链表中的结点仍然是递增排序的。
 **/

struct ListNode
{
    int value;
    ListNode* pNext;

    ListNode(int v = 0)
        :value(v)
        ,pNext(NULL)
    {}
};

// 1->3->5->7
// 1->4->6->8
// 1->2->3->4->5->6->7->8

ListNode* MergeList(ListNode* pHead1, ListNode* pHead2)
{
    if (NULL == pHead1)
    {
        return pHead2;
    }
    else if (NULL == pHead2)
    {
        return pHead1;
    }

    ListNode* pMergeHead = NULL;

    if (pHead1->value < pHead2->value)
    {
        pMergeHead = pHead1;
        pMergeHead->pNext = MergeList(pHead1->pNext, pHead2);
    }
    else
    {
        pMergeHead = pHead2;
        pMergeHead->pNext = MergeList(pHead1, pHead2->pNext);
    }

    return pMergeHead;
}

ListNode* findmin(ListNode* p1, ListNode* p2)
{
    if (p1->value < p2->value)
    {
        return p1;
    }
    else
    {
        return p2;
    }
}



// 非递归法
ListNode* MergeList_NO_recursion(ListNode* pHead1, ListNode* pHead2)
{
    ListNode* pMergeHead = NULL;
    ListNode* pMergeEnd = NULL;

    if (NULL == pHead1)
    {
        return pHead2;
    }
    else if (NULL == pHead2)
    {
        return pHead1;
    }

    ListNode* cur = NULL;
    ListNode* pOther = NULL; // 记录出cur的另一个链表头

    if (pHead1->value < pHead2->value)
    {
        pMergeHead = pHead1;
        pOther = pHead2;
    }
    else
    {
        pMergeHead = pHead2;
        pOther = pHead1;
    }

    pMergeEnd = pMergeHead;
    cur = pMergeHead->pNext;

    while (NULL != cur && NULL != pOther)
    {
        if (cur->value < pOther->value)
        {
            pMergeEnd->pNext = cur;
            cur = cur->pNext;
        }
        else
        {
            pMergeEnd->pNext = pOther;
            pOther = pOther->pNext;
        }
          pMergeEnd = pMergeEnd->pNext;
    }

    if (NULL == cur)
    {
        pMergeEnd->pNext = pOther; 
    }
    else 
    {
        pMergeEnd->pNext = cur;
    }

    return pMergeHead;
}



void test_MergeList()
{
    // 1 3 5
    // 2 4 6
    ListNode l1(1);
    ListNode l2(3);
    ListNode l3(5);
    ListNode r1(2);
    ListNode r2(4);
    ListNode r3(6);
    
    l1.pNext = &l2;
    l2.pNext = &l3;
    
    r1.pNext = &r2;
    r2.pNext = &r3;

    ListNode* mergeHead = NULL;

    //mergeHead = MergeList(NULL, NULL);
    //mergeHead = MergeList(&l1, &r1);
    //mergeHead = MergeList(&l1, NULL);
    mergeHead = MergeList(NULL, &r1);


}

void test_MergeList_NO_recursion()
{
    // 1 3 5
    // 2 4 6
    ListNode l1(1);
    ListNode l2(3);
    ListNode l3(5);
    ListNode r1(2);
    ListNode r2(4);
    ListNode r3(6);
    
    l1.pNext = &l2;
    l2.pNext = &l3;
    
    r1.pNext = &r2;
    r2.pNext = &r3;

    ListNode* mergeHead = NULL;

   // mergeHead = MergeList_NO_recursion(NULL, NULL);
   // mergeHead = MergeList_NO_recursion(&l1, &r1);
    // mergeHead = MergeList_NO_recursion(&l1, NULL);
    mergeHead = MergeList_NO_recursion(NULL, &r1);


}

int main()
{
    test_MergeList_NO_recursion();
    return 0;
}

