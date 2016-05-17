#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

/******
 * 面试题15 ：链表中倒数第K个结点
 * 题目：输入一个链表，输出链表中倒数第K个结点。为了符合大多数人的习
 * 惯， 本题从1开始计数，即链表的尾结点是倒数第1个结点。例如一个链表
 * 有6个结点，从头结点开始它们的值依次是1,2,3,4,5,6,
 * 这个链表的倒数第3个结点是值为4的结点。
 *******/

struct ListNode
{
    int value;
    ListNode* pNext;
    ListNode(int v)
        :value(v)
        ,pNext(NULL)
    {}
};

ListNode* FindKthToTail(const ListNode* pListHead, unsigned int k)
{
    if (NULL == pListHead || 0 == k)
    {
        return NULL;
    }

    const ListNode* pFast = pListHead;
    const ListNode* pSlow = pListHead;

    for (unsigned int i = 0; i < k - 1; ++i)
    {
        if (NULL != pFast->pNext)
        {
            pFast = pFast->pNext;
        }
        else
        {
            return NULL;
        }
    }

    while (NULL != pFast->pNext)
    {
        pFast = pFast->pNext;
        pSlow = pSlow->pNext;
    }

    return (ListNode*)pSlow;
}

void test()
{
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(3);
    ListNode l4(4);

    l1.pNext = &l2;
    l2.pNext = &l3;
    l3.pNext = &l4;

    cout<<FindKthToTail(&l1, -1)<<endl;
    cout<<FindKthToTail(&l1, 1)->value<<endl;
    cout<<FindKthToTail(&l1, 0)<<endl;
    cout<<FindKthToTail(&l1, 4)->value<<endl;
    cout<<FindKthToTail(&l1, 5)<<endl;

}

int main()
{
    test();
    return 0;
}


