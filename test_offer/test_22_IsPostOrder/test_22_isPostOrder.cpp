#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stack>
//using namespace std;

/******
 * 面试题22 栈的压入、弹出序列
 * 题目： 输入两个整数序列，第一个序列表示栈的压入顺序，请判断
 * 第二个是否为该栈的弹出顺序。【假设压入栈的所有数字均不相等】
 * 例如序列1,2,3,4,5是某栈的压栈序列，序列4,5,3,2,1是该压栈序列
 * 的对应的一个弹出序列，但4,3,5,1,2就不可能是该栈的弹出序列
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
                // 压完了 压栈序列
                if (pNextPush - pPush == length)
                {
                    break;
                }

                stackData.push(*pNextPush);
                pNextPush++;
            }

            // 压栈序列找不见弹出值 
            // 用stackData.top() 前提 stackData不为空 有
            // (pNextPop - pPop < length) 和 
            //  while (stackData.empty() || stackData.top() != *pNextPop)
            // 保障
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



