#include <iostream>
using namespace std;
#include <string>

/**
��Ŀ����:
	������������ n �� m��������1��2��3.......n ������ȡ������,ʹ��͵��� m ,Ҫ���������еĿ�������г���
*/
#if 0
int main()
{
	int n, m;
	cin >> n >> m;
	int count = 0;
	int num = 1;
	for (int i = 1; i<n-num; i++)
	{
		count = i;
		for (int j = 0; j < num; j++)
		{
			count += count+1;
		}
		if (count == m)
		{
			for (int k = 0; k < num; k++)
			{
				cout << count - k << " ";
			}
			cout << endl;
		}	
	}
	return 0;
}
#endif
#if 0
int main()
{
	string  src;
	cin >> src;
	int count = 0;
	int max = 0;
	for (int i = 0; i < src.size(); i++)
	{
		if (src[i] <= '9' && src[i] >= '1')
			count++;
		else
		{
			if (count > max)
			{
				max = count;
				int start = i - count;
			}
			count = 0;
		}
	}
	auto iter = src.begin();
	while()

	cout << max << endl;
	return 0;
}
#endif

