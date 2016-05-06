#define _CRT_SECURE_NO_WARNINGS 1
/*********
 *	������4���滻�ո�
 *	��Ŀ����ʵ��һ�����������ַ�����ÿ���ո��滻�ɡ�% 
 	20����
 *	�������롰We are happy���������Ϊ��We%20are%
	20happy��.
 *
 *
 *
 ********/

#include<iostream>
using namespace std;
// capacityΪstring������
void replace_blank(char string[], int capacity)
{
	if (string == NULL || capacity < 0)
	{
		return ;
	}

	int num_blank = 0;	//	�ո���
	int length = 0;	//	stringʵ�ʳ���
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
	//	new_length Ϊ �ո��滻�ɡ�%20��֮��ĳ���
	int new_length = length + num_blank * 2;

	if (new_length + 1 > capacity)
	{
		return;
	}

	int index_old = length;
	int index_new = new_length;

	while(index_old >= 0 && index_new > index_old)	
		// index_new > index_old	�Ż� ����ո��ֹͣ
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
