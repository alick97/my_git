#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

/****
 * 面试题13 在O（1） 时间删除链表的结点
 * 题目： 给定单向链表的头指针和一个结点指针，定义一个函  * 数，在O(1)时间删除该结点。链表结点与函数定义如下：
 **/

struct ListNode
{
    int value;
    ListNode* pNext;
};

void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
{
    if (NULL == pListHead || NULL == pToBeDeleted)
    {
        return;
    }

    // 非尾结点
    if (NULL != pToBeDeleted->pNext)
    {
        ListNode* pNext = pToBeDeleted->pNext;
        pToBeDeleted->value = pNext->value;
        pToBeDeleted->pNext = pNext->pNext;

        delete pNext;
    }
    // 链表只有一个结点 删除头结点
    else if (*pListHead == pToBeDeleted)
    {
        delete pToBeDeleted;
        pToBeDeleted = NULL;
        *pListHead = NULL;
    }
    // 链表有多个结点 删除尾结点
    else
    {
        ListNode* pNode = *pListHead;

        while (pNode->pNext != pToBeDeleted)
        {
            pNode = pNode->pNext;
        }

        pNode->pNext = NULL;
        delete pToBeDeleted;
        pToBeDeleted = NULL;
    }
}

void test()
{
    ListNode* n1 = new ListNode;
    ListNode* n2 = new ListNode;
    ListNode* n3 = new ListNode;
    ListNode* n4 = new ListNode;

    n1->value = 1; 
    n2->value = 2;
    n3->value = 3;
    n4->value = 4;

    n1->pNext = n2;
    n2->pNext = n3;
    n3->pNext = n4;
    n4->pNext = NULL;

    DeleteNode(&n1, n2);
    DeleteNode(&n1, n4);


    ListNode* l1 = new ListNode;
    l1->value = 1;
    l1->pNext = NULL;
    DeleteNode(&l1, l1);
}

int main()
{
    test();
    return 0;
}



