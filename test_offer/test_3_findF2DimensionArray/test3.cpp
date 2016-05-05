#define _CRT_SECURE_NO_WARNINGS 1
/*
 *  面试题3：二维数组中的查找
 *  《剑指offer》
    题目：在一个二维数组中，每一行按照从左到右的递增顺序    排序，每一列按照从上到下递增的顺序排序。请完成一个   函数，输入这样一个二维数组和一个整数，判断数组中是   否含有整数。



 ***************/
#include <iostream>
using namespace std;

bool Find(int* matrix, int rows, int columns, int number)
{
    bool found = false;

    if (matrix != NULL && rows > 0 && columns > 0)
    {
        int row = 0;
        int column = columns - 1;   //  右上角开始

        while (row < rows && column >= 0 )
        {
            if (matrix[row * columns + column] == number)
            {
                found = true;
                break;
            }
            else if (matrix[row * columns + column] > number)
            {
                column--;
            }
            else
            {
                row++;
            }
        }
    }

    return found;
}

void test_Find()
{
    int array[] = {1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15};
    bool ret1 = Find(array,4,4,6);
    bool ret2 = Find(NULL,4,4,6);
    bool ret3 = Find(array,4,4,22);
}


int main()
{
    test_Find();
    return 0;
}
