#if 0

#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	long long count = 1;
	int ret = 0;
	for (int i = n; i > 0; i--)
	{
		if (i == 10)
		{
			ret += 2;
			count *= 36288;
			while (count % 10 == 0)
			{
				ret++;
				count /= 10;
			}
			break;
		}
		count *= i;
		while (count % 10 == 0)
		{
			ret++;
			count /= 10;
		}
	}
	
	cout << ret << endl;
	system("pause");
	return 0;
}

#endif