#include <iostream>
using namespace std;
#include <vector>

#if 0
class Solution {
public:
	vector<int> searchRange(int A[], int n, int target){
		int pos = Find(0, n, A, target);
		vector<int> ret;
		ret.resize(2);
		ret[0] = pos;
		ret[1] = pos;
		if(pos != -1)
		{
			while (ret[0] - 1 >= 0 && A[ret[0] - 1] == target)
				--ret[0];
			while (ret[1] + 1 < n && A[ret[1] + 1] == target)
				++ret[1];
		}
		return ret;

	}
	int Find(int left, int right, int *A, int target)
	{
		if (left == right)
			return -1;
		int mid = left + (right - left) / 2;
		if (A[mid] > target)
			return Find(left, mid, A, target);
		else if (A[mid] < target)
			return Find(mid + 1, right, A, target);
		else return mid;
	}
};
#endif

#if 0
class Solution {
public:
	int searchInsert(int A[], int n, int target) {
		return  Find(0, n, A, target);
	}
	int Find(int left, int right, int *A, int target)
	{
		if (left == right)
			return left;
		int mid = left + (right - left) / 2;
		if (A[mid] > target)
			return Find(left, mid, A, target);
		else if (A[mid] < target)
			return Find(mid + 1, right, A, target);
		else return mid;
	}
};

#endif 