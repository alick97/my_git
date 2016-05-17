#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

/******
 * ������15 �������е�����K�����
 * ��Ŀ������һ��������������е�����K����㡣Ϊ�˷��ϴ�����˵�ϰ
 * �ߣ� �����1��ʼ�������������β����ǵ�����1����㡣����һ������
 * ��6����㣬��ͷ��㿪ʼ���ǵ�ֵ������1,2,3,4,5,6,
 * �������ĵ�����3�������ֵΪ4�Ľ�㡣
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


