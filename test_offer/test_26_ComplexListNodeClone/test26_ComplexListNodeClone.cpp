#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <assert.h>
/************
 * 面试题26 复杂链表的复制
 * 题目： 请实现函数ComplexListNode* Clone（ComplexListNode* pHead），
 * 复制一个复杂链表。在复杂链表中，每个结点除了有一个pNext指针指向
 * 下一个结点外，还有一个pSibling指向链表中的任意结点或者NULL。
 * 结点的定义如下：

***************/

struct ComplexListNode
{
    int _value;
    ComplexListNode* pNext;
    ComplexListNode* pSibling;// 兄弟结点

    ComplexListNode(int v = 0)
        :_value(v)
        ,pNext(NULL)
        ,pSibling(NULL)
    {}
};

ComplexListNode* Clone(ComplexListNode* pHead)
{
    assert(NULL != pHead);
    // 现将复制的结点 链到对应结点的后面
    // 如 a-b-c-d
    //    a-a'-b-b'-c-c'-d-d'
    ComplexListNode* cur = pHead;

    while (NULL != cur)
    {
        ComplexListNode* newNode = new ComplexListNode(cur->_value);
        newNode->pNext = cur->pNext;
        cur->pNext = newNode;
        cur = newNode->pNext;
    }

    // 将新结点的pSibling赋值
    cur = pHead;

    while (NULL != cur)
    {
        ComplexListNode* pCloned = cur->pNext;

        if (NULL != cur->pSibling)
        {
            pCloned->pSibling = cur->pSibling->pNext;
        }
        cur = pCloned->pNext;
    }

    cur = pHead->pNext->pNext;
    // 拆分
    ComplexListNode* newHead = pHead->pNext;
    pHead->pNext = newHead->pNext;
    ComplexListNode* next = newHead;
    while (NULL != cur)
    {
        next->pNext = cur->pNext;
        next = next->pNext;
        cur->pNext = next->pNext;
        cur = cur->pNext;
    }

    return newHead;
}

void test()
{
    ComplexListNode* n1 = new ComplexListNode(1);
    ComplexListNode* n2 = new ComplexListNode(2);
    ComplexListNode* n3 = new ComplexListNode(3);
    n1->pNext = n2;
    n2->pNext = n3;

    n3->pSibling = n1;
    n2->pSibling = n2;

    ComplexListNode* newHead = Clone(n1);
}

int main()
{
    test();
    return 0;
}