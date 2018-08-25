#include <string>
using namespace std;
#include <vector>
#include <iostream>

#if 0
class Solution {
public:
	string ReverseSentence(string str) {
		auto t1 = str.end();
		auto t2 = str.end();
		auto t3 = str.end();
		
		string  ret;
		
		t1--;
		while (t1 != str.begin())
		{
			while (t1 != str.begin() && *t1 != ' ')
			{
				t1--;
			}
			t2 = t1;
			if (*t1 == ' ')
			{
				t2++;
			}

			
			while (t2 != t3)
			{
				ret.push_back(*t2++);
			}

			if (*t1 == ' ')
			{
				t3 = t1;
				ret.push_back(*t1);
				t1--;
			}
			else break;
		}
		return ret;
	}
};


int main()
{
	Solution s;
	cout << s.ReverseSentence("student a am i") << endl;

	return 0;
}

#endif  