#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<string>
using namespace std;
// ������ 1 ����ֵ���������
// ��Ŀ������Ϊ����CMyString����������Ϊ��������Ӹ�ֵ�����������

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


//  һ�㷽��
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


//  �ִ�д��
CMyString& CMyString::operator=(const CMyString& str)
{
    if (this != &str)
    {
        CMyString strTemp(str);

        swap(m_pData, strTemp.m_pData);
    }

    return *this;
}

