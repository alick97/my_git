#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stack>
//using namespace std;

/******
 * ������22 ջ��ѹ�롢��������
 * ��Ŀ�� ���������������У���һ�����б�ʾջ��ѹ��˳�����ж�
 * �ڶ����Ƿ�Ϊ��ջ�ĵ���˳�򡣡�����ѹ��ջ���������־�����ȡ�
 * ��������1,2,3,4,5��ĳջ��ѹջ���У�����4,5,3,2,1�Ǹ�ѹջ����
 * �Ķ�Ӧ��һ���������У���4,3,5,1,2�Ͳ������Ǹ�ջ�ĵ�������
 ********/

bool IsPopOrder(const int* pPush, const int* pPop, int length)
{
    bool bPossible = false;

    if (NULL != pPush && NULL != pPop && length > 0)
    {
        const int* pNextPush = pPush;
        const int* pNextPop = pPop;
        std::stack<int>stackData;

        while (pNextPop - pPop < length)
        {
            while (stackData.empty() || stackData.top() != *pNextPop)
            {
                // ѹ���� ѹջ����
                if (pNextPush - pPush == length)
                {
                    break;
                }

                stackData.push(*pNextPush);
                pNextPush++;
            }

            // ѹջ�����Ҳ�������ֵ 
            // ��stackData.top() ǰ�� stackData��Ϊ�� ��
            // (pNextPop - pPop < length) �� 
            //  while (stackData.empty() || stackData.top() != *pNextPop)
            // ����
            if (stackData.top() != *pNextPop)
            {
                break;
            }
            else
            {
                stackData.pop();
                pNextPop++;
            }
        }

        if (stackData.empty() && pNextPop - pPop == length)
        {
            bPossible = true;
        }
    }

    return bPossible;
}


void test()
{
    const int length = 5;
    int stack_push[length] = { 1,2,3,4,5};
    int stack_Pop1[length] = {5,4,3,2,1};
    int stack_Pop2[length] = { 3,1,2,4,5};
    bool possible = IsPopOrder(stack_push, stack_Pop1, length);
  possible = IsPopOrder(stack_push, stack_Pop2, length);

   int stack_push3[1] = { 1};
    int stack_Pop3[1] = {1};
    possible = IsPopOrder(stack_push3, stack_Pop3, 1);
        
}

int main()
{
    test();
    return 0;
}



