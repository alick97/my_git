#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

/************
 * 面试题36 数组中的逆序对
 * 题目：在数组中的两个数字如果前面的数字大于后面的数字，
 *  则这两个数字组成一个逆序对。输入一个数组，求出这个数组中
 * 逆序对的总数。
 * 例如：{7,5,6,4}中，一共5个逆序对 {7,6},{7,5},{7,4},{6,4},{5,4}
********
 * [归并排序的应用]
***************/

 int InversePairsCore(int* data,int* copy, int start, int end);


int InversePairs(int* data, int length)
{
    if (data == NULL || length < 0)
    {
        return 0;
    }

    int* copy = new int[length];

    for (int i = 0; i < length; i++)
    {
        copy[i] = data[i];
    }

    int count = InversePairsCore(data, copy, 0, length - 1);
    delete[] copy;

    return count;
}

 int InversePairsCore(int* data,int* copy, int start, int end)
 {
     if (start == end)
     {
         copy[start] = data[start];
         return 0;
     }

     int length = (end - start)/2;

     int leftCount = InversePairsCore(copy, data, start, start + length);
     int rightCount = InversePairsCore(copy, data, start + length + 1, end);

     // 假设前面已经排好
     // i 初始化为前半段最后一个数字的下标
     int i = start + length;
     // j 初始化为后半段最后一个数字的下标
     int j = end;

     int indexCopy = end;
     int count = 0;

     while (i >= start && j >= start + length + 1)
     {
         if (data[i] > data[j])
         {
             copy[indexCopy--] = data[i--];
             count += j - start - length; // 减少了比较次数
         }
         else
         {
             copy[indexCopy--] = data[j--];
         }
     }

     for (; i >= start; i--)
     {
         copy[indexCopy--] = data[i];
     }

     for (; j >= start + length + 1; j--)
     {
         copy[indexCopy--] = data[j];
     }

     return leftCount + rightCount + count;
 }


 void test()
 {
     int arr[] = {7,5,6,4};
     int count = InversePairs(arr, 4);
 }


int main()
{
    test();
    return 0;
}
