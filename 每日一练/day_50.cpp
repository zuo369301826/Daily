#include <iostream>
#include <stack>
#include <string>
using namespace std;


#if 0
int  main()
{
	int M, N;
	cin >> M >> N;
	stack<char> s;
	int flag = 1;

	if (M == 0)
	{
		cout << 0<<endl;
		system("pause");
		return 0;
	}
	if (M < 0)
	{
		M = -M;
		flag = -1;
	}

	int yushu = 0;
	char next = 0;
	while (M != 0)
	{
		yushu = M % N;
		M = M / N;
		if (yushu >= 10)
			next = 'A' + yushu - 10;
		else
			next = '0' + yushu;
		s.push(next);
	}
	if (flag == -1)
		cout << '-';
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
	cout << endl;
	
	system("pause");
	return 0;
}
#endif


//����һ��������n, ��n!(���׳�)ĩβ�ж��ٸ�0�� ���� : n = 10; n!= 3628800, ���Դ�Ϊ2
#if 0
int main()
{
	int n;
	cin >> n;
	int count = 0;
	int a_5 = n / 5;
	int a_25 = a_5 / 5;
	int a_125 = a_25 / 5;
	int a_625 = a_125 / 5;
	count += (a_5 + a_25 + a_125 + a_625);
	cout << count << endl;
	system("pause");
	return 0;
}
#endif

