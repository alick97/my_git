#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
/*****
 * 面试题29：数组中出现次数超过一半的数字
 * 题目： 数组中有一个数字出现的次数超过数组长度的一半，请找出这
 * 个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
 * 由于数字2在数组中出现5次，超过数组长度的一半，因此输出2.
 ***********/
bool g_bInputInvalid = false;

bool CheckInvalidArray(int* numbers, int length);
bool CheckMoreThanHalf(int* numbers, int length, int result);

int Partition(int* numbers, int length, int start, int end);
// method 1  排序后 中位数就是 这个数
// 利用快排思想 找中位数 递归问题 有二分的味道
int MoreThanHalfNum_way1(int* numbers, int length)
{
    if (CheckInvalidArray(numbers, length))
    {
        return 0;
    }

    int middle = length >> 1;

    int start = 0;
    int end = length - 1;

    int index = Partition(numbers, length, start, end);

    while (index != middle)
    {
        if (index > middle) // 中位数在左边
        {
            end = index - 1;
            index = Partition(numbers, length, start, end);
        }
        else // 中位数在右边
        {
            start = index + 1;
            index = Partition(numbers, length, start, end);
        }
    }

    int result = numbers[middle];

    if (!CheckMoreThanHalf(numbers, length, result))
    {
        return 0;
    }

    return result;

}

// 一次快排
//[start, end]
int Partition(int* numbers, int length, int start, int end)
{
    if (numbers == NULL || length <= 0 || start < 0 || end >= length)
    {
        throw exception("Invalid Partition");
    }

    int key = end;

    while (start < end)
    {
        while (start < end && numbers[start] <= numbers[key])
        {
            start++;
        }

        while (start < end && numbers[end] >= numbers[key])
        {
            end--;
        }
        swap(numbers[start], numbers[end]);
    }

    if (numbers[start] > numbers[key])
    {
        swap(numbers[start], numbers[key]);
         return start;
    }
    else // 1 2 3 4 99
    {
        return key;
    }
}



// method 2 相互抵消 最后剩下的一个就是


bool CheckInvalidArray(int* numbers, int length)
{
    g_bInputInvalid = false;

    if (NULL == numbers || length <= 0)
    {
        g_bInputInvalid = true;
    }

    return g_bInputInvalid;
}

bool CheckMoreThanHalf(int* numbers, int length, int result)
{
    int times = 0;

    for (int i = 0; i < length; i++)
    {
        if (numbers[i] == result)
        {
            times++;
        }
    }

    if (times > length / 2)
    {
        return true;
    }
    else
    {
        g_bInputInvalid = true;
        return false;
    }

}

int MoreThanHalfNum_way2(int* numbers, int length)
{
    if (CheckInvalidArray(numbers, length))
    {
        return 0;
    }

    int result = numbers[0];
    int times = 1;

    for (int i = 1; i < length; i++)
    {
        if (0 == times)
        {
            result = numbers[i];
            times++;
        }
        else if (result != numbers[i])
        {
            times--;
        }
        else
        {
            times++;
        }
    }

    if (!CheckMoreThanHalf(numbers, length, result))
        {
              result = 0;
        }

    return result;
}


void test()
{
    int arr[9] = {1,2,3,2,2,2,5,4,2};
   // int ret = MoreThanHalfNum_way2(arr, 9);
    int ret = MoreThanHalfNum_way1(arr,9);
}


int main()
{
    test();
    return 0;
}
