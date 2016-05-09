#define _CRT_SECURE_NO_WARNINGS 1

/**
 * 面试题7 用两个栈实现队列
 * 题目：用两个栈实现一个队列，队列的声明如下
 * 请实现它的两个函数appendTail 和 deleteHead，
 * 分别完成在队列尾部插入节点和在队列头部删除结点的功
 * 能。
 ******/
#include <stack>
#include <iostream>
using namespace std;

template<class T>
class CQueue
{
public:
	CQueue<T>(){};
	~CQueue<T>(){};

	void appendTail(const T& node);
	T deleteHead();

private:
	stack<T> stack1;
	stack<T> stack2;
};


template<class T>
void CQueue<T>::appendTail(const T& node)
{
	stack1.push(node);
}

template<class T>
T CQueue<T>::deleteHead()
{
	if (stack2.empty())
	{
		while(!stack1.empty())
		{
			T& data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}
	}

	if (stack2.empty())
	{
		throw exception("queue is empty");
	}

	T head = stack2.top();
	stack2.pop();

	return head;
}


void test()
{
	CQueue<int> q;
	q.appendTail(1);
	q.appendTail(2);
	q.appendTail(3);

	int tmp = q.deleteHead();
	tmp = q.deleteHead();
	tmp =q.deleteHead();
	try
	{
	tmp =q.deleteHead();
	}
	catch (const exception& e)
	{
		cout<<e.what()<<endl;
	}

}

int main()
{
	test();
	return 0;
}
