#include <iostream>
using namespace std;
#include <stack>
#include <vector>

/*  ×îÐ¡Õ» */
#if 0
class Solution {
public:
	void push(int value) {
		if (_stack.empty())
		{
			_minstack.push(value);
		}
		else 
		{
			int min = _minstack.top();
			if(value < min)
				_minstack.push(value);
			else _minstack.push(min);
		}
		_stack.push(value);
	}

	void pop() {
		_stack.pop();
		_minstack.pop();

	}

	int top() {
		return _stack.top();
	}

	int min() {
		return _minstack.top();
	}
private:
	stack<int> _stack;
	stack<int> _minstack;
};

#endif

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		int index1 = 0;
		int index2 = 0;
		while (index1 < pushV.size() )
		{
			if (s.empty() || s.top() != popV[index2])
			{
				s.push(pushV[index1]);
				index1++;
			}

			while (!s.empty() && s.top() == popV[index2])
			{
				s.pop();
				index2++;
			}
		}

		if (s.empty())
			return true;
		else return false;
	}

private:
	stack<int> s;
};