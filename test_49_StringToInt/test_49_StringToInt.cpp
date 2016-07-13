#include <iostream>
using namespace std;

/*********************

 * 面试题49：把字符串转换为整数
*************************/
enum {kValid, kInvalid};

int g_nStatus = kInvalid; 

long  StrToIntCore(const char* str, bool minus);


int StrToInt(const char* str)
{
	g_nStatus = kInvalid;
	long num = 0;

	if (str != NULL && *str != '\0')
	{
		bool minus = false; // 负数符号
		if (*str == '+')
		{
			str++;
		}
		else if (*str == '-')
		{
			str++;
			minus = true;
		}

		if (*str != '\0') 
		{
			num = StrToIntCore(str, minus);
		}
	}

	return (int)num;
}

long StrToIntCore(const char* str, bool minus)
{
	long num = 0;

	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
		{
			int flag = minus ? -1 : 1;
			num = num * 10 + ( *str - '0') * flag;
			//	防止溢出
			if ((minus && num < (int)0x80000000) || (!minus && num > (int)0x7FFFFFFF))
			{
				num = 0;
				break;
			}
			str++;
		}
		else
		{
			num = 0;
			break;
		}
	}

	if (*str == '\0')
	{
		g_nStatus = kValid ;
	}

	return num;
}



void test()
{
	char* str1 = "+";
	char* str2 = "";
	char* str3 = "-12";
	char* str4 = "-1a2";
	
//	cout<<str1<<"       "<<StrToInt(str1)<<"            "<<g_nStatus<<endl;
//	cout<<str2<<"      "<<StrToInt(str2)<<"            "<<g_nStatus<<endl;
cout<<str3<<"      "<<StrToInt(str3)<<"            "<<g_nStatus<<endl;
//	cout<<str4<<"      "<<StrToInt(str4)<<"            "<<g_nStatus<<endl;
	
}

int main()
{
	test();
	return 0;
}
