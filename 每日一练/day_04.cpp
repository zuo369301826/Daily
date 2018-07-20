#include <iostream>
#include <vector>
using namespace std;
#pragma warning (disable:4996)

/*×Ö·û´®ÄæÐò*/

//int main()
//{
//	char str[100];
//	char sstr[100];
//	char c;
//	int i = 0;
//	while (c = getchar())
//	{
//		if (c != '\n')
//			str[i++] = c;
//		else
//			break;
//	}
//	str[i] = '\n';
//
//
//	int L = 0;
//	int R = 0;
//	while (L < i)
//	{
//		while (str[R] != ' ' && str[R] != '\n')
//			R++;
//
//		int l = L;
//		int r = R;
//		while (l < R)
//		{
//			sstr[l] = str[r - 1];
//			l++;
//			r--;
//		}
//
//		sstr[l] = ' ';
//
//		R++;
//		L = R;
//	}
//
//	L = 0;
//	R =i - 1;
//	while (L < i)
//	{
//		str[L] = sstr[R];
//		L++;
//		R--;
//	}
//
//	L = 0;
//	while (L < i)
//	{
//		cout << str[L++];
//	}
//	cout << endl;
//
//	return 0;
//}