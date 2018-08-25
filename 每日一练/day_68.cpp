#include <iostream>
#include <vector>
using namespace std;


//Ç°Ðò±éÀú
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> ret;
		_postorderTraversal(root, &ret);
		return ret;
	}

	void _postorderTraversal(TreeNode* root, vector<int>* ret)
	{
		if (NULL == root)
			return;
		ret->push_back(root->val);
		
		_postorderTraversal(root->left, ret);

		_postorderTraversal(root->right, ret);
	}
};