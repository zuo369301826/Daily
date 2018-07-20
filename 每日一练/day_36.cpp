#include <iostream>
using namespace std;
#include <vector>


/**
	1到n之间所有的ke个数的组合
*/
#if 0
class Solution {
public:
	vector<vector<int> > combine(int n, int k) {
		return _combine(n, k, 1);
	}
	vector<vector<int> > _combine(int n, int k, int start)
	{
		vector<vector<int>> ret;
		if ( k <= 0 || n < k || n - start + 1 < k) 
			return ret;

		vector<vector<int>> one = _combine(n, k - 1, start + 1);
		for (int i = 0; i < one.size(); i++)
		{
			one[i].push_back(start);
			ret.push_back(one[i]);
		}

		vector<vector<int>> two = _combine(n, k, start + 1);
		for (int i = 0; i < two.size(); i++)
			ret.push_back(two[i]);

		return ret;
	}
};

#endif


/**
	求x的平方根

	解法：
		
			牛顿迭代法，牛顿-拉夫逊方法
*/
class Solution {
public:
	int sqrt(int x) {
		double g = x;
		while (abs_math(g*g - x)>0.000001) {
			g = (g + x / g) / 2;
		}
		return g;
	}
	double abs_math(double num)
	{
		return num<0 ? -num : num;
	}
};

