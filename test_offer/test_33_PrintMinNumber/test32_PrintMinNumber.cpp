#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<string>

using namespace std;
#define debug 0
/***********
 * ������ 33 �������ų���С����
 * ��Ŀ������һ�����������飬����������������ƴ�������ų�һ������
 * ��ӡ��ƴ�ӳɵ����������е���С��һ����
 * ���� ����{3, 32,321},���ӡ��������С����Ϊ 321323
 * 
****************/
const int g_MAxNumberLength = 10;

char* g_StrCombine1 = new char[g_MAxNumberLength*2 + 1];
char* g_StrCombine2 = new char[g_MAxNumberLength*2 + 1];

int compare(const void* strNumber1, const void* strNumber2)
{
    strcpy(g_StrCombine1, *(char**)strNumber1);
    strcat(g_StrCombine1, *(char**)strNumber2);
    strcpy(g_StrCombine2, *(char **)strNumber2);
    strcat(g_StrCombine2, *(char**)strNumber1);
#if debug  cout<<g_StrCombine1<<"------"<<g_StrCombine2<<endl;
#endif
    return strcmp(g_StrCombine1, g_StrCombine2);
}

void PrintMinNumber(int* numbers, int length)
{
    if (numbers == NULL || length <= 0)
    {
        return ;
    }

    char** strNumbers = (char**) new int[length];

    for (int i = 0; i < length; ++i)
    {
        strNumbers[i] = new char[g_MAxNumberLength + 1];
        sprintf(strNumbers[i], "%d", numbers[i]); // ����ת���ַ�
    }
    /////////////////////////////////////
        qsort(strNumbers, length, sizeof(char*), compare);

        for (int i = 0; i < length; ++i)
        {
           cout<<strNumbers[i];
        }

        cout<<endl;
    
        for (int i = 0; i < length; i++)
        {
            delete[] strNumbers[i];
        }
    delete[] strNumbers;
}

void test()
{
    int arr[] = {3,32,321};
    PrintMinNumber(arr, 3);
}


int main()
{
    test();
    return 0;
}
