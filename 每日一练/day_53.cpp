
//进制转换

#if 0
#include <iostream>
#include <string>
#include <stack>
using namespace std;


int main()
{
	int M, N;
	cin >> M >> N;
	string s;

	if (M == 0)
	{
		cout << 0 << endl;
		return 0;
	}


	if (M < 0)
	{
		cout << "-";
		M = -M;
	}

	char a;
	while (M > 0)
	{
		int n = M % N;
		M /= N;
		if(n < 10)
			a = '0' + n;
		else a = 'A' + (n - 10);
		s.push_back(a);
	}
	auto end = s.rbegin();
	while (end != s.rend())
		cout << *end++;
	cout << endl;
	return 0;
}

#endif

//阶乘求零

#if 0
#include <iostream>
#include <cmath>
using namespace std;
int math(int n, int c)
{
	int q = pow(5, c);
	int count = n / q;
	if (count == 0)
		return 0;
	else
		return count + math(n, c + 1);
}
int main()
{
	int n;
	cin >> n;
	int count = math(n,1);
	cout << count<<endl;
	return 0;
}
#endif