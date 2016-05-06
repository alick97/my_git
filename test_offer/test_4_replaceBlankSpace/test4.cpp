#define _CRT_SECURE_NO_WARNINGS 1
/*********
 *	面试题4：替换空格
 *	题目：请实现一个函数，把字符串的每个空格替换成“% 
 	20”。
 *	例如输入“We are happy”，则输出为“We%20are%
	20happy”.
 *
 *
 *
 ********/

#include<iostream>
using namespace std;
// capacity为string的容量
void replace_blank(char string[], int capacity)
{
	if (string == NULL || capacity < 0)
	{
		return ;
	}

	int num_blank = 0;	//	空格数
	int length = 0;	//	string实际长度
	int i = 0;

	while (string[i] != '\0')
	{
		++length;

		if (string[i] == ' ')
		{
			num_blank++;
		}

		++i;
	}
	//	new_length 为 空格替换成“%20”之后的长度
	int new_length = length + num_blank * 2;

	if (new_length + 1 > capacity)
	{
		return;
	}

	int index_old = length;
	int index_new = new_length;

	while(index_old >= 0 && index_new > index_old)	
		// index_new > index_old	优化 走完空格就停止
	{
		if (string[index_old] == ' ')
		{
			string[index_new--] = '0';
			string[index_new--] = '2';
			string[index_new--] = '%';
		}
		else
		{
			string[index_new--] = string[index_old];
		}

		--index_old;
	}
}


void test_replace_blank()
{
	char str1[50] = "We are   happy";
	char str2[50] = {};
	char str3[50] = "   ";

	replace_blank(NULL,50);
	replace_blank(str1,50);
	replace_blank(str2,50);
	replace_blank(str3,50);

	cout<<str1<<endl;
	cout<<str2<<endl;
	cout<<str3<<endl;
}




int main()
{
	test_replace_blank();
	return 0;
}
