#include <iostream>
#include <cmath>
using namespace std;
#include <stack>
#include <vector>

#if 0
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
	bool IsBalanced_Solution(TreeNode* pRoot) {
		if (pRoot == NULL)
			return true;
		if ( IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right) )
		{
			if (abs(GetHight(pRoot->left) - GetHight(pRoot->right)) <= 1)
				return true;
			else return false;
		}
		return false;
	}
	int GetHight(TreeNode* pRoot)
	{
		if (pRoot == NULL)
			return 0;
		int leftlen = GetHight(pRoot->left);
		int rightlen = GetHight(pRoot->right);
		return (1 + ((leftlen>rightlen)?leftlen:rightlen) );
	}
};
#endif

#if 0
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
	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> arr;
		_postorderTraversal(root, arr);
		return arr;
	}
	void _postorderTraversal(TreeNode* root, vector<int> &arr)
	{
		if (root != NULL)
		{
			_postorderTraversal(root->left, arr);
			_postorderTraversal(root->right, arr);
			arr.push_back(root->val);
		}
	}
};

#endif

