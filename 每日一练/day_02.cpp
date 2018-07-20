#include <iostream>
using namespace std;
#pragma warning (disable:4996)

/*  ×Ö·û´®×ªÊý×Ö  */
int StrToInt(string str) {
	int len = str.size();
	int* p = new int[len];
	int i = 0;
	int flag = 1;

	if (str[0] == '-')
	{
		flag = -1; i = 1;
	}
	else if (str[0] == '+')
	{
		flag = 1; i = 1;
	}


	int j = 0;
	for (; i < len; i++)
	{
		if (!(str[i] <= '9' && str[i] >= '0'))
			return 0;
		else
		{
			p[j++] = str[i] - '0';
		}
	}

	int num = p[0];
	for (int i = 1; i < j; i++)
	{
		num *= 10;
		num += p[i];
	}
	return flag*num;
}




/* 2.×Ö·û´®ÄæÐò */
string rotateString(string A, int n, int p) {
	char *pstr = new char[n * 2];
	int k = 0;
	for (int j = 1; j <= 2 ; j++)
	{
		for (int i = 0; i < n; i++)
		{
			pstr[k++] = A[i];
		}
	}

	for (int i = 0; i < n; i++)
	{
		A[i] = pstr[i + p + 1];
	}
	return A;
}
//
//int main()
//{
//	//string str = "-1234a789";
//	//int a = StrToInt(str);
//	//cout << a << endl;
//
//	string str = "abcdefgh";
//	str = rotateString(str, 8, 4);
//
//
//
//	system("pause");
//	return 0;
//}