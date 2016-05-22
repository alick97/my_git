#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
void PrintMatrixInCircle(int* numbers, int columns, int rows, int start);
void PrintMatrixClockWisely(int* numbers, int columns, int rows)
{
    if (NULL == numbers || columns <= 0 || rows <= 0)
    {
        return;
    }

    int start = 0;
    // start 记录每次开始的左上角的 下标

    // 结束条件 例如3列 5行 以小的3列为准 当start = 1时 1*2 < 3 但
    // 当start = 2 时 2*2 > 3 结束 偶数相同
    while (start * 2 < rows && start * 2 < columns)
    {
        PrintMatrixInCircle(numbers, columns, rows, start);
        start++;
    }

    cout<<endl;
}

void PrintMatrixInCircle(int* numbers, int columns, int rows, int start)
{
    int endX = columns - 1 -start; // 列结尾
    int endY = rows - 1 - start;   //  行结尾
    // 注意三种 特殊情况 
    // 只有一行  只打印行
    // 只有一列  只打印行和右边的列
    // 只有两行  只打印行、右边的列和下面的行

    // 其他 三行两列及以上 四条边都打印


    // 从左到右打印一行
    for (int i = start; i <= endX; ++i)
    {
        //cout<<numbers[start][i]<<"---";
        cout<<numbers[start * columns + i]<<"---";
    }

    // 从上到下打印一列
    if (start < endY) // 至少两行
    {
        for (int i = start + 1; i <= endY; ++i)
        {
           // cout<<numbers[i][endX]<<"---";
            cout<<numbers[i * columns + endX]<<"---";

        }
    }

    // 从右到左打印一行
    // 条件 至少两行 至少两列
    if (start < endY && start < endX)
    {
        for (int i = endX - 1; i >= start; --i)
        {
            //cout<<numbers[endY][i]<<"---";
            cout<<numbers[endY * columns + i]<<"---";
        }
    }

    // 从下向上打印一列
    // 条件： 三行两列 及以上
    if (start < endX && start + 1 < endY)
    {
        for (int i = endY - 1; i >= start + 1; --i)
        {
           // cout<<numbers[i][start]<<"---";
            cout<<numbers[i * columns + start]<<"---";

        }
    }
}

void test()
{
    int arr[4][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
   // int * p = (int *)arr;
    PrintMatrixClockWisely((int *)arr, 4, 4);
}


int main()
{
    test();
    return 0;
}
