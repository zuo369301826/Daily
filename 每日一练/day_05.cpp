#include <iostream>
#include <vector>
using namespace std;
#pragma warning (disable:4996)


 /* 字符串和模式匹配*/

//bool match(char* str, char* pattern)
//{
//	int i = 0;
//	int j = 0;
//	while(str[i] != '\0' &&  pattern[j] != '\0' )
//	{
//		//1
//		if (str[i] == pattern[j] || str[i] == '.' || pattern[j] == '.') // 相同匹配
//		{
//			i++;
//			j++;
//		}
//
//		//2
//		else if(str[i] == '*' || pattern[j] == '*')// aaab  和 a*b  匹配    
//		{
//			if (str[i] == '*') 
//			{
//				char flag = str[i - 1];
//				while (pattern[j] == flag)
//					j++;
//				i++;
//			}
//			else
//			{
//				char flag = pattern[j - 1];
//				while (str[i] == flag)
//					i++;
//				j++;
//			}
//		}
//	
//		//3
//		else if (str[i + 1] == '*' || pattern[j + 1] == '*') //ab*a   和  aa
//		{
//			if (str[i + 1] == '*')
//				i += 2;
//			else j += 2;
//		}
//
//	}
//
//	if (str[i] == '\0' && pattern[j] == '\0')
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}

//bool match(char* str, char* pattern)
//{
//	if (str == NULL || pattern == NULL)
//		return false;
//	int i = 0;
//	int j = 0;
//	while (str[i] != '\0' &&  pattern[j] != '\0')
//	{
//		if (str[i] == pattern[j] || pattern[j] == '.')
//		{
//			i++;
//			j++;
//		}
//		else break;
//	}
//	if (str[i] == '\0' && pattern[j] == '\0')
//		return true;
//	else return false;
//}

bool match(char* str, char* pattern)
{
	if (str == NULL || pattern == NULL)
		return false;

	string s(str);
	string s2(pattern);
	int L1 = s.size();
	int L2 = s2.size();
	int i = 0;
	int j = 0;
	while (i < L1 && j  < L2)
	{
		if (s[i] == s2[j] ||s2[j] == '.')
		{
			i++;
			j++;
		}
		else if (s2[j] == '*')
		{
			char flag = s2[j - 1];
			int d = 50;
			while (s[i+d] == flag)
				i+=d;
			while (s[i] == flag)
				i++;
			j++;
		}
		else if (s2[j + 1] == '*')
			j += 2;
	}

	if (i == L1 && j  == L2)
		return true;
	else return false;
}




//int main()
//{
//	char a[] ="aaa";
//	char b[] ="aaa";
//	bool ret = match(a,b);
//	cout << a << " " << b << " " << ret << endl;
//
//	char c[] = "a.a";
//	ret = match(a,c);
//	cout << a << " " << c << " " << ret << endl;
//
//	char d[] = "ab*ac*a";
//	ret = match(a,d);
//	cout << a << " " << d << " " << ret << endl;
//
//	char e[] = "aa.a";
//	ret = match(a, e);
//	cout << a << " " << e << " " << ret << endl;
//
//	char f[] = "ab*a";
//	ret = match(a,f);
//	cout << a << " " << f << " " << ret << endl;
//
//
//	char eq[] = "aaaaaaaaaaaaa";
//	char fq[] = "a.a.aa.aaaa.a";
//	ret = match(eq, fq);
//	cout << eq << " " << fq << " " << ret << endl;
//
//	system("pause");
//	return 0;
//}

/* 在有序的二维数组中查找一个数字  */

bool Find(int target, vector<vector<int> > array) {
	int L = array.size();
	int W = array[0].size();

	int i = 0;
	int j = W-1;

	while (i < L && j >= 0)
	{
		if (array[i][j] == target)
			return true;
		else
		{
			if (array[i][j] > target)
				j--;
			else i++;
		}
	}
	return false;
}