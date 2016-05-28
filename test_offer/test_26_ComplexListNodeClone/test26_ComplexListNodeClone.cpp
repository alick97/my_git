#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <assert.h>
/************
 * ������26 ��������ĸ���
 * ��Ŀ�� ��ʵ�ֺ���ComplexListNode* Clone��ComplexListNode* pHead����
 * ����һ�����������ڸ��������У�ÿ����������һ��pNextָ��ָ��
 * ��һ������⣬����һ��pSiblingָ�������е����������NULL��
 * ���Ķ������£�

***************/

struct ComplexListNode
{
    int _value;
    ComplexListNode* pNext;
    ComplexListNode* pSibling;// �ֵܽ��

    ComplexListNode(int v = 0)
        :_value(v)
        ,pNext(NULL)
        ,pSibling(NULL)
    {}
};

ComplexListNode* Clone(ComplexListNode* pHead)
{
    assert(NULL != pHead);
    // �ֽ����ƵĽ�� ������Ӧ���ĺ���
    // �� a-b-c-d
    //    a-a'-b-b'-c-c'-d-d'
    ComplexListNode* cur = pHead;

    while (NULL != cur)
    {
        ComplexListNode* newNode = new ComplexListNode(cur->_value);
        newNode->pNext = cur->pNext;
        cur->pNext = newNode;
        cur = newNode->pNext;
    }

    // ���½���pSibling��ֵ
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
    // ���
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