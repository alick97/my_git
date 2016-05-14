#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;

// 打印从1到n位数
bool add_snumber_by1(char* s_number, int length);
void print_num(const char* s_num);

void printToN(int n)
{
    if (n <= 0)
    {
        return;
    }

    char* s_number = new char[n + 1];
    memset(s_number, '0', n);
    s_number[n] = '\0';

    while (!add_snumber_by1(s_number, n))
    {
        print_num(s_number); // 去除前面多余0 的打印 如 001   打印为1
    }
    delete[] s_number;
}

bool add_snumber_by1(char* s_number, int length) // 每次加一 超过字符串位数 返回true 
{
    assert(s_number != NULL && length >= 0);
    int high_pos_add1 = 0; // 进位
    bool s_over = false;
    for (int i = length - 1; i >= 0; i--)
    {
        int num_pos = s_number[i] - '0' + high_pos_add1;

        if (length - 1 == i) // 最低位
        {
            num_pos += 1;
        }

        if (num_pos >= 10)
        {
            if (0 == i) // 做高位有进位 说明到n位数最大值了
            {
                s_over = true;
                break;
            }
            else
            {
                high_pos_add1 = 1;
                num_pos -= 10;
                s_number[i] = num_pos + '0';
            }
        }
        else
        {
            s_number[i] = num_pos + '0';
            break;
        }
    }

    return s_over;
}


void print_num(const char* s_num)
{
    assert(s_num);
    while('0' == *s_num)
    {
        ++s_num;
    }

    cout<<s_num<<endl;
}

//------------方法2
// 递归法
void print_n_recursive(char* s_num, int length, int index)
{
    if (length - 1 == index)
    {
        print_num(s_num);
        return ;
    }

    for (int i = 0; i < 10; i++)
    {
        s_num[index + 1] = i + '0';
        print_n_recursive(s_num, length, index + 1);
    }
}






void printToN_way2(int n)
{
    if (n <= 0)
    {
        return;
    }

    char* s_num = new char[n + 1];
    s_num[n] = '\0';

    for (int i = 0; i < 10; i++)
    {
        s_num[0] = i + '0';
        print_n_recursive(s_num, n, 0);
    }

    delete[] s_num;
}


int main()
{
    //printToN(4);

    printToN_way2(2);
    return 0;
}


