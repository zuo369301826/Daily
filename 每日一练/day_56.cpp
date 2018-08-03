#include<iostream>
#include<string>
using namespace std;

#if 0
// 1.输入两个链表，找出它们的第一个公共结点。
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) 
		{}
};
class Solution {
public:
	ListNode * FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		if ( NULL == pHead1 ||  NULL == pHead2)
			return NULL;
		int len_1 = 0;
		int len_2 = 0;
		ListNode* p1 = pHead1;
		ListNode* p2 = pHead2;
		while (p1)
		{
			++len_1;
			p1 = p1->next;
		}
		while (p2)
		{
			++len_2;
			p2 = p2->next;
		}

		p1 = pHead1;
		p2 = pHead2;
		if (len_2 > len_1)
		{
			for (int i = 0; i < (len_2 - len_1); ++i)
			{
				p2 = p2->next;
			}
		}
		else 
		{
			for (int i = 0; i < (len_1 - len_2); ++i)
			{
				p1 = p1->next;
			}
		}
		while (p2 && p1)
		{
			if (p2 == p1)
			{
				return p1;
			}
			p2 = p2->next;
			p1 = p1->next;
		}
		return NULL;
	}
};
#endif

//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
//要求不能创建任何新的结点，只能调整树中结点指针的指向。

#if 0 
// 解决方法 -- 递归法：转换左子树  转换右子树 连接根和左右子树
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
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		TreeNode *start_list;
		TreeNode *end_list;
		_Convert(pRootOfTree, start_list, end_list);
		return start_list;
	}
	void _Convert(TreeNode* root, TreeNode* &start_list, TreeNode* &end_list)
	{
		if (root == NULL)
		{
			start_list = NULL;
			end_list = NULL;
			return;
		}

		if (root->left == NULL && root->right == NULL)
		{
			start_list = root;
			end_list = root;
			return;
		}

		TreeNode *start_left, *end_left, *start_right, *end_right;
		
		//在左子树中找链表的头，即转化左子树
		if (root->left == NULL) //左子树为空
			start_list = root;
		else
		{
			_Convert(root->left, start_left, end_left);//转化左子树
			start_list = start_left; //链表的头是左子树转化为链表的头
			//将根连接左右子树  左子树的尾连接根 右子树的头连接根
			root->left = end_left;
			end_left->right = root;
		}

		//在右子树中找链表的尾，即转化右子树
		if (root->right == NULL)
			end_list = root;
		else
		{
			_Convert(root->right, start_right, end_right);//转化右子树
			end_list = end_right;
			//将根连接左右子树  左子树的尾连接根 右子树的头连接根
			root->right = start_right;
			start_right->left = root;
		}
	}
};

#endif
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};


// 方法2 非递归法  使用栈
#if 0
#include <stack>
class Solution {
public:
	TreeNode * Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == NULL)
			return NULL;

		stack<TreeNode *> s;

		if (pRootOfTree->left == NULL && pRootOfTree->right == NULL)
			return pRootOfTree;

		TreeNode* root = NULL;
		TreeNode* cur = pRootOfTree;
		TreeNode* per = NULL;
		while (cur)
		{
			s.push(cur);
			cur = cur->left;
		}
		cur = s.top();
		s.pop();
		root = cur;
		per = cur;
		cur = cur->right;

		while (cur || !s.empty())
		{
			while (cur)
			{
				s.push(cur);
				cur = cur->left;
			}
			cur = s.top();
			s.pop();
			per->right = cur;
			cur->left = per;
			per = cur;
			cur = cur->right;
		}
		return root;
	}
};
#endif