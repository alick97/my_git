#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;
/*************
 *  ������21������min������ջ
 *  ��Ŀ�� ����ջ�����ݽṹ�����ڸ�������ʵ��һ���ȹ��õ�ջ����Сֵ��
 *  min�������ڸ�ջ�У�����min��push�Լ�pop��ʱ�临�Ӷ�ΪO��1����
 *
 ***********/

template<class T>
class StackWithMin
{
public:
    void push(const T& value)
    {
       _data.push(value);

       if (0 == _min.size() || value < _min.top())
       {
           _min.push(value);
       }
       else
       {
           _min.push(_min.top());
       }
    }

    void pop()
    {
        assert(_data.size() > 0 && _min.size() > 0);

        _data.pop();
        _min.pop();
    }

    T& min() 
    {
        assert(_data.size() > 0 && _min.size() > 0);

        return _min.top();
    }


private:
    stack<T> _data;
    stack<T> _min;
};


void test()
{
    StackWithMin<int> s;
    s.push(5);
    s.push(4);
    s.push(6);
    s.push(3);
    s.push(1);
    cout<<s.min()<<endl;

    s.pop();
    cout<<s.min()<<endl;
    s.pop();
    cout<<s.min()<<endl;  
    s.pop();
    cout<<s.min()<<endl;
}

int main()
{
    test();
    return 0;
}

