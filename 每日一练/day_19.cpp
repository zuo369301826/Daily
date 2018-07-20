#include <iostream>
using namespace std;
#include <stack>

#if 0
/*  两个栈实现一个队列 */
class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		int ret = stack2.top();
		stack2.pop();
		return ret;
	}
private:
	stack<int> stack1;
	stack<int> stack2;
};

#endif


#if 0
int main()
{
	int n;
	int *arr = NULL;
	char *com = NULL;

	cin >> n;
	arr = new int[n];
	com = new char[n];
	stack<int> s;
	for (int i = 0; i < n; i++)
	{
		cin >> com[i];
		if(com[i] == 'P')
			cin >> arr[i];
	}
	
	for (int i = 0; i < n; i++)
	{
		switch (com[i])
		{
		case 'P':
		{
			s.push(arr[i]);
			break; 
		}
		case 'A':
		{
			if (s.empty())
				cout << 'E' << endl;
			else cout << s.top() << endl;
			break;
		}
		case 'O':
		{
			if(!s.empty())
				s.pop();
			break;
		}
		}
	}
	cout << endl;

	delete[] arr;
	delete[] com;
	system("pause");
	return 0;
}

#endif