#include <vector>
#include <unordered_map>
using namespace std;

#if 0
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		unordered_map<int, int> map;
		for (int i = 0; i < numbers.size(); i++)
		{
			++map[numbers[i]];
			if (map[numbers[i]] > numbers.size() / 2)
			{
				return numbers[i];
			}
		}
		return 0;
	}
};

#endif