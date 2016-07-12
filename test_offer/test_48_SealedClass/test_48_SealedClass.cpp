#include <iostream>
using namespace std;

/***************
 * 面试题48 ： 不能被继承的类
 * 题目： 用C++设计一个不能被继承的类

*****************/
// 常规解法
// 把构造函数设为私有函数
class SealedClass1
{
public:
	static SealedClass1* GetInstance()
	{
		return new SealedClass1();
	}

	static void DeleteInstance(SealedClass1* pInstance)
	{
		delete pInstance;
	}
private:
	SealedClass1()
	{
		cout<<"base"<<endl;
	};
	~SealedClass1() 
	{
		cout<<"delete base"<<endl;
	};
};

void test_SealedClass1()
{
	/*
	// error 'B' : no appropriate default constructor available
	class B:public SealedClass1
	{};

	B b;
	*/

	// 利用静态函数 缺点 只能在堆上
    SealedClass1* p = SealedClass1::GetInstance();
	//p->DeleteInstance(p);
	SealedClass1::DeleteInstance(p);

}


// 新奇的解法 利用虚继承 (可以在栈上定义)
class SealedClass2;
class MakeSealed
{
	friend SealedClass2;
private:
	MakeSealed() { 	cout<<"base"<<endl; };
	~MakeSealed() { cout<<"delete base"<<endl;};

};

class SealedClass2 : virtual public MakeSealed
{
public:
	SealedClass2() {};
	~SealedClass2() {};
};
/*
//  error C2248: 'MakeSealed::MakeSealed' : cannot access private member declared in class 'MakeSealed'
class Try: public SealedClass2
{
public:
	Try() {};
	~Try() {};
};
*/

void test_SealedClass2()
{
	SealedClass2 b2;
//	Try t;
}

int main()
{
	//test_SealedClass1();
	test_SealedClass2();
	return 0;
}
