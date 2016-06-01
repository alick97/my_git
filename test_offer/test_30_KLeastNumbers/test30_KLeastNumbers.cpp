#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<assert.h>
using namespace std;

/**********
 * ������30 ��С��k����
 * ��Ŀ ����n���������ҳ�������С��k����
 * ��������4��5��1��6��2��7��3��8��8�����֣�����С��4����Ϊ1��2��3��4
***************/


// ���ڿ���˼�� �����޸�ԭ������ O(N)
int Partition(int* input,int n, int start, int end);

void GetLeastNumbers(int* input, int n, int* output, int k)
{
    if (NULL == input || NULL == output || k > n || n <= 0 || k <= 0)
    {
        return;
    }

    int start = 0;
    int end = n - 1;
    int index = Partition(input, n, start, end);

    while (index != k - 1)
    {
        if (index > k - 1) // ����� 
        {
            end = index - 1;
            index =  Partition(input, n, start, end);
        }
        else // ���ұ�
        {
            start = index + 1;
            index = Partition(input, n, start, end);
        }
    }

    for (int i = 0; i < k; i++)
    {
        output[i] = input[i];
    }

}

// [start ,end]
int Partition(int* input,int n, int start, int end)
{
    assert(input && n > 0);

    int index = end;
    end = end - 1;

    while (start < end)
    {
        while (start < end && input[start] <= input[index])
        {
            start++;
        }

        while (start < end && input[end] >=  input[index])
        {
            end--;
        }
   

        swap(input[start], input[end]);
  }

    if (start == end)
    {
        if (input[start] > input[index])
        {
            swap(input[start], input[index]);
            return start;
        }
        else
        {
            return index;
        }
    }

}

void test()
{
    int arr[10] = {6,5,4,2,1,4,7,8,9,4};
    int arr2[10] = {10,9,8,7,6,5,4,3,2,1};
    int min[4];
    GetLeastNumbers(arr2, 10, min, 4);
}


// method 2
// ���ô��

void _AJustDown(int* output,int size, int parent);

void GetLeastNumbers_method2(int* input, int n, int* output, int k)
{
    assert(input != NULL && output != NULL && n > 0 && k > 0 && k <= n );
    //����k������
    int i = 0;
    for (; i < k; i++)
    {
        output[i] = input[i];
    }

    // ����k�Ĵ��
    int j = (k - 2) / 2;
    while (j >= 0)
    {
        _AJustDown(output, k, j--); // ���µ���
    }

    for(; i < n; i++)
    {
        if (input[i] < output[0])
        {
            output[0] = input[i];
            // ����
            _AJustDown(output, k, 0);
        }
    }
}

// ���µ���
void _AJustDown(int* output,int size, int parent)
{
    assert(output && size > 0 && parent >= 0);

    int child = parent * 2 +1;

    while (child < size)
    {
        if (child + 1 < size && output[child + 1] > output[child])
        {
            child += 1;
        }

        if (output[parent] < output[child])
        {
            swap(output[parent], output[child]);
            parent = child;
            child = parent * 2 + 1;
        }

        else
        {
            break;
        }
    }
}

void test_method2()
{
    int arr[10] = {6,5,4,2,1,4,7,8,9,4};
    int arr2[10] = {10,9,8,7,6,5,4,3,2,1};
    int min[4];
    GetLeastNumbers_method2(arr2, 10, min, 4);
}

int main()
{
    //test();
    test_method2();
    return 0;
}
