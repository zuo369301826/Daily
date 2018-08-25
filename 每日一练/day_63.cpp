#include <iostream>
using namespace std;


//求二叉树的镜像
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
		}
};
#if 0
class Solution {
public:
	void Mirror(TreeNode *pRoot) {
		if (pRoot == NULL)
			return ;
		_Mirror(pRoot);
	}
	void _Mirror(TreeNode *pRoot) {
		if (pRoot->left || pRoot->right)
		{
			if (pRoot->left)
				_Mirror(pRoot->left);
			if (pRoot->right)
				_Mirror(pRoot->right);
			TreeNode *temp = pRoot->left;
			pRoot->left = pRoot->right;
			pRoot->right = temp;
		}
	}
};
#endif 


#if 0
//求数的深度
class Solution {
public:
	int TreeDepth(TreeNode* pRoot)
	{
		return _TreeDepth(pRoot);

	}
	int _TreeDepth(TreeNode* pRoot)
	{
		if (NULL == pRoot)
			return 0;
		return (max(_TreeDepth(pRoot->left), _TreeDepth(pRoot->right)) + 1);
	}
	int max(int a, int b)
	{
		return (a > b ? a : b);
	}
};


int main()
{
	Solution s;
	TreeNode a1(1);
	TreeNode a2(2);	
	TreeNode a3(3);
	TreeNode a4(4);
	TreeNode a5(5);
	TreeNode a6(6);
	TreeNode a7(7);

	TreeNode* p = &a1;
	a1.left  = &a2;
	a1.right = &a3;
	a2.left = &a4;
	a2.right = &a5;
	a3.left = &a6;
	a3.right = &a7;

	cout << s.TreeDepth(p) << endl;
	return 0;
}
#endif 

