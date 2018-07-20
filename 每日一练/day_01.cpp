#include <iostream>
using namespace std;
#pragma warning (disable:4996)

/* ¿Õ¸ñ×ª 20% */
class Replacement {
public:
	string replaceSpace(string iniString, int length) {
		char str[1000];
		iniString.copy(str, length, 0);
		str[length] = 0;

	
		cout << str << endl;

		int count = 0;
		for (int i = 0; i < length; i++)
		{
			if (str[i] == ' ')
			count+=2;
		}
		int len = length + 1;

		for (int i = length + count + 1; count != 0 ;i--)
		{
			if (str[len] == ' ')
			{
				str[i--] = '0';
				str[i--] = '2';
				str[i] = '%';
				count -= 2;
			}
			else str[i] = str[len];
			len--;
		}

		string a(str);
	
		return a;
	}
};

