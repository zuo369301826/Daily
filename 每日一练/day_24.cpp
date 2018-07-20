#include <iostream>
using namespace std;


#if 0
/*  二叉树的深度  */
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
	val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
	int TreeDepth(TreeNode* pRoot)
	{
		if (pRoot == NULL)
			return 0;
		int size = _TreeDepth(pRoot);
		return size;
	}

	int _TreeDepth(TreeNode* pRoot)
	{
		if (pRoot == NULL)
			return 0;
		int l_size = _TreeDepth(pRoot->left);
		int r_size = _TreeDepth(pRoot->right);
		return (1 + ((l_size > r_size) ? l_size : r_size));
	}
};



int main()
{
	Solution s;
	TreeNode n(0);
	TreeNode nL(1);
	TreeNode nR(1);
	TreeNode nLL(5);
	TreeNode nLR(5);
	TreeNode nRL(5);
	TreeNode nRR(5);

	n.left = &nL;
	n.right = &nR;

	nL.left = &nLL;
	nL.right = &nLR;

	nR.left = &nRL;
	nR.right = &nRR;
	int size = s.TreeDepth(&n);
	cout << size << endl;

	system("pause");
	return 0;
}
#endif

/* 二叉树前序遍历*/
#include <vector>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#if 0
//递归
class Solution {
public:
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> ret;
		if (root == NULL)
			return ret;
		_preorderTraversal(root, ret);
		return ret;
	}
	void _preorderTraversal(TreeNode *root, vector<int> &ret)
	{
		if (root != NULL)
		{
			ret.push_back(root->val);
			_preorderTraversal(root->left, ret);
			_preorderTraversal(root->right, ret);
		}
	}
};
#endif

//2非递归-栈
#include <stack>
class Solution {
public:
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> ret;
		if (root == NULL)
			return ret;
		stack<TreeNode*> s;
		s.push(root);
		TreeNode* pCur;

		while (!s.empty()) 
		{
			pCur = s.top();
			s.pop();
			if (pCur)
			{
				s.push(pCur->right);
				s.push(pCur->left);
				ret.push_back(pCur->val);
			}

		}
		return ret;
	}
};