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
    // start ��¼ÿ�ο�ʼ�����Ͻǵ� �±�

    // �������� ����3�� 5�� ��С��3��Ϊ׼ ��start = 1ʱ 1*2 < 3 ��
    // ��start = 2 ʱ 2*2 > 3 ���� ż����ͬ
    while (start * 2 < rows && start * 2 < columns)
    {
        PrintMatrixInCircle(numbers, columns, rows, start);
        start++;
    }

    cout<<endl;
}

void PrintMatrixInCircle(int* numbers, int columns, int rows, int start)
{
    int endX = columns - 1 -start; // �н�β
    int endY = rows - 1 - start;   //  �н�β
    // ע������ ������� 
    // ֻ��һ��  ֻ��ӡ��
    // ֻ��һ��  ֻ��ӡ�к��ұߵ���
    // ֻ������  ֻ��ӡ�С��ұߵ��к��������

    // ���� �������м����� �����߶���ӡ


    // �����Ҵ�ӡһ��
    for (int i = start; i <= endX; ++i)
    {
        //cout<<numbers[start][i]<<"---";
        cout<<numbers[start * columns + i]<<"---";
    }

    // ���ϵ��´�ӡһ��
    if (start < endY) // ��������
    {
        for (int i = start + 1; i <= endY; ++i)
        {
           // cout<<numbers[i][endX]<<"---";
            cout<<numbers[i * columns + endX]<<"---";

        }
    }

    // ���ҵ����ӡһ��
    // ���� �������� ��������
    if (start < endY && start < endX)
    {
        for (int i = endX - 1; i >= start; --i)
        {
            //cout<<numbers[endY][i]<<"---";
            cout<<numbers[endY * columns + i]<<"---";
        }
    }

    // �������ϴ�ӡһ��
    // ������ �������� ������
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
