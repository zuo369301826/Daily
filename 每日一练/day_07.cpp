#include <iostream>
#include <vector>
using namespace std;
#pragma warning (disable:4996)


//
string PrintMinNumber(vector<int> numbers) {
	
	int N = numbers.size();
	
	vector<int> num;
	num.resize(N);
	for (int i = 0; i < N; i++)
		num[i] = 1;

	int min = 10;
	int _yu = 0;

	vector<int> m;

	int _n = 0;
	int count = 0;

	while (count < N)
	{
		for (int i = 0; i < N; i++)
		{
			if (num[i] == 1)
			{
				_yu = numbers[i] % 10;
				if (_yu <= min && _n > 0)
				{
					if (_yu < min)
					{
						_n = 1;
						m.resize(_n);
						m[0] = i;
					}
					else
					{
						_n++;
						m.resize(_n);
						m[_n - 1] = i;
					}
				}
			}
		}
		while (_n != 1)
		{

		}

		count++;
	}
	return "";
}


/*求和等于sum的连续数值*/

//vector<vector<int> > FindContinuousSequence(int sum) {
//	vector<vector<int> > arr;
//	int count = 0;
//	int Q = 0;
//	int W = 0;
//	for (int i = 1; i < (sum + 1) / 2; i++)
//	{
//		int j = i;
//		count = j;
//		while (j++)
//		{
//			count += j;
//			if (count > sum)
//				break;
//			else if (count == sum)
//			{
//				arr.resize(Q + 1);
//				int k = i;
//				while (k <= j)
//				{
//					arr[Q].resize(W + 1);
//					arr[Q][W++] = k++;
//				}
//				Q++;
//				W = 0;
//			}
//		}
//	}
//
//	int q = arr.size();
//	int w = 0;
//	for (int i = 0; i < q; i++)
//	{
//		w = arr[i].size();
//		for (int j = 0; j < w; j++)
//		{
//			cout << arr[i][j] << " ";
//		}
//		cout << endl;
//	}
//	return arr;
//}
//
//int main()
//{
//	vector<vector<int> > arr = FindContinuousSequence(200);
//	system("pause");
//	return 0;
//}

//
//int main()
//{
//	int arr[] = { 3, 32, 321 };
//
//	vector<int> num(3);
//	for (int i = 0; i < 3; i++)
//		num[i] = arr[i];
//
//	string a=PrintMinNumber(num);
//
//	system("pause");
//	return 0;
//}