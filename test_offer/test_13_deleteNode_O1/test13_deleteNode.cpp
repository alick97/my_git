#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

/****
 * ������13 ��O��1�� ʱ��ɾ������Ľ��
 * ��Ŀ�� �������������ͷָ���һ�����ָ�룬����һ����  * ������O(1)ʱ��ɾ���ý�㡣�������뺯���������£�
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

    // ��β���
    if (NULL != pToBeDeleted->pNext)
    {
        ListNode* pNext = pToBeDeleted->pNext;
        pToBeDeleted->value = pNext->value;
        pToBeDeleted->pNext = pNext->pNext;

        delete pNext;
    }
    // ����ֻ��һ����� ɾ��ͷ���
    else if (*pListHead == pToBeDeleted)
    {
        delete pToBeDeleted;
        pToBeDeleted = NULL;
        *pListHead = NULL;
    }
    // �����ж����� ɾ��β���
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



