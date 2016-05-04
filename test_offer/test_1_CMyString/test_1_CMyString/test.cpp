#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<string>
using namespace std;
// 面试题 1 ：赋值运算符函数
// 题目：如下为类型CMyString的声明，请为该类型添加赋值运算符函数。

class CMyString
{
public:
    CMyString(char* pData = NULL);
    CMyString(const CMyString& str);
    ~CMyString();
    CMyString& operator=(const CMyString& str);
private:
    char* m_pData;
};


//  一般方法
/*
CMyString& CMyString::operator=(const CMyString& str)
{
    if (this == &str)
    {
        return *this;
    }
    char* p_tmp = new char[strlen(str.m_pData) + 1];
    delete[] m_pData;
    m_pData = p_tmp;
    strcpy(m_pData, str.m_pData);

    return *this;
}
*/


//  现代写法
CMyString& CMyString::operator=(const CMyString& str)
{
    if (this != &str)
    {
        CMyString strTemp(str);

        swap(m_pData, strTemp.m_pData);
    }

    return *this;
}

