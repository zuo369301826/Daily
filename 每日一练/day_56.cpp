#include<iostream>
#include<string>
using namespace std;

#if 0
// 1.�������������ҳ����ǵĵ�һ��������㡣
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

//����һ�ö��������������ö���������ת����һ�������˫������
//Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��

#if 0 
// ������� -- �ݹ鷨��ת��������  ת�������� ���Ӹ�����������
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
		
		//�����������������ͷ����ת��������
		if (root->left == NULL) //������Ϊ��
			start_list = root;
		else
		{
			_Convert(root->left, start_left, end_left);//ת��������
			start_list = start_left; //�����ͷ��������ת��Ϊ�����ͷ
			//����������������  ��������β���Ӹ� ��������ͷ���Ӹ�
			root->left = end_left;
			end_left->right = root;
		}

		//�����������������β����ת��������
		if (root->right == NULL)
			end_list = root;
		else
		{
			_Convert(root->right, start_right, end_right);//ת��������
			end_list = end_right;
			//����������������  ��������β���Ӹ� ��������ͷ���Ӹ�
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


// ����2 �ǵݹ鷨  ʹ��ջ
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