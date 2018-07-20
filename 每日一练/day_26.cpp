#include <iostream>
using namespace std;
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
	int run(TreeNode *root) {
		if (root == NULL)
			return 0;
		return GetHight(root);
	}

	int GetHight(TreeNode *root)
	{
		if (NULL == root->left  && NULL == root->right)
			return 1;
		else if (root->left == NULL && NULL != root->right)
			return 1 + GetHight(root->right);
		else if(root->left != NULL && NULL == root->right)
			return 1 + GetHight(root->left);
		else 
		{
			int left  = GetHight(root->left);
			int right = GetHight(root->right);
			return (1 + ((left < right) ? left : right));
		}	
	}
};

#endif