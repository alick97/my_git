#define _CRT_SECURE_NO_WARNINGS 1
/*
 *  ������3����ά�����еĲ���
 *  ����ָoffer��
    ��Ŀ����һ����ά�����У�ÿһ�а��մ����ҵĵ���˳��    ����ÿһ�а��մ��ϵ��µ�����˳�����������һ��   ��������������һ����ά�����һ���������ж���������   ����������



 ***************/
#include <iostream>
using namespace std;

bool Find(int* matrix, int rows, int columns, int number)
{
    bool found = false;

    if (matrix != NULL && rows > 0 && columns > 0)
    {
        int row = 0;
        int column = columns - 1;   //  ���Ͻǿ�ʼ

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
