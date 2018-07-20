#include <iostream>
using namespace std;
#include <stack>
#include <vector>

#if 0
class SetOfStacks {
public:
	vector<vector<int> > setOfStacks(vector<vector<int> > ope, int size) {

		vector<vector<int>> ret;
		if (size == 0 || ope.size() == 0)
			return ret;
		int n = (ope.size() / size) + 1;
		stack<int> *s = new stack<int>[n];

		ret.resize(n);


		int index = 0;
		for (int i = 0; i < ope.size(); i++)
		{
			if (ope[i][0] == 1)
			{
				if (s[index].size() == size)
					index++;
				s[index].push(ope[i][1]);
			}
			else if (ope[i][0] == 2)
			{
				if (s[index].empty())
				{
					if (index != 0)
						index--;
					else continue;
				}
				s[index].pop();
			}
		}


		//int vi = 0;
		//for (int i = index; i >= 0; i--,vi++)
		//{
		//	ret[vi].resize(s[i].size());
		//	for (int j = 0; j < size && !s[i].empty(); j++)
		//	{
		//		ret[vi][j] = s[i].top();
		//		s[i].pop();
		//	}
		//}

		for (int i = 0; i <= index; i++)
		{
			ret[i].resize(s[i].size());
			for (int j = 0; j < size && !s[i].empty(); j++)
			{
				ret[i][j] = s[i].top();
				s[i].pop();
			}
		}

		return ret;
 	}
};

int main()
{
	vector<vector<int>> v;
	int size = 2;
	v.resize(11);
	for (int i = 0; i < 11; i++)
	{
		v[i].resize(2);
	}
	v[0][0] = 1;
	v[0][1] = 0;

	v[1][0] = 1;
	v[1][1] = 1;
	
	v[2][0] = 1;
	v[2][1] = 2;

	v[3][0] = 1;
	v[3][1] = 3;

	v[4][0] = 1;
	v[4][1] = 4;

	v[5][0] = 1;
	v[5][1] = 5;

	v[6][0] = 1;
	v[6][1] = 6;

	v[7][0] = 1;
	v[7][1] = 7;

	v[8][0] = 1;
	v[8][1] = 8;

	v[9][0] = 1;
	v[9][1] = 9;

	v[10][0] = 1;
	v[10][1] = 10;

	SetOfStacks s;

	vector<vector<int>> vp(s.setOfStacks(v,size));

	for (int i = 0; i < vp.size(); i++)
		for (int j = 0; j < vp[i].size(); j++)
			cout << vp[i][j] << " ";
	cout<<endl;

	system("pause");
	return 0;
}

#endif

#if 0
class TwoStacks {
public:
	vector<int> twoStacksSort(vector<int> numbers) {
		vector<int> v;
		v.resize(numbers.size());
		if (numbers.size() == 0)
			return numbers;
		stack<int> s;
		int right;

		for (int i = 0; i < numbers.size(); i++)
		{
			right = i;
			while (!s.empty() && numbers[i] < s.top())
			{
				right--;
				numbers[right] = s.top();
				s.pop();
			}
			s.push(numbers[i]);
			while (right < i)
			{
				s.push(numbers[right++]);
			}
			
		}

		for (int i = 0; i<numbers.size() && !s.empty(); i++)
		{
			v[i] = s.top();
			s.pop();
		}
		return v;
	}
};

int main()
{
	vector<int> numbers;
	numbers.resize(10);
	numbers[0] = 69;
	numbers[1] = 34;//
	numbers[2] = 92;
	numbers[3] = 65;
	numbers[4] = 7;//
	numbers[5] = 64;//
	numbers[6] = 18;//
	numbers[7] = 35;//
	numbers[8] = 10;//
	numbers[9] = 48;//

	//7 10  18 34 35 48 64 65 69 92 

	TwoStacks t;
	vector<int> r(t.twoStacksSort(numbers));

	for (int i = 0; i < r.size(); i++)
		cout << r[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}
#endif