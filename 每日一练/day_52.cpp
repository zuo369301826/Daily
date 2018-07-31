#include <iostream>
#include <string>
using namespace std;

#if 0
int main()
{
	string str;
	string ret;
	cin >> str;
	int max = 0;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			int j = i + 1;
			while (str[j] >= '0' && str[j] <= '9')
			{
				j++;
			}
			if (j - i > max)
			{
				ret.resize(0);
				max = j - i;
				for (int k = i; k < j; k++)
					ret.push_back(str[k]);
			}
			else continue;
		}
	}
	if(ret.size() > 0)
		cout << ret << endl;
	system("pause");
	return 0;
}
#endif


/*

给定一个有n个正整数的数组A和一个整数sum,求选择数组A中部分数字和为sum的方案数。
当两种选取方案有一个数字的下标不一样,我们就认为是不同的组成方案。

*/

#if 0
int main()
{
	int n, sum;
	cin >> n >> sum;
	int *A = new int[n];
	for (int i = 0; i < n; i++)
		cin >> A[i];
	int* *d = new int*[n+1] ;
	for (int i = 0; i <= n; i++)
		d[i] = new int[sum+1];

	for (int i = 1; i <= sum; i++)
	{
		d[0][i] = 0;
	}
	d[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= sum; j++)
		{
			if (j >= A[i-1])
				d[i][j] = d[i - 1][j] + d[i - 1][j - A[i-1]];
			else
				d[i][j] = d[i - 1][j];
		}
	}
	cout << d[n][sum] << endl;
	
	system("pause");
	return 0;
}

#endif


