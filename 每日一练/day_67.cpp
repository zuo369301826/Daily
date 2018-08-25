#include <iostream>
#include <vector>

#if 0
using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

//¶þ²æÊ÷ÐòÁÐ»¯
class Solution {
public:
	char* Serialize(TreeNode *root) {
		char c[1024];
		int i = 0;
		_Serialize(root, &c, i);
		c[i] = '\0';
		return c;

	}

	void _Serialize(TreeNode * root, char(*c)[1024], int& i )
	{
		if (root == NULL)
			*c[i++] = root->val ;

		*c[i++] = root->val;
		
		if (root->left )
		{
			_Serialize(root->left, c, i);
		}
		else *c[i++] = '*';

		if (root->right)
		{
			_Serialize(root->right, c, i);
		}
		else *c[i++] = '*';
	}

	TreeNode* Deserialize(char *str) {
		return _Deserialize(str);
	}
	TreeNode* _Deserialize(char* str)
	{
		TreeNode* root;
		if (*str == '\0')
			return 
		if (*str == '*')
			return NULL;
		root->val = 

	}

};

#endif 


